#pragma once

#include "IVehicle.h"

class F350 : public IVehicle
{
public:

    F350(long licensePlate) : 
        IVehicle(licensePlate)
    {
    }

    VehicleType GetVehicleType( void )
    {
        return VehicleType_OverSized;
    }
};
