#pragma once
#include "class.h"
#include "class_hori.h"
#include "functions.h"
#include "operators.h"
#include "AT.h"
//#include "time_test.h"

int main()
{
    if (AT() == 1) {
        cout << "Autotest passed!\n\n";
    }
    if (AT() == 0) {
        cout << "Autotest failled!\n\n";
    }

    int mode = 0;
   
    test(1000000);
    std::cout << "Read array of vectors and derive in file - 1\n\n";
    std::cout << "Arithmetic with vectors - 2\n\n\n";
    std::cin >> mode;
   
    if (mode == 1) {
        vector<CComplexVector*> arr;
        char name[20];
        std::cout << "Enter name of file\n";
        std::cin >> name;
      //  create_CCV_and_fout(name, dim);
        arr = fscan_data_and_output(name);

    }
    else if (mode == 2) {
        vector<CComplexVector*> arr;
       
        CComplexVectorHori sum;
        CComplexVectorHori dif;
        ComplexNumber sp;

        string name;
        std::cout << "\nEnter name of file with two vectors\n";
        std::cin >> name;
        arr = fscan_data_without_output(name);

        CComplexVectorHori a(*arr[0]);
        CComplexVectorHori b(*arr[1]);

        sum = a + b;
        sum.output();

        dif = a - b;
        dif.output();

        sp = a*b;
        sp.file_otput(a.get_foutput());
    }
    else {
        cout << "Incorrect nuber\n";
    }

  
    return 1;
}
