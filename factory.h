#pragma once
#include "class.h"



class Factory {

public:
    virtual CComplexVector* Create(ifstream& inp) = 0;
};

