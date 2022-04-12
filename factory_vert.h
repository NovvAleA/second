#pragma once
#include "factory.h"
#include "class_vert.h"

class Factory_Vert : public Factory {
public:
    CComplexVector* Create(ifstream& inp) override {
        return new CComplexVectorVert(inp);
    }
};