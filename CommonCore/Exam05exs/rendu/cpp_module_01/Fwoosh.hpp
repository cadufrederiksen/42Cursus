#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class	Fwoosh : public ASpell
{
	public:
		Fwoosh();
		Fwoosh(std::string, std::string);
		Fwoosh(const Fwoosh&);
		Fwoosh& operator=(const Fwoosh&);
		virtual ~Fwoosh();

		virtual ASpell*		clone() const;
};

#endif
