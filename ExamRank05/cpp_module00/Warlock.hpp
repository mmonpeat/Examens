#pragma once

#include <iostream>
#include <string>
#include <map>

class Warlock
{
	private:
		std::string	name;
		std::string	title;

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
};
