#pragma once

#include "GraphNode.h"

#include <iostream>
#include <vector>

using namespace std;

class Graph
{
 
public:

    void AddVertex( int data )
    {
        _vertices.push_back( GraphNode(data) );
    }

    void AddEdge(int fromIndex, int toIndex)
    {
        GraphNode &vertexFrom = _vertices.at(fromIndex);
        GraphNode &vertexTo = _vertices.at(toIndex);

        vertexFrom.SetEdges(&vertexTo);
    }

    void Print()
    {
        for(vector<GraphNode>::iterator itr = _vertices.begin(); itr != _vertices.end(); ++itr)
        {
            GraphNode * currentNode = itr._Ptr;

            cout << "V=" << currentNode->GetData() << " : E=";

            for(vector<GraphNode*>::iterator itr = currentNode->GetEdges()->begin(); itr != currentNode->GetEdges()->end(); ++itr)
            {
                GraphNode * currentNode = *itr;

                cout << currentNode->GetData() <<", ";
            }

            cout << "}" << endl;
        }
    }

    /*
    Add root node to back of list
    Get next node at front
    Add all edges of node back of list
    [Searches by each level first]
    */
    GraphNode* BreadthSearch(int dataSearch)
    {
        ClearAllVisited();
        cout << "Searching |" << dataSearch << "| ";
        vector<GraphNode*> nodeList;

        GraphNode * currentNode = &_vertices.at(0);

        currentNode->SetVisited(true);
        nodeList.push_back(currentNode);

        int i = 0;

        while(i < nodeList.size())
        {
            currentNode = nodeList.at(i);
            cout << "{" << currentNode->GetData() <<"}, ";

            for(vector<GraphNode*>::iterator itr = currentNode->GetEdges()->begin(); itr != currentNode->GetEdges()->end(); ++itr)
            {
                GraphNode * edgeNode = *itr;

                if(dataSearch == edgeNode->GetData())
                {
                    cout << "{Found}" << endl;
                    return edgeNode;
                }
                else if(edgeNode->GetVisited() == false)
                {
                    edgeNode->SetVisited(true);
                    nodeList.push_back(edgeNode);
                    cout << "[" << edgeNode->GetData() <<"], ";
                }
            }
            ++i;
        }

		return nullptr;
    }

    /*
    Add root to list
    Pop Next node from front of list
    Add Edges to front of list

    Get
    */
    GraphNode* DepthSearch(int dataSearch)
    {
        ClearAllVisited();
        cout << "Searching |" << dataSearch << "| ";
        vector<GraphNode*> nodeList;

        GraphNode * currentNode = &_vertices.at(0);

        currentNode->SetVisited(true);
        nodeList.push_back(currentNode);

        //int i = 0;

        while(nodeList.size() > 0)
        {
            bool validNodeFound = false;
            currentNode = nodeList.back();

            cout << "{" << currentNode->GetData() <<"}, ";

            //push first valid edge onto list
            for(vector<GraphNode*>::iterator itr = currentNode->GetEdges()->begin(); itr != currentNode->GetEdges()->end() && validNodeFound == false; ++itr)
            {
                GraphNode * edgeNode = *itr;

                if(dataSearch == edgeNode->GetData())
                {
                    cout << "{Found}" << endl;
                    return edgeNode;
                }
                else if(edgeNode->GetVisited() == false)
                {
                    validNodeFound = true;
                    edgeNode->SetVisited(true);
                    nodeList.push_back(edgeNode);
                    cout << "[" << edgeNode->GetData() <<"], ";
                }
            }

            if(validNodeFound == false)
            {
                nodeList.pop_back();
            }
        }

        cout << endl;

		return nullptr;
    }

    GraphNode* FindByData( int dataSearch )
    {
        for(vector<GraphNode>::iterator itr = _vertices.begin(); itr != _vertices.end(); ++itr)
        {
            GraphNode * currentNode = itr._Ptr;

            if(dataSearch == currentNode->GetData())
            {
                return currentNode;
            }
        }

        return nullptr;
    }

    void ClearAllVisited()
    {
        for(vector<GraphNode>::iterator itr = _vertices.begin(); itr != _vertices.end(); ++itr)
        {
            GraphNode * currentNode = itr._Ptr;

            currentNode->SetVisited(false);
        }
    }

private:
    vector<GraphNode> _vertices;
};
