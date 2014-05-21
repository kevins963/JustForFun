/* Notes: Always write down and figure out what is needed */

/*
What does a parking lot have
 Enterence
 Parking Spaces
 List of all cars
Check
 Is Full
 Is Open
 Enter Car
  Check if preferred size is available else find any that will fit
 

Parking space has
 Size
 Car
Check
 Is Occupied
 Car Enter
 Car Exit
 Check if will fit
 Get size

Car
 Size

Sizes
 Compact
 Standard
 Oversized
*/

#pragma once

#include "ParkingSpot.h"
#include "IVehicle.h"
#include <vector>
#include <iostream>

using namespace std;

class ParkingLot
{
public:

    ParkingLot()
    {

    }

    ParkingLot( int compactSpaces, int standardSpaces, int oversizedSpaces)
    {
        _parkingSpots = vector<ParkingSpot>();
        //_parkedVehicles = vector<IVehicle*>();

        CreateNewSpots( VehicleType_Compact, compactSpaces );
        CreateNewSpots( VehicleType_Standard, standardSpaces );
        CreateNewSpots( VehicleType_OverSized, oversizedSpaces );
    }
    bool IsFull(void)
    {
        for( vector<ParkingSpot>::iterator itr = _parkingSpots.begin(); itr != _parkingSpots.end(); ++itr )
        {
            if( itr._Ptr->IsOccupied() == false )
            {
                return false;
            }
        }

        return true;
    }

    bool IsOpen(void)
    {
        return true;
    }

    bool CarEnter( IVehicle * pVehicle )
    {
        bool parked = false;
        cout << " car " << pVehicle->GetLicensePlate() << " enum " << pVehicle->GetVehicleType();
        // Look for preferred spot else use non preferred spot
        ParkingSpot * pParkingSpot = nullptr;

        for(vector<ParkingSpot>::const_iterator itr = _parkingSpots.begin(); itr != _parkingSpots.end(); ++itr )
        {

            if( itr._Ptr->IsOccupied() == false && 
                itr._Ptr->WillFit( pVehicle ) )
            {
                if(itr._Ptr->GetPreferredSize() == pVehicle->GetVehicleType())
                {
                    itr._Ptr->EnterVehicle(pVehicle);
                    cout << "parked ";   
                    parked = true;
                }
                else if( pParkingSpot == nullptr )
                {
                    pParkingSpot = itr._Ptr;
                }
            }
        }

        //No preferred spots so park in non preferred
        if( pParkingSpot != nullptr && !parked )
        {
            pParkingSpot->EnterVehicle( pVehicle );
            cout << " parked non preferred ";
            parked = true;
        }
        else 
        {
            cout << " no parking spot ";
        }

        cout << endl;

        return parked;

    }

    void ExitVehicle( IVehicle * pVehicle )
    {
        for( vector<ParkingSpot>::const_iterator itr = _parkingSpots.begin(); itr != _parkingSpots.end(); ++itr )
        {
            if( itr._Ptr->GetVehicle() == pVehicle )
            {
                itr._Ptr->ExitVehicle();
            }
        }
    }

private:
    void CreateNewSpots( VehicleType vtype, int count )
    {
        for( int i = 0; i < count; i++)
        {
            _parkingSpots.push_back( ParkingSpot(vtype) );
        }
    }
private:
    vector<ParkingSpot> _parkingSpots;
};