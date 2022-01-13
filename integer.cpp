//Zach Ambroseo, hw2, The implementation file

#include "integer.h"
#include <string>
#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

Integer::Integer(std::string val)
{
 negative=false;
 int n=int(val.size());
 //empty string
 if(n==0)
 {
  digits.push_back(0);
  return;
 }
 
 //leading zero
 if(val[0]=='0' && n>1)
 {
  digits.push_back(0);
  return;
 }
 
 for(int i=n-1; i>=0; --i)
 {
  char cha=val[i];
  if(std::isdigit(c)) {
   digits.push_back('0');
  }
  else
  {
   digits.clear();
   digits.push_back(0);
   return;
  }
 }
}

Integer::Integer()
{
 negative=false;
 digits.push_back(0);
}

bool Integer::operator<(const Integer& rhs) const
{
 if(!negative && !rhs.negative)
  return less_than(digits, rhs.digits);
 if(negative && rhs.negative)
  return less_than(rhs.digits, digits);
 if(negative && !rhs.negative)
  return true;
 return false; 
}

bool Integer::operator>(const Integer& rhs) const
{
 if(!negative && !rhs.negative)
  return less_than(rhs.digits, digits);
 if(negative && rhs.negative)
  return less_than(digits, rhs.digits);
 if(!negative && rhs.negative)
  return true;
 return false; 
}

bool Integer::operator==(const Integer& rhs) const
{
 if(!negative && !rhs.negative)
  if(less_than(digits, rhs.digits)==false && less_than(rhs.digits, digits)==false)
   return true;
 if(negative && rhs.negative)
  if(less_than(rhs.digits, digits)==false && less_than(digits, rhs.digits)==false)
   return true;
 return false;
} 
bool Integer::operator<=(const Integer& rhs) const
{
 if(!negative && rhs.negative)
  return false;
 if(!negative && !rhs.negative)
  if(less_than(rhs.digits, digits))
   return false;
 if(negative && rhs.negative)
  if(less_than(digits, rhs.digits)==true)
   return false;
 return true;
}

bool Integer::operator>=(const Integer& rhs) const
{
 if(negative && !rhs.negative)
  return false;
 if(!negative && !rhs.negative)
  if(less_than(digits, rhs.digits))
   return false;
 if(negative && rhs.negative)
  if(less_than(rhs.digits, digits)==true)
   return false;
 return true;
}
bool Integer::operator!=(const Integer& rhs) const
{
 if(!negative && !rhs.negative)
  if(less_than(digits, rhs.digits)==false && less_than(rhs.digits, digits)==false)
   return false;
 if(negative && rhs.negative)
  if(less_than(rhs.digits, digits)==false && less_than(digits, rhs.digits)==false)
   return false;
 return true;
}

Integer Integer::operator+(const Integer& rhs) const
{
 Integer temp;
 temp.digits= add(digits, rhs.digits);
 return temp;
}

Integer Integer::operator-(const Integer & rhs) const
{
 Integer temp;
 if(!negative && !rhs.negative)
 {
  if(*this<rhs)
  {
   temp.sub(rhs.digits, digits);
   temp.operator-();
   return temp;
  }
  if(*this>rhs)
  {
   temp.sub(digits, rhs.digits);
   return temp;
  }
  if(*this==rhs)
  {
   temp.sub(digits, rhs.digits);
   return temp;
  }
 }  
 if(negative && !rhs.negative)
 {
  temp.add(rhs.digits, digits);
  temp.operator-();
  return temp;
 }
 if(!negative && rhs.negative)
 {
  temp.add(digits,rhs.digits);
  return temp;
 }

 if(negative && rhs.negative)
 {
  if(*this<rhs)
  {
   temp.sub(rhs.digits, digits);
   return temp;
  }
  if(*this>rhs)
  {
   temp.sub(digits, rhs.digits);
   temp.operator-();
   return temp;
  }
  if(*this==rhs)
  {
   temp.sub(digits, rhs.digits);
   return temp;
  }
 }
 return temp;
}

Integer Integer:: operator-() const
{
	Integer temp;
	temp.negative= !negative;
	temp.digits=digits;
	return temp;
}


bool Integer::less_than(const digit_list& lhs, const digit_list& rhs) const
{
 if(lhs.size()<rhs.size())
  return true;
 if(lhs.size()>rhs.size())
  return false;
 for(int i=digits.size()-1;i>=0;--i)
 {
  if(lhs[i]<rhs[i])
   return true;
  if(lhs[i]>rhs[i])
   return false;
 }
 return false;
}


