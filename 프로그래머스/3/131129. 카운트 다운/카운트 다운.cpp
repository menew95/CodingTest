#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    
    vector<pair<int, int>> cnts(target+1, {0,0});
    
    auto check = [&](int nextScore, int cur)
    {
        if (nextScore < 0)
            return false;
        if (cnts[nextScore].first 
            && cnts[nextScore].first <= cnts[cur].first)
            return false;
        if (cnts[nextScore].first == cnts[cur].first + 1
            && cnts[nextScore].second > cnts[cur].second)
            return false;
    
        return true;
    };
    
    for (int cur=target; cur > 0; cur--)
    {
        int nextScore;
        
        for (int score = 1; score <= 20; score++)
        {
            for (int i = 1; i <= 3; i++)
            {
                nextScore = cur - score*i;
                if (!check(nextScore, cur)) continue ;
                
                cnts[nextScore].first = cnts[cur].first + 1;
                
                if (i == 1) cnts[nextScore].second = cnts[cur].second + 1;
                else cnts[nextScore].second = cnts[cur].second;
            }
        }
        
        nextScore = cur - 50;
        
        if (!check(nextScore, cur)) continue;
        
        cnts[nextScore].first = cnts[cur].first + 1;
        cnts[nextScore].second = cnts[cur].second + 1;
    }
    
    answer = { cnts[0].first, cnts[0].second };
    
    return answer;
}