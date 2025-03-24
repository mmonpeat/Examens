#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{}

TargetGenerator &TargetGenerator::operator=(const TargetGenerator &obj)
{
	this->array = obj.array;
        return (*this);
}

TargetGenerator::TargetGenerator(const TargetGenerator &obj)
{
        *this = obj;
}


TargetGenerator::~TargetGenerator()
{
        for (std::map<std::string, ATarget *>::iterator it = array.begin(); it != array.end();  ++it)
                delete it->second;
}

void TargetGenerator::learnTargetType(const ATarget *spell)
{
        std::map<std::string, ATarget *>::iterator it = array.find(spell->getType());

        if (it == array.end())
                array[spell->getType()] = spell->clone();
}

void TargetGenerator::forgetTargetType(const std::string name)
{
        std::map<std::string, ATarget *>::iterator it = array.find(name);

        if (it != array.end())
        {
                delete it->second;
                array.erase(it);
        }
}

ATarget *TargetGenerator::createTarget(std::string const &name)
{
        std::map<std::string, ATarget *>::iterator it = array.find(name);

        if (it != array.end())
                return it->second->clone();
        return (NULL);
}
