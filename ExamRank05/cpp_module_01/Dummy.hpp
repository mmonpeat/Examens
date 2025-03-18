#pragma once

#include <iostream>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
		Dummy();
		ATarget *clone() const;
};
