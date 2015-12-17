#pragma once

#include <vector>
#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;
/*
preorder: root, left, right
inorder: left, root, right
postorder: left, right, root
*/
class Tree
{
public:
    Tree();
    ~Tree();

    void Insert( int data );
    void InsertBalanced( int data );
    void PrintTree( void );
    void RotateNode( TreeNode * parent, TreeNode * node );
    void PrintInOrder( void );
    
private:
    void PrintInOrder( TreeNode* node );
    TreeNode * _rootNode;
};

Tree::Tree()
{
    _rootNode = nullptr;
}

Tree::~Tree()
{
}

/*
    check left node
    Balancing tree -
             5
        {4- -} {- -}
        n,ln=c,ln, c,ln = 0, n,rn = c
*/
void Tree::Insert( int data )
{
    if(_rootNode == nullptr)
    {
        _rootNode = new TreeNode(data);
    }
    else
    {
        bool found = false;
        TreeNode * currentNode = _rootNode;
        while(!found)
        {
            if(currentNode->GetData() >= data)
            {
                if(currentNode->GetNodeLeft() == nullptr)
                {
                    currentNode->SetNodeLeft(new TreeNode(data));
                    found = true;
                }
                else
                {
                    currentNode = currentNode->GetNodeLeft();
                }
            }
            else
            {
                if(currentNode->GetNodeRight() == nullptr)
                {
                    currentNode->SetNodeRight(new TreeNode(data));
                    found = true;
                }
                else
                {
                    currentNode = currentNode->GetNodeRight();
                }
            }
        }
    }
}

/*
[3}
      5
    4   -
  3
  5L->3
  3L->1 3R->-

  cn
  if data < cn
   if ln has node and rn = null
      if(data < ln)
        ln->ln = data
        ln->rn = cn
      else 
        data->ln = ln
        data->rn = cn
*/
void Tree::InsertBalanced( int data )
{
    TreeNode * prevNode = nullptr;

    if(_rootNode == nullptr)
    {
        _rootNode = new TreeNode(data);
    }
    else
    {
        bool found = false;
        TreeNode * currentNode = _rootNode;
        while(!found)
        {
            if(currentNode->GetData() >= data)
            { 
                if(currentNode->GetNodeLeft() == nullptr)
                {
                    currentNode->SetNodeLeft(new TreeNode(data));
                    found = true;
                }
                else if(currentNode->GetNodeRight() == nullptr)
                {
                    /* unbalanced */

                    if( currentNode->GetNodeLeft()->GetData() > data )
                    {
                        
                    }
                    //currentNode->SetNodeLeft(new TreeNode(data));
                    found = true;
                }
                else
                {
                    prevNode = currentNode;
                    currentNode = currentNode->GetNodeLeft();
                }
            }
            else
            {
                if(currentNode->GetNodeRight() == nullptr)
                {
                    currentNode->SetNodeRight(new TreeNode(data));
                    found = true;
                }
                else
                {
                    prevNode = currentNode;
                    currentNode = currentNode->GetNodeRight();
                }
            }
        }
    }
}

void Tree::RotateNode( TreeNode * parent, TreeNode * node )
{
    if( parent->GetData() < node->GetData() )
    {
        node->SetNodeLeft(parent);
        parent->SetNodeRight(nullptr);
    }
    else
    {
        node->SetNodeRight(parent);
        parent->SetNodeLeft(nullptr);
    }
}

void Tree::PrintTree()
{

    cout << "Tree Breadth:" << endl;

    queue<TreeNode*> nodeList;

    nodeList.push(_rootNode);
    
    int currentSize = 0;
    

    while( nodeList.size() > 0)
    {

        currentSize = nodeList.size();

        cout << "{";
        int i = 0;
        while( i < currentSize )
        {
            TreeNode * node = nodeList.front();
            
            cout << node->GetData() << ","; 
            ++i;
        
            if(node->GetNodeLeft() != nullptr)
            {
                nodeList.push( node->GetNodeLeft());
            }
            
            if(node->GetNodeRight() != nullptr)
            {
                nodeList.push( node->GetNodeRight());
            }

            nodeList.pop();
        }
        cout << "} ";
    }

    cout << endl;

}

void Tree::PrintInOrder( void )
{
    cout << "[";
    PrintInOrder( _rootNode );
    cout << "]" << endl;
}


void Tree::PrintInOrder( TreeNode* node )
{
    
    if( node->GetNodeLeft() )
    {
        PrintInOrder( node->GetNodeLeft() );
    }

    cout << node->GetData() << ", ";

    if( node->GetNodeRight() )
    {
        PrintInOrder( node->GetNodeRight() );
    }
}
