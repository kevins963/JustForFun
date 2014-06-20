#ifndef __TREE_GRAPH_ALGORITHMS_H
#define __TREE_GRAPH_ALGORITHMS_H

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "TreeNode.h"
#include "Tree.h"
#include "GraphNode.h";

using namespace std;

class TreeGraphAlgorithms
{

public:
	void TestAll( void );

	void TestIsTreeBalanced( void );
	bool IsTreeBalanced( TreeNode* tree );

	void TestIsGraphNodeConnected( void );
	bool IsGraphNodeConnected( GraphNode* graphStart, GraphNode* graphEnd );

	void TestCreateBalancedBTree( void );
	Tree* CreateBalancedBTree( vector<int> values );

	void TestFindCommonAncestor( void );
	TreeNode* FindCommonAncestor( TreeNode* root, TreeNode* n1, TreeNode* n2 );
	bool Contains( TreeNode* root, TreeNode* n1 );

    void TestShortestPathUsingBfs( void );
    vector<GraphNode*> ShortestPathUsingBfs( GraphNode* start, GraphNode* find );

    void TestShortestWeightedPathUsingBfs( void );
    pair<int,vector<GraphNodeWeighted*>>  ShortestWeightedPathUsingBfs( GraphNodeWeighted* start, GraphNodeWeighted* find );

private:
	int GetMaxCount( TreeNode* tree );
};

void TreeGraphAlgorithms::TestAll( void )
{
	TestIsTreeBalanced();
	TestIsGraphNodeConnected();
	TestCreateBalancedBTree();
	TestFindCommonAncestor();
    TestShortestPathUsingBfs();
    TestShortestWeightedPathUsingBfs();
}


void TreeGraphAlgorithms::TestFindCommonAncestor( void )
{
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);
	/*
			t1
          t2   t3
		t4 t6
      t5
	*/

	t1.SetNodeLeft( &t2 );
	t1.SetNodeRight( &t3 );
	
	t2.SetNodeLeft( &t4 );
	t2.SetNodeRight( &t6 );

	t4.SetNodeLeft( &t5 );

	cout << "<<<<< TestFindCommonAncestor " << endl;

	cout << "expected = " << t2.GetData() << endl;
	cout << "result   = " << FindCommonAncestor( &t1, &t5, &t6 )->GetData() << endl;

	
	cout << "expected = " << t2.GetData() << endl;
	cout << "result   = " << FindCommonAncestor( &t1, &t4, &t5 )->GetData() << endl;
	
}

TreeNode* TreeGraphAlgorithms::FindCommonAncestor( TreeNode* root, TreeNode* n1, TreeNode* n2 )
{
	if( Contains( root->GetNodeLeft(), n1 ) && Contains( root->GetNodeLeft(), n2 ) )
	{
		return FindCommonAncestor( root->GetNodeLeft(), n1, n2 );
	}
	else if( Contains( root->GetNodeRight(), n1 ) && Contains( root->GetNodeRight(), n2 ) )
	{
		return FindCommonAncestor( root->GetNodeRight(), n1, n2 );
	}

	return root;
}

bool TreeGraphAlgorithms::Contains( TreeNode* root, TreeNode* n1 )
{
	if( root == n1 )
	{
		return true;
	}
	else if( !root )
	{
		return false;
	}
	
	return Contains( root->GetNodeLeft(), n1 ) || Contains( root->GetNodeRight(), n1 );
}

void TreeGraphAlgorithms::TestIsTreeBalanced( void )
{
	TreeNode tree(1);
	TreeNode tree1(2);
	TreeNode tree2(3);
	TreeNode tree3(3);

	cout << "<<<<< TestIsTreeBalanced" << endl;

	cout << "Expected = " << false << endl;
	cout << "Result   = " << IsTreeBalanced( (TreeNode*)( 0 ) ) << endl;

	cout << "Expected = " << true << endl;
	cout << "Result   = " << IsTreeBalanced( &tree ) << endl;

	tree.SetNodeRight( &tree1 );
	cout << "Expected = " << true << endl;
	cout << "Result   = " << IsTreeBalanced( &tree ) << endl;
	
	tree1.SetNodeLeft( &tree2 );
	cout << "Expected = " << false << endl;
	cout << "Result   = " << IsTreeBalanced( &tree ) << endl;

	//    t
	// t3    t1
	//     t2
	tree.SetNodeLeft( &tree3 );
	cout << "Expected = " << true << endl;
	cout << "Result   = " << IsTreeBalanced( &tree ) << endl;
}

