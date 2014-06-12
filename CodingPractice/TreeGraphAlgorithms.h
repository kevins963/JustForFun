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
private:
	int GetMaxCount( TreeNode* tree );
};

void TreeGraphAlgorithms::TestAll( void )
{
	TestIsTreeBalanced();
	TestIsGraphNodeConnected();
	TestCreateBalancedBTree();
	TestFindCommonAncestor();
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


#endif