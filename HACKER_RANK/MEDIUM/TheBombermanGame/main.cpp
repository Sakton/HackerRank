#include <iostream>
#include <vector>

enum class State { BOMB, FIRE, EMPTY };

std::vector< std::string > bomberMan( int n, std::vector< std::string > grid ) {
  State state = State::EMPTY;
  std::vector< std::pair< int, int > > indexes;

  if ( n == 1 ) return grid;
  if ( !( n % 2 ) )
    n = 2;
  else {
    if ( n % 4 == 3 ) n = 3;
    if ( n % 4 == 1 ) n = 5;
  }

  for ( int64_t i = 1; i <= n; ++i ) {
    switch ( state ) {
      case State::BOMB: {
        for ( int k = 0; k < grid.size( ); ++k ) {
          for ( int m = 0; m < grid[ k ].size( ); ++m ) {
            if ( grid[ k ][ m ] == 'O' )
              indexes.push_back( std::make_pair( k, m ) );
            else if ( grid[ k ][ m ] == '.' )
              grid[ k ][ m ] = 'O';
          }
        }
        state = State::FIRE;
        break;
      }

      case State::FIRE: {
        for ( auto &el : indexes ) {
          int k = el.first;
          int m = el.second;
          if ( ( k - 1 ) >= 0 ) {
            if ( grid[ k - 1 ][ m ] != '0' ) grid[ k - 1 ][ m ] = '.';
          }
          if ( ( k + 1 ) < grid.size( ) ) {
            if ( grid[ k + 1 ][ m ] != '0' ) grid[ k + 1 ][ m ] = '.';
          }
          if ( ( m - 1 ) >= 0 ) {
            if ( grid[ k ][ m - 1 ] != '0' ) grid[ k ][ m - 1 ] = '.';
          }
          if ( ( m + 1 ) < grid[ k ].size( ) ) {
            if ( grid[ k ][ m + 1 ] != '0' ) grid[ k ][ m + 1 ] = '.';
          }
          grid[ k ][ m ] = '.';
        }
        state = State::BOMB;
        indexes.clear( );
        break;
      }

      case State::EMPTY:
        state = State::BOMB;
        break;

      default:
        break;
    }
  }

  return grid;
}

// std::vector< std::string > bomberMan( int n, std::vector< std::string > grid ) {
//  State state = State::EMPTY;
//  std::vector< std::pair< int, int > > indexes;
//  for ( int64_t i = 1; i <= n; ++i ) {
//    switch ( state ) {
//      case State::BOMB: {
//	for ( int k = 0; k < grid.size( ); ++k ) {
//	  for ( int m = 0; m < grid[ k ].size( ); ++m ) {
//	    //	    if ( grid[ k ][ m ] == '.' )
//	    //	      grid[ k ][ m ] = 'O';
//	    //	    else if ( grid[ k ][ m ] == 'O' )
//	    //	      grid[ k ][ m ] = '1';
//	    if ( grid[ k ][ m ] == 'O' )
//	      indexes.push_back( std::make_pair( k, m ) );
//	    else if ( grid[ k ][ m ] == '.' )
//	      grid[ k ][ m ] = 'O';
//	  }
//	}
//	state = State::FIRE;
//	break;
//      }

