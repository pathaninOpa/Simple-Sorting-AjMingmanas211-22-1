#include <iomanip>
#include <iostream>
using namespace std;

inline void display(int *a, int n){
  for(int i = 0 ;i < n;i++){
    cout<< setw(5) << a[i];
  }
  cout<<endl;
}

inline void displayIndex(int n){
  cout << "[";
  cout << setfill(' ') << setw(2) << n;
  cout << "]";
  setfill(0);
}

inline void swap(int &a,int &b){
  int temp = a;
  a = b;
  b = temp;
}

void bubbleSort(int a[], int n) {
  for(int i = 0; i < n; i++) {
    bool sorted = false;
    for (int j = n - 1; j >= 1; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        display(a,n);
        sorted = true;
      }
    }
    if (!sorted) {
      break;
    }
  }
}

void selectionSort(int a[], int n) {
    for(int i = 0; i < n - 1; i++){
        int temp;
        temp = i;
        displayIndex(n-i-1);
        display(a, n);
        for (int j = i + 1; j < n; j++){
            if (a[j] < a[i]) {
                temp = j;
            }
        }
        swap(a[i],a[temp]);
    } 
}


void insertion(int a[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && a[j - 1] > a[j]; j--){
            swap(a[j], a[j - 1]);
        }
        displayIndex(n-i);
        display(a, n);
    }
}
