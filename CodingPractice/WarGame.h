#pragma once

/*
Start
1 Deal new deck of cards
2 Shuffle cards
3 Deal equal to each player

Play
4 Both players turn top card
5 higher value wins
6 equal value put three cards down flip next over

End
7 One player has no more cards
*/

#include "Cards.h"
#include "CardDeck.h"

#include <vector>
#include <queue>
#include <deque>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class WarCame
{
public:
    WarCame(){};

    void RunGame();

private:
    void LoadDeck();
    void DealPlayers();

    void PlayTurn();
    //void HandlePlay();
    bool CheckGameComplete();

private:
    vector<Card> _deck;
    deque<Card*> _playerOne;
    deque<Card*> _playerTwo;
};

void WarCame::RunGame()
{
    LoadDeck();
    DealPlayers();

    while( !CheckGameComplete() )
    {
        PlayTurn();
        cout << "p1=" << _playerOne.size() << "p2=" << _playerTwo.size() << endl;
    }

    cout << "Complete, Winner:  " << ( _playerOne.size() > 0 ) ? "Player One" : "Player Two";
    cout << endl;

}

void WarCame::LoadDeck()
{
    CardDeck cardDeck;

    _deck = cardDeck.CreateDeck();
    cardDeck.ShuffleDeck( _deck );
    cardDeck.ShuffleDeck( _deck );
    cardDeck.ShuffleDeck( _deck );
}

void WarCame::DealPlayers()
{
    int players = 2;

    for( int i = 0; i < _deck.size(); i++ )
    {
        if( i % players == 0 )
        {
            _playerOne.push_back( &_deck[i] );
        }
        else
        {
            _playerTwo.push_back( &_deck[i] );
        }
    }
}

void WarCame::PlayTurn()
{
    bool isTurnComplete = false;
    int cardsToPlay = 1;
    vector<Card*> playerOneCards;
    vector<Card*> playerTwoCards;

    while( !isTurnComplete && 
         ( _playerOne.size() > 0 && _playerTwo.size() > 0 ) && 
         (  cardsToPlay > 0 ) )
    {
        
        
        playerOneCards.push_back( _playerOne.front() );
        playerTwoCards.push_back( _playerTwo.front() );
        _playerOne.pop_front();
        _playerTwo.pop_front();

        cardsToPlay--;
        if( cardsToPlay == 0 )
        {
            if( playerOneCards.back() == playerTwoCards.back() )
            {
                cardsToPlay = 3;
                cout << "**WAR**" << endl;
            }
            else
            {
                if( playerOneCards.back() > playerTwoCards.back() )
                {
                    std::copy( playerOneCards.begin(), playerOneCards.end(), std::back_inserter( _playerOne )  );
                    std::copy( playerTwoCards.begin(), playerTwoCards.end(), std::back_inserter( _playerOne )  );  
                }
                else
                {
                    std::copy( playerOneCards.begin(), playerOneCards.end(), std::back_inserter( _playerTwo )  );
                    std::copy( playerTwoCards.begin(), playerTwoCards.end(), std::back_inserter( _playerTwo )  );
                }
            }
        }
    }
}

bool WarCame::CheckGameComplete()
{
    return ( _playerOne.size() == 0 || _playerTwo.size() == 0 );
}
