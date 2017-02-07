#include "detect_win_px.h"
#include "stdio.h"

DetectWinPX::DetectWinPX()
{
	m_wang.assign(10, 0);
	m_tong.assign(10, 0);
	m_tiao.assign(10, 0);
    m_adds.assign(5, 0);
	m_hong = 0;
    m_fcai = 0;
    m_bban = 0;
	m_all = false;
	m_win = false;
	m_hongWTT.assign(35, 0);
}

DetectWinPX::~DetectWinPX()
{
}

void DetectWinPX::Reset()
{
	m_wang.assign(10, 0);
	m_tong.assign(10, 0);
	m_tiao.assign(10, 0);
    m_adds.assign(5, 0);
	m_hong = 0;
    m_fcai = 0;
    m_bban = 0;
	m_all = false;
	m_win = false;
    m_ting.clear();
	m_hongWTT.assign(35, 0);
}

void DetectWinPX::AddCard(const CardInfo& card)
{
	if (card.m_type == CARD_WANG)
	{
		++m_wang[card.m_code];
	}
	else if (card.m_type == CARD_TONG)
	{
		++m_tong[card.m_code];
	}
	else if (card.m_type == CARD_TIAO)
	{
		++m_tiao[card.m_code];
	}
	else if (card.m_type == CARD_HONG)
	{
		//++m_hong;
        ++m_adds[card.m_code];
	}
}

bool DetectWinPX::AddCardCode(int code)
{
	int type = code / 10;
	int index = code % 10;
	if (type == CARD_WANG)
	{
		if (m_wang[index] >= 4)
		{
			return false;
		}
		else
		{
			m_wang[index] = m_wang[index] + 1;
			return true;
		}
	}
	if (type == CARD_TONG)
	{
		if (m_tong[index] >= 4)
		{
			return false;
		}
		else
		{
			m_tong[index] = m_tong[index] + 1;
			return true;
		}
	}
	if (type == CARD_TIAO)
	{
		if (m_tiao[index] >= 4)
		{
			return false;
		}
		else
		{
			m_tiao[index] = m_tiao[index] + 1;
			return true;
		}
	}
    if (type == CARD_HONG)
    {
        if (m_adds[index] >= 4)
        {
            return false;
        }
        else
        {
            m_adds[index] = m_adds[index] + 1;
            return true;
        }
    }
	return false;
}

void DetectWinPX::DumpCards()
{
    printf("\n");
    //printf("\n========================================\n");
    printf("WAN:");
    for (unsigned int i = 0; i < m_wang.size(); i++)
    {
        if (m_wang[i] > 0)
        {
            printf("%d%d ", i, m_wang[i]);
        }
    }
    printf("\tTONG:");
    for (unsigned int i = 0; i < m_tong.size(); i++)
    {
        if (m_tong[i] > 0)
        {
            printf("%d%d ", i, m_tong[i]);
        }
    }
    printf("\tTIAO:");
    for (unsigned int i = 0; i < m_tiao.size(); i++)
    {
        if (m_tiao[i] > 0)
        {
            printf("%d%d ", i, m_tiao[i]);
        }
    }
    printf("\tHONG:");
    for (unsigned int i = 0; i < m_adds.size(); i++)
    {
        if (m_adds[i] > 0)
        {
            printf("%d%d ", i, m_adds[i]);
        }
    }
    printf("\n");
    //printf("\tHONG:%d", m_hong);
    //printf("\tFCAI:%d", m_fcai);
    //printf("\tHONG:%d\n", m_bban);
}

void DetectWinPX::AddTingCard(const CardInfo& card)
{
	for (unsigned int i = 0; i < m_ting.size(); ++i)
	{
		if (m_ting[i].m_type == card.m_type && m_ting[i].m_code == card.m_code)
		{
			return;
		}
	}

	m_ting.push_back(card);

	return;
}

void DetectWinPX::TingAllCard()
{
	CardInfo card;
	card.m_type = CARD_WANG;
	for (unsigned int i = 1; i < 10; ++i)
	{
		card.m_code = i;
		AddTingCard(card);
	}
	card.m_type = CARD_TONG;
	for (unsigned int i = 1; i < 10; ++i)
	{
		card.m_code = i;
		AddTingCard(card);
	}
	card.m_type = CARD_TIAO;
	for (unsigned int i = 1; i < 10; ++i)
	{
		card.m_code = i;
		AddTingCard(card);
	}
	m_all = true;
	m_win = true;
	return;
}

