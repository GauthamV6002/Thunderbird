#include "../../PID/PID.hpp"

#ifndef __DRIVE
#define __DRIVE

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
            // TODO: Increase timeout for larger calcs
            PID::PID_System turnPID = PID::PID_System(0, 2.5, 0.0, 17.5, 100, 5, 600, 5000);

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


            // Auton Macro Functions
            void outtakeAndDeposit(int power = 80, int time = 750);

            // For Auton PID
            void moveLateral(double dist); // In inches
            void turnToAngleRelative(double targetAngle); // In degrees CW = +ve
            void turnToAngleAbsolute(double targetAngle); // In degrees; CW = +ve

            void translateRelative(double xTranslation, double yTranslation);

            // TODO: Set up bang-bang control in case something goes wrong

            // Calibrate Functions
            void plannerCalibration();
            void turnPIDCalibration();
            void drivePIDCalibration();

            // Actual Autons
            void goalSideAWP();
            void goalSideElims();

            void shootSideAWP();
    };
}

#endif // __DRIVE
