#pragma once
//#ifndef WARLOCK_HPP
//# define WARLOCK_HPP
//Pots usar #pragma once, evita que hpp es carregui varies vegades en una mateixa compilació, com el ifndef

#include "ASpell.hpp"
#include <vector>

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		std::vector<ASpell *> learned;

		Warlock(const Warlock &obj);
		Warlock &operator=(Warlock const &obj);
	
	public:
		Warlock(std::string const name, std::string const title);
		~Warlock();

		std::string const &getName() const;
		std::string const &getTitle() const;

		void setTitle(std::string const &title);
		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(std::string spellName);
		void launchSpell(std::string spellName, ATarget &target);
};

//#endif
