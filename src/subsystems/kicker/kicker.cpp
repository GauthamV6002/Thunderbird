#include "main.h"
#include "pros/misc.h"

void thunderbird::Kicker::chargeSync() {
    // TODO: Change to PID?
    int sensorProximity = thunderbird::kickerPlatformOptical.get_proximity();
    const int sensorThreshold = 210;

    CHARGED_POSITION_ANGLE = 5500;

    float error = CHARGED_POSITION_ANGLE - thunderbird::catapultRotationSensor.get_position();
    float power = kickerPID.compute(error);


    if(sensorProximity > sensorThreshold) {
        kickerMotors = 127; // Fire Catapult
    } else {
        if(thunderbird::catapultRotationSensor.get_position() > CHARGED_POSITION_ANGLE || thunderbird::catapultRotationSensor.get_position() < 0){
            kickerMotors = 0;
        } else {
            kickerMotors = power;
        }
    }
}

void thunderbird::Kicker::runKicker() {
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        matchLoadRoutineIsActive = !matchLoadRoutineIsActive;
    }
    pros::screen::print(pros::E_TEXT_MEDIUM, 1, "kickerToggle: %d", matchLoadRoutineIsActive); 
    pros::screen::print(pros::E_TEXT_MEDIUM, 3, "rot: %d", thunderbird::catapultRotationSensor.get_position()); 

    if(matchLoadRoutineIsActive) chargeSync();
}