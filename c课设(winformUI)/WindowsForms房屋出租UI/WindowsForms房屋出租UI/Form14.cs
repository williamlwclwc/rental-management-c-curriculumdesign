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
    public partial class Form14 : Form
    {
        [DllImport("c课设信息录入.dll", EntryPoint = "?Guest_add@@YAXPAD0000MMMM@Z", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi)]
        public extern static void Guest_add(string id, string name, string room_no, string tin, string tout, float staymonth, float deposit, float tpay, float rpay);
        public Form14()
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
            if (MessageBox.Show("确定要录入信息吗？", "录入操作确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question, MessageBoxDefaultButton.Button2) == DialogResult.OK)
            {
                /*//将用户界面输入数据写入文件
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
                textBox9.Text = "";*/
                string id = textBox1.Text;
                string name = textBox2.Text;
                string room_no = textBox3.Text;
                string tin = textBox4.Text;
                string tout = textBox5.Text;
                if(tout=="")
                {
                    tout = "0";
                }
                float staymonth = Convert.ToSingle(textBox6.Text);
                float deposit = Convert.ToSingle(textBox7.Text);
                float tpay = Convert.ToSingle(textBox8.Text);
                float rpay = Convert.ToSingle(textBox9.Text);
                Guest_add(id, name, room_no, tin, tout, staymonth, deposit, tpay, rpay);
                MessageBox.Show("录入完成", "客人租房信息");
                Close();//录入后关闭窗口
            }
        }
    }
}
