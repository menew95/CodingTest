#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

map<string, int> g_course;
vector<int> g_temp(11, 0);

void comb(int depth, int s_index, int v_index, string cur, string& order, vector<int>& course)
{
    if(course.size() > v_index && cur.length() == course[v_index])
    {
        g_course[cur]++;
        
        g_temp[cur.length()] = g_temp[cur.length()] > g_course[cur] ? g_temp[cur.length()] : g_course[cur];
    }
    
    if(course[v_index] < cur.length() + 1)
    {
        v_index++;
    }
    
    if (depth == cur.length())
    {
        return;
    }
    else
    {
        for(int i = s_index; i < order.length(); i++)
        {
            comb(depth, i + 1, v_index, cur + order.substr(i, 1), order, course);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    int _max = *max_element(course.begin(), course.end());
    
    for(int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end());
        comb(_max, 0, 0, "", orders[i], course);
    }
    
    for(auto& _p : g_course)
    {
        if(_p.second > 1 && g_temp[_p.first.length()] == _p.second)
        {
            answer.push_back(_p.first);
        }
    }
    
    return answer;
}