int DetectWinPX::EnCodeCard(const CardInfo& card)
{
	int code = card.m_type * 10 + card.m_code;
	return code;
}

CardInfo DetectWinPX::DeCodeCard(int code)
{
	int ctype = code / 10;
	int ccode = code % 10;
	CardInfo card;
	card.m_type = ctype;
	card.m_code = ccode;
	card.m_weight = code;
	return card;
}

int DetectWinPX::GetTingCards(std::vector<int>& cardlist)
{
    int count = 0;
    for (unsigned int i = 0; i < m_ting.size(); ++i)
    {
        int code = EnCodeCard(m_ting[i]);
        cardlist.push_back(code);
        count++;
    }

    return count;
}

void DetectWinPX::DetectDump()
{
	m_hongWTT.assign(35, 0);
	for (unsigned int i = 0; i < m_wang.size(); i++)
	{
		if (m_wang[i] != 0)
		{
			m_hongWTT[i] = m_wang[i];
		}
	}
	for (unsigned int i = 0; i < m_tong.size(); i++)
	{
		if (m_tong[i] != 0)
		{
			m_hongWTT[i + 10] = m_tong[i];
		}
	}
	for (unsigned int i = 0; i < m_tiao.size(); i++)
	{
		if (m_tiao[i] != 0)
		{
			m_hongWTT[i + 20] = m_tiao[i];
		}
	}
    for (unsigned int i = 0; i < m_adds.size(); i++)
    {
        if (m_adds[i] != 0)
        {
            m_hongWTT[i + 30] = m_adds[i];
        }
    }
}

void DetectWinPX::DumpTing()
{
	//printf("\n=======================Current Ting Card================================\n");
    printf("Current Ting: ");
	for (std::vector<CardInfo>::iterator iter = m_ting.begin(); iter != m_ting.end(); ++iter)
	{
		printf("%d%d ", iter->m_type, iter->m_code);
	}
    printf("\n");
	//printf("\n========================================================================\n");
}

bool DetectWinPX::DetectAA()
{
	for (unsigned int i = 0; i < m_hongWTT.size() - 1; i++)
	{
		if (m_hongWTT[i] >= 2)
		{
			return true;
		}
	}

	return false;
}

void DetectWinPX::DetectCard(CardInfo& card, std::vector<int>& cardlist)
{
	int index = card.m_weight;
	if (index < 0 || index >= 35)
	{
		return;
	}
	else
	{
		cardlist[index]++;
	}
}

bool DetectWinPX::DetectWinOne()
{
	//for (unsigned i = WANG_TYPE; i < HONG_TYPE; ++i)
	//{
	//	DetectDivision(i);
	//}
	//if (m_ting.size() > 0)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}

	//DetectAllCard(); 
    //DetectReverse();
	DetectAllCardPX(); 
    return m_win;
}

bool DetectWinPX::DetectDivision(unsigned int type)
{
	if (type > CARD_TIAO || type < CARD_WANG)
		return false;
	int start = type * 10;
	int end = start + 10;

	for (int i = start + 1; i < 10; i++)
	{
		CardInfo card = DeCodeCard(i);
		std::vector<int> cardlist;
		cardlist.assign(m_hongWTT.begin() + start, m_hongWTT.begin() + 10);
		DetectCard(card, cardlist);
		if (RemoveAA(cardlist))
		{
			m_win = true;
			AddTingCard(card);
		}
	}
	return m_win;
}

