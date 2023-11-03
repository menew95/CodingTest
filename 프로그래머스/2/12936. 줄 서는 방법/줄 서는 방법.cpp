#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> _v(n);
    
    long long _pre = 1;
    
    for(int i=0; i<n;i++)
    {
        _v[i] = i + 1;
        _pre *= i + 1;
    }
    
    if(k == 1)
        return _v;

    k -= 1;
    
    long long _mod, _div;

    while(_v.size() != 1)
    {
        _pre /= n;
        _mod = k % _pre;
        _div = k / _pre;
        answer.push_back(_v[_div]);
        _v.erase(_v.begin() + _div);
        k = _mod;
        n--;
    }
    
    answer.push_back(_v[0]);
    
    return answer;
}