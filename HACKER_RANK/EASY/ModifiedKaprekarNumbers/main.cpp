#include <iostream>
#include <string>
#include <vector>

void kaprekarNumbers( int p, int q ) {
  std::vector< int > res;
  for ( int64_t i = p; i <= q; ++i ) {
    int64_t x = i * i;
    std::string ts = std::to_string( x );
    if ( x == 0 ) continue;
    if ( x == 1 ) {
      res.push_back( x );
      continue;
    } else if ( ts.length( ) > 1 ) {
      int d = ts.length( ) / 2;
      int64_t a = std::stoi( ts.substr( 0, d ) );
      int64_t b = std::stoi( ts.substr( d ) );
      if ( b != 0 && a + b == i ) res.push_back( i );
    }
  }
  if ( res.empty( ) )
    std::cout << "INVALID RANGE";
  else
    for ( auto el : res ) std::cout << el << ' ';
}

int main( ) {
  // kaprekarNumbers( 0, 10 );
  std::cout << std::endl;
  kaprekarNumbers( 1, 99999 );  // 1 9 45 55 99 297 703 999 2223 2728 4950 5050 7272 7777 9999 17344 22222 77778 82656 95121 99999
  // kaprekarNumbers( 77778, 77778 );
}
