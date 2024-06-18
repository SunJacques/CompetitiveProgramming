#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> point;

int euclidian(point p1,point p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void printTree(vector <vector <int> >& tree,int N, int K){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j ++){
            cout << tree[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){
    int N,K;
    int x,y;
    cin >> N >> K;
    vector <vector <int> > tree(N, vector<int>(N, -1));
    vector <point> checkpoints;

    
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        checkpoints.push_back(make_pair(x, y));
    }

    
    for (int i = 0; i < N - 1; i++){
        for (int j = i + 1; j < N - K + i; j ++){
            tree[i][j] = euclidian(checkpoints[i], checkpoints[j]);
        }
    }

    

    printTree(tree, N, K);

    return 0;
}