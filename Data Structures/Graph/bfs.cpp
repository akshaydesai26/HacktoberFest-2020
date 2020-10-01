#include <iostream>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std;

template<typename T>
class Graph {
	unordered_map<T, list<T> > l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(T src) {
		map<T, bool> visited;
		map<T, int> dist (10, 0);
		// vector<int> distances (10, 0);
		vector<int> parent (10, 0);
		queue<T> q;
		q.push(src);
		visited[src] = true;
		dist[src] = 0;
		// distances[src] = 0;
		while (!q.empty()) {
			T node = q.front();
			q.pop();

			cout << node << " distance: " << dist[node] << endl;
			for (int x : l[node]) {
				if (!visited[x]) {
					q.push(x);
					visited[x] = true;
					dist[x] = dist[node] + 1;
				}
			}
		}
	}
};
int main() {

	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);

	g.bfs(0);
	return 0;
}