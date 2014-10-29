using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MoreCodingCSharp
{
    /* Use a knight to jump two peices on a chess board and find the way with the lease number of moves to jump both */
    class ChessShortestPath
    {
        const int MaxRows = 8;
        const int MaxCols = 8;

        int[][] KnightMoveList = new int[][]{ 
        new int[] {2, 1}, 
        new int[] {2, -1},
        new int[] {-2, 1}, 
        new int[] {-2, -1},
        new int[] {1, 2}, 
        new int[] {1, -2},
        new int[] {-1, 2}, 
        new int[] {-1, -2} };

        Dictionary< int, List<int>> MoveMap;

        int[][] KnightDijkstraMap;
    
        public ChessShortestPath()
        {
            CreateKnightMoves();
            CreateDijkstra();
        }

        public void Test()
        {
            List<int[]> tests = new List<int[]>();
            tests.Add(new int[4]{ 
                      GetIndex(0,0),
                      GetIndex(1,2),
                      GetIndex(2,4),
                      2 });
            tests.Add(new int[4]{ 
                      GetIndex(1,0),
                      GetIndex(2,2),
                      GetIndex(0,2),
                      3 });

            tests.Add(new int[4]{ 
                      GetIndex(7,7),
                      GetIndex(4,1),
                      GetIndex(3,1),
                      6 });
            System.Console.WriteLine("CheckShortestPath<<<<<<<<<<<<<<");

            foreach (int[] test in tests)
            {
                int ret = FindMinimumMoves(test[0], test[1], test[2]);
                System.Console.WriteLine("min = {0}", test[3]);
            }

        }
        private void CreateKnightMoves()
        {
            MoveMap = new Dictionary< int,List<int> >();

            for (int i = 0; i < MaxCols; i++)
            {
                for( int j = 0; j < MaxRows; j++ )
                {

                    MoveMap[GetIndex(i, j)] = new List<int>();

                    for (int k = 0; k < MaxRows; k++)
                    {
                        int edge = GetIndex(KnightMoveList[k][0] + i, KnightMoveList[k][1] + j);

                        if (edge != -1)
                        {
                            MoveMap[GetIndex(i, j)].Add(edge);
                        }
                    }
                }
            }
        }

        void CreateDijkstra()
        {
            KnightDijkstraMap = new int[MaxRows*MaxCols][];

            for (int i = 0; i < MaxCols * MaxRows; i++)
            {
                int[] dist = new int[MaxCols * MaxRows];
                
                for(int j = 0; j < dist.Length; j++)
                {
                    dist[j] = 0;
                }

                //Use BFS to find shortest path to each
                List<int> currentList = new List<int>();

                currentList.Add(i);

                while( currentList.Count > 0 )
                {
                    int node = currentList[0];
                    currentList.RemoveAt(0);

                    List<int> edgesInNode = MoveMap[node];

                    //Only add nodes if less than
                    foreach( int edge in edgesInNode )
                    {
                        if( (dist[node] + 1 < dist[edge] || dist[edge] == 0 )&& edge != node)
                        {
                            dist[edge] = dist[node] + 1;
                            currentList.Add(edge);
                        }
                    }
                }

                KnightDijkstraMap[i] = dist;
            }
        }

        int GetIndex(int row, int col)
        {
            if( (row < 0) || (row >= MaxRows) || 
                (col < 0) || (col >= MaxCols) )
            {
                return -1;
            }

            return (row * MaxCols + col);
        }

        int FindMinimumMoves(int knight, int peice1, int peice2)
        {
            //Find the shortest distance between all possible options
            //If more than two that would use recursive to find it

            int route1 = KnightDijkstraMap[knight][peice1] + KnightDijkstraMap[peice1][peice2];
            int route2 = KnightDijkstraMap[knight][peice2] + KnightDijkstraMap[peice2][peice1];

            return Math.Max(route1, route2);
        }
    }

}
