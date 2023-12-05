#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, pair<bool, vector<int>>> _map;

void conv_info(string& s)
{
    stringstream _ss(s);
    
    vector<vector<string>> _info(4, vector<string>(2, "-"));
    int _score;
    _ss >> _info[0][0] >>_info[1][0] >> _info[2][0] >> _info[3][0] >> _score;
    
    for(int i = 0; i < 2; i++)
    {
        string _s1 = _info[0][i];
        
        for(int j = 0; j < 2; j++)
        {
            string _s2 = _s1 + _info[1][j];
            
            for(int k = 0; k < 2; k++)
            {
                string _s3 = _s2 + _info[2][k];
                
                for(int l = 0; l < 2; l++)
                {
                    string _s4 = _s3 + _info[3][l];
                    
                    _map[_s4].second.push_back(_score);
                }
            }
        }
    }
}

int find_query(string& s)
{
    int _ret = 0;
    stringstream _ss(s);
    
    vector<string> _info(4);
    int _score;
    
    _ss >> _info[0] 
        >> _info[1] >> _info[1]
        >> _info[2] >> _info[2] 
        >> _info[3] >> _info[3] >> _score;
    
    string _key = _info[0] + _info[1] + _info[2] + _info[3];
    
    if(!_map[_key].first)
    {
        sort(_map[_key].second.begin(), _map[_key].second.end());
        _map[_key].first = true;
    }
    
    auto _it = lower_bound(_map[_key].second.begin(), _map[_key].second.end(), _score);

    return _map[_key].second.size() - (_it - _map[_key].second.begin());
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for(int i = 0; i < info.size(); i++)
        conv_info(info[i]);
    
    for(auto _s : query)
        answer.push_back(find_query(_s));
    
    return answer;
}