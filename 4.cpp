#include <iostream>
#include <cstring>

using namespace std;

int main(){

    char metin[256];
    int x;

    cout<<"metin    : ";
    cin.getline(metin, 256);

    int len = strlen(metin);

    cout<<"index    : ";
    cin>>x;

    // tekrar sordurtmaya üşendim
    if(x<0) x*=-1;
    if(x>len) x%=len;

    int m = -1, u = -1;

    for(int i = 0, j = 0 ; i<x ; i++){

        if(i==x) continue;

        int i2=i;
        for(j=x ; metin[i2++]==metin[j] ; j++);

        if(j-x>2){

            if(j-x>u){ u = j-x; m = x-i; }

        }

    }

    cout
    <<"mesafe   : "<<m<<endl
    <<"uzunluk  : "<<u;

    return 0;

}