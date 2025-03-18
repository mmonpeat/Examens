#include "ASpell.hpp"

ASpell::ASpell(): name(""), effects(""){}

ASpell::ASpell(std::string name, std::string effects): name(name), effects(effects) {}

ASpell::ASpell(const ASpell &obj): name(obj.name), effects(obj.effects) {}

ASpell &ASpell::operator=(const ASpell &obj)
{
	name = obj.name;
	effects = obj.effects;
	return (*this);
}

ASpell::~ASpell() {}

std::string ASpell::getName() const
{
	return (name);
}

std::string ASpell::getEffects() const
{
	return (effects);
}

void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}

