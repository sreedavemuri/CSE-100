#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;
// I didn't have a chance to get the code from the TA at that time. I used Prims Algorithm based on the pseudocode given

int* prims_algo(int n, vector<pair<int, int>> adj[], bool Q[], int key[], int parents[] ){
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>G;
    G.push(pair<int,int>(0,0));
    
    for(int i = 0; i<n; i++){
        key[i]= INT_MAX; 
        parents[i] = 0;
    }
    while(!G.empty()) {
        int u = G.top().second; 
        G.pop();
        Q[u] = true;
        
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i].first;
            int w = adj[u][i].second;
            
            if(!Q[v] && key[v] > w){
                key[v] = adj[u][i].second;
                G.push(pair<int,int>(w,v));
                parents[v] = u;
            }
        }     
    }
    return parents;
}

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    //99999 = INT_MAX
    vector<pair<int, int>> adj[99999];
    bool Q[99999]; 
    int key[99999];
    int parents[99999];

    for(int i = 0; i < m; i++){
        int u, v, w; 
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    prims_algo(n, adj, Q, key, parents);
    for(int i = 1; i < n; i++)
        cout<< parents[i] <<endl;

    return 0;
}