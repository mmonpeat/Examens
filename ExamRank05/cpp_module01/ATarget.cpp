#include "ATarget.hpp"

ATarget::ATarget(): type("") {}

ATarget::ATarget(const std::string &type): type(type) {}

ATarget::ATarget(const ATarget &obj)
{
	*this = obj;
}

ATarget &ATarget::operator=(const ATarget &obj)
{
	this->type = obj.type;
	return (*this);
}

ATarget::~ATarget() {}

const std::string &ATarget::getType() const
{
	return (this->type);
}

void ATarget::getHitBySpell(const ASpell &obj) const
{
	std::cout << type << " has been " << obj.getEffects() << "!" <<std::endl;
}

