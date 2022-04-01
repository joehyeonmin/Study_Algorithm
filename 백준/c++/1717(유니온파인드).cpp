#include <bits/stdc++.h>

using namespace std;
int parent[1000001];

int find(int x)
{
    if (parent[x] == x)
        return x;
    // 경로 압축을 위해 이렇게 표현
    return parent[x] = find(parent[x]);
}

// v를 부모로 
//   v
//   |
//   u
void union_tree(int a, int b)
{
    int aRoot = find(a);
    int bRoot = find(b);
    if (aRoot != bRoot)
        parent[aRoot] = bRoot;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a, b, c;

    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;

        if (a == 0)
        {
            union_tree(b, c);
        }
        else if (a == 1)
        {
            if (find(b) == find(c))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}