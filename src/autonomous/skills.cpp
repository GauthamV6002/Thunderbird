#include "autonomous/autonomous.hpp"
#include "main.h"
#include "pros/motors.h"
#include "subsystems/catapultAndIntake/catapultAndIntake.hpp"
#include "subsystems/flywheel/flywheel.hpp"
#include "subsystems/drive/drive.hpp"

// TODO: DONT USE TURNRELATIVE! TURN ABSOLUTE REMOVES COMPOUNDING ERROR
// TODO: FIX PLANNER WEBSITE TO USE TURN ABSOLUTE

void runMatchLoading(int numTriballs, thunderbird::CatapultAndIntake _catapultAndIntake) {
    const int matchLoadSpeed = 127, sensorThreshold = 240;

    int triballCounter = 0;
    bool hasIncremented = false;

    const int rotationSensorMin = 5000, distanceSensorMax = 100;

    double timeSpentRunning = 0;
    double timeSpentStalled = 0, stallThreshold = 100, minStallTime = 1500;

    while(triballCounter <= numTriballs) {

        bool triballIsInsideCata = (thunderbird::catapultRotationSensor.get_position() > rotationSensorMin && thunderbird::catapultCheckerDistance.get() < distanceSensorMax);

        if(thunderbird::kickerPlatformOptical.get_proximity() > sensorThreshold) {
            _catapultAndIntake.spinCatapult(matchLoadSpeed);
            if(!hasIncremented) {
                triballCounter++;
                hasIncremented = true;
            }
        }  else if (triballIsInsideCata) {
            _catapultAndIntake.spinCatapult(127);
        } else {
            _catapultAndIntake.chargeSync();
            hasIncremented = false;
            if(thunderbird::catapultRotationSensor.get_velocity() < stallThreshold) {
                timeSpentStalled += 10;
            } else {
                timeSpentStalled = 0;
            }

            // Break out of stall
            if(timeSpentStalled > minStallTime) {
                _catapultAndIntake.spinCatapult(-127);
                pros::delay(400);
                timeSpentRunning += 400;
                _catapultAndIntake.spinCatapult(127);
                pros::delay(400);
                timeSpentRunning += 400;
            }
        }

        timeSpentRunning += 10;
        pros::screen::print(pros::E_TEXT_MEDIUM, 4, "timeSpentRunning: %f", timeSpentRunning); 
        if(timeSpentRunning > 35000) break;
        pros::delay(10);
    }
}

void thunderbird::Auton::skillsRoutine() {

    // SECTION - Release Intake & 
    this->_flywheel.spinForward(127*0.8);
    this->_flywheel.raiseFlywheelLift();
    pros::delay(750);
    this->_flywheel.lowerFlywheelLift();
    pros::delay(60 * 1000);

    // this->_drive.turnToAngleRelative(165);
    // this->_drive.moveLateral(58.83);
    // this->_drive.turnToAngleRelative(68);
    // this->_wings.openWings();
    // pros::delay(400);
    // thunderbird::driveMotors = 127;
}