
#include "timetable.h"

void timetable::print( std::ostream& out ) const
{
   out << "Performance table of " << algo;
   if( version. size( ))
   {
      out << " (version ";
      for( auto p = version. begin( ); p != version. end( ); ++ p )
      {
         if( p != version. begin( ))
            out << "-";
         out << *p;
      }
      out << ")";
   }
   out << " (inputsize/runtime in seconds):\n";
   out << std::scientific;
   for( auto t : times )
   {
      out << "     " << t. first << "/";
      out << std::setprecision(4) << t. second;
   }
   out << "\n";
}

