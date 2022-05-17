//a: void func(const int a);     做為參數使用，說明函數內是不能修改該參數的。
//b: const int func();           做為返回值使用，說明函數的返回值是不能被修改的。
//c: int func() const;           常數函數，說明函數是不能修改該類別中成員的值的，只能用於類別的成員函數中。
#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
class FRACTION{
  friend bool operator==(const FRACTION& left,FRACTION& right);
  friend bool operator!=(const FRACTION& left,FRACTION& right);

  private:
   int numer,denom;
   int gcd(int n,int m){
     int gcd=1;
     for(int k=1;k<=n&&k<=m;k++){
       if(n%k==0&&m%k==0)gcd=k;
     }
     return gcd;
   }
   void normalize(){
      if(denom==0){
        cout<<"Invalid denominator in fraction"<<endl;
        assert(false);
      }
      if(denom<0){
        denom=-denom;
        numer=-numer;
      }
      int divisor=gcd(abs(numer),abs(denom));
      numer=numer/divisor;
      denom=denom/divisor;
   }
   public:
      FRACTION():numer(0),denom(1){};
      FRACTION(int n,int d):numer(n),denom(d){}
      void print(){
        cout<<numer<<"/"<<denom<<endl;
      }


      const FRACTION operator+(){
          FRACTION temp(numer,denom);
          return temp;
      }
      const FRACTION operator-(){
          FRACTION temp(-numer,denom);
          return temp;
      }
      FRACTION &operator++(){//preincrement ++f1
        numer=numer+denom;
        this->normalize();
        return *this;
      }
      FRACTION &operator--(){//predecrement  --f1
        numer=numer-denom;
        this->normalize();
        return *this;
      }
      FRACTION& operator+=(const FRACTION& right){
        numer=numer*right.denom+denom*right.numer;
        denom=denom*right.denom;
        normalize();
        return *this;
      }

};
bool operator==(const FRACTION& left,FRACTION& right){
        return (left.numer*right.denom==right.numer*left.denom);
  }
bool operator!=(const FRACTION& left,FRACTION& right){
        return (left.numer*right.denom==right.numer*left.denom);
  }
int main(){
     FRACTION f1(1,2),f2(1,2),f3;
     f1.print();
     f2.print();
     if(f1==f2)cout<<"HO HO"<<endl;
     f1+=f2;//f1=f1+f2
     ++f1;
     ++f1;
     f1.print();
     f2.print();
}