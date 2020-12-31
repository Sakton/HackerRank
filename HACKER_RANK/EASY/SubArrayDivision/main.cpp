#include <iostream>
#include <numeric>
#include <vector>

int birthday( std::vector< int > s, int d, int m ) {
  int count = 0;
  if ( s.size( ) == 1 && d == s[ 0 ] ) {
    count = 1;
  } else {
    int summ = std::accumulate( s.begin( ), s.begin( ) + m, 0 );
    if ( summ == d ) ++count;
    for ( std::vector< int >::size_type i = 0; i < s.size( ) - m; ++i ) {
      summ -= s[ i ];
      summ += s[ i + m ];
      if ( summ == d ) ++count;
    }
  }
  return count;
}

int main()
{
  // std::vector< int > t { 1, 2, 1, 3, 2 };
  // std::vector< int > t { 1, 1, 1, 1, 1, 1 };
  // std::vector< int > t { 4 };
  std::vector< int > t { 2, 3, 4, 4, 2, 1, 2, 5, 3, 4, 4, 3, 4, 1, 3, 5, 4, 5, 3, 1, 1, 5, 4, 3, 5, 3, 5, 3,
                         4, 4, 2, 4, 5, 2, 3, 2, 5, 3, 4, 2, 4, 3, 3, 4, 3, 5, 2, 5, 1, 3, 1, 4, 2, 2, 4, 3,
                         3, 3, 3, 4, 1, 1, 4, 3, 1, 5, 2, 5, 1, 3, 5, 4, 3, 3, 1, 5, 3, 3, 3, 4, 5, 2 };
  std::cout << birthday( t, 26, 8 );
}
