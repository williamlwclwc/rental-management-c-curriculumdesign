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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //点击创建删除信息界面
            Form8 delete_type = new Form8();
            delete_type.Show();
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
            //点击创建录入信息界面
            Form6 add_type = new Form6();
            add_type.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击创建修改信息界面
            Form7 edit_type = new Form7();
            edit_type.Show();
        }
    }
}
