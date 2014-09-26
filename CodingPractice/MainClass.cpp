#include "MainClass.h"
#include "CyclicList.h"
#include "ClassB.h"
#include "Simulator.h"
#include "Graph.h"
#include "Tree.h"
#include "RegMatch.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "Palandromic.h"
#include <iostream>
#include "WarGame.h"
#include "Fibinocci.h"
#include "Heapsort.h"
#include "StringAlgorithms.h"
#include "LinkedListAlgorithms.h"
#include "RecursionAlgorithms.h"
#include "SortingAlgorithms.h"
#include "TreeGraphAlgorithms.h"
#include "BitManipulationAlg.h"
#include "BucketSort.h"
#include "CodeChef.h"
#include <iostream>
#include <fstream>
#include <string>
#include "MathProblems.h"

using namespace std;

MainClass::MainClass(void)
{
    int valuesSet1[] = {5,4,3,2,1};
    int valuesSet2[] = {3,4,5,1,2};
    int valuesSet3[] = {5,1,2,3,4};
    int valuesSet4[] = {5,4,3,2,1};
    int valuesSet5[] = {2,2,1,1,1};
    int valuesSet6[] = {2,3,5,4,1};

    CyclicList list1, list2, list3, list4, list5, list6;

    for(int i = 0; i < 5; i++)
    {
        list1.Insert(valuesSet1[i]);
        list2.Insert(valuesSet2[i]);
        list3.Insert(valuesSet3[i]);
        list4.Insert(valuesSet4[i]);
        list5.Insert(valuesSet5[i]);
        list6.Insert(valuesSet6[i]);
    }

    list1.PrintData();
    list2.PrintData();
    list3.PrintData();
    list4.PrintData();
    list5.PrintData();
    list6.PrintData();

    /* Notes
    class lifecycle
    inherited class
    class members
    ~derived class
    ~class members
    ~inherited class
    */
    ClassB * pClassB = new ClassB();
    delete pClassB;

    Simulator simulator;

    simulator.Run();

    RunGraphs();
	RunTrees();
	RunRedMatch();
	RunSorting();
    RunPalandrome();
    RunCardGame();
    RunFib();

    StringAlgorithms strAlg;
    strAlg.TestAll();

	LinkedListAlgorithms llAlg;
	llAlg.TestAll();

	RecursionAlgorithms recursionAlgs;
	recursionAlgs.TestAll();

	SortingAlgorithms sortingAlg;
	sortingAlg.TestAll();

	TreeGraphAlgorithms trAlg;
	trAlg.TestAll();

	BitManipulationAlg bitManAlg;
	bitManAlg.TestAll();

	BucketSort bucketSort;
	bucketSort.TestAll();

    CodeChef chefCode;
    chefCode.TestAll();

	MathProblems mathProblems;
	mathProblems.TestAll();

    RunFileIo();

}

void MainClass::RunFileIo()
{
    std::fstream fs;
    fs.open ("test.txt", std::fstream::out | std::fstream::app);

    if( fs.good() )
        fs << " more lorem ipsum";

    fs.close();


    string fileData;
    fs.open ("test.txt", std::fstream::in | std::fstream::app);
        fs >> fileData;

    /*while( !fs.eof() )
    {
        //fs.read();
       fs >>fileData;     
       cout << fileData;
    }*/
}

void MainClass::RunGraphs()
{
    Graph graph;

    graph.AddVertex(0);
    graph.AddVertex(1);
    graph.AddVertex(2);
    graph.AddVertex(3);
    graph.AddVertex(4);
    graph.AddVertex(5);
    graph.AddVertex(6);

    
    graph.AddEdge(0, 4);
    graph.AddEdge(0, 6);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
     graph.AddEdge(2, 3);
    graph.AddEdge(2, 5);
    graph.AddEdge(2, 6);
    graph.AddEdge(3, 2);
    graph.AddEdge(4, 5);
    graph.AddEdge(5, 3);
    graph.AddEdge(5, 4);
    graph.AddEdge(6, 1);
    graph.AddEdge(6, 3);

    graph.Print();   

    graph.BreadthSearch(1);
    graph.DepthSearch(1);
}

void MainClass::RunTrees()
{
	int someArray[] = {1,6,4,2,8,0,5,6,3,4};
	Tree tree;

	for( int i = 0; i < 10; i++ )
	{
		tree.Insert(someArray[i]);
		tree.PrintTree();
	}

	
}


void MainClass::RunRedMatch()
{
	RegMatch regMatch;

	cout << "Is Match = " << regMatch.IsMatch("ab\0", "ab\0") << endl;
	cout << "Is Match = " << regMatch.IsMatch("ab\0", ".b\0") << endl;
	cout << "Is Match = " << regMatch.IsMatch("ab\0", "*.\0") << endl;
	cout << "Is Match = " << regMatch.IsMatch("aaab\0", "*ab\0") << endl;
	cout << "Is Match = " << regMatch.IsMatch("aaab\0", "*b\0") << endl;;
	cout << "Is Match = " << regMatch.IsMatch("aaab\0", "*b\0") << endl;;
	cout << "Is Match = " << regMatch.IsMatch("aaab\0", "*ba\0") << endl;
	cout << "Is Match = " << regMatch.IsMatch("aaab\0", "aaab\0") << endl;
	cout << "Is Match = " << regMatch.IsMatch("aaab\0", "*a*b\0") << endl;


}
void MainClass::RunSorting()
{
	int array1[] = {0,2,6,1,5,3,9,7,4,8};
    int array2[] = {0,2,6,1,5,3,9,7,4,8};
    int array3[] = {0,2,6,1,5,3,9,7,4,8};
	deque<int> unsortedData;

	for(int i = 0; i < 10; i++)
	{
		unsortedData.push_back(array1[i]);
	}
	MergeSort mergeSort;

	mergeSort.Sort(unsortedData);

    QuickSort quicksort;
        cout << "Quick Started:" << endl;
    quicksort.Sort(array2, 0, 9);
        cout << "Quick End:" << endl;

	cout << "Heapsort" << endl;
	Heapsort heapsort;
	heapsort.Sort( array3, 10 );
	cout << "Heapsort end " << endl;
}

MainClass::~MainClass(void)
{
}

void MainClass::RunPalandrome()
{
    vector<string> palandromeStrings;
    palandromeStrings.push_back( "something abcddcba well" );
    palandromeStrings.push_back( "something abcd.,/dcba well" );
    palandromeStrings.push_back( "something ab c.d dcba well" );
    palandromeStrings.push_back( "something a bc  d dc b  a well" );
    palandromeStrings.push_back( "something aBcdDcba well" );
    palandromeStrings.push_back( "something abcdcba well" );

    Palandromic palandrone;
    for(int i=0; i < palandromeStrings.size(); i++)
    {
        cout << "String input =" << palandromeStrings[i] << "|| largest palandrone " << palandrone.GetLongestPalandromic( palandromeStrings[i] ) << endl;
    }
}

void MainClass::RunCardGame()
{
    WarCame warGame;
    warGame.RunGame();
}

void MainClass::RunFib()
{
    Fibinocci fib;
    cout << "FIB" << endl;

    for( int i = 0; i < 10 ; i++ )
    {
        cout << "fib Recursive(" << i << ") = " << fib.CalcFibRecursive( i ) << endl;
        cout << "fib Iterative(" << i << ") = " << fib.CalcFibInterative( i ) << endl;
    }
}

int main()
{
    char var[100];

    MainClass app;

	cout << "Done";
    cin >> var;
}