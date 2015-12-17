#pragma once

class TreeNode
{
public:
    TreeNode(void);
    TreeNode(int data);

    ~TreeNode(void);

    void SetNodeLeft(TreeNode * leftNode);
    void SetNodeRight(TreeNode * rightNode);
    TreeNode* GetNodeLeft(void);
    TreeNode* GetNodeRight(void);
    int GetData(void);

private:
    int _data;
    TreeNode * _leftNode;
    TreeNode * _rightNode;
};

TreeNode::TreeNode()
{
    _data = 0;
    _leftNode = nullptr;
    _rightNode = nullptr;
}

TreeNode::TreeNode(int data)
{
    _data = data;
    _leftNode = nullptr;
    _rightNode = nullptr;
}

TreeNode::~TreeNode()
{
    
}

void TreeNode::SetNodeLeft(TreeNode * leftNode)
{
    _leftNode = leftNode;
}
void TreeNode::SetNodeRight(TreeNode * rightNode)
{
    _rightNode = rightNode;
}
TreeNode* TreeNode::GetNodeLeft(void)
{
    return _leftNode;
}

TreeNode* TreeNode::GetNodeRight(void)
{
    return _rightNode;
}

int TreeNode::GetData(void)
{
    return _data;
}