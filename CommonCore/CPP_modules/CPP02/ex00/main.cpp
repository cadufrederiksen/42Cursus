#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);//cria b a partir de a
	Fixed c;

	c = b; //copia oq que tem em b em c

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
 
	return 0;
}