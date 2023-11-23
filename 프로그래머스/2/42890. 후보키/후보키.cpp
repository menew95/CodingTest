#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool candidate_key(vector<vector<string>>& relation, vector<int>& key)
{
    map<string, int> _map;
    
    for(int i = 0; i < relation.size(); i++)
    {
        string _tmp;
        for(int j = 0; j < key.size(); j++)
            _tmp += relation[i][key[j]];
        
        _map[_tmp]++;
    }
    
    return _map.size() == relation.size();
}

void check_minimality(vector<int>& key, vector<vector<int>>& candidate_keys)
{
    vector<int> _list;
    
    for(int i = 0; i < candidate_keys.size(); i++)
    {
        int _cnt = 0;
        
        if(key.size() > candidate_keys[i].size())
            continue;
        
        for(auto num :  candidate_keys[i])
        {
            if(num == key[_cnt])
            {
                _cnt++;
            }
        }
        
        if(_cnt == key.size())
        {
            _list.push_back(i);
        }
    }
    
    if(_list.size() == 0)
    {
        candidate_keys.push_back(key);
    }
    else
    {
        for(int i = _list.size() - 1; i >= 0; i--)
        {
            if(i == 0)
                candidate_keys[_list[i]] = key;
            else
                candidate_keys.erase(candidate_keys.begin() + _list[i]);
        }
    }
}

void comb(int n, vector<vector<string>>& relation, vector<int>& key, vector<vector<int>>& candidate_keys)
{
    if(n < relation[0].size())
    {
        for(int i = n; i < relation[0].size(); i++)
        {
            key.push_back(i);
            
            if(candidate_key(relation, key))
            {
                check_minimality(key, candidate_keys);
                
                key.pop_back();
                continue;
            }
            
            comb(i + 1, relation, key, candidate_keys);
            
            key.pop_back();
        }
    }
}

int solution(vector<vector<string>> relation) {

    vector<vector<int>> _candidate_keys;
    vector<int> _key;
    
    comb(0, relation, _key, _candidate_keys);
    
    return _candidate_keys.size();
}