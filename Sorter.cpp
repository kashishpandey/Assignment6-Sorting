#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include "Sorter.h"
using namespace std;

// default constructor
Sorter::Sorter(){}

// overloaded constructor
Sorter::Sorter(string fileName){
  fileName = fileName;
}

// destructor
Sorter::~Sorter(){
  delete num;
}

// quick sort
void Sorter::QuickSort(){
  double *sortedNum = new double[numSize]{};
  for(int i = 0; i < numSize; ++i){
    sortedNum[i] = num[i];
  }
  qs(sortedNum, 0, numSize-1);
}

void Sorter::qs(double *sortedNum, int lowI, int highI){
  if(lowI < highI){
    int lowEndIndex = Partition(sortedNum, lowI, highI);
    qs(sortedNum, lowI, lowEndIndex - 1);
    qs(sortedNum, lowEndIndex + 1, highI);
  }
}
// swapping pointers (using for Partition)
  void Sorter::Swapping(double* a, double* b){
    double temp = *a;
    *a = *b;
    *b = temp;
  }

  int Sorter::Partition(double *sortedNum, int lowI, int highI){
    // middle element = pivot
    int pivot = sortedNum[highI];
    int lowIndex = lowI;
    for(int i = lowI; i < highI; ++i){
      if(sortedNum[i] <= pivot){
        Swapping(&sortedNum[i], &sortedNum[lowIndex]);
        lowIndex++;
      }
    }
    Swapping(&sortedNum[lowIndex], &sortedNum[highI]);
    return lowIndex;
  }

// quick sort timing
  void Sorter::qsTime(){
    cout << endl;
    cout << "---------------" << endl;
    cout << "Quick Sort" << endl;
    cout << "---------------" << endl;
    clock_t startTime = clock();
    cout << "Start Time: " << startTime << endl;
    QuickSort();
    clock_t endTime = clock();
    cout << "End time: " << endTime << endl;
    double duration = ((double)(endTime-startTime))/CLOCKS_PER_SEC;
    cout << "Total duration: " << duration << " seconds" << endl;
  }

// merge sort
  void Sorter::MergeSort(){
    double *sortedNum = new double[numSize]{};
    for(int i = 0; i < numSize; ++i){
      sortedNum[i] = num[i];
    }
    ms(sortedNum, 0, numSize-1);
    delete sortedNum;
  }

  void Sorter::merge(double *sortedNum, int left, int middle, int right){
    int leftPosition = middle - left + 1;
    int rightPosition = right - middle;

    double sortLeft[leftPosition];
    double sortRight[rightPosition];

    int i, j;

    for(i = 0; i < leftPosition; ++i){
      sortLeft[i] = sortedNum[left + i];
    }

    for(j = 0; j < rightPosition; ++j){
      sortRight[j] = sortedNum[middle+1+j];
    }

    i = 0;
    j = 0;

    int k = left;

    while(i < leftPosition && j < rightPosition){
      if(sortLeft[i] <= sortRight[j]){
        sortedNum[k] = sortLeft[i];
        i++;
      }
      else{
        sortedNum[k] = sortRight[j];
        j ++;
      }
      k ++;
    }

    while(i < leftPosition){
      sortedNum[k] = sortLeft[i];
      i ++;
      k ++;
    }

    while(i < rightPosition){
      sortedNum[k] = sortRight[j];
      j ++;
      k ++;
    }
  }

  void Sorter::ms(double *sortedNum, int left, int right){
    int middle;
    if(left < right){
      // finding midpoint in the partiton
      middle = left+(right-left)/2;
      ms(sortedNum, left, middle);
      ms(sortedNum, middle + 1, right);
      // merging into sorted order
      merge(sortedNum, left, middle, right);
    }
  }

