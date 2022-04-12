#include "functions.h"


vector<CComplexVector*> fscan_data_and_output(const char* fname) {

	vector<CComplexVector*> arr = fscan_data_without_output(fname);
	vector<CComplexVector*>::iterator k;

	for (k = arr.begin(); k != arr.end(); k++) {(*k)->output();}
	return arr;
}

vector<CComplexVector*> fscan_data_without_output(const char* fname) {
	ifstream inp;
	string tmp;
	int  i = 0;

	inp.open(fname);
	if (!inp.is_open()) {
		printf("Fileread error!");
	}

	vector<CComplexVector*> arr;
	map<string, Factory*> factory;
	factory["Hori"] = new Factory_Hori;
	factory["Vert"] = new Factory_Vert;

	while (inp >> tmp) {
		arr.push_back(factory[tmp]->Create(inp));
	}
	inp.close();

	return arr;
}





