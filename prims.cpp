#include <bits/stdc++.h>
using namespace std;

// MINIMUM SPANNING TREE ==> PRIMS
void Prims(int n, int ** graph){
    bool * visited = new bool[n];
    for(int i=0; i<n; i++)visited[i] = false;
    int * Weight = new int[n];
    for(int i=0; i<n; i++)Weight[i]=INT_MAX;
    Weight[0]=0;
    int * Parents = new int[n];
    for(int i=0; i<n; i++)Parents[i]=i;
    int count = 0;
    while(count < n){
        int minW = INT_MAX, minI;
        for(int i=0; i<n; i++){
            if(visited[i])continue;
            if(minW>Weight[i]){
                minW = Weight[i];
                minI = i;
            }
        } 
        visited[minI] = true;
        for(int i=0; i<n; i++){
            if(graph[minI][i]>0 && !visited[i]){
                if(Weight[i] > graph[minI][i]){
                    Weight[i] = graph[minI][i];
                    Parents[i] = minI;
                }
            }
        }
        count++;
    }

    // Printing MST
    for(int i=0; i<n-1; i++){
        cout<<i+1<<" "<<Parents[i+1]<<" "<<Weight[i+1]<<endl;
    }

    //delete
    delete[] Weight;
    delete[] Parents;
    delete[] visited;
}

// Use adjency list and priority queue for optimized approach
// O(E + Elog(N))

int main()
{
    ios_base::sync_with_stdio( false ) ;  
    cin.tie(NULL) ; 
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen( "input.txt" , "r", stdin);
        freopen( "output.txt" , "w", stdout);
        freopen( "Error.txt" , "w", stderr);
    #endif

    int n,e;
    cin>>n>>e;
    int ** graph = new int * [n];
    for(int i=0 ; i<n ; i++){
      graph[i] = new int [n];
      for(int j=0;j<n;j++)graph[i][j]=-1;
    }
    for(int i=0;i<e;i++){
      int n1,n2,w;
      cin>>n1>>n2>>w;
      graph[n1][n2]=w;
      graph[n2][n1]=w;
    }

    Prims(n,graph);

    return 0;
}
