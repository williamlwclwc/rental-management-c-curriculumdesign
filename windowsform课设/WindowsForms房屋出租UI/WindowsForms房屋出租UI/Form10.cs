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
    public partial class Form10 : Form
    {
        public Form10()
        {
            InitializeComponent();
        }

        private void Form10_Load(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭该窗口
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //将用户界面输入的信息写入文件
            StreamWriter sw = new StreamWriter("客房基本信息.txt", true);
            sw.Write(textBox5.Text+"\r\n");
            sw.Write(textBox4.Text + "\r\n");
            sw.Write(textBox3.Text);
            sw.Write(textBox2.Text+" ");
            sw.Write(textBox1.Text+" ");
            sw.Write(comboBox2.Text);
            sw.Write(comboBox1.Text);
            sw.Dispose();
            textBox5.Text = "";
            textBox4.Text = "";
            textBox3.Text = "";
            textBox2.Text = "";
            textBox1.Text = "";
            comboBox2.Text = "";
            comboBox1.Text = "";
            this.Close();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
