#include "ATarget.hpp"

ATarget::ATarget(): type("") {}

ATarget::ATarget(std::string type): type(type) {}

ATarget::ATarget(const ATarget &obj): type(obj.type) {}

ATarget &ATarget::operator=(const ATarget &obj)
{
	type = obj.type;
	return (*this);
}

ATarget::~ATarget() {}

const std::string &ATarget::getType() const
{
	return (type);
}

void ATarget::getHitBySpell(const ASpell &obj) const
{
	std::cout << type << " has been " << obj.getEffects() << "!" <<std::endl;
}

