#include "ATarget.hpp"

ATarget::ATarget() : _type()
{
}

ATarget::ATarget(std::string type) : _type(type)
{
}

ATarget::ATarget(const ATarget& ref)
{
	_type = ref._type;
}

ATarget&
ATarget::operator=(const ATarget& ref)
{
	_type = ref._type;
	return (*this);
}

ATarget::~ATarget()
{
}

const std::string&
ATarget::getType(void) const
{
	return (_type);
}

void
ATarget::getHitBySpell(const ASpell& ref) const
{
	std::cout << _type << " has been " << ref.getEffects() << "!" << std::endl;
}
