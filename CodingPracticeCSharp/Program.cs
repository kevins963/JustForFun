using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingPracticeCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Program thisApp = new Program();
            Console.WriteLine("CSharp Code Practice");
            thisApp.RunSorting();

            while (true) { };
        }

        void RunSorting()
        {
            int[] someArray = { 4, 1, 3, 5, 9, 2, 7, 8, 6, 0 };

            BubbleSort bubbleSort = new BubbleSort();

            bubbleSort.Sort(someArray);

            KnapsackAlg knapsackalg = new KnapsackAlg();
            knapsackalg.RunTest();

        }
    }
}
