#include <iostream>
#include <string>

using namespace std;

char hasha(char a){

    return a^('b');

}

bool confirm(char a, char b){

    return (b^'b') == a ;

}

int main(){

    char a;
    
    cin>>a;

    char b = hasha(a);

    cout<<confirm(a,b);


    return 0;

}