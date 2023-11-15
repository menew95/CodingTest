#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    
    string _s = "ACFJMNRT";
    
    auto condition = [](string& s, string& condition)
    {
        int _pos1 = s.find(condition[0]);
        int _pos2 = s.find(condition[2]);
        
        int _diff = condition[4] - '0' + 1;
        
        switch(condition[3])
        {
            case '=':
            {
                return abs(_pos1 - _pos2) == _diff; 
            }
            case '<':
            {
                return abs(_pos1 - _pos2) < _diff;
            }
            case '>':
            {
                return abs(_pos1 - _pos2) > _diff;
            }
        }
    };
    
    do
    {
        bool _hr = true;
        
        for(int i = 0; i < data.size(); i++)
        {
            if(!condition(_s, data[i]))
            {
                _hr = false;
                break;
            }
        }
        
        if(_hr)
            answer++;
    }
    while(next_permutation(_s.begin(), _s.end()));
    
    
    return answer;
}