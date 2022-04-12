#pragma once
#include "factory.h"
#include "class_hori.h"

class Factory_Hori : public Factory {
public:
    CComplexVector* Create(ifstream& inp) override {
        return new CComplexVectorHori(inp);
    }
};