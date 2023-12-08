#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    
    struct Node
    {
        int _n;
        Node* _l = nullptr;
        Node* _r = nullptr;
    };
    
    vector<Node> _nodes(n);
    stack<Node*> _removes;
    
    Node* _cur = &_nodes[k];
    
    for(int i = 0; i < n; i++)
    {
        _nodes[i]._n = i;
        if(i != 0)
            _nodes[i]._l = &_nodes[i - 1];
        if(i != n - 1)
            _nodes[i]._r = &_nodes[i + 1];
    }
    
    for(int i = 0; i < cmd.size(); i++)
    {
        if(_cur == nullptr)
            return "S";
        if(cmd[i][0] == 'U')
        {
            int _cnt = stoi(cmd[i].substr(2));
            
            for(int i = 0; i < _cnt; i++)
            {
                if(_cur->_l == nullptr)
                    break;
                _cur = _cur->_l;
            }
        }
        else if(cmd[i][0] == 'D')
        {
            int _cnt = stoi(cmd[i].substr(2));
            
            for(int i = 0; i < _cnt; i++)
            {
                if(_cur->_r == nullptr)
                    break;
                _cur = _cur->_r;
            }
        }
        else if(cmd[i][0] == 'C')
        {
            _removes.push(_cur);
            
            if(_cur->_l != nullptr) _cur->_l->_r = _cur->_r; 
            if(_cur->_r != nullptr) _cur->_r->_l = _cur->_l;
            
            if (_cur->_r == nullptr) _cur = _cur->_l;
            else _cur = _cur->_r;
            
        }
        else if(cmd[i][0] == 'Z' && !_removes.empty())
        {
            auto* _node = _removes.top();
            _removes.pop();
            
            if(_node->_r != nullptr) _node->_r->_l = _node;
            if(_node->_l != nullptr) _node->_l->_r = _node;
        }
    }
    
    while(!_removes.empty())
    {
        answer[_removes.top()->_n] = 'X';
        _removes.pop();
    }
    
    return answer;
}