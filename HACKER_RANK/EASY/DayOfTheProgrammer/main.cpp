#include <iostream>
#include <string>

std::string dayOfProgrammer( int year ) {
  auto isVisokosnyGrogorian = [ & ]( int year ) { return ( ( year % 400 == 0 ) || ( ( year % 4 == 0 ) && ( year % 100 != 0 ) ) ); };
  auto isVisokosnyYulian = [ & ]( int year ) { return ( year % 4 ) == 0; };
  int dayStart = 243;
  if ( 1700 <= year && year < 1918 ) {
    if ( isVisokosnyYulian( year ) ) {
      dayStart++;
    }
  } else if ( 1918 < year && year <= 2700 ) {
    if ( isVisokosnyGrogorian( year ) ) {
      dayStart++;
    }
  } else {
    dayStart -= 13;
  }
  return std::to_string( 256 - dayStart ) + ".09." + std::to_string( year );
}

int main( ) { std::cout << dayOfProgrammer( 1918 ) << std::endl; }
