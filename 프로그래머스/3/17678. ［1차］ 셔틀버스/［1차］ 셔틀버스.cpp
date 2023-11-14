#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b)
{
    int h_a, h_b, m_a, m_b;
    
    h_a = stoi(a.substr(0, 2));
    h_b = stoi(b.substr(0, 2));
    
    if(h_a != h_b)
        return h_a < h_b;
    
    m_a = stoi(a.substr(3, 2));
    m_b = stoi(b.substr(3, 2));
    
    return m_a <= m_b;
    
}

int toint(string& s)
{
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    
    return h * 60 + m;
}

string tostring(int i)
{
    string _s;
    
    if(i / 60 < 10)
    {
        _s += "0";
    }
    _s += to_string(i / 60);
    _s += ":";
    
    if(i % 60 < 10)
    {
        _s += "0";
    }
        
    _s += to_string(i % 60);
    
    return _s;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    vector<int> _timetable;
    
    for(int i = 0; i < timetable.size(); i++)
        _timetable.push_back(toint(timetable[i]));
    
    sort(_timetable.begin(), _timetable.end());
    
    vector<int> _bus;
    int _time = 540;
    _bus.push_back(_time);
    for(int i = 1; i < n; i++)
    {
        _time += t;
        _bus.push_back(_time);
    }
    
    int _cur = 0;
    
    for(int i = 0; i < _bus.size(); i++)
    {
        for(int _cnt = 0; _cnt < m && _cur < _timetable.size(); _cnt++)
        {
            answer = tostring(_bus[i]);
            
            if(_timetable[_cur] <= _bus[i])
            {
                if(i == _bus.size() - 1 && _cnt == m - 1)
                {
                    return tostring(_timetable[_cur] - 1);
                }
                
                _cur++;
            }
            else
            {
                break;
            }
        }
    }
    
    return answer;
}