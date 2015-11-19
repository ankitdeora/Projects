using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace collision
{
    public partial class Form1 : Form
    {
        int i = 51234536;
        bool left = true;
        string j;
        string k = "the cat is faster than the dog";
        //bool right;

        public Form1()
        {
            j = i.ToString();
            //Console.WriteLine(j.GetType());
            //Console.WriteLine(i.GetType());
            Console.WriteLine("datatypes are j->{0}, i->{1}",j.GetTypeCode(),i.GetTypeCode());
            Console.WriteLine(k.Trim());
            
            InitializeComponent();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (left) { player.BackColor = Color.Red; }
            else { player.BackColor = Color.Green; }

            left = !left;
      
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Right) { player.Left += 5; };
            if (e.KeyCode == Keys.Left) { player.Left -= 5;};
            if (e.KeyCode == Keys.Up) { player.Top -= 5; };
            if (e.KeyCode == Keys.Down) { player.Top += 5; };
           
        }
    }
}
