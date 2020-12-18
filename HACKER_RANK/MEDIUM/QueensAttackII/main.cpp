#include <iostream>

// using Point = std::pair< int, int >;

// int queensAttack( int n, int k, int r_q, int c_q, std::vector< std::vector< int > >&& obstacles );

// Point coordRayEnd( int r_q, int c_q, int drow, int dcol, int n );

// int main( ) { /*circlePoint( 13, nRow( 13, 3 ), 10 );*/
//  // queensAttack( 100000, 1, 100000, 1, { } );
//  // queensAttack( 100000, 1, 100000, 100, { } );
//  // queensAttack( 14, 1, 3, 10, { } );
//  //  auto x = coordRayEnd( 3, 10, 0, 0, 14 );
//  //  std::cout << x.first << ", " << x.second << std::endl;

//  queensAttack( 5, 3, 4, 3, { { 5, 5 }, { 4, 2 }, { 2, 3 } } );
//}

// int queensAttack( int n, int k, int r_q, int c_q, std::vector< std::vector< int > >&& obstacles ) {
//  int count = 3 * ( n - 1 ) + 2 * ( std::min( std::min( r_q, n - 1 - r_q ), std::min( c_q, n - 1 - c_q ) ) );
//  std::vector< Point > rays( 8 );
//  // 1.определить точки концов лучей
//  rays[ 0 ] = coordRayEnd( r_q, c_q, 0, -1, n );
//  rays[ 1 ] = coordRayEnd( r_q, c_q, 1, -1, n );
//  rays[ 2 ] = coordRayEnd( r_q, c_q, 1, 0, n );
//  rays[ 3 ] = coordRayEnd( r_q, c_q, 1, 1, n );
//  rays[ 4 ] = coordRayEnd( r_q, c_q, 0, 1, n );
//  rays[ 5 ] = coordRayEnd( r_q, c_q, -1, 1, n );
//  rays[ 6 ] = coordRayEnd( r_q, c_q, -1, 0, n );
//  rays[ 7 ] = coordRayEnd( r_q, c_q, -1, -1, n );
//  for ( auto el : rays ) std::cout << el.first << ", " << el.second << std::endl;
//  std::cout << "*********" << std::endl;

//  // 2. уравнение прямой: (x - x1)/(x2 - x1) = (y - y1)/(y2 - y1), где (x,y) - проверяемая точка
//  //(x1,y1) - точка королевы
//  //(x2,y2) - точка конца луча
//  // если равеноство верно то проверяемая точка лежит на прямой
//  for ( const auto& el : obstacles ) {
//    for ( auto& rayEndPoint : rays ) {
//      //если это точка прямой
//      int dProvR = std::abs( el[ 0 ] - r_q );
//      int dProvC = std::abs( el[ 1 ] - c_q );
//      int dRayR = std::abs( rayEndPoint.first - r_q );
//      int dRayC = std::abs( rayEndPoint.second - c_q );
//      // if ( std::fabs( dProvR / dRayR - dProvC / dRayC ) <= 1e-3 ) {
//      if ( std::fabs( dProvR * dRayC - dProvC * dRayR ) <= 1e-3 ) {
//        //сравнить расстояние до нее, и до той что в списке
//        int qlenProv = dProvR * dProvR + dProvC * dProvC;
//        int qlenRay = dRayR * dRayR + dRayC * dRayC;
//        if ( qlenProv < qlenRay ) {
//          //если расстояние меньше то записываем эту точку
//          rayEndPoint = std::make_pair( el[ 0 ], el[ 1 ] );
//          std::cout << el[ 0 ] << ", " << el[ 1 ] << std::endl;
//        }
//      }
//    }
//  }

//  std::cout << "*********" << std::endl;
//  std::cout << "*********" << std::endl;

//  for ( auto el : rays ) std::cout << el.first << ", " << el.second << std::endl;
//  std::cout << "*********" << std::endl;
//  std::cout << "*********" << std::endl;
//  std::cout << "*********" << std::endl;

//  return count;
//}

// Point coordRayEnd( int r_q, int c_q, int drow, int dcol, int n ) {
//  if ( drow == 0 && dcol == 0 ) return std::make_pair( r_q, c_q );
//  for ( ; ( r_q <= ( n ) && r_q > 0 ) && ( c_q <= ( n ) && c_q > 0 ); r_q += drow, c_q += dcol )
//    ;
//  r_q -= drow;
//  c_q -= dcol;
//  return std::make_pair( r_q, c_q );
//}

#include <vector>

#include "Point.h"

int queensAttack( int n, int k, int r_q, int c_q, std::vector< std::vector< int > >&& obstacles );

int main( ) {
  std::cout << queensAttack( 5, 3, 4, 3, { { 5, 5 }, { 4, 2 }, { 2, 3 } } );
  return 0;
}

int queensAttack( int n, int k, int r_q, int c_q, std::vector< std::vector< int > >&& obstacles ) {}
