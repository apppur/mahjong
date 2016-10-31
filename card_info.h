#pragma once

enum ECardType
{
	CARD_WANG = 0,
	CARD_TONG = 1,
	CARD_TIAO = 2,
	CARD_HONG = 3,
};

struct CardInfo
{
	int m_type;
	int m_code;
	int m_weight;
};

struct CmpCardInfo
{
	bool operator() (const CardInfo& lcard, const CardInfo& rcard)
	{
		return (lcard.m_weight < rcard.m_weight);
	}
};