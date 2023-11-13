#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> g_root;
vector<bool> g_visit;

int find(int x, int idx, int cnt)
{
    g_visit[idx] = true;
    
    if(g_root[idx] == x)
        return cnt;
    else
        return find(x, g_root[idx], cnt + 1);
}

int solution(vector<int> cards) {
    int answer = 0;
    
    g_visit.resize(cards.size() + 1, false);
    g_root.resize(cards.size() + 1);
    
    for(int i = 1; i <= cards.size(); i++)
        g_root[i] = cards[i - 1];
    vector<int> _group;
    int _sum = 0, _max1 = 0, _max2 = 0;
    for(int i = 1; i <= cards.size(); i++)
    {
        if(g_visit[i])
            continue;
        
        _group.push_back(find(i, i, 1));
    }
    
    for(int i = 0; i < _group.size(); i++)
    {
        if(_max1 < _group[i])
        {
            _max2 = _max1;
            _max1 = _group[i];
        }
        else if(_max2 < _group[i])
            _max2 = _group[i];
    }
    
    return _max1 * _max2;
}