#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
}

Fwoosh::Fwoosh(std::string name, std::string effects) : ASpell(name, effects)
{
}

Fwoosh::Fwoosh(const Fwoosh& ref) : ASpell(ref)
{
}

Fwoosh&
Fwoosh::operator=(const Fwoosh& ref)
{
	if (this != &ref)
		*this = ref;
	return (*this);
}

Fwoosh::~Fwoosh()
{
}

ASpell*
Fwoosh::clone(void) const
{
	return (new Fwoosh(*this));
}