bool DetectWinPX::DetectAllCard()
{
	for (int i = 1; i < 30; i++)
	{
		if (m_all)
		{
			return true;
		}
		if (i != 10 && i != 20)
		{
			CardInfo card = DeCodeCard(i);
			std::vector<int> cardlist;
			cardlist.assign(m_hongWTT.begin(), m_hongWTT.end());
			DetectCard(card, cardlist);
			if (RemoveAA(cardlist))
			{
				m_win = true;
				if (m_all)
				{
					return m_all;
				}
				AddTingCard(card);
			}
			std::vector<int> cardlistr;
			cardlistr.assign(m_hongWTT.begin(), m_hongWTT.end());
			DetectCard(card, cardlistr);
            if (IsAAA(cardlistr))
            {
                if (RemoveAAR(cardlistr))
                {
                    m_win = true;
                    if (m_all)
                    {
                        return m_all;
                    }
                    AddTingCard(card);
                }
            }
		}
	}

	return m_win;
}

bool DetectWinPX::DetectReverse()
{
	for (int i = 1; i < 30; i++)
	{
		if (m_all)
		{
			return true;
		}
		if (i != 10 && i != 20)
		{
			CardInfo card = DeCodeCard(i);
			std::vector<int> cardlist;
			cardlist.assign(m_hongWTT.begin(), m_hongWTT.end());
			DetectCard(card, cardlist);
			if (ReverseAA(cardlist))
			{
				m_win = true;
				if (m_all)
				{
					return m_all;
				}
				AddTingCard(card);
			}
			std::vector<int> cardlistr;
			cardlistr.assign(m_hongWTT.begin(), m_hongWTT.end());
			DetectCard(card, cardlistr);
            if (IsAAA(cardlistr))
            {
                if (ReverseAAR(cardlistr))
                {
                    m_win = true;
                    if (m_all)
                    {
                        return m_all;
                    }
                    AddTingCard(card);
                }
            }
		}
	}

	return m_win;
}

bool DetectWinPX::RemoveAA(std::vector<int>& cardlist)
{
    bool flag = false;
	if (m_hong >= 1)
	{
		std::vector<int> cardlast;
		cardlast.assign(cardlist.begin(), cardlist.end());
		RemoveAAA(cardlast);
		if (m_hong - 1 > 0)
		{
			RemoveABC(cardlast, m_hong - 1);
		}
		else
		{
			RemoveABC(cardlast);
		}
		std::vector<int> leftlist;
		if (CalcLeftCard(cardlast, leftlist) == 0)
		{
			TingAllCard();
			m_all = true;
			return m_all;
		}
        else if (CalcLeftCard(cardlast, leftlist) == 1)
        {
            flag = true;
        }
        else if (CalcLeftCard(cardlast, leftlist) == 2 && m_hong - 1 == 2)
        {
            flag = true;
        }
	}

    if (!IsPairs(cardlist))
    {
        if (m_hong < 0)
        {
            return false;
        }
        else if (m_hong == 1)
        {
            RemoveAAA(cardlist);
            RemoveABC(cardlist);
            std::vector<int> leftlist;
            if (CalcLeftCard(cardlist, leftlist) == 1)
            {
                CardInfo card = DeCodeCard(leftlist[0]);
                AddTingCard(card);
                return true;
            }
            else {
                return false;
            }
        }
    } 
    else
    {
        for (unsigned int i = 0; i < cardlist.size(); i++)
        {
            if (cardlist[i] >= 2)
            {
                std::vector<int> cardlast;
                cardlast.assign(cardlist.begin(), cardlist.end());
                cardlast[i] -= 2;
                RemoveAAA(cardlast);
                if (m_hong > 0)
                {
                    RemoveABC(cardlast, m_hong);
                }
                else
                {
                    RemoveABC(cardlast);
                }
                bool subflag = true;
                for (std::vector<int>::iterator iter = cardlast.begin(); iter != cardlast.end(); ++iter)
                {
                    if (*iter > 0)
                    {
                        subflag = false;
                        break;
                    }
                }
                flag = flag || subflag;
            }
        }
    }
	return flag;
}

