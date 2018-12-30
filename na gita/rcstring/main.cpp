#include "rcstring.h"
//A.F
int main()
{
rcstring a,b,c;
a="10";
b="ala ma kota";
cout << a << " " << b << endl; // 10 ala ma ma kota
c=a+b;
cout << c<<endl; // 10ala ma kota
c=a+rcstring(" ")+b;
cout << c << endl; //10 ala ma kota
rcstring d("a");
cout << d <<endl; //a
d+="ula";
cout << d << endl; //aula
d+="15";
cout << d << endl; //aula15
cout << d[3]<<endl; //a
d[3]='b';
cout << d << endl; //aulb15
d[2]=d[1]=d[0];
cout << d << endl; //aaab15

rcstring qaz = "ORZEszkowa MAniA";
cout<<qaz.toLower()<<endl;

rcstring w = "-6234as";
int x = w.atoi();
cout<<"atoi "<<x<<endl;

rcstring lol = "123sdfa9873423asdasdasd";
cout<<lol.Left(6)<<endl;

return 0;
}
