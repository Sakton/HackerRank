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
    //    while ( fact_.back( ) == 0 ) fact_.pop_back( );
    auto t = std::find_if( fact_.begin( ), fact_.end( ), []( int x ) { return ( x != 0 ); } );
    fact_.erase( fact_.begin( ), t );
    //    std::reverse( fact_.begin( ), fact_.end( ) );
    for ( auto el : fact_ ) std::cout << el;
    std::cout << std::endl;
  }

  void mult( int n ) {
    type t( fact_.size( ) + 1 );
    //    for ( type::size_type i = 0; i < fact_.size( ); ++i ) {
    //      int a = fact_[ i ] * n;
    //      t[ i ] = a;
    //    }
    //    for ( type::size_type i = 0; i < t.size( ) - 1; ++i ) {
    //      t[ i + 1 ] += t[ i ] / BASE;
    //      t[ i ] %= BASE;
    //    }

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
  // TODO на 20 факториале проблемы с нулями
  b.factorial( 19 );
}
