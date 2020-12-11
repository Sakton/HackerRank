#include <iostream>

int saveThePrisoner( int n, int m, int s );

int main( ) {
  // std::cout << saveThePrisoner( 5, 2, 1 );  // 2
  // std::cout << saveThePrisoner( 5, 2, 2 );  // 3
  // std::cout << saveThePrisoner( 7, 19, 2 );  // 6
  // std::cout << saveThePrisoner( 3, 7, 3 );  // 3
  // std::cout << saveThePrisoner( 352926151, 380324688, 94730870 );  // 122129406
  // std::cout << saveThePrisoner( 94431605, 679262176, 5284458 );  // 23525398
  // std::cout << saveThePrisoner( 499999999, 999999997, 2 );  // 499999999
  // std::cout << saveThePrisoner( 499999999, 999999998, 2 );  // 1
  std::cout << saveThePrisoner( 999999999, 999999999, 1 );  // 999999999
}

int saveThePrisoner( int n, int m, int s ) { return ( s + m - 2 ) % n + 1; }
