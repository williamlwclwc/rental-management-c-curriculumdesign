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
            MaximizeBox = false;
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
            if (MessageBox.Show("确定退出系统吗？", "退出确认", MessageBoxButtons.OKCancel,MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                //点击ok退出程序
                Application.Exit();
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击创建数据查询窗口
            MessageBox.Show("请务必先在“数据维护->录入信息”录入好全部基本信息后再进行相关查询！" + "\r\n" + "  点击确定开始查询", "使用须知");
            Form3 sjcxform = new Form3();
            sjcxform.Show();
            this.Hide();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //点击创建数据统计窗口
            MessageBox.Show("请务必先在“数据维护->录入信息”录入好全部基本信息后再进行相关统计统计！" + "\r\n" + "  点击确定开始统计", "使用须知");
            Form4 sjtjform = new Form4();
            sjtjform.Show();
            this.Hide();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
                
        }
    }
}
