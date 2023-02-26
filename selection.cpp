#include<iostream>
using namespace std;
void selection(int a[], int n){
    for(int i=0;i<n-1;i++){//for n-2 passes since, the last element need not 
    // be sorted at the final pass
        int min=i;//minimum value is set to i initially
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;//updating the minimum value after comparing
            }
        }
        //swapping
        swap(a[i],a[min]);
    }
}
void swap(int x, int y){
    int temp = y;
    y = x;
    x = temp;
}
int main(){
    //int arr[]={2,7,4,1,5,3};
    //int x = sizeof(arr)/sizeof(arr[0]);
    int y;
    cout<<"Enter no. of elements in the array: ";
    cin>>y;
    int arr[y];
    cout<<"Enter array elements: "<<endl;
    for(int i=0;i<y;i++){
        cin>>arr[i];
    }
    selection(arr,y);
    for(int i=0;i<y;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
