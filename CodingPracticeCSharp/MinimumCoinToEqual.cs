using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingPracticeCSharp
{
    class MinimumCoinToEqual
    {
        //Given X coins find the minimum amount to equal Y
        //Ex 1,5,10,25 =>31 = {25,5,1}

        public void RunTests()
        {
            TestFindMinCoinsForChange();
        }

        void TestFindMinCoinsForChange()
        {
            Console.WriteLine("TestFindMinCoinsForChange");
            int[] coins = {1,5,10,25};
            int[,] tests = { {1,1}, {5,1}, {10,1}, {25,1}, {30,2} };

            for(int i = 0; i < 50; i++ )
            {
                Console.WriteLine("input {0} result {1}", i, FindMinCoinsForChange(i, coins));
            }
            int result = FindMinCoinsForChange( 33, coins );

            Console.WriteLine("r={0}", result);
        }

        //using table -> NxM memory
        int FindMinCoinsForChange( int value, int[] coins )
        {
            // create table [n+1,m+1] we need empty default row/col

            //coins = i, value = j
            int maxI = coins.Length;
            int maxJ = value + 1;
            int i;
            int j;

            int[,] optTable = new int[maxI,maxJ];
 
            //Fill
            for (i = 0; i < maxI; i++)
            {
                for (j = 0; j < maxJ; j++)
                {
                    int leastCoins = 0;
                    //check if current value works
                    if ( coins[i] > j )
                    {
                        leastCoins = 0;
                    }
                    else
                    {
                        leastCoins = optTable[i, j - coins[i]] + 1;
                    }

                    if (i > 0)
                    {
                        if (leastCoins == 0)
                        {
                            leastCoins = optTable[i - 1, j];
                        }
                        else if (optTable[i - 1, j] < leastCoins && optTable[i - 1, j] != 0)
                        {
                            leastCoins = optTable[i - 1, j];
                        }
                    }

                    optTable[i, j] = leastCoins;
                }
            }
            return optTable[maxI - 1, maxJ - 1];
        }

    }
}
