using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MoreCodingCSharp
{
    public class StringAlgs
    {

        public void TestAll()
        {

            TestPrintAllCombinations();
        }

        void TestPrintAllCombinations()
        {
            List<String> stringList = new List<string>();
            PrintAllCombinations("abcdefgh", 0, stringList);
                
            System.Console.WriteLine("TestPrintAllCombinations<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");

            foreach( String curString in stringList )
            {
                System.Console.Write(" {0}, ", curString );
            }
                System.Console.WriteLine(" ");

        }
        //a: bc, a: cb, b: ac, b: ca, c: ab, c ba 
        void PrintAllCombinations(String inString, int index, List<String> allStrings)
        {
            if( index >= inString.Length )
            {
                return;
            }

            PrintAllCombinations( inString, index + 1, allStrings );

            int lastIndex = allStrings.Count;

            for (int i = 0; i < lastIndex; i++ )
            {
                String newString = inString[index] + allStrings[i];
                allStrings.Add(newString);

                newString = allStrings[i] + inString[index];
                allStrings.Add(newString);
            }

            allStrings.Add(inString[index].ToString());
        }

    }
}
