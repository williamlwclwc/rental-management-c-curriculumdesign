using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms房屋出租UI
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //点击创建数据维护窗口
            Form2 sjwhform = new Form2();
            sjwhform.Show();
            this.Hide();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //点击退出程序
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击创建数据查询窗口
            Form3 sjcxform = new Form3();
            sjcxform.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //点击创建数据统计窗口
            Form4 sjtjform = new Form4();
            sjtjform.Show();
            this.Hide();
        }
    }
}
