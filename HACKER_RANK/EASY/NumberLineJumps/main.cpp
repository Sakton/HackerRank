#include <iostream>
#include <string>

std::string kangaroo( int x1, int v1, int x2, int v2 ) { return ( ( v1 > v2 ) && !( ( x2 - x1 ) % ( v2 - v1 ) ) ) ? "YES" : "NO"; }

int main()
{
  std::cout << kangaroo( 0, 3, 4, 2 ) << std::endl;
  // std::cout << kangaroo( 0, 2, 5, 3 ) << std::endl;
  return 0;
}