//      case State::FIRE: {
//	//	for ( int k = 0; k < grid.size( ); ++k ) {
//	//	  for ( int m = 0; m < grid[ k ].size( ); ++m ) {
//	//	    if ( grid[ k ][ m ] == '1' ) {
//	//	      if ( k - 1 >= 0 ) {
//	//		if ( grid[ k - 1 ][ m ] != '1' ) grid[ k - 1 ][ m ] = '.';
//	//	      }
//	//	      if ( ( k + 1 ) < grid.size( ) ) {
//	//		if ( grid[ k + 1 ][ m ] != '1' ) grid[ k + 1 ][ m ] = '.';
//	//	      }
//	//	      if ( ( m - 1 ) >= 0 ) {
//	//		if ( grid[ k ][ m - 1 ] != '1' ) grid[ k ][ m - 1 ] = '.';
//	//	      }
//	//	      if ( ( m + 1 ) < grid[ k ].size( ) ) {
//	//		if ( grid[ k ][ m + 1 ] != '1' ) grid[ k ][ m + 1 ] = '.';
//	//	      }
//	//	      grid[ k ][ m ] = '.';
//	//	    }
//	//	  }
//	//	}
//	for ( auto &el : indexes ) {
//	  int k = el.first;
//	  int m = el.second;
//	  if ( ( k - 1 ) >= 0 ) {
//	    if ( grid[ k - 1 ][ m ] != '0' ) grid[ k - 1 ][ m ] = '.';
//	  }
//	  if ( ( k + 1 ) < grid.size( ) ) {
//	    if ( grid[ k + 1 ][ m ] != '0' ) grid[ k + 1 ][ m ] = '.';
//	  }
//	  if ( ( m - 1 ) >= 0 ) {
//	    if ( grid[ k ][ m - 1 ] != '0' ) grid[ k ][ m - 1 ] = '.';
//	  }
//	  if ( ( m + 1 ) < grid[ k ].size( ) ) {
//	    if ( grid[ k ][ m + 1 ] != '0' ) grid[ k ][ m + 1 ] = '.';
//	  }
//	  grid[ k ][ m ] = '.';
//	}
//	state = State::BOMB;
//	break;
//      }

//      case State::EMPTY:
//	state = State::BOMB;
//	break;

//      case State::START:
//	state = State::EMPTY;
//	break;

//      default:
//	break;
//    }
//  }

//  //  for ( int k = 0; k < grid.size( ); ++k ) {
//  //    for ( int m = 0; m < grid[ k ].size( ); ++m ) {
//  //      if ( grid[ k ][ m ] == 'O' )
//  //	grid[ k ][ m ] = '.';
//  //      else if ( grid[ k ][ m ] == '1' )
//  //	grid[ k ][ m ] = 'O';
//  //    }
//  //  }

//  return grid;
//}

int main( ) {
  std::vector< std::string > vs { ".......", "...O...", "....O..", ".......", "OO.....", "OO....." };
  // std::vector< std::string > vs { "O.O.O.O", "...O...", "....O..", ".......", "OO.....", "OO....." };
  auto res = bomberMan( 123234123, vs );
  for ( auto &el : res ) {
    std::cout << el << std::endl;
  }
}

//  for ( int i = 3; i <= n + 2; ++i ) {
//    if ( !( n % 3 ) ) {
//      for ( int k = 0; k < grid.size( ); ++k ) {
//	for ( int m = 0; m < grid[ k ].size( ); ++m ) {
//	  if ( grid[ k ][ m ] == '.' )
//	    grid[ k ][ m ] = 'O';
//	  else if ( grid[ k ][ m ] == 'O' )
//	    grid[ k ][ m ] = '1';
//	}
//      }
//    }

//    if ( !( n % 2 ) ) {
//      for ( int k = 0; k < grid.size( ); ++k ) {
//	for ( int m = 0; m < grid[ k ].size( ); ++m ) {
//	  if ( grid[ k ][ m ] == '1' ) {
//	    if ( k - 1 >= 0 ) {
//	      grid[ k - 1 ][ m ] = '.';
//	    }
//	    if ( ( k + 1 ) < grid.size( ) ) {
//	      grid[ k + 1 ][ m ] = '.';
//	    }
//	    if ( ( m - 1 ) >= 0 ) {
//	      grid[ k ][ m - 1 ] = '.';
//	    }
//	    if ( ( m + 1 ) < grid[ k ].size( ) ) {
//	      grid[ k ][ m + 1 ] = '.';
//	    }
//	    grid[ k ][ m ] = '.';
//	  }
//	}
//      }
//    }
//  }

//  for ( int k = 0; k < grid.size( ); ++k ) {
//    for ( int m = 0; m < grid[ k ].size( ); ++m ) {
//      if ( grid[ k ][ m ] == '1' ) grid[ k ][ m ] = 'O';
//    }
//  }
