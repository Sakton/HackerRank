#include <iostream>
#include <string>
#include <vector>
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

void separateNumbers( std::string s ) {
  std::string t, a;
  for ( std::string::size_type l = 1; l <= s.size( ) / 2 && s != t; l++ ) {
    a = t = s.substr( 0, l );
    for ( int i = 1; t.size( ) < s.size( ); i++ ) {
      t += std::to_string( stoll( a ) + i );
    }
  }
  std::cout << ( s == t ? "YES " + a : "NO" ) << std::endl;
}

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
