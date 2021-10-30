#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e6 + 1;
int N, M;	// put them in global, could be shared
vector<int> adj[SIZE];
bool visited[SIZE];

// use BFS to find the path
// this is a generic BFS code
bool find_path(int x, int y) {
	fill(visited, visited + SIZE, false);	// initialize with false
	visited[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (int sub_node : adj[node]) {
			if (sub_node == y) return true;
			if (!visited[sub_node])
			{
				q.push(sub_node);
				visited[sub_node] = true;
			}
		}
	}
	return false;
}

int main() {
	// the following 3 lines is to accelerate the input
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;	// we need to convert them into adj list
		adj[a].push_back(b);
	}
	int p, q;
	cin >> p >> q;
	if (find_path(p, q)) {
		cout << "yes" << endl;
	}
	else if (find_path(q, p)) {
		cout << "no" << endl;
	}
	else {
		cout << "unknown" << endl;
	}
}