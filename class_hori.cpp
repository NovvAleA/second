#include "class_hori.h"


int CComplexVectorHori::output() {
	ofstream out;
	out.open(foutput, ios_base::app);
	vector<int>::iterator j;
	vector<int>::iterator k;

	for (j = arr_re.begin(), k = arr_im.begin(); j != arr_re.end(); j++, k++) {
		if (*k > 0) {
			if (*j != 0) {
				out << *j << " + " << *k << "i, ";
			}
			else { out << *k << "i, "; }
		}
		if (*k < 0) {
			if (*j != 0) {
				out << *j << " " << *k << "i, ";
			}
			else { out << *k << "i,"; }
		}
		if (*k == 0) {
			out << *j << ", ";
		}
	}

	out << "\n\n";
	out.close();
	return 1;
}

CComplexVectorHori::CComplexVectorHori(ifstream& inp) {
	inp >> foutput;

	char tmp;
	int num = 0;

	while (inp >> num) {
		arr_re.push_back(num);

		inp.get(tmp);
		if (tmp == '\0' || tmp == '\n') {
			cout << "Odd quantity of numbers" << endl;
			break;
		}

		inp >> num;
		arr_im.push_back(num);

		inp.get(tmp);
		if (tmp == '\0' || tmp == '\n') {
			break;
		}
	}
}

CComplexVectorHori operator+(CComplexVectorHori first, CComplexVector& second) {
    CComplexVectorHori tmp(first);
    if (first.get_foutput() != second.get_foutput()) {
        tmp.set_fname("rez.txt");
    }
    if (first.get_dim() != second.get_dim()) {
        cout << "Dim error!\n";
    };
    tmp += second;
    return tmp;
}

CComplexVectorHori operator-(CComplexVectorHori first, CComplexVector& second) {
	CComplexVectorHori tmp(first);
	if (first.get_foutput() != second.get_foutput()) {
		tmp.set_fname("rez.txt");
	}
	if (first.get_dim() != second.get_dim()) {
		cout << "Dim error!\n";
	};
	tmp -= second;
	return tmp;
}

//CComplexVector& operator+(CComplexVector& first, CComplexVector& second) {
//	CComplexVectorHori tmp = first;
//	if (first.get_dim() != second.get_dim()) {
//		cout << "Dim error!\n";
//	};
//	tmp += second;
//	return tmp;
//}


//ComplexNumber CCompexVector0::operator*( CCompexVector* other) {
//    ComplexNumber sc;
//    sc.re = 0;
//    sc.im = 0;
//
//    double* arr_re1 = arr[0];
//    double* arr_im1 = arr[1];
//    double* arr_re2 = (*other).get_re_p();
//    double* arr_im2 = (*other).get_im_p();
//    ;
//
//    for (int i = 0; i < dim; i++) {
//        sc.re += arr_re1[i] * arr_re2[i] + arr_im1[i] * arr_im2[i];
//        sc.im += arr_re1[i] * arr_im2[i] - arr_im1[i] * arr_re2[i];
//    }
//    return sc;
//}