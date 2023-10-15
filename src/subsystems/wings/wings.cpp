#include "main.h"

void thunderbird::Wings::openWings() {
    thunderbird::leftWing.set_value(HIGH);
    thunderbird::rightWing.set_value(HIGH);
}

void thunderbird::Wings::closeWings() {
    thunderbird::leftWing.set_value(LOW);
    thunderbird::rightWing.set_value(LOW);
}

void thunderbird::Wings::openLeft() {
    thunderbird::leftWing.set_value(HIGH);
}

void thunderbird::Wings::closeLeft() {
    thunderbird::leftWing.set_value(LOW);
}

void thunderbird::Wings::openRight() {
    thunderbird::rightWing.set_value(HIGH);
}

void thunderbird::Wings::closeRight() {
    thunderbird::rightWing.set_value(LOW);
}



void thunderbird::Wings::runWings() {
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
        if(this->wingsAreOpen) {
            closeWings();
            this->wingsAreOpen = false;
        } else {
            openWings();
            this->wingsAreOpen = true;
        }
    }
}