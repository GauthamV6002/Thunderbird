#include "main.h"

void thunderbird::Drive::plannerCalibration() {
    //this->turnToAngleRelative(0.00);
    this->moveLateral(24.00);
    this->turnToAngleRelative(-45.00);
    this->moveLateral(33.94);
    this->turnToAngleRelative(90.00);
    this->moveLateral(33.94);
    this->turnToAngleRelative(-90.00);
    this->moveLateral(33.94);
    this->turnToAngleRelative(-135.00);
    this->moveLateral(72.00);
}

void thunderbird::Drive::turnPIDCalibration() {
    this->turnToAngleRelative(30);
	this->turnToAngleRelative(60);
	this->turnToAngleRelative(45);
	this->turnToAngleRelative(-135);
	this->turnToAngleRelative(180);
}

void thunderbird::Drive::drivePIDCalibration() {
    this->moveLateral(12);
    this->moveLateral(36);
    this->moveLateral(-48);
    this->moveLateral(6);
    this->moveLateral(18);
    this->moveLateral(-24);
}