bool TreeGraphAlgorithms::IsTreeBalanced( TreeNode* tree )
{
	if( !tree )
	{
		return false;
	}

	int lnc = GetMaxCount( tree->GetNodeLeft() );
	int rnc = GetMaxCount( tree->GetNodeRight() );

	if( abs( lnc - rnc ) > 1 )
	{
		return false;
	}

	bool isBalancedLeft = ( tree->GetNodeLeft() ) ? IsTreeBalanced( tree->GetNodeLeft() ) : true;
	bool isBalancedRight = ( tree->GetNodeRight() ) ? IsTreeBalanced( tree->GetNodeRight() ) : true; 

	return isBalancedLeft && isBalancedRight;
}

int TreeGraphAlgorithms::GetMaxCount( TreeNode* tree )
{
	if( !tree )
	{
		return 0;
	}

	int lnc = GetMaxCount( tree->GetNodeLeft() );
	int rnc = GetMaxCount( tree->GetNodeRight() );
	
	return std::max( lnc, rnc ) + 1;	
}

void TreeGraphAlgorithms::TestIsGraphNodeConnected( void )
{

	GraphNode g1(1);
	GraphNode g2(1);
	GraphNode g3(1);
	GraphNode g4(1);
	GraphNode g5(1);
	GraphNode g6(1);

	g1.SetEdges( &g2 );

	g2.SetEdges( &g4 );
	g2.SetEdges( &g5 );

	g3.SetEdges( &g2 );
	g3.SetEdges( &g5 );
	g3.SetEdges( &g6 );

	g4.SetEdges( &g1 );
	
	g6.SetEdges( &g5 );

	cout << "<<<<< TestIsGraphNodeConnected" << endl;

	cout << "expected = " << true << endl;
	cout << "result   = " << IsGraphNodeConnected( &g1, &g2 ) << endl;
	
	cout << "expected = " << true << endl;
	cout << "result   = " << IsGraphNodeConnected( &g1, &g4 ) << endl;
	
	cout << "expected = " << false << endl;
	cout << "result   = " << IsGraphNodeConnected( &g1, &g3 ) << endl;
	
	cout << "expected = " << true << endl;
	cout << "result   = " << IsGraphNodeConnected( &g3, &g4 ) << endl;
	
	cout << "expected = " << false << endl;
	cout << "result   = " << IsGraphNodeConnected( &g5, &g1 ) << endl;
	

	/*
	1 2 3
	4 5 6
	1: 2, 3, 6
	*/
	
}

bool TreeGraphAlgorithms::IsGraphNodeConnected( GraphNode* graphStart, GraphNode* graphEnd )
{
	map<GraphNode*, bool> visitedNodes;
	vector<GraphNode*> searchList;

	if( !graphStart || !graphEnd )
	{
		return false;
	}

	/* Get start node */

	searchList.push_back( graphStart );
	visitedNodes[graphStart] = true;

	while( searchList.size() > 0 )
	{
		/* Get current node */
		GraphNode* curNode = searchList.back();
		searchList.pop_back();
		/* Validate current node */
		if( curNode == graphEnd )
		{
			return true;
		}

		/* If no match add all non visited edges to the search list */

		for( vector<GraphNode*>::iterator itr = curNode->GetEdges()->begin();
			itr < curNode->GetEdges()->end();
			itr++
			)
		{
			if( visitedNodes.count( *itr ) == 0 )
			{
				visitedNodes[*itr] = true;
				searchList.push_back( *itr );
			}
		}
	}

	return false;
}

void TreeGraphAlgorithms::TestCreateBalancedBTree( void )
{
	int t1[] = {1,2,3, 4, 5,6,7, 8 ,9,10,11, 12, 13,14,15};

	vector<int> v1( t1, t1 + sizeof(t1) / sizeof( t1[0] ) );

	Tree* tree = CreateBalancedBTree( v1 );

	tree->PrintInOrder();

	
	v1.push_back( 16 );
	tree = CreateBalancedBTree( v1 );

	tree->PrintInOrder();
}

