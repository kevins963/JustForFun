using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MoreCodingCSharp
{
    class SortingAlgs
    {

        public void TestAll()
        {
            TestQuickSort();
        }

        void TestQuickSort()
        {
            List<int> inList = new List<int>(new int[]{10,3,8,9,2,11,14,15,1,6,5,7,4,13,12});

            QuickSort(inList, 0, inList.Count - 1);

            System.Console.WriteLine("TestQuickSort<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");

            foreach (int printVal in inList)
            {
                System.Console.Write(" {0}, ", printVal);
            }
            System.Console.WriteLine(" ");
        }

        void QuickSort(List<int> inArray, int left, int right)
        {
            if (left < right)
            {
                int pivot = QuickSortPivotIndex(inArray, left, right);
                QuickSort(inArray, left, pivot - 1);
                QuickSort(inArray, pivot + 1, right);
            }
        }

        int QuickSortPivotIndex(List<int> inArray, int left, int right)
        {
            //Put all items smaller than pivot on left side
            int lessThanIndex = left;

            for (int i = left; i < right; i++)
            {
                if (inArray[i] < inArray[right])
                {
                    int temp = inArray[i];
                    inArray[i] = inArray[lessThanIndex];
                    inArray[lessThanIndex] = temp;
                    lessThanIndex++;
                }
            }

            int temp1 = inArray[right];
            inArray[right] = inArray[lessThanIndex];
            inArray[lessThanIndex] = temp1;

            return lessThanIndex;
        }
    }
}
