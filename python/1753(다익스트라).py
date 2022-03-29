import sys
import heapq
input = sys.stdin.readline
INF = sys.maxsize

V, E = map(int, input().split())
K = int(input())

graph = [[] * (V+1) for i in range(V+1)]
dist = [INF] * (V+1)
heap = []


def dijkstar(start):
    heapq.heappush(heap, (0, start))
    dist[start] = 0

    while heap:
        # cost / index
        now_cost, now_index = heapq.heappop(heap)

        for i in graph[now_index]:
            # g[0] = index / g[1] = cost
            next_index = i[0]
            next_cost = now_cost + i[1]

            if dist[next_index] > next_cost:
                dist[next_index] = next_cost
                heapq.heappush(heap, (dist[next_index], next_index))


for i in range(E):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

dijkstar(K)

for i in range(1, V+1):
    if dist[i] == INF:
        print("INF")
    else:
        print(dist[i])
