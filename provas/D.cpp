#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    bool xxx = false;
    while(cin >> N, N) {
        if (xxx) cout << endl;
        xxx = true;

        int freq[10001] = {};

        while(N--) {
            int a;
            cin >> a;
            freq[a]++;
        }

        int M = 0, Mi = 0, total = 0;
        for(int i = 0; i < 10001; ++i) {
            if (freq[i]) total++;
            if (freq[i] > M) M = freq[i], Mi = i;
        }

        cout << "Mais votado foi " << Mi << " com " << M << " votos\n";
        cout << "No total foram " << total << " candidatos\n";
    }

    return 0;
}
