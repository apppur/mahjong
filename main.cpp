#include "detect_win.h"
#include <iostream>

int main(int argc, char** argv)
{
	std::cout << "Please enter a integer one integer(1-9, 11-19,21-29) at a time:" << std::endl;
	DetectWin detect;
//Repeat:
//	int code;
//	int count = 0;
//	while (!std::cin.eof())
//	{
//		std::cin >> code;
//		if (code < 1 || code == 10 || code == 20 || code > 30)
//		{
//			std::cout << "Please enter a integer one integer(1-9, 11-19,21-29)" << std::endl;
//			goto Repeat;
//		}
//		if (detect.AddCardCode(code))
//		{
//			goto Repeat;
//		}
//		else
//		{
//			std::cout << "Please enter a integer one integer(1-9, 11-19,21-29). the more time is four." << std::endl;
//			goto Repeat;
//		}
//	}
	detect.AddCardCode(14); 
	detect.AddCardCode(15);
	detect.AddCardCode(15);
	detect.AddCardCode(16);
	detect.AddCardCode(16);
	detect.AddCardCode(22);
	detect.AddCardCode(23);
	detect.AddCardCode(24);
	detect.AddCardCode(25);
	detect.AddCardCode(25);
	detect.AddCardCode(28);
	detect.AddCardCode(29);
	detect.AddCardCode(30);
    detect.DumpCards();
	detect.DetectDump();
	detect.DetectWinOne();
	detect.DumpTing();
	//goto Repeat;

	return 0;
}
