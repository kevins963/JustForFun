#pragma once

#include <vector>

using namespace std;

class GraphNode
{
public:
    GraphNode(int data)
    {
       _data = data;
       _visited = false;
    }

    ~GraphNode()
    {

    }

    int GetData()
    {
        return _data;
    }

    void SetEdges( GraphNode* edge )
    {
        _edges.push_back(edge);
    }

    void ClearEdges()
    {
        _edges.clear();
    }

    vector<GraphNode*>* GetEdges()
    {
        return &_edges;
    }

    void SetVisited( bool isVisited )
    {
        _visited = isVisited;
    }

    bool GetVisited(void)
    {
        return _visited;
    }

private:
    int _data;
    vector<GraphNode*> _edges;
    bool _visited;

};