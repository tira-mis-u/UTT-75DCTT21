using System;

// Bai 2.7
int n = int.Parse(Console.ReadLine()!);
int[] a = new int[n];
for(int i = 0; i < n; i++)
{
    a[i] = int.Parse(Console.ReadLine()!);
}
int max1 = a[0], max2 = a[0];
for(int i = 1; i < n; i++)
{
    if(max1 <= a[i])
    {
        max2 = max1;
        max1 = a[i];
    } else if (a[i] > max2) // check phía sau xem là còn ptu nào lớn hơn max2 kh
    {
        max2 = a[i];
    }
}
Console.WriteLine("Max: " + max1 + "\nMax 2: " + max2);