#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> stones, int k) {
    int _left = *min_element(stones.begin(), stones.end());
    int _right = *max_element(stones.begin(), stones.end());
    
     while (_left <= _right)
     {
         int _mid = (_left + _right) / 2;
         
         int _cnt = 0;
         bool _can = true;
         
         
         for(int i = 0; i < stones.size(); i++)
         {
             if (stones[i] - _mid <= 0) _cnt++;
             else _cnt = 0;
             
             if(_cnt >= k)
             {
                 _can = false;
                 break;
             }
         }
         
         if(_can)
         {
             _left = _mid + 1;
         }
         else
         {
             _right = _mid - 1;
         }
     }
    
    return _left;
}