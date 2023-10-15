#include "../../include/odometry/odometry.hpp"

float odometry::Odometry_System::getXPosition() {
    return this->xPosition;
}

float odometry::Odometry_System::getYPosition() {
    return this->yPosition;
}

float odometry::Odometry_System::getAngle() {
    return this->currentAngle;
}