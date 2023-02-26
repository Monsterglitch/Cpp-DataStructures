#include <iostream>
using namespace std;

int search(int array[], int n, int x) {
    for (int i = 0; i < n; i++)
        if (array[i] == x)
            return i;
    return -1;
}

int main() {
    int n, x;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter search element: ";
    cin>>x;
    int result = search(arr, n, x);
    if(result == -1){
        cout << "Element not found";
    }
    else{
        cout << "Element found at index: " << result;
    }
    return 0;
}