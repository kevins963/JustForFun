#pragma once

class ListNode
{
public:
    ListNode(int data)
    {
        _data = data;
        _pNextNode = nullptr;
    }

    ~ListNode(void){};

    int GetData()
    {
        return _data;
    }

    ListNode * GetNextNode()
    {
        return _pNextNode;
    }

    void SetNextNode( ListNode * pNextNode )
    {
        _pNextNode = pNextNode;
    }

private:
    int _data;
    ListNode * _pNextNode;
};

