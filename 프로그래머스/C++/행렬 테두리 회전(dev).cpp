#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int graph[101][101];

int changeGraph(int x1, int y1, int x2, int y2)
{
    int tmp[396];
    for (int j = 0; j < 395; ++j) {
        tmp[j] = 10001;
    }

    int sum = 0;
    for (int i = 0;i < y2 - y1 + 1;i++)
    {
        tmp[i] = graph[x1][y1 + i];
    }
    sum = sum + y2 - y1 + 1;
    for (int i = 0;i < x2 - x1;i++)
    {
        tmp[sum + i] = graph[x1 + i + 1][y2];
    }
    sum = sum + x2 - x1;
    for (int i = 0;i < y2 - y1;i++)
    {
        tmp[sum + i] = graph[x2][y2 - 1 - i];
    }
    sum = sum + y2 - y1;
    //cout << "sum : " << sum << "\n";
    for (int i = 0;i < x2 - x1 - 1;i++)
    {
        tmp[sum + i] = graph[x2 - i - 1][y1];
    }

    /*for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }*/
    //////////////////////////////////////
    int min = 10001;

    /*for(int i=0;i<10;i++)
    {
        cout << tmp[i] << "\n";
    }*/
    //  8 9 10 16 22 28 27 26 20 14

    sum = 0;

    //   1 1 2 2
    for (int i = 0;i < y2 - y1;i++)
    {
        //cout << tmp[i];
        graph[x1][y1 + i + 1] = tmp[i];
    }
    //cout << "\n";

    sum = sum + y2 - y1;
    for (int i = 0;i < x2 - x1;i++)
    {
        //cout << tmp[sum + i];
        graph[x1 + i + 1][y2] = tmp[sum + i];
    }
    //cout << "\n";

    sum = sum + x2 - x1;
    for (int i = 0;i < y2 - y1;i++)
    {
        //cout << x2 << y2-1-i << tmp[sum + i];
        graph[x2][y2 - 1 - i] = tmp[sum + i];
    }
    //cout << "\n";

    sum = sum + y2 - y1;
    for (int i = 0;i < x2 - x1;i++)
    {
        //cout << x2-i << y1 << tmp[sum + i];
        graph[x2 - i - 1][y1] = tmp[sum + i];
    }

    //cout << "\n";

    for (int j = 0; j < 395; ++j) {
        if (tmp[j] < min) {
            min = tmp[j];
        }
    }

    /*for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }*/

    //cout << "min : " << min << "\n";
    return min;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int tmp = 0;
    for (int i = 1;i < rows + 1;i++)
    {
        for (int j = 1;j < columns + 1;j++)
        {
            tmp = tmp + 1;
            graph[i][j] = tmp;
        }
    }

    for (int i = 0;i < queries.size(); i++)
    {
        int start_x = queries[i][0];
        int start_y = queries[i][1];
        int end_x = queries[i][2];
        int end_y = queries[i][3];
        //cout << start_x << start_y << end_x << end_y;

        int result = changeGraph(start_x, start_y, end_x, end_y);
        answer.push_back(result);
    }

    return answer;
}