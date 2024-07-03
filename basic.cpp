#include<bits/stdc++.h>
#include "hero.cpp"
using namespace std;

class hero{
    // properties
    int health;
};

int main(){
    hero h1;
    cout << "Size of Hero h1 : " << sizeof(h1) << endl;
    // It will return the size of integer <<-- -->> Integer is of sie '4'
    // Size o f empty class is -> "1" <- for identification of class 1 byte of memory is allocated to the empty class
    Shero sh1;
    cout << "Size of Shero sh1 : " << sizeof(sh1) << endl;
    return 0;
}