﻿using System;
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
    public partial class Form11 : Form
    {
        public Form11()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭该窗口
            this.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("确定要修改信息吗？", "修改操作确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                if (textBox1.Text != "" && comboBox1.Text != "" && textBox2.Text != "")
                {
                    //将用户界面中输入的参数写入文件中，编码采用与c一致的GB2312
                    StreamWriter sw = new StreamWriter("函数参数.txt", false, System.Text.Encoding.GetEncoding("GB2312"));
                    sw.Write(textBox1.Text + "\r\n");
                    sw.Write(comboBox1.Text + "\r\n");
                    sw.Write(textBox2.Text);
                    sw.Dispose();
                    this.comboBox1.Text = "";
                    this.textBox2.Text = "";
                    this.textBox1.Text = "";
                    //调用c程序处理数据，将结果重写回文件中
                    Process myProcess = new Process();

                    string fileName = @"c课设c语言部分.exe";

                    ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(fileName, "3");//case3为c中修改基本信息

                    myProcess.StartInfo = myProcessStartInfo;

                    myProcess.Start();

                    while (!myProcess.HasExited)

                    {

                        myProcess.WaitForExit();

                    }

                    int returnValue = myProcess.ExitCode;
                    MessageBox.Show("修改完成", "客房基本信息");
                    Close();
                }
                else
                {
                    MessageBox.Show("修改参数未填写完整", "修改失败");
                }
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
