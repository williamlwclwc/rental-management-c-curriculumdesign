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
    public partial class Form25 : Form
    {
        public Form25()
        {
            InitializeComponent();
            MaximizeBox = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (comboBox1.Text != "" && textBox2.Text != "")
            {
                //将输入的信息写入“函数参数.txt”
                StreamWriter sw = new StreamWriter("函数参数.txt", false, System.Text.Encoding.GetEncoding("GB2312"));
                sw.Write(comboBox1.Text + "\r\n");
                sw.Write(textBox2.Text);
                sw.Dispose();
                this.comboBox1.Text = "";
                //调用c程序：客房基本信息查询（按类别和每月租金）
                Process myProcess = new Process();

                string fileName = @"c课设c语言部分.exe";

                ProcessStartInfo myProcessStartInfo = new ProcessStartInfo(fileName, "8");

                myProcess.StartInfo = myProcessStartInfo;

                myProcess.Start();

                while (!myProcess.HasExited)

                {

                    myProcess.WaitForExit();

                }

                int returnValue = myProcess.ExitCode;
                //新建一个窗口，并在窗口打开c程序写好的过的结果文件
                Form17 cxjg = new Form17();
                cxjg.Show();
            }
            else
            {
                MessageBox.Show("请正确输入参数", "参数错误");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //点击关闭该窗口
            Close();
        }
    }
}
