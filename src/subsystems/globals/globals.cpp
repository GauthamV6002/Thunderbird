#include "api.h"

namespace thunderbird {
    pros::Controller master (pros::E_CONTROLLER_MASTER);

    //REVIEW - Used Ports: 7/17 | 13/14/15 & 3/9/5 |  11/20, 2, 12

    // Drive
    pros::Motor frontLeft (13, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleLeft (14, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backLeft (15, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor frontRight (3, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleRight (9, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backRight (5, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group leftMotors ({frontLeft, middleLeft, backLeft});
    pros::Motor_Group rightMotors ({frontRight, middleRight, backRight});
    pros::Motor_Group driveMotors ({frontLeft, middleLeft, backLeft, frontRight, middleRight, backRight});

    // Intake & Cata from the cata being the front
    pros::Motor catapultIntakeLeft (7, pros::E_MOTOR_GEAR_RED, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor catapultIntakeRight (17, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor_Group catapultAndIntakeMotors({catapultIntakeLeft, catapultIntakeRight});

    // Pneumatics
    pros::ADIDigitalOut rightWing ('A', LOW);
    pros::ADIDigitalOut leftWing ('G', LOW);
    pros::ADIDigitalOut elevationRelease ('B', LOW);

    pros::ADIDigitalOut intakeLift ('C', LOW);
    pros::ADIDigitalOut blocker ('D', LOW);
 
    //Sensors
    pros::Imu IMU1 (20);
    pros::Imu IMU2 (11);
    pros::Rotation catapultRotationSensor (2);
    pros::ADIDigitalIn cataLimitSwitch ('H');
    pros::Optical kickerPlatformOptical (12);

    // TODO - give ports
    pros::Distance backSideDistanceSensor(19);
    pros::Distance intakeChecker(1);

}