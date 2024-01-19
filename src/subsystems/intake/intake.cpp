#include "main.h"
#include "pros/misc.h"
#include "pros/motors.h"

void thunderbird::Intake::setIntakeConfig() {
    thunderbird::intakeMotors.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
}

void thunderbird::Intake::intakeIn(int power) {
    thunderbird::intakeMotors = power;
}

void thunderbird::Intake::runIntake() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) intakeIn(127);
    else if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) intakeIn(-127);
    else intakeIn(0);
}

void thunderbird::Intake::outtake(int time, int power) {
    intakeIn(-power);
    pros::delay(time);
    intakeIn(0);

}