#include "main.h"
#include "pros/misc.h"

// Helper functions for motor control

// Inversion checker
void thunderbird::Drive::checkInversion() {
    // Check inversion control
	if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		this->inverted = !this->inverted; 
	}
}

// Circle to Square Mapping Fuction
// TODO: Move to Utilities/math_utils.cpp Namespace
void thunderbird::Drive::circleToSquare(double u, double v, double& x, double& y) {

    double u2 = u * u;
    double v2 = v * v;
    double twosqrt2 = 2.0 * sqrt(2.0);
    double subtermx = 2.0 + u2 - v2;
    double subtermy = 2.0 - u2 + v2;
    double termx1 = subtermx + u * twosqrt2;
    double termx2 = subtermx - u * twosqrt2;
    double termy1 = subtermy + v * twosqrt2;
    double termy2 = subtermy - v * twosqrt2;

    double epsilon = 0.001;
    if (fabs(termx2) < epsilon) {
        termx2 = 0.0;
    }
    if (fabs(termy2) < epsilon) {
        termy2 = 0.0;
    }

    x = 0.5 * sqrt(fabs(termx1)) - 0.5 * sqrt(fabs(termx2));
    y = 0.5 * sqrt(fabs(termy1)) - 0.5 * sqrt(fabs(termy2));
}

float thunderbird::Drive::getAvgEncoderValue(int numIterations, int delayBetweenIterations) {
    // TODO: Make sure the directions don't end up doing something weird
    
    float sum = 0;

    for(int i = 0; i < numIterations; i++) {
        sum += thunderbird::frontLeft.get_position() + thunderbird::middleLeft.get_position() + thunderbird::backLeft.get_position() + thunderbird::frontRight.get_position() + thunderbird::middleRight.get_position() + thunderbird::backRight.get_position();
        pros::delay(delayBetweenIterations);
    }
    
    return sum / (6 * numIterations);
}

float thunderbird::Drive::getAvgEncoderValue() {
    return (thunderbird::frontLeft.get_position() + thunderbird::middleLeft.get_position() + thunderbird::backLeft.get_position() + thunderbird::frontRight.get_position() + thunderbird::middleRight.get_position() + thunderbird::backRight.get_position()) / 6.0;
}

float thunderbird::Drive::getAvgIMURotation(int numIterations, int delayBetweenIterations) {
    float sum = 0;

    for(int i = 0; i < numIterations; i++) {
        sum += thunderbird::IMU1.get_rotation() + thunderbird::IMU2.get_rotation();
        pros::delay(delayBetweenIterations);
    }

    // TODO: ensure the encoders bloody work omfl

    return sum / (2*numIterations);
}

float thunderbird::Drive::getAvgIMURotation() {
    return ((thunderbird::IMU1.get_rotation() + thunderbird::IMU2.get_rotation()) / 2);
}

void thunderbird::Drive::reverseFront() {
    this->frontIsNormal = !(this->frontIsNormal);
}