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

		void add(const Integer& other) {
			value += other.value;
		}

		void subtract(const Integer& other) {
			value -= other.value;
		}

		void multiply(const Integer& other) {
			value *= other.value;
		}
};

int main() {
    Integer num1(5);
    Integer num2(10);
    const Integer num3(15);

    // Próba bezpośredniego przypisania niemożliwa, powoduje błąd kompilacji, ponieważ 'value' jest prywatne.

    // Testowanie getterów i setterów
    cout << "Value of num1: " << num1.getValue() << endl;
    num1.setValue(20);
    cout << "New value of num1: " << num1.getValue() << endl;

    // Operacje na obiektach
    num1.add(num2);
    cout << "num1 after adding num2: " << num1.getValue() << endl;

    num1.subtract(num2);
    cout << "num1 after subtracting num2: " << num1.getValue() << endl;

    num1.multiply(num2);
    cout << "num1 after multiplying by num2: " << num1.getValue() << endl;

    // Test operacji na obiekcie const
    cout << "Value of num3: " << num3.getValue() << endl;
    // num3.setValue(30); // To spowoduje błąd kompilacji, ponieważ num3 jest stały

    return 0;
}

