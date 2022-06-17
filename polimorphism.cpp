//polimorphism use demonstration 
#include <iostream>

using namespace std;

class Vehicle{
    protected: 
    int regNo;
    string color;
    double weight;
    
    public:
    Vehicle(){
    }
    Vehicle(int r, string c, double w){
        regNo = r;
        color = c;
        weight = w;
    }
    virtual void drive(){
        cout<<"I am the mother of all drives";
    }
    
};

class Car:public Vehicle{
    int doors;
    int power;
    public:
     Car(int r, string c, double w, int p, int d):Vehicle(r,c,w){
        power = p;
        doors =d;
        
    }
    void drive(){
        cout<<"I drive using steering, gas and gear lever - car";
    }
};

class bus:public Vehicle{
    int doors;
    int power;
    public:
      bus(int r, string c, double w, int p, int d):Vehicle(r,c,w){
        power = p;
        doors =d;
        
    }
    void drive(){
        cout<<"I drive using steering, gas and gear lever. I carry more people - bus";
    }
};

class spaceship:public Vehicle{
    int power;
    public:
    spaceship():Vehicle(){
    }
    spaceship(int r, string c, double w, int p):Vehicle(r,c,w){
        power = p;
    }
    void drive(){
        cout<<"I meet aliens and I can disappear - spaceship";
    }
};


int main()
{
    Vehicle *vehicles =  new Vehicle[50];
    // first vehicle can be car, 2nd can be bus, 3rd can spaceship

    //polymorphism - many faces/many shapes 
    //vehicle object to be a car, vehicle object to be abus, vehicle - spaceship
    
    //int a[5] = can store 5 integers
    
    // Vehicle[100] = objects of all child classes.
    
  /*  
    bus b1(444, "MiWay", 4.4, 4,4);
    Car c1(444, "Tesla", 4.4, 4,4);
    spaceship s1(444, "alienship", 4.4, 4);
    
    vehicles[0] = &b1;
    vehicles[1]= &c1;
    vehicles[2]=  &s1;
    // create an arrray of vehicles - car, bus, spaceship
    
    for(int i=0;i<3;i++){
        vehicles[i].drive();
    }
    */
    
    Vehicle *v;
    bus b1(444, "MiWay", 4.4, 4,4);
    Car c1(444, "Tesla", 4.4, 4,4);
    spaceship s1(444, "alienship", 4.4, 4);
    
    v=&b1;
    v->drive();
    
    cout<<endl;
    
    v=&c1;
    v->drive();
    
    cout<<endl;
    
    v=&s1;
    v->drive();
    
    //polymorphism
    
    return 0;
}
