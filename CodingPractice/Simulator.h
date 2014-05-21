#pragma once

#include "ParkingLot.h"
#include "F350.h"
#include "Prius.h"
#include "IVehicle.h"

#include <random>
#include <vector>

using namespace std;

class Simulator
{
public:

    Simulator()
    {
        _parkingLot = ParkingLot(5, 10, 5);

        for(int i = 0; i < 25; i++)
        {
            _waitingCars.push_back( new Prius(i) );
            _waitingCars.push_back( new F350(i + 25));
        }
    }

    void Run()
    {

        for(int i = 0; _waitingCars.size() > 0 ; i++)
        {

            if( !_parkingLot.IsFull() )
            {
                if(_parkingLot.CarEnter(_waitingCars.back()))
                {
                    _parkedCars.push_back(_waitingCars.back());
                    _waitingCars.pop_back();
                    
                }
            }

            if(i % 3 ==0)
            {
                _parkingLot.ExitVehicle(_waitingCars.back());
                _waitingCars.pop_back();
            }
        }
    }

private:
    vector<IVehicle*> _waitingCars;
    vector<IVehicle*> _parkedCars;
    ParkingLot _parkingLot;
};