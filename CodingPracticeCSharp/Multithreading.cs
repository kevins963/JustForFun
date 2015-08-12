using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CodingPracticeCSharp
{
    class Multithreading
    {
        public void RunTests()
        {
            TestThreads();
        }

        void TestThreads()
        {
            //Thread t1 = new Thread( this.ProcessData );
            Task task = Task.Run( ()=>
            {
                Console.WriteLine("Something");
            });

        }

        void ProcessData( String data )
        {
            bool isFinished = true;
            int lastIndex = 0;
            while (isFinished == false)
            {
                Thread.Sleep(50);
                Console.Write("[P {0}] ", data[lastIndex]);
                if (lastIndex >= (data.Length - 1))
                {
                    isFinished = true;
                }
            }

            
        }
        static void SomeMethod()
        {
            Console.WriteLine("SomeMethod");
        }
    }
    
}
