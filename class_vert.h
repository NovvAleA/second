#pragma once
#include "class.h"
#include "operators.h"

class CComplexVectorVert : public CComplexVector {
public:
	CComplexVectorVert(ifstream& inp);
	CComplexVectorVert():CComplexVector() {}
	CComplexVectorVert(CComplexVector& other):CComplexVector(other){}
	int output() override;
	using CComplexVector::CComplexVector;
	using CComplexVector:: operator=;
	using CComplexVector:: operator+=;
	using CComplexVector:: operator-=;
	using CComplexVector:: operator!=;
	friend CComplexVectorVert operator+(CComplexVectorVert first, CComplexVector& second);
	friend CComplexVectorVert operator-(CComplexVectorVert first, CComplexVector& second);
};