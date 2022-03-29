# your code goes here
import sys
input = sys.stdin.readline


def update(a, b):
    idx = a + size-1
    tree[idx] = b
    while idx != 1:
        idx = idx//2
        tree[idx] = tree[idx*2]+tree[idx*2+1]


def sum(l, r):
    l = l + size-1
    r = r + size-1
    sumV = 0
    while l <= r:
        if l % 2 == 1:
            sumV = sumV + tree[l]

        if r % 2 == 0:
            sumV = sumV + tree[r]

        l = (l+1)//2
        r = (r-1)//2
    return sumV


tree = [0]*(1000000*4)
n, m, k = map(int, input().split())
size = 1
while(size < n):
    size = size*2

for i in range(n):
    num = int(input())
    tree[size+i] = num

for i in range(size-1, 0, -1):
    tree[i] = tree[i*2]+tree[i*2+1]

for i in range(m+k):
    a, b, c = map(int, input().split())

    if a == 1:
        update(b, c)

    elif a == 2:
        print(sum(b, c))
        # print()
