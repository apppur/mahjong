#include "detect_win.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>

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
	detect.AddCardCode(1); 
	detect.AddCardCode(3);
	detect.AddCardCode(4);
	detect.AddCardCode(5);
	detect.AddCardCode(6);
	detect.AddCardCode(8);
	detect.AddCardCode(16);
	detect.AddCardCode(17);
	detect.AddCardCode(18);
	detect.AddCardCode(21);
	detect.AddCardCode(22);
	detect.AddCardCode(23);
	detect.AddCardCode(30);
    detect.DumpCards();
	detect.DetectDump();
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
	detect.DetectWinOne();
    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
	detect.DumpTing();
    std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
    std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;

    {
        detect.Reset();
        detect.AddCardCode(3); 
        detect.AddCardCode(4);
        detect.AddCardCode(5);
        detect.AddCardCode(7);
        detect.AddCardCode(8);
        detect.AddCardCode(12);
        detect.AddCardCode(12);
        detect.AddCardCode(25);
        detect.AddCardCode(26);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(4);
        detect.AddCardCode(5);
        detect.AddCardCode(7);
        detect.AddCardCode(8);
        detect.AddCardCode(9);
        detect.AddCardCode(15);
        detect.AddCardCode(16);
        detect.AddCardCode(17);
        detect.AddCardCode(22);
        detect.AddCardCode(23);
        detect.AddCardCode(24);
        detect.AddCardCode(25);
        detect.AddCardCode(25);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(1); 
        detect.AddCardCode(1);
        detect.AddCardCode(6);
        detect.AddCardCode(6);
        detect.AddCardCode(14);
        detect.AddCardCode(16);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(1); 
        detect.AddCardCode(1);
        detect.AddCardCode(6);
        detect.AddCardCode(6);
        detect.AddCardCode(16);
        detect.AddCardCode(17);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(4);
        detect.AddCardCode(5);
        detect.AddCardCode(6);
        detect.AddCardCode(7);
        detect.AddCardCode(8);
        detect.AddCardCode(11);
        detect.AddCardCode(11);
        detect.AddCardCode(12);
        detect.AddCardCode(12);
        detect.AddCardCode(27);
        detect.AddCardCode(28);
        detect.AddCardCode(29);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }

    {
        detect.Reset();
        detect.AddCardCode(2);
        detect.AddCardCode(4);
        detect.AddCardCode(15);
        detect.AddCardCode(18);
        detect.AddCardCode(18);
        detect.AddCardCode(24);
        detect.AddCardCode(24);
        detect.AddCardCode(27);
        detect.AddCardCode(28);
        detect.AddCardCode(29);
        detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(12);
        detect.AddCardCode(14);
        detect.AddCardCode(15);
        detect.AddCardCode(17);
        detect.AddCardCode(19);
        detect.AddCardCode(19);
        detect.AddCardCode(21);
        detect.AddCardCode(22);
        detect.AddCardCode(25);
        detect.AddCardCode(26);
        detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(15);
        detect.AddCardCode(16);
        detect.AddCardCode(16);
        detect.AddCardCode(16);
        detect.AddCardCode(18);
        detect.AddCardCode(19);
        //detect.AddCardCode(21);
        detect.AddCardCode(22);
        detect.AddCardCode(23);
        detect.AddCardCode(26);
        detect.AddCardCode(27);
        detect.AddCardCode(28);
        detect.AddCardCode(30);
        //detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(7);
        detect.AddCardCode(8);
        detect.AddCardCode(12);
        detect.AddCardCode(13);
        detect.AddCardCode(14);
        detect.AddCardCode(15);
        detect.AddCardCode(15);
        //detect.AddCardCode(21);
        detect.AddCardCode(23);
        detect.AddCardCode(24);
        detect.AddCardCode(26);
        detect.AddCardCode(26);
        detect.AddCardCode(26);
        detect.AddCardCode(30);
        //detect.AddCardCode(30);
        //detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(4);
        detect.AddCardCode(5);
        detect.AddCardCode(6);
        detect.AddCardCode(13);
        detect.AddCardCode(14);
        detect.AddCardCode(16);
        detect.AddCardCode(17);
        detect.AddCardCode(18);
        //detect.AddCardCode(21);
        detect.AddCardCode(27);
        detect.AddCardCode(27);
        detect.AddCardCode(28);
        detect.AddCardCode(28);
        detect.AddCardCode(30);
        //detect.AddCardCode(30);
        //detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(4);
        detect.AddCardCode(5);
        detect.AddCardCode(6);
        detect.AddCardCode(14);
        detect.AddCardCode(16);
        detect.AddCardCode(17);
        detect.AddCardCode(18);
        //detect.AddCardCode(21);
        detect.AddCardCode(28);
        detect.AddCardCode(28);
        detect.AddCardCode(30);
        //detect.AddCardCode(30);
        //detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
    {
        detect.Reset();
        detect.AddCardCode(5);
        detect.AddCardCode(13);
        detect.AddCardCode(14);
        detect.AddCardCode(16);
        detect.AddCardCode(17);
        detect.AddCardCode(18);
        detect.AddCardCode(19);
        //detect.AddCardCode(21);
        //detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.AddCardCode(30);
        detect.DumpCards();
        detect.DetectDump();
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        detect.DetectWinOne();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        detect.DumpTing();
        std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout << "Calc win cost :" << time_span.count() << " seconds" << std::endl;
    }
	//goto Repeat;

	return 0;
}
