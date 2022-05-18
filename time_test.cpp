//#include "time_test.h"

#include "class.h"
#include "class_hori.h"
#include "functions.h"
#include "operators.h"
#include <chrono>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int test(int dim) {
	CComplexVectorHori u, v, s;
	int re = 0;
	int im = 0;

	for (int i = 0; i < dim; i++) {
		u.get_arr_re().push_back(rand() % 100);
		v.get_arr_re().push_back(rand() % 100);
		u.get_arr_im().push_back(rand() % 100);
		v.get_arr_im().push_back(rand() % 100);
		s.get_arr_re().push_back(rand() % 100);
		s.get_arr_im().push_back(rand() % 100);
	}

	double start;
	double end;
	start = omp_get_wtime();
	for (int i = 0; i < v.get_dim(); i++) {
		re += u.get_real_ip(i) * v.get_real_ip(i) - u.get_imag_ip(i) * v.get_imag_ip(i);
		im += u.get_real_ip(i) * v.get_imag_ip(i) + u.get_imag_ip(i) * v.get_real_ip(i);
	}
	end = omp_get_wtime();
	printf("Scalar product %f seconds\n", end - start);

	for (int i = 0; i < dim; i++) {
		s.set_re_i(i, rand() % 100);
		s.set_im_i(i, rand() % 100);
	}


	//#pragma omp parallel for reduction(+: re, im)
	//	for (int i = 0; i < v.get_dim(); i++) {
	//		re += u.get_real_ip(i) * v.get_real_ip(i) - u.get_imag_ip(i) * v.get_imag_ip(i);
	//		im += u.get_real_ip(i) * v.get_imag_ip(i) + u.get_imag_ip(i) * v.get_real_ip(i);
	//	}
	//	end = omp_get_wtime();
	//	printf("Work omp took %f seconds\n", end - start);
	start = omp_get_wtime();
#pragma omp parallel shared(u,v)  reduction(+: re, im)
	{
# pragma omp for
		for (int i = 0; i < v.get_dim(); i++) {
			re += u.get_real_ip(i) * v.get_real_ip(i) - u.get_imag_ip(i) * v.get_imag_ip(i);
			im += u.get_real_ip(i) * v.get_imag_ip(i) + u.get_imag_ip(i) * v.get_real_ip(i);
		}
	}
	end = omp_get_wtime();
	printf("Scalar product omp %f seconds\n\n", end - start);

	/////////////////////////////////////////////////////////////////////////////////////////////


	vector<int>::iterator i;
	vector<int>::iterator j;
	vector<int>::iterator k;

	for (int i = 0; i < dim; i++) {
		s.set_re_i(i, rand() % 100);
		s.set_im_i(i, rand() % 100);
	}
	start = omp_get_wtime();
	for (int i = 0; i < s.get_dim(); i++) {
		s.set_re_i(i, u.get_real_ip(i) + v.get_real_ip(i));
		s.set_im_i(i, u.get_imag_ip(i) + v.get_imag_ip(i));
	}
	end = omp_get_wtime();
	printf("Sum %f seconds\n", end - start);


	for (int i = 0; i < dim; i++) {
		s.set_re_i(i, rand() % 100);
		s.set_im_i(i, rand() % 100);
	}
	start = omp_get_wtime();
#pragma omp parallel for
	for (int i = 0; i < s.get_dim(); i++) {
		s.set_re_i(i, u.get_real_ip(i) + v.get_real_ip(i));
	}
#pragma omp parallel for
	for (int i = 0; i < s.get_dim(); i++) {
		s.set_im_i(i, u.get_imag_ip(i) + v.get_imag_ip(i));
	}
	
	end = omp_get_wtime();
	printf("Sum omp %f seconds\n\n", end - start);

	/*end = omp_get_wtime();
	printf("Scalar product omp %f seconds\n", end - start);
	begin = std::chrono::steady_clock::now();
    #pragma omp parallel for 
	for (i = s.re_begin(), j = u.re_begin(), k = v.re_begin(); j != u.re_end(); i++, j++, k++) {
		*i = *j + *k;
	}
    #pragma omp parallel for
	for (i = s.im_begin(), j = u.im_begin(), k = v.im_begin(); j != u.im_end(); i++, j++, k++) {
		*i = *j + *k;
	}
	end = std::chrono::steady_clock::now();
	elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
	std::cout << "\nSum runtime omp is: " << elapsed_ms.count() << " ms\n";*/

	return 1;
}