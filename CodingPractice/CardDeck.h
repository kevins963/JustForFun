#pragma once
#include <vector>
#include "Cards.h"
#include <random>
/*
1. Create full deck
2. Shuffle Deck
*/

using namespace std;

class CardDeck
{
public:
    vector<Card> CreateDeck();

    void ShuffleDeck( vector<Card>& cards );

private:
};

vector<Card> CardDeck::CreateDeck()
{
    vector<Card> deck;
    Card::CardFaceValue cardValue = Card::Face_1;
    while( cardValue < Card::Face_Max )
    {
        deck.push_back( Card( cardValue, Card::Suit_Clover ) );
        deck.push_back( Card( cardValue, Card::Suit_Heart ) );
        deck.push_back( Card( cardValue, Card::Suit_Spade ) );
        deck.push_back( Card( cardValue, Card::Suit_Diamonds ) );
        cardValue = (Card::CardFaceValue)( cardValue + 1 );
    }

    return deck;
}

void CardDeck::ShuffleDeck( vector<Card>& cards )
{
    for (int i = 0; i < cards.size(); i++ )
    {
        int swapIndex = rand() % cards.size();
        Card temp = cards[i];
        cards[i] = cards[swapIndex];
        cards[swapIndex] = temp;
    }
}


