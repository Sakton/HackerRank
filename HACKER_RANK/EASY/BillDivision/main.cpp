#include <iostream>
#include <numeric>
#include <vector>

void bonAppetit( std::vector< int > bill, int k, int b ) {
  int sum = std::accumulate( bill.cbegin( ), bill.cend( ), 0, std::plus< int >( ) );
  sum -= bill[ k ];
  if ( b == sum / 2 )
    std::cout << "Bon Appetit";
  else
    std::cout << ( b - sum / 2 );
}

int main( ) {
  std::vector< int > t { 3, 10, 2, 9 };
  bonAppetit( t, 1, 7 );
}
