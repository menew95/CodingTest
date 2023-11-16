#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    long long d2 = (long long)d * (long long)d;
    
    for(int i = 0; i <= d; i += k)
    {
        int b = sqrt(d2 - (long long)i * (long long)i);

         answer += b / k + 1;
    }
    
    return answer;
}