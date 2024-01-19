#include "autonomous/autonomous.hpp"
#include "main.h"
#include "subsystems/catapultAndIntake/catapultAndIntake.hpp"


void thunderbird::Auton::shootSideAWP() {
    
    // SECTION - Hit preload into goal, go fwd and turn to descore matchload
    _wings.openFrontLeft();
    pros::delay(300);
    _wings.closeFrontLeft();
    _drive.moveLateral(4);
    _drive.turnToAngleAbsolute(90);
    _wings.openBackRight();
    pros::delay(300);
    _drive.turnToAngleAbsolute(-23);
    _wings.closeBackRight();

    // SECTION - Rush towards the middle triball, intake it and come back
    _intake.intakeIn(127);
    _drive.moveLateral(49);
    pros::delay(400);
    _intake.intakeIn(127);
    _drive.moveLateral(-49);

    _drive.turnToAngleAbsolute(45);
    _intake.intakeIn(-127);
    pros::delay(600);

    // SECTION - Push the alliance match load in
    _drive.turnToAngleAbsolute(90);
    _drive.moveLateral(-24);
    _drive.turnToAngleAbsolute(135);
    // _wings.openBackWings();
    _drive.moveLateral(-8);
    _drive.moveLateral(5);
    // _wings.closeBackWings();

    // SECTION - Go touch the bar
    _drive.turnToAngleAbsolute(90);
    _drive.moveLateral(32);
    _drive.turnToAngleAbsolute(45);
    _drive.moveLateral(25);

}



// void thunderbird::Auton::goalSideAWP() {

//     // SECTION - Intake inwards, extend Intake by raising the lift
//     this->_intake.intakeIn(127);
//     // this->_flywheel.raiseFlywheelLift();
//     pros::delay(600);
//     // this->_flywheel.lowerFlywheelLift();

//     // SECTION - Move forward and outtake towards the goal
//     this->_drive.moveLateral(43);
//     this->_drive.turnToAngleAbsolute(60);

//     this->_intake.outtake(500, 40);

//     // SECTION - Turn to get the next triball, get it, and then outtake it also
//     this->_drive.turnToAngleAbsolute(-95);
//     this->_intake.intakeIn(127);
//     this->_drive.moveLateral(25);

//     this->_drive.turnToAngleAbsolute(70);
    
//     // Drive fwd while outtaking
//     this->_drive.moveLateral(8);
//     this->_intake.intakeIn(-100);
//     pros::delay(700);

//     // SECTION - Turn towards mid triball, Go for the mid triball by aligning with the barrier
//     this->_drive.turnToAngleAbsolute(-40);
//     this->_intake.intakeIn(127);
//     this->_drive.moveLateral(18);

//     thunderbird::leftMotors = 0;
//     thunderbird::rightMotors = 110;
//     pros::delay(500);
//     thunderbird::driveMotors = 50;
//     pros::delay(500);
//     thunderbird::driveMotors = 0;

//     // Turn to face the goal via absolute coords
//     this->_drive.turnToAngleAbsolute(-90);
//     this->_drive.moveLateral(-6);
//     this->_drive.moveLateral(6);


//     // SECTION - Turn around and push ALL the triballs in
//     this->_drive.turnToAngleAbsolute(90);
//     this->_intake.intakeIn(0);
//     this->_wings.openFrontWings();

//     this->_drive.moveLateral(30);

//     thunderbird::driveMotors = 127;
//     pros::delay(1000);
//     this->_drive.moveLateral(-12);
// }

// void thunderbird::Auton::goalSideSafe() {

//     // SECTION - Extend Intake by raising the lift
//     // this->_flywheel.raiseFlywheelLift();
//     pros::delay(1000);
//     // this->_flywheel.lowerFlywheelLift();

//     this->_drive.moveLateral(53);
//     this->_drive.turnToAngleRelative(90);

//     this->outtakeAndDeposit(-100, 0, 600, 24); // Deposit triball

// }

void thunderbird::Auton::shootSideSafe() {

    // Release intake
    this->_intake.intakeIn(100);

    // Remove triball from matchload zone
    _wings.openBackRight();
    pros::delay(600);
    this->_drive.turnToAngleAbsolute(-180);
    _wings.closeBackRight();
    pros::delay(600);

    _drive.moveLateral(-20);
    _drive.turnToAngleAbsolute(-45);

    _drive.moveLateral(25);
    _intake.intakeIn(-127);
}