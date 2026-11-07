using System;
namespace Bai_2_8
{
    public class MaTran
    {
        public int hang { get; }
        public int cot { get; }
        private int[,] data;

        public MaTran(int rows, int cols) {
            hang = rows;
            cot = cols;
            data = new int[rows, cols];
        }

        public void nhap()
        {
            for (int i = 0; i < hang; i++)
            {
                string[] inp = Console.ReadLine()!.Split(" ");
                for (int j = 0; j < cot; j++) data[i, j] = int.Parse(inp[j]);
            }
        }

        public override string ToString()
        {
            string s = "";
            for (int i = 0; i < hang; i++) {
                for (int j = 0; j < cot; j++) s += ($"{data[i, j]}" + (j < cot - 1 ? " " : ""));
                s += "\n";
            }
            return s;
        }

        public static MaTran operator +(MaTran a, MaTran b)
        {
            MaTran res = new MaTran(a.hang, a.cot);
            for(int i = 0; i < a.hang; i++) for(int j = 0; j < a.cot; j++)
            {
                res.data[i, j] = a.data[i, j] + b.data[i, j];
            }
            return res;
        }
    }
    class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Nhap so hang cua ma tran:");
            int n = int.Parse(Console.ReadLine()!);
            Console.WriteLine("Nhap so cot cua ma tran:");
            int m = int.Parse(Console.ReadLine()!);
            MaTran x = new MaTran(n, m);
            MaTran y = new MaTran(n, m);
            Console.WriteLine("Nhap ma tran dau tien:");
            x.nhap();
            Console.WriteLine("Nhap ma tran thu hai:");
            y.nhap();
            MaTran z = x + y;
            Console.WriteLine($"Tong 2 ma tran la: {z.ToString()}");
        }
    }
}