Tree* TreeGraphAlgorithms::CreateBalancedBTree( vector<int> values )
{
	Tree* tree = nullptr;

	if( values.size() == 0 )
	{
		return tree;
	}

	int interval;
	int currentIndex;
	int midIndex;

	/* Get mid index */
	midIndex = values.size() / 2;

	/* Create initial index */
	tree = new Tree();

	tree->Insert( values[midIndex] );
	interval = values.size() / 2 + 1;

	while( interval > 1 )
	{
		currentIndex = interval / 2 - 1;

		while( currentIndex < values.size() )
		{
			tree->Insert( values[currentIndex] );
			currentIndex += interval;
		}

		interval /= 2;
	}

	return tree;
}

/*
Find the shortest path using BFS, using a visted tree store the first node to visit it instead of a bool

Starting with the find node work backwords to find the shortest path, if last node not visited then they are not connected
*/
vector<GraphNode*> TreeGraphAlgorithms::ShortestPathUsingBfs( GraphNode* start, GraphNode* find )
{
    bool isFound = false;
    vector<GraphNode*> shortestPath;
    queue<GraphNode*> searchEdges;
    map<GraphNode*, GraphNode*> visitedNodes;

    searchEdges.push( start );
    while( searchEdges.size() > 0 && !isFound )
    {
        GraphNode* currentEdge = searchEdges.front();
        searchEdges.pop();

        for( vector<GraphNode*>::iterator itr = currentEdge->GetEdges()->begin(); itr != currentEdge->GetEdges()->end(); itr++ )
        {
            //Check if node has already been visited, if not then add it to the map storing who its first parent is
            if( visitedNodes.find( *itr ) == visitedNodes.end() )
            {
                visitedNodes[*itr] = currentEdge;
                searchEdges.push( *itr );
                
                if( *itr == find )
                {
                    isFound = true;
                }
            }
        }
    }

    //If a path is found create the shortest path and return

    if( isFound )
    {
        GraphNode* currentEdge = find;
        shortestPath.push_back( currentEdge);

        while( currentEdge != start )
        {
            currentEdge = visitedNodes[currentEdge];
            shortestPath.push_back( currentEdge);
        }
    }

    return shortestPath;
}

void TreeGraphAlgorithms::TestShortestPathUsingBfs( void )
{
    /*
    1: 2
    2: 4,5
    3: 2,5,6
    4: 1
    5:
    6: 5
    */
    GraphNode g1(1);
    GraphNode g2(2);
    GraphNode g3(3);
    GraphNode g4(4);
    GraphNode g5(5);
    GraphNode g6(6);

    g1.SetEdges( &g2 );

    g2.SetEdges( &g4 );
    g2.SetEdges( &g5 );

    g3.SetEdges( &g2 );
    g3.SetEdges( &g5 );
    g3.SetEdges( &g6 );

    g4.SetEdges( &g1 );

    g6.SetEdges( &g5 );

    /*
    4-> 3 no connection
    3->4: 3-1-2-4
    */
    cout << "<<<<<<<<<<<<<<<<<<<ShortestPathUsingBfs" << endl;
    vector<GraphNode*> p1 = ShortestPathUsingBfs( &g4, &g3 );
    
    cout << "shortest path 4->3: ";
    for ( vector<GraphNode*>::iterator itr = p1.begin(); itr != p1.end(); itr++ )
    {
        cout << ", " << (*itr)->GetData();
    }
    cout << endl;

    p1 = ShortestPathUsingBfs( &g3, &g4 );

    cout << "shortest path 3->4: ";
    for ( vector<GraphNode*>::iterator itr = p1.begin(); itr != p1.end(); itr++ )
    {
        cout << ", " << (*itr)->GetData();
    }
    cout << endl;
}

