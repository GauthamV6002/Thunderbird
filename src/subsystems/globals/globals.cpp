#include "api.h"
#include "pros/motors.h"

namespace thunderbird {
    pros::Controller master (pros::E_CONTROLLER_MASTER);

    //REVIEW - Used Ports: 10/20/17 | 5/3/2 & 14/13/12 |  11/19

    // Drive
    pros::Motor frontLeft (16, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleLeft (18, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backLeft (9, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor frontRight (13, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleRight (14, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backRight (3, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group leftMotors ({frontLeft, middleLeft, backLeft});
    pros::Motor_Group rightMotors ({frontRight, middleRight, backRight});
    pros::Motor_Group driveMotors ({frontLeft, middleLeft, backLeft, frontRight, middleRight, backRight});

    // Intake & Cata from the cata being the front
    pros::Motor kickerRightMotor(2, pros::E_MOTOR_GEAR_GREEN, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor kickerLeftMotor(10, pros::E_MOTOR_GEAR_RED, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor_Group kickerMotors({kickerRightMotor, kickerLeftMotor});

    pros::Motor intakeLeft (20, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor intakeRight (0, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor_Group intakeMotors ({intakeLeft, intakeRight});


    // Pneumatics
    pros::ADIDigitalOut leftFrontWing ('B', LOW);
    pros::ADIDigitalOut rightFrontWing ('D', LOW);

    pros::ADIDigitalOut leftBackWing ('A', LOW);
    pros::ADIDigitalOut rightBackWing ('C', LOW);

    pros::ADIDigitalOut elevation ('H', LOW);
 
    //Sensors
    pros::Imu IMU1 (7);
    pros::Imu IMU2 (17);
    pros::Rotation catapultRotationSensor (19);
    // pros::ADIDigitalIn cataLimitSwitch ('H');
    pros::Optical kickerPlatformOptical (5);

    // TODO - give ports
    // pros::Distance backSideDistanceSensor(19);
    // pros::Distance intakeChecker(1);
    // pros::Distance catapultCheckerDistance(18);

}