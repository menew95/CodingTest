#include <iostream>
#include <cmath>

using namespace std;

long long solution(int w,int h) {
    long long answer = 0;
    
    for(long long i = 1; i < w; i++)
    {
        double _tmp = h * i / (double)w;
        
        answer += (long long)_tmp;
    }
    
    return answer * 2;
}