#ifndef __DRIVE
#define __DRIVE

#include "../../PID/PID.hpp"
namespace thunderbird {
    class Drive { // Class Template for 6m Drive
        public:

            bool inverted = false;
            int deadzoneRange = 10;
            bool frontIsNormal = true; // Normal is with the cata being the front

            double lateralCurveScale = 0.0;
            double turnCurveScale = 2.5;

            // Curvature Drive Constants
            double CD_TURN_NONLINEARITY = 0.65f;
            double DRIVE_DEADBAND = 0.1f;
            double DRIVE_SLEW = 0.02f;

            

            double CD_NEG_INERTIA_SCALAR = 4.0f;
            double CD_SENSITIVITY = 1.0f;

            const double PI = 3.1415f;

            double quickStopAccumlator = 0.0;
            double negInertiaAccumlator = 0.0;

            double prevTurn = 0.0;
            double prevThrottle = 0.0;

            // Drive & Turn PID
            // 0.2, 0.012, 0.7, 250 = accurate w/ integral
            // 0.2, 0.0, 1.425, 250 = best
            PID::PID_System drivePID = PID::PID_System(0, 0.3, 0.0, 2.225, 250, 50, 300, 2500);

            // 0.86 of P only = accurate
            // 0.825, 0, 4.75
            // 0.70 works nice
            // TODO: Increase timeout for larger calcs : changed minSettleTime from 600->400
            PID::PID_System turnPID = PID::PID_System(0, 3.0, 0.0, 17.5, 100, 7, 200, 4000);


            PID::PID_System swingPID = PID::PID_System(0, 2.5, 0.0, 17.5, 100, 5, 600, 8000);

            // Driver control tank function
            void tank();
            void joystickL();
            void arcade(bool invertTurning = false, bool joystickCurves = true);
            void curvatureDrive(bool singleStick = false);

            // Encoder & Sensor Utils
            float getAvgEncoderValue(int numIterations, int delayBetweenIterations);
            float getAvgEncoderValue();

            float getAvgIMURotation(int numIterations, int delayBetweenIterations);
            float getAvgIMURotation();
            
            float getAvgMotorVelocity();

            //Other Utils
            void checkInversion();
            void circleToSquare(double u, double v, double& x, double& y);
            void reverseFront();

            double curveRemap(double x, double curveScale);

            // For Auton PID
            void moveLateral(double dist); // In inches
            void turnToAngleRelative(double targetAngle); // In degrees CW = +ve
            void turnToAngleAbsolute(double targetAngle, double maxSpeed = 127); // In degrees; CW = +ve

            void swingToAngleRelative(double targetAngle, double radius);

            void translateRelative(double xTranslation, double yTranslation);

            // TODO: Set up bang-bang control in case something goes wrong
            void moveLateralBangBang(double dist, double speed, double threshold = 50, double timeout = 6000);
            
            void turnToAngleRelativeBangBang(double targetAngle, double speed, double threshold = 5, double timeout = 4000);
            void swingToAngleRelativeBangBang(double targetAngle, double speed, double threshold = 5, double timeout = 4000);
    };
}

#endif // __DRIVE