bool DetectWinPX::RemoveAAR(std::vector<int>& cardlist)
{
    bool flag = false;
	if (m_hong >= 1)
	{
		std::vector<int> cardlast;
		cardlast.assign(cardlist.begin(), cardlist.end());
		if (m_hong - 1 > 0)
		{
			RemoveABC(cardlast, m_hong - 1);
		}
		else
		{
			RemoveABC(cardlast);
		}
		RemoveAAA(cardlast);
		std::vector<int> leftlist;
		if (CalcLeftCard(cardlast, leftlist) == 0)
		{
			TingAllCard();
			m_all = true;
			return m_all;
		}
        else if (CalcLeftCard(cardlast, leftlist) == 1)
        {
            flag = true;
        }
        else if (CalcLeftCard(cardlast, leftlist) == 2 && m_hong - 1 == 2)
        {
            flag = true;
        }
	}

    if (!IsPairs(cardlist))
    {
        if (m_hong < 0)
        {
            return false;
        }
        else if (m_hong == 1)
        {
            RemoveABC(cardlist);
            RemoveAAA(cardlist);
            std::vector<int> leftlist;
            if (CalcLeftCard(cardlist, leftlist) == 1)
            {
                CardInfo card = DeCodeCard(leftlist[0]);
                AddTingCard(card);
                return true;
            }
            else {
                return false;
            }
        }
    } 
    else
    {
        for (unsigned int i = 0; i < cardlist.size(); i++)
        {
            if (cardlist[i] >= 2)
            {
                std::vector<int> cardlast;
                cardlast.assign(cardlist.begin(), cardlist.end());
                cardlast[i] -= 2;
                if (m_hong > 0)
                {
                    RemoveABC(cardlast, m_hong);
                }
                else
                {
                    RemoveABC(cardlast);
                }
                RemoveAAA(cardlast);
                bool subflag = true;
                for (std::vector<int>::iterator iter = cardlast.begin(); iter != cardlast.end(); ++iter)
                {
                    if (*iter > 0)
                    {
                        subflag = false;
                        break;
                    }
                }
                flag = flag || subflag;
            }
        }
    }
	return flag;
}

bool DetectWinPX::ReverseAA(std::vector<int>& cardlist)
{
    bool flag = false;
	if (m_hong >= 1)
	{
		std::vector<int> cardlast;
		cardlast.assign(cardlist.begin(), cardlist.end());
		RemoveAAA(cardlast);
		if (m_hong - 1 > 0)
		{
			RemoveCBA(cardlast, m_hong - 1);
		}
		else
		{
			RemoveCBA(cardlast);
		}
		std::vector<int> leftlist;
		if (CalcLeftCard(cardlast, leftlist) == 0)
		{
			TingAllCard();
			m_all = true;
			return m_all;
		}
        else if (CalcLeftCard(cardlast, leftlist) == 1)
        {
            flag = true;
        }
        else if (CalcLeftCard(cardlast, leftlist) == 2 && m_hong - 1 == 2)
        {
            flag = true;
        }
	}

    if (!IsPairs(cardlist))
    {
        if (m_hong < 0)
        {
            return false;
        }
        else if (m_hong == 1)
        {
            RemoveAAA(cardlist);
            RemoveCBA(cardlist);
            std::vector<int> leftlist;
            if (CalcLeftCard(cardlist, leftlist) == 1)
            {
                CardInfo card = DeCodeCard(leftlist[0]);
                AddTingCard(card);
                return true;
            }
            else {
                return false;
            }
        }
    } 
    else
    {
        for (unsigned int i = 0; i < cardlist.size(); i++)
        {
            if (cardlist[i] >= 2)
            {
                std::vector<int> cardlast;
                cardlast.assign(cardlist.begin(), cardlist.end());
                cardlast[i] -= 2;
                RemoveAAA(cardlast);
                if (m_hong > 0)
                {
                    RemoveCBA(cardlast, m_hong);
                }
                else
                {
                    RemoveCBA(cardlast);
                }
                bool subflag = true;
                for (std::vector<int>::iterator iter = cardlast.begin(); iter != cardlast.end(); ++iter)
                {
                    if (*iter > 0)
                    {
                        subflag = false;
                        break;
                    }
                }
                flag = flag || subflag;
            }
        }
    }
	return flag;
}

