
#include "B.h"

struct C:public B
{
	C() { std::cout << "Cctor"<< std::endl; }
};