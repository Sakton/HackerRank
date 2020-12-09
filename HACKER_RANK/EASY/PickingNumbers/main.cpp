#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int pickingNumbers( std::vector< int > a ) {
  std::map< int, int > mSet;
  for ( auto el : a ) mSet[ el ]++;
  int total = 0;
  for ( auto el : mSet ) {
    total = std::max( total, el.second );
    int key = el.first;
    int val = el.second;
    auto nxt = mSet.find( key + 1 );
    if ( nxt != mSet.end( ) )
      if ( ( key - nxt->first ) <= 1 ) total = std::max( total, std::abs( val + nxt->second ) );
  }
  return total;
}

int main( ) {
  // std::vector< int > inpt { 4, 6, 5, 3, 3, 1 };
  // std::vector< int > inpt { 1, 2, 2, 3, 1, 2 };
  std::vector< int > inpt { 4, 6, 5, 3, 3, 1 };
  std::cout << pickingNumbers( inpt );
}
