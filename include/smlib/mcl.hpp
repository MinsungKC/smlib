#pragma once

#include "smlib/mclsetup.hpp"
#include "lemlib/chassis/chassis.hpp"
#include <vector>
#include <tuple>
#include <random> 
#include "smlib/mclsetup.hpp"

namespace smlib {
    struct Particle {
        double x;
        double y;
        double theta; 
        double weight;
    };
    class MCL {
        public: 
            /**
             * @brief Construct a new MCL object
             * 
             * @param x_pos
             * @param y_pos
             * @param theta

             */

             MCL(double x_pos, double y_pos, double theta);

             /**
             *
             * @brief Get the current position of the robot
             * 
             * @return std::tuple<double, double, double> x position, y position, and heading of the robot
             */

            std::tuple<double, double, double> getPosition();



    };
}