#include "main.h"

void thunderbird::Auton::plannerCalibration() {
    //this->_drive.turnToAngleRelative(0.00);
    this->_drive.moveLateral(24.00);
    this->_drive.turnToAngleRelative(-45.00);
    this->_drive.moveLateral(33.94);
    this->_drive.turnToAngleRelative(90.00);
    this->_drive.moveLateral(33.94);
    this->_drive.turnToAngleRelative(-90.00);
    this->_drive.moveLateral(33.94);
    this->_drive.turnToAngleRelative(-135.00);
    this->_drive.moveLateral(72.00);
}

void thunderbird::Auton::turnPIDCalibration() {
    this->_drive.turnToAngleRelative(30);
	this->_drive.turnToAngleRelative(60);
	this->_drive.turnToAngleRelative(45);
	this->_drive.turnToAngleRelative(-135);
	this->_drive.turnToAngleRelative(180);
}

void thunderbird::Auton::drivePIDCalibration() {
    // this->_drive.moveLateral(24);
    // pros::delay(1000);
    // this->_drive.moveLateral(-12);
    // pros::delay(1000);
    this->_drive.moveLateral(-12);
    this->_drive.moveLateral(24);
    this->_drive.moveLateral(36);
    this->_drive.moveLateral(-48);
    this->_drive.moveLateral(6);
    this->_drive.moveLateral(18);
    this->_drive.moveLateral(-24);
}