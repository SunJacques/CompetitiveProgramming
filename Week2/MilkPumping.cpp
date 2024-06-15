#include <iostream>
#include <list>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int N,M;
    int a,b,c,f;
    int INF = 99999999;
    typedef pair<int, pair<int,int> > node;
    typedef pair<long long,int> plli;
    vector<node> edges[1001];
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c >> f;
        edges[a].push_back(make_pair(c,make_pair(b,f)));
        edges[b].push_back(make_pair(c,make_pair(a,f))); // undirected graph
    }

    long long best_score = 0;

    for (int min_flow = 1 ; min_flow <= 1000; min_flow++)
    {
        int start_node = 1;
        long long dist[N + 1];
        fill(dist, dist+ N + 1, INF);
        priority_queue<plli, vector<plli>, greater<plli> > p_queue;
        p_queue.push(make_pair(0,start_node));
        dist[start_node] = 0;

        while (!p_queue.empty())
        {
            auto [node_dist, curr] = p_queue.top();
            p_queue.pop();

            if (dist[curr] == node_dist) //
            {
                for (auto v : edges[curr])
                {
                    int flow = v.second.second;
                    if (flow >= min_flow && v.first + node_dist < dist[v.second.first])
                    {
                        dist[v.second.first] = v.first + node_dist;
                        p_queue.push(make_pair(dist[v.second.first], v.second.first));
                    }
                }
            }
        }

        if (dist[N] != INF) // if we can reach the end node
        {
            long long score = static_cast<long long>(1000000) * min_flow / dist[N];
            if (score > best_score)
            {
                best_score = score;
            }
        }
    }

    cout << best_score << endl;

    return 0;
}