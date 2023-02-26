#include<iostream>
using namespace std;
void insertion(int a[],int n) {
    int value, i, j;
    for(i=1;i<n;i++){
        value=a[i];
        j=i-1;
        while(j>=0 && a[j]>value){
            a[j+1]=a[j];
            i=j-1;
        }
        a[j+1]=value;
    }
}
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int N = sizeof(arr) / sizeof(arr[0]);
    insertion(arr, N);
    printArray(arr, N);
    return 0;
}
