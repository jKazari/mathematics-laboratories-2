#include <iostream>

#define TANK_LIMIT 50

using namespace std;

struct Car {
	double tank_fuel;

	Car() {
		tank_fuel = 0;
	}

	void refuel(double refuel_amount) {
		if (tank_fuel + refuel_amount > TANK_LIMIT) {
			tank_fuel = TANK_LIMIT;
			cout << ">> Refueled to full tank";
		}
		else {
			tank_fuel += refuel_amount;
			cout << ">> Refueled " << refuel_amount << " L" << endl << "Current fuel amount: " << tank_fuel << " L" << endl;
		}
	}

	void drive(double kilometers) {
		if (kilometers <= tank_fuel * 10) {
			tank_fuel -= kilometers / 10;
			cout << ">> Traveled " << kilometers << " km" << endl; 
		}
		else {
			cout << ">> Traveled " << tank_fuel * 10 << " km out of " << kilometers <<" km. Tank empty." << endl;
			tank_fuel = 0;
		}
	}

	void fuel_amount();
};

void Car::fuel_amount() {
	cout << "Current fuel amount: " << tank_fuel << " L" << endl;
}

int main() {
	Car my_car;

	my_car.refuel(35);
	my_car.drive(323);
	my_car.fuel_amount();
	my_car.drive(100);
	my_car.fuel_amount();
	my_car.refuel(55);

	return 0;
}