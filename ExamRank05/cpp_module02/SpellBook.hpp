#pragma once

#include <iostream>
#include <string>
#include <map>

#include "ASpell.hpp"

class SpellBook
{
        private:
                SpellBook &operator=(const SpellBook &obj);
                SpellBook(const SpellBook &obj);

                std::map<std::string, ASpell *>array;
        public:
                SpellBook();
                ~SpellBook();

                void learnSpell(const ASpell *spell);
                void forgetSpell(const std::string name);
		ASpell* createSpell(std::string const &name);
};
