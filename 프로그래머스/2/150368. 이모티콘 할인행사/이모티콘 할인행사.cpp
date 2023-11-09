#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void Comb(int depth, vector<vector<int>>& event, vector<int>& discount)
{
    if(depth == 0)
    {
        event.push_back(discount);
        
        return;
    }
    
    for(int i = 40; i >= 0; i -= 10)
    {
        discount.push_back(i);
        
        Comb(depth - 1, event, discount);
        
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    
    vector<vector<int>> _events;
    vector<int> _discount;
    
    for(int i = 0; i < emoticons.size(); i++)
        emoticons[i] /= 100;
    
    Comb(emoticons.size(), _events, _discount);
    
    for(int i = 0; i < _events.size(); i++)
    {
        int _cnt = 0, _money = 0;
        
        for(int j = 0; j < users.size(); j++)
        {
            int _sum = 0;
            
            for(int k = 0; k < _events[i].size(); k++)
            {
                if(_events[i][k] >= users[j][0])
                {
                    _sum += emoticons[k] * (100 - _events[i][k]);
                }
            }
            
            if(_sum >= users[j][1])
            {
                _cnt++;
            }
            else
            {
                _money += _sum;
            }
        }
        
        if(answer[0] < _cnt)
        {
            answer[0] = _cnt;
            answer[1] = _money;
        }
        else if(answer[0] == _cnt && answer[1] < _money)
        {
            answer[1] = _money;
        }
    }
    
    
    return answer;
}