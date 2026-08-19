using System;
namespace basicCalculator
{
    class Bai_2_14
    {
        public static void Main(string[] arg)
        {
            float a = float.Parse(Console.ReadLine()!);
            float b = float.Parse(Console.ReadLine()!);
            char o = char.Parse(Console.ReadLine()!);
            switch (o)
            {
                case '+':
                    Console.WriteLine($"Phep cong la: {a + b}");
                    break;
                case '-':
                    Console.WriteLine($"Phep tru la: {a - b}");
                    break;
                case '*':
                    Console.WriteLine($"Phep nhan la: {a * b}");
                    break;
                case '/':
                    Console.WriteLine($"Phep chia la: {a + b}");
                    break;
                default:
                    Console.WriteLine("Khong thuc hien duoc phep tinh!");
                    break;
            }
        }
    }
}