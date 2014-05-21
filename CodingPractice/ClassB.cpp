#include "ClassB.h"

#include <iostream>

using namespace std;


ClassB::ClassB(void)
{
    cout << "ClassB Constructor <Derived>" << endl;
}


ClassB::~ClassB(void)
{
    cout << "ClassB Destructor <Derived>" << endl;
}
