#pragma once

typedef enum VehicleType
{
    VehicleType_Compact,
    VehicleType_Standard,
    VehicleType_OverSized
} VehicleType;

class IVehicle
{
public:

    IVehicle( long licensePlate ) :
        _licnesePlate(licensePlate)
    {
        _isDriving = true;
    }
    virtual ~IVehicle() {};

    virtual VehicleType GetVehicleType( void ) = 0;

    long GetLicensePlate()
    {
        return _licnesePlate;
    }

    bool GetIsDriving( void )
    {
        return _isDriving;
    }

    void SetIsDriving( bool isDriving )
    {
        _isDriving = isDriving;
    }

    bool Equals( IVehicle * pVehicle )
    {
        return ( _licnesePlate == pVehicle->GetLicensePlate() );
    }

private:
    long _licnesePlate;
    bool _isDriving;

};