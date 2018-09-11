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

            for(int i = 0, j = words.size() - 1; i < words.size()/2 + (words.size() % 2); ++i, --j) {
                if (words[i] != words[j] || !is_palindrome(words[i])) {
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
