#include <algorithm>
#include <iostream>
#include <vector>

class BigFactorial {
  using type = std::vector< int >;
  const int BASE = 1e4;

 public:
  explicit BigFactorial( ) : fact_( 1, 1 ) {}

  void factorial( int n ) {
    while ( n > 1 ) {
      mult( n );
      --n;
    }
    auto t = std::find_if( fact_.begin( ), fact_.end( ), []( int x ) { return ( x != 0 ); } );
    fact_.erase( fact_.begin( ), t );
  }

  void print( ) const {
    for ( type::size_type i = 0; i < fact_.size( ); ++i ) {
      int k = 0;
      if ( i ) {
        if ( fact_[ i ] < 10 ) {
          k = 3;
        } else if ( fact_[ i ] < 100 ) {
          k = 2;
        } else if ( fact_[ i ] < 1000 ) {
          k = 1;
        }
        for ( int i = 0; i < k; ++i ) std::cout << 0;
      }
      std::cout << fact_[ i ];
    }
  }

 private:
  void mult( int n ) {
    type t( fact_.size( ) + 1 );
    for ( int i = fact_.size( ) - 1; i >= 0; --i ) {
      int a = fact_[ i ] * n;
      t[ i + 1 ] = a;
    }
    for ( int i = t.size( ) - 1; i >= 1; --i ) {
      t[ i - 1 ] += t[ i ] / BASE;
      t[ i ] %= BASE;
    }
    fact_.swap( t );
  }

 private:
  type fact_;
};

int main( ) {
  BigFactorial b;
  b.factorial( 50 );
  b.print( );
}
