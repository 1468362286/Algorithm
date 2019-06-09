using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;
namespace test
{
    class Program
    {
        static bool judge(char x)
        {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y')
            {
                return true;
            }
            return false;
        }
        static void Main(string[] args)
        {
            var str1 = Console.ReadLine();
            var str = Console.ReadLine();
            int a = int.Parse(str1);
            int len = str.Length;
            string ans = string.Empty;
            for (int i = 0; i < str.Length; i++)
            {
                if (judge(str[i]))
                {
                    ans += str[i];
                    if (i == len-1)
                        break;
                    while (judge(str[i + 1]))
                    {
                        i++;
                        if (i == len - 1)
                            break;
                    }
                }
                else
                    ans += str[i];
            }           
            Console.WriteLine(ans);
        }
    }
}
