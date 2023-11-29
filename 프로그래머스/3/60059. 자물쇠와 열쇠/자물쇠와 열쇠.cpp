#include <string>
#include <vector>
#include <iostream>


using namespace std;

struct Key
{
    vector<vector<int>> _key;
    
    void rotate()
    {
        vector<vector<int>> _tmp = _key;
        
        for(int i = 0; i < _key.size(); i++)
            for(int j = 0; j < _key[0].size(); j++)
            {
                _key[i][j] = _tmp[_key.size() - j - 1][i];
            }
    }
};

bool Open(vector<vector<int>>& key, vector<vector<int>>& lock, int di, int dj, int cnt)
{
    for(int i = 0; i < key.size(); i++)
    {
        if(i + di < 0 || i + di >= lock.size())
            continue;
        
        for(int j = 0; j < key.size(); j++)
        {
            if(j + dj < 0 || j + dj >= lock.size())
                continue;
            
            if(key[i][j] == lock[i + di][j + dj])
                return false;
            else if(key[i][j] == 1 && lock[i + di][j + dj] == 0)
                cnt--;
        }
    }
    
    
    return (cnt == 0);
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    
    Key _key;
    _key._key = key;
    
    int _cnt = 0;
    
    for(int i = 0; i < lock.size(); i++)
        for(int j = 0; j < lock.size(); j++)
            if(!lock[i][j])
                _cnt++;
    
    if(_cnt == 0)
        return true;
    
    for(int k = 0; k < 4; k++)
    {
        for(int i = 1 - (int)key.size(); i < (int)lock.size(); i++)
        {
            for(int j = 1 - (int)key.size(); j < (int)lock.size(); j++)
            {    
                if(Open(_key._key, lock, i, j, _cnt))
                {
                    return true;
                }
            }
        }
        
        _key.rotate();
    }
    
    return false;
}