#include "drive.hpp"
#include "main.h"
#include <cmath>
#include <math.h>

// !SECTION - LATERAL PID

void thunderbird::Drive::moveLateral(double dist) {

    // Reset positions for simpler error calculation
    thunderbird::driveMotors.tare_position();

    float targetPosition = dist * 46.29961 * (this->frontIsNormal ? 1 : -1); // dist * 300/2pi*r; which is 300 / (2.75 * 3.14159)
    //NOTE - Blue motors have 300ticks/rev

    double timeSpentStalled = 0;

    const double MIN_STALL_POWER = 30, MIN_STALL_VELOCITY = 4, MIN_STALL_TIME = 400;


    while(!(this->drivePID.isSettled())) {
        float error = targetPosition - this->getAvgEncoderValue();
        float power = this->drivePID.compute(error);

        pros::screen::print(TEXT_MEDIUM, 5, "power: %f", power); 

        thunderbird::driveMotors = power;
        pros::delay(10);

        // // Stall Detection
        // if(power > MIN_STALL_POWER && this->getAvgMotorVelocity() < MIN_STALL_VELOCITY) {
        //     timeSpentStalled += 10;
        // } else {
        //     timeSpentStalled = 0;
        // }

        // if(timeSpentStalled > MIN_STALL_TIME) break;
		
    }

    // pros::screen::print(TEXT_MEDIUM, 5, "settled!");
    thunderbird::driveMotors.brake();
    this->drivePID.resetSystem();

}

// !SECTION - TURN PID

void thunderbird::Drive::turnToAngleRelative(double targetAngle) {

    float targetPosition = getAvgIMURotation() + targetAngle;

    while(!(this->turnPID.isSettled())) {
        float error = targetPosition - this->getAvgIMURotation();
        float power = this->turnPID.compute(error);

        thunderbird::leftMotors = power;
        thunderbird::rightMotors = -power;
        pros::delay(10);
		pros::screen::print(TEXT_MEDIUM, 3, "Error:  %f   |   Power: %f", error, power);
    }

    pros::screen::print(TEXT_MEDIUM, 5, "settled!");

    thunderbird::driveMotors.brake();
    this->turnPID.resetSystem();

}


void thunderbird::Drive::turnToAngleAbsolute(double targetAngle, double maxSpeed) {

    while(!(this->turnPID.isSettled())) {
        float error = targetAngle - this->getAvgIMURotation();
        float power = this->turnPID.compute(error);

        if(fabs(power) > fabs(maxSpeed)){
            thunderbird::leftMotors = (power > 0) ? maxSpeed : -maxSpeed;
            thunderbird::rightMotors = (power > 0) ? -maxSpeed : maxSpeed;
        } else {
            thunderbird::leftMotors = power;
            thunderbird::rightMotors = -power;
        }

        // thunderbird::leftMotors = (fabs(power) > fabs(maxSpeed)) ? maxSpeed : power;
        // thunderbird::rightMotors = (fabs(power) > fabs(maxSpeed)) ? -maxSpeed : -power;
        pros::delay(10);
		pros::screen::print(TEXT_MEDIUM, 3, "Error:  %f   |   Power: %f", error, power);
    }

    pros::screen::print(TEXT_MEDIUM, 5, "settled!");

    thunderbird::driveMotors.brake();
    this->turnPID.resetSystem();
}

// !SECTION - SWING PID

void thunderbird::Drive::swingToAngleRelative(double targetAngle, double radius) {

    float targetPosition = getAvgIMURotation() + targetAngle;

    while(!(this->swingPID.isSettled())) {
        float error = targetPosition - this->getAvgIMURotation();
        float power = this->swingPID.compute(error);

        if(targetAngle > 0) thunderbird::leftMotors = power;
        else thunderbird::rightMotors = power;
        pros::delay(10);
		pros::screen::print(TEXT_MEDIUM, 3, "Error:  %f   |   Power: %f", error, power);
    }

    pros::screen::print(TEXT_MEDIUM, 5, "settled!");

    thunderbird::driveMotors.brake();
    this->swingPID.resetSystem();

}

// !SECTION - BANG BANG CONTROL

void thunderbird::Drive::moveLateralBangBang(double dist, double speed, double threshold, double timeout) {
    // Reset positions for simpler error calculation
    thunderbird::driveMotors.tare_position();
    float targetPosition = dist * 46.29961 * (this->frontIsNormal ? 1 : -1); // dist * 300/2pi*r; which is 300 / (2.75 * 3.14159)
    float error = 10000, timeSpentRunning = 0;

    while(fabs(error) > threshold && timeSpentRunning <= timeout) {
        error = targetPosition - this->getAvgEncoderValue();
        thunderbird::driveMotors = (error > 0) ? speed : -speed;

        pros::delay(10);
        timeSpentRunning += 10;
    }

    thunderbird::driveMotors.brake();
}

void thunderbird::Drive::turnToAngleRelativeBangBang(double targetAngle, double speed, double threshold, double timeout) {
    float targetPosition = getAvgIMURotation() + targetAngle;
    float error = 10000, timeSpentRunning = 0;

    while (error > threshold && timeSpentRunning <= timeout) {
        pros::screen::print(TEXT_MEDIUM, 11, "err: %f", error); 
        error = targetPosition - this->getAvgIMURotation();
        thunderbird::leftMotors = speed;
        thunderbird::rightMotors = -speed;

        pros::delay(10);
        timeSpentRunning += 10;
    }

    pros::screen::print(TEXT_MEDIUM, 10, "stopped"); 
    thunderbird::driveMotors.brake();
}

void thunderbird::Drive::swingToAngleRelativeBangBang(double targetAngle, double speed, double threshold, double timeout) {
    float targetPosition = getAvgIMURotation() + targetAngle;
    float error = 10000, timeSpentRunning = 0;

    while (fabs(error) > threshold && timeSpentRunning <= timeout) {
        pros::screen::print(TEXT_MEDIUM, 11, "err: %f", error); 
        error = targetPosition - this->getAvgIMURotation();
        if(targetAngle > 0 && speed > 0) thunderbird::leftMotors = speed;
        else if(targetAngle > 0 && speed < 0) thunderbird::rightMotors = speed;
        else if(targetAngle < 0 && speed < 0) thunderbird::leftMotors = speed;
        else thunderbird::rightMotors = speed;

        pros::delay(10);
        timeSpentRunning += 10;
    }

    pros::screen::print(TEXT_MEDIUM, 10, "stopped"); 
    thunderbird::driveMotors.brake();
}


// !SECTION - COMBINED UTILS

void thunderbird::Drive::translateRelative(double xTranslation, double yTranslation) {
    double turnAngle = (-1 * atan2(yTranslation, xTranslation) * 57.2958) + 90;
    double lateralDist = sqrt(yTranslation*yTranslation + xTranslation*xTranslation);
    
    this->turnToAngleRelative(turnAngle);
    this->moveLateral(lateralDist);
}