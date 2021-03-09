#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <climits>
// By: Sreeda Vemuri
// Skeleton Code provided as graph.cpp, additionally, TA arman also gave some more code in class. I followed the BFS given in the textbook. 

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddVertex(string);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddVertex(string vert) {
    vertices.push_back(vert);
    // I didnt know where to use this
}

void Graph::AddEdge(string vert1,string vert2,int wgt) {
    pair<string,string> p(vert1, vert2);
    edges[p] = wgt;
    
}

bool Graph::FindVertex(string vert1) {
    //search vert1 inside list<string> vertices, it is a for-loop
    // used iterator from PrintOut(void)
    list<string>::iterator it;
    for(it = vertices.begin(); it != vertices.end(); it++)
        if(*it == vert1)
            return true;
    return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
   pair<string,string> p(vert1, vert2);
    if(edges.find(p) != edges.end())
        return edges[p];
    
    else return -1;
}

int Graph::IsReachable(string vert1, string vert2) {
    //pg. 595
    queue<string> Q;
    map<string,int> d;
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
      
    for(it = vertices.begin(); it != vertices.end(); it++) {
        d[*it] = INT_MAX;
    }
    d[vert1] = 0;
    Q.push(vert1);     
    do{
        string u = Q.front(); Q.pop();
          
        for(eit = edges.begin(); eit != edges.end(); eit++) {
            if((*eit).first.first == u) {
                string v = (*eit).first.second;
                if(d[v] >= d[u]) {
                    d[v] = d[u] + 1;
                    Q.push(v);
                }
            }
        }
    }while(!Q.empty());
    
    if(d[vert2] != INT_MAX)
        return d[vert2];

          
    return -1;
}

int main() {
    Graph G;
    string vertex, edgeBegin, edgeEnd;                    
    int wgt;
    
    cin >> vertex;
    do{
        G.vertices.push_back(vertex);
        cin >> vertex;
    }while(vertex != "END");
    
    cin >> edgeBegin;
    do{
        cin >> edgeEnd;
        cin >> wgt;
        G.AddEdge(edgeBegin, edgeEnd, wgt);
        cin >> edgeBegin; 
    }while(edgeBegin != "END");
    
    G.PrintOut();
    
    string a;
    string b;
    
    cin >> wgt;
    do{
        if(wgt == 1){
            cin >> a;
            if(G.FindVertex(a) == true)
                cout << "1" << endl;
            else cout << "0" << endl;
        }
        else if(wgt == 2){
            cin >> a;
            cin >> b;
            int cost = G.FindEdgeCost(a,b);
            cout << cost << endl;
        }
        else{
            cin >> a;
            cin >> b;
            int num = G.IsReachable(a,b);
            cout << num << endl;
        }
        cin >> wgt;
    } while (wgt != 0);
        
    return 0;
}