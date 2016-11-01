#include "detect_win.h"
#include <vector>

class TestCase
{
    public:
        TestCase() {}
        ~TestCase() {}

        bool AddCardCode(int code);
        int CalcWinCards();

        bool AutoVerify();

    private:
        std::vector<int> m_cards;
        std::vector<int> m_ting;
        DetectWin m_detect;
};
