#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;
	public:
		ATarget();
		ATarget(const std::string &type);
		ATarget(const ATarget &obj);
		ATarget &operator=(const ATarget &obj);
		virtual ~ATarget();

		const std::string &getType() const;

		virtual ATarget *clone() const = 0;
		void getHitBySpell(const ASpell &obj) const;
};
