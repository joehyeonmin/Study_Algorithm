#include <bits/stdc++.h>

using namespace std;

int N, M, K, B, T;
long long IDT[1000000 * 4];

void update(int p, long long v)
{
    p = p + (B - 1);

    IDT[p] = v;
    while (p != 1)
    {
        p = p / 2;
        IDT[p] = IDT[p * 2] + IDT[(p * 2 + 1)];
    }
}

long long lgSum(int l, int r)
{
    l += (B - 1); r += (B - 1);
    long long sumV = 0;
    while (l <= r)
    {
        if (l % 2 == 1)
            sumV += IDT[l];
        if (r % 2 == 0)
            sumV += IDT[r];

        l = (l + 1) / 2;
        r = (r - 1) / 2;
    }
    return sumV;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;

    for (B = 1; B < N; B = B * 2);

    for (int i = B; i < N + B; i++)
    {
        int num;
        cin >> num;
        IDT[i] = num;
    }

    for (int i = B - 1; i > 0; i--)
    {
        IDT[i] = IDT[i * 2] + IDT[i * 2 + 1];
    }

    T = M + K;

    int a, b;
    long long c;
    for (int i = 0; i < M + K; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
            update(b, c);
        else
            cout << lgSum(b, c) << "\n";
    }

    return 0;
}