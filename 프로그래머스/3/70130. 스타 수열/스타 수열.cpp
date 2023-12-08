#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    unordered_map<int, int> _um;
    
    for(auto n : a)
        _um[n]++;
    
    for(auto _p : _um)
    {
        if(_p.second * 2 < answer)
            continue;
        int _tmp = 0;
        
        for(int i = 0; i < a.size() - 1; i++)
        {
            if(a[i] == a[i + 1])
                continue;
            if(a[i] != _p.first && a[i + 1] != _p.first)
                continue;
            
            _tmp += 2;
            i++;
        }
        
        answer = max(answer, _tmp);
    }
    
    return answer;
}