#ifndef __INTAKE
#define __INTAKE

#include "../../PID/PID.hpp"
namespace thunderbird {
    class Intake { // Class Template for 6m Drive
        public:
            
            void setIntakeConfig();

            // TODO: Enable Automatic sensing
            void intakeIn(int power);
            void runIntake();

            // Auton Macros
            void outtake(int time = 600, int power = 127);

    };
}

#endif // __INTAKE
