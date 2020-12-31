#include <iostream>
#include <vector>

using namespace std;

int divisibleSumPairs( int n, int k, vector< int > ar ) {
  int x = 0;
  for ( int i = 0; i < n - 1; ++i )
    for ( int j = i + 1; j < n; ++j )
      if ( !( ( ar[ i ] + ar[ j ] ) % k ) ) ++x;
  return x;
}

int main( ) {
  cout << divisibleSumPairs( 6, 3, { 1, 3, 2, 6, 1, 2 } ) << endl;
  return 0;
}
