#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct signal_ms
{
    int _s_ms = 0;
    int _e_ms = 0;
    int _ms = 0;
    
};

signal_ms convert(string& s)
{
    signal_ms _ret_ms;
    
    _ret_ms._e_ms = stoi(s.substr(11, 2)) * 3600000
        + stoi(s.substr(14, 2)) * 60000
        + stoi(s.substr(17, 2)) * 1000
        + stoi(s.substr(20, 3));
    
    _ret_ms._ms = (int)(stof(s.substr(24)) * 1000);
    
    if(_ret_ms._e_ms < _ret_ms._ms)
        _ret_ms._s_ms = 0;
    else
        _ret_ms._s_ms = _ret_ms._e_ms - _ret_ms._ms  + 1;
    
    cout << _ret_ms._s_ms << ' ' << _ret_ms._e_ms << endl;
    
    return _ret_ms; 
}

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<signal_ms> _signals(lines.size());
    
    for(int i = 0; i < lines.size(); i++)
    {
        _signals[i] = convert(lines[i]);
    }
    
    sort(_signals.begin(), _signals.end(), [](auto& a, auto& b)
         {
             return a._e_ms < b._e_ms;
         });
    
    for(int i = 0; i < _signals.size(); i++)
    {
        int _s_ms_s = _signals[i]._s_ms;
        int _e_ms_s = _s_ms_s + 999;
        
        int _s_ms_e = _signals[i]._e_ms;
        int _e_ms_e = _s_ms_e + 999;
        
        int _cnt_s = 0, _cnt_e = 0;
        
        for(int j = i; j < _signals.size(); j++)
        {
            if(_signals[j]._s_ms >= _s_ms_s && _signals[j]._s_ms <= _e_ms_s)
                _cnt_s++;
            else if(_signals[j]._e_ms >= _s_ms_s && _signals[j]._e_ms <= _e_ms_s)
                _cnt_s++;
            else if(_signals[j]._s_ms <= _s_ms_s && _signals[j]._e_ms >= _e_ms_s)
                _cnt_s++;
            
            if(_signals[j]._s_ms >= _s_ms_e && _signals[j]._s_ms <= _e_ms_e)
                _cnt_e++;
            else if(_signals[j]._e_ms <= _e_ms_e && _signals[j]._e_ms >= _s_ms_e)
                _cnt_e++;
            else if(_signals[j]._s_ms <= _s_ms_e && _signals[j]._e_ms >= _e_ms_e)
                _cnt_e++;
        }
        
        answer = answer > _cnt_s ? answer : _cnt_s;
        answer = answer > _cnt_e ? answer : _cnt_e;
    }
    
    return answer;
}