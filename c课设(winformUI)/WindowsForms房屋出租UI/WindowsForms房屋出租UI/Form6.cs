using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;

namespace WindowsForms房屋出租UI
{
    public partial class Form6 : Form
    {
        [DllImport("c课设信息录入.dll",EntryPoint = "?Rtype_add@@YAXDHHH@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static void Rtype_add(char rt , int max, int suite_no, int rfree);
        public Form6()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭此窗口
            this.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            /*//将用户在界面中输入的数据存入文件中
            StreamWriter sw = new StreamWriter("客房类别信息.txt", true);
            sw.Write(comboBox1.Text);
            sw.Write(textBox2.Text + " ");
            sw.Write(textBox3.Text + " ");
            sw.Write(textBox4.Text);
            sw.Dispose();
            this.comboBox1.Text = "";
            this.textBox2.Text = "";
            this.textBox3.Text = "";
            this.textBox4.Text = "";*/
            if (MessageBox.Show("确定要录入信息吗？", "录入操作确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                //点击ok录入信息
                char rt = Convert.ToChar(comboBox1.Text);
                int max = Convert.ToInt32(textBox2.Text);
                int suite_no = Convert.ToInt32(textBox3.Text);
                int rfree = Convert.ToInt32(textBox4.Text);
                Rtype_add(rt, max, suite_no, rfree);
                MessageBox.Show("录入完成", "客房类别信息");
                Close();//存储完毕后关闭窗口
            }
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