digit_list Integer::sub(const digit_list & lhs , const digit_list & rhs ) const 
{
Integer temp;
 int carry=0;
 int tmp=0;
 int size=0;
 int altsize=0;
 if(lhs.size()>rhs.size())
 {
  size=rhs.size();
  altsize=lhs.size();
  for(int i=0; i< size; i++)
   {
    tmp=lhs[i];
    if(carry>0)
    {
     tmp=tmp-1;
     carry--;
    }
    if(tmp>=rhs[i])
     {
     tmp=tmp-rhs[i];
     }
    else if(tmp<rhs[i])
    {
     carry++;
     tmp=tmp+10;
     tmp=tmp-rhs[i];
    }
    temp.digits.push_back(tmp);
    tmp=0;
   }
  for(int i=size; i<altsize;i++)
  {
   tmp=lhs[i];
   if(carry>0)
   {
    tmp=tmp-1;
    carry--;
   }
   temp.digits.push_back(tmp);
   tmp=0;
  }
 }
 else
 {
  altsize=lhs.size();
  for(int i=0; i< altsize; i++)
  {
   tmp=lhs[i];
   if(carry>0)
   {
    tmp=tmp-1;
    carry--;
   }
   if(tmp>=rhs[i])
    tmp=tmp-rhs[i];
   else if(tmp<rhs[i])
   {
    carry++;
    tmp=tmp+10;
    tmp=tmp-rhs[i];
   }
   temp.digits.push_back(tmp);
   tmp=0;
  }
 }
 return temp.digits;
}

digit_list Integer:: add( const digit_list & lhs , const digit_list & rhs ) const
{
Integer temp;
 int carry=0;
 int tmp=0;
 int size=0;//size of the smaller Integer vector
 int altsize=0;//size of the larger Ingeger Vector
 //determine which side is larger than add the two vector to the size of the smaller and after input the remaining values of the larger vector along with carry.
 if(lhs.size()>rhs.size())
 {
   size=rhs.size();
   altsize=lhs.size();
   for(int i=0; i< size; i++)
   {
    tmp=lhs[i]+rhs[i];
    if(carry>0)
    {
     tmp=tmp+carry;
     carry--;
    }
    if(tmp >=10)
    {
     carry ++;
     tmp=tmp-10;
    }
    temp.digits.push_back(tmp);
    tmp=0;
   }
   for(int i= size; i<altsize; i++)
   {
    tmp=lhs[i];
    if(carry>0)
    {
     tmp=tmp+carry;
     carry--;
    }
    if(tmp>=10)
    {
     carry++;
     tmp=tmp-10;
    }
    temp.digits.push_back(tmp);
    tmp=0;
   }
   if(carry>0)
   {
    temp.digits.push_back(carry);
    size++;
   }
 }
 else if(lhs.size()<rhs.size())
 {
  size=lhs.size();
  altsize=rhs.size();
  for(int i=0; i< size; i++)
  {
   tmp=lhs[i]+rhs[i];
   if(carry>0)
   {
    tmp=tmp+carry;
    carry--;
   }
   if(tmp >=10)
   {
    carry ++;
    tmp=tmp-10;
   }
   temp.digits.push_back(tmp);
   tmp=0;
  }
  for(int i= size; i<altsize; i++)
  {
   tmp=rhs[i];
   if(carry>0)
   {
    tmp=tmp+carry;
    carry--;
   }
   if(tmp>=10)
   {
    carry++;
    tmp=tmp-10;
   }
   temp.digits.push_back(tmp);
   tmp=0;
  }
  if(carry>0)
  {
   temp.digits.push_back(carry);
   size++;
  }
 }
 else
 {
  altsize=lhs.size();
  for(int i=0; i< altsize; i++)
  {
   tmp=lhs[i]+rhs[i];
   if(carry>0)
   {
    tmp=tmp+carry;
    carry--;
   }
   if(tmp >=10)
   {
    carry ++;
    tmp=tmp-10;
   }
   temp.digits.push_back(tmp);
   tmp=0;
  }
  if(carry>0)
  {
   temp.digits.push_back(carry);
   size++;
  }
 }
 return temp.digits;
}

std:: ostream& operator<<( std :: ostream & out , const Integer& val )
{
 int size=val.digits.size();
 for(int i=size-1; i>=0; i--)
 {
  out<< val.digits[i];
 }
 return out;
}
