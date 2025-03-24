#include "ASpell.hpp"

ASpell::ASpell(): name(""), effects("")
{}

ASpell::ASpell(const std::string &name, const std::string &effects): name(name), effects(effects) {}

ASpell::ASpell(const ASpell &obj)
{
	*this = obj;
}

ASpell &ASpell::operator=(const ASpell &obj)
{
	name = obj.name;
	effects = obj.effects;
	return (*this);
}

ASpell::~ASpell()
{}

const std::string &ASpell::getName() const
{
	return (this->name);
}

const std::string &ASpell::getEffects() const
{
	return (this->effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}

