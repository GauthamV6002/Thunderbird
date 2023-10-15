#include "autonomous/autonomous.hpp"
#include "main.h"

void thunderbird::Auton::outtakeAndDeposit(int power, int moveDelay, int time, int distBack) {
    this->_catapultAndIntake.intakeForward(-127);
    pros::delay(moveDelay);
    thunderbird::driveMotors = power;
    pros::delay(time);
    this->_drive.moveLateral(-distBack);
}