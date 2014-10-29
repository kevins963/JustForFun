#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

class Practice1
{
public:
    void Run();

    void TestAll( void );

    void sprintf( char* str, char* fmt, ... );
private:
    char* reverse_string( char* inputString );
    char find_match( char* inString, char* matchString );

};

void Practice1::Run()
{
    TestAll();

    char* stringReversed = reverse_string( "This is some string" );

    printf( "%s\n", stringReversed );

    char isMatch;

    isMatch = find_match( "abcdefg", "a" );
    printf( "Is Match Found: %d\n", isMatch );

    isMatch = find_match( "abcdefg", "g" );
    printf( "Is Match Found: %d\n", isMatch );

    isMatch = find_match( "abcdefg", "abcdefg" );
    printf( "Is Match Found: %d\n", isMatch );

    isMatch = find_match( "abcdefg", "cde" );
    printf( "Is Match Found: %d\n", isMatch );

    isMatch = find_match( "abcdefg", "ced" );
    printf( "Is Match Found: %d\n", isMatch );


}


char* Practice1::reverse_string( char* inputString )
{
    int size;

    char* pHead;
    char* pOutStringHead;

    char* outString;

    size = strlen( inputString );
    outString = (char*)malloc( sizeof( inputString ) * size + 1 );

    pHead = ( inputString + size - 1 );
    pOutStringHead = outString;

    printf( "size: %d", size );

    while( size-- )
    {
        *pOutStringHead++ = *pHead--;
    }

    *pOutStringHead = '\0';

    return outString;
}

char Practice1::find_match( char* inString, char* matchString )
{
    char isMatchFound = 0;

    //Get lengths
    int inStringLength = strlen( inString );
    int matchStringLength = strlen( matchString );

    //Traverse input string

    for( int i = 0; i < ( inStringLength - matchStringLength + 1 ) && isMatchFound == 0; ++i )
    {
        //If first char matches count sequental matches
        if( inString[i] == matchString[0] )
        {
            //If sequental matches equal match length, match is found
            char isMatchingError = 0;

            for( int j = 0; j < matchStringLength && isMatchingError == 0; ++j )
            {
                if( inString[ i + j] != matchString[ j ] )
                {
                    isMatchingError = 1;  
                }
            }

            if( isMatchingError == 0 )
            {
                isMatchFound = 1;
            }

        }

    }
    //return if match is found
    return isMatchFound;
}

void Practice1::sprintf( char* str, char* fmt, ... )
{
    char * tempStr = str;
    char* copy_arg;
    va_list args;
    va_start(args, fmt);

    //Go through format
    
    while( *fmt != NULL )
    {
        if( *fmt == '%' )
        {
            fmt++;

            switch( *fmt )
            {
            case 'd':
                _itoa_s( va_arg( args, int ), str, 30, 10 );
                break;
            case 's':
                copy_arg = va_arg( args, char*);
                strcpy_s(str, strlen( copy_arg ) + 1, copy_arg );
                break;
            }

            while( *str != '\0' )
                {
                    str++;
            };

        }
        else
        {
            *str++ = *fmt;
        }


        ++fmt;
    //Check for char type, % is used for special types

    //if special type take in the va list

    //insert converted char to string

    }
    va_end(args);

    *str = '\0';

    //add end deliminator
}

void Practice1::TestAll( void )
{
    char output[128];
    
    cout << "****** Test sprintf*********\n";

    sprintf( output, "this is a formated string, %d, %s\n", 6, "test_string");

    cout << output;
    
}
