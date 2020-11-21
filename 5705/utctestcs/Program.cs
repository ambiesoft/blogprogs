using System;

namespace utctest
{
    class Program
    {
        static void Main(string[] args)
        {
            DateTime now = DateTime.Now;
            DateTime utcNow = DateTime.UtcNow;
            DateTime zero = new DateTime(0);
            Int32 unixTimestamp = (Int32)(DateTime.UtcNow.Subtract(new DateTime(1970, 1, 1))).TotalSeconds;
            Console.WriteLine("unixTimestamp: " + unixTimestamp);
            Console.WriteLine();

            Console.WriteLine("now.ToLongDateString(): " + now.ToLongDateString());
            Console.WriteLine("utcNow.ToLongDateString(): " + utcNow.ToLongDateString());
            Console.WriteLine("zero.ToLongDateString(): " + zero.ToLongDateString());
            Console.WriteLine();

            Console.WriteLine("now.ToLongTimeString(): " + now.ToLongTimeString());
            Console.WriteLine("utcNow.ToLongTimeString(): " + utcNow.ToLongTimeString());
            Console.WriteLine("zero.ToLongTimeString(): " + zero.ToLongTimeString());
            Console.WriteLine();

            Console.WriteLine("now.Ticks: " + now.Ticks);
            Console.WriteLine("utcNow.Ticks: " + utcNow.Ticks);
            Console.WriteLine("zero.Ticks: " + zero.Ticks);
            Console.WriteLine();

            Console.WriteLine("now.Millisecond:" + now.Millisecond);
            Console.WriteLine("utcNow.Millisecond:" + utcNow.Millisecond);
            Console.WriteLine("zero.Millisecond:" + zero.Millisecond);
            Console.WriteLine();

        }
    }
}
