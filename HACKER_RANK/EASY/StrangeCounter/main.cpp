#include <cmath>
#include <iostream>

long strangeCounter( long t ) {
  long k = std::log2( ( t + 2 ) / 3 );
  long n_k = 3 * std::pow( 2, k );
  long t_k = n_k - 2;
  return n_k - ( t - t_k );
}

int main( ) { std::cout << strangeCounter( 46 ); }
