﻿using System;
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
        
        public void RunTest()
        {
            TestBranchAndBound();
        }

        void TestBranchAndBound()
        {
            List<KnapsackItem> items = new List<KnapsackItem>();

            items.Add(new KnapsackItem(1, 2));
            items.Add(new KnapsackItem(4, 4));
            items.Add(new KnapsackItem(6, 5));
            items.Add(new KnapsackItem(10, 10));

            KnapsackBranchAndBound(items, 10);
        }

        //Branch and bound method is similar to backtrack but instead up going through all solutions
        //algorithm with branch and test if the maximum bound is greater than current value
        //if not then skips entire subtree.  Great with large datasets where bounding can be calculated
        //Compared to dynamic 2D table, BB has much less memory but potentially higher runtime iterations 2^n 
        //however runtime is usually much lower
        int KnapsackBBRecursion(List<KnapsackItem> sortedItems,List<KnapsackItem> knapsack, int maxCapacity, int level, int currentValue)
        {
            //check endpoint
            if (level >= sortedItems.Count)
            {
                return currentValue;
            }
            //calculate upper bounds of max value
            int upperBounds = 0;
            int knapsackWeight = 0;

            foreach (KnapsackItem item in knapsack)
            {
                upperBounds += item._value;
                knapsackWeight += item._weight;
            }

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
            if (upperBounds <= currentValue)
            {
                return currentValue;
            }
            else
            {
                level++;
                int valueNo = KnapsackBBRecursion( sortedItems, knapsack, maxCapacity, level, currentValue );
                int valueWith = KnapsackBBRecursion(sortedItems, knapsack, maxCapacity, level, currentValue);

                int maxValue = Math.Max(valueNo, valueWith);
                maxValue = Math.Max(maxValue, currentValue);

                return maxValue;

            }
        }

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

            int maxValue = KnapsackBBRecursion(items, new List<KnapsackItem>(), capacity, 0, 0);
            return maxValue;
        }
    }
}
