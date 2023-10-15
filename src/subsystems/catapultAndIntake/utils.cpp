#include "main.h"

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


// Util Functions to load/intake
void thunderbird::CatapultAndIntake::spinCatapult(int power) {
    thunderbird::catapultAndIntakeMotors = -power;
}

void thunderbird::CatapultAndIntake::intakeForward(int power) {
    thunderbird::catapultAndIntakeMotors = power;
}