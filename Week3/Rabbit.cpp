#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>


using namespace std;

struct point{
    int x, y;
};

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
const char direction[] = {'R', 'L', 'D', 'U'};

int main(){
    int C, R;

    cin >> C >> R;
    vector<string> map(R);
    struct point start, end;
    
    for (int i = 0; i < R; i++)
    {
        cin >> map[i];
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == 'R')
            {
                start = (struct point) {j,i};
            }
            else if (map[i][j] == 'D')
            {
                end = (struct point) {j,i};
            }
        }
    }

    // BFS
    queue<point> q;
    q.push(start);
    vector<vector<int> > dist(R, vector<int>(C, -1));
    vector<vector<point> > parent(R, vector<point>(C, (struct point){-1,-1}));
    vector<vector<char> > moves(R, vector<char>(C, ' '));
    dist[start.y][start.x] = 0;

    while(!q.empty())
    {
        point node = q.front();
        q.pop();

        for (int i=0; i < 4; i++)
        {
            int newX = node.x + dx[i];
            int newY = node.y + dy[i];

            if (newX < C && newX >= 0 && newY < R && newY >= 0 
                && (map[newY][newX] == '.' || map[newY][newX] == 'D')
                && dist[newY][newX] == -1)
            {
                dist[newY][newX] = dist[node.y][node.x] + 1;
                parent[newY][newX] = node;
                moves[newY][newX] = direction[i];

                q.push((struct point){newX, newY});
            }
        }
    }

    //reverse path
    string path;
    point current = end;

    if (dist[end.y][end.x] != -1)
    {
        while (current.x != start.x || current.y != start.y)
        {
            path += (moves[current.y][current.x]);
            current = parent[current.y][current.x];
        }
    }

    reverse(path.begin(),path.end());
    cout << path << endl;

    return 0;
}