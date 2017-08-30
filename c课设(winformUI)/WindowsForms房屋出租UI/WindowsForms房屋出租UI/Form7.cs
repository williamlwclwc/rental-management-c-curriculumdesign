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
using System.Diagnostics;

namespace WindowsForms房屋出租UI
{
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭此窗口
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确定要修改信息吗？", "修改操作确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                //点击OK进行修改操作
                //将用户界面输入参数存入文件中，编码选用与c一致的GB2312
                StreamWriter sw = new StreamWriter("函数参数.txt", false, System.Text.Encoding.GetEncoding("GB2312"));
                sw.Write(comboBox1.Text);
                sw.Write(comboBox2.Text + " ");
                sw.Write(textBox1.Text);
                sw.Dispose();
                this.comboBox1.Text = "";
                this.comboBox2.Text = "";
                this.textBox1.Text = "";
                //调用c语言程序处理文件数据并再重写入文件中
                Process myProcess = new Process();

                string fileName = @"c课设c语言部分.exe";

                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(fileName, "1");//case1为c中修改分类信息部分

                myProcess.StartInfo = myProcessStartInfo;

                myProcess.Start();

                while (!myProcess.HasExited)

                {

                    myProcess.WaitForExit();

                }

                int returnValue = myProcess.ExitCode;
                MessageBox.Show("修改完成", "客房分类信息");
                Close();
            }
        }
    }
}
