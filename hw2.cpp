//Zach Ambroseo, hw2, Testfile

#include <iostream>
#include <cassert>
#include "integer.h"

using namespace std ;

int main ()
{
// test same values
 Integer x1 ("42");
 Integer x2 ("42");
 assert ( x1 == x2 );
 assert (!( x1 != x2 ));
 assert (!( x1 < x2 ));
 assert (!( x1 > x2 ));
 assert ( x1 <= x2 );
 assert ( x1 >= x2 );

// test two different values
 Integer x3 ("50");
 Integer x4 ("57");
 assert ( x3 != x4 );
 assert ( x3 < x4 );
 assert ( x3 <= x4 );
 assert (!( x3 > x4 ));
 assert (!( x3 >= x4 ));
 assert (!( x3 == x4 ));
 assert ( x4 > x3 );
 assert ( x4 >= x3 );
 assert (!( x4 < x3 ));
 assert (!( x4 <= x3 ));

// test adding two different values
 Integer x5 ("99999999999999999999");
 Integer x6 ("1");
 Integer r1 ("100000000000000000000");
 assert ( x5 + x6 == r1 );

// no carry add test
 Integer x7 ("21");
 Integer x8 ("175");
 Integer r2 ("196");
 assert ( x7 + x8 == r2 );

// additional tests for addition , subtraction , and unary minus

// print tests
 cout << " should be 1: " << x6 << endl ;
 cout << " should be 42: " << x1 << endl ;
 cout << " should be 175: " << x8 << endl ;
// etc .
}
