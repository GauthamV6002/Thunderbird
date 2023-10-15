#include "main.h"
#include <cmath>
#include <math.h>

void thunderbird::Drive::moveLateral(double dist) {

    // Reset positions for simpler error calculation
    thunderbird::driveMotors.tare_position();

    float targetPosition = dist * 46.29961 * (this->frontIsNormal ? 1 : -1); // dist * 300/2pi*r; which is 300 / (2.75 * 3.14159)
    //NOTE - Blue motors have 300ticks/rev

    while(!(this->drivePID.isSettled())) {
        float error = targetPosition - this->getAvgEncoderValue();
        float power = this->drivePID.compute(error);

        thunderbird::driveMotors = power;
        pros::delay(10);
		// pros::screen::print(TEXT_MEDIUM, 3, "error:  %f   |   Power: %f", error, power);
    }

    // pros::screen::print(TEXT_MEDIUM, 5, "settled!");
    // pros::screen::print(TEXT_MEDIUM, 5, "is settled: %d", drivePID.isSettled());

    thunderbird::driveMotors.brake();
    this->drivePID.resetSystem();

}

// TODO: Ensure PID system is reset after each movement

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

void thunderbird::Drive::turnToAngleAbsolute(double targetAngle) {

}

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

void thunderbird::Drive::translateRelative(double xTranslation, double yTranslation) {
    double turnAngle = (-1 * atan2(yTranslation, xTranslation) * 57.2958) + 90;
    double lateralDist = sqrt(yTranslation*yTranslation + xTranslation*xTranslation);
    
    this->turnToAngleRelative(turnAngle);
    this->moveLateral(lateralDist);
}