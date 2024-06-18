#include <iostream>
#include <string>
#include <vector>

using namespace std;

int charToIndex(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 26;
    }
    return -1;
}

int main(){
    string s,t;
    int S, T;
    vector<int> countS(52, 0), countT(52, 0);
    int result = 0;

    cin >> S >> T;
    cin >> s >> t;

    if (S > T) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < S; ++i) {
        countS[charToIndex(s[i])]++;
        countT[charToIndex(t[i])]++;
    }

    if (countS == countT) result++;

    for (int i = S; i < T; ++i) {
        countT[charToIndex(t[i])]++;
        countT[charToIndex(t[i - S])]--;

        if (countS == countT) result++;
    }
    

    cout << result << endl;

    return 0;
};