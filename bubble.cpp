#include<iostream>
using namespace std;
void bubble(int a[], int n){
    for(int i=0;i<n;i++){ //for n-1 passes
        int flag = 0; //flag is used for finding redundant passes
        for(int j=0;j<n-i-1;j++){ //in the later passes the last few positions 
        // are sorted to decrease the time complexity from O(n^2) -> O(n)
        // we don't want to go through the sorted portion of the array.
            if(a[j]>a[j+1]){ //comparing first and next element
                swap(a[j],a[j+1]);
                flag=1; //flag is set 1 to indicate that swap has happened
            }
        }
    if(flag==0) //flag is 0 if no swap was made
        break; //this means that the array is sorted in the last pass so break
    }
}
void swap(int x, int y){
    int temp = y;
    y = x;
    x = temp;
}
int main(){
    //int arr[]={2,7,4,1,5,3,8};
    //int x = sizeof(arr)/sizeof(arr[0]);
    int y;
    cout<<"Enter no. of elements in the array: ";
    cin>>y;
    int arr[y];
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<y;i++){
        cin>>arr[i];
    }
    bubble(arr,y);
    for(int i=0;i<y;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
