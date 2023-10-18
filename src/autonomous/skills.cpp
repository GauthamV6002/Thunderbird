#include "autonomous/autonomous.hpp"
#include "main.h"

void thunderbird::Auton::skillsRoutine() {
    // SECTION - Matchload 44 triballs
    /*
    const int matchLoadSpeed = 127, sensorThreshold = 240;

    int triballCounter = 0;
    bool hasIncremented = false;

    while(triballCounter <= 5) {
        if(thunderbird::kickerPlatformOptical.get_proximity() > sensorThreshold) {
            this->_catapultAndIntake.spinCatapult(matchLoadSpeed);
            if(!hasIncremented) {
                triballCounter++;
                hasIncremented = true;
            }
        } else {
            this->_catapultAndIntake.chargeSync();
            hasIncremented = false;
        }
    }

    this->_drive.turnToAngleRelative(60);
    this->_drive.moveLateral(19.28); */


    // SECTION - Turn and push in the two red triballs

    /* // SECTION - Drive under barrier to other side, on the left of goal
    this->_catapultAndIntake.spinCatapult(127);
    pros::delay(600);
    this->_drive.moveLateral(85.00);
    this->_drive.turnToAngleRelative(-45.00);
    this->_drive.moveLateral(30.00);
    this->_drive.turnToAngleRelative(-45.00);

    // SECTION - Push twice into left side
    this->ramAndGoBack(127, 750, 16);
    this->ramAndGoBack(127, 750, 12); */

    // SECTION - Drive to middle
    this->_drive.moveLateral(80);
    this->_drive.turnToAngleRelative(-90);
    this->_drive.moveLateral(20.04);
    this->_drive.turnToAngleRelative(-90.00);
    this->_drive.moveLateral(23.91);
    this->_drive.turnToAngleRelative(90.00);
    this->_drive.moveLateral(37.46);
    this->_drive.turnToAngleRelative(93);
    // TODO: Add turn to angle Absolute above

    // SECTION - Push twice in middle (second push is angled?)
    this->_wings.openWings();
    this->ramAndGoBack(100, 1000, 20);
    this->ramAndGoBack(100, 1000, 10);

    // SECTION - Drive to right side

    // SECTION - Push twice on right side

}

/* this->_drive.turnToAngleRelative(60);
this->_drive.moveLateral(19.28);
this->_drive.turnToAngleRelative(-220.94);
this->_drive.moveLateral(35.42);
this->_drive.turnToAngleRelative(-45.75);
this->_drive.moveLateral(68.99);
this->_drive.turnToAngleRelative(328.36);
this->_drive.moveLateral(28.03);
this->_drive.turnToAngleRelative(-56.91);
this->_drive.moveLateral(16.92);
this->_drive.turnToAngleRelative(-180.00);
this->_drive.moveLateral(16.92);
this->_drive.turnToAngleRelative(182.85);
this->_drive.moveLateral(16.19);
this->_drive.turnToAngleRelative(-186.35);
this->_drive.moveLateral(8.59);
this->_drive.turnToAngleRelative(93.66);
this->_drive.moveLateral(46.61);
this->_drive.turnToAngleRelative(86.75);
this->_drive.moveLateral(33.58);
this->_drive.turnToAngleRelative(-267.73);
this->_drive.moveLateral(31.75);
this->_drive.turnToAngleRelative(220.29);
this->_drive.moveLateral(36.33);
this->_drive.turnToAngleRelative(-180.00);
this->_drive.moveLateral(36.33);
this->_drive.turnToAngleRelative(180.34);
this->_drive.moveLateral(36.87);
this->_drive.turnToAngleRelative(89.78);
this->_drive.moveLateral(43.33);
this->_drive.turnToAngleRelative(-271.91);
this->_drive.moveLateral(15.16);
this->_drive.turnToAngleRelative(47.33);
this->_drive.moveLateral(14.34); */