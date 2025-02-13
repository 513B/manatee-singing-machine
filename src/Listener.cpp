
// Listener.cpp
#include "Listener.h"

Listener::Listener(double x, double y, double z, double yaw, double pitch, double earDistance_)
        : position({x, y, z}), orientation({yaw, pitch}), earDistance(earDistance_) {}

void Listener::setPosition(double x, double y, double z) {
    position = {x, y, z};
}

std::vector<double> Listener::getPosition() const {
    return position;
}

void Listener::setOrientation(double yaw, double pitch) {
    orientation = {yaw, pitch};
}

std::vector<double> Listener::getOrientation() const {
    return orientation;
}

double Listener::getEarDistance() const {
    return earDistance;
}
