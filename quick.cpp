#include <iostream>
using namespace std;
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
//function to rearrange array
int partition(int array[], int low, int high) {
    int pivot = array[high];//pointer for pivot
    int i = (low - 1);//pointer for greater element
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {//checking if the current value is lesser than pivot element
            i++;
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            swap(&array[i], &array[j]);//swap function is called
        }
    }
    swap(&array[i + 1], &array[high]);//element smaller than pivot is replaced with the element greater than pivot
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
    int pi = partition(array, low, high);//partition function is called
    quickSort(array, low, pi - 1);// elements smaller than pivot are on left of pivot
    quickSort(array, pi + 1, high);// elements greater than pivot are on righ of pivot

    }
}

int main() {
    int data[] = {8, 7, 6, 1, 0, 9, 2};//array is declared
    int n = sizeof(data) / sizeof(data[0]);//size of the array is calculated

    cout << "Unsorted Array: \n";
    printArray(data, n);//printing array
    quickSort(data, 0, n - 1);

    cout << "Sorted array in ascending order: \n";
    printArray(data, n);
}