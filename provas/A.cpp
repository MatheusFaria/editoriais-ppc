#include <bits/stdc++.h>

using namespace std;


bool is_palindrome(string w) {
    for (int i = 0, j = w.size() - 1; i < w.size()/2; ++i, --j)
        if (w[i] != w[j]) return false;
    return true;
}

int main() {
    int N;
    cin >> N;

    while(N--) {
        char word[100], c;
        vector<string> words;
        string phrase = "";

        while(scanf("%s%c", word, &c), words.push_back(word), phrase += word, c != '\n');

        if (is_palindrome(phrase)) {
            bool ok = true;

            for(auto word: words) {
                if (!is_palindrome(word)) {
                    ok = false;
                    break;
                }
            }

            if (ok) cout << "Palindromo completo\n";
            else cout << "Frase palindromo\n";
        }
        else cout << "Nada\n";
    }
    return 0;
}
