#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class	Polymorph : public ASpell
{
	public:
		Polymorph();
		Polymorph(std::string, std::string);
		Polymorph(const Polymorph&);
		Polymorph& operator=(const Polymorph&);
		virtual ~Polymorph();

		virtual ASpell*		clone() const;
};

#endif
