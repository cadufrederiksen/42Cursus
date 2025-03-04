#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class	Dummy : public ATarget
{
	public:
		Dummy();
		Dummy(std::string);
		Dummy(const Dummy&);
		Dummy& operator=(const Dummy&);
		virtual ~Dummy();

		virtual ATarget*		clone() const;
};

#endif
