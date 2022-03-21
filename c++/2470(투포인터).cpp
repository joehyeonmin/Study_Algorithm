#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> water;

int INF = 2000000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    //water.push_back(0);

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        water.push_back(num);
    }
    int start = 0;
    int end = N - 1;

    int sum, sum2, sum3;
    int min = INF;
    sort(water.begin(), water.end());

    //-10 -8 -6 -1 1 5 7 9
    //-99 -2 -1 4 98
    //1 2 3 4 5 6
    //-100 -99 1 2 3 4 5 6 99
    //-99 -2 -1 1 98 100 101
    //-101 -100 -98 -1 1 2 99

    //cout << start << end << endl;
    int as, ae;

    while (start < end)
    {
        sum = water[start] + water[end];
        if (sum < 0)
            sum = sum * -1;

        sum2 = water[start + 1] + water[end];
        if (sum2 < 0)
            sum2 = sum2 * -1;
        sum3 = water[start] + water[end - 1];
        if (sum3 < 0)
            sum3 = sum3 * -1;

        if (sum == 0)
        {
            cout << water[start] << " " << water[end];
            return 0;
        }
        else if (sum2 > sum3)
        {
            if (sum < min)
            {
                min = sum;
                as = start;
                ae = end;
            }
            end--;
        }
        else
        {
            if (sum < min)
            {
                min = sum;
                as = start;
                ae = end;
            }
            start++;
        }
    }

    if (N == 2)
    {
        as = 0;
        ae = 1;

    }

    cout << water[as] << " " << water[ae];
    return 0;
}