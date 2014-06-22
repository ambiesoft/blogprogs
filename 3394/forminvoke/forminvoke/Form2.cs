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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            this.Text += "ID:" + Thread.CurrentThread.ManagedThreadId;
        }

        internal delegate void invokedele();
        internal void invoked()
        {
            MessageBox.Show(Thread.CurrentThread.ManagedThreadId.ToString());
        }
    }
}
