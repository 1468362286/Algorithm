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
            long mo,h,l;
            h = 0;
            l = 0;
            string[] inp = Console.ReadLine().Split(' ');
            long n = Convert.ToInt64(inp[0]);
            long m = Convert.ToInt64(inp[1]);
            long k = Convert.ToInt64(inp[2]);
         //   k = k % (n * 3);
            if (k <= n - 1)
            {
                Console.WriteLine(k + 1 + " " + 1);
            }
            else
            {
                k -= (n - 1);
                mo = m - 1;
                if (k % mo > 0)
                    h = (k / mo) + 1;
                else
                    h = (k / mo);
                if ((k % mo)>0)
                    l = k % mo;
                else
                    l = mo;
                if ((h & 1)==1)
                {
                    l = l + 1;
                }
                else
                {
                    l = mo - l + 2;
                }
                Console.WriteLine(n - h + 1 + " " + l);
            }        
        }
    }
}