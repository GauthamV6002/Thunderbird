#include "main.h"

// Subsystems (_name convention to represent objects)
thunderbird::Drive _drive = thunderbird::Drive();
thunderbird::Intake _intake = thunderbird::Intake();
thunderbird::Kicker _kicker = thunderbird::Kicker();
thunderbird::Wings _wings = thunderbird::Wings();
thunderbird::Elevation _elevation = thunderbird::Elevation();
thunderbird::Blocker _blocker = thunderbird::Blocker();

// Autonomous System
thunderbird::Auton autons = thunderbird::Auton(_drive, _kicker, _intake, _wings, _elevation, _blocker);

void disabled() {}

void competition_initialize() {
	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);

	// pros::delay(2000);
}

void initialize() {
	// Configs
	_intake.setIntakeConfig();
	thunderbird::catapultRotationSensor.reset_position();
	thunderbird::driveMotors.tare_position();

	thunderbird::IMU1.reset(false);
	thunderbird::IMU2.reset(false);
}

void autonomous() {
	// autons.goalSideAWP();
	// autons.shootSideSafe();
	autons.skillsRoutine();
}



void opcontrol() {

	// SKILLS ONLY
	_drive.moveLateral(-20);
    // TODO: Clamp absolute turning to 0-360
    _drive.turnToAngleAbsolute(-65); 
    _wings.openBackWings();

    while(true) {

        // Main loop functions
        _drive.arcade(true, false) ;
		// _drive.curvatureDrive(false);
		// _drive.joystickL();

		_intake.runIntake();
		_kicker.runKicker();
		// _flywheel.runFlywheel();

        _wings.runWings();
		// _blocker.runBlocker();
		_elevation.runElevation();

        pros::delay(5);
    }
}

