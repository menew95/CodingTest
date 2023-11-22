#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {

    int answer = 0;
    
    vector<vector<int>> _diff(beginning.size(), vector<int>(beginning[0].size()));
    
    for(int i = 0; i < beginning.size(); i++)
        for(int j = 0; j < beginning[0].size(); j++)
            _diff[i][j] = beginning[i][j] ^ target[i][j];
    
    int _cnt = 0, _sum = 0;
    for(int i = 0; i < beginning[0].size(); i++) 
        _sum += _diff[0][i];
    
    for(int i = 1; i < beginning.size(); i++) 
    {
        bool o_flag=true, r_flag=true;
        
        for(int j = 0; j < beginning[0].size(); j++) 
        {
            if((_diff[i][j] ^ 0) != _diff[0][j]) o_flag = false;
            if((_diff[i][j] ^ 1) != _diff[0][j]) r_flag = false;
        }
        if (!o_flag) 
        {
            if(!r_flag) return -1;
            else _cnt++;
        }
    }
    
    answer = min(_cnt + _sum, (int)beginning.size() - _cnt + (int)beginning[0].size() - _sum);
    
    return answer;
}