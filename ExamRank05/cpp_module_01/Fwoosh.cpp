#include "Fwoosh.hpp"

Fwoosh::Fwoosh()
{
	this->name = "Fwoosh";
	this->effects = "fwooshed";
}

ASpell *Fwoosh::clone() const
{
	return (new Fwoosh());
}
