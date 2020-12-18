#ifndef POINT_H
#define POINT_H
#include <algorithm>
#include <iostream>

class Point {
 public:
  Point( int row, int col ) : row_ { row }, col_ { col }, changed { false } {}
  int lenthQuadrat( const Point &op ) { return ( col_ - op.col_ ) * ( col_ - op.col_ ) + ( col_ - op.col_ ) * ( col_ - op.col_ ); }
  Point rayPoint( int drow, int dcol, int n ) {
    if ( drow == 0 && dcol == 0 ) return *this;
    int r = row_;
    int c = col_;
    for ( ; ( r <= ( n ) && r > 0 ) && ( c <= ( n ) && c > 0 ); r += drow, c += dcol )
      ;
    r -= drow;
    c -= dcol;
    return Point( r, c );
  }
  int row( ) const { return row_; }
  int col( ) const { return col_; }
  void change( ) { changed = true; };
  bool isChanged( ) const { return changed; };

 private:
  int row_;
  int col_;
  bool changed;
};

class Line {
 public:
  Line( const Point &a, const Point &b ) : a_ { a }, b_ { b } { };
  bool pointBelongsLine( const Point &p ) {
    if ( ( p.col( ) - a_.col( ) ) * ( b_.row( ) - a_.row( ) ) == ( p.row( ) - a_.row( ) ) * ( b_.col( ) - a_.col( ) ) ) {
      int rowMax = std::max( a_.row( ), b_.row( ) );
      int rowMin = std::min( a_.row( ), b_.row( ) );
      int colMax = std::max( a_.col( ), b_.col( ) );
      int colMin = std::min( a_.col( ), b_.col( ) );

      if ( ( rowMin <= p.row( ) && p.row( ) <= rowMax ) && ( colMin <= p.col( ) && p.col( ) <= colMax ) ) {
        return true;
      }
    }
    return false;
  }
  int countPoint( ) {
    int len = std::max( std::abs( a_.col( ) - b_.col( ) ), std::abs( a_.row( ) - b_.row( ) ) );
    if ( b_.isChanged( ) ) --len;
    return len;
  }
  Point getB( ) const { return b_; }
  void setB( const Point &b ) {
    b_ = b;
    b_.change( );
  }

 private:
  Point a_;
  Point b_;
};

// class Point {
// public:
//  Point( int row, int col ) : row_ { row }, col_ { col }, changed { false } {}

//  int lenthQuadrat( const Point &op ) { return ( col_ - op.col_ ) * ( col_ - op.col_ ) + ( col_ - op.col_ ) * ( col_ - op.col_ ); }
//  Point rayPoint( int drow, int dcol, int n ) {
//    if ( drow == 0 && dcol == 0 ) return *this;
//    int r = row_;
//    int c = col_;
//    for ( ; ( r <= ( n ) && r > 0 ) && ( c <= ( n ) && c > 0 ); r += drow, c += dcol )
//      ;
//    r -= drow;
//    c -= dcol;
//    return Point( r, c );
//  }
//  int row( ) const { return row_; }
//  int col( ) const { return col_; }
//  void change( ) { changed = true; };
//  bool isChanged( ) const { return changed; };

//  friend std::ostream &operator<<( std::ostream &out, const Point &p ) { return out << "Point: " << p.row( ) << ":" << p.col( ); }

// private:
//  int row_;
//  int col_;
//  bool changed;
//};

// class Line {
// public:
//  Line( const Point &a, const Point &b ) : a_ { a }, b_ { b } { };
//  bool pointBelongsLine( const Point &p ) {
//    //если точка на прямой
//    if ( ( p.col( ) - a_.col( ) ) * ( b_.row( ) - a_.row( ) ) == ( p.row( ) - a_.row( ) ) * ( b_.col( ) - a_.col( ) ) ) {
//      //принадлежит ли она отрезку
//      int rowMax = std::max( a_.row( ), b_.row( ) );
//      int rowMin = std::min( a_.row( ), b_.row( ) );
//      int colMax = std::max( a_.col( ), b_.col( ) );
//      int colMin = std::min( a_.col( ), b_.col( ) );

//      if ( ( rowMin <= p.row( ) && p.row( ) <= rowMax ) && ( colMin <= p.col( ) && p.col( ) <= colMax ) ) {
//        return true;
//      }
//    }
//    return false;
//  }
//  int countPoint( ) {
//    int len = std::max( std::abs( a_.col( ) - b_.col( ) ), std::abs( a_.row( ) - b_.row( ) ) );
//    if ( b_.isChanged( ) ) --len;
//    return len;
//  }

//  Point getB( ) const { return b_; }
//  void setB( const Point &b ) {
//    b_ = b;
//    b_.change( );
//  }

//  friend std::ostream &operator<<( std::ostream &out, const Line &l ) { return out << "Line: " << l.a_ << " : " << l.b_; }

// private:
//  Point a_;
//  Point b_;
//};

#endif  // POINT_H
