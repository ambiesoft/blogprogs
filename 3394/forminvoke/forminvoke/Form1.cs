using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace forminvoke
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text += "ID:" + Thread.CurrentThread.ManagedThreadId;
        }

        Thread _t;
        Form2 _f2;
        void ths()
        {
            _f2=new Form2();
            _f2.ShowDialog();
            _f2.Dispose();
        }
        private void button1_Click(object sender, EventArgs e)
        {
            _t = new Thread(ths);
            _t.Start();
        }

        private delegate void invokedele();
        private void invoked()
        {
            MessageBox.Show(Thread.CurrentThread.ManagedThreadId.ToString());
        }
        private void button2_Click(object sender, EventArgs e)
        {
            this.BeginInvoke(new invokedele(invoked));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            _f2.BeginInvoke(new Form2.invokedele(_f2.invoked));
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Class1.threadsafemethod(this);
            Class1.threadsafemethod(_f2);
        }
    }
}
