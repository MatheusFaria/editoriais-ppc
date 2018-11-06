#include <bits/stdc++.h>

using namespace std;

int main() {

    int N;
    cin >> N;
    getchar();

    while(N--) {
        vector<char> braces;
        bool ok = true;

        char c;
        while(scanf("%c", &c), c != '\n') {
            if (c == '[' || c == '(' || c == '{') braces.push_back(c);
            else if(c == '}' || c == ']' || c == ')') {
                if (!braces.empty()) {
                         if (braces.back() == '[' && c == ']') braces.pop_back();
                    else if (braces.back() == '{' && c == '}') braces.pop_back();
                    else if (braces.back() == '(' && c == ')') braces.pop_back();
                    else ok = false;
                }
                else ok = false;
            }
        }

        if (ok && braces.empty()) cout << "Compilou\n";
        else cout << "Erro de compilacao\n";
    }

    return 0;
}
