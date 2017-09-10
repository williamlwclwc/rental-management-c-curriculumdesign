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
    public partial class Form8 : Form
    {
        public Form8()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭该窗口
            this.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确定要删除信息吗？", "删除操作确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                if (comboBox1.Text != "")
                {
                    //将用户界面中输入参数写入文件中
                    StreamWriter sw = new StreamWriter("函数参数.txt");
                    sw.Write(comboBox1.Text);
                    sw.Dispose();
                    this.comboBox1.Text = "";
                    //调用c程序处理数据并重写回文件中
                    Process myProcess = new Process();

                    string fileName = @"c课设c语言部分.exe";

                    ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(fileName, "0");//case0为c中删除分类信息部分

                    myProcess.StartInfo = myProcessStartInfo;

                    myProcess.Start();

                    while (!myProcess.HasExited)

                    {

                        myProcess.WaitForExit();

                    }

                    int returnValue = myProcess.ExitCode;
                    MessageBox.Show("删除完成", "客房类别信息");
                    Close();
                }
                else
                {
                    MessageBox.Show("请检查删除参数是否正确", "删除失败");
                }
            }
        }
    }
}
