#include <bits/stdc++.h>

using namespace std;

#define MAX 100000
string names[MAX];

int main() {
    int N;
    scanf("%d", &N);

    while(N--) {
        int M;
        scanf("%d", &M);

        for(int i = 0; i < M; ++i) {
            char b[50];
            scanf("%s", b);

            names[i] = string(b);
        }

        int Q;
        scanf("%d", &Q);

        for(int i = 0; i < Q; ++i) {
            char b[50];
            scanf("%s", b);

            if (binary_search(names, names + M, string(b))) printf("Estou Rico!\n");
            else printf("Tentarei de novo\n");
        }

        if(N) printf("\n");
    }

    return 0;
}

