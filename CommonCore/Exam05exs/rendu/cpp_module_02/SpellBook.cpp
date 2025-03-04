#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
	for (std::vector<ASpell*>::iterator it = _list.begin();it != _list.end();)
	{
		delete (*it);
		it = _list.erase(it);
	}
}

void
SpellBook::learnSpell(ASpell* spell)
{
	for (std::vector<ASpell*>::iterator it = _list.begin();it != _list.end();it++)
		if ((*(*it)).getName() == (*spell).getName())
			return ;
	_list.push_back(spell->clone());
}

void
SpellBook::forgetSpell(const std::string& name)
{
	for (std::vector<ASpell*>::iterator it = _list.begin();it != _list.end();)
	{
		if ((*(*it)).getName() == name)
		{
			delete (*it);
			it = _list.erase(it);
		}
		else
			it++;
	}
}

ASpell*
SpellBook::createSpell(const std::string& name)
{
	for (std::vector<ASpell*>::iterator it = _list.begin();it != _list.end();it++)
	{
		if ((*(*it)).getName() == name)
		{
			return ((*(*it)).clone());
		}
	}
	return (NULL);
}
