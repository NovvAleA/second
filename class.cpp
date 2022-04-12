#include "class.h"


 CComplexVector& CComplexVector::operator=(const CComplexVector& other) {
	vector<int>::iterator j;
	int k = 0;
	if (this->get_dim() < other.get_dim()) {
		for (int i = this->get_dim(); i < other.get_dim(); i++) {
			arr_re.push_back(0);
			arr_im.push_back(0);
		}
	}
	if (this->get_dim() > other.get_dim()) {
		for (int i = other.get_dim(); i < this->get_dim(); i++) {
			arr_re.pop_back();
			arr_im.pop_back();
		}
	}
	/*if(this->get_dim() == 0)
	for (int i = 0; i < other.get_dim(); i++) {
		arr_re.push_back(0);
		arr_im.push_back(0);
	}*/
	for (j = arr_re.begin(); j != arr_re.end(); j++, k++) {
		*j = other.get_real_ip(k);
	}
	for (j = arr_im.begin(), k = 0; j != arr_im.end(); j++, k++) {
		*j = other.get_imag_ip(k);;
	}
	return *this;
}
int CComplexVector::operator!=(CComplexVector& other) {
	
	if (arr_re != other.get_arr_re()) {
		return 1;
	}
	if (arr_im != other.get_arr_im()) {
		return 1;
	}
	return 0;
}

CComplexVector& CComplexVector::operator+=(CComplexVector& second) {
	if (this->get_dim() != second.get_dim()) {
		cout << "Dim error in += !\n";
	};
	vector<int>::iterator j;
	vector<int>::iterator k;

	for (j = arr_re.begin(), k = second.re_begin(); j != arr_re.end(); j++, k++) {
		*j += *k;
	}
	for (j = arr_im.begin(), k = second.im_begin(); j != arr_im.end(); j++, k++) {
		*j += *k;
	}
	return *this;
}
CComplexVector& CComplexVector::operator-=(CComplexVector& second) {
	/*CCompexVector0 temp(dim);*/
	if (this->get_dim() != second.get_dim()) {
		cout << "Dim error in -= !\n";
	};
	vector<int>::iterator j;
	vector<int>::iterator k;

	for (j = arr_re.begin(), k = second.re_begin(); j != arr_re.end(); j++, k++) {
		*j -= *k;
	}
	for (j = arr_im.begin(), k = second.im_begin(); j != arr_im.end(); j++, k++) {
		*j -= *k;
	}
	//this->output();
	return *this;
}


