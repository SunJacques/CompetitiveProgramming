#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int N, C;
    cin >> N;
    vector <int> song(N);

    for (int i = 0; i < N; i++){
        cin >> song[i];
    }

    cin >> C;
    
    multiset <int> chords;
    for (int i = 0; i < C; i++){
        int x;
        std::cin >> x;
        chords.insert(x);
    }

    vector<int> seventh;
    for (int i = 0; i < N - C + 1; i++){
        multiset<int> window(song.begin() + i, song.begin() + i + C);

        auto it1 = window.begin();
        auto it2 = chords.begin();
        bool same = true;

        while (it1 != window.end() && it2 != chords.end()){
            int diff = *(window.begin()) - *(chords.begin());
            if (*it1 - *it2 != diff){
                same = false;
            }
            ++it1;
            ++it2;
        }

        if (same == true){
            seventh.push_back(i + 1);
        }
    }

    cout << seventh.size() << endl;

    for (int result : seventh){
        cout << result << endl;
    }
    return 0;
}