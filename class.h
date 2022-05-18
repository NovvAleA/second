#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include  < fstream >


using namespace std;
class CComplexVector {
protected:
	vector<int> arr_re;
	vector<int> arr_im;
	string foutput;
public:
	CComplexVector( CComplexVector& other) {
		foutput = other.get_foutput();
		vector<int>::iterator j;
		vector<int>::iterator k;

		for (int i = 0; i < other.get_dim(); i++) {
			arr_re.push_back(0);
			arr_im.push_back(0);
		}
		for (j = arr_re.begin(), k = other.re_begin(); j != arr_re.end(); j++, k++) {
			*j += *k;
		}
		for (j = arr_im.begin(), k = other.im_begin(); j != arr_im.end(); j++, k++) {
			*j += *k;
		}
	}
	CComplexVector(){
		foutput = "rez.txt";
	}

	const int get_real_ip(int i) const {
		if (i >= arr_re.size()) {
			cout << "Error in get_real_ip";
		}
		return arr_re[i];
	}
	const int get_imag_ip(int i) const {
		if (i >= arr_re.size()) {
			cout << "Error in get_imag_ip";
		}
		return arr_im[i];
	}

	vector<int>& get_arr_re() {
		return arr_re;
	}
	vector<int>& get_arr_im() {
		return arr_im;
	}
    vector<int>::iterator re_begin() {
		return arr_re.begin();
	}
    vector<int>::iterator im_begin() {
		return arr_im.begin();
	}
	vector<int>::iterator re_end() {
		return arr_re.end();
	}
	vector<int>::iterator im_end() {
		return arr_im.end();
	}
	
	string get_foutput() {
		return foutput;
	}
	const int get_dim() const {
		if (arr_re.size() == arr_im.size()) {
			return arr_re.size();
		}
		else {
			cout << "Error! re_dim = " << arr_re.size() << " , im_dim = " << arr_im.size();
			cout << endl;
		}
		return 0;
	}
	void set_fname(string fname) {
		foutput = fname;
	}
	void set_re_i(size_t i, int value) {
		if (i >= 0 && i <= arr_re.size())
			arr_re[i] = value;
		else
			cout << "Eror in set_re_i";
		
	}
	void set_im_i( size_t i,  int value) {
		if (i >= 0 && i <= arr_im.size())
			arr_im[i] = value;
		else
			cout << "Eror in set_im_i";
	}
    virtual int output() = 0;
	CComplexVector& operator+=( CComplexVector& second);
	CComplexVector& operator-=(CComplexVector& second);
    CComplexVector& operator=(const CComplexVector& other);
//	friend ComplexNumber operator*(CComplexVector& u, CComplexVector& v);
	int operator!=(CComplexVector& other);
	 ~CComplexVector() {
		 
	 }
};

class ComplexNumber {
public:
	double re;
	double im;
	ComplexNumber() {
		re = 0;
		im = 0;
	}
	ComplexNumber (ComplexNumber& other) {
		re = other.re;
		im = other.im;
	}
	ComplexNumber& operator=(const ComplexNumber& other) {		
		re = other.re;
		im = other.im;
		return *this;
	}
	void print() {
		if (im > 0 ) {
			if (re != 0) {
				cout << re << " + " << im << "i, ";
			}
			else {cout << im << "i, ";}
		}
		if (im < 0) {
			if(re != 0){
				cout << re << " " << im << "i, ";
			}
			else { cout << im << "i,"; }		
		}
		if (im == 0) {
			cout << re << ", ";
		}
	}

	void file_otput(string foutput) {
		ofstream out;
		out.open(foutput, ios_base::app);
		if (im > 0) {
			if (re != 0) {
				out << re << " + " << im << "i, ";
			}
			else { out << im << "i, "; }
		}
		if (im < 0) {
			if (re != 0) {
				out << re << " " << im << "i, ";
			}
			else { out << im << "i,"; }
		}
		if (im == 0) {
			out << re << ", ";
		}
		out << "\n\n";
		out.close();
	}
};

