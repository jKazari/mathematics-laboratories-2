#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Vehicle {
protected:
    string name;
    string color;
    float weight;
    float max_speed;

public:
    Vehicle() : name("default"), color("default"), weight(0), max_speed(0) {}

    Vehicle(string n, string c, float w, float m) : 
    name(n), color(c), weight(w), max_speed(m) {}

    virtual ~Vehicle() {
        cout << "Destroying Vehicle: Name: " << name << ", Color: " << color << ", Weight: " << weight << ", Max speed: " << max_speed << endl;
    }

    virtual void start_engine() {
        cout << "Vehicle engine started." << endl;
    }

    virtual void stop_engine() {
        cout << "Vehicle engine stopped." << endl;
    }
};

class Car : virtual public Vehicle {
protected:
    float horsepower;
    float number_of_doors;

public:
    Car() : Vehicle(), horsepower(0), number_of_doors(0) {}

    Car(string n, string c, float w, float m, float hp, float nd) : 
    Vehicle(n, c, w, m), horsepower(hp), number_of_doors(nd) {}

    virtual ~Car() {
        cout << "Destroying Car: Name: " << name << ", Color: " << color << ", Weight: " << weight 
        << ", Max speed: " << max_speed << ", Horsepower: " << horsepower 
        << ", Number of doors: " << number_of_doors << endl;
    }

    void accelerate(float time) {
        float acceleration = sqrt(horsepower * 745.7 / (2 * weight * time));
        float velocity = acceleration * time;
        float distance = 0.5 * acceleration * time * time;
        cout << "Car accelerated by " << acceleration << " m/s2 in " << time 
        << " seconds, achieving velocity of " << velocity << " m/s and traveling a distance of " 
        << distance << " meters." << endl; 
    }

    void honk() {
        cout << "Honk! Honk! Honk!" << endl;
    }
};

class Boat : virtual public Vehicle {
protected:
    float length;
    int max_passengers;

public:
    Boat() : Vehicle(), length(0), max_passengers(0) {}

    Boat(string n, string c, float w, float m, float le, int mp) : 
    Vehicle(n, c, w, m), length(le), max_passengers(mp) {}

    virtual ~Boat() {
        cout << "Destroying Boat: Name: " << name << ", Color: " << color << ", Weight: " << weight 
        << ", Max speed: " << max_speed << ", Length: " << length 
        << ", Maximum passengers: " << max_passengers << endl;
    }

    void lowerAnchor() {
        cout << "Lowered anchor. Boat is not moving." << endl;
    }

    void raiseAnchor() {
        cout << "Raised anchor. Boat can now move." << endl;
    }
};

class Amphibian : public Car, public Boat {
protected:
    bool is_in_amphibious_mode;

public:
    Amphibian() : Vehicle(), Car(), Boat(), is_in_amphibious_mode(false) {}

    Amphibian(string n, string c, float w, float m, float hp, float nd, float le, int mp, bool am) :
    Vehicle(n, c, w, m), Car(n, c, w, m, hp, nd), Boat(n, c, w, m, le, mp), is_in_amphibious_mode(am) {}

    virtual ~Amphibian() {
        cout << "Destroying Amphibian: Name: " << name << ", Color: " << color << ", Weight: " << weight << ", Max speed: " << max_speed 
            << ", Horsepower: " << horsepower << ", Number of doors: " << number_of_doors 
            << ", Length: " << length << ", Maximum passengers: " << max_passengers 
            << ", Amphibious mode: " << (is_in_amphibious_mode ? "On" : "Off") << endl;
    }

    void switchToLandMode() {
        is_in_amphibious_mode = false;
        cout << "Switched to land mode." << endl;
    }

    void switchToWaterMode() {
        is_in_amphibious_mode = true;
        cout << "Switched to water mode." << endl;
    }
};

int main() {
    Vehicle* vehiclePtr = new Vehicle("Toyota Mega Cruiser", "Black", 2850, 125);
    Car* carPtr = new Car("Renault Alpine A310", "Blue", 990, 220, 150, 2);
    Boat* boatPtr = new Boat("Wellcraft 355", "White", 7300, 91, 11.8, 5);
    Amphibian* amphibianPtr = new Amphibian("Pan Samochodzik", "Red", 1300, 265, 335, 2, 5, 2, false);

    vehiclePtr->start_engine();
    vehiclePtr->stop_engine();

    carPtr->start_engine();
    carPtr->accelerate(10);
    carPtr->honk();
    carPtr->stop_engine();

    boatPtr->start_engine();
    boatPtr->lowerAnchor();
    boatPtr->raiseAnchor();
    boatPtr->stop_engine();

    amphibianPtr->start_engine();
    amphibianPtr->switchToWaterMode();
    amphibianPtr->accelerate(15);
    amphibianPtr->switchToLandMode();
    amphibianPtr->stop_engine();

    delete vehiclePtr;
    delete carPtr;
    delete boatPtr;
    delete amphibianPtr;

    return 0;
}
