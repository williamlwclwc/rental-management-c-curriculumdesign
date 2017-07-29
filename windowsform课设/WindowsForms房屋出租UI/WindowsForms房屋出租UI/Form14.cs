using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms房屋出租UI
{
    public partial class Form14 : Form
    {
        public Form14()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭该窗口
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //将用户界面输入数据写入文件
            StreamWriter sw = new StreamWriter("D:\\liuwenchang\\编程\\c语言\\c课设\\windowsform课设\\客人租房信息.txt", true, System.Text.Encoding.GetEncoding("GB2312"));
            sw.Write(textBox1.Text + "\r\n");
            sw.Write(textBox2.Text + "\r\n");
            sw.Write(textBox3.Text + "\r\n");
            sw.Write(textBox4.Text + "\r\n");
            sw.Write(textBox5.Text + "\r\n");
            sw.Write(textBox6.Text + " ");
            sw.Write(textBox7.Text + " ");
            sw.Write(textBox8.Text + " ");
            sw.Write(textBox9.Text + " ");
            sw.Dispose();
            textBox1.Text = "";
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
            textBox5.Text = "";
            textBox6.Text = "";
            textBox7.Text = "";
            textBox8.Text = "";
            textBox9.Text = "";
            this.Close();
        }
    }
}
