#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    bool ccc = true;
    while(cin >> N, N) {
        if (!ccc) cout << endl;
        ccc = false;

        string ids[10001];
        vector<int> ages;

        while(N--) {
            string a;
            int b;
            cin >> a >> b;

            ids[b] = a;
            ages.push_back(b);
        }

        sort(ages.begin(), ages.end());

        for(auto age: ages) {
            cout << ids[age] << endl;
        }
    }

    return 0;
}
