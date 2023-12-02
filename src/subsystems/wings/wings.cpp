#include "main.h"

// Both Wings
void thunderbird::Wings::openWings() {
    thunderbird::leftWing.set_value(HIGH);
    thunderbird::rightWing.set_value(HIGH);
}

void thunderbird::Wings::closeWings() {
    thunderbird::leftWing.set_value(LOW);
    thunderbird::rightWing.set_value(LOW);
}

// Left Wings
void thunderbird::Wings::openLeft() {
    thunderbird::leftWing.set_value(HIGH);
}

void thunderbird::Wings::closeLeft() {
    thunderbird::leftWing.set_value(LOW);
}

//Right Wings
void thunderbird::Wings::openRight() {
    thunderbird::rightWing.set_value(HIGH);
}

void thunderbird::Wings::closeRight() {
    thunderbird::rightWing.set_value(LOW);
}

//Auton Remover
void thunderbird::Wings::expandAutonRemover() {
    thunderbird::autonRemover.set_value(HIGH);
}
void thunderbird::Wings::retractAutonRemover() {
    thunderbird::autonRemover.set_value(LOW);
}

void thunderbird::Wings::runWings() {
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) {
        if(this->leftWingIsOpen) {
            closeLeft();
            this->leftWingIsOpen = false;
        } else {
            openLeft();
            this->leftWingIsOpen = true;
        }
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
        if(this->rightWingIsOpen) {
            closeRight();
            this->rightWingIsOpen = false;
        } else {
            openRight();
            this->rightWingIsOpen = true;
        }
    }

    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        if(this->autonRemoverIsExpanded) {
            expandAutonRemover();
            this->autonRemoverIsExpanded = false;
        } else {
            retractAutonRemover();
            this->autonRemoverIsExpanded = true;
        }
    }
}