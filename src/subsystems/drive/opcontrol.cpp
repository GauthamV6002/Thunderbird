#include "main.h"

// Tank function
void thunderbird::Drive::joystickL() {

	// Check if brake is active - if so, BRAKE!
	// if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B) && !master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
	// 	this->brakeAll();
	// 	return;
	// }

    int analogLeftY = this->inverted ? -1 * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) : master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int analogLeftX = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);

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
	this->checkInversion();
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

void thunderbird::Drive::arcade(bool invertTurning) {
    int analogLeftY = this->inverted ? -1 * master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) : master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int analogRightX = invertTurning ? -1 * master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X) : master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

    //Standard Drive setup; send joystick y to all motors; subtract/add joystick x from left/right side, respectively
    thunderbird::frontLeft = analogLeftY + analogRightX;
	thunderbird::middleLeft = analogLeftY + analogRightX;
	thunderbird::backLeft = analogLeftY + analogRightX;

	thunderbird::frontRight = analogLeftY - analogRightX;
	thunderbird::middleRight = analogLeftY - analogRightX;
	thunderbird::backRight = analogLeftY - analogRightX;

	// Check inversion control
	// this->checkInversion();
	// lol no inversion haha boo
}
