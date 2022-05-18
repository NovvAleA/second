#include "operators.h"
#include <chrono>


ComplexNumber operator*(CComplexVector& u, CComplexVector& v) {
	ComplexNumber sc;
	if (u.get_dim() != v.get_dim()) {
		cout << "Dim error in * !\n";
		return sc;
	}
	int rea = 0, ime = 0;
//	int real = 0,
//	int imag = 0;
	/*vector<int>::iterator i1 = u.re_begin();
	vector<int>::iterator i2 = u.im_begin();
	vector<int>::iterator j1 = v.re_begin();
	vector<int>::iterator j2 = v.im_begin();

	for (i1; i1 != u.re_end(); i1++, i2++, j1++, j2++) {
		sc.re += (*i1) * (*j1) + (*i2) * (*j2);
		sc.im += (*i1) * (*j2) - (*i2) * (*j1);

	}*/

//	auto begin = std::chrono::steady_clock::now();
//    #pragma omp parallel for reduction(+: re, im)
#pragma omp parallel shared(u,v)  reduction(+: rea, ime)
	{
# pragma omp for
		for (int i = 0; i < v.get_dim(); i++) {
			rea += u.get_real_ip(i) * v.get_real_ip(i) - u.get_imag_ip(i) * v.get_imag_ip(i);
			ime += u.get_real_ip(i) * v.get_imag_ip(i) + u.get_imag_ip(i) * v.get_real_ip(i);
		}
	}
	sc.re = rea;
	sc.im = ime;
//	auto end = std::chrono::steady_clock::now();
//	auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
//	std::cout << "\nScular product runtime is: " << elapsed_ms.count() << " ms\n";

	
	return sc;
}
