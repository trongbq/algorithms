#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using namespace std;

const int INFINITY = 9999;
const int NO_PATH = -1;
const int INVALID_VERTEX = -1;

struct vertex {
    int name;
    int d;
    vertex *p;
};

class Graph {
    vector<vector<int> > adj; // adjceacy-matrix with weight
private:
    int findVertexWithMinDistance(map<int, int> distances, vector<bool> visited);
    vector<int> findNeighbors(int v);
public:
    Graph(int v);
    void addEdge(int u, int v, int w);
    void dijkstra(int s);
    void display();
};

Graph::Graph(int v) {
    for (int i = 0; i < v; i++) {
        vector<int> vec;
        for (int j = 0; j < v; j++) {
            vec.push_back(NO_PATH);
        }
        adj.push_back(vec);
    }
}

void Graph::addEdge(int u, int v, int w) {
    adj[u][v] = w;
}

void Graph::dijkstra(int s) {
    map<int, int> distances; // Store current shortest-path distance from parent to a vertices
    map<int, int> parents; // Store parents of a vertices
    vector<bool> visited; // Mark vertices that are visited
    
    // Initialize data
    for (int i = 0; i < adj.size(); i++) {
        distances[i] = INFINITY;
        visited.push_back(false);
    }
    distances[s] = 0;
    
    // Start the calculation of shortest-path for all vertices
    int v = findVertexWithMinDistance(distances, visited);
    while (v != INVALID_VERTEX) {
        vector<int> neighbors = findNeighbors(v);

        for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
            int nd = distances[v] + adj[v][*it];
            if (distances[*it] > nd) {
                distances[*it] = nd;
                parents[*it] = v;
            }
        }
        visited[v] = true;
        v = findVertexWithMinDistance(distances, visited);
    }
    
    // Display the results
    cout << "Dijkstra:" << endl;
    cout << "Parent\tVertex\tDistance" << endl;
    for (int i = 0; i < adj.size(); i++) {
        cout << parents[i] << "\t" << i << "\t" << distances[i] << endl;
    }
}

// Find the vertex that is not visited and has smallest shortest-path distance
int Graph::findVertexWithMinDistance(map<int, int> distances, vector<bool> visited) {
    int min = INFINITY;
    int v = INVALID_VERTEX;

    for (map<int, int>::iterator it = distances.begin(); it != distances.end(); it++) {
        if (!visited[it->first] && min > it->second) {
            min = it->second;
            v = it-> first;
        }
    }

    return v;
}

vector<int> Graph::findNeighbors(int v) {
    vector<int> neighbors;
    for (int i = 0; i < adj.size(); i++) {
        if (adj[v][i] != NO_PATH) {
            neighbors.push_back(i);
        }
    }
    
    return neighbors;
}

void Graph::display() {
    cout << "Adjacency-matrix of graph:" << endl;
    
    cout << "   ";
    for (int i = 0; i < adj.size(); i++) {
        cout << i << "\t";
    }
    cout << endl;
    
    for (int i = 0; i < adj.size(); i++) {
        cout << i << "  ";
        for (vector<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
            if (*it == NO_PATH) {
                cout << "-\t";
            } else {
                cout << *it << "\t";
            }
        }
        cout << endl;
    }
}

int main()
{
  Graph g(9);
  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 0, 4);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 1, 8);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 5, 4);
  g.addEdge(2, 8, 2);
  g.addEdge(3, 2, 7);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 3, 9);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 2, 4);
  g.addEdge(5, 3, 14);
  g.addEdge(5, 4, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 5, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 0, 8);
  g.addEdge(7, 1, 11);
  g.addEdge(7, 6, 1);
  g.addEdge(7, 8, 7);
  g.addEdge(8, 2, 2);
  g.addEdge(8, 6, 6);
  g.addEdge(8, 7, 7);
  
  g.display();
  g.dijkstra(0);
  
  return 0;
}
