#pragma once;

#include "IVehicle.h"

class ParkingSpot
{
public:
    ParkingSpot( VehicleType preferredSize ) :
        _preferredSize(preferredSize),
        _pVehicle(nullptr)
    {
    }

    bool IsOccupied()
    {
        return !(_pVehicle == nullptr);
    }

    bool EnterVehicle( IVehicle * pVehicle )
    {
        if( IsOccupied() == false )
        {
            _pVehicle = pVehicle;
            return true;
        }

        return false;
    }

    IVehicle * ExitVehicle( void )
    {
        IVehicle * pVehicle = _pVehicle;

        _pVehicle = nullptr;

        return pVehicle;
    }

    VehicleType GetPreferredSize()
    {
        return _preferredSize;
    }

    bool WillFit( IVehicle * vehicle )
    {
        bool willFit = false;

        VehicleType vehicleType = vehicle->GetVehicleType();

        switch (_preferredSize)
        {
        case VehicleType_Compact:
            if( vehicleType == VehicleType_Compact )
            {
                willFit = true;
            }
            break;
        case VehicleType_Standard:
            if( vehicleType == VehicleType_Compact ||
                vehicleType == VehicleType_Standard )
            {
                willFit = true;
            }
            break;
        case VehicleType_OverSized:
            if( vehicleType == VehicleType_Compact ||
                vehicleType == VehicleType_Standard || 
                vehicleType == VehicleType_OverSized )
            {
                willFit = true;
            }
            break;
        default:
            break;
        }

        return willFit;
    }

    IVehicle * GetVehicle()
    {
        return _pVehicle;
    }

private:
    VehicleType _preferredSize;
    IVehicle * _pVehicle;
};