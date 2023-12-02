#ifndef __FLYWHEEL
#define __FLYWHEEL

#include "../../PID/PID.hpp"
namespace thunderbird {
    class Flywheel { // Class Template for 6m Drive
        public:
            const int HIGH_ARC_SPEED = 127, LOW_ARC_SPEED = 102, REST_SPEED = 80;
            bool flywheelIsLifted = false;
            bool flywheelIsActive = true;

            void runMatchLoadingHighArc();
            void runMatchLoadingLowArc();

            void raiseFlywheelLift();
            void lowerFlywheelLift();

            void toggleFlywheelLift();
            
            void spinForward(int power); // TODO: Switch to PID control on this method
            void toggleFlywheel();

            void runFlywheel();
    };
}

#endif // __FLYWHEEL
