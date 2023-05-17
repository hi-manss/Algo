#include <iostream>

using namespace std;

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot = array[high];

        int i = (low - 1);
        for (int j = low; j < high; j++)
        {
            if (array[j] <= pivot)
            {
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        quicksort(array, low, i);
        quicksort(array, i + 2, high);
    }
}

int main()
{
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

    quicksort(array, 0, n - 1);
cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;

    return 0;
}