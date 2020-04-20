
#ifndef SET_INCLUDED
#define SET_INCLUDED    1

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cmath>


class set 
{
   
   size_t set_size;           // Total number of elements.

   double max_load_factor;
   std::vector< std::list< std::string >> buckets;
   std::hash< std::string > hash; 
   std::equal_to< std::string > eq;
   
public:
   // Number of buckets cannot be zero. 
   
   set( size_t num_buckets = 4, double max_load_factor = 3.0 ) 
      : set_size{ 0 },
        max_load_factor{ max_load_factor },
        buckets{ std::vector< std::list< std::string >> ( num_buckets ) }
   {
      if( num_buckets == 0 )
         throw std::runtime_error( "number of buckets cannot be zero" ); 
   }

   set(std::initializer_list<std::string>init):
   set_size(0),
   max_load_factor(3.0),
   buckets{ std::vector< std::list< std::string >> (init.size()) }
   {
      for(const std::string& i:init){
         simp_insert(i);
      }
   }


   // X = default, where X is default constructor, copy constructor,
   // assignment, or destructor always means: Apply X on the members.
   // For example, default copy-constructor means: 
   // Call the copy constructors of the members of the class.

   set( const set& s ) = default; 
   set& operator = ( const set& s ) = default; 
   ~set() = default; 

   bool contains( const std::string& s ) const;

   bool simp_insert( const std::string& s );
      // Returns true if the insertion took place.
      // simp_insert is called 'simple', because it does not rehash.

   bool insert( const std::string& s );
      // Returns true if the insertion took place.

   bool remove( const std::string& s );
      // Returns true if s was present.

   size_t size() const
      { return set_size; }

   bool isempty() const
      { return set_size == 0; }

   void clear();
     
   void rehash( size_t newbucketsize );
      // Is this a const operation? Somewhat.
 
   std::ostream& print( std::ostream& out ) const; 


   // The functions below are not part of 
   // the usual set interface, but they are useful for 
   // testing. They are all given, so that you don't have
   // to implement them. 

   double loadfactor() const 
   {
      return static_cast<double> ( set_size ) / buckets. size( ); 
         // C-style casts of form (double) set_size are deprecated. 
   }

   double standarddev() const 
   {
      double sum = 0.0;
      double lf = loadfactor();

      for ( const auto& l : buckets ) 
      {
	  double dif = l.size() - lf;
          sum += dif*dif;
      }

      return sqrt( sum / buckets. size( ));
   }
  
   std::ostream& printstatistics( std::ostream& out ) const;

   size_t getnrbuckets( ) const  
      { return buckets. size( ); }

   const std::list< std::string > & getbucket( size_t i ) const
      { return buckets[i]; }

};


#if 1
inline std::ostream& operator << ( std::ostream& out, const set& s ) 
{
   return s.print( out );
}
#endif 

#endif


