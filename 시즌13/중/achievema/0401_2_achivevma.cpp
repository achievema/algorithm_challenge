#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;
vector<int> graph[MAX];
bool visited_dfs[MAX];
bool visited_bfs[MAX];

void dfs(int v) {
    visited_dfs[v] = true;
    cout << v << " ";
    for (int next : graph[v]) {
        if (!visited_dfs[next]) {
            dfs(next);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited_bfs[v] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int next : graph[current]) {
            if (!visited_bfs[next]) {
                visited_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int N, M, V;
    cin >> N >> M >> V;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);  // 양방향
    }

    // 정점 번호가 작은 것부터 방문하도록 정렬
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    cout << "\n";
    bfs(V);
    cout << "\n";

    return 0;
}
