#include <iostream>
#include <string>

#if 1
#include <boost/any.hpp>
using boost::any;
using boost::any_cast;
using boost::bad_any_cast;
#else
#include <any>
using std::any;
using std::any_cast;
using std::bad_any_cast;
#endif
// Modified http://faithandbrave.hateblo.jp/entry/2016/07/29/181945
int main()
{
  any a = 3; // int値を代入
  a = std::string("hello"); // stringオブジェクトを代入

  // 中身を取り出す
  // 取り出せなかったらstd::bad_any_cast例外
  try {
    std::string s = any_cast<std::string>(a);
    std::cout << s << std::endl;
  }
  catch (bad_any_cast& e) {
    std::cout << "bad_any_cast: " << e.what() << std::endl;
  }

  // 中身を取り出す
  // こちらは取り出せなかったらヌルポインタが返る
  if (std::string* s = any_cast<std::string>(&a)) {
    std::cout << *s << std::endl;
  }
  else {
    std::cout << "null" << std::endl;
  }
}
