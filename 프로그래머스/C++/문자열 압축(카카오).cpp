#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int answer = 1000;

void calculate(int len, string s)
{
    string tmp;
    string check;
    int cnt = 1;
    for(int i=0;i<len;i++)
    {
        check = check + s[i];
    }
    //cout << check << "\n";

    for(int i=len;i<s.length();i=i+len)
    {
        if(check==s.substr(i,len))
            cnt++;
        else
        {   
            if(cnt>1)
            {
                //tmp.replace(i-(cnt*len),cnt*len, to_string(cnt) + check );
                tmp = tmp + to_string(cnt);
            }
            tmp = tmp + check;
            cnt = 1;
            check = s.substr(i,len);
        }  
    }
    if(cnt>1)
        tmp = tmp + to_string(cnt);
    tmp = tmp + check;
    
    //cout << " : " << tmp << endl;
    answer = min(answer, (int)tmp.length());
}

int solution(string s) {
    if(s.length()==1)
        return 1;
        
    for(int i=1;i<s.length()/2+1; i++)
    {
        calculate(i,s);
    }

    return answer;
}