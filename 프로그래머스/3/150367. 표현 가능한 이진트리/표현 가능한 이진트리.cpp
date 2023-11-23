#include <string>
#include <vector>
#include <iostream>

using namespace std;

string make(long long num)
{
    string _s;
    while(num > 0)
    {
        _s = to_string(num % 2) + _s;
        num /= 2;
    }
    
    return _s;
}

bool check(string str, int s, int e) {
    if (e - s == 1 || str.substr(s, e - s).find("1") == string::npos) return true;
    
    int _mid = (e + s) / 2;
 
    if (str[_mid] == '1' && check(str, s, _mid) && check(str, _mid + 1, e)) 
        return true;
    else 
        return false;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        string _s = make(numbers[i]);
        
        int _n_pow = 1;
        
        while(true)
        {
            if(_s.length() <= _n_pow - 1)
            {
                break;
            }
            
            _n_pow *= 2;
        }
        
        _s.insert(_s.begin(), (_n_pow - 1) - _s.length(), '0');
        
        if(check(_s, 0, _s.length()))
            answer.push_back(1);
        else 
            answer.push_back(0);
    }
        
    
    
    return answer;
}