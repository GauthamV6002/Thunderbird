#include "autonomous/autonomous.hpp"
#include "main.h"
#include "subsystems/catapultAndIntake/catapultAndIntake.hpp"

void thunderbird::Auton::goalSideAWP() {

    // SECTION - Extend Intake by raising the lift
    this->_flywheel.raiseFlywheelLift();
    pros::delay(1000);
    this->_flywheel.lowerFlywheelLift();

    this->_drive.moveLateral(60);
    this->_drive.turnToAngleRelative(-60);

    // SECTION - Put both triballs in
    // this->_wings.openRight();
    this->_drive.moveLateral(-34); // Put one in
    this->_drive.moveLateral(12); // Go back
    // this->_wings.closeRight();
    this->_drive.turnToAngleRelative(-180); // Turn towards goal
    this->outtakeAndDeposit(100, 0, 750, 30); // Deposit other triball
    // _drive.positionFromBarrier(dist);


    // Get alliance triball
    this->_drive.turnToAngleRelative(61);
    this->_drive.moveLateral(54.0);
    // this->_catapultAndIntake.intakeForward(127);
    pros::delay(750);

    this->_drive.moveLateral(-42.0); // GO back
    this->_drive.turnToAngleRelative(-61); //turn towards goal

    this->outtakeAndDeposit(100, 800, 750, 24); // Deposit triball
}

void thunderbird::Auton::goalSideSafe() {

    // SECTION - Extend Intake by raising the lift
    this->_flywheel.raiseFlywheelLift();
    pros::delay(1000);
    this->_flywheel.lowerFlywheelLift();

    this->_drive.moveLateral(53);
    this->_drive.turnToAngleRelative(90);

    this->outtakeAndDeposit(-100, 0, 600, 24); // Deposit triball

}

// void thunderbird::Auton::shootSideAWP() {

//     // SECTION - expand intake & intake triball
//     // this->_catapultAndIntake.spinCatapult(127);
//     pros::delay(700);
//     // this->_catapultAndIntake.spinCatapult(0);

//     // this->_catapultAndIntake.intakeForward(127);
//     pros::delay(400);

//     // SECTION - drive fwd, turn 90, open wings and push both triballs out
//     this->_drive.moveLateral(43);
//     this->_wings.openLeft();
//     pros::delay(300);
//     this->_drive.turnToAngleRelative(80.00);
    
//     // push the triballs to the other side
//     // this->_drive.moveLateral(29.79);
//     thunderbird::driveMotors = 127;
//     pros::delay(600);

//     // Go forward and deposit the alliance triball into the goal
//     // this->outtakeAndDeposit(100, 600, 600, 12);
//     // this->_drive.moveLateral(56.33);

//     // this->_drive.turnToAngleRelative(51.00);
//     // this->_drive.moveLateral(62.88);
// }

// void thunderbird::Auton::shootSideAWPOnly() {
//     // this->_catapultAndIntake.spinCatapult(127);
//     pros::delay(700);
//     // this->_catapultAndIntake.spinCatapult(0);
//     pros::delay(500);

//     // SECTION Move fwd and remove matchload
//     this->_drive.moveLateral(16);
//     // this->_catapultAndIntake.expandAutonRemover();
//     this->_drive.turnToAngleRelativeBangBang(150, 40);

//     // SECTION Line up and touch elevation bar

//     this->_drive.turnToAngleAbsolute(-135);
//     this->_drive.moveLateral(36.00);

//     this->_drive.moveLateral(-5);
//     this->_drive.turnToAngleRelative(-90.00);
//     this->_drive.moveLateral(50.00);


// }

void thunderbird::Auton::shootSideSafe() {

    // Remove triball from matchload zone
    // pros::delay(2000);
    this->_wings.expandAutonRemover();
    pros::delay(200);
    this->_drive.turnToAngleRelative(-205);
    this->_wings.retractAutonRemover();
    pros::delay(200);
    // this->_drive.turnToAngleRelative(65);

    // Go to elevation bar & raise blocker to touch it
    this->_drive.moveLateral(-37.5);
    this->_blocker.openBlocker();
}