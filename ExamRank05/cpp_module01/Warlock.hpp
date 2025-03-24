#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
	private:
		std::string	name;
		std::string	title;
		std::map<std::string, ASpell *>array;

		Warlock();
		Warlock(const Warlock &obj);
		Warlock &operator=(Warlock const &obj);
	
	public:
		Warlock(const std::string &name, const std::string &title);
		~Warlock();

		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &title);
		void introduce() const;

		void learnSpell(const ASpell *spell);
		void forgetSpell(const std::string name);
		void launchSpell(const std::string name, ATarget &target);
};

