#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int V, E, K;
vector<pair<int, int>> graph[20001];
int dist[20001];
bool isVisited[20001];

int INF = 10000000;

priority_queue<pair<int, int>> pq;

void dijkstar(int k)
{
    pq.push(make_pair(0, k));

    while (!pq.empty())
    {
        int now_index = pq.top().second;
        int now_cost = -pq.top().first;

        pq.pop();

        for (int i = 0; i < graph[now_index].size(); i++)
        {
            int next_index = graph[now_index][i].first;
            int next_cost = graph[now_index][i].second + now_cost;

            if (dist[next_index] > next_cost)
            {
                dist[next_index] = next_cost;
                pq.push(make_pair(-dist[next_index], next_index));
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;
    cin >> K;
    int a, b, c;

    for (int i = 0; i < E; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }

    for (int i = 0; i <= V; i++) {
        dist[i] = INF;
        isVisited[i] = false;
    }

    dist[K] = 0;
    dijkstar(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF)
        {
            cout << "INF" << "\n";
            continue;
        }
        cout << dist[i] << "\n";
    }

    return 0;
}
