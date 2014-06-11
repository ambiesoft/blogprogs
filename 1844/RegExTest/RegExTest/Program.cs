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
            // "abcdef"の中に"abc"があればTrue
            if(Regex.IsMatch("abcdef", "abc"))
            {
                Console.WriteLine("True");
            }


            // 大文字小文字は区別されるのでFalse
            if (Regex.IsMatch("abcdef", "ABC"))
            {
                Console.WriteLine("True");
            }

            // IgnoreCaseをつければTrue
            if (Regex.IsMatch("abcdef", "ABC", RegexOptions.IgnoreCase))
            {
                Console.WriteLine("True");
            }


            // aで始まっていればTrue
            if (Regex.IsMatch("abcdef", @"^a"))
            {
                Console.WriteLine("True");
            }
            if (Regex.IsMatch("bcdef", @"^a"))
            {
                Console.WriteLine("True");
            }


            // fで終わっていればTrue
            if (Regex.IsMatch("abcdef", @"f$"))
            {
                Console.WriteLine("True");
            }
            if (Regex.IsMatch("abcde", @"f$"))
            {
                Console.WriteLine("True");
            }


            // aで始まってfで終わっていればTrue
            // .は任意の一文字
            // *は一つ前の文字の０個以上の任意の文字列
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


            // 検索で何個見つかったか調べる
            MatchCollection mc;
            mc = Regex.Matches("abcdef", "abc");
            Console.WriteLine(mc.Count); // 1

            mc = Regex.Matches("abcdefabcdef", "abc");
            Console.WriteLine(mc.Count); // 2

            mc = Regex.Matches("123458", "abc");
            Console.WriteLine(mc.Count); // 0


            // 文字列の中のabcをxxxに変換
            string s;
            s = Regex.Replace("abcdef", "abc", "xxx");
            Console.WriteLine(s); // "xxxdef"

            s = Regex.Replace("abcabcdef", "abc", "xxx");
            Console.WriteLine(s); // "xxxxxxdef"

            s = Regex.Replace("12345", "abc", "xxx");
            Console.WriteLine(s); // "12345"


            // 文字列の中のabcを大文字小文字を逆にして変換
            s = Regex.Replace("abcdef", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "ABCdef"
            s = Regex.Replace("zzzABCzzz", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "zzzabczzz"
            s = Regex.Replace("zzzAbCzzz", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "zzzaBczzz"
            s = Regex.Replace("abcAbcAAAAABcceAbcabcAbC", "abc", trans, RegexOptions.IgnoreCase);
            Console.WriteLine(s); // "ABCaBCAAAAabCceaBCABCaBc"


            // 文字列の中の\nを改行、\tをタブ、\\を\に変換
            s = Regex.Replace(@"aaa\nbbb\nccc", @"\\.", trans2);
            Console.WriteLine(s);   // aaa
                                    // bbb
                                    // ccc
            s = Regex.Replace(@"\\", @"\\.", trans2);
            Console.WriteLine(s);   // \


            // パターンが決まっている場合はあらかじめコンパイルしておく、下は上と同じ
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
