using System;
using System.Text;
namespace basicCalculator
{
    class Bai_2_14
    {
        public static void Main(string[] arg)
        {
            Console.InputEncoding = Encoding.Unicode;
            Console.OutputEncoding = Encoding.Unicode;
            Console.Write("Nhập số đầu tiên: ");
            float a = float.Parse(Console.ReadLine()!);
            Console.Write("Nhập số tiếp theo: ");
            float b = float.Parse(Console.ReadLine()!);
            Console.Write("Nhập dấu của phép tính: ");
            char o = char.Parse(Console.ReadLine()!);
            switch (o)
            {
                case '+':
                    Console.WriteLine($"Phép cộng là: {a + b}");
                    break;
                case '-':
                    Console.WriteLine($"Phép trừ là: {a - b}");
                    break;
                case '*':
                    Console.WriteLine($"Phép nhân là: {a * b}");
                    break;
                case '/':
                    Console.WriteLine($"Phép chia là: {a / b}");
                    break;
                default:
                    Console.WriteLine("Không thực hiện được phép tính");
                    break;
            }
        }
    }
}