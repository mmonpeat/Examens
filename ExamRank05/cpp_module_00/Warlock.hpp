#ifndef WARLOCK_HPP
# define WARLOCK_HPP
//Pots usar #pragma once, evita que hpp es carregui varies vegades en una mateixa compilació, com el ifndef

#include <iostream>
class Warlock
{
	private:
		std::string	name;
		std::string	title;

		Warlock(const Warlock &obj);
		Warlock &operator=(Warlock const &obj);
	
	public:
		Warlock(std::string const name, std::string const title);
		~Warlock();

		std::string const &getName() const;
		std::string const &getTitle() const;

		void setTitle(std::string const &title);
		void introduce() const;
};

#endif
