// https://cpprefjp.github.io/reference/tuple/tie.html
#include <iostream>
#include <tuple>
#include <string>

int main1()
{
  // 変数への参照を持つtupleを作る
  {
    int a = 1;
    char b = 'a';
    std::string c = "Hello";

    std::tuple<int&, char&, std::string&> t = std::tie(a, b, c);
  }

  // タプルから要素をまとめて取り出す
  {
    std::tuple<int, char, std::string> t(1, 'a', "Hello");

    int a = 0;
    char b = 0;
    std::string c;
    std::tie(a, b, c) = t;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
  }
  std::cout << std::endl;
  // タプルから要素をまとめて取り出し、一部要素を無視する
  {
    std::tuple<int, char, std::string> t(1, 'a', "Hello");

    int a = 0;
    std::string c;
    std::tie(a, std::ignore, c) = t; // 'a'は無視して1と"Hello"だけ取り出す

    std::cout << a << std::endl;
    std::cout << c << std::endl;
  }
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

struct File {
  std::string type;
  std::string name;

  File(const std::string& type, const std::string& name)
      : type(type), name(name) {}
};

bool operator<(const File& a, const File& b)
{
  // ファイル種別、ファイル名の順番で優先順位を付けて比較
  // 1. typeを比較する
  // 2. typeでどちらかが小さいか判断できればその結果を返す
  // 3. typeが等値であれば、nameを比較する
  return std::tie(a.type, a.name) < std::tie(b.type, b.name);
}

int main2()
{
  std::vector<File> files = {
    {"text", "b.txt"},
    {"application", "b.exe"},
    {"application", "a.exe"},
    {"text", "a.txt"}
  };

  // 並べ替え
  std::sort(files.begin(), files.end());

  for (const File& file : files) {
    std::cout << file.type << ", " << file.name << std::endl;
  }
}

int main()
{
    main1();
    main2();
}
