#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0)
    {
        int _tmp = n % 3;
        
        if (_tmp == 0)
        {
            answer = "4" + answer;
            n = n / 3 - 1;
        }
        else 
        {
            answer = to_string(_tmp) + answer;
            n = n / 3;
        }
    }
    
    return answer;
}