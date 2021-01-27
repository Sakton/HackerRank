#include <iostream>
#include <string>
#include <vector>

// TODO !!! THIS BAD ALGORITHM
void separateNumbers( std::string s ) {
  if ( s[ 0 ] == '0' ) {
    std::cout << "NO" << std::endl;
    return;
  }

  if ( s.size( ) <= 1 ) {
    std::cout << "NO" << std::endl;
    return;
  }
  std::string::size_type pos = 0;
  // 1. получить 1 и 2 число
  std::string::size_type len = 1;
  std::string firstNum;
  std::string startNumString;
  while ( len <= s.size( ) / 2 ) {
    std::string firstStrNum = s.substr( 0, len );
    //узнаем какое число ждем дальше
    int64_t firstInt = std::stoll( firstStrNum );
    int64_t secondIntOgidanie = firstInt + 1;
    std::string secondStringOgidanie = std::to_string( secondIntOgidanie );
    std::string second = s.substr( len, secondStringOgidanie.size( ) );
    if ( secondStringOgidanie == second ) {
      firstNum = firstStrNum;
      startNumString = second;
      pos += firstStrNum.size( ) + second.size( );
      break;
    } else {
      len++;
    }
  }

  if ( startNumString.empty( ) ) {
    std::cout << "NO" << std::endl;
    return;
  }

  // c 3 и далее
  while ( ( pos + startNumString.size( ) ) <= s.size( ) ) {
    int64_t a = std::stoll( startNumString );
    int64_t b = a + 1;
    std::string bStr = std::to_string( b );
    std::string secondStr = s.substr( pos, bStr.size( ) );
    if ( bStr != secondStr ) {
      std::cout << "NO" << std::endl;
      return;
    }
    startNumString = bStr;
    pos += bStr.size( );
    a = b;
  }

  std::cout << "YES " << std::stoll( firstNum ) << std::endl;
}

// void separateNumbers( std::string s ) {
//  std::vector< int > t( s.size( ), 0 );
//  for ( std::string::size_type i = 0; i < s.size( ); ++i ) {
//    t[ i ] = s[ i ] - '0';
//  }
//}

// void separateNumbers( std::string s ) {
//  using sType = std::string;
//  int pos = 1;
//  int first = std::stoi( s.substr( 0, pos ) );
//  int tempFirst = first;
//  int tempSecond = std::stoi( s.substr( pos, std::to_string( first + 1 ).size( ) ) );
//  for ( ; pos < s.size( ) / 2; ) {
//    if ( ( tempSecond - tempFirst ) == 1 ) {
//      ++tempFirst;
//      pos += std::to_string( tempFirst ).size( );
//      tempSecond = std::stoi( s.substr( pos, std::to_string( tempFirst + 1 ).size( ) ) );
//    } else {
//      std::cout << "No" << std::endl;
//    }
//  }
//  std::cout << "Yes " << first << std::endl;
//}

/*
99910001001
7891011
9899100
999100010001
*/

/*
1234
91011
99100
101103
010203
13
1
*/

int main( ) {
  //  separateNumbers( "1011" );
  //  separateNumbers( "91011121314151617" );
  //  separateNumbers( "9991000" );
  //  separateNumbers( "99910001001" );
  //  separateNumbers( "7891011" );
  //  separateNumbers( "9899100" );
  //  separateNumbers( "999100010001" );
  //  separateNumbers( "1234" );
  //  separateNumbers( "91011" );
  //  separateNumbers( "99100" );
  //  separateNumbers( "101103" );
  //  separateNumbers( "010203" );
  //  separateNumbers( "13" );
  //  separateNumbers( "1" );

  //  separateNumbers( "00000000000000000000000000000000" );
  //  separateNumbers( "11111111111111111111111111111111" );
  //  separateNumbers( "22222222222222222222222222222222" );
  //  separateNumbers( "33333333333333333333333333333333" );
  //  separateNumbers( "44444444444444444444444444444444" );
  //  separateNumbers( "55555555555555555555555555555555" );
  //  separateNumbers( "66666666666666666666666666666666" );
  //  separateNumbers( "77777777777777777777777777777777" );
  //  separateNumbers( "88888888888888888888888888888888" );
  //  separateNumbers( "10001001100210031004100510061007" );

  // separateNumbers( "90071992547409929007199254740993" );
  separateNumbers( "45035996273704964503599627370497" );  // 4503599627370496 и 4503599627370497 ???
  //  separateNumbers( "22517998136852482251799813685249" );
  //  separateNumbers( "11258999068426241125899906842625" );
  separateNumbers( "562949953421312562949953421313" );  // 562949953421312 и 562949953421313
  //  separateNumbers( "90071992547409928007199254740993" );
  //  separateNumbers( "45035996273704963503599627370497" );
  //  separateNumbers( "22517998136852481251799813685249" );
  //  separateNumbers( "11258999068426240125899906842625" );
  //  separateNumbers( "562949953421312462949953421313" );
}
