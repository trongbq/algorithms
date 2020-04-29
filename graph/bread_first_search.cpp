#import <iostream>
#import <list>
#import <vector>
#import <queue>

using namespace std;

// Undirected Graph
class Graph {
    vector<list<int> > adj; // Using adjacency-list to present graph
public:
    Graph(int v);
    void addEdge(int u, int v);
    void bfs(int s);
    void display();
};

Graph::Graph(int v) {
    for (int i = 0; i < v; i++) {
        adj.push_back(list<int>(0));
    }
}

void Graph::addEdge(int u, int v) {
    // Graph is undirected so we have to create 2 edges
    adj[u].push_back(v);
    adj[v].push_front(u);
}

void Graph::display() {
    cout << "Adjacency-list of graph:" << endl;
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ":";
        for (list<int>::iterator it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << " -> " << *it;
        }
        cout << endl;
    }
}

// Discover every edge off the graph that are reachable from s
void Graph::bfs(int s) {
    cout << "Start BFS: ";

    // Keep track of vertices that are visited
    vector<int> visited(adj.size());
    for (int i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }

    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        // Print out the current visited vertex
        cout << " " << v;

        for (list<int>::iterator it = adj[v].begin(); it != adj[v].end(); it++) {
            if (!visited[*it]) {
                q.push(*it);
                visited[*it] = true;
            }
        }
    }

    cout << endl;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
    cout << endl;
    g.bfs(2);

    return 0;
}


