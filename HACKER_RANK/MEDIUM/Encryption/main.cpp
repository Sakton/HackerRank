#include <iostream>
#include <string>
#include <vector>

std::string encryption( std::string s ) {
  std::string trim;
  std::string::size_type idx = 0;
  std::string::size_type end = 0;
  while ( idx != std::string::npos ) {
    idx = s.find( " ", idx );
    if ( idx != std::string::npos ) {
      trim += s.substr( end, idx - end );
      ++idx;
      end = idx;
    } else {
      trim += s.substr( end, s.size( ) );
    }
  }
  std::string::size_type len = trim.size( );
  std::string::size_type row = std::sqrt( len );
  std::string::size_type col = 0;
  if ( row * row == len ) {
    col = row;
  } else {
    col = row + 1;
  }
  std::vector< std::string > vs;
  std::string::size_type pos = 0;
  while ( pos < trim.size( ) ) {
    vs.push_back( trim.substr( pos, col ) );
    while ( vs.back( ).size( ) < col ) {
      vs.back( ).push_back( ' ' );
    }
    pos += col;
  }
  std::string res;
  for ( std::string::size_type c = 0; c < col; ++c ) {
    std::string e;
    for ( auto &el : vs ) e.push_back( el[ c ] );
    res += e;
    if ( e.back( ) != ' ' ) res += ' ';
  }
  return res;
}

int main( ) {
  // std::cout << encryption( "havean ice day" ) << std::endl;
  std::cout << encryption( "feedthedog" ) << std::endl;
  // std::cout << encryption( "chillout" ) << std::endl;
  // std::cout << encryption( "wclwfoznbmyycxvaxagjhtexdkwjqhlojykopldsxesbbnezqmixfpujbssrbfhlgubvfhpfliimvmnny" ) << std::endl;
  // wmgjpnull cyjqlejgi lyhhdzbui wctlsqsbm fxeoxmsvv ovxjeirfm zadysxbhn nxkkbffpn bawobphfy
}
