#include <iomanip>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

inline void display(int *a, int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        cout << setw(5) << a[i];
    }
    cout << "]" << endl;
}

inline void displayIndex(int n) {
    cout << "[" << setfill(' ') << setw(2) << n << "]";
    cout.fill(' ');
}

inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int a[], int n) {
    int l = 0;
    for (int i = 0; i < n; i++) {
        bool sorted = false;
        for (int j = n - 1; j >= i + 1; j--) {
            if (a[j] < a[j - 1]) {
                l++;
                swap(a[j], a[j - 1]);
                sorted = true;
            }
        }
        if (!sorted) {
            break;
        }
        cout << "[";
        cout << setfill(' ') << setw(2) << l;
        cout << "]";
        setfill(' ');
        display(a, n);
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        displayIndex(i+1);
        display(a, n);
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

void insertionSort(int a[], int n) {
  int i;
  for (i = 1; i < n; i++) {
    for (int j = i; j > 0 && a[j - 1] > a[j]; j--) {
      swap(a[j], a[j - 1]);
    }
    displayIndex(i);
    display(a, n);
  }
  displayIndex(i);
  display(a, n);
}

void shuffle(int a[], int n) {
    random_device rd;
    mt19937 gen(rd());
    for (int i = n - 1; i > 0; i--) {
        uniform_int_distribution<> dis(0, i);
        int j = dis(gen);
        swap(a[i], a[j]);
    }
}

bool isSorted(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }
    return true;
}

void bogosort(int a[], int n) {
  int step = 0;
  while (!isSorted(a, n)) {
      step++;
      displayIndex(step);
      display(a, n);
      shuffle(a, n);
  }
  step++;
  displayIndex(step);
  display(a, n);
}

void copyArray(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
    }
}

void compare(int a[], int n){
  int b[n];
  copyArray(a, b, n);
  
  cout << "===Comparison between [Bubble, Insertion, Selection, Bogo]===" <<endl << endl;
  cout << "Sample Array: " << endl;
  display(a, n);
  cout << "-----------------------------" << endl << endl;
  
  auto beg = high_resolution_clock::now();
  bubbleSort(b, n);
  auto end = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(end - beg);
  cout << "Elapsed(ms) <Bubble Sort>: " << duration.count() << endl;
  cout << "-----------------------------" << endl << endl;
  
  copyArray(a, b, n);
  beg = high_resolution_clock::now();
  insertionSort(b, n);
  end = high_resolution_clock::now();
  duration = duration_cast<microseconds>(end - beg);
  cout << "Elapsed(ms) <Insertion Sort>: " << duration.count() << endl << endl;
  cout << "-----------------------------" << endl << endl;
  
  copyArray(a, b, n);
  beg = high_resolution_clock::now();
  selectionSort(b, n);
  end = high_resolution_clock::now();
  duration = duration_cast<microseconds>(end - beg);
  cout << "Elapsed(ms) <Selection Sort>: " << duration.count() << endl << endl;
  cout << "-----------------------------" << endl << endl;
  copyArray(a, b, n);
  beg = high_resolution_clock::now();
  bogosort(b, n);
  end = high_resolution_clock::now();
  duration = duration_cast<microseconds>(end - beg);
  cout << "Elapsed(ms) <Bogo Sort>: " << duration.count() << endl << endl;
  cout << "-----------------------------" << endl << endl;
}