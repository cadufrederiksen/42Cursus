#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <vector>
# include <string>
# include <iostream>

class ATarget;

class TargetGenerator
{
	private:
		TargetGenerator(const TargetGenerator&);
		TargetGenerator& operator=(const TargetGenerator&);
		std::vector<ATarget*>	_list;

	public:
		TargetGenerator();
		~TargetGenerator();

		void	learnTargetType(ATarget*);
		void	forgetTargetType(const std::string&);
		ATarget*	createTarget(const std::string&);
};

# include "ATarget.hpp"

#endif
