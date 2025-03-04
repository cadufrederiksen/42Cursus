#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
	for (std::vector<ATarget*>::iterator it = _list.begin();it != _list.end();)
	{
		delete (*it);
		it = _list.erase(it);
	}
}

void
TargetGenerator::learnTargetType(ATarget* spell)
{
	for (std::vector<ATarget*>::iterator it = _list.begin();it != _list.end();it++)
		if ((*(*it)).getType() == (*spell).getType())
			return ;
	_list.push_back(spell->clone());
}

void
TargetGenerator::forgetTargetType(const std::string& name)
{
	for (std::vector<ATarget*>::iterator it = _list.begin();it != _list.end();)
	{
		if ((*(*it)).getType() == name)
		{
			delete (*it);
			it = _list.erase(it);
		}
		else
			it++;
	}
}

ATarget*
TargetGenerator::createTarget(const std::string& name)
{
	for (std::vector<ATarget*>::iterator it = _list.begin();it != _list.end();it++)
	{
		if ((*(*it)).getType() == name)
		{
			return ((*(*it)).clone());
		}
	}
	return (NULL);
}
