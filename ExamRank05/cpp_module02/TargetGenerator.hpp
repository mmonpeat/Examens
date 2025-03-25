#pragma once

#include <iostream>
#include <map>
#include <string>

#include "ATarget.hpp"

class TargetGenerator
{
        private:
                TargetGenerator &operator=(const TargetGenerator &obj);
                TargetGenerator(const TargetGenerator &obj);

                std::map<std::string, ATarget*>array;
        public:
                TargetGenerator(void);
                ~TargetGenerator(void);

                void learnTargetType(const ATarget *spell);
                void forgetTargetType(const std::string name);
                ATarget* createTarget(std::string const &name);
};
