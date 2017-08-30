using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms房屋出租UI
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //点击返回上一级
            Form1 preform1 = new Form1();
            preform1.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //点击创建客房分类查询窗口
            Form23 cxjg = new Form23();
            cxjg.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击创建按房间号查询客房基本信息窗口
            Form24 cxjg = new Form24();
            cxjg.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            //点击创建按类别，每月租金查询客房基本信息窗口
            Form25 cxjg = new Form25();
            cxjg.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //点击创建按身份证号查询客人租房信息窗口
            Form26 cxjg = new Form26();
            cxjg.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            //点击创建按姓/名时间查询客人租房信息窗口
            Form27 cxjg = new Form27();
            cxjg.Show();
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }
    }
}
