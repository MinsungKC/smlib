#pragma once

#include "mclsetup.hpp"
#include "chassis.hpp"

namespace smlib {
    class Chassis;
    class MCL {
        public: 
            /**
             * @brief Construct a new MCL object
             * 
             * @param setup the setup object containing the parameters for the filter
             * @param chassis the chassis object containing the current state of the robot
             */
            MCL(MCLsetup setup, Chassis chassis);


    };
}