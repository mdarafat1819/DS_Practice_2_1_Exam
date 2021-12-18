#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
    bool visited[100];
    int vertices, edges;
    vector<int> adjList[100];
public:
    Graph() {
        for(int i = 0; i < 100; i++) visited[i] = false;
    }
    void input() {
        int v, e, a, b;
        cin>>v>>e;
        vertices = v;
        edges = e;
        for(int i = 0; i < edges; i++) {
            cin>>a>>b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
    }

    void dfs(int source) {

        stack<int> s;
        s.push(source);
        visited[source] = true;

        while(!s.empty()) {
            int node = s.top();
            cout<<node<<" ";
            s.pop();
            for(int i = 0; i < adjList[node].size(); i++) {
                if(visited[adjList[node][i]] == false) {
                    s.push(adjList[node][i]);
                    visited[adjList[node][i]] = true;
                }
            }
        }
       
    }
    void dfsFull() {
        for(int i = 1; i <= vertices; i++) {
            if(!visited[i]) dfs(i);
        }
    }

};

int main() {

    freopen("D:\\c++\\cp\\input.txt", "r", stdin);
    //freopen("D:\\c++\\cp\\output.txt", "w", stdout);
    Graph g;

    g.input();
    g.dfsFull();

    return 0;
}