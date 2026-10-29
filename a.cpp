#include <iostream>
#include <cstring>

using namespace std;

struct member{

    char letter;
    int offset:15;
    int length:4;

};

int main(){

    char metin[255];
    member mList[255];

    int a=0;

    cout<<"metin: "<<endl;
    cin.getline(metin,255);

    int len = strlen(metin);

    for(int i=0;i<len;i++){

        int u=0;
        int m=0;
        
        for(int j=0;j<i;j++){

            int i2=i;

            int t=j;
            
            while(metin[t]==metin[i2]){i2++; t++;}

            if(i2-i>2){

                if(i2-i>=u){
                    u=t-j;
                    m=i2-t;
                }

            }

        }

        if(u<3)
            cout<<metin[i];    
                    
        else{
            cout<<'('<<m<<','<<u<<')';
            i+=u-1;
        }

    }

    return 0;

}