#pragma once

#include "pros/distance.hpp"

namespace smlib {

    // Which side of the robot the sensor is mounted on.
    // Used by MCLsetup to automatically assign sensors to the correct slot.
    enum class Side { front, back, left, right };

    class DistanceSensor {
        public:
            /**
             * @brief Construct a new Distance Sensor object
             *
             * @param port the port the sensor is plugged into (1-21)
             * @param side the side of the robot the sensor is on (Side::front, Side::back, Side::left, Side::right)
             * @param xOffset the horizontal offset of the sensor from the center of the robot in inches
             * @param yOffset the vertical offset of the sensor from the center of the robot in inches
             */
            DistanceSensor(int port, Side side, double xOffset, double yOffset)
                : distanceSensor(port), side(side), xOffset(xOffset), yOffset(yOffset) {}

            // Returns which side of the robot this sensor is on.
            // Used internally by MCLsetup to sort sensors into front/back/left/right slots.
            Side getSide() const { return side; }

            /**
             * @brief Get the distance reading from the sensor in inches
             *
             * @return double distance in inches
             *
             * @b Example
                * @code {.cpp}
                void initalize() {
                distanceSensor.getDistance();
                // get distance sensor reading in inches
                }
                @endcode
             */
            // PROS returns distance in mm, so divide by 25.4 to convert to inches.
            double getDistance() { return distanceSensor.get() / 25.4; }

            // Returns a reference to the underlying pros::Distance object.
            // Use this to access PROS-only methods (get_object_size, get_object_velocity, get_confidence, etc.)
            // without needing to declare a second sensor object on the same port.
            pros::Distance& getRaw() { return distanceSensor; }

        private:
            pros::Distance distanceSensor;
            Side side;
            double xOffset;  // horizontal distance from robot center to sensor, in inches
            double yOffset;  // vertical distance from robot center to sensor, in inches
    };
}
