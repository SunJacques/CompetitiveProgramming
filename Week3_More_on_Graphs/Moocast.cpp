#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct coord {
        int x;
        int y;
    };

double euclidean(const coord& p1,const coord& p2){
        double deltaX = p2.x - p1.x;
        double deltaY = p2.y - p1.y;

        return sqrt(deltaX * deltaX + deltaY * deltaY);
    };

int main(){
    int N;
    cin >> N;
    vector< vector<int> > adjacency(N);
    pair<coord,long> cow[N];

    for (int i = 0; i < N ; i++)
    {
        cin >> cow[i].first.x >> cow[i].first.y >> cow[i].second;
    }

    //Adjacency matrix
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i != j && euclidean(cow[i].first, cow[j].first) <= cow[i].second) {
                adjacency[i].push_back(j);
            }
        }
    }

    // BFS for every cow
    int maxCow = 0;
    
    for (int i = 0; i < N ;i++)
    {
        int counter = 1;
        vector<bool> seen(N, false);
        vector<int> todo;

        todo.push_back(i);
        seen[i] = true;

        for (size_t id = 0; id < todo.size(); id++)
        {
            for (auto v : adjacency[todo[id]])
            {
                if (!seen[v])
                {
                    seen[v] = true;
                    todo.push_back(v);
                    counter++;
                }
            }
        }

        if (counter > maxCow)
        {
            maxCow = counter;
        }
    }
    
    cout << maxCow << endl;

    return 0;
}

