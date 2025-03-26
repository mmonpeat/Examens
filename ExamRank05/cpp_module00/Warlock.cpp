#include "Warlock.hpp"

Warlock::Warlock(void) {}

Warlock::Warlock(const Warlock &obj)
{
	*this = obj;
}

Warlock &Warlock::operator=(const Warlock &obj)
{
	this->name = obj.name;
	this->title = obj.title;
	return (*this);
}

Warlock::Warlock(const std::string &name, const std::string &title): name(name), title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
	return (this->name);
}

const std::string &Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::setTitle(const std::string &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}
