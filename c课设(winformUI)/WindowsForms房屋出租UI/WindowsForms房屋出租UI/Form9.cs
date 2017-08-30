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
    public partial class Form9 : Form
    {
        public Form9()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //点击返回上一级菜单
            Form2 sjwhform = new Form2();
            sjwhform.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //点击创建录入信息窗口
            Form10 add_basic = new Form10();
            add_basic.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击创建修改信息窗口
            Form11 edit_basic = new Form11();
            edit_basic.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //点击创建删除信息窗口
            Form12 delete_basic = new Form12();
            delete_basic.Show();
        }
    }
}
