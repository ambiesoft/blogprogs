#include <iostream>
#include <locale>

using namespace std;
void printfloat()
{
    printf("%g\n", 12345.54321);
}
void cfunc()
{
    setlocale(LC_ALL, "");
    printf("LC_ALL:%s\n", setlocale(LC_ALL,NULL));
    printf("LC_CTYPE:%s\n", setlocale(LC_CTYPE,NULL));

    setlocale(LC_ALL, "C");
    printf("LC_ALL:%s\n", setlocale(LC_ALL,NULL));
    printf("LC_CTYPE:%s\n", setlocale(LC_CTYPE,NULL));

    setlocale(LC_ALL, "C");


    setlocale(LC_ALL, "en");
    printfloat();

    setlocale(LC_ALL, "fr");
    printfloat();

    setlocale(LC_ALL, "de");
    printfloat();
 }
int main()
{
    cfunc();
  std::cout.imbue(std::locale::classic());
  std::cout << 1234.5 << std::endl;
  // std::cout.imbue(std::locale("en_US"));
  std::cout.imbue(std::locale("en"));
  std::cout << 1234.5 << std::endl;
  std::cout.imbue(std::locale("de"));
  std::cout << 1234.5 << std::endl;

  std::cout.imbue(std::locale::classic());
  std::cout << 1234.5 << std::endl;
}
