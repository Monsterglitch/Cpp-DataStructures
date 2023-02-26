#include<iostream>
#include<cstring>
using namespace std;

#define INF 999999
#define V 5

int G[V][V] = {
  {0, 9, 75, 0, 0},
  {9, 0, 95, 19, 42},
  {75, 95, 0, 51, 66},
  {0, 19, 51, 0, 31},
  {0, 42, 66, 31, 0}};

int main() {
    int no_edge;
    int x;
    int y;
    int selected[V];
    memset(selected, false, sizeof(selected));// sets all the values to false
    selected[0] = true;
    cout<<"Edge"<<" : "<<"Weight"<<endl;
    while(no_edge < V-1) {
        x = 0;
        y = 0;
        int min = INF;
        for(int i = 0;i < V;i++) {
            if(selected[i]) {
                for(int j = 0;j < V;j++) {
                    if(!selected[j] && G[i][j]) {
                        if(min > G[i][j]) {
                            min = G[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        cout<<"("<<x<<"-"<<y<<")"<<":  "<<min<<endl;
        selected[y] = true;
        no_edge++;
    }
    return 0;
}
/*
OUTPUT
Edge : Weight
(0-1):  9
(1-3):  19
(3-4):  31
(3-2):  51
*/