#pragma once

#include <vector>

using namespace std;

class Card
{
public:
    typedef enum CardFaceValue
    {
        Face_1,
        Face_2,
        Face_3,
        Face_4,
        Face_5,
        Face_6,
        Face_7,
        Face_8,
        Face_9,
        Face_J,
        Face_Q,
        Face_K,
        Face_Max
    } CardFaceValue;

    typedef enum CardSuit
    {
        Suit_Heart,
        Suit_Spade,
        Suit_Diamonds,
        Suit_Clover,
        Suit_Max
    } CardSuit;

    Card( CardFaceValue value, CardSuit suit) :
        _value( value ),
        _suit( suit )
    {

    }

    CardSuit GetSuit();
    CardFaceValue GetValue();
protected:
    
private:

    CardSuit _suit;
    CardFaceValue _value;

};

Card::CardSuit Card::GetSuit()
{
    return _suit;
}

Card::CardFaceValue Card::GetValue()
{
    return _value;
}
