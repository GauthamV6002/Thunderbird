#ifndef __AUTON
#define __AUTON

#include "subsystems/globals/globals.hpp"
#include "subsystems/drive/drive.hpp"
#include "subsystems/wings/wings.hpp"
#include "subsystems/blocker/blocker.hpp"
#include "subsystems/catapultAndIntake/catapultAndIntake.hpp"
#include "subsystems/elevation/elevation.hpp"

namespace thunderbird {
    class Auton {
        public:
        Drive _drive;
        CatapultAndIntake _catapultAndIntake;
        Wings _wings;
        Elevation _elevation;

        Auton(Drive _drive, CatapultAndIntake _catapultAndIntake, Wings _wings, Elevation _elevation);

        // Calibration Functions
        void plannerCalibration();
        void turnPIDCalibration();
        void drivePIDCalibration();

        // Actual Autons
        void goalSideAWP();
        void goalSideElims();

        void shootSideAWP();
        void shootSideSafe();
        void shootSideElims();

        // Skills
        void skillsRoutine();

        // Utils & Macros
        void outtakeAndDeposit(int power = 80, int moveDelay = 200, int time = 500, int distBack = 12);
    };
}

#endif