bool DetectWinPX::ReverseAAR(std::vector<int>& cardlist)
{
    bool flag = false;
	if (m_hong >= 1)
	{
		std::vector<int> cardlast;
		cardlast.assign(cardlist.begin(), cardlist.end());
		if (m_hong - 1 > 0)
		{
			RemoveCBA(cardlast, m_hong - 1);
		}
		else
		{
			RemoveCBA(cardlast);
		}
		RemoveAAA(cardlast);
		std::vector<int> leftlist;
		if (CalcLeftCard(cardlast, leftlist) == 0)
		{
			TingAllCard();
			m_all = true;
			return m_all;
		}
        else if (CalcLeftCard(cardlast, leftlist) == 1)
        {
            flag = true;
        }
        else if (CalcLeftCard(cardlast, leftlist) == 2 && m_hong - 1 == 2)
        {
            flag = true;
        }
	}

    if (!IsPairs(cardlist))
    {
        if (m_hong < 0)
        {
            return false;
        }
        else if (m_hong == 1)
        {
            RemoveCBA(cardlist);
            RemoveAAA(cardlist);
            std::vector<int> leftlist;
            if (CalcLeftCard(cardlist, leftlist) == 1)
            {
                CardInfo card = DeCodeCard(leftlist[0]);
                AddTingCard(card);
                return true;
            }
            else {
                return false;
            }
        }
    } 
    else
    {
        for (unsigned int i = 0; i < cardlist.size(); i++)
        {
            if (cardlist[i] >= 2)
            {
                std::vector<int> cardlast;
                cardlast.assign(cardlist.begin(), cardlist.end());
                cardlast[i] -= 2;
                if (m_hong > 0)
                {
                    RemoveCBA(cardlast, m_hong);
                }
                else
                {
                    RemoveCBA(cardlast);
                }
                RemoveAAA(cardlast);
                bool subflag = true;
                for (std::vector<int>::iterator iter = cardlast.begin(); iter != cardlast.end(); ++iter)
                {
                    if (*iter > 0)
                    {
                        subflag = false;
                        break;
                    }
                }
                flag = flag || subflag;
            }
        }
    }
	return flag;
}

bool DetectWinPX::IsPairs(std::vector<int>& cardlist)
{
	for (unsigned int i = 0; i < cardlist.size(); i++)
    {
        if (cardlist[i] >= 2)
        {
            return true;
        }
    }

    return false;
}

bool DetectWinPX::RemoveAAA(std::vector<int>& cardlist)
{
    int flag = false;
	for (unsigned int i = 0; i < cardlist.size(); i++)
	{
		if (cardlist[i] >= 3)
		{
			cardlist[i] -= 3;
            flag = true;
		}
	}

    return flag;
}

bool DetectWinPX::IsAAA(std::vector<int>& cardlist)
{
    int flag = false;
	for (unsigned int i = 0; i < cardlist.size(); i++)
	{
		if (cardlist[i] >= 3)
		{
            flag = true;
            break;
		}
	}
    return flag;
}


