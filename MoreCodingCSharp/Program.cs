using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MoreCodingCSharp;

namespace MoreCodingCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            StringAlgs stringAlgs = new StringAlgs();
            stringAlgs.TestAll();

            SortingAlgs sortAlgs = new SortingAlgs();
            sortAlgs.TestAll();

            ChessShortestPath chessShortestPath = new ChessShortestPath();
            chessShortestPath.Test();


        }
    }
}
