#include "autonomous/autonomous.hpp"
#include "main.h"
#include "subsystems/catapultAndIntake/catapultAndIntake.hpp"

void thunderbird::Auton::goalSideAWP() {
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
    this->_wings.openLeft();
    this->_drive.moveLateral(12); // Go back
    this->_wings.closeLeft();
    this->_drive.turnToAngleRelative(-180); // Turn towards goal
    this->outtakeAndDeposit(100, 600, 750, 30); // Deposit other triball
    // _drive.positionFromBarrier(dist);


    // Get alliance triball
    this->_drive.turnToAngleRelative(56.82);
    this->_drive.moveLateral(50.70);
    this->_catapultAndIntake.intakeForward(127);

    this->_drive.moveLateral(-40.0); // GO back
    this->_drive.turnToAngleRelative(-56.82); //turn towards goal

    this->outtakeAndDeposit(100, 800, 750, 24); // Deposit triball
    


}

void thunderbird::Auton::shootSideAWP() {

    // SECTION - expand intake & intake triball
    this->_catapultAndIntake.spinCatapult(127);
    pros::delay(700);
    this->_catapultAndIntake.spinCatapult(0);

    this->_catapultAndIntake.intakeForward(127);
    pros::delay(400);

    // SECTION - drive fwd, turn 90, open wings and push both triballs out
    this->_drive.moveLateral(43);
    this->_wings.openLeft();
    pros::delay(300);
    this->_drive.turnToAngleRelative(80.00);
    
    // push the triballs to the other side
    // this->_drive.moveLateral(29.79);
    thunderbird::driveMotors = 127;
    pros::delay(600);

    // Go forward and deposit the alliance triball into the goal
    // this->outtakeAndDeposit(100, 600, 600, 12);
    // this->_drive.moveLateral(56.33);

    // this->_drive.turnToAngleRelative(51.00);
    // this->_drive.moveLateral(62.88);
}

void thunderbird::Auton::shootSideSafe() {
    // SECTION - Open & intake blue triball
    this->_catapultAndIntake.spinCatapult(127);
    pros::delay(700);
    this->_catapultAndIntake.spinCatapult(0);
    pros::delay(500);


    // SECTION - deposit alliance triball
    // this->_drive.moveLateral(20.00); // Move into push position
    // this->_drive.turnToAngleRelative(55.00); // Turn towards goal

    thunderbird::leftMotors = 60;
    thunderbird::rightMotors = 30;
    pros::delay(1800);
    
    // Ram twice
    this->ramAndGoBack(80, 750, 10);
    // this->ramAndGoBack(100, 750, 17);

    // SECTION - Get matchload & intake it
    this->_catapultAndIntake.expandAutonRemover();
    this->_drive.moveLateral(-5); // Move into push position
    // TODO: Make timeout for bang-bang control
    this->_drive.turnToAngleRelativeBangBang(110.00, 60); // Take out matchload by turning
    this->_drive.turnToAngleRelativeBangBang(-20.00, 40); // Take out matchload by turning

    // Intake matchload by going fwd
    this->_catapultAndIntake.intakeForward(127); // start intake
    this->_drive.moveLateral(-8); // Move into push position
    pros::delay(2500);

    // SECTION - Move outwards and towards elevation bar
    this->_drive.moveLateral(21.00);

    this->_catapultAndIntake.retractAutonRemover();
    this->_drive.turnToAngleRelative(130.00);
    this->_drive.moveLateral(-24.00);

    // SECTION - outake & touch elevation bar
    this->_catapultAndIntake.intakeForward(-127);
    pros::delay(800);
    this->_drive.turnToAngleRelative(-10);

    this->_drive.moveLateral(-33);




}