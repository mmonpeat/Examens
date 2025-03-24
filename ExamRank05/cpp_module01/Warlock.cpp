#include "Warlock.hpp"

Warlock::Warlock()
{}

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

void Warlock::learnSpell(const ASpell *spell)
{
	if (!spell)
		return;
	std::map<std::string, ASpell *>::iterator it = array.find(spell->getName());

	if (it == array.end())
		array[spell->getName()] = spell->clone();
}


void Warlock::forgetSpell(const std::string name)
{
	std::map<std::string, ASpell *>::iterator it = array.find(name);

	if (it != array.end())
	{
		delete it->second;
		array.erase(it);
	}
}

void Warlock::launchSpell(const std::string name, ATarget &target)
{
	std::map<std::string, ASpell *>::iterator it = array.find(name);

	if (it != array.end())
		it->second->launch(target);
}


