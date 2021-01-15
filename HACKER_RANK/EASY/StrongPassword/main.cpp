#include <iostream>
#include <string>

/*
numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"
*/

// int minimumNumber( int n, std::string password ) {
//  int count = 4;
//  bool number = false;
//  bool strochn = false;
//  bool glavn = false;
//  bool spec = false;

//  if ( password.size( ) < 6 ) return 6 - password.size( );
//  for ( auto ch : password ) {
//    if ( !number && std::isdigit( ch ) ) {
//      --count;
//      number = true;
//    }
//    if ( !strochn && std::islower( ch ) ) {
//      --count;
//      strochn = true;
//    }
//    if ( !glavn && std::isupper( ch ) ) {
//      --count;
//      glavn = true;
//    }
//    if ( !spec && std::ispunct( ch ) ) {
//      --count;
//      spec = true;
//    }
//    if ( number && strochn && glavn && spec ) break;
//  }
//  return count;
//}

int minimumNumber( int n, std::string password ) {
  int size = password.size( );
  int countNumber = 0;
  int countLower = 0;
  int countUpper = 0;
  int countSpec = 0;
  for ( auto ch : password ) {
    if ( std::isdigit( ch ) ) ++countNumber;
    if ( std::islower( ch ) ) ++countLower;
    if ( std::isupper( ch ) ) ++countUpper;
    if ( std::ispunct( ch ) ) ++countSpec;
    if ( countNumber && countLower && countUpper && countSpec ) break;
  }
  int res = 0;
  if ( !countNumber ) ++res;
  if ( !countLower ) ++res;
  if ( !countUpper ) ++res;
  if ( !countSpec ) ++res;
  if ( ( size + res ) < 6 ) res += 6 - ( size + res );
  return res;
}

int main( ) {
  // std::cout << minimumNumber( 11, "#HackerRank" );
  std::cout << minimumNumber( 3, "Ab1" );
  // std::cout << minimumNumber( 4, "4700" );
}
