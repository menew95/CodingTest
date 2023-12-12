#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> _v = { -1 };
    for(int _ingre : ingredient)
    {
        if(_v.back() == 1 && _ingre == 2) _v.back() = 12;
        else if(_v.back() == 12 && _ingre == 3) _v.back() = 123;
        else if(_v.back() == 123 && _ingre == 1) answer++, _v.pop_back();
        else _v.push_back(_ingre);
    }    

    return answer;
}