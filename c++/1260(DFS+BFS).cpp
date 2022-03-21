#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int N, M, V;
vector<int> graph[1001];
int visited[1001];
queue<int> q;

void dfs(int start)
{
    if (visited[start] == 1)
        return;

    visited[start] = 1;
    cout << start << " ";

    for (int i = 0; i < graph[start].size(); i++)
    {
        dfs(graph[start][i]);
    }
}

void bfs(int start)
{
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout << cur << " ";

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (visited[next] == 0)
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> V;
    int a, b;
    for (int i = 1; i < M + 1; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i < N + 1; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(V);

    for (int i = 1; i < N + 1; i++)
    {
        visited[i] = 0;
    }
    cout << "\n";

    bfs(V);

    return 0;
}