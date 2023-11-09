#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer(ranges.size());
    
    vector<int> _collatz;
    
    _collatz.push_back(k);
    int n = k;
    while(n != 1)
    {
        n = n % 2 == 0 ? n / 2 : n * 3 + 1;
        _collatz.push_back(n);
    }
    
    vector<double> _di(_collatz.size(), 0.0);
    int _n = 0;
    
    for(int i = 0; i < _collatz.size() - 1; i++)
    {
        _n++;
        _di[i + 1] = _di[i] + (_collatz[i] + _collatz[i + 1]) / 2.0;
    }
    
    for(int i = 0; i < ranges.size(); i++)
    {
        int a = ranges[i][0];
        int b = _n + ranges[i][1];
        
        if(a > b)
        {
            answer[i] = -1;
        }
        else
        {
            answer[i] = _di[b] - _di[a] ;
        }
    }
    
    return answer;
}