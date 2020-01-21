using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Windows.Forms;

namespace txtvalidateandchange
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            Text = "'z' is invalid";
        }

        [MethodImpl(MethodImplOptions.NoInlining)]
        public string GetCurrentMethod()
        {
            var st = new StackTrace();
            var sf = st.GetFrame(1);

            return sf.GetMethod().Name + "(Text is '" + textBox1.Text + "')";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            txtLog.Text += (GetCurrentMethod());
            txtLog.Text += "\r\n";
        }

        private void textBox1_Validating(object sender, CancelEventArgs e)
        {
            txtLog.Text += (GetCurrentMethod());
            txtLog.Text += "\r\n";

            if(textBox1.Text.IndexOf('z') >= 0)
            {
                MessageBox.Show("'z' is invalid");
                e.Cancel = true;
            }
        }

        private void textBox1_Validated(object sender, EventArgs e)
        {
            txtLog.Text += (GetCurrentMethod());
            txtLog.Text += "\r\n";
        }
    }
}
