#include <iostream>
#include <string>

using namespace std;

int main(){

    int x[4];

    unsigned char out='w';
    

    cout<<"0-3 4 sayi gir"<<endl;
    cin>>x[0]>>x[1]>>x[2]>>x[3];

    for(int i=3;0<=i;i--){

        x[i]%=4;//hatalı girişte tekrar istetmeye üşendim

       out = (out << 2) | x[i]; 
       // char geçici olaran int olur. taşan veriler soldaki byte gider. 
       //atama sırasında soldaki byte kullanılabilir, kullanılmazsa veri silinir. 

    }

    cout<<(int)out;

    return 0;

}