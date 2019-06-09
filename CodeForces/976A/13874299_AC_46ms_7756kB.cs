using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int n=int.Parse(Console.ReadLine());
            string s=Console.ReadLine();
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '1')
                    count++;
            }
            if (count >= 1)
            {
                Console.Write("1");
            }
            for (int i = 0; i < n - count; i++)
                Console.Write("0");
           // Console.Write("helloworld!\n");
        }
    }
}
