#ifndef POINT_H
#define POINT_H
#include <algorithm>

class Point {
 public:
  Point( int x, int y ) : x_ { x }, y_ { y } {}

  int lenthQuadrat( const Point &op ) { return ( x_ - op.x_ ) * ( x_ - op.x_ ) + ( y_ - op.y_ ) * ( y_ - op.y_ ); }
  Point rayPoint( int drow, int dcol, int n ) {
    if ( drow == 0 && dcol == 0 ) return *this;
    int r = x_;
    int c = y_;
    for ( ; ( r <= ( n ) && r > 0 ) && ( c <= ( n ) && c > 0 ); r += drow, c += dcol )
      ;
    r -= drow;
    c -= dcol;
    return Point( r, c );
  }
  int x( ) const { return x_; }
  int y( ) const { return y_; }

 private:
  int x_;
  int y_;
};

class Line {
 public:
  Line( const Point &a, const Point &b ) : a_ { a }, b_ { b } { };
  bool pointBelongsLine( const Point &p ) {
    return ( p.x( ) - a_.x( ) ) * ( b_.y( ) - a_.y( ) ) == ( p.y( ) - a_.y( ) ) * ( b_.x( ) - a_.x( ) );
  }

  int countPoint( ) { return std::max( std::abs( a_.x( ) - b_.x( ) ), std::abs( a_.y( ) - b_.y( ) ) ); }

 private:
  Point a_;
  Point b_;
};

#endif // POINT_H
