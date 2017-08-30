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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //点击创建统计年度客房收入，入住月数，入住率的窗口
            Form20 cs = new Form20();
            cs.Show();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //统计累计入住月数最多的10个客人
            Form21 cs = new Form21();
            cs.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            //点击返回上一级界面
            Form1 preform1 = new Form1();
            preform1.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //点击创建统计每类客房数，入住非入住数窗口
            Form18 cs = new Form18();
            cs.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击创建统计年度各类营业额窗口
            Form19 cs = new Form19();
            cs.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //点击创建统计租户欠费情况窗口
            Form22 cs = new Form22();
            cs.Show();
        }
    }
}
