#ifndef __GLOBALS
#define __GLOBALS

#include "api.h"

namespace thunderbird {

    extern pros::Controller master;

    // Drive
    extern pros::Motor frontLeft;
    extern pros::Motor middleLeft;
    extern pros::Motor backLeft;
    
    extern pros::Motor frontRight;
    extern pros::Motor middleRight;
    extern pros::Motor backRight;

    extern pros::Motor_Group leftMotors;
    extern pros::Motor_Group rightMotors;
    extern pros::Motor_Group driveMotors;

    // Flywheel/Intake
    extern pros::Motor catapultIntakeRight;
    extern pros::Motor catapultIntakeLeft;
    extern pros::Motor_Group catapultAndIntakeMotors;

    // Pneumatics
    extern pros::ADIDigitalOut rightWing;
    extern pros::ADIDigitalOut leftWing;
    extern pros::ADIDigitalOut elevationRelease;
    extern pros::ADIDigitalOut autonRemover;

    extern pros::ADIDigitalOut blocker;

    // Sensors
    extern pros::Imu IMU1;
    extern pros::Imu IMU2;

    extern pros::Rotation catapultRotationSensor;
    extern pros::Optical kickerPlatformOptical;

    extern pros::Distance backSideDistanceSensor;
    extern pros::Distance intakeChecker;
}

#endif