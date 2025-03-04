#include "BrickWall.hpp"

BrickWall::BrickWall() : ATarget("Inconspicuous Red-brick Wall")
{
}

BrickWall::BrickWall(std::string type) : ATarget(type)
{
}

BrickWall::BrickWall(const BrickWall& ref) : ATarget(ref.getType())
{
}

BrickWall&
BrickWall::operator=(const BrickWall& ref)
{
	if (this != &ref)
		*this = ref;
	return (*this);
}

BrickWall::~BrickWall()
{
}

ATarget*
BrickWall::clone(void) const
{
	return (new BrickWall(*this));
}
