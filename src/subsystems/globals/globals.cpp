#include "api.h"
#include "pros/motors.h"

namespace thunderbird {
    pros::Controller master (pros::E_CONTROLLER_MASTER);

    //REVIEW - Used Ports: 10/20/17 | 5/3/2 & 14/13/12 |  11/19

    // Drive
    pros::Motor frontLeft (5, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleLeft (3, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backLeft (2, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor frontRight (15, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor middleRight (13, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor backRight (12, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);

    pros::Motor_Group leftMotors ({frontLeft, middleLeft, backLeft});
    pros::Motor_Group rightMotors ({frontRight, middleRight, backRight});
    pros::Motor_Group driveMotors ({frontLeft, middleLeft, backLeft, frontRight, middleRight, backRight});

    // Intake & Cata from the cata being the front
    //TODO: Check if intake is a blue cart
    pros::Motor flywheel (17, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    
    pros::Motor intakeLeft (20, pros::E_MOTOR_GEAR_BLUE, true, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor intakeRight (18, pros::E_MOTOR_GEAR_BLUE, false, pros::E_MOTOR_ENCODER_COUNTS);
    pros::Motor_Group intakeMotors ({intakeLeft, intakeRight});


    // Pneumatics
    pros::ADIDigitalOut leftWing ('A', LOW);
    pros::ADIDigitalOut rightWing ('H', LOW);
    pros::ADIDigitalOut elevationRelease ('B', LOW);
    pros::ADIDigitalOut autonRemover ('G', LOW);

    pros::ADIDigitalOut blocker ('F', LOW);
    pros::ADIDigitalOut flywheelLift ('D', LOW);
 
    //Sensors
    pros::Imu IMU1 (19);
    pros::Imu IMU2 (7);
    pros::Rotation catapultRotationSensor (2);
    // pros::ADIDigitalIn cataLimitSwitch ('H');
    pros::Optical kickerPlatformOptical (12);

    // TODO - give ports
    // pros::Distance backSideDistanceSensor(19);
    // pros::Distance intakeChecker(1);
    pros::Distance catapultCheckerDistance(18);

}