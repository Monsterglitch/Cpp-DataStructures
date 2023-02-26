#include<iostream>
using namespace std;
void merge(int a[],int &l, int &m, int &n){//sorts the divided parts of the original array
    int p=m-l+1;//total elements of left array
    int q=n-m;//total elements of right array

    int L[p],R[q];//empty array creation
    for(int i=0;i<p;i++){
        L[i]=a[l+i];//assigning values to the left array
    }
    for(int j=0;j<q;j++){
        R[j]=a[m+1+j];//assigning values to the right array
    }

    int i, j, k;
    i=0;j=0;k=l;//k=l is the starting index of the original array

    while(i<p && j<q){
        if(L[i]<=R[j]){//compares the left and right array element
            a[k]=L[i];//overwrites the elements in the original array
            i++;//with elements of left array
        }
        else{
            a[k]=R[j];//overwrites the elements in the original array
            j++;//with elements of right array
        }
        k++;//index of the original array is incremented for the filling of next index 
    }

    while(i<p){
        a[k]=L[i];
        i++;
        k++;
    }//executes if the right array is exhausted
    while(j<q){
        a[k]=R[j];
        j++;
        k++;
    }//executes if the left array is exhausted
}
void mergesort(int a[], int g, int h){
    if(g<h){//checks if start element is less than the end element
        int mid=g+(h-g)/2;
        mergesort(a,g,mid);//divides the array into 2 parts -> left part
        mergesort(a,mid+1,h);//right part
        merge(a,g,mid,h);//function call
    }
}
void printarray(int a[], int &n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}//prints array
int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    cout<<"Enter array elements: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }//input of array
    //int arr[] = {6, 5, 12, 10, 9, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    mergesort(arr,0,size-1);
    cout<<"Sorted Array!"<<endl;
    printarray(arr,size);
    return 0;
}