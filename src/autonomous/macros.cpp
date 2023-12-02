#include "autonomous/autonomous.hpp"
#include "main.h"

void thunderbird::Auton::outtakeAndDeposit(int power, int moveDelay, int time, int distBack) {
    this->_intake.intakeIn(-127);
    pros::delay(moveDelay);
    thunderbird::driveMotors = -power;
    pros::delay(time);
    this->_drive.moveLateral(-distBack);
    this->_intake.intakeIn(0);
}

void thunderbird::Auton::ramAndGoBack(int power, int time, int distBack) {
    thunderbird::driveMotors = power;
    pros::delay(time);
    this->_drive.moveLateral(-distBack);
}