#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

class UnionFind;

class UnionFind
{
public:
	UnionFind(int size);

	void Union(int a, int b);
	int Find(int a);
	int Get(int a);
	void Print();
private:
	vector<int> mCommunity;
};

class UnionFindDisjointSet
{
public:
	void Test();
private:
	void MerginCommunities(int numPeople, string inputCommands);

	
};

void UnionFindDisjointSet::Test()
{
	int tests;
	int people;
	cout << "UnionFindDisjointSet" << endl;

	//string inputString = "M 1 2 M 3 4 Q 3 M 5 6 M 6 7 Q 7 M 1 5 Q 7 M 6 3 Q 7 M 1 7 M 7 3 M 2 7 M 3 7 M 4 7 M 5 7 M 6 7 Q 1 Q 1 Q 2 Q 3 Q 4 Q 5 Q 6 Q 7";


	std::ifstream in("input.txt");
	in >> people >> tests;

	std::stringstream buffer;
	buffer << in.rdbuf();

	std::string contents(buffer.str());

	MerginCommunities(people, contents);

}
/*
commands:
Q x return community size of x
M x y add x,y to each others community

We want to get the size of each persons community, if a-b are connection c-d
connected and d-a conneccted that community size of a = b, c, d => 4
*/
void UnionFindDisjointSet::MerginCommunities(int numPeople, string inputCommands)
{
	stringstream iss(inputCommands);

	UnionFind unionFind(numPeople);

	int i = 0;
	while (iss)
	{
		char cmd;
		iss >> cmd;

		switch (cmd)
		{
		case 'Q':
		{
			int member;
			iss >> member;

			cout << member-1 << " " << unionFind.Get(member -1) << endl;
		}
		break;
		case 'M':
		{
			int m, n;
			iss >> m >> n;

			unionFind.Union(m -1, n-1);
			//unionFind.Print();

		}
		default:
			break;
		}
	}

	unionFind.Print();
}


UnionFind::UnionFind(int size) :
	mCommunity(size, -1)
{

};

void UnionFind::Union(int a, int b)
{
	//combine a and b, already have parent reassign
	
	int rootA = Find(a);
	int rootB = Find(b);

	if (rootA != rootB)
	{
		//-x => x is number in community
		if (mCommunity[rootA] < mCommunity[rootB])
		{
			mCommunity[rootA] += mCommunity[rootB];
			mCommunity[rootB] = rootA;
		}
		else if (mCommunity[rootB] < mCommunity[rootA])
		{
			mCommunity[rootB] += mCommunity[rootA];
			mCommunity[rootA] = rootB;
		}
		else
		{
			//default is -1 (itself)
			mCommunity[rootA] += mCommunity[rootB];
			mCommunity[rootB] = rootA;
		}
	}
	else
	{
		cout << "same " << endl;
	}

	if ( abs(mCommunity[rootA]) > mCommunity.size() || abs(mCommunity[rootB]) > mCommunity.size())
	{
		Print();
	}

	//cout << "Union " << a << "|" << b << " A " << mCommunity[a] << " rA " << rootA << " B " << mCommunity[b] << " rB " << rootB << endl;
}

int UnionFind::Find(int a)
{

	if (mCommunity[a] >= 0)
	{
		return Find(mCommunity[a]);
		//mCommunity[a] = Find(mCommunity[a]);

	}

	return a;
	//if (mCommunity[a] >= 0)
	//{
	//	int root;
	//	root = Find(mCommunity[a]);

	//	if (root != mCommunity[a])
	//	{
	//		mCommunity[a] = root;
	//	}

	//	root = a;
	//}
	/*while (mCommunity[a] >= 0)
	{
		a = mCommunity[a];
	}

	return a;*/
}

int UnionFind::Get(int a)
{
	int rootA = Find(a);

	return abs(mCommunity[rootA]);
}

void UnionFind::Print(void)
{

	cout << "[ ";

	for (int i = 0; i < mCommunity.size(); i++)
	{
		cout << mCommunity[i] << ", ";
	}
	cout << "] " << endl;

}

