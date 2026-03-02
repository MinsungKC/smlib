#pragma once


#include <cmath> 
#include <vector> 

namespace smlib {
    class MCLsetup {
        public: 
            /**
             * @brief Construct a new MCLsetup object
             * 
             * @param numParticles the number of particles to use in the filter higher = more accurate
             * @param mapWidth the width of the field in units (define in lemlib units)
             * @param mapHeight the length of the map in units (define in lemlib units)
             * @param sensorNoise the standard deviation of the sensor noise (calculate this by taking a large number of sensor readings and calculating the standard deviation)
             * @param motionNoise the standard deviation of the motion noise (calculate this by taking a large number of motion readings and calculating the standard deviation)
             * @param distance1 front distance sensor pointer
             * @param distance2 back distance sensor pointer
             * @param distance3 left distance sensor pointer
             * @param distance4 right distance sensor pointer
             */
            MCLsetup(int numParticles, double mapWidth, double mapHeight, double sensorNoise, double motionNoise, );
    };
}