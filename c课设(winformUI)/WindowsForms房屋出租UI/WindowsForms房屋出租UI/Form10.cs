using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms房屋出租UI
{
    public partial class Form10 : Form
    {
        [DllImport("c课设信息录入.dll", EntryPoint = "?Basic_add@@YAXPADDMMDD@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static void Basic_add(string room_no, char rt, float s, float rent, char balcony, char occupied);
        public Form10()
        {
            InitializeComponent();
            MaximizeBox = false;
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
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确定要录入信息吗？", "录入操作确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                /*//将用户界面输入的信息写入文件
                StreamWriter sw = new StreamWriter("客房基本信息.txt", true);
                sw.Write(textBox5.Text+"\r\n");
                sw.Write(textBox4.Text + "\r\n");
                sw.Write(comboBox3.Text);
                sw.Write(textBox2.Text+" ");
                sw.Write(textBox1.Text+" ");
                sw.Write(comboBox2.Text);
                sw.Write(comboBox1.Text);
                sw.Dispose();
                textBox5.Text = "";
                textBox4.Text = "";
                comboBox3.Text = "";
                textBox2.Text = "";
                textBox1.Text = "";
                comboBox2.Text = "";
                comboBox1.Text = "";*/
                if (textBox5.Text.Length>3 || textBox5.Text == "")
                {
                    MessageBox.Show("客房编号未输入或超过三位数", "录入失败");
                }
                else if(comboBox3.Text == "" || textBox2.Text == "" || textBox1.Text == "" || comboBox2.Text == "" || comboBox1.Text == "")
                {
                    MessageBox.Show("录入信息不能为空", "录入失败");
                }
                else
                {
                    string room_no = textBox5.Text;
                    char rt = Convert.ToChar(comboBox3.Text);
                    float s = Convert.ToSingle(textBox2.Text);
                    float rent = Convert.ToSingle(textBox1.Text);
                    char balcony = Convert.ToChar(comboBox2.Text);
                    char occupied = Convert.ToChar(comboBox1.Text);
                    Basic_add(room_no, rt, s, rent, balcony, occupied);
                    MessageBox.Show("录入完成", "客房基本信息");
                    Close();//录入后关闭窗口
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            textBox4.Text = "8" + textBox5.Text;
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }


        private void comboBox3_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
