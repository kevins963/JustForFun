using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingPracticeCSharp
{
    /*
     * Bubble Sort
     * Compare every adjacent pair and switch if needed
     */
    class BubbleSort
    {
        public Array Sort(int[] unsortedArray)
        {
            for (int i = unsortedArray.Length - 1; i > 0; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    if (unsortedArray[j] > unsortedArray[j + 1])
                    {
                        int temp = unsortedArray[j+1];
                        unsortedArray[j+1] = unsortedArray[j];
                        unsortedArray[j] = temp;
                    }
                }
                PrintArray(unsortedArray);
            }

            PrintArray(unsortedArray);

            return unsortedArray;
        }

        public void PrintArray(int[] printArray)
        {
            StringBuilder outputString = new StringBuilder();

            foreach (int printValue in printArray)
            {
                outputString.AppendFormat("{0},", printValue);
            }

            Console.WriteLine("{" + outputString.ToString() + "}");
        }
    }
}
