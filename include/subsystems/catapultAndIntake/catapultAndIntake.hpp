#ifndef __CATA_INTAKE
#define __CATA_INTAKE

#include "../../PID/PID.hpp"

namespace thunderbird {
    class CatapultAndIntake {
        public: 

        PID::PID_System catapultPID = PID::PID_System(0, 0.1, 0.2, 0, 0, 10 * 100, 500, 4000);

        const double STORAGE_ANGLE = 65 * 100, MATCH_ANGLE = 40 * 100; 
        int cycleState = 0; // 0 is normal, 1 is matchload, 2 is manual action

        bool triballIntaked = false;

        // Main opcontrol loop function vm,l
        void runCatapultAndIntake();

        void runAutomaticReload(); // While Driving
        void runManualAction(); // In case something brakes
        void runMatchLoadRoutine(); // For Match loading based on distance sensor

        // Init function; sets brake mode
        void setCatapultAndIntakeConfig();

        // Intake Functions
        void operateIntake(int direction);

        // Util Functions
        void charge();
        void fire();

        void intakeFully(int timeout = 2000);

        void spinCatapult(int power);
        void intakeForward(int power);
    };
}

#endif