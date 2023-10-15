// #include "main.h"

// // TODO: Ram function, stall detection

// void thunderbird::Drive::goalSideAWP() {
// 	// turn45 &outtake and turn back after first move
// 	//dont turn at @4 and at @7

// 	//this->turnToAngleRelative(0.00);
// 	this->reverseFront();

// 	thunderbird::catapultAndIntakeMotors = 50;

// 	// fwd & outtake
// 	this->moveLateral(48.63);
// 	this->turnToAngleRelative(80);
// 	thunderbird::catapultAndIntakeMotors = -127;
// 	pros::delay(1000);


// 	//Get next triball
// 	this->turnToAngleRelative(-90);
// 	thunderbird::catapultAndIntakeMotors = 127;
// 	pros::delay(750);
// 	this->moveLateral(10.0);
// 	pros::delay(250);
// 	thunderbird::catapultAndIntakeMotors.brake();

// 	//deposit
// 	this->turnToAngleRelative(117.90);
// 	thunderbird::catapultAndIntakeMotors = -60;
// 	pros::delay(750);
// 	this->moveLateral(21.11);
	
// 	//GO back & turn
// 	this->moveLateral(-10.15);
// 	this->turnToAngleRelative(160); //360 - abs(180 + x)

// 	// Get another triball
// 	this->moveLateral(28.89);
// 	this->turnToAngleRelative(180.12);
// 	this->moveLateral(38.00);
// 	this->turnToAngleRelative(-179.61);
// 	this->moveLateral(9.37);
// 	this->turnToAngleRelative(-31.72);
// 	this->moveLateral(33.16);
// 	this->turnToAngleRelative(192.85);
// 	this->moveLateral(39.44);
// }

// void thunderbird::Drive::goalSideElims() {
// 	this->turnToAngleRelative(-34.34);
// 	this->moveLateral(60.83);

// 	this->turnToAngleRelative(-70.04);
// 	this->moveLateral(25.14);

// 	this->turnToAngleRelative(183.14);
// 	this->moveLateral(64.77);

// 	this->turnToAngleRelative(-168.75);
// 	this->moveLateral(8.59);

// 	this->turnToAngleRelative(-35.75);
// 	this->moveLateral(40.09);
	
// 	this->turnToAngleRelative(175.28);
// 	this->moveLateral(25.66);
	
// 	this->turnToAngleRelative(39.14);
// 	this->moveLateral(22.39);
	
// 	this->turnToAngleRelative(-179.34);
// 	this->moveLateral(22.23);
	
// 	this->turnToAngleRelative(-118.54);
// 	this->moveLateral(42.34);
	
// 	this->turnToAngleRelative(179.51);
// 	this->moveLateral(42.54);
	
// 	this->turnToAngleRelative(-240.30);
// 	this->moveLateral(22.90);
	
// }
















/*!SECTION

	// TODO: Histogram Array for sensor values?

	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);
	pros::delay(2000);

	_catapultAndIntake.intakeForward(127);

	_drive.moveLateral(-60);
	_drive.turnToAngleRelative(-110);
	
	// TODO: Make a delayed action function

	_catapultAndIntake.intakeForward(-127);
	pros::delay(500);

	_catapultAndIntake.intakeForward(0);
	
	// TODO: Make a pushing function with max power
	thunderbird::driveMotors = -100;
	pros::delay(750);


	// _drive.moveLateral(24);






*/