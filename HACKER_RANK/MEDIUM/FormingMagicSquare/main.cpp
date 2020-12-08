#include <iostream>
#include <list>
#include <vector>

int formingMagicSquare( std::vector< std::vector< int > > s );

int main()
{
  // std::vector< std::vector< int > > input { { 5, 5, 5 }, { 5, 5, 5 }, { 5, 5, 5 } };
  // std::vector< std::vector< int > > input { { 5, 3, 4 }, { 1, 5, 8 }, { 6, 4, 2 } };
  // std::vector< std::vector< int > > input { { 3, 3, 3 }, { 3, 3, 3 }, { 3, 3, 3 } };
  // std::vector< std::vector< int > > input { { 4, 8, 2 }, { 4, 5, 7 }, { 6, 1, 6 } };
  // std::vector< std::vector< int > > input { { 6, 7, 8 }, { 7, 6, 2 }, { 3, 2, 3 } };  // 17
  std::vector< std::vector< int > > input { { 2, 9, 8 }, { 4, 2, 7 }, { 5, 6, 7 } };  // 21
  std::cout << formingMagicSquare( input );
}

int formingMagicSquare( std::vector< std::vector< int > > s ) {}

/*
int formingMagicSquare( std::vector< std::vector< int > > s ) {
  std::vector< int > circle( 8 );
  circle[ 0 ] = s[ 0 ][ 0 ];
  circle[ 1 ] = s[ 0 ][ 1 ];
  circle[ 2 ] = s[ 0 ][ 2 ];
  circle[ 3 ] = s[ 1 ][ 2 ];
  circle[ 4 ] = s[ 2 ][ 2 ];
  circle[ 5 ] = s[ 2 ][ 1 ];
  circle[ 6 ] = s[ 2 ][ 0 ];
  circle[ 7 ] = s[ 1 ][ 0 ];
  // circle[ 8 ] = s[ 1 ][ 1 ];  //центральный элемент
  for ( auto el : circle ) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  std::list< int > etalon { 1, 8, 3, 4, 9, 2, 7, 6 };  // 5 всегда в центре

  int max = 0;
  std::vector< int > countMaxes( 8 );
  for ( int i = 0; i < 8; ++i ) {
    auto it = etalon.begin( );
    int cou = 0;
    for ( int j = 0; j < 8; ++j, ++it ) {
      if ( circle[ j ] == *it ) {
        ++cou;
      }
      if ( max < cou ) {
        max = cou;
        countMaxes[ max ]++;
      }
      if ( max == cou ) {
        countMaxes[ max ]++;
      }
    }
    etalon.push_back( etalon.front( ) );
    etalon.pop_front( );
  }

  std::cout << "max = " << max << std::endl;
  for ( auto el : countMaxes ) {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  int newCou = 0;
  for ( int i = 0; i < 8 && newCou < max; ++i ) {
    auto it = etalon.begin( );
    newCou = 0;
    for ( int j = 0; j < 8
; ++j ) {
  if ( circle[ j ] == *it ) {
    ++newCou;
  }
  ++it;
}
if ( newCou < max ) {
  etalon.push_back( etalon.front( ) );
  etalon.pop_front( );
}
}

std::cout << "newCou = " << newCou << std::endl;

for ( auto el : etalon ) {
  std::cout << el << " ";
}

std::cout << std::endl;
std::vector< int > vecEt( etalon.cbegin( ), etalon.cend( ) );
int res = std::abs( s[ 1 ][ 1 ] - 5 );  //центральный только 5 может быть
for ( auto it = vecEt.cbegin( ), jt = circle.cbegin( ); it != vecEt.cend( ); ++it, ++jt ) {
  res += std::abs( *it - *jt );
}
return res;
}

*/
