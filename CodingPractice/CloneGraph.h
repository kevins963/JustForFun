#pragma once

#include "GraphNode.h";

#include <map>;
#include <deque>
#include <vector>
class CloneGraph
{
    CloneGraph(){};
    ~CloneGraph(){};


    GraphNode* CloneBFS( GraphNode* inputNode );
    
};

/*
Get node, add to map
Add neighbors to map

If neighbor doesn't exist in graph add to deque
*/
GraphNode* CloneGraph::CloneBFS( GraphNode* inputNode )
{
    deque<GraphNode*> graphQueue;
    map<GraphNode*, GraphNode*> graphMap;

    GraphNode* graphCopy = new GraphNode( inputNode->GetData() );
    graphMap[graphCopy] = graphCopy;

    graphQueue.push_back( inputNode );

    while( graphQueue.size() > 0)
    {
        GraphNode * currentNode = graphQueue.front();
        graphQueue.pop_front();
        vector<GraphNode*> * neighbors = currentNode->GetEdges();
        //Check if node is already in map

        for( vector<GraphNode*>::iterator itr = neighbors->begin(); itr != neighbors->end(); itr++)
        {
            GraphNode * currentNeighbor = *itr;
            if( graphMap.find( currentNode ) == graphMap.end() )
            {
                graphQueue.push_back( currentNeighbor );
                graphMap[currentNeighbor] = currentNeighbor;
            }
        }
    }

}
