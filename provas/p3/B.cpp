#include <bits/stdc++.h>

using namespace std;

set<string> visited;

int N;
string board;
string winning_state;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

inline void change(int c) {
    int i = c / N;
    int j = c % N;

    for(int k = 0; k < 4; ++k) {
        int p = (i + dx[k]) * N + (j + dy[k]);
        if (p > 0 && p < board.size()) board[p] = (1 - (board[p] - '0')) + '0';
    }
}

bool dfs() {
    if (board == winning_state) return true;

    visited.insert(board);

    for(int i = 0; i < board.size(); ++i) {
        change(i);
        if (!visited.count(board)) if(dfs()) return true;
        change(i);
    }

    return false;
}

int main() {

    scanf("%d", &N);

    char line[50];

    board = "";
    for(int i = 0; i < N; ++i) {
        scanf(" %[^\n]", line);
        board += string(line);
    }

    winning_state = string(N * N, '1');

    if (dfs()) printf("Y\n");
    else printf("N\n");

    return 0;
}
