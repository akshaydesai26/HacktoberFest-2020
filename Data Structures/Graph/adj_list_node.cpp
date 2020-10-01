#include <iostream>
#include <cstring>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {
	unordered_map<string, list<pair<string, int> > > l;
public:
	void addeEdge(string x, string y, bool birdir, int weight) {
		l[x].push_back(make_pair(y, weight));

		if (birdir) {
			l[y].push_back(make_pair(x, weight));
		}
	}

	void printList() {
		for (auto p : l) {
			string city = p.first;
			list<pair<string, int> > nbrs = p.second;
			cout << city << "->";
			for (auto nbr : nbrs) {
				cout << nbr.first << " " << nbr.second << " , ";
			}
			cout << endl;
		}
	}
};
int main() {

	Graph g;
	g.addeEdge("A", "B", true, 20);
	g.addeEdge("A", "c", true, 10);
	g.addeEdge("A", "D", false, 50);
	g.addeEdge("B", "D", true, 40);
	g.addeEdge("c", "D", true, 30);
	g.printList();
	return 0;
}