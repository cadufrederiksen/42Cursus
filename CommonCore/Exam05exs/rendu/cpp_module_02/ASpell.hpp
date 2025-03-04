#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <string>

class ATarget;

class	ASpell
{
	private:
		std::string		_name;
		std::string		_effects;

	public:
		ASpell(std::string, std::string);
		ASpell();
		ASpell(const ASpell&);
		ASpell& operator=(const ASpell&);
		virtual ~ASpell();

		std::string getName() const;
		std::string getEffects() const;

		virtual ASpell*		clone() const = 0;

		void		launch(const ATarget&) const;
};

# include "ATarget.hpp"

#endif
