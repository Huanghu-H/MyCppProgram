#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Graph 
{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void DFS(int u, vector<bool>& visited, vector<pair<int, int>>& edges) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                edges.push_back({u, v});
                DFS(v, visited, edges);
            } else if (v != edges.back().first) {
                edges.push_back({u, v});
            }
        }
    }
    void findFaces() {
        vector<bool> visited(V, false);
        vector<pair<int, int>> edges;
        vector<vector<int>> faces;
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                edges.clear();
                DFS(u, visited, edges);
                vector<int> face;
                for (auto it = edges.rbegin(); it != edges.rend(); it++) {
                    face.push_back(it->first);
                    if (it->first == u && it->second == edges.back().second) {
                        break;
                    }
                }
                faces.push_back(face);
            }
        }
        for (int i = 0; i < faces.size(); i++) {
            cout << "Face " << i + 1 << ": ";
            for (int vertex : faces[i]) {
                cout << vertex << " ";
            }
            cout << endl;
        }
    }
};
int main() 
{
	int n,m;
	cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++)
    {
    	int x,y;
    	cin>>x>>y;
    	g.addEdge(x, y);
	}

    g.findFaces();
    return 0;
}
// 5 8 0 1 1 2 2 3 3 0 0 4 4 1 4 2 4 3
