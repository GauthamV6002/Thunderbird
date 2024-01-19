#include "main.h"
#include "pros/misc.h"

void thunderbird::Wings::openFrontWings() {
    openFrontLeft();
    openFrontRight();
}

void thunderbird::Wings::closeFrontWings() {
    closeFrontLeft();
    closeFrontRight();
}

void thunderbird::Wings::openFrontLeft() { thunderbird::leftFrontWing.set_value(HIGH); }
void thunderbird::Wings::openFrontRight() { thunderbird::rightFrontWing.set_value(HIGH); }
void thunderbird::Wings::closeFrontLeft() { thunderbird::leftFrontWing.set_value(LOW); }
void thunderbird::Wings::closeFrontRight() { thunderbird::rightFrontWing.set_value(LOW); }

void thunderbird::Wings::openBackLeft() { thunderbird::leftBackWing.set_value(HIGH); }
void thunderbird::Wings::openBackRight() { thunderbird::rightBackWing.set_value(HIGH); }
void thunderbird::Wings::closeBackLeft() { thunderbird::leftBackWing.set_value(LOW); }
void thunderbird::Wings::closeBackRight() { thunderbird::rightBackWing.set_value(LOW); }

void thunderbird::Wings::openBackWings() {
    openBackLeft();
    openBackRight();
}

void thunderbird::Wings::closeBackWings() {
    closeBackLeft();
    closeBackRight();
}

void thunderbird::Wings::runWings() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) openFrontWings();
    else closeFrontWings();

    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) openBackWings();
    else closeBackWings();
}