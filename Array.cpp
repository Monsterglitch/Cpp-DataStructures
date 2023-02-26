#include<iostream>
using namespace std;

template<typename T>
class List {
    private:
        T *arr;
        int size,capacity;
    public:
        List() {
            size = capacity = 0;
            arr = new T[capacity];
        }  
        /*List(int n) {
            capacity = n;size = 0;
            arr = new T[capacity];
        }*/
        void getCapacity() {
            cout<<"Enter the capacity of the list:";
            cin>>capacity;
        }
        void append(T val) {
            if(size == capacity) {
                cout<<"Array is full....";
                exit(-1);
            }
            else {
                arr[size] = val;
                size++;
            }
        }
        void insert(int pos,T val) {
            if(pos>size || pos>capacity) {
                cout<<"Cannot be inserted at this particular position...";
                exit(-1);
            }
            else {
                for(int i=size-1;i>=pos-1;i--)
                    	arr[i+1] = arr[i];
                arr[pos-1] = val;
                size++;
            }
        }
        void del(int pos) {
            if(pos>size) {
                	cout<<"No element is in that position...";
                	exit(-1);
            }
            else {
             for(int i=pos-1;i<size-1;i++)
             	arr[i] = arr[i+1];
             size--;
            }
        }
        void display() {
            for(int i=0;i<size;i++)
                	cout<<arr[i]<<" ";
            cout<<"\n";
        }
};
int main() {
    List<int> lst;
    lst.getCapacity();
    char ch='y';
    do {
        int choice,temp,pos;
        cout<<"1 APPEND AN ELEMENT\n2 INSERT AN ELEMENT\n3 DELETE AN ELEMENT\n4 DISPLAY\n";
        cout<<"Enter the choice(1/2/3/4):";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the element to be added:";
                cin>>temp;
                lst.append(temp);
                break;
            case 2:
                cout<<"Enter the element to be inserted:";
                cin>>temp;
                cout<<"Enter the position to be inserted:";
                cin>>pos;
                lst.insert(pos,temp);
                break;
            case 3:
                cout<<"Enter the position to be deleted:";
                cin>>pos;
                lst.del(pos);
                break;
            case 4:
                lst.display();
                break;
            default:
                cout<<"Invalid choice...\n";
        }
        cout<<"Do you wanna continue(y/n):";
        cin>>ch;
        cout<<"\n";
    } while (ch == 'y');
    return 0;
}
