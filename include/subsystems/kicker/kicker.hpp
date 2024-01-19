#ifndef __FLYWHEEL
#define __FLYWHEEL

#include "../../PID/PID.hpp"
namespace thunderbird {
    class Kicker { // Class Template for 6m Drive
        public:

            bool matchLoadRoutineIsActive = false;
            double CHARGED_POSITION_ANGLE = 55 * 100; 
            PID::PID_System kickerPID = PID::PID_System(0, 0.1, 0.2, 0, 0, 10 * 100, 500, 4000);

            void runMatchLoadRoutine();
            void runKicker();

            void chargeSync();
    };
}

#endif // __FLYWHEEL
