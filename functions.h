#pragma once
#include "class.h"
#include "factory.h"
#include "factory_hori.h"
#include "factory_vert.h"
#include <map>
#include <fstream>

int test(int dim);
vector<CComplexVector*> fscan_data_and_output(const char* fname);

vector<CComplexVector*> fscan_data_without_output(string fname);
//CComplexVector** fscan_data(const char* fname, int dim, int* arrdim);
//CComplexVector** fscan_data(const char* fname, int dim);
//int create_CCV(const char* fname, int dim);
//int create_CCV_and_fout(const char* fname, int dim);
