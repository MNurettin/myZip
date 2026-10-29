#include <iostream>
#include <cstring>

using namespace std;

int main(){

    while(true){

        char metin[256] = {};

        cout<<"\n\nmetin    : ";
        cin.getline(metin, 256);

        int len = strlen(metin);

        int t = 0;

        for(int x=0;x<len;x++){

            int m = -1, u = -1;

            for(int i = 0, j = 0 ; i<x ; i++){

                int i2=i;
                for(j=x ; metin[i2++]==metin[j] ; j++);

                if(j-x>2){

                    if(j-x>u){ u = j-x; m = x-i; }

                }

            }

            if(u<3){
                cout<<metin[x];
            }else{
                cout<<"("<<m<<","<<u<<")";
                x+=u-1;
            }


        }

    }

    return 0;

}