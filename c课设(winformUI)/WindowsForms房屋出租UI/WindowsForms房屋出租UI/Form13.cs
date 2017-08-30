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
    public partial class Form13 : Form
    {
        public Form13()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //取消返回上一级窗口
            Form2 sjwhform = new Form2();
            sjwhform.Show();
            this.Hide();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //点击创建录入信息窗口
            Form14 add_type = new Form14();
            add_type.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击创建修改信息窗口
            Form15 edit_basic = new Form15();
            edit_basic.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            MessageBox.Show("删除功能一次仅能删除一条信息，删除多次租房客人信息，请进行多次删除操作", "删除操作提示");
            //点击创建删除信息窗口
            Form16 delete_basic = new Form16();
            delete_basic.Show();
        }
    }
}
