#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class	Fireball : public ASpell
{
	public:
		Fireball();
		Fireball(std::string, std::string);
		Fireball(const Fireball&);
		Fireball& operator=(const Fireball&);
		virtual ~Fireball();

		virtual ASpell*		clone() const;
};

#endif
