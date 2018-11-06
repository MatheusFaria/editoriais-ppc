#include <bits/stdc++.h>

using namespace std;

#define MAX_N 10010

using ii = pair<int, int>;

vector<ii> G[MAX_N];
int distances[MAX_N];

void djikstra_sssp(int s) {
    memset(distances, -1, sizeof distances);

    priority_queue<ii, vector<ii>, greater<ii>> to_visit;
    distances[s] = 0;
    to_visit.push(ii(distances[s], s));

    while(!to_visit.empty()) {
        auto d = to_visit.top().first;
        auto u = to_visit.top().second;
        to_visit.pop();

        if (d > distances[u]) continue;

        for(const auto & wv: G[u]) {
            auto w = wv.first;
            auto v = wv.second;

            if (distances[u] + w < distances[v] || distances[v] == -1) {
                distances[v] = distances[u] + w;
                to_visit.push(ii(distances[v], v));
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    while(M--) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        G[a].push_back(ii(w, b));
        G[b].push_back(ii(w, a));
    }

    djikstra_sssp(1);

    vector<ii> C;

    for (int i = 2; i <= N; ++i)
        if (distances[i] != -1) C.push_back(ii(distances[i], i));

    sort(C.begin(), C.end());

    printf("Cidades:\n");
    for(auto c: C) printf("%d %d\n", c.second, c.first);

    return 0;
}
