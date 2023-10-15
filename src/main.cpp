#include "main.h"

// Object Initializations
thunderbird::Drive _drive = thunderbird::Drive(); //_name convention to represent objects
thunderbird::CatapultAndIntake _catapultAndIntake = thunderbird::CatapultAndIntake();
thunderbird::Wings _wings = thunderbird::Wings();
thunderbird::Elevation _elevation = thunderbird::Elevation();

thunderbird::Blocker _blocker = thunderbird::Blocker();

void disabled() {}

void competition_initialize() {
	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);

	pros::delay(2000);
}

void initialize() {
	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);

	pros::delay(2000);
}

void autonomous() {

	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);

	pros::delay(2000);

	


}



void opcontrol() {

	/*NOTE - Control Scheme 
	
		R1: Intake IN
		R2: Intake OUT / Fire Cata

		L1: Toggle Wings
		L2: Toggle Intake Lift

		D_PAD X: Switch to Match Load Routine for Cata
		D_PAD DOWN: Switch to Manual Action for Cata

		D_PAD B: Release Elevation Mech
		D_PAD A: Toggle Blocker
	
	*/


	// Configs
	_catapultAndIntake.setCatapultAndIntakeConfig();
	thunderbird::driveMotors.tare_position();


    while(true) {

        // Main loop functions
        _drive.arcade(true);
		// _drive.joystickL();

        _catapultAndIntake.runCatapultAndIntake();

        _wings.runWings();
		_blocker.runBlocker();
		_elevation.runElevation();

		// pros::screen::print(TEXT_MEDIUM, 2, "avg encoder value:  %f", _drive.getAvgEncoderValue(3, 10));

		pros::screen::print(TEXT_MEDIUM, 9, "IMU1: %f | IMU2: %f", thunderbird::IMU1.get_rotation(), thunderbird::IMU2.get_rotation()); 
		pros::screen::print(TEXT_MEDIUM, 10, "avg IMU: %f", _drive.getAvgIMURotation()); 

        pros::delay(10);
    }
}