void DetectWinPX::RemoveABC(std::vector<int>& cardlist)
{
	for (unsigned int i = 0; i < cardlist.size();)
	{
		if (i + 2 < cardlist.size())
		{
			if (cardlist[i] > 0 && cardlist[i + 1] > 0 && cardlist[i + 2] > 0)
			{
				cardlist[i] -= 1;
				cardlist[i + 1] -= 1;
				cardlist[i + 2] -= 1;
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
}

void DetectWinPX::RemoveCBA(std::vector<int>& cardlist)
{
    for (int i = (cardlist.size() - 1); i >= 0; )
    {
        if (i >= 2)
        {
            if (cardlist[i] > 0 && cardlist[i-1] > 0 && cardlist[i - 2] > 0)
            {
                cardlist[i] -= 1;
                cardlist[i - 1] -= 1;
                cardlist[i - 2] -= 1;
            }
            else 
            {
                i--;
            }
        } else
        {
            i--;
        }
    }
}

void DetectWinPX::RemoveABC(std::vector<int>& cardlist, int hong)
{
	for (unsigned int i = 0; i < cardlist.size();)
	{
		if (i + 1 < cardlist.size())
		{
			if (i + 2 < cardlist.size() && cardlist[i] > 0 && cardlist[i + 1] > 0 && cardlist[i + 2] > 0)
			{
				cardlist[i] -= 1;
				cardlist[i + 1] -= 1;
				cardlist[i + 2] -= 1;
			} 
            else if (i + 4 < cardlist.size() && cardlist[i] > 0 && cardlist[i+1] == 0 && cardlist[i+2] > 0 && cardlist[i+3] > 0 
                    && cardlist[i+4] >= 2)
            {
                cardlist[i+2] -= 1;
                cardlist[i+3] -= 1;
                cardlist[i+4] -= 1;
            }
			else if (i + 2 < cardlist.size() && cardlist[i] > 0 && cardlist[i + 1] == 0 && cardlist[i + 2] > 0 && hong > 0 && ((i + 1) % 10 != 0))
			{
				cardlist[i] -= 1;
				hong--;
				cardlist[i + 2] -= 1;
			}
			else if (i + 2 < cardlist.size() && cardlist[i] > 0 && cardlist[i + 1] > 0 && cardlist[i + 2] == 0 && hong > 0 && (i % 10 != 0))
			{
				cardlist[i] -= 1;
				cardlist[i + 1] -= 1;
				hong--;
			}
			else if (cardlist[i] > 0 && cardlist[i + 1] > 0 && hong > 0 && ((i + 1) % 10 == 9))
			{
				cardlist[i] -= 1;
				cardlist[i + 1] -= 1;
				hong--;
			}
            else if (cardlist[i]==2 && cardlist[i+1] == 0 && hong > 0)
            {
                cardlist[i] -= 2;
                hong--;
            }
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
	std::vector<int> leftlist;
	int left = CalcLeftCard(cardlist, leftlist);
    if (hong == 1 && left == 2 && leftlist.size() == 1)
    {
        cardlist[leftlist[0]] = 0;
    }
	else if (hong == 2 && left == 1)
	{
		cardlist[leftlist[0]] = 0;
	}
	else if (hong == 3 && left == 0)
	{
		TingAllCard();
		m_win = true;
	}
}

void DetectWinPX::RemoveCBA(std::vector<int>& cardlist, int hong)
{
	for (int i = (cardlist.size() - 1); i >= 0;)
	{
		if (i >= 2)
		{
			if (cardlist[i] > 0 && cardlist[i - 1] > 0 && cardlist[i - 2] > 0)
			{
				cardlist[i] -= 1;
				cardlist[i - 1] -= 1;
				cardlist[i - 2] -= 1;
			} 
            else if (i >= 4 && cardlist[i] > 0 && cardlist[i-1] == 0 && cardlist[i-2] > 0 && cardlist[i-3] > 0 
                    && cardlist[i-4] >= 2)
            {
                cardlist[i-2] -= 1;
                cardlist[i-3] -= 1;
                cardlist[i-4] -= 1;
            }
			else if (cardlist[i] > 0 && cardlist[i - 1] == 0 && cardlist[i - 2] > 0 && hong > 0 && ((i - 1) % 10 != 0))
			{
				cardlist[i] -= 1;
				hong--;
				cardlist[i - 2] -= 1;
			}
			else if (cardlist[i] > 0 && cardlist[i - 1] > 0 && cardlist[i - 2] == 0 && hong > 0 && ((i - 2) % 10 != 0))
			{
				cardlist[i] -= 1;
				cardlist[i - 1] -= 1;
				hong--;
			}
			else if (cardlist[i] > 0 && cardlist[i - 1] > 0 && hong > 0 && ((i - 1) % 10 == 1))
			{
				cardlist[i] -= 1;
				cardlist[i - 1] -= 1;
				hong--;
			}
            else if (cardlist[i]==2 && cardlist[i-1] == 0 && hong > 0)
            {
                cardlist[i] -= 2;
                hong--;
            }
			else
			{
				i--;
			}
		}
		else
		{
			i--;
		}
	}
	std::vector<int> leftlist;
	int left = CalcLeftCard(cardlist, leftlist);
    if (hong == 1 && left == 2 && leftlist.size() == 1)
    {
        cardlist[leftlist[0]] = 0;
    }
	else if (hong == 2 && left == 1)
	{
		cardlist[leftlist[0]] = 0;
	}
	else if (hong == 3 && left == 0)
	{
		TingAllCard();
		m_win = true;
	}
}

int DetectWinPX::CalcLeftCard(std::vector<int>& cardlist, std::vector<int>& leftlist)
{
	int sum = 0;
	for (unsigned int i = 1; i < cardlist.size(); i++)
	{
		if (cardlist[i] > 0)
		{
			sum += cardlist[i];
			leftlist.push_back(i);
		}
	}

	return sum;
}

bool DetectWinPX::IsWin()
{
    std::vector<int> cardlist;
    cardlist.assign(m_hongWTT.begin(), m_hongWTT.end());
    if (RemoveAA(cardlist) || ReverseAA(cardlist))
    {
        m_win = true;
    }

    return m_win;
}

// JiangSu PeiXian Mahjong
//
//
bool DetectWinPX::RemoveAAAPX(std::vector<int>& cardlist)
{
    int flag = false;
	for (unsigned int i = 0; i < cardlist.size(); i++)
	{
		if (cardlist[i] >= 3)
		{
			cardlist[i] -= 3;
            flag = true;
		}
	}

    return flag;
}

void DetectWinPX::RemoveABCPX(std::vector<int>& cardlist)
{
	for (unsigned int i = 0; i < cardlist.size() && i < 30;)
	{
		if (i + 2 < cardlist.size())
		{
			if (cardlist[i] > 0 && cardlist[i + 1] > 0 && cardlist[i + 2] > 0)
			{
				cardlist[i] -= 1;
				cardlist[i + 1] -= 1;
				cardlist[i + 2] -= 1;
			}
			else
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}
}

bool DetectWinPX::RemoveAAPX(std::vector<int>& cardlist)
{
    bool flag = false;
    if (!IsPairs(cardlist))
    {
        return false;
    } 
    else
    {
        for (unsigned int i = 0; i < cardlist.size(); i++)
        {
            if (cardlist[i] >= 2)
            {
                std::vector<int> cardlast;
                cardlast.assign(cardlist.begin(), cardlist.end());
                cardlast[i] -= 2;
                RemoveAAAPX(cardlast);
                RemoveABCPX(cardlast);
                bool subflag = true;
                for (std::vector<int>::iterator iter = cardlast.begin(); iter != cardlast.end(); ++iter)
                {
                    if (*iter > 0)
                    {
                        subflag = false;
                        break;
                    }
                }
                flag = flag || subflag;
            }
        }
    }
	return flag;
}

bool DetectWinPX::RemoveAARPX(std::vector<int>& cardlist)
{
    bool flag = false;
    if (!IsPairs(cardlist))
    {
        return false;
    } 
    else
    {
        for (unsigned int i = 0; i < cardlist.size(); i++)
        {
            if (cardlist[i] >= 2)
            {
                std::vector<int> cardlast;
                cardlast.assign(cardlist.begin(), cardlist.end());
                cardlast[i] -= 2;
                RemoveABCPX(cardlast);
                RemoveAAAPX(cardlast);
                bool subflag = true;
                for (std::vector<int>::iterator iter = cardlast.begin(); iter != cardlast.end(); ++iter)
                {
                    if (*iter > 0)
                    {
                        subflag = false;
                        break;
                    }
                }
                flag = flag || subflag;
            }
        }
    }
	return flag;
}

bool DetectWinPX::DetectAllCardPX()
{
	for (int i = 1; i < 34; i++)
	{
		if (m_all)
		{
			return true;
		}
		if (i != 10 && i != 20 && i != 30)
		{
			CardInfo card = DeCodeCard(i);
			std::vector<int> cardlist;
			cardlist.assign(m_hongWTT.begin(), m_hongWTT.end());
			DetectCard(card, cardlist);
			if (RemoveAAPX(cardlist))
			{
				m_win = true;
				AddTingCard(card);
			}
			std::vector<int> cardlistr;
			cardlistr.assign(m_hongWTT.begin(), m_hongWTT.end());
			DetectCard(card, cardlistr);
            if (IsAAA(cardlistr))
            {
                if (RemoveAARPX(cardlistr))
                {
                    m_win = true;
                    AddTingCard(card);
                }
            }
		}
	}

	return m_win;
}

bool DetectWinPX::IsWinPX()
{
    std::vector<int> cardlist;
    cardlist.assign(m_hongWTT.begin(), m_hongWTT.end());
    if (RemoveAAPX(cardlist))
    {
        m_win = true;
    }

    return m_win;
}

