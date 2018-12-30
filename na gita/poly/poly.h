#ifndef __POLY_H__
#define __POLY_H__
#include<cmath>
#include<iostream>
#include<vector>
//A.F
using namespace std;

class Poly
{
  vector<double> array;

public:
  Poly()
  {
  }
  Poly(float x )
  {
	if( x < 0 )
	     throw exception();        
	else if (array.size() == 0 )
            array.push_back(x) ;
        else 
	    x = array[0]  ;
  }
  double& operator[] (unsigned int size_of_vector)
  {
	if (array.size() <= size_of_vector )
		array.resize( size_of_vector + 1, 0);

	return array[size_of_vector];
  }
  Poly operator+ (const Poly& co) const//zwracam bo jest lokalna zmienna
  {
      Poly n;
      int length ;
      if(this->array.size() > co.array.size()) 
        length = this->array.size() ;
      else 
        length = co.array.size();
      n.array.resize( length, 0 ) ;

      for( int i = 0 ; i < length ; i++ )
      {
        if(this->array.size() > i)
		n.array[i]+=(this->array[i]);
	else
		n.array[i]+=0;
	
	if( co.array.size() > i )
		n.array[i]+=co.array[i];
	else
		n.array[i]+=0;
      }
      return n;
  };
  //friend Poly operator*(int x, Poly p)
  //{
        //return p * x ;
  //}
  double operator()(double x)//opeartor niestatyczny
  {
      double suma = 0 ;
      for( unsigned int i = 0 ; i< array.size() ; i++ )
          suma+=(this->array.at(i)*pow(x,i));

      return suma;
  }
  friend Poly operator* (Poly ca,Poly co) 
  {
      Poly n;
      n.array.resize( ca.array.size() + co.array.size() );
      for( unsigned int i = 0 ; i < n.array.size() ; i++ )
            n.array.at(i) = 0 ;

      for( unsigned int i = 0 ; i < ca.array.size() ; i++ )
      {
        for( unsigned int j = 0 ; j < co.array.size() ; j++ )
                n.array.at(i+j)+= ca.array.at(i) * co.array.at(j);
      }
      return n;
  };
  friend ostream &operator << (ostream &out, const Poly & toWrite)
  {
      for( unsigned int i = toWrite.array.size()-1; i>=0 ; i--)
      {
          if( toWrite.array.at(i)!=0 )
          {
            out << toWrite.array.at(i) ;
            if( i!=0 )
            	out << "x" << i ;
            else if ( i == 0)
                break;

            out<<"+";
          }
      }
    out<<" "<<endl;
    return out;
  };

};
#endif /* __POLY_H__ */
