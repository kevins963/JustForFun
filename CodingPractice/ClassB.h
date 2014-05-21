#pragma once
#include "ClassA.h"
#include "ClassC.h"

class ClassB : ClassA
{
public:
    ClassB(void);
    virtual ~ClassB(void);

private:
    ClassC _classC;
};

