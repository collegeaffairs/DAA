#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;

class graph{
    public:
        int n;
        int m;
        vector<list<int>> adj;

    graph(int node, int edges){
        n = node;
        m = edges;  
        adj.resize(n);  
    }

    void storeGraph(int m){
        for(int i = 0; i < m; i++ ){
            int u,v;
            cout << "enter edge: " ;
            cin >> u;
            cin >> v;
            adj[u].push_back(v);
        }
    }

    vector<int> bfs(int source){
        bool discovered[n];
        for(int i=0;i<n ; i++){
            discovered[i] = false;
        }

        discovered[source]=true;

        vector<int> storeBFS;
        stack<int> q;
        q.push(source);

        while(!q.empty()){
            source = q.top();
            q.pop();
            cout << source << " ";
            storeBFS.push_back(source);
            for(auto it: adj[source]){
                if(!discovered[it]){
                    q.push(it);
                    discovered[it] = true;
                }
            }
        }

        return storeBFS;
    }



};

int main(){
    int n = 4;
    int m = 6;
    graph g(n,m);
    g.storeGraph(m);
    g.bfs(1);
}
