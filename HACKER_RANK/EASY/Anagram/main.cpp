#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int anagram( string s ) {
  string::size_type sz = s.size( );
  if ( sz % 2 != 0 ) return -1;
  vector< int > counts( 26, 0 );
  for ( string::size_type i = 0, j = sz - 1; i < sz / 2; ++i, --j ) {
    counts[ s[ i ] - 'a' ]++;
    counts[ s[ j ] - 'a' ]--;
  }
  int count1 = 0;
  int count2 = 0;
  for ( auto el : counts ) {
    if ( el > 0 )
      count1 += el;
    else if ( el < 0 )
      count2 += std::abs( el );
  }
  return min( count1, count2 );
}

/*
hhpddlnnsjfoyxpciioigvjqzfbpllssuj

xulkowreuowzxgnhmiqekxhzistdocbnyozmnqthhpievvlj

dnqaurlplofnrtmh

aujteqimwfkjoqodgqaxbrkrwykpmuimqtgulojjwtukjiqrasqejbvfbixnchzsahpnyayutsgecwvcqngzoehrmeeqlgknnb

lbafwuoawkxydlfcbjjtxpzpchzrvbtievqbpedlqbktorypcjkzzkodrpvosqzxmpad

drngbjuuhmwqwxrinxccsqxkpwygwcdbtriwaesjsobrntzaqbe

ubulzt

vxxzsqjqsnibgydzlyynqcrayvwjurfsqfrivayopgrxewwruvemzy

xtnipeqhxvafqaggqoanvwkmthtfirwhmjrbphlmeluvoa

gqdvlchavotcykafyjzbbgmnlajiqlnwctrnvznspiwquxxsiwuldizqkkaawpyyisnftdzklwagv
*/

int main( ) {
  //  std::cout << anagram( "aaabbb" ) << std::endl;
  //  std::cout << anagram( "ab" ) << std::endl;
  //  std::cout << anagram( "abc" ) << std::endl;
  //  std::cout << anagram( "mnop" ) << std::endl;
  //  std::cout << anagram( "xyyx" ) << std::endl;
  //  std::cout << anagram( "xaxbbbxx" ) << std::endl;
  std::cout << anagram( "hhpddlnnsjfoyxpciioigvjqzfbpllssuj" ) << std::endl;  // 10
  std::cout << anagram( "xulkowreuowzxgnhmiqekxhzistdocbnyozmnqthhpievvlj" ) << std::endl;
  std::cout << anagram( "dnqaurlplofnrtmh" ) << std::endl;
  std::cout << anagram( "aujteqimwfkjoqodgqaxbrkrwykpmuimqtgulojjwtukjiqrasqejbvfbixnchzsahpnyayutsgecwvcqngzoehrmeeqlgknnb" ) << std::endl;
  std::cout << anagram( "lbafwuoawkxydlfcbjjtxpzpchzrvbtievqbpedlqbktorypcjkzzkodrpvosqzxmpad" ) << std::endl;
  std::cout << anagram( "drngbjuuhmwqwxrinxccsqxkpwygwcdbtriwaesjsobrntzaqbe" ) << std::endl;
  std::cout << anagram( "ubulzt" ) << std::endl;
  std::cout << anagram( "vxxzsqjqsnibgydzlyynqcrayvwjurfsqfrivayopgrxewwruvemzy" ) << std::endl;
  std::cout << anagram( "xtnipeqhxvafqaggqoanvwkmthtfirwhmjrbphlmeluvoa" ) << std::endl;
  std::cout << anagram( "gqdvlchavotcykafyjzbbgmnlajiqlnwctrnvznspiwquxxsiwuldizqkkaawpyyisnftdzklwagv" ) << std::endl;
}
