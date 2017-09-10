using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsForms房屋出租UI
{
    public partial class Form12 : Form
    {
        public Form12()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭该窗口
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确定要删除信息吗？", "删除操作确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                if (textBox1.Text != "")
                {
                    //将用户界面输入参数写入文件中
                    StreamWriter sw = new StreamWriter("函数参数.txt");
                    sw.Write(textBox1.Text);
                    sw.Dispose();
                    this.textBox1.Text = "";
                    //调用c程序处理，并将结果重写入文件
                    Process myProcess = new Process();

                    string fileName = @"c课设c语言部分.exe";

                    ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(fileName, "2");//case2为c中删除基本信息功能

                    myProcess.StartInfo = myProcessStartInfo;

                    myProcess.Start();

                    while (!myProcess.HasExited)

                    {

                        myProcess.WaitForExit();

                    }

                    int returnValue = myProcess.ExitCode;
                    MessageBox.Show("删除完成", "客房基本信息");
                    Close();
                }
                else
                {
                    MessageBox.Show("删除参数未填写", "删除失败");
                }
            }
        }
    }
}
