#include "main.h"

// Subsystems
thunderbird::Drive _drive = thunderbird::Drive(); //_name convention to represent objects
// thunderbird::CatapultAndIntake _catapultAndIntake = thunderbird::CatapultAndIntake();
thunderbird::Intake _intake = thunderbird::Intake();
thunderbird::Flywheel _flywheel = thunderbird::Flywheel();
thunderbird::Wings _wings = thunderbird::Wings();
thunderbird::Elevation _elevation = thunderbird::Elevation();
thunderbird::Blocker _blocker = thunderbird::Blocker();

// Autonomous System
thunderbird::Auton autons = thunderbird::Auton(_drive, _flywheel, _intake, _wings, _elevation, _blocker);

void disabled() {}

void competition_initialize() {
	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);

	// pros::delay(2000);
}

void initialize() {
	// Configs
	_intake.setIntakeConfig();
	thunderbird::driveMotors.tare_position();

	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);
}

void autonomous() {

	// pros::delay(2000); //TODO: DELETE
	// autons.goalSideAWP();
	
	// autons.shootSideAWPOnly();
	// autons.goalSideSafe();
	autons.skillsRoutine();
	// pros::delay(2000);
	// autons.shootSideSafe();
	// autons.goalSideAWP();
}



void opcontrol() {

	/*NOTE - Control Scheme 
	
		R1: Intake IN
		R2: Intake OUT / Fire Cata

		L1: Toggle Wings
		L2: Toggle Intake Lift

		D_PAD X: Switch to Match Load Routine for Cata
		D_PAD DOWN: Switch to Automatic Action for Cata

		D_PAD B: Release Elevation Mech
		D_PAD A: Toggle Blocker
		D_PAD Y: Toggle Auton Remover
	
	*/

    while(true) {

        // Main loop functions
        _drive.arcade(true);
		// _drive.joystickL();

        // _catapultAndIntake.runCatapultAndIntake();
		_intake.runIntake();
		_flywheel.runFlywheel();

        _wings.runWings();
		_blocker.runBlocker();
		_elevation.runElevation();

		// pros::screen::print(TEXT_MEDIUM, 1, "rotation sensor: %d", thunderbird::catapultRotationSensor.get_angle()); 
		// pros::screen::print(TEXT_MEDIUM, 3, "dist sensor: %d", thunderbird::catapultCheckerDistance.get()); 

        pros::delay(10);
    }
}

