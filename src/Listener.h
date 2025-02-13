
#ifndef LISTENER_H
#define LISTENER_H

#include <vector>

class Listener {
public:
    Listener(double x, double y, double z, double yaw, double pitch, double earDistance);

    void setPosition(double x, double y, double z);
    std::vector<double> getPosition() const;

    void setOrientation(double yaw, double pitch);
    std::vector<double> getOrientation() const;

    double getEarDistance() const;

private:
    std::vector<double> position;      // {x, y, z}
    std::vector<double> orientation;   // {yaw, pitch}
    double earDistance;
};

#endif // LISTENER_H
