#include "detect_win.h"

DetectWin::DetectWin()
{
	m_wang.assign(10, 0);
	m_tong.assign(10, 0);
	m_tiao.assign(10, 0);
	m_hong = 0;
	m_all = false;
	m_win = false;
	m_hongWTT.assign(10, 0);
}

DetectWin::~DetectWin()
{
}

void DetectWin::Reset()
{
	m_wang.assign(10, 0);
	m_tong.assign(10, 0);
	m_tiao.assign(10, 0);
	m_hong = 0;
	m_all = false;
	m_win = false;
	m_hongWTT.assign(10, 0);
}

void DetectWin::AddCard(const CardInfo& card)
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
		++m_hong;
	}
}

bool DetectWin::AddCardCode(int code)
{
	if (code == 30)
	{
		if (m_hong > 4)
		{
			return false;
		}
		else
		{
			m_hong++;
			return true;
		}
	}
	int type = code / 10;
	int index = code % 10;
	if (type == CARD_WANG)
	{
		if (m_wang[index] > 4)
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
		if (m_tong[index] > 4)
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
		if (m_tiao[index] > 4)
		{
			return false;
		}
		else
		{
			m_tiao[index] = m_tiao[index] + 1;
			return true;
		}
	}
	return false;
}

void DetectWin::AddTingCard(const CardInfo& card)
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

void DetectWin::TingAllCard()
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

int DetectWin::EnCodeCard(const CardInfo& card)
{
	int code = card.m_type * 10 + card.m_code;
	return code;
}

CardInfo DetectWin::DeCodeCard(int code)
{
	int ctype = code / 10;
	int ccode = code % 10;
	CardInfo card;
	card.m_type = ctype;
	card.m_code = ccode;
	card.m_weight = code;
	return card;
}

void DetectWin::DetectDump()
{
	m_hongWTT.clear();
	m_hongWTT.assign(30, 0);
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
}

void DetectWin::DumpTing()
{
	printf("\n=======================Current Ting Card================================\n");
	for (std::vector<CardInfo>::iterator iter = m_ting.begin(); iter != m_ting.end(); ++iter)
	{
		printf("%d%d ", iter->m_type, iter->m_code);
	}
	printf("\n========================================================================\n");
}

bool DetectWin::DetectAA()
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

void DetectWin::DetectCard(CardInfo& card, std::vector<int>& cardlist)
{
	int index = card.m_weight;
	if (index < 0 || index >= 30)
	{
		return;
	}
	else
	{
		cardlist[index]++;
	}
}

bool DetectWin::DetectWinOne()
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

	return DetectAllCard();
}

bool DetectWin::DetectDivision(unsigned int type)
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

bool DetectWin::DetectAllCard()
{
	for (int i = 1; i < 30; i++)
	{
		if (m_all)
		{
			return true;
		}
		if (i != 10 || i != 20)
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
		}
	}

	return m_win;
}

bool DetectWin::RemoveAA(std::vector<int>& cardlist)
{
	if (m_hong >= 2)
	{
		std::vector<int> cardlast;
		cardlast.assign(cardlist.begin(), cardlist.end());
		RemoveAAA(cardlast);
		if (m_hong - 2 > 0)
		{
			RemoveABC(cardlast, m_hong - 2);
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
	}

	bool flag = false;
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
	return flag;
}

void DetectWin::RemoveAAA(std::vector<int>& cardlist)
{
	for (unsigned int i = 0; i < cardlist.size(); i++)
	{
		if (cardlist[i] >= 3)
		{
			cardlist[i] -= 3;
			return;
		}
	}
}

void DetectWin::RemoveABC(std::vector<int>& cardlist)
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

void DetectWin::RemoveABC(std::vector<int>& cardlist, int hong)
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
	if (hong == 2 && left == 1)
	{
		cardlist[leftlist[0]] = 0;
	}
	else if (hong == 3 && left == 0)
	{
		TingAllCard();
		m_win = true;
	}
}

int DetectWin::CalcLeftCard(std::vector<int>& cardlist, std::vector<int>& leftlist)
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