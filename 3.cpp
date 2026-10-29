#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

struct node{

    char letter = '\0';
    node* left = nullptr;
    node* right = nullptr;
    int count = 0;

};

void bit(unsigned char a, int depth, char* r) {
    int j = 0;
    
    for (int i = depth - 1; i >= 0; i--) {
        if ((a & (1 << i)) != 0) {
            r[j++] = '1';
        } else {
            r[j++] = '0';
        }
    }
    
    r[j] = '\0';

}

void dict(node* tree, unsigned char a=0, int count=0){

    if(tree->letter =='\0'){

        dict(tree->left, a<<1 ,count+1);
        
        dict(tree->right, (a<<1)+1 ,count+1);

        return;

    }

    char r[9];
    bit(a,count,r);
    cout <<tree->letter<<" : "<<r<<endl<<endl;

    return;

}

int main(){

    char metin[256] = {};
    int asc[256] = {};

    node letters[512];

    cout<<"metin gir."<<endl;
    cin.getline(metin, 256);
    
    int len = strlen(metin);

    for(int i=0;i<len;i++){

        asc[(unsigned)metin[i]]++;

    }

    int tc=0;

    for(int i=0;i<256;i++){

        if(asc[i]>0){
            letters[tc].letter = char(i);
            letters[tc].count = asc[i];
            tc++;
        }

    }

    for(int i=0; i<tc; i=i+2){

        if(i+1>=tc){ tc--; break; }

        int ek1, ek2, k1, k2;

        ek1 = ek2 = 2147483647;//INT_MAX
        k1 = k2 = -1;
    
        for(int j=i;j<tc;j++){

            if(ek1>letters[j].count){

                ek2 = ek1;
                k2 = k1;

                ek1=letters[j].count;
                k1=j;

            }else if(ek2>letters[j].count){

                ek2=letters[j].count;
                k2=j;

            }

        }

        node tmp = letters[i];
        letters[i] = letters[k1];
        letters[k1] = tmp;

        tmp = letters[i+1];
        letters[i+1] = letters[k2];
        letters[k2] = tmp;

        letters[tc].right = &letters[i];
        letters[tc].left = &letters[i+1];
        letters[tc].count = letters[i].count + letters[i+1].count;
        
        tc++;

    }

    dict(&letters[tc]);

    return 0;

}

/*
    int tmp=0; 
    bool k=true; 

    for(int j=0;j<tmp;j++){

        if(metin[i]==letters[j].letter){
            letters[j].count++; 
            k=false; 
            break; 
        }

    } 

    if(k){
        letters[tmp].letter = metin[i];
        letters[tmp].count++; tmp++; 
    }

*/