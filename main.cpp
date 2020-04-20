
#include <iostream>
#include <sstream>
#include <random>

#include "set.h"
#include "timetable.h"
#include "timer.h"


// Convert anything to a string:

template< typename T > 
std::string tostring( const T& t ) 
{
   std::ostringstream ind;
   ind << t;
   return ind. str( ); 
}


int main( int argc, char * argv [ ] )
{
   #if 1
   set kaz;
   
   std::cout << kaz. insert( "aqtobe" ) << "\n"; 
   std::cout << kaz. insert( "atyrau" ) << "\n";
   std::cout << kaz. insert( "paris" ) << "\n";
   std::cout << kaz. insert( "paris" ) << "\n";
   std::cout << kaz. insert( "saratov" ) << "\n";
   std::cout << kaz. insert( "dresden" ) << "\n"; 

   for( char c1 = 'a'; c1 <= 'z'; ++ c1 )
      for( char c2 = 'a'; c2 <= 'z'; ++ c2 )
         kaz. insert( std::string( { c1, c2 } )); 

   // If this inserts something, then there is something wrong with your code:

   for( char c1 = 'a'; c1 <= 'z'; ++ c1 )
      for( char c2 = 'a'; c2 <= 'z'; ++ c2 )
      {
         if( kaz. insert( std::string( { c1, c2 } )))
            std::cout << "something is wrong with your code: " << 
                      std::string( { c1, c2 } ) << "\n";
      }

   std::cout << kaz << "\n";
   kaz. printstatistics( std::cout );

   std::cout << kaz. contains( "parijs" ) << "\n";
   std::cout << kaz. contains( "shymkent" ) << "\n";
   std::cout << kaz. contains( "astana" ) << "\n";
      // Try a random string.

   std::cout << kaz << "\n";
   kaz. printstatistics( std::cout );
   
   /////////////////////////////////////////////////////////////////////
   // code copied from previous exercise:
   /////////////////////////////////////////////////////////////////////

   timetable tab( std::string( "set with hashing" ));

   for( size_t s = 1000; s < 1500000; s = 2 * s )
   {
      set someset1;

      timer tt;
      size_t nr = 0;
      for( size_t k = 0; k != s; ++ k )
      {
         nr += someset1. insert( std::string( "aa" ) + tostring<int>( rand( )));
         nr += someset1. insert( std::string( "bb" ) + tostring<int>( rand( )));
      }

      auto someset2 = someset1;

      if( nr != someset1. size( ))
         throw std::runtime_error( "counting went wrong 1" );

      // We go through someset2, in order to make someset1 empty. 

      for( size_t i = 0; i != someset2. getnrbuckets( ); ++ i ) 
      {
         for( const auto& s : someset2. getbucket(i))
         {
            nr -= someset1. remove( s ); 
         }
      }

      if( nr != 0 || someset1. size( ) != 0 )
      {
         std::cout << "nr = " << nr << "\n";
         std::cout << "someset1. size( ) = " << someset1. size( ) << "\n";
         throw std::runtime_error( "counting went wrong 2" );
      }

      tab. insert( s, tt. time( ));
   }

   std::cout << tab << "\n";
   std::cout << "totaltime " << tab. totaltime( ) << "\n"; 
   #endif 
}


