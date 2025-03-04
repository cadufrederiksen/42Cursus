#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <vector>
# include <string>
# include <iostream>

class ASpell;

class SpellBook
{
	private:
		SpellBook(const SpellBook&);
		SpellBook& operator=(const SpellBook&);
		std::vector<ASpell*>	_list;
	
	public:
		SpellBook();
		~SpellBook();

		void	learnSpell(ASpell*);
		void	forgetSpell(const std::string&);
		ASpell*	createSpell(const std::string&);
};

# include "ASpell.hpp"

#endif
