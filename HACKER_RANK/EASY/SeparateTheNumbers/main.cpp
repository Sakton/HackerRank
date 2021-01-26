#include <iostream>
#include <string>

void separateNumbers( std::string s ) {
  if ( s[ 0 ] == '0' ) {
    std::cout << "NOT" << std::endl;
    return;
  }
  std::string::size_type lenthNum = 1;
  std::string::size_type pos = 0;
  // 1. получить первое число
  int len = 1;
  while ( len <= s.size( ) / 2 ) {
    std::string firstStrNum = s.substr( 0, len );
    //узнаем какое число ждем дальше
    int firstInt = std::stoi( firstStrNum );
    int secondIntOgidanie = firstInt + 1;
    std::string secondStringOgidanie = std::to_string( secondIntOgidanie );
    std::string second = s.substr( len, secondStringOgidanie.size( ) );
    if ( secondStringOgidanie == second ) {  //если ожидаемое сбылось
      std::cout << "second --> " << second << std::endl;
      break;
    } else {
      len++;
    }
  }
  if ( len == s.size( ) / 2 ) {
    std::cout << "NO" << std::endl;
    return;
  }

  //
}

int main( ) {
  // separateNumbers( "1011" );
  // separateNumbers( "91011121314151617" );
  separateNumbers( "9991000" );
  // separateNumbers( "99100" );
}
