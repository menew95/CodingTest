#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    Node(int i, int x, int y) : _index(i), _x(x), _y(y) {}
    int _index = 0;
    int _x, _y;
    Node* _parent = nullptr;
    Node* _left = nullptr;
    Node* _right = nullptr;
    
    void insert(Node* node)
    {
        if(node->_x < _x)
        {
            if(_left == nullptr) _left = node;
            else _left->insert(node);
        }
        else if(node->_x > _x)
        {
            if(_right == nullptr) _right = node;
            else _right->insert(node);
        }
    }
    
};

void preorder(Node* node, vector<int>& _v)
{
    _v.push_back(node->_index);
    
    if(node->_left != nullptr) preorder(node->_left, _v);
    if(node->_right != nullptr) preorder(node->_right, _v);
}

void postorder(Node* node, vector<int>& _v)
{
    if(node->_left != nullptr) postorder(node->_left, _v);
    if(node->_right != nullptr) postorder(node->_right, _v);
    
    _v.push_back(node->_index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2);
    
    vector<Node> _nodes;
    
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        _nodes.push_back({i + 1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    
    sort(_nodes.begin(), _nodes.end(), [](auto& node1, auto& node2)
         {
             return node1._y > node2._y;
         });
    
    Node& _root = _nodes[0];
    
    for(int i = 1; i < _nodes.size(); i++)
    {
        _root.insert(&_nodes[i]);
    }
    
    preorder(&_nodes[0], answer[0]);
    postorder(&_nodes[0], answer[1]);
    
    return answer;
}