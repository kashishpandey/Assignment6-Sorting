#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Sorter{
  public:

    Sorter();
    Sorter(string fileName);
    ~Sorter();

    void QuickSort();
    void qsTime();
    void qs(double *sortedNum, int lowI, int highI);
    void MergeSort();
    void msTime();
    void ms(double *sortedNum, int left, int right);
    void merge(double *sortedNum, int left, int middle, int right);
    void SelectionSort();
    void ssTime();
    void InsertionSort();
    void insertTime();
    void BubbleSort();
    void bsTime();

    void fileIntoArray();
    double numberGen(double min, double max);
    void sampleFile(int size);

    void Swapping(double*a, double*b);
    int Partition(double *sortedNum, int lowI, int highI);

    private:
      double *num;
      // number of elements
      int numSize;
      // text file containing a list of double values
      string fileName;

      //ifstream inFile;
      ofstream outFile;
  };
