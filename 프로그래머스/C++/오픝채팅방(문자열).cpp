#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char del)
{
    vector<string> result;
    stringstream ss(input);
    string tmp;

    while(getline(ss, tmp, del))
    {
        result.push_back(tmp);
    }
    return result;
}


vector<string> solution(vector<string> record) {
    vector<string> state;
    vector<string> answer;
    vector<string> name;
    map<string, string> user;
    for(int i =0; i< record.size(); i++)
    {
        if(record[i][0]=='E')
        {
            vector<string> tmp; 
            tmp = split(record[i], ' ');
            user[tmp[1]] = tmp[2];
            //cout << tmp[1] << tmp[2] << endl;
            name.insert(name.end(), tmp.begin(), tmp.end());
            state.push_back("님이 들어왔습니다.");
        }

        else if(record[i][0] == 'L')
        {
            vector<string> tmp; 
            tmp = split(record[i], ' ');
            name.insert(name.end(), tmp.begin(), tmp.end());
            name.push_back("asdf");
            state.push_back("님이 나갔습니다.");
        }


        else
        {
            vector<string> tmp = split(record[i], ' ');
            user[tmp[1]] = tmp[2];
        }//*/ 1 4 7

    }

    for(int i = 0; i < state.size(); i++)
        answer.push_back(user[name[1+i*3]] + state[i]);


    return answer;
}