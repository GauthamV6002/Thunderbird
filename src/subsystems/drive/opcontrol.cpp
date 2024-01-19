#include "main.h"
#include "pros/misc.h"

// Tank function
void thunderbird::Drive::joystickL() {

	// Check if brake is active - if so, BRAKE!
	// if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
	// 	this->brakeAll();
	// 	return;
	// }

    int analogLeftY = this->inverted ? -1 * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) : master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int analogLeftX = -1 * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

	// If R2 is pressed, restrict movement to Y-Axis only
	if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) analogLeftX = 0;

	if(abs(analogLeftY) < this->deadzoneRange) analogLeftY = 0;
	if(abs(analogLeftX) < this->deadzoneRange) analogLeftX = 0;

	double scaledX, scaledY;

	//Inputs are for a unit circle, so must be scaled down by 127
	circleToSquare(analogLeftY / 127.0, analogLeftX / 127.0, scaledY, scaledX);

	// Rescale to 0 - 127
	scaledX *= 127;
	scaledY *= 127;

    //Standard Drive setup; send joystick y to all motors; subtract/add joystick x from left/right side, respectively
    thunderbird::frontLeft = scaledY + scaledX;
	thunderbird::middleLeft = scaledY + scaledX;
	thunderbird::backLeft = scaledY + scaledX;

	thunderbird::frontRight = scaledY - scaledX;
	thunderbird::middleRight = scaledY - scaledX;
	thunderbird::backRight = scaledY - scaledX;

	// Check inversion control
	// this->checkInversion();
}

void thunderbird::Drive::tank() {
	int analogLeftY = this->inverted ? -1 * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) : master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int analogRightY = this->inverted ? -1 * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y) : master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);

    //Standard Drive setup; send joystick y to all motors; subtract/add joystick x from left/right side, respectively
    thunderbird::frontLeft = analogLeftY;
	thunderbird::middleLeft = analogLeftY;
	thunderbird::backLeft = analogLeftY;

	thunderbird::frontRight = analogRightY;
	thunderbird::middleRight = analogRightY;
	thunderbird::backRight = analogRightY;

	this->checkInversion();
}

void thunderbird::Drive::arcade(bool invertTurning, bool joystickCurves) {
    
	// int analogLeftY, analogRightX;
	double analogLeftY =  master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	double analogRightX =  master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) * 1.5;

	// if (joystickCurves) {
	// 	analogLeftY =  master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	// 	analogRightX =  this->curveRemap(master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), turnCurveScale);
	// } else {
		
	// }
	
    
	if(invertTurning) analogRightX *= -1;

    //Standard Drive setup; send joystick y to all motors; subtract/add joystick x from left/right side, respectively
    thunderbird::frontLeft = analogLeftY + analogRightX;
	thunderbird::middleLeft = analogLeftY + analogRightX;
	thunderbird::backLeft = analogLeftY + analogRightX;

	thunderbird::frontRight = analogLeftY - analogRightX;
	thunderbird::middleRight = analogLeftY - analogRightX;
	thunderbird::backRight = analogLeftY - analogRightX;

	// if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) this->lateralCurveScale -= 0.1;
	// if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) this->lateralCurveScale += 0.1;
	// pros::screen::print(TEXT_MEDIUM, 0, "lateralCurveScale: %f", lateralCurveScale); 

	// if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) this->turnCurveScale -= 0.1;
	// if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) this->turnCurveScale += 0.1;
	// pros::screen::print(TEXT_MEDIUM, 1, "turnCurveScale: %f", turnCurveScale); 
}

void thunderbird::Drive::curvatureDrive(bool singleStick) {

	double ithrottle = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
	double iturn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

	
	bool turnInPlace = false;
	double linearCmd = ithrottle;
	if (fabs(ithrottle) < DRIVE_DEADBAND && fabs(iturn) > DRIVE_DEADBAND) {
		// The controller joysticks can output values near zero when they are
		// not actually pressed. In the case of small inputs like this, we
		// override the throttle value to 0.
		linearCmd = 0.0;
		turnInPlace = true;
	} else if (ithrottle - prevThrottle > DRIVE_SLEW) {
		linearCmd = prevThrottle + DRIVE_SLEW;
	} else if (ithrottle - prevThrottle < -(DRIVE_SLEW * 2)) {
		// We double the drive slew rate for the reverse direction to get
		// faster stopping.
		linearCmd = prevThrottle - (DRIVE_SLEW * 2);
	}

	// Double sinusoidal turn remapping
	double denominator = sin(PI / 2 * CD_TURN_NONLINEARITY);
	double firstRemapIteration = sin(PI / 2 * CD_TURN_NONLINEARITY * iturn) / denominator;
	double remappedTurn =  sin(PI / 2 * CD_TURN_NONLINEARITY * firstRemapIteration) / denominator;

	pros::screen::print(TEXT_MEDIUM, 4, "remappedTurn: %f", remappedTurn); 

	double left, right;
	if (turnInPlace) {
		// The remappedTurn value is squared when turning in place. This
		// provides even more fine control over small speed values.
		left = remappedTurn * std::abs(remappedTurn);
		right = -remappedTurn * std::abs(remappedTurn);

	} else {
		double negInertiaPower = (iturn - prevTurn) * CD_NEG_INERTIA_SCALAR;
		negInertiaAccumlator += negInertiaPower;

		double angularCmd =
			fabs(linearCmd) *  // the more linear vel, the faster we turn
				(remappedTurn + negInertiaAccumlator) *
				CD_SENSITIVITY -  // we can scale down the turning amount by a
								// constant
			quickStopAccumlator;

		right = left = linearCmd;
		left += angularCmd;
		right -= angularCmd;

		pros::screen::print(TEXT_MEDIUM, 6, "angularCmd: %f", angularCmd); 
		pros::screen::print(TEXT_MEDIUM, 7, "linearCmd: %f", linearCmd); 

		if (negInertiaAccumlator > 1) {
			negInertiaAccumlator -= 1;
		} else if (negInertiaAccumlator < -1) {
			negInertiaAccumlator += 1;
		} else {
			negInertiaAccumlator = 0;
		}

		if (quickStopAccumlator > 1) {
			quickStopAccumlator -= 1;
		} else if (quickStopAccumlator < -1) {
			quickStopAccumlator += 1;
		} else {
			quickStopAccumlator = 0.0;
		}
	}

	prevTurn = iturn;
	prevThrottle = ithrottle;
	
	thunderbird::leftMotors = left;
	thunderbird::rightMotors = right;

	pros::screen::print(TEXT_MEDIUM, 0, "left: %f", left); 
	pros::screen::print(TEXT_MEDIUM, 2, "right: %f", right); 

}