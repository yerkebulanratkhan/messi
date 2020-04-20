/*
 * set.cpp
 *
 *  Created on: Mar 18, 2019
 *      Author: benja
 */


#include "set.h"

// (your code here)

bool set::simp_insert(const std::string& s){
   size_t h = hash(s)%buckets.size();
   if (contains(s)==true){
      return false;
   }
   else {
      buckets[h].push_back(s);
      set_size++;
      return true;
   }
}
         
bool set::contains( const std::string& s ) const {
   size_t h = hash(s)%buckets.size();
   if (buckets[h].empty()==true){
      return false;
   }
   else {
      std::list< std::string > ::const_iterator it=((buckets[h]).begin());
      for ( ; it!=buckets[h].end(); it++){
         if (*it==s){
            return true;
         }
      }
   }
   return false;
}

bool set::remove( const std::string& s ){
   if (contains(s)==false){
      return false;
   }
   else {
      size_t h = hash(s)%buckets.size();
      buckets[h].remove(s);
      set_size--;
      return true;
   }
}

void set::clear(){
   std::vector< std::list< std::string >> newbuckets = 
   std::vector< std::list< std::string >> ( buckets.size() );
   std::swap(buckets, newbuckets);
   set_size=0;
}

void set::rehash( size_t newbucketsize ){
   if (newbucketsize<4){
      newbucketsize=4;
   }
   std::vector< std::list< std::string >> newbuckets = 
   std::vector< std::list< std::string >> ( newbucketsize );
   for (size_t i=0; i<buckets.size(); i++){
      std::list< std::string > ::const_iterator it=((buckets[i]).begin());
      for ( ; it!=buckets[i].end(); it++){
         size_t h = hash(*it)%newbuckets.size();
         newbuckets[h].push_back(*it);
      }
   }
   std::swap(buckets, newbuckets);
}

bool set::insert( const std::string& s ){
   if (simp_insert(s)==false){
      return false;
   }
   if (loadfactor()>max_load_factor){
      rehash(2*buckets.size());
   }
   return true;
}


std::ostream& set::printstatistics( std::ostream& out ) const
{
   out << "set size =            " << size( ) << "\n";
   out << "load factor =         " << loadfactor( ) << " ( max = " << max_load_factor << " )\n";
   out << "standard deviation =  " << standarddev( ) << "\n";
   return out;
}

std::ostream& set::print( std::ostream& out ) const
{
   for (size_t i=0; i<buckets.size(); i++){
      out << "#" << i << "| ";
      std::list< std::string > ::const_iterator it=((buckets[i]).begin());
      for ( ; it!=buckets[i].end(); it++){
         out << " - " << *it ; 
      }
      out << "\n";
   }
   return out;
}