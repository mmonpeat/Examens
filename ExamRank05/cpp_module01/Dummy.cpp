#include "Dummy.hpp"

Dummy::Dummy()
{
	this->type = "Target Practice Dummy";
}
Dummy::~Dummy()
{}

ATarget *Dummy::clone() const
{
	return(new Dummy());
}

