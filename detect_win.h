#pragma once
#include "card_info.h"
#include <vector>

class DetectWin
{
public:
	DetectWin();
	~DetectWin();

	void AddCard(const CardInfo& card);
	void AddTingCard(const CardInfo& card);
	void TingAllCard();
	int EnCodeCard(const CardInfo& card);
	CardInfo DeCodeCard(int code);
	bool AddCardCode(int code);
	void DumpTing();
    void DumpCards();
    int GetTingCards(std::vector<int>& cardlist);

	void Reset();
	bool DetectAA();
	void DetectDump();
	void DetectCard(CardInfo& card, std::vector<int>& cardlist);
	bool DetectDivision(unsigned int type);
	bool DetectAllCard();
	bool DetectWinOne();
	int  CalcLeftCard(std::vector<int>& cardlist, std::vector<int>& leftlist);
	bool RemoveAA(std::vector<int>& cardlist);
	bool RemoveAAA(std::vector<int>& cardlist);
	void RemoveABC(std::vector<int>& cardlist, int hong);
	void RemoveABC(std::vector<int>& cardlist);
	void RemoveCBA(std::vector<int>& cardlist, int hong);
	void RemoveCBA(std::vector<int>& cardlist);
    bool ReverseAA(std::vector<int>& cardlist);
    bool DetectReverse();
    bool IsPairs(std::vector<int>& cardlist);
    bool IsWin();

private:
	std::vector<int> m_wang;
	std::vector<int> m_tong;
	std::vector<int> m_tiao;

	std::vector<CardInfo> m_ting;

	int m_hong;
	bool m_all;
	bool m_win;
	std::vector<int> m_hongWTT;
};
