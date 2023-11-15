#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    
    int answer = s.length();
    
    for(int i = 1; i <= s.length() / 2; i++)
    {
        string _tmp;
        
        for(int j = 0; j < s.length(); j += i)
        {
            int _cnt = 0;
            string _zip = s.substr(j, i);
            for(int k = j + i; k < s.length(); k += i)
            {
                string _target = s.substr(k, i);
                
                if(_zip == _target)
                {
                    _cnt++;
                }
                else break;
            }
            
            if(_cnt > 0)
            {
                _tmp += to_string(_cnt + 1);
                j += i * _cnt;
            }
            
            _tmp += _zip;
        }
        
        answer = answer < _tmp.length() ? answer : _tmp.length();
    }
    
    return answer;
}