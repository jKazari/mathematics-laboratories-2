#include <iostream>

using namespace std;

class Integer {
    int value;

	public:
		Integer(int v) : value(v) {
			cout << "Created object with value: " << value << endl;
		}

		int getValue() const {
			return value;
		}

		void setValue(int v) {
			value = v;
		}

		friend void add(Integer& left, const Integer& right);

		void subtract(const Integer& other) {
			value -= other.value;
		}

		void multiply(const Integer& other) {
			value *= other.value;
		}
};

void add(Integer& left, const Integer& right) {
    left.value += right.value;
}

int main() {
    Integer num1(5);
    Integer num2(10);
    const Integer num3(15);

    // Użycie funkcji zaprzyjaźnionej
    add(num1, num2);
    cout << "num1 after befriended adding num2: " << num1.getValue() << endl;

    return 0;
}

