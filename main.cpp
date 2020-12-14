#include "Sorter.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv){
  if(argc == 1){
    cout << "Please enter the file name after ./a.out!!!" << endl;
    return 0;
  }
    Sorter *s = new Sorter(argv[1]);
    cout << "------------------------------" << endl;
    cout << "Timings for sorting algorthims" << endl;
    cout << "------------------------------" << endl;

    s-> sampleFile(1000);
    s->qsTime();
    s->msTime();
    s-> bsTime();
    s->insertTime();
    s-> ssTime();
    s->fileIntoArray();
    delete s;

}
