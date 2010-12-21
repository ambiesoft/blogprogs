using System;
using System.Collections.Generic;
using System.Text;
using System.Text.RegularExpressions;

namespace RegExTest
{
    class Program
    {
        static void Main(string[] args)
        {
            // "abcdef"�̒���"abc"�������True
            if(Regex.IsMatch("abcdef", "abc"))
            {
                Console.WriteLine("True");
            }


            // �啶���������͋�ʂ����̂�False
            if (Regex.IsMatch("abcdef", "ABC"))
            {
                Console.WriteLine("True");
            }

            // IgnoreCase�������True
            if (Regex.IsMatch("abcdef", "ABC", RegexOptions.IgnoreCase))
            {
                Console.WriteLine("True");
            }


            // a�Ŏn�܂��Ă����True
            if (Regex.IsMatch("abcdef", @"^a"))
            {
                Console.WriteLine("True");
            }
            if (Regex.IsMatch("bcdef", @"^a"))
            {
                Console.WriteLine("True");
            }


            // f�ŏI����Ă����True
            if (Regex.IsMatch("abcdef", @"f$"))
            {
                Console.WriteLine("True");
            }
            if (Regex.IsMatch("abcde", @"f$"))
            {
                Console.WriteLine("True");
            }


            // a�Ŏn�܂���f�ŏI����Ă����True
            // .�͔C�ӂ̈ꕶ��
            // *�͈�O�̕����̂O�ȏ�̔C�ӂ̕�����
            string pattern = @"^a.*f$";
            if (Regex.IsMatch("abcdef", pattern))
            {
                Console.WriteLine("True");
            }
            if (Regex.IsMatch("abcde", pattern))
            {
                Console.WriteLine("True");
            }
            if (Regex.IsMatch("bcdef", pattern))
            {
                Console.WriteLine("True");
            }
            if (Regex.IsMatch("af", pattern))
            {
                Console.WriteLine("True");
            }


            // �����ŉ��������������ׂ�
            MatchCollection mc;
            mc = Regex.Matches("abcdef", "abc");
            Console.WriteLine(mc.Count); // 1

            mc = Regex.Matches("abcdefabcdef", "abc");
            Console.WriteLine(mc.Count); // 2

            mc = Regex.Matches("123458", "abc");
            Console.WriteLine(mc.Count); // 0


            // ������̒���abc��xxx�ɕϊ�
            string s;
            s = Regex.Replace("abcdef", "abc", "xxx");
            Console.WriteLine(s); // "xxxdef"

            s = Regex.Replace("abcabcdef", "abc", "xxx");
            Console.WriteLine(s); // "xxxxxxdef"

            s = Regex.Replace("12345", "abc", "xxx");
            Console.WriteLine(s); // "12345"


            // ������̒���abc��啶�����������t�ɂ��ĕϊ�
            s = Regex.Replace("abcdef", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "ABCdef"
            s = Regex.Replace("zzzABCzzz", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "zzzabczzz"
            s = Regex.Replace("zzzAbCzzz", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "zzzaBczzz"
            s = Regex.Replace("abcAbcAAAAABcceAbcabcAbC", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "ABCaBCAAAAabCceaBCABCaBc"


            // ������̒���\n�����s�A\t���^�u�A\\��\�ɕϊ�
            s = Regex.Replace(@"aaa\nbbb\nccc", @"\\.", trans2);
            Console.WriteLine(s);   // aaa
                                    // bbb
                                    // ccc
            s = Regex.Replace(@"\\", @"\\.", trans2);
            Console.WriteLine(s);   // \


            // �p�^�[�������܂��Ă���ꍇ�͂��炩���߃R���p�C�����Ă����A���͏�Ɠ���
            Regex r = new Regex(@"\\.");
            s = r.Replace(@"aaa\nbbb\nccc", trans2);
            Console.WriteLine(s);   // aaa
                                    // bbb
                                    // ccc
            s = r.Replace(@"\\", trans2);
            Console.WriteLine(s);   // \
            s = r.Replace(@"\\\n\\\t\\\n\\", trans2);
            Console.WriteLine(s);   // \

        }

        static string trans2(Match m)
        {
            string ret = string.Empty;
            string x = m.ToString();
            if (x == @"\n")
            {
                ret = "\r\n";
            }
            else if (x == @"\t")
            {
                ret = "\t";
            }
            else
            {
                ret = x[1].ToString();
            }

            return ret;
        }

        static string trans(Match m)
        {
            string ret = string.Empty;
            string x = m.ToString();
            foreach (char c in x)
            {
                if (char.IsLower(c))
                {
                    ret += char.ToUpper(c);
                }
                else
                {
                    ret += char.ToLower(c);
                }
            }

            return ret;
        }
    }
}
