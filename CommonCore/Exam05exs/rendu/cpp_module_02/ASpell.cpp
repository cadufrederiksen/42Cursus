#include "ASpell.hpp"

ASpell::ASpell() : _name(), _effects()
{
}

ASpell::ASpell(std::string name, std::string effects) : _name(name), _effects(effects)
{
}

ASpell::ASpell(const ASpell& ref)
{
	_name = ref._name;
	_effects = ref._effects;
}

ASpell&
ASpell::operator=(const ASpell& ref)
{
	_name = ref._name;
	_effects = ref._effects;
	return ((*this));
}

ASpell::~ASpell()
{
}

std::string
ASpell::getName(void) const
{
	return (_name);
}

std::string
ASpell::getEffects(void) const
{
	return (_effects);
}

void
ASpell::launch(const ATarget& ref) const
{
	ref.getHitBySpell((*this));
}
