#include "catapultAndIntake.hpp"
#include "main.h"

// Util Functions to load/intake
void thunderbird::CatapultAndIntake::spinCatapult(int power) {
    thunderbird::catapultAndIntakeMotors = -power;
}

void thunderbird::CatapultAndIntake::intakeForward(int power) {
    thunderbird::catapultAndIntakeMotors = power;
}

// TODO: Fix this to make it non-blocking?
void thunderbird::CatapultAndIntake::charge() {
        float error = this->STORAGE_ANGLE - thunderbird::catapultRotationSensor.get_position();
        float power = catapultPID.compute(error);

        // Only spin the cata if power is more than 0
        if(power < 10) thunderbird::catapultAndIntakeMotors.brake();
        else this->spinCatapult(power);
}

//TODO: Fix..?
void thunderbird::CatapultAndIntake::fire() {
    thunderbird::catapultAndIntakeMotors = 127;
}

void thunderbird::CatapultAndIntake::intakeFully(int timeout) {
    int timeSpentRunning = 0;
    this->intakeForward(127);

    while(thunderbird::intakeChecker.get() > 30 && timeSpentRunning < timeout) {
        timeSpentRunning += 10;
        pros::delay(10);
    }

    thunderbird::catapultAndIntakeMotors.brake();
}