#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// int visited[10001];
// vector<string> graph[10001];
int finish = 0;
bool check = false;

void dfs(string start, vector<bool>& visit, vector<string> &answer, vector<vector<string>>& tickets)
{
    answer.push_back(start);
    cout << start << finish << "\n";
    if(finish == tickets.size())
        check = true;

    for(int i=0; i<visit.size(); i++)
    {
        if(visit[i]==0 && tickets[i][0] == start)
        {
            visit[i] = 1;
            finish++;
            dfs(tickets[i][1], visit, answer, tickets);

            if(check == false)
            {
                answer.pop_back();
                visit[i] = false;
            }
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) 
{
   
    vector<bool> visited(tickets.size(), 0);
    vector<string> answer;
    vector<string> tmp;
    sort(tickets.begin(), tickets.end());

    dfs("ICN", visited, answer, tickets);

    return answer;
}