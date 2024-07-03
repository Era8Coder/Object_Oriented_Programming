#include<bits/stdc++.h>
#include "hero.cpp"
using namespace std;

// Part - ONE   ]-> Access Modifiers
/*
    Access Modifiers :-> 
        1) Public                               -> can be accessed outside class also
        2) Private              (By Default)    -> can be accessed inside class only
        3) Protected                            -> {Later}
*/

/*
class hero{
    // properties
    public:
    int health;
    char level;
};

int main(){
    // creation of object
    hero ramesh;    

    ramesh.health = 70;
    ramesh.level = 'A';

    cout << "health is : " << ramesh.health << endl;
    cout << "level is : " << ramesh.level << endl;
    return 0;
}
*/
// Part - TWO       ]-> Getter Setter
/*
class hero{
    // properties

    int health;
    public:
    char level;

    void print(){
        cout << level << endl;
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }
};

int main(){
    // creation of object
    hero ramesh;    
    ramesh.set_health(70);
    cout << "Ramesh health is : " << ramesh.get_health() << endl;
    // ramesh.health = 70;
    ramesh.level = 'A';

    // cout << "health is : " << ramesh.health << endl;
    cout << "level is : " << ramesh.level << endl;
    return 0;
}
*/

// Part - THREE     ]-> Static and Dynamic Allocation
/*
class hero{
    // properties

    int health;
    public:
    char level;

    void print(){
        cout << level << endl;
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }
};

int main(){
    // static allocation
    hero h1;
    cout << "level is: " << h1.level << endl;
    cout << "health is:" << h1.get_health() << endl;

    // dynamic allocation
    hero *b = new hero; 
    b->set_level('B');
    b->set_health(80);
    cout << "level is : " << (*b).level << endl;
    cout << "health is: " << (*b).get_health() << endl;

    cout << "Rain of Tears" << endl;

    cout << "level is: " << b->level << endl;
    cout << "health is:" << b->get_health() << endl;
    return 0;
}
*/

// Part - FOUR      ]-> Constructor Called
/*
class hero{
    // properties

    int health;
    public:
    char level;

    hero()              // when you make the parameterised constructor the default constructor dies :)
    {
        cout << "Constructor Called: " << endl;
    }

    hero(int health)
    {
        cout << "second -> " << this << endl;
        this->health = health;              // This keyword is used to access the current object this->health => Ramesh ka health
    }

    hero(int health, char level){
        this -> health = health;
        this -> level  = level;
    }

    void print(){
        cout << level << endl;
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }
};
*/
/*
int main(){

    // object created statically
    cout << "hi" << endl;
    hero ramesh(10);
    cout << "Address of Ramesh: " << &ramesh << endl;
    cout << "hlo" << endl;
    ramesh.print(); // Garbage Value

    // dynamically
    hero *h = new hero();
    h->print();     // Garbage value

    hero temp(22, 'B');
    temp.print();

    // static allocation
    hero h1;
    cout << "level is: " << h1.level << endl;
    cout << "health is:" << h1.get_health() << endl;

    // dynamic allocation
    hero *b = new hero; 
    b->set_level('B');
    b->set_health(80);
    cout << "level is : " << (*b).level << endl;
    cout << "health is: " << (*b).get_health() << endl;

    cout << "Rain of Tears" << endl;

    cout << "level is: " << b->level << endl;
    cout << "health is:" << b->get_health() << endl;
    
    return 0;
}
*/

// Part - FIVE      ]-> copying from other object
/*
class hero{
    // properties

    int health;
    public:
    char level;

    hero()              // when you make the parameterised constructor the default constructor dies :)
    {
        cout << "Constructor Called: " << endl;
    }

    hero(int health)
    {
        cout << "second -> " << this << endl;
        this->health = health;              // This keyword is used to access the current object this->health => Ramesh ka health
    }

    hero(int health, char level){
        this -> health = health;
        this -> level  = level;
    }

    
        // After writing the self written copy constructor that made by compiler dies RIP
    
    hero(hero& temp){             // copy constructor   // -->> When i mak ampersand then it don't make error but without ampersand it makes error <<-- 
        
            // use of ampersand is must because it makes copy again and again infinitely -> again and again copying of copy constructor <<-- :)
            // Pass By Value -> Infinte copying :)
            // Pass By Reference -> Not infinite copying :)
        
        cout << "Copy Constructor Called : " << endl;
        this->health = temp.health;
        this->level  = temp.level; 
    }

    void print(){
        cout << "health: " << this->health << endl;
        cout << "level: " << this->level << endl;
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }
};

int main(){
    hero S(70, 'C');
    S.print();

    // -->> Copy Constructor is called <<-- 
    hero R(S);
    R.print();
    return 0;
}
*/

