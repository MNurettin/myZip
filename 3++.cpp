#include <iostream>
#include <cstring>
#define int_max 2147483647

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
        r[j++] = '0' + ((a >> i) & 1);
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
    cout <<tree->letter<<" : "<<r<<"\n\n";

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
    
    while(true){

        int ek1, ek2, k1, k2;

        ek1 = ek2 = int_max;
        k1 = k2 = -1;
    
        for(int j=0;j<tc;j++){

            int tmp;

            if(ek1>(tmp = letters[j].count)){

                ek2 = ek1;
                k2 = k1;

                ek1=tmp;
                k1=j;

            }else if(ek2>tmp){

                ek2=tmp;
                k2=j;

            }

        }

        if(k2==-1) break;

        letters[tc].left = &letters[k1];
        letters[tc].right = &letters[k2];
        letters[tc].count = ek1 + ek2;

        letters[k1].count = letters[k2].count = int_max;
        
        tc++;

    }


    dict(&letters[tc-1]);

    return 0;

}