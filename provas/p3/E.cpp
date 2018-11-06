#include <bits/stdc++.h>

using namespace std;

#define MAX_V 10000

vector<int> G[MAX_V];
int visited[MAX_V];

bool bfs() {
    memset(visited, 0, sizeof visited);

    int initial_vertice = 0;

    queue<int> to_visit;
    to_visit.push(initial_vertice);
    visited[initial_vertice] = 1;

    while(!to_visit.empty()) {
        auto v = to_visit.front();
        to_visit.pop();

        for (auto i: G[v]) {
            if (!visited[i]) {
                visited[i] = -visited[v];
                to_visit.push(i);
            }

            if (visited[i] == visited[v]) return false;
        }
    }

    return true;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    assert(N <= 10000);
    assert(N - 1 <= M && M <= N * (N - 1));

    for (int i = 0; i < M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        assert(a < N && a >= 0);
        assert(b < N && b >= 0);

        G[a].push_back(b);
        G[b].push_back(a);
    }

    if (bfs()) {
        printf("Debate de qualidade\n");
    }
    else {
        printf("Sala polarizada!\n");
    }

    return 0;
}
