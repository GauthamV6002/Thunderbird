#include "main.h"

void thunderbird::Blocker::openBlocker() {
    thunderbird::blocker.set_value(HIGH);
}

void thunderbird::Blocker::closeBlocker() {
    thunderbird::blocker.set_value(LOW);
}

void thunderbird::Blocker::runBlocker() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        if(this->blockerIsOpen) {
            closeBlocker();
            this->blockerIsOpen = false;
        } else {
            openBlocker();
            this->blockerIsOpen = true;
        }
    }
}