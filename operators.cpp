#include "operators.h"

//CComplexVectorHori operator+(CComplexVectorHori first, CComplexVector& second) {
//    CComplexVectorHori tmp(first);
//    if (first.get_foutput() != second.get_foutput()) {
//        tmp.set_fname("rez.txt");
//    }
//    if (first.get_dim() != second.get_dim()) {
//        cout << "Dim error!\n";
//    };
//    tmp += second;
//    return tmp;
//}
//CComplexVectorVert operator+(CComplexVectorVert first, CComplexVector& second) {
//    CComplexVectorVert tmp(first);
//    if (first.get_foutput() != second.get_foutput()) {
//        tmp.set_fname("rez.txt");
//    }
//    if (first.get_dim() != second.get_dim()) {
//        cout << "Dim error!\n";
//    };
//    tmp += second;
//    return tmp;
//}
//
//CComplexVectorHori operator-(CComplexVectorHori first, CComplexVector& second) {
//    CComplexVectorHori tmp(first);
//    if (first.get_foutput() != second.get_foutput()) {
//        tmp.set_fname("rez.txt");
//    }
//    if (first.get_dim() != second.get_dim()) {
//        cout << "Dim error!\n";
//    };
//    tmp -= second;
//    return tmp;
//}
//
//CComplexVectorVert operator-(CComplexVectorVert first, CComplexVector& second) {
//    CComplexVectorVert tmp(first);
//    if (first.get_foutput() != second.get_foutput()) {
//        tmp.set_fname("rez.txt");
//    }
//    if (first.get_dim() != second.get_dim()) {
//        cout << "Dim error!\n";
//    };
//    tmp -= second;
//    return tmp;
//}

ComplexNumber operator*(CComplexVector& u, CComplexVector& v) {
	ComplexNumber sc;
	if (u.get_dim() != v.get_dim()) {
		cout << "Dim error in * !\n";
		return sc;
	}

	/*vector<int>::iterator i1 = u.re_begin();
	vector<int>::iterator i2 = u.im_begin();
	vector<int>::iterator j1 = v.re_begin();
	vector<int>::iterator j2 = v.im_begin();

	for (i1; i1 != u.re_end(); i1++, i2++, j1++, j2++) {
		sc.re += (*i1) * (*j1) + (*i2) * (*j2);
		sc.im += (*i1) * (*j2) - (*i2) * (*j1);

	}*/

	//vector<int> arr_re1 = u.get_arr_re();
	//vector<int> arr_im1 = u.get_arr_im();
	//vector<int> arr_re2 = v.get_arr_re();
	//vector<int> arr_im2 = v.get_arr_im();

	for (int i = 0; i < v.get_dim(); i++) {
		sc.re += u.get_real_ip(i) * v.get_real_ip(i) - u.get_imag_ip(i) * v.get_imag_ip(i);
		sc.im += u.get_real_ip(i) * v.get_imag_ip(i) + u.get_imag_ip(i) * v.get_real_ip(i);
	}
	return sc;
}
