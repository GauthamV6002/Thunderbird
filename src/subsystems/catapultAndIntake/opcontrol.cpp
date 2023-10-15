// #include "../../../include/PID/PID.hpp"
#include "main.h"
#include "pros/motors.h"


// Main loop function
void thunderbird::CatapultAndIntake::runCatapultAndIntake() {

    // Break the cycle
    // TODO: Ensure you don't get locked into one mode
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
        this->cycleState = (this->cycleState == 0) ? 2 : 0; // Manual Action
    } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        this->cycleState = (this->cycleState == 0) ? 1 : 0; // Match Load Routine
    }

    if(this->cycleState == 2) {
        this->runAutomaticReload();
    } else if(this->cycleState == 1) {
        this->runMatchLoadRoutine();
    } else {
        this->runManualAction();
    }

    //TODO: Add Power detection to figure out whether the motor is overexerting, as such stop it
}

void thunderbird::CatapultAndIntake::runAutomaticReload() {

    if(!master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2) && !triballIntaked) {
        
        // Charge up cata to hold
        float error = this->MATCH_ANGLE - thunderbird::catapultRotationSensor.get_position();
        float power = catapultPID.compute(error);

        // Only spin the cata if power is more than 0
        // TODO: Refactor to with isSettled by reseting PID after each intake/outake
        if(power < 10 /* || this->catapultPID.isSettled() */) thunderbird::catapultAndIntakeMotors.brake();
        else this->spinCatapult(power);
		
        // pros::screen::print(TEXT_MEDIUM, 7, "Power:  %f | Error: %f", power, error);
        // pros::screen::print(TEXT_MEDIUM, 8, "triball intaked?: %d", this->triballIntaked);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        this->triballIntaked = true;
        this->intakeForward(127);
    } else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        this->spinCatapult(127);
        this->triballIntaked = false;
        this->catapultPID.resetSystem();
    } else {
        intakeForward(0);
    }

}

void thunderbird::CatapultAndIntake::runMatchLoadRoutine() {
    
    const int matchLoadSpeed = 100, sensorThreshold = 240;
    int sensorProximity = thunderbird::kickerPlatformOptical.get_proximity();

    if(sensorProximity > sensorThreshold) {
        this->spinCatapult(127);
    } else {
        this->charge();
    }
        
}

void thunderbird::CatapultAndIntake::runManualAction() {
    int power = 80;

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        thunderbird::catapultAndIntakeMotors.brake();  
    } else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        this->spinCatapult(power);
    }
}

void thunderbird::CatapultAndIntake::setCatapultAndIntakeConfig() {
    thunderbird::catapultAndIntakeMotors.set_brake_modes(pros::E_MOTOR_BRAKE_BRAKE);

    thunderbird::catapultRotationSensor.reset_position();
    thunderbird::kickerPlatformOptical.disable_gesture();
}