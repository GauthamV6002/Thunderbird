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
    extern pros::Motor kickerRightMotor;
    extern pros::Motor kickerLeftMotor;
    extern pros::Motor_Group kickerMotors;

    extern pros::Motor flywheel;
    extern pros::Motor intakeLeft;
    extern pros::Motor intakeRight;
    extern pros::Motor_Group intakeMotors;

    // Pneumatics
    extern pros::ADIDigitalOut leftFrontWing;
    extern pros::ADIDigitalOut rightFrontWing;

    extern pros::ADIDigitalOut leftBackWing;
    extern pros::ADIDigitalOut rightBackWing;
 
    extern pros::ADIDigitalOut elevation;

    // Sensors
    extern pros::Imu IMU1;
    extern pros::Imu IMU2;

    extern pros::Rotation catapultRotationSensor;
    extern pros::Optical kickerPlatformOptical;

    extern pros::Distance backSideDistanceSensor;
    extern pros::Distance intakeChecker;
    extern pros::Distance catapultCheckerDistance;
}

#endif