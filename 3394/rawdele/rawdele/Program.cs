using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
namespace rawdele
{
    class Program
    {
        delegate void mydelegate();
        static void myfunc()
        {
            Console.WriteLine("myfunc Thread:" + Thread.CurrentThread.ManagedThreadId);
            Thread.Sleep(500);
            Console.WriteLine("myfunc1");
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Main Thread:" + Thread.CurrentThread.ManagedThreadId);
            mydelegate myd = new mydelegate(myfunc);

            Console.WriteLine("Normal Call");
            myd();

            Console.WriteLine("Invoke Call");
            myd.Invoke();

            Console.WriteLine("BeginInvoke Call");
            IAsyncResult iar = myd.BeginInvoke(null, null);
            Console.WriteLine("Wait BeginInvoke Call");
            myd.EndInvoke(iar);
        }
    }
}
