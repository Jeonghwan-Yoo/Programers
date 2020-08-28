#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y, idx;
    Node *left;
    Node *right;
};

void PrePostorder(Node *parent, vector<int> &pre, vector<int> &post)
{
    pre.emplace_back(parent->idx);
    if (parent->left != nullptr)
        PrePostorder(parent->left, pre, post);
    if (parent->right != nullptr)
        PrePostorder(parent->right, pre, post);
    post.emplace_back(parent->idx);
}

void MakeTree(Node *parent, Node *child)
{
    if (parent->x > child->x)
    {
        if (parent->left == nullptr)
            parent->left = child;
        else
            MakeTree(parent->left, child);
    }
    else
    {
        if (parent->right == nullptr)
            parent->right = child;
        else
            MakeTree(parent->right, child);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    int n = (int)nodeinfo.size();
    vector<Node> tree(n);
    for (int i = 0; i < n; ++i)
    {
        tree[i].x = nodeinfo[i][0];
        tree[i].y = nodeinfo[i][1];
        tree[i].idx = i + 1;
    }
    
    sort(tree.begin(), tree.end(), [&tree](Node const &a, Node const &b)
    {
        if (a.y == b.y)
            return a.x < b.x;
        return a.y > b.y;
    });
    
    Node *root = &tree[0];
    for (int i = 1; i < n; ++i)
        MakeTree(root, &tree[i]);
    
    vector<int> pre, post;
    PrePostorder(root, pre, post);
    answer.emplace_back(pre);
    answer.emplace_back(post);
    
    return answer;
}