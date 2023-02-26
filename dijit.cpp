#include <iostream>
using namespace std;
int n;

int findmin(int dist[],bool known[]) {
    int min = 9999,min_index;
    for(int i=0;i<n;i++){
        if(!known[i] && dist[i]<min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijiktra(int g[10][10],int src) {
    int dist[n];
    bool known[n];
    for(int i=0;i<n;i++)
        dist[i]=9999,known[i] = false;
    dist[src] = 0;

    for(int i = 0;i<n-1;i++){
        int u = findmin(dist,known);
        known[u] = true;
        for(int j=0;j<n;j++){
            if(g[u][j] && !known[j] && (dist[u]+g[u][j]) < dist[j])
                dist[j] = dist[u] + g[u][j];
        }
    }

    for(int i=0;i<n;i++)
        cout<<src<<"-"<<i<<"="<<dist[i];

}

int main(){
    cout << "ENter the vertex";
    cin >> n;
    int g[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
        }
    }
    dijiktra(g, 0);
    return 0;
}