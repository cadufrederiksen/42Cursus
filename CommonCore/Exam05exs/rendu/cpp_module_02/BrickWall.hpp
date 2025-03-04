#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class	BrickWall : public ATarget
{
	public:
		BrickWall();
		BrickWall(std::string);
		BrickWall(const BrickWall&);
		BrickWall& operator=(const BrickWall&);
		virtual ~BrickWall();

		virtual ATarget*		clone() const;
};

#endif
