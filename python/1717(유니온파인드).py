import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def find(a):
    if a == parent[a]:
        return a
    tmp = find(parent[a])
    parent[a] = tmp
    return parent[a]


def union(a, b):
    a_root = find(a)
    b_root = find(b)

    if a_root != b_root:
        parent[a_root] = b_root


n, m = map(int, input().split())
parent = [0] * (n+1)
for i in range(n+1):
    parent[i] = i


for i in range(m):
    a, b, c = map(int, input().split())

    if a == 0:
        union(b, c)
    else:
        if find(b) == find(c):
            print("YES")
        else:
            print("NO")
