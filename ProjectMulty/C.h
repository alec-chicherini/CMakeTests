
#include "B.h"

struct C:public B
{
	C() { std::cout << "C ctor" << std::endl; }
};