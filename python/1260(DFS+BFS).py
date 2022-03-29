import sys
from collections import deque


def dfs(n):
    print(n, end=' ')
    visited[n] = True
    for i in graph[n]:
        if not visited[i]:
            dfs(i)


def bfs(n):
    visited[n] = True
    queue = deque([n])
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


# node, branch, first node
n, m, v = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False] * (n + 1)

# make adjacency list
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(1, n+1):
    graph[i].sort()

dfs(v)
visited = [False] * (n + 1)
print()
bfs(v)
