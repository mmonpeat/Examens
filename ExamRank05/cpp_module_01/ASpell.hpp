#pragma once

#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
	protected:
		std::string	name;
		std::string	effects;
	public:
		ASpell();
		ASpell(std::string name, std::string effects);
		ASpell(const ASpell &obj);
		ASpell &operator=(const ASpell &obj);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell *clone() const = 0;
		void launch(const ATarget &obj) const;
};
