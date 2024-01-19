#include "elevation.hpp"
#include "main.h"
#include "pros/misc.h"

void thunderbird::Elevation::expandElevationMechanism() {
    thunderbird::elevation.set_value(HIGH);
    this->elevationIsExpanded = true;
}

void thunderbird::Elevation::retractElevationPiston() {
    thunderbird::elevation.set_value(LOW);
    this->elevationIsExpanded = false;
}

void thunderbird::Elevation::toggleElevationMechanism() {
    if(elevationIsExpanded) {
        retractElevationPiston();
    } else {
        expandElevationMechanism();
    }
}

void thunderbird::Elevation::runElevation() {
    if(master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        toggleElevationMechanism();
    }
}