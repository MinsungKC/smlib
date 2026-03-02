#pragma once

#include <initializer_list>
#include "smlib/distancesensor.hpp"

namespace smlib {
    class MCLsetup {
        public:
            /**
             * @brief Construct a new MCLsetup object
             *
             * @param numParticles the number of particles to use in the filter higher = more accurate
             * @param mapWidth the width of the field in units (define in lemlib units)
             * @param mapHeight the length of the map in units (define in lemlib units)
             * @param sensorNoise the standard deviation of the sensor noise
             * @param motionNoise the standard deviation of the motion noise
             * @param robotWidth the width of the robot in inches
             * @param robotLength the length of the robot in inches
             * @param sensors list of distance sensor pointers — each is automatically assigned to its
             *                side based on the Side set when the sensor was constructed; omitted sides
             *                default to nullptr
             *
             * @b Example
                * @code {.cpp}
                smlib::DistanceSensor frontSensor(1, smlib::Side::front, 0, 0);
                smlib::DistanceSensor backSensor(2, smlib::Side::back, 0, 0);

                // leftSensor and rightSensor are not passed — they will be nullptr
                smlib::MCLsetup setup(1200, 144, 144, 1.0, 1.0, 18, 18, {&frontSensor, &backSensor});
                @endcode
             */
            MCLsetup(int numParticles, double mapWidth, double mapHeight, double sensorNoise, double motionNoise,
                     double robotWidth, double robotLength,
                     std::initializer_list<DistanceSensor*> sensors = {})
                : numParticles(numParticles), mapWidth(mapWidth), mapHeight(mapHeight),
                  sensorNoise(sensorNoise), motionNoise(motionNoise),
                  robotWidth(robotWidth), robotLength(robotLength) {
                for (DistanceSensor* s : sensors) {
                    if (s == nullptr) continue;
                    switch (s->getSide()) {
                        case Side::front: front = s; break;
                        case Side::back:  back  = s; break;
                        case Side::left:  left  = s; break;
                        case Side::right: right = s; break;
                    }
                }
            }

            int getNumParticles() const { return numParticles; } // return # of particles
            double getMapWidth() const { return mapWidth; } // return map width in inches
            double getMapHeight() const { return mapHeight; } // return map height in inches
            double getSensorNoise() const { return sensorNoise; } // return sensor noise (standard deviation)
            double getMotionNoise() const { return motionNoise; } // return motion noise (standard deviation)
            double getRobotWidth() const { return robotWidth; }
            double getRobotLength() const { return robotLength; }
            DistanceSensor* getFrontSensor() const { return front; }
            DistanceSensor* getBackSensor() const { return back; }
            DistanceSensor* getLeftSensor() const { return left; }
            DistanceSensor* getRightSensor() const { return right; }
        private:
            int numParticles;
            double mapWidth;
            double mapHeight;
            double sensorNoise;
            double motionNoise;
            double robotWidth;
            double robotLength;

            DistanceSensor* front = nullptr;
            DistanceSensor* back  = nullptr;
            DistanceSensor* left  = nullptr;
            DistanceSensor* right = nullptr;
    };
}
