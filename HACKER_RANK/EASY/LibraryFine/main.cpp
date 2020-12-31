#include <iostream>

int libraryFine( int d1, int m1, int y1, int d2, int m2, int y2 );

// 2 7 1014   1 1 1015

int main( ) {
  std::cout << libraryFine( 6, 6, 2015, 9, 6, 2015 );
  // std::cout << libraryFine( 2, 7, 1014, 1, 1, 1015 );
}
// 1 - дата фактическая
// 2 - дата ожидаемая

int libraryFine( int d1, int m1, int y1, int d2, int m2, int y2 ) {
  int constexpr DAY_PENALTY = 15;
  int constexpr MONTH_PENALTY = 500;
  int constexpr YEAR_PENALTY = 10000;
  if ( y1 < y2 )
    return 0;
  else if ( y1 == y2 ) {
    if ( m1 < m2 )
      return 0;
    else if ( m1 > m2 )
      return ( m1 - m2 ) * MONTH_PENALTY;
    else {
      if ( d1 <= d2 ) return 0;
      return ( d1 - d2 ) * DAY_PENALTY;
    }
  }
  return YEAR_PENALTY;
}

// int libraryFine( int d1, int m1, int y1, int d2, int m2, int y2 ) {
//  int constexpr DAY_PENALTY = 15;
//  int constexpr MONTH_PENALTY = 500;
//  int constexpr YEAR_PENALTY = 10000;
//  int fine = 0;
//  if ( y1 - y2 <= 0 ) {
//    if ( m1 - m2 <= 0 ) {
//      if ( d1 - d2 <= 0 ) {
//        fine = 0;
//      } else {
//        fine = ( d1 - d2 ) * DAY_PENALTY;
//      }
//    } else {
//      fine = ( m1 - m2 ) * MONTH_PENALTY;
//    }
//  } else {
//    fine = YEAR_PENALTY;
//  }

//  // if ( y1 >= y2 )
//  return fine;
//}
