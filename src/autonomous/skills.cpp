#include "autonomous/autonomous.hpp"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"
#include "subsystems/catapultAndIntake/catapultAndIntake.hpp"
#include "subsystems/drive/drive.hpp"

void runMatchLoading(thunderbird::Kicker _kicker) {

    double timeSpentRunning = 0;

    while(true) {

        _kicker.chargeSync();

        timeSpentRunning += 10;
        if(timeSpentRunning > 35 * 1000) break;
        pros::delay(10);
    }
}

void thunderbird::Auton::skillsRoutine() {

    // SECTION -  Align to shoot, wait 30s
    this->_drive.moveLateral(-20);
    // TODO: Clamp absolute turning to 0-360
    this->_drive.turnToAngleAbsolute(-65); 
    this->_wings.openBackRight();

    runMatchLoading(_kicker);
    this->_wings.closeBackRight();
    kickerMotors = 127;
    pros::delay(150);
    kickerMotors = 0;


    // SECTION - Align with the tunnel, and go to the other side
    this->_drive.turnToAngleAbsolute(0); 
    this->_drive.moveLateral(22);
    this->_drive.turnToAngleAbsolute(-40);

    // SECTION - Go over to the other side and to the front of the goal
    this->_drive.moveLateral(80);
    this->_drive.turnToAngleAbsolute(-135);
    this->_drive.moveLateral(24);
    this->_drive.turnToAngleRelative(-35);
    this->_drive.moveLateral(40);
    this->_drive.turnToAngleAbsolute(-220);

    // SECTION - Make a push into the goal, close wings
    this->_wings.openBackWings();
    thunderbird::driveMotors = -127;
    pros::delay(1000);
    this->_wings.closeBackWings();
    pros::delay(300);

    // SECTION - Go back and realign with the barrier
    thunderbird::driveMotors = 80;
    pros::delay(1000);

    // SECTION - Move fwd a bit, turn and get in position for an angled push
    this->_drive.moveLateral(-4);
    this->_drive.turnToAngleAbsolute(45);

    this->_drive.moveLateral(-32);
    this->_drive.turnToAngleAbsolute(0);

    // SECTION - Go fwd, then make a swing push

    this->_wings.openFrontWings();
    pros::delay(200);
    this->_drive.moveLateral(24);

    // Do a swing into the goal
    thunderbird::leftMotors = 64;
    thunderbird::rightMotors = 127;
    pros::delay(1000);

    this->_wings.closeFrontWings();
    pros::delay(300);

    // SECTION - Ram into the side for to align
    this->_drive.moveLateral(-15);
    this->_drive.turnToAngleAbsolute(-135);

    thunderbird::driveMotors = -100;
    pros::delay(1800);

    // SECTION - Turn and make a push into the side
    this->_drive.moveLateral(8);
    this->_drive.turnToAngleAbsolute(90);
    this->_drive.moveLateral(-28);
    //TODO: Reduce header timeout?

    // SECTION - Go back and forth 4x 

    this->_drive.turnToAngleAbsolute(40);
    thunderbird::driveMotors = -127;
    pros::delay(800);
    this->_drive.moveLateral(12);
    this->_drive.turnToAngleAbsolute(45);

    thunderbird::driveMotors = -127;
    pros::delay(800);
    this->_drive.moveLateral(12);
    this->_drive.turnToAngleAbsolute(45);


    thunderbird::driveMotors = -127;
    pros::delay(800);
    this->_drive.moveLateral(12);
    this->_drive.turnToAngleAbsolute(45);


    thunderbird::driveMotors = -127;
    pros::delay(800);
    this->_drive.moveLateral(12);
    this->_drive.turnToAngleAbsolute(45);


    
}