
#ifndef TIMER_INCLUDED
#define TIMER_INCLUDED  1

#include <chrono>
#include <iostream> 

struct timer
{
   std::chrono::system_clock::time_point t0;  
      // Reference time. 

   timer( ) 
      : t0{ std::chrono::system_clock::now( ) }
   { }
  
   timer( const timer& ) = delete;
   const timer& operator = ( const timer& ) const = delete;

   void clear( )
   {
      t0 = std::chrono::system_clock::now( ); 
   }

   // Note that time( ) does not reset. 
   // It returns the time in seconds.

   double time( ) const
   {
      std::chrono::system_clock::time_point t1 =
         std::chrono::system_clock::now( );
      return std::chrono::duration< double > ( t1 - t0 ). count( );
   }

};

#endif

