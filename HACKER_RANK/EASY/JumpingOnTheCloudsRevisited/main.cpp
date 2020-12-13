#include <iostream>
#include <vector>

int jumpingOnClouds( std::vector< int > c, int k );

int main( ) {
  // std::cout << jumpingOnClouds( { 0, 0, 1, 0, 0, 1, 1, 0 }, 2 );  // 92
  std::cout << jumpingOnClouds( { 1, 1, 1, 0, 1, 1, 0, 0, 0, 0 }, 3 );  // 80
}

int jumpingOnClouds( std::vector< int > c, int k ) {
  int life = 100;
  int i = ( k ) % c.size( );
  life -= ( c[ i ] * 2 + 1 );
  while ( i ) {
    i = ( i + k ) % c.size( );
    life -= ( c[ i ] * 2 + 1 );
  }
  return life;
}
