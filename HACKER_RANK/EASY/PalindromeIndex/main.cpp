#include <iostream>
#include <string>

int palindromeIndex( std::string s ) {
  int ind = -1;
  int i = 0;
  int j = s.size( ) - 1;
  for ( ; i < j && s[ i ] == s[ j ]; ++i, --j )
    ;
  if ( i < j ) {
    int l = i + 1;
    int r = j;
    for ( ; l < r && s[ l ] == s[ r ]; ++l, --r )
      ;
    if ( l >= r )
      ind = i;
    else {
      l = i;
      r = j - 1;
      for ( ; l < r && s[ l ] == s[ r ]; ++l, --r )
        ;
      if ( l >= r ) ind = j;
    }
  }
  return ind;
}

int main( ) {
  // std::cout << palindromeIndex( "aaab" ) << std::endl;
  // std::cout << palindromeIndex( "aaaa" ) << std::endl;
  //  std::cout << palindromeIndex( "baa" ) << std::endl;
  std::cout << palindromeIndex( "hgygsvlfcwnswtuhmyaljkqlqjjqlqkjlaymhutwsnwcwflvsgygh" ) << std::endl;
  return 0;
}
