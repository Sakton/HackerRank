#include <iostream>
#include <vector>

std::vector< int > permutationEquation( std::vector< int > p );

int main( ) {
  // auto res = permutationEquation( { 5, 2, 1, 3, 4 } );
  // auto res = permutationEquation( { 2, 3, 1 } );
  auto res = permutationEquation( { 4, 3, 5, 1, 2 } );
  for ( auto el : res ) std::cout << el << " ";
}

std::vector< int > permutationEquation( std::vector< int > p ) {
  p.insert( p.begin( ), -1 );
  int len = p.size( );
  std::vector< int > r;
  for ( int x = 1; x < len; ++x ) {
    int a = 1;
    while ( x != p[ a ] ) ++a;
    int b = 1;
    while ( a != p[ b ] ) ++b;
    r.push_back( b );
  }
  return r;
}
