#pragma once
#include "class.h"
#include "class_hori.h"
#include "functions.h"
#include "operators.h"

int AT() {
	vector<CComplexVector*> arr;
	vector<CComplexVector*> arr1;
	ComplexNumber sc;
	int re, im = 0;
	int arrdim = 0;
	arr = fscan_data_without_output("at1.txt");
	if (arr.size() != 5) {
		cout << "Error! arrdim is " << arr.size() << " instead 5" << endl;
		return 0;
	}
	(*arr[0]) += (*arr[1]);
	(*arr[1]) -= (*arr[4]);
	arr1  = fscan_data_without_output("antans.txt"); 
	if (arr1.size() != 5) {
		cout << "Error_1! arrdim is " << arr.size() << " instead 5" << endl;
		return 0;
	}
	for (size_t i = 0; i < arr.size(); i++) {
		if ((*arr[i]) != (*arr1[i])) {
			cout << "Error_2! vector on" << i << "string " << endl;
			return 0;
		}
	}
	re = -4;
	im = 0;
	sc = (*arr[3])*(*arr[4]);
	if (re != sc.re || im != sc.im) {
		cout << "Error_3! sc is wrong" << endl;
		return 0;
	}
	return 1;
}