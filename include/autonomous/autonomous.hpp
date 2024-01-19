#ifndef __AUTON
#define __AUTON

#include "subsystems/globals/globals.hpp"
#include "subsystems/drive/drive.hpp"
#include "subsystems/wings/wings.hpp"
#include "subsystems/blocker/blocker.hpp"
#include "subsystems/catapultAndIntake/catapultAndIntake.hpp"
#include "subsystems/elevation/elevation.hpp"
#include "subsystems/kicker/kicker.hpp"
#include "subsystems/intake/intake.hpp"

namespace thunderbird {
    class Auton {
        public:
        Drive _drive;
        // CatapultAndIntake _catapultAndIntake;
        Kicker _kicker;
        Intake _intake;
        Wings _wings;
        Elevation _elevation;
        Blocker _blocker;

        Auton(Drive _drive, Kicker _kicker, Intake _intake, Wings _wings, Elevation _elevation, Blocker _blocker);

        // Calibration Functions
        void plannerCalibration();
        void turnPIDCalibration();
        void drivePIDCalibration();

        // Actual Autons
        void goalSideAWP();
        void goalSideSafe();
        void goalSideElims();

        void shootSideAWP();
        void shootSideAWPOnly();
        void shootSideSafe();
        void shootSideElims();

        // Skills
        void skillsRoutine();
        void skillsSetup();

        // Utils & Macros
        void outtakeAndDeposit(int power = 80, int moveDelay = 200, int time = 500, int distBack = 12);
        void ramAndGoBack(int power = 80, int time = 500, int distBack = 12);
    };
}

#endif