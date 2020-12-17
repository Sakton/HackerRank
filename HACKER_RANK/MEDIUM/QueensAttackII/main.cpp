#include <iostream>

#include "queen.h"

int queensAttack( int n, int k, int r_q, int c_q, std::vector< std::vector< int > >&& obstacles );

int main( ) { /*circlePoint( 13, nRow( 13, 3 ), 10 );*/
  queensAttack( 14, 1, 3, 10, { } );
}

// int queensAttack( int n, int k, int r_q, int c_q, std::vector< std::vector< int > >&& obstacles ) {
//  Queen q( n, r_q, c_q );
//  q.queensAttack( );
//  return 0;
//}

/*
        int left = ( ( c_q - r ) < 0 ) ? 0 : c_q - r;
        int right = ( ( c_q + r ) > n ) ? n : c_q + r;
        int top = ( ( r_q + r ) > n ) ? n : r_q + r;
        int bottom = ( ( r_q - r ) < 0 ) ? 0 : r_q - r;
        // std::cout << "l = " << left << " r = " << right << " t = " << top << " b = " << bottom << std::endl;
        std::cout << "( " << left << ":" << top << " ), ( " << right << ":" << top << " ), ( " << right << ":" << bottom << " ), ( " <<
        left
                  << ":" << bottom << " )" << std::endl;
 */

int queensAttack( int n, int k, int r_q, int c_q, std::vector< std::vector< int > >&& obstacles ) {
  std::vector< int > bug( 8 );
  int radius = std::max( std::max( r_q, n - r_q ), std::max( c_q, n - c_q ) );
  std::cout << radius << std::endl;
  int count = 0;
  int countAll = 3 * ( n - 1 ) + 2 * ( std::min( std::min( r_q, n - 1 - r_q ), std::min( c_q, n - 1 - c_q ) ) );
  int a = 3 * ( n - 1 );
  int b = 2 * ( std::min( std::min( r_q, n - 1 - r_q ), std::min( c_q, n - 1 - c_q ) ) );
  std::cout << "countAll = " << countAll;
  //  for ( int r = 1; r < radius; ++r ) {
  //    //    int left = ( ( c_q - r ) < 0 ) ? 0 : c_q - r;
  //    //    int right = ( ( c_q + r ) > n ) ? n : c_q + r;
  //    //    int top = ( ( r_q + r ) > n ) ? n : r_q + r;
  //    //    int bottom = ( ( r_q - r ) < 0 ) ? 0 : r_q - r;
  //    //    // std::cout << "l = " << left << " r = " << right << " t = " << top << " b = " << bottom << std::endl;
  //    //    std::cout << "( " << left << ":" << top << " ), ( " << right << ":" << top << " ), ( " << right << ":" << bottom << " ), ( "
  //    <<
  //    //    left
  //    //              << ":" << bottom << " )" << std::endl;
  //  }

  // for ( int i = left; i < right; ++i ) }

  return count;
}
