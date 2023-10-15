#include "autonomous/autonomous.hpp"
#include "main.h"

void thunderbird::Auton::goalSideElims() {
    //2 should be a swing into intaking the triball
    //engage wings after 2
    // Dont rotate after 2

    // 4 is a back-up, dont rotate

    // Head to mid-barrier triball **
    this->_drive.turnToAngleRelative(-33.94);
    this->_drive.moveLateral(59.60);

    // Intake, swing, and align **
    this->_catapultAndIntake.intakeForward(127);
    thunderbird::leftMotors = -127;
    pros::delay(600); //TODO - Adjust
    thunderbird::driveMotors = 0;
    // this->_catapultAndIntake.intakeFully();

    // Open left wing, push a bit, turn, and push more TODO - maybe push first fully
    this->_wings.openLeft();
    this->_drive.moveLateral(12); // TODO - might need to change
    this->_wings.closeLeft();
    this->_drive.turnToAngleRelative(-180); 

    // Push both triballs in (intaked one and the one @ mid) **
    this->outtakeAndDeposit();



    // Turn towards final green triball, and go get it
    this->_catapultAndIntake.intakeForward(127);
    this->_drive.turnToAngleRelative(-37.22);
    this->_drive.moveLateral(33.99);
    // this->_catapultAndIntake.intakeFully();

    // Put it into the goal
    //TODO - maybe use a curve, since it auto-aligns with goal
    this->_drive.turnToAngleRelative(180);
    this->_drive.moveLateral(16.97);
    this->_drive.turnToAngleRelative(36.0);
    this->outtakeAndDeposit(80, 200, 750, 18); // TODO 18 needs to be tuned


    this->_drive.turnToAngleRelative(180.00);
    this->_drive.moveLateral(20.92);
    this->_drive.turnToAngleRelative(-123.50);
    this->_drive.moveLateral(38.39);
    this->_drive.turnToAngleRelative(175.81);
    this->_drive.moveLateral(47.68);
    this->_drive.turnToAngleRelative(-231.81);
    this->_drive.moveLateral(29.15);

}

void thunderbird::Auton::shootSideElims() {
    // this->_drive._catapultAndIntake.runCatapultAndIntake();
}