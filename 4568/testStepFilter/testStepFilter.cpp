
#include "stdafx.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;


// Create "%USERPROFILE%\My Documents\Visual Studio 2017\Visualizers\.natstepfilter" with xml content below.
/***********
<?xml version="1.0" encoding="utf-8"?>
<StepFilter xmlns="http://schemas.microsoft.com/vstudio/debugger/natstepfilter/2010">

<Function><Name>operator new</Name><Action>NoStepInto</Action></Function>
<Function><Name>operator delete</Name><Action>NoStepInto</Action></Function>
<!-- Skip everything in std -->
<Function><Name>std::.*</Name><Action>NoStepInto</Action></Function>
<!-- all methods on WebKit OwnPtr and variants, ... WTF::*Ptr<*>::* -->
<!-- <Function><Name>WTF::.*Ptr&lt;.*&gt;::.*</Name><Action>NoStepInto</Action></Function> -->

</StepFilter>
************/


int main()
{
	// if the step filter is enabled, stepping into string ctor will be disabled.
	string s;
	s = "aaa";
	s.append("bbb");

	cout << s << endl;

    return 0;
}

