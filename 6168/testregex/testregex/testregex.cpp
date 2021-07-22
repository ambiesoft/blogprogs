
#include <iostream>
#include <string>
#include <regex>
using namespace std;

void matchtest1()
{
    // 全体がマッチしているかを調べる
    string hay = "123-456-7890";
    regex re(R"(^\d\d\d-\d\d\d-\d\d\d\d$)");
    smatch result;
    if (regex_search(hay, result, re))
        cout << "match!\n";
}
void searchtest1()
{
    string hay = "123-456-7890";

    // hayから'456' を取得したい
    // 取得したい部分をカッコで括る
    regex re(R"(^\d\d\d-(\d\d\d)-\d\d\d\d)");
    smatch result;

    if (regex_search(hay, result, re))
    {
        // resultの[1]に入っている。
        // [0]は全体
        // カッコをいくつ追加してもいい
        cout << result[1].str() << endl;
    }
}

void replacetest1()
{
    string hay = "123-456-7890";

    // hayの'456'を'abc'に変えたい
    // 変えたい部分は両方に'-'があるのでここを見つけて変える
    regex re(R"(-\d\d\d-)");
    string replaced = regex_replace(hay, re, "-abc-");
    cout << replaced << endl;
}
void replacetest2()
{
    string hay = "123-456-7890";
    // '7890-456-123'に変えたい
    // 変えたい部分をカッコで括る。３つある
    regex re(R"((\d\d\d)-(\d\d\d)-(\d\d\d\d))");
    // カッコで括ったものを$1,$2,$3で参照して組み立てる。
    string replaced = regex_replace(hay, re, "$3-$2-$1");
    cout << replaced << endl;
}
// 上のwchar_tバージョン
void replacetest2w()
{
    wstring hay = L"123-456-7890";
    // '7890-456-123'に変えたい
    // 変えたい部分をカッコで括る。３つある
    wregex re(LR"((\d\d\d)-(\d\d\d)-(\d\d\d\d))");
    // カッコで括ったものを$1,$2,$3で参照して組み立てる。
    wstring replaced = regex_replace(hay, re, L"$3-$2-$1");
    wcout << replaced << endl;
}
int main()
{
    matchtest1();
    searchtest1();
    replacetest1();
    replacetest2();
    replacetest2w();
}
