//Zach Ambroseo, hw2, header file

#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <vector>
#include <iostream>

typedef std :: vector <int > digit_list ; // int is really too big ( for 0 to 9)

class Integer
{
 public :
  Integer();
// overloaded constructor , set to given string value (of all digits )
  Integer( std :: string val );

// unary negation operator
  Integer operator-();
// binary addition operator
  Integer operator+(const Integer & rhs) const ;
// binary subtraction operator
  Integer operator-(const Integer & rhs) const;

// six relational comparison operators
  bool operator<(const Integer& rhs) const;
  bool operator>(const Integer& rhs) const;
  bool operator==(const Integer& rhs) const;
  bool operator<=(const Integer& rhs) const;
  bool operator>=(const Integer& rhs) const;
  bool operator!=(const Integer& rhs) const;



// output an Integer to ostream
  friend std :: ostream & operator <<( std :: ostream & out , const Integer & val );

 private :
  digit_list digits ; // least significant digit first ( little endian )
  bool negative ; // true if the value is less than zero

// private helpers for adding and subtracting digit lists
  digit_list add(const digit_list & lhs , const digit_list & rhs) const ;
  digit_list sub(const digit_list & lhs , const digit_list & rhs) const ;
// private helper to check if lhs is less - than the rhs
  bool less_than(const digit_list & lhs , const digit_list & rhs) const ;
};

#endif
