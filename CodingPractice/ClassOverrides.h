
#include <string>
#include <iostream>

using namespace std;

class ClassCopyTest;
class ClassDeepCopy;
class ClassShallowCopy;

class ClassCopyTest
{
public:
    void RunTests();
};

class ClassDeepCopy
{
public:
    ClassDeepCopy( const string name, int age );
    ClassDeepCopy( const ClassDeepCopy &object );
    ~ClassDeepCopy( void );
    ClassDeepCopy& operator=( const ClassDeepCopy &object);
    void UpdateData( const string name, int age );
public:
    string * mpName;
    int mAge;

};


class ClassShallowCopy
{
public:
    ClassShallowCopy( const string name, int age );
    ~ClassShallowCopy( void );
    void UpdateData( const string name, int age );
public:
    string * mpName;
    int mAge;

};

void ClassCopyTest::RunTests()
{
    ClassShallowCopy shallowCopy1( "Kevin", 30 );
    ClassShallowCopy shallowCopy2( "David", 35 );
    ClassShallowCopy shallowCopy3( shallowCopy1 );

    ClassDeepCopy deepCopy1( "Kevin", 30 );
    ClassDeepCopy deepCopy2( "David", 35 );
    ClassDeepCopy deepCopy3( deepCopy1 );

    cout << "Shallow Copy" << endl << 
        "Object 1 = " << *shallowCopy1.mpName << " " << shallowCopy1.mAge << endl <<
        "Object 2 = " << *shallowCopy2.mpName << " " << shallowCopy2.mAge << endl <<
        "Object 3 = " << *shallowCopy3.mpName << " " << shallowCopy3.mAge << endl;

    shallowCopy2 = shallowCopy1;
    shallowCopy1.UpdateData( "Thomas", 100 );

    cout << "Shallow Copy" << endl << 
        "Object 1 = changed " << *shallowCopy1.mpName << " " << shallowCopy1.mAge << endl <<
        "Object 2 = Object1 " << *shallowCopy2.mpName << " " << shallowCopy2.mAge << endl <<
        "Object 3(object1)  " << *shallowCopy3.mpName << " " << shallowCopy3.mAge << endl;


    cout << "Deep Copy" << endl << 
        "Object 1 = " << *deepCopy1.mpName << " " << deepCopy1.mAge << endl <<
        "Object 2 = " << *deepCopy2.mpName << " " << deepCopy2.mAge << endl <<
        "Object 3 = " << *deepCopy3.mpName << " " << deepCopy3.mAge << endl;

    deepCopy2 = deepCopy1;
    deepCopy1.UpdateData( "Thomas", 100 );

    cout << "Deep Copy" << endl << 
        "Object 1 = changed " << *deepCopy1.mpName << " " << deepCopy1.mAge << endl <<
        "Object 2 = Object1 " << *deepCopy2.mpName << " " << deepCopy2.mAge << endl <<
        "Object 3(object1)  " << *deepCopy3.mpName << " " << deepCopy3.mAge << endl;
}


ClassDeepCopy::ClassDeepCopy(const string name, int age) :
    mAge( age )
{
    mpName = new string( name );
}

ClassDeepCopy::ClassDeepCopy(const ClassDeepCopy &object) :
    mAge( object.mAge )
{
    mpName = new string( *object.mpName );
}

ClassDeepCopy::~ClassDeepCopy(void)
{
    if( mpName )
    {
       // delete mpName;
    }
}

ClassDeepCopy& ClassDeepCopy::operator=(const ClassDeepCopy &object)
{
    if( this != &object )
    {
        mAge = object.mAge;
        mpName->clear();
        *mpName = *object.mpName;
    }

    return *this;
}

void ClassDeepCopy::UpdateData(const string name, int age)
{
    mAge = age;
    mpName->clear();
    *mpName = name;
}



void ClassShallowCopy::UpdateData(const string name, int age)
{
    mAge = age;
    mpName->clear();
    *mpName = name;
}

ClassShallowCopy::ClassShallowCopy(const string name, int age) :
    mAge( age )
{
    mpName = new string( name );
}

ClassShallowCopy::~ClassShallowCopy(void)
{
    if( mpName )
    {
        //delete mpName;
    }
}
