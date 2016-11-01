#include "test_case.h"

int main(int argc, char** argv)
{
    TestCase testcase;
	testcase.AddCardCode(1); 
	testcase.AddCardCode(3);
	testcase.AddCardCode(4);
	testcase.AddCardCode(5);
	testcase.AddCardCode(6);
	testcase.AddCardCode(8);
	testcase.AddCardCode(16);
	testcase.AddCardCode(17);
	testcase.AddCardCode(18);
	testcase.AddCardCode(21);
	testcase.AddCardCode(22);
	testcase.AddCardCode(23);
	testcase.AddCardCode(30);

    testcase.CalcWinCards();
    testcase.AutoVerify();

    return 0;
}
