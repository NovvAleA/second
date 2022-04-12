#pragma once
#include "class.h"
#include "operators.h"

class CComplexVectorHori : public CComplexVector {
public:
	CComplexVectorHori(ifstream& inp);
	CComplexVectorHori():CComplexVector() {}
	CComplexVectorHori(CComplexVector& other) :CComplexVector(other) {}
	int output() override;
	using CComplexVector::CComplexVector;
	//friend CComplexVector& operator+(CComplexVector& first, CComplexVector& second);
	friend CComplexVectorHori operator+(CComplexVectorHori first, CComplexVector& second);
	friend CComplexVectorHori operator-(CComplexVectorHori first, CComplexVector& second);
	using CComplexVector:: operator=;
	using CComplexVector:: operator+=;
	using CComplexVector:: operator-=;
	using CComplexVector:: operator!=;
};