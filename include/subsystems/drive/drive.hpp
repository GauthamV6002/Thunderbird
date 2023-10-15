#ifndef __DRIVE
#define __DRIVE

#include "../../PID/PID.hpp"
namespace thunderbird {
    class Drive { // Class Template for 6m Drive
        public:

            bool inverted = false;
            int deadzoneRange = 10;
            bool frontIsNormal = true; // Normal is with the cata being the front

            // Drive & Turn PID
            // 0.2, 0.012, 0.7, 250 = accurate w/ integral
            // 0.2, 0.0, 1.425, 250 = best
            PID::PID_System drivePID = PID::PID_System(0, 0.2, 0.0, 1.425, 250, 50, 300, 40000);

            // 0.86 of P only = accurate
            // 0.825, 0, 4.75
            // 0.70 works nice
            // TODO: Increase timeout for larger calcs : changed minSettleTime from 600->400
            PID::PID_System turnPID = PID::PID_System(0, 2.5, 0.0, 17.5, 100, 5, 400, 2000);


            PID::PID_System swingPID = PID::PID_System(0, 2.5, 0.0, 17.5, 100, 5, 600, 8000);

            // Driver control tank function
            void tank();
            void joystickL();
            void arcade(bool invertTurning = false);

            // Encoder & Sensor Utils
            float getAvgEncoderValue(int numIterations, int delayBetweenIterations);
            float getAvgEncoderValue();

            float getAvgIMURotation(int numIterations, int delayBetweenIterations);
            float getAvgIMURotation();

            //Other Utils
            void checkInversion();
            void circleToSquare(double u, double v, double& x, double& y);
            void reverseFront();

            // For Auton PID
            void moveLateral(double dist); // In inches
            void turnToAngleRelative(double targetAngle); // In degrees CW = +ve
            void turnToAngleAbsolute(double targetAngle); // In degrees; CW = +ve

            void swingToAngleRelative(double targetAngle, double radius);

            void translateRelative(double xTranslation, double yTranslation);

            // TODO: Set up bang-bang control in case something goes wrong
    };
}

#endif // __DRIVE
