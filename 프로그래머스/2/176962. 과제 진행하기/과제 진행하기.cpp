#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

struct subject
{
    string _subject;
    int _m_s, _m_e;
    int _time = 0;
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    vector<subject> _subjects;
    
    for(auto& _v : plans)
    {
        subject _subject;
        _subject._subject = _v[0];
        
        _subject._m_s = stoi(_v[1].substr(0, 2)) * 60 + stoi(_v[1].substr(3));
        
        _subject._time = stoi(_v[2]);
        
        _subject._m_e = _subject._m_s + _subject._time;
        
        _subjects.push_back(_subject);
    }
    
    sort(_subjects.begin(), _subjects.end(), [](auto& a, auto& b)
         {
             return a._m_s < b._m_s;
         });
    
    stack<subject> _remain;
    int _idx = 0;
    subject _cur = _subjects[_idx];
    
    while(answer.size() < plans.size())
    {
        if(_idx + 1 == plans.size())
        {
            answer.push_back(_cur._subject);
            
            while(!_remain.empty())
            {
                answer.push_back(_remain.top()._subject);
                _remain.pop();
            }
        }
        else if(_cur._m_e > _subjects[_idx + 1]._m_s)
        {
            // 과제가 끝나기전에 새로운 과제
            _cur._time = _cur._m_e - _subjects[_idx + 1]._m_s;
            
            _remain.push(_cur);
            _idx++;
            _cur = _subjects[_idx];
            
        }
        else
        {
            answer.push_back(_cur._subject);
            
            // 과제가 끝남
            if(!_remain.empty())
            {
                // 남은 과제가 잇으면 이전 과제로
                _remain.top()._m_s = _cur._m_e;
                _remain.top()._m_e = _remain.top()._m_s + _remain.top()._time;
                
                _cur = _remain.top();
                _remain.pop();
            }
            else if(_idx < _subjects.size())
            {
                // 남은 과제가 없으면 다음 과제로
                _idx++;
                _cur = _subjects[_idx];
            }
        }
    }
    
    return answer;
}