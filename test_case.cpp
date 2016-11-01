#include "time_util.h"
#include "test_case.h"
#include <iostream>

bool TestCase::AddCardCode(int code)
{
    if (code < 1 || code > 30 || code == 10 || code == 20)
    {
        std::cout << "the code must in (1-9, 11-19, 21-29)" << std::endl;
        return false;
    } 
    else if (m_cards.size() > 13)
    {
        std::cout << "the max cards don't exceed 13." << std::endl;
        return false;
    }
    else
    {
        m_cards.push_back(code);
        return true;
    }
}

int TestCase::CalcWinCards()
{
    for (unsigned int i = 0; i < m_cards.size(); i++)
    {
        m_detect.AddCardCode(m_cards[i]);
    }

    m_detect.DumpCards();
	m_detect.DetectDump();
    TimeUtil timer;
    m_detect.DetectWinOne();
    timer.Span();
	m_detect.DumpTing();
    int count = m_detect.GetTingCards(m_ting);
    return count;
}

bool TestCase::AutoVerify()
{
    for (unsigned int i = 0; i < m_cards.size(); i++)
    {
        if (m_cards[i] == 30)
        {
            continue;
        }

        for (unsigned int j = 0; j < m_ting.size(); ++j)
        {
            m_detect.Reset();
            for (unsigned int m = 0; m < i; m++)
            {
                m_detect.AddCardCode(m_cards[m]);
            }
            for (unsigned int n = i+1; n < m_cards.size(); n++)
            {
                m_detect.AddCardCode(m_cards[n]);
            }
            std::cout << "------------------------------------------------------------------------" << std::endl;
            std::cout << "Test Card: " << m_cards[i];
            m_detect.AddCardCode(m_ting[j]);
            m_detect.DumpCards();
            m_detect.DetectDump();
            TimeUtil timer;
            m_detect.DetectWinOne();
            timer.Span();
            m_detect.DumpTing();
            std::vector<int> tinglist;
            int count = m_detect.GetTingCards(tinglist);
            if (count == 0)
            {
                std::cout << "\033[1;31m" << "Card: " << m_ting[j] << " Replace Card: " << m_cards[i] << " TEST FAILED!!!\033[0m" << std::endl;
            }
            else
            {
                bool found = false;
                for (unsigned int k = 0; k < tinglist.size(); k++)
                {
                    if (m_cards[i] == tinglist[k])
                    {
                        found = true;
                        break;
                    }
                }
                if (found)
                {
                    std::cout << "\033[1;32m" << "Card: " << m_ting[j] << " Replace Card: " << m_cards[i] << " TEST PASS!!!" << "\033[0m" << std::endl;
                } else
                {
                    std::cout << "\033[1;31m" << "Card: " << m_ting[j] << " Replace Card: " << m_cards[i] << " TEST FAILED!!!" << "\033[0m" << std::endl;
                }
            }
            std::cout << "------------------------------------------------------------------------" << std::endl;
        }
    }
}