// merge sort timing
  void Sorter::msTime(){
    cout << endl;
    cout << "---------------" << endl;
    cout << "Merge Sort" << endl;
    cout << "---------------" << endl;
    clock_t startTime = clock();
    cout << "Start Time: " << startTime << endl;
    MergeSort();
    clock_t endTime = clock();
    cout << "End time: " << endTime << endl;
    double duration = ((double)(endTime-startTime))/CLOCKS_PER_SEC;
    cout << "Total duration: " << duration << " seconds" << endl;
  }

// selection sort
  void Sorter::SelectionSort(){
    double *sortedNum = new double[numSize]{};
    for(int i = 0; i < numSize; ++i){
      sortedNum[i] = num[i];
    }
    for(int i = 0; i <= numSize-1; ++i){
      for(int j=i+1; j < numSize; ++j){
        if(sortedNum[i] > sortedNum[j])
        {
          int t = sortedNum[i];
          sortedNum[i] = sortedNum[j];
          sortedNum[j] = t;
        }
      }
    }
    delete sortedNum;
  }

// selection sort timing
  void Sorter::ssTime(){
    cout << endl;
    cout << "---------------" << endl;
    cout << "Selection Sort" << endl;
    cout << "---------------" << endl;
    clock_t startTime = clock();
    cout << "Start Time: " << startTime << endl;
    SelectionSort();
    clock_t endTime = clock();
    cout << "End time: " << endTime << endl;
    double duration = ((double)(endTime-startTime))/CLOCKS_PER_SEC;
    cout << "Total Duration: " << duration << " seconds" << endl;
  }

// insertion sort
  void Sorter::InsertionSort(){
    double *sortedNum = new double[numSize]{};
    for(int i = 0; i < numSize; ++i){
      sortedNum[i] = num[i];
    }
    int key;
    int j;
    for (int i = 0; i < numSize; ++ i){
      key = sortedNum[i];
      j = i;
      while( j > 0 && sortedNum[j-1]>key){
        sortedNum[j] = sortedNum[j-1];
        j--;
      }
      sortedNum[j] = key;
    }
    delete sortedNum;
  }

// insertion sort timing
  void Sorter::insertTime(){
    cout << endl;
    cout << "---------------" << endl;
    cout << "Insertion Sort" << endl;
    cout << "---------------" << endl;
    clock_t startTime = clock();
    cout << "Start Time: " << startTime << endl;
    InsertionSort();
    clock_t endTime = clock();
    cout << "End time: " << endTime << endl;
    double duration = ((double)(endTime-startTime))/CLOCKS_PER_SEC;
    cout << "Total Duration: " << duration << " seconds" << endl;
  }

// bubble sort
void Sorter::BubbleSort(){
  double *sortedNum = new double[numSize]{};
  for(int i = 0; i < numSize; ++i){
    sortedNum[i] = num[i];
  }
  bool isSwapped;
  for (int i =0; i < numSize; ++i){
    isSwapped = false;
    for (int j = 0; j < numSize - i- 1; j ++){
      // elements are swapped if j is greater than the sucessor
      if (sortedNum[j] > sortedNum[j+1]){
        Swapping(&sortedNum[j], &sortedNum[j+1]);
        isSwapped = true;
      }
    }
    if (isSwapped == false){
      break;
    }
  }
  delete sortedNum;
}

// bubble sort timing
void Sorter::bsTime(){
  cout << endl;
  cout << "---------------" << endl;
  cout << "Bubble Sort" << endl;
  cout << "---------------" << endl;
  clock_t startTime = clock();
  cout << "Start Time: " << startTime << endl;
  BubbleSort();
  clock_t endTime = clock();
  cout << "End Time: " << endTime << endl;
  double duration = ((double)(endTime-startTime))/CLOCKS_PER_SEC;
  cout << "Total Duration: " << duration << " seconds" << endl;
}

void Sorter::fileIntoArray(){
    ifstream myfile(fileName);
    string line;
    if(myfile.is_open()){
      getline(myfile, line);
      numSize = stoi(line);
      num = new double[numSize]{};
      int current = 0;
      while(getline(myfile, line)){
        num[current] = stod(line);
        current ++;
      }
      myfile.close();
    }
  }