// PART - SIX       ]-> Shallow and Deep Copy
/*
class hero{
    // properties

    int health;
    public:
    char* name;         // We had dynamically allocated since there is more space available in heap
    char level;

    hero()              // when you make the parameterised constructor the default constructor dies :)
    {
        cout << "Constructor Called: " << endl;
        name = new char[100];
    }

    hero(int health)
    {
        cout << "second -> " << this << endl;
        this->health = health;              // This keyword is used to access the current object this->health => Ramesh ka health
    }

    hero(int health, char level){
        this -> health = health;
        this -> level  = level;
    }

    
        // After writing the self written copy constructor that made by compiler dies RIP
    
    // -->> For deep copying we have to use our this constructor <<--
    hero(hero& temp){             // copy constructor   // -->> When i mak ampersand then it don't make error but without ampersand it makes error <<-- 
        
            // use of ampersand is must because it makes copy again and again infinitely -> again and again copying of copy constructor <<-- :)
            // Pass By Value -> Infinte copying :)
            // Pass By Reference -> Not infinite copying :)
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);          // Copying ch the new string
        this->name = ch;
        cout << "Copy Constructor Called : " << endl;
        this->health = temp.health;
        this->level  = temp.level; 
    }

    void print(){
        cout << endl;
        cout << "[Name: " << this->name << " , ";
        cout << "Health: " << this->health << " , ";
        cout << "Level: " << this->level << " ]";
        cout << endl;
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }

    void set_name(char name[]){
        strcpy(this->name, name);
    }
};

int main(){
    hero h1;
    h1.set_health(12);
    h1.set_level('D');
    char name[8] = "Anirudh";
    h1.set_name(name);
    h1.print();

    // -->> Using default copy constructor <<--     
    hero h2(h1);
    h2.print();
    // H2 = H1
    h1.name[0] = 'G';
    h1.print();
    h2.print();     // H2 also changes 
    // -->> Default copy constructor copies shallowly <<-- //
    // Shallow copy -> we are accessing the same memory again

        // After using the deep copy there is no change in the second hero h2 we had created <<--
    h1 = h2;
    h1.print();
    h2.print();
    return 0;
}
*/

// PART - SEVEN     ] -> Destructor -> deallocates the memory <<-- 
/*
class hero{
    // properties

    int health;
    public:
    char* name;         // We had dynamically allocated since there is more space available in heap
    char level;

    hero()              // when you make the parameterised constructor the default constructor dies :)
    {
        cout << "Constructor Called: " << endl;
        name = new char[100];
    }

    hero(int health)
    {
        cout << "second -> " << this << endl;
        this->health = health;              // This keyword is used to access the current object this->health => Ramesh ka health
    }

    hero(int health, char level){
        this -> health = health;
        this -> level  = level;
    }

    
        // After writing the self written copy constructor that made by compiler dies RIP
    
    // -->> For deep copying we have to use our this constructor <<--
    hero(hero& temp){             // copy constructor   // -->> When i mak ampersand then it don't make error but without ampersand it makes error <<-- 
        
            // use of ampersand is must because it makes copy again and again infinitely -> again and again copying of copy constructor <<-- :)
            // Pass By Value -> Infinte copying :)
            // Pass By Reference -> Not infinite copying :)
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);          // Copying ch the new string
        this->name = ch;
        cout << "Copy Constructor Called : " << endl;
        this->health = temp.health;
        this->level  = temp.level; 
    }

    void print(){
        cout << endl;
        cout << "[Name: " << this->name << " , ";
        cout << "Health: " << this->health << " , ";
        cout << "Level: " << this->level << " ]";
        cout << endl;
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }

    void set_name(char name[]){
        strcpy(this->name, name);
    }

    // destructor
    ~hero(){
        cout << "Destructor bhai called" << endl;
    }
};

int main(){
    // static   -> Destructor is automatically called for them :)
    hero a;

    // dynamic
    hero* b = new hero();   // we have to call destructor manually for them :)
    delete b;   // deleting dynamically allocated one ">-<"
    return 0;
}
*/

