using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class Form1 : Form
    {
        Stack<double> numStack = new Stack<double>();
        Stack<char> operatorStack = new Stack<char>();
        int afterPeriodCount = 0;
        bool previouslyBinaryOpUpdated = true;

        public Form1()
        {
            InitializeComponent();
        }

        public bool updateStacks(double number = -1,char binaryOperator = '$',bool periodFlag = false )
        {
            if (number != -1)
            {
                if (!previouslyBinaryOpUpdated)
                {
                    double previous = numStack.Pop();
                    numStack.Push(previous * 10 + number);
                }
                else
                {
                    numStack.Push(number);
                }
                previouslyBinaryOpUpdated = false;
            }

            if (binaryOperator != '$')
            {
                if (binaryOperator == ')')
                {
                    if (operatorStack.Count != 0)
                    {
                        char lastOperator = operatorStack.Pop();
                        double B = numStack.Pop();
                        double A = numStack.Pop();

                        switch (lastOperator)
                        {
                            case '+':
                                numStack.Push(A + B);
                                break;
                            case '-':
                                numStack.Push(A - B);
                                break;
                            case '*':
                                numStack.Push(A * B);
                                break;
                            case '/':
                                numStack.Push(A / B);
                                break;
                            default:
                                Console.WriteLine("invalid operator detected");
                                break;
                        }

                        previouslyBinaryOpUpdated = false;
                    }
                }
                else
                {
                    if (!previouslyBinaryOpUpdated)
                    {
                        operatorStack.Push(binaryOperator);
                        previouslyBinaryOpUpdated = true;
                    }
                }
            }

            if (periodFlag)
            {
                afterPeriodCount++;
                previouslyBinaryOpUpdated = false;
            }

            return true;
        }
        public void updateOutput()
        {
            // utility not decided
            // string input = textBox.Text;
            // Console.WriteLine(input);
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            textBox.Text += "1";
            updateStacks(number: 1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            textBox.Text += "2";
            updateStacks(number: 2);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox.Text += "3";
            updateStacks(number: 3);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox.Text += "4";
            updateStacks(number: 4);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            textBox.Text += "5";
            updateStacks(number: 5);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            textBox.Text += "6";
            updateStacks(number: 6);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            textBox.Text += "7";
            updateStacks(number: 7);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            textBox.Text += "8";
            updateStacks(number: 8);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            textBox.Text += "9";
            updateStacks(number: 9);
        }

        private void button0_Click(object sender, EventArgs e)
        {
            textBox.Text += "0";
            updateStacks(number: 0);
        }

        private void buttonPeriod_Click(object sender, EventArgs e)
        {
            textBox.Text += ".";
            updateStacks(periodFlag: true);
        }

        private void buttonPlus_Click(object sender, EventArgs e)
        {
            textBox.Text += "+";
            updateStacks(binaryOperator: '+');
        }

        private void buttonMinus_Click(object sender, EventArgs e)
        {
            textBox.Text += "-";
            updateStacks(binaryOperator: '-');
        }

        private void buttonMultiply_Click(object sender, EventArgs e)
        {
            textBox.Text += "*";
            updateStacks(binaryOperator: '*');
        }

        private void buttonDivide_Click(object sender, EventArgs e)
        {
            textBox.Text += "/";
            updateStacks(binaryOperator: '/');
        }

        private void buttonSin_Click(object sender, EventArgs e)
        {
            textBox.Text += "sin";
        }

        private void buttonCos_Click(object sender, EventArgs e)
        {
            textBox.Text += "cos";
        }

        private void buttonTan_Click(object sender, EventArgs e)
        {
            textBox.Text += "tan";
        }

        private void buttonLog_Click(object sender, EventArgs e)
        {
            textBox.Text += "log";
        }

        private void buttonEquals_Click(object sender, EventArgs e)
        {
            //perform calculations on all stack elements
            textBox.Text = "=" + numStack.Peek().ToString();
        }

        private void buttonClear_Click(object sender, EventArgs e)
        {
            textBox.Clear();
            numStack.Clear();
            operatorStack.Clear();
            previouslyBinaryOpUpdated = true;
            afterPeriodCount = 0;
        }

        private void button_L_bracket_Click(object sender, EventArgs e)
        {
            //do nothing
            textBox.Text += "(";
        }

        private void button_R_bracket_Click(object sender, EventArgs e)
        {
            textBox.Text += ")";
            updateStacks(binaryOperator: ')');
        }

        private void buttonAns_Click(object sender, EventArgs e)
        {
            //no use till now
        }

        private void textBox_KeyPress(object sender, KeyPressEventArgs e)
        {
            switch (e.KeyChar)
            {
                case '1':
                    updateStacks(number: 1);
                    break;
                case '2':
                    updateStacks(number: 2);
                    break;
                case '3':
                    updateStacks(number: 3);
                    break;
                case '4':
                    updateStacks(number: 4);
                    break;
                case '5':
                    updateStacks(number: 5);
                    break;
                case '6':
                    updateStacks(number: 6);
                    break;
                case '7':
                    updateStacks(number: 7);
                    break;
                case '8':
                    updateStacks(number: 8);
                    break;
                case '9':
                    updateStacks(number: 9);
                    break;
                case '0':
                    updateStacks(number: 0);
                    break;
                case '+':
                    updateStacks(binaryOperator: '+');
                    break;
                case '-':
                    updateStacks(binaryOperator: '-');
                    break;
                case '*':
                    updateStacks(binaryOperator: '*');
                    break;
                case '/':
                    updateStacks(binaryOperator: '/');
                    break;
                case ')':
                    updateStacks(binaryOperator: ')');
                    break;
                case (char)13:
                    textBox.Text = "=" + numStack.Peek().ToString();
                    textBox.AppendText("\n");
                    break;
            }
        }

        
    }
}
