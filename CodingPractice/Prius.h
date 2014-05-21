#pragma once

#include "IVehicle.h"

class Prius : public IVehicle
{
public:
    Prius(long licensePlate) : 
        IVehicle(licensePlate)
    {
    }

    ~Prius(){};

    VehicleType GetVehicleType( void )
    {
        return VehicleType_Compact;
    }
};