// PART - EIGHT     ] -> Using static keyword
/* 
class hero{
    // properties

    int health;
    public:
    char* name;         // We had dynamically allocated since there is more space available in heap
    char level;
    static int time_to_complete;       // independent of hero and enemy <- it's the super level 

    hero()              // when you make the parameterised constructor the default constructor dies :)
    {
        cout << "Constructor Called: " << endl;
        name = new char[100];
    }

    hero(int health)
    {
        cout << "second -> " << this << endl;
        this->health = health;              // This keyword is used to access the current object this->health => Ramesh ka health
    }

    hero(int health, char level){
        this -> health = health;
        this -> level  = level;
    }

    
        // After writing the self written copy constructor that made by compiler dies RIP
    
    // -->> For deep copying we have to use our this constructor <<--
    hero(hero& temp){             // copy constructor   // -->> When i mak ampersand then it don't make error but without ampersand it makes error <<-- 
        
            // use of ampersand is must because it makes copy again and again infinitely -> again and again copying of copy constructor <<-- :)
            // Pass By Value -> Infinte copying :)
            // Pass By Reference -> Not infinite copying :)
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);          // Copying ch the new string
        this->name = ch;
        cout << "Copy Constructor Called : " << endl;
        this->health = temp.health;
        this->level  = temp.level; 
    }

    void print(){
        cout << endl;
        cout << "[Name: " << this->name << " , ";
        cout << "Health: " << this->health << " , ";
        cout << "Level: " << this->level << " ]";
        cout << endl;
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }

    void set_name(char name[]){
        strcpy(this->name, name);
    }

    // destructor
    ~hero(){
        cout << "Destructor bhai called" << endl;
    }
};

int hero::time_to_complete = 5;     // Data type - Class - Scope Resolution Operator - field name - Time Left
// static one don't belong to object it belongs to class

int main(){
    // How to 
    cout << hero::time_to_complete << endl;
    hero a;
    cout << a.time_to_complete << endl;
    hero b;
    b.time_to_complete = 10;
    cout << a.time_to_complete << endl;
    cout << b.time_to_complete << endl;
    return 0;
}
*/

// PART - NINE      ] -> Static functions -> no need to create object no need of this keyword
// static function can access static members only
class hero{
    // properties

    int health;
    public:
    char* name;         // We had dynamically allocated since there is more space available in heap
    char level;
    static int time_to_complete;       // independent of hero and enemy <- it's the super level 

    hero()              // when you make the parameterised constructor the default constructor dies :)
    {
        cout << "Constructor Called: " << endl;
        name = new char[100];
    }

    hero(int health)
    {
        cout << "second -> " << this << endl;
        this->health = health;              // This keyword is used to access the current object this->health => Ramesh ka health
    }

    hero(int health, char level){
        this -> health = health;
        this -> level  = level;
    }

    
        // After writing the self written copy constructor that made by compiler dies RIP
    
    // -->> For deep copying we have to use our this constructor <<--
    hero(hero& temp){             // copy constructor   // -->> When i mak ampersand then it don't make error but without ampersand it makes error <<-- 
        
            // use of ampersand is must because it makes copy again and again infinitely -> again and again copying of copy constructor <<-- :)
            // Pass By Value -> Infinte copying :)
            // Pass By Reference -> Not infinite copying :)
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);          // Copying ch the new string
        this->name = ch;
        cout << "Copy Constructor Called : " << endl;
        this->health = temp.health;
        this->level  = temp.level; 
    }

    void print(){
        cout << endl;
        cout << "[Name: " << this->name << " , ";
        cout << "Health: " << this->health << " , ";
        cout << "Level: " << this->level << " ]";
        cout << endl;
    }

    static int random(){
        return time_to_complete;
        // cout << health << endl;  static function can access static data-type only
    }

    int get_health(){
        return health;
    }

    char get_level(){
        return level;
    }

    void set_health(int h){
        health = h;
    }

    void set_level(char ch){
        level = ch;
    }

    void set_name(char name[]){
        strcpy(this->name, name);
    }

    // destructor
    ~hero(){
        cout << "Destructor bhai called" << endl;
    }
};

int hero::time_to_complete = 5;     // Data type - Class - Scope Resolution Operator - field name - Time Left
// static one don't belong to object it belongs to class

int main(){
    cout << hero::random() << endl;     // can access static data member only
 
    // cout << hero::time_to_complete << endl;
    // hero a;
    // cout << a.time_to_complete << endl;
    // hero b;
    // b.time_to_complete = 10;
    // cout << a.time_to_complete << endl;
    // cout << b.time_to_complete << endl;
    return 0;
}