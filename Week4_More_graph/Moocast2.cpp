#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(int x, vector<int> &repr){
    if (repr[x] < 0) return x;
    return repr[x] = find(repr[x], repr);
}

bool unite(int a, int b, vector<int> &repr){
    a = find(a,repr);
    b = find(b,repr);

    if (a==b) return false;
    if (repr[a] > repr[b]) swap(a,b);
    repr[a] += repr[b];
    repr[b] = a;

    return true;
}


int main(){
    int N;
    
    cin >> N;
    vector<pair<int,int> >  points(N);
    vector<pair<long int, pair<int,int> > > edges;
    vector<int> repr(N,-1);

    for (int i = 0; i < N; i++) cin >> points[i].first >> points[i].second;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            edges.push_back(make_pair (dx * dx + dy * dy, make_pair(i,j)));
        }
    }
    int maxDistance = 0;

    sort(edges.begin(), edges.end());

    for (auto edge : edges){
        if (unite(edge.second.first, edge.second.second, repr)){
            maxDistance = edge.first;
        };
    }

    cout << maxDistance << endl;

    return 0;
}