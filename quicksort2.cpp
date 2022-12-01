#include <cstdlib>
#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int partition(int array[], int low, int high) {

  int pivot = array[high];

  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {

      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);

  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

int main() {
    int n;
    cout<<"Enter the number of elements needed in the array : ";
    cin>>n;
    int* data = new int(n);
    cout<<"Enter end point : ";
    int b;
    cin>>b;
    for(int i=0;i<n;i++){
        data[i] = 1 + rand()%b;
    }
    cout<<endl;
  cout << "Given Array : ";

 auto start = high_resolution_clock::now();
  printArray(data, n);
  quickSort(data, 0, n - 1); 
  cout << "Sorted array : ";
  printArray(data, n);

  auto stop = high_resolution_clock::now();

auto duration = duration_cast<nanoseconds>(stop - start); 
    cout << "Time taken by Quick sort : "
         << duration.count() << " nanoseconds" << endl;
 
    return 0;
}