/*
Find the shortest path using BFS, using a cost tree to find out the total cost of a path, if the current cost is less then the existing cost calculat new cost and add the parent pointer

Starting with the find node work backwords to find the shortest path, if last node not visited then they are not connected
*/
pair<int,vector<GraphNodeWeighted*>> TreeGraphAlgorithms::ShortestWeightedPathUsingBfs( GraphNodeWeighted* start, GraphNodeWeighted* find )
{
    bool isFound = false;
    vector<GraphNodeWeighted*> shortestPath;
    queue<GraphNodeWeighted*> searchEdges;
    map<GraphNodeWeighted*, pair<GraphNodeWeighted*,int>> visitedNodes;
    int cost = 0;

    //Set inital cost to zero
    searchEdges.push( start );
    visitedNodes[start] = make_pair(start, 0);
    while( searchEdges.size() > 0 && !isFound )
    {
        GraphNodeWeighted* currentEdge = searchEdges.front();
        searchEdges.pop();
        
        //Get the cost at current node
        int costAtCurrentNode = visitedNodes[currentEdge].second;

        for( vector<pair<GraphNodeWeighted*, int>>::iterator itr = currentEdge->GetEdges()->begin(); itr != currentEdge->GetEdges()->end(); itr++ )
        {
            //Get total cost from current node cost plus edge cost
            int pathCost = costAtCurrentNode + (*itr).second;

            //Check if current path is less then existing path add to search path, replace existing cost
            map<GraphNodeWeighted*, pair<GraphNodeWeighted*,int>>::iterator currentPathCostItr = visitedNodes.find( (*itr).first );

            if( currentPathCostItr == visitedNodes.end() )
            {
                //Edge not visited yet
                visitedNodes[(*itr).first] = make_pair(currentEdge, pathCost);
                
                if( (*itr).first != find )
                    searchEdges.push( (*itr).first );

            }
            //Else check if current path has lower cost
            else if( pathCost < (*currentPathCostItr).second.second )
            {
                //Edge not visited yet
                visitedNodes[(*itr).first] = make_pair(currentEdge, pathCost);
                if( (*itr).first != find )
                    searchEdges.push( (*itr).first );
            }
        }
    }

    //If a path is found create the shortest path and return

    if( visitedNodes.find( find ) != visitedNodes.end() )
    {
        cost = (visitedNodes[find]).second;
        GraphNodeWeighted* currentEdge = find;
        shortestPath.push_back( currentEdge);

        while( currentEdge != start )
        {
            currentEdge = (visitedNodes[currentEdge]).first;
            shortestPath.push_back( currentEdge);
        }
    }

    return make_pair(cost,shortestPath);
}

void TreeGraphAlgorithms::TestShortestWeightedPathUsingBfs( void )
{
    /*
    1: 2
    2: 4,5
    3: 2,5,6
    4: 1
    5:
    6: 5
    */
    GraphNodeWeighted g1(1);
    GraphNodeWeighted g2(2);
    GraphNodeWeighted g3(3);
    GraphNodeWeighted g4(4);
    GraphNodeWeighted g5(5);
    GraphNodeWeighted g6(6);
    GraphNodeWeighted g7(7);
    GraphNodeWeighted g8(8);
    GraphNodeWeighted g9(9);

    g1.SetEdges( &g2, 5 );
    g1.SetEdges( &g4, 6 );

    g2.SetEdges( &g1, 5 );
    g2.SetEdges( &g3, 4 );
    g2.SetEdges( &g5, 2 );

    g3.SetEdges( &g2, 4 );
    g3.SetEdges( &g6, 6 );

    g4.SetEdges( &g1, 6 );
    g4.SetEdges( &g5, 7 );
    g4.SetEdges( &g7, 4 );

    g5.SetEdges( &g2, 2 );
    g5.SetEdges( &g4, 7 );
    g5.SetEdges( &g6, 7 );
    g5.SetEdges( &g8, 2 );

    g6.SetEdges( &g3, 6 );
    g6.SetEdges( &g5, 7 );
    g6.SetEdges( &g9, 3 );

    g7.SetEdges( &g4, 4 );
    g7.SetEdges( &g8, 6 );

    g8.SetEdges( &g5, 2 );
    g8.SetEdges( &g7, 6 );
    g8.SetEdges( &g9, 5 );
    
    g9.SetEdges( &g6, 3 );
    g9.SetEdges( &g8, 5 );



    /*
    4-> 3 no connection
    3->4: 3-1-2-4
    */
    cout << "<<<<<<<<<<<<<<<<<<<ShortestPathUsingBfs" << endl;
    pair<int,vector<GraphNodeWeighted*>> p1 = ShortestWeightedPathUsingBfs( &g1, &g9 );
    
    cout << "shortest path 4->3: " << "total cost: "<< p1.first << endl;
    for ( vector<GraphNodeWeighted*>::iterator itr = p1.second.begin(); itr != p1.second.end(); itr++ )
    {
        cout << ", " << (*itr)->GetData();
    }
    cout << endl;
}


#endif