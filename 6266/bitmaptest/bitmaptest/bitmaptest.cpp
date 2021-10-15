#include <Windows.h>
#include <iostream>
#include "analyze.h"
using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    HDC hDC = GetDC(NULL);

    // color bits
    // How much color 1 bit can show. Power of 2
    int bitPixel = GetDeviceCaps(hDC, BITSPIXEL);
    cout << "bitPixel=" << bitPixel << endl;

    // Width, in pixels, of the screen; or for printers, the width, in pixels,
    // of the printable area of the page.
    int horzRes = GetDeviceCaps(hDC, HORZRES);
    
    // Width, in millimeters, of the physical screen
    int horzSize = GetDeviceCaps(hDC, HORZSIZE);
    int rez = horzRes / horzSize;

    // Number of entries in the device's color table, if the device has a color depth
    // of no more than 8 bits per pixel. For devices with greater color depths, 1 is returned.
    int numColors = GetDeviceCaps(hDC, NUMCOLORS);

    CBitmap bmp("Redbrick.bmp");
    return 0;
}

