#include <iostream>

using namespace std;

void merge(int array[], int low, int mid, int high) {
  int n1 = mid - low + 1;
  int n2 = high - mid;

  int L[n1], R[n2];

  for (int i = 0; i < n1; ++i) {
    L[i] = array[low + i];
  }
  for (int j = 0; j < n2; ++j) {
    R[j] = array[mid + 1 + j];
  }

  int i = 0, j = 0;
  int k = low;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      array[k] = L[i];
      i++;
    } else {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    array[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int array[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    merge(array, low, mid, high);
  }
}

int main() {
//   int array[] = {1, 5, 3, 2, 4};
  int size;
    cout << "Enter Size of Array: ";
    cin >> size;
    int array[size];
    cout << "Enter only " << size << " Elements ";
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " Element: ";
        cin >> array[i];
    }


  int n = sizeof(array) / sizeof(array[0]);

  mergeSort(array, 0, n - 1);
cout << "Sorted Array: ";
  for (int i = 0; i < n; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  return 0;
}