#include "SpellBook.hpp"

SpellBook::SpellBook()
{}

SpellBook &SpellBook::operator=(const SpellBook &obj)
{
	this->array = obj.array;
        return (*this);
}

SpellBook::SpellBook(const SpellBook &obj)
{
        *this = obj;
}


SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell *>::iterator it = array.begin(); it != array.end();  ++it)
		delete it->second;
}

void SpellBook::learnSpell(const ASpell *spell)
{
        std::map<std::string, ASpell *>::iterator it = array.find(spell->getName());

        if (it == array.end())
                array[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string name)
{
        std::map<std::string, ASpell *>::iterator it = array.find(name);

        if (it != array.end())
        {
                delete it->second;
                array.erase(it);
        }
}

ASpell *SpellBook::createSpell(std::string const &name)
{
        std::map<std::string, ASpell *>::iterator it = array.find(name);

        if (it != array.end())
                return it->second->clone();
	return (NULL);
}
