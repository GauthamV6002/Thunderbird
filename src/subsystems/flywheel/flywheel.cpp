#include "main.h"
#include "pros/misc.h"

//Flywheel Spin Functions
// Flywheel
void thunderbird::Flywheel::spinForward(int power) {
    thunderbird::flywheel = power;
} 

void thunderbird::Flywheel::toggleFlywheel() {
        if(this->flywheelIsActive) {
        this->spinForward(this->flywheelIsLifted ? this->HIGH_ARC_SPEED : this->LOW_ARC_SPEED);
        this->flywheelIsActive = !this->flywheelIsActive;
    } else {
        this->spinForward(0);
        this->flywheelIsActive = !this->flywheelIsActive;
    }
}


//Lift Functions
void thunderbird::Flywheel::raiseFlywheelLift() {
    thunderbird::flywheelLift.set_value(HIGH);
}

void thunderbird::Flywheel::lowerFlywheelLift() {
    thunderbird::flywheelLift.set_value(LOW);
}

void thunderbird::Flywheel::toggleFlywheelLift() {
    if(this->flywheelIsLifted) {
        lowerFlywheelLift();
        this->flywheelIsLifted = !this->flywheelIsLifted;
        this->spinForward(this->flywheelIsActive ? this->LOW_ARC_SPEED : 0);
    } else {
        raiseFlywheelLift();
        this->spinForward(this->flywheelIsActive ? this->HIGH_ARC_SPEED : 0);
        this->flywheelIsLifted = !this->flywheelIsLifted;
    }
}

// Matchloading Macros
void thunderbird::Flywheel::runMatchLoadingHighArc() {
    raiseFlywheelLift();
    this->spinForward(this->HIGH_ARC_SPEED);
}

void thunderbird::Flywheel::runMatchLoadingLowArc() {
    lowerFlywheelLift();
    this->spinForward(this->LOW_ARC_SPEED);
}

//TODO: MAKE THIS WORK LMFAO
void thunderbird::Flywheel::runFlywheel() {
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        toggleFlywheelLift();
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
        toggleFlywheel();
    }
}