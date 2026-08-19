using System;
namespace blahblah 
{
    class ReverseInt
    {
        public static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int ans = 0;
            while (n > 0) // vi kq cuoi la 0
            { // kqua của phần dư trước * 10 + phần dư sau
                ans = ans * 10 + n % 10;
                n /= 10;
            }
            Console.WriteLine(ans);
        }
    }
}