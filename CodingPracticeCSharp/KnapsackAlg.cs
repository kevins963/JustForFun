using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace CodingPracticeCSharp
{
    class KnapsackItem
    {
        public int _value;
        public int _weight;

        public KnapsackItem(int value, int weight)
        {
            _value = value;
            _weight = weight;
        }
    }

    class Knapsack
    {
        public LinkedList<KnapsackItem> _items;
        public int _maxCapacity;
        public int _currentCapacity;

        public Knapsack(int capacity)
        {
            _maxCapacity = capacity;
            _currentCapacity = 0;
            _items = new LinkedList<KnapsackItem>();
        }
    }

    //Knapsack algorithm 0/1 is an NP optimization problem. You want to maximize the total value of the knapsack
    //while the total weight is less than the capacity of the sack

    class KnapsackAlg
    {
        int count;

        public void RunTest()
        {
            TestBranchAndBound();
        }

        void TestBranchAndBound()
        {
            List<KnapsackItem> items = new List<KnapsackItem>();

            items.Add(new KnapsackItem(2, 1));
            items.Add(new KnapsackItem(2, 2));
            items.Add(new KnapsackItem(3, 3));
            items.Add(new KnapsackItem(5, 4));
            items.Add(new KnapsackItem(3, 3));
            items.Add(new KnapsackItem(3, 4));
            items.Add(new KnapsackItem(4, 5));
            items.Add(new KnapsackItem(6, 6));
            items.Add(new KnapsackItem(7, 6));
            items.Add(new KnapsackItem(4, 5));
            items.Add(new KnapsackItem(2, 4));
            items.Add(new KnapsackItem(6, 4));
            items.Add(new KnapsackItem(3, 4));
            items.Add(new KnapsackItem(7, 4));
            items.Add(new KnapsackItem(13, 9));
            items.Add(new KnapsackItem(4, 7));
            items.Add(new KnapsackItem(14, 15));
            items.Add(new KnapsackItem(5, 3));
            items.Add(new KnapsackItem(11, 8));
            items.Add(new KnapsackItem(22, 18));
            items.Add(new KnapsackItem(4, 2));
            items.Add(new KnapsackItem(22, 26));
            items.Add(new KnapsackItem(12, 11));
            items.Add(new KnapsackItem(5, 4));

            KnapsackBranchAndBound(items, 50);
        }

        //Branch and bound method is similar to backtrack but instead up going through all solutions
        //algorithm with branch and test if the maximum bound is greater than current value
        //if not then skips entire subtree.  Great with large datasets where bounding can be calculated
        //Compared to dynamic 2D table, BB has much less memory but potentially higher runtime iterations 2^n 
        //however runtime is usually much lower

        int KnapsackBBRecursion(bool useBounds, List<KnapsackItem> sortedItems, int maxCapacity, int level, int currentValue, int currentWeight, int bestValue )
        {
            //check endpoint
            count++;
            if (level >= sortedItems.Count)
            {
                //Console.WriteLine("END {0}", level);
                return currentValue;
            }

            //calculate upper bounds of max value
            int upperBounds = currentValue;
            int knapsackWeight = currentWeight;

            for (int i = level; i < sortedItems.Count() && (knapsackWeight < maxCapacity); i++)
            {
                KnapsackItem item = sortedItems[i];
                //two possibilities either full item or partial item can be used
                if (knapsackWeight + item._weight <= maxCapacity)
                {
                    knapsackWeight += item._weight;
                    upperBounds += item._value;
                }
                else
                {
                    //use partial item to calc max poential even though we can only us 0/1
                    int weightRemaining = (maxCapacity - knapsackWeight);
                    int partialValue = (item._value * weightRemaining) / item._weight;

                    upperBounds += partialValue;
                    knapsackWeight += weightRemaining;
                }
            }

            //Check upper bound to see if we should continue
            if (useBounds && 
                upperBounds <= bestValue)
            {
                //Console.Write("LIMITED ");
                return 0;
            }
            else
            {
                //Console.Write("START L/V/W/B {0} {1} {2} || ", level, currentValue, currentWeight, bestValue );

                if (currentWeight + sortedItems[level]._weight <= maxCapacity)
                {
                    int valueWith = KnapsackBBRecursion(useBounds, sortedItems, maxCapacity, level + 1, currentValue + sortedItems[level]._value, currentWeight + sortedItems[level]._weight, bestValue);

                    if (valueWith > bestValue)
                    {
                        bestValue = valueWith;
                    }
                }

                int valueNo = KnapsackBBRecursion(useBounds, sortedItems, maxCapacity, level + 1, currentValue, currentWeight, bestValue);

                if (valueNo > bestValue)
                {
                    bestValue = valueNo;
                }

                
               // Console.Write("STOP L/B {0} {1}\n", level, bestValue);

                return bestValue;
            }
        }

        //int KnapsackBBIteration(bool useBounds, List<KnapsackItem> sortedItems, int maxCapacity)
        //{
        //    //bool[] itemUsed = new bool[sortedItems.Count];
        //    int level = 0;
        //    int currentValue = 0;
        //    int currentWeight = 0;
        //    int bestValue = 0;

        //    KeyValuePair<int, bool> dfsPointer = new KeyValuePair<int,bool>();
        //    LinkedList<KeyValuePair<int,bool>> knapsack = new LinkedList<KeyValuePair<int,bool>>();
            
            
        //    //use dfs to get value so queue lifo
        //    knapsack.AddFirst( new KeyValuePair<int, bool>( level, false ) );
        //    knapsack.AddFirst( new KeyValuePair<int, bool>( level, true ) );

        //    // 1 -> 2 -> 3 -> 4
        //    while ( knapsack.Count > 0 )
        //    {
        //        KeyValuePair<int, bool>  itemPtr = knapsack.First();

        //        level = itemPtr.Key;
                
        //        //should use item
        //        if( itemPtr.Value == true)
        //        {
        //            KnapsackItem item = sortedItems[level];

        //            if( item._weight + currentWeight <= maxCapacity )
        //            {
        //                currentValue += item._value;
        //                currentWeight += item._weight;
        //            }
        //        }
                
        //        if( level + 1 < sortedItems.Count )
        //        {
                    
        //            knapsack.AddFirst( new KeyValuePair<int, bool>( level+1, false ) );
        //            knapsack.AddFirst( new KeyValuePair<int, bool>( level+1, true ) );
        //        }

                
        //        //calculate
        //        currentValue = currentValue + knapsack.First().
        //        //On enter node we need to know if it is used or not

        //    }
        //    //only increment level, if going to level add if decreasing

        //    //check endpoint
        //    count++;
        //    if (level >= sortedItems.Count)
        //    {
        //        //Console.WriteLine("END {0}", level);
        //        return currentValue;
        //    }

        //    //calculate upper bounds of max value
        //    int upperBounds = currentValue;
        //    int knapsackWeight = currentWeight;

        //    for (int i = level; i < sortedItems.Count() && (knapsackWeight < maxCapacity); i++)
        //    {
        //        KnapsackItem item = sortedItems[i];
        //        //two possibilities either full item or partial item can be used
        //        if (knapsackWeight + item._weight <= maxCapacity)
        //        {
        //            knapsackWeight += item._weight;
        //            upperBounds += item._value;
        //        }
        //        else
        //        {
        //            //use partial item to calc max poential even though we can only us 0/1
        //            int weightRemaining = (maxCapacity - knapsackWeight);
        //            int partialValue = (item._value * weightRemaining) / item._weight;

        //            upperBounds += partialValue;
        //            knapsackWeight += weightRemaining;
        //        }
        //    }

        //    //Check upper bound to see if we should continue
        //    if (useBounds &&
        //        upperBounds <= bestValue)
        //    {
        //        //Console.Write("LIMITED ");
        //        return 0;
        //    }
        //    else
        //    {
        //        //Console.Write("START L/V/W/B {0} {1} {2} || ", level, currentValue, currentWeight, bestValue );

        //        if (currentWeight + sortedItems[level]._weight <= maxCapacity)
        //        {
        //            int valueWith = KnapsackBBRecursion(useBounds, sortedItems, maxCapacity, level + 1, currentValue + sortedItems[level]._value, currentWeight + sortedItems[level]._weight, bestValue);

        //            if (valueWith > bestValue)
        //            {
        //                bestValue = valueWith;
        //            }
        //        }

        //        int valueNo = KnapsackBBRecursion(useBounds, sortedItems, maxCapacity, level + 1, currentValue, currentWeight, bestValue);

        //        if (valueNo > bestValue)
        //        {
        //            bestValue = valueNo;
        //        }


        //        // Console.Write("STOP L/B {0} {1}\n", level, bestValue);

        //        return bestValue;
        //    }
        //}

        //int KnapsackBBRecursion(List<KnapsackItem> sortedItems,List<KnapsackItem> knapsack, int maxCapacity, int level, int currentValue)
        //{
        //    //check endpoint
        //    if (level >= sortedItems.Count)
        //    {
        //        return currentValue;
        //    }
        //    //calculate upper bounds of max value
        //    int upperBounds = 0;
        //    int knapsackWeight = 0;

        //    foreach (KnapsackItem item in knapsack)
        //    {
        //        upperBounds += item._value;
        //        knapsackWeight += item._weight;
        //    }

        //    for (int i = level; i < sortedItems.Count() && (knapsackWeight < maxCapacity); i++)
        //    {
        //        KnapsackItem item = sortedItems[i];
        //        //two possibilities either full item or partial item can be used
        //        if (knapsackWeight + item._weight <= maxCapacity)
        //        {
        //            knapsackWeight += item._weight;
        //            upperBounds += item._value;
        //        }
        //        else
        //        {
        //            //use partial item to calc max poential even though we can only us 0/1
        //            int weightRemaining = (maxCapacity - knapsackWeight);
        //            int partialValue = (item._value * weightRemaining) / item._weight;

        //            upperBounds += partialValue;
        //            knapsackWeight += weightRemaining;
        //        }
        //    }

        //    //Check upper bound to see if we should continue
        //    if (upperBounds <= currentValue)
        //    {
        //        return currentValue;
        //    }
        //    else
        //    {
        //        level++;
        //        int valueNo = KnapsackBBRecursion( sortedItems, knapsack, maxCapacity, level, currentValue );
        //        int valueWith = KnapsackBBRecursion(sortedItems, knapsack, maxCapacity, level, currentValue);

        //        int maxValue = Math.Max(valueNo, valueWith);
        //        maxValue = Math.Max(maxValue, currentValue);

        //        return maxValue;

        //    }
        //}

        int KnapsackBranchAndBound( List<KnapsackItem> items, int capacity )
        {
            //
            LinkedList<KnapsackItem> dfsStack = new LinkedList<KnapsackItem>();

            //Sort the items by maximum benefit value / weight
            items.Sort(delegate(KnapsackItem i1, KnapsackItem i2)
            {
                float i1d = (float)i1._value / (float)i1._weight;
                float i2d = (float)i2._value / (float)i2._weight;

                if( i1._value == i2._value &&
                    i1._weight == i2._weight)
                {
                    return 0;
                }

                if (i1d > i2d)
                {
                    return -1;
                }

                return 1;
            });

            foreach (KnapsackItem item in items)
            {
                Console.WriteLine("item = {0} {1} {2:0.000}", item._value, item._weight, (float)item._value / (float)item._weight);
            }

            count = 0;
            int maxValNoBounds = KnapsackBBRecursion(false, items, capacity, 0, 0, 0, 0);
            int countNoBounds = count;

            count = 0;
            int maxValWithBounds = KnapsackBBRecursion(true, items, capacity, 0, 0, 0, 0);
            int countWithBounds = count;

            Console.WriteLine("Total iterations backtracking V/C: {0} {1}", maxValNoBounds, countNoBounds);
            Console.WriteLine("Total iterations B&B V/C: {0} {1}", maxValWithBounds, countWithBounds);

            return maxValWithBounds;
        }
    }
}
