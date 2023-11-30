#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long conv_sec(string time)
{
    return (long long)stoi(time.substr(0, 2)) * 3600 + (long long)stoi(time.substr(3, 2)) * 60 + (long long)stoi(time.substr(6));
}

vector<long long> conv_log(string& log)
{
    vector<long long> _ret(2);
    
    _ret[0] = conv_sec(log.substr(0, 8));
    _ret[1] = conv_sec(log.substr(9));
    
    return _ret;
}

string conv_time(long long time)
{
    string _ret;
    
    if(time / 3600 < 10)
        _ret += "0";
    
    _ret += to_string(time / 3600) + ":";
    time %= 3600;
    
    if(time / 60 < 10)
        _ret += "0";
    
    _ret += to_string(time / 60) + ":";
    time %= 60;
    
    if(time < 10)
        _ret += "0";
    
    _ret += to_string(time);
    
    return _ret;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    long long _play_time = conv_sec(play_time);
    long long _adv_time = conv_sec(adv_time);
    
    vector<vector<long long>> _logs;
    
    vector<int> _acc_time(3600 * 100, 0);
    for(int i = 0; i < logs.size(); i++)
    {
        auto _log = conv_log(logs[i]);
        
        for(int j = _log[0] + 1; j <= _log[1]; j++) _acc_time[j]++;
    }
    
    long long _cur_play = 0, _max_play = 0;
    int _time = 1;
    
    for (int i = 1; i <= _adv_time; i++)
        _cur_play += _acc_time[i];
    
    _max_play = _cur_play;
    
    for (int i = 2; i <= (_play_time - _adv_time + 1); i++)
    {
        _cur_play += (long long)(_acc_time[i + _adv_time - 1] - _acc_time[i - 1]);
        if (_cur_play > _max_play)
        {
            _max_play = _cur_play;
            _time = i;
        }
    }
    
    answer = conv_time(_time - 1);
    
    return answer;
}