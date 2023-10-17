#include "autonomous/autonomous.hpp"
#include "main.h"

void thunderbird::Auton::goalSideElims() {
    this->_drive.reverseFront();

    //SECTION - Extend Intake by lowering cata // Open left wing to push triball
    this->_wings.openLeft();
    this->_catapultAndIntake.spinCatapult(127);
    pros::delay(400);
    this->_catapultAndIntake.spinCatapult(0);
    this->_wings.closeLeft();

    this->_drive.moveLateral(57); // OLD

    // SECTION - Head to mid-barrier triball **
    // thunderbird::driveMotors = -127; // go at full power
    // pros::delay(775);
    // thunderbird::leftMotors = -127; // go at full power
    // thunderbird::rightMotors = -80; // go at full power
    // pros::delay(700);

    

    // SECTION - Intake, swing, and align **
    this->_catapultAndIntake.intakeForward(127);
    thunderbird::leftMotors = -127;
    pros::delay(600); //TODO - Adjust
    thunderbird::driveMotors = -127;
    pros::delay(200); //TODO - Adjust
    thunderbird::driveMotors = 0;
    this->_catapultAndIntake.intakeForward(0);
    // this->_catapultAndIntake.intakeFully();

    // SECTION - Put both triballs in
    this->_drive.moveLateral(-34); // Put one in
    // this->_wings.openLeft();
    this->_drive.moveLateral(12); // Go back
    // this->_wings.closeLeft();
    this->_drive.turnToAngleRelative(-180); // Turn towards goal
    this->outtakeAndDeposit(100, 600, 750); // Deposit other triball
    // _drive.positionFromBarrier(dist);

    //TODO - Make sure both went in with sensor control

    // SECTION - Get the third triball & deposit it
    this->_drive.turnToAngleRelative(142.0);
    this->_catapultAndIntake.intakeForward(127);
    this->_drive.moveLateral(32.00);
    this->_drive.moveLateral(-20.5); // Come back a bit
    this->_drive.turnToAngleRelative(-150); // Turn towards goal
    this->outtakeAndDeposit(127, 400, 1000);
    // _drive.positionFromBarrier(dist);
}



void thunderbird::Auton::shootSideElims() {
    // this->_drive._catapultAndIntake.runCatapultAndIntake();
}