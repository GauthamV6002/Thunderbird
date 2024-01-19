// #include "catapultAndIntake.hpp"
// #include "main.h"

// // Util Functions to load/intake
// void thunderbird::CatapultAndIntake::spinCatapult(int power) {
//     thunderbird::catapultAndIntakeMotors = -power;
// }

// void thunderbird::CatapultAndIntake::intakeForward(int power) {
//     thunderbird::catapultAndIntakeMotors = power;
// }

// // TODO: Fix this to make it non-blocking?
// void thunderbird::CatapultAndIntake::charge() {

//     float power = 0;

//     while(power < 10) {

//         float error = this->STORAGE_ANGLE - thunderbird::catapultRotationSensor.get_position();
//         power = catapultPID.compute(error);

//         pros::delay(10);
//         this->spinCatapult(power);
//     }

//     thunderbird::catapultAndIntakeMotors.brake();

// }

// void thunderbird::CatapultAndIntake::chargeSync() {

//     float error = this->STORAGE_ANGLE - thunderbird::catapultRotationSensor.get_position();
//     float power = catapultPID.compute(error);
//     this->spinCatapult(power);

// }


// //TODO: Fix..?
// void thunderbird::CatapultAndIntake::fire() {
//     thunderbird::catapultAndIntakeMotors = 127;
// }

// void thunderbird::CatapultAndIntake::intakeFully(int timeout) {
//     int timeSpentRunning = 0;
//     this->intakeForward(127);

//     while(thunderbird::intakeChecker.get() > 30 && timeSpentRunning < timeout) {
//         timeSpentRunning += 10;
//         pros::delay(10);
//     }

//     thunderbird::catapultAndIntakeMotors.brake();
// }

// // Auton Remover

// void thunderbird::CatapultAndIntake::expandAutonRemover() {
//     // thunderbird::autonRemover.set_value(HIGH);
// }

// void thunderbird::CatapultAndIntake::retractAutonRemover() {
//     // thunderbird::autonRemover.set_value(LOW);    
// }
