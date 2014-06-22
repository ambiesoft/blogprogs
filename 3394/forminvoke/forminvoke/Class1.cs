using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
namespace forminvoke
{
    class Class1
    {
        delegate void dele(Control c);
        internal static void threadsafemethod(Control c)
        {
            if (c.InvokeRequired)
            {
                c.BeginInvoke(new dele(threadsafemethod), c);
                return;
            }

            MessageBox.Show("threadsafemethod" + Thread.CurrentThread.ManagedThreadId);
        }

    }
}
