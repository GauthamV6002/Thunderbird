#include "main.h"
#include "pros/misc.h"

void thunderbird::Elevation::releaseElevationMechanism() {
    thunderbird::elevationRelease.set_value(HIGH);
}

void thunderbird::Elevation::retractElevationPiston() {
    thunderbird::elevationRelease.set_value(LOW);
}

void thunderbird::Elevation::runElevation() {
    if(master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        releaseElevationMechanism();
    }
}