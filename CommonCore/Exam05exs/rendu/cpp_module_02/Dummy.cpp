#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{
}

Dummy::Dummy(std::string type) : ATarget(type)
{
}

Dummy::Dummy(const Dummy& ref) : ATarget(ref.getType())
{
}

Dummy&
Dummy::operator=(const Dummy& ref)
{
	if (this != &ref)
		*this = ref;
	return (*this);
}

Dummy::~Dummy()
{
}

ATarget*
Dummy::clone(void) const
{
	return (new Dummy(*this));
}
