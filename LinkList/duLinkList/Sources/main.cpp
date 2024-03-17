#include <iostream>
#include <easyx.h>
#include "dulinkedlist.h"
using namespace std;
int main()
{
	dulinkedlist a;
	a.run();
	a.~dulinkedlist();
	return 0;
}