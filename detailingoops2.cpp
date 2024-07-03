/*
    -->> Object Oriented Programming Part 2 <<--
*/
/*
    -->> Encapsulation -> Wrapping up data member and function <<--
    Why do we need encapsulation ? -> information/data hiding
    -> We can hide data using encapsulation <-
    If we want we can make class read only 
    Code reliablity <<--
*/

/*
    -->> Inheritance -> Inheriting the properties of parent class 
    Example -> Inheriting the properties of male and female class from humans
*/
#include<bits/stdc++.h>
using namespace std;

class student{
    private:
        string name;
        int age;
        int height;

    public:
    int get_age(){
        return this->age;
    }
};

class human{
    public:
    int height;
    int weight;
    int age;

    int get_Age(){
        return age;
    }

    void set_weight(int w){  
        weight = w;
    }
};

class male: protected human{        // protected => can be accessed by child class or given class 
    public:
    string color;

    void sleep(){
        cout << "Male Sleeping" << endl;
    }

    int get_height(){
        return this->height;
    }
};

int main(){
    // student first;
    male obj1;
    // cout << obj1.age << endl;           // Male had inherited the Human's Properties
    // cout << obj1.weight << endl;
    // cout << obj1.height << endl;
    // cout << obj1.color << endl;
    // obj1.set_weight(84);
    // cout << obj1.weight << endl;
    // obj1.sleep();
    cout << obj1.get_height() << endl;              // -->> Getter object <<--
    cout << "World Asks me why I love her ?" << endl;
    return 0;
}