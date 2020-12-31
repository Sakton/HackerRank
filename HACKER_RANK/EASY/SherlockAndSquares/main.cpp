#include <fstream>
#include <iostream>

int squares( int a, int b );
void test( );

// a = 327610187 b = 686112903 answer = 8093  raschet = 8094  !!!!!!!!!!!!! 8093
// a = 324432467 b = 859919996 answer = 11312  raschet = 11313  !!!!!!!!!!!!! 11312

int main( ) {
  test( );
  // std::cout << squares( 327610187, 686112903 );
  // std::cout << squares( 324432467, 859919996 );
}

int squares( int a, int b ) {
  double x = std::sqrt( a );
  int xx = static_cast< int >( x );
  if ( ( x - xx ) > 1e-9 ) ++xx;
  int y = std::sqrt( b );
  return y - xx + 1;
}

// int squares( int a, int b ) {
//  double x = std::sqrt( a );
//  x *= 100;
//  int xx = static_cast< int >( x );
//  int k = xx % 100;
//  xx /= 100;
//  if ( k % 100 > 0 ) {
//    ++xx;
//  }
//  int y = std::sqrt( b );
//  return y - xx + 1;
//}

void test( ) {
  std::ifstream finInpt( "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/EASY/SherlockAndSquares/input.txt" );
  std::ifstream finOutpt( "E:/CPP/MyProects/HACKER_RANK/HackerRank/HACKER_RANK/EASY/SherlockAndSquares/outpt.txt" );
  int count = 0;
  finInpt >> count;
  std::cout << count;
  int a = 0;
  int b = 0;
  int answer = 0;
  while ( count ) {
    finInpt >> std::skipws >> a >> b;
    finOutpt >> std::skipws >> answer;
    int rasch = squares( a, b );
    std::cout << "a = " << a << " b = " << b << " answer = " << answer << "  raschet = " << rasch;
    if ( answer != rasch ) std::cout << "  !!!!!!!!!!!!!";
    std::cout << std::endl;
    --count;
  }
}
