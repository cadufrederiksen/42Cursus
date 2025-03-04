#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <vector>

class	ASpell;
class	ATarget;

class	Warlock
{
	private:
		std::string				_name;
		std::string				_title;
		std::vector<ASpell*>	_list;
		
		Warlock();
		Warlock(const Warlock&);
		Warlock& operator=(const Warlock&);
		
	public:
		Warlock(std::string, std::string);
		virtual ~Warlock();

		const std::string& getName() const;
		const std::string& getTitle() const;

		void	setTitle(const std::string&);

		void	introduce() const;

		void	learnSpell(const ASpell*);
		void	forgetSpell(std::string);
		void	launchSpell(std::string, const ATarget&);
};

# include "ASpell.hpp"
# include "ATarget.hpp"

#endif
