#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    // Number of nodes and edges
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    cout << "Enter the number of edges: ";
    cin >> edges;

    // Adjacency list representation using a map of vectors
    map<int, vector<int> > adjacencyList;

    // Input edges
    cout << "Enter the edges (format: u v, where u and v are nodes):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;

        // Add edge u -> v
        adjacencyList[u].push_back(v);

        // Add edge v -> u (uncomment the line below for an undirected graph)
        // adjacencyList[v].push_back(u);
    }

    // Output the adjacency list
    cout << "\nAdjacency List:" << endl;
    for (const auto &pair : adjacencyList) {
        cout << pair.first << ": ";
        for (const auto &neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
