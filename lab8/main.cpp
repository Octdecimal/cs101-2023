#include<iostream>

using namespace std;

class Fueltank {
	private:
	    int m_FueltankCapacity;
		int m_Gas_grade;
	public:
	    Fueltank(int FueltankCapacity = 3000, int Gas = 98) {
			m_FueltankCapacity = FueltankCapacity;
			m_Gas_grade = Gas;
		}
		int fuel_up(int v, int gas) {
			if(v > m_FueltankCapacity) {
				cout << "Error: FueltankCapacity: " << v << ", but fuel up: " << m_FueltankCapacity << "\n";
			}
			if(gas != m_Gas_grade) {
				cout << "Error: Gas_grade " << gas << ", Correct Gas_grade: " << m_Gas_grade << "\n";
			}
			if((v < m_FueltankCapacity) and (gas == m_Gas_grade)) {
				cout << "fuel_up: " << v << " Gas_grade: " << gas << "\n";
			}
			return v;
		};
		int set_Gas_grade(int Gas_grade) {
			m_Gas_grade = Gas_grade;
			cout << "Set Gas_grade: " << m_Gas_grade << "\n";
			return Gas_grade; 
		};
		int get_Gas_grade() {
			cout << m_Gas_grade << "\n";
			return m_Gas_grade;
		};
};

class Car {
	Fueltank m_Fueltank;
	public:
	string m_brand;
	string m_model;
	int m_year;
	int m_MaxSeating;
	string get_brand() {
		return m_brand;
	}
	Car(string x, string y, int z, int s) {
		m_brand = x;
		m_model = y;
		m_year = z;
		m_MaxSeating = s;
    }
	int get_m_MaxSeating() {
		return m_MaxSeating;
	}
	int get_Gas_grade() {
		return m_Fueltank.get_Gas_grade();
	}
	int set_Gas_grade(int gas) {
		return m_Fueltank.set_Gas_grade(gas);
	}
	int fuel_up(int v, int gas) {
		return m_Fueltank.fuel_up(v, gas);
	}
};

class BMW_Car: public Car {
	private:
	string m_DriveMode;

	public:
	BMW_Car(string y, int z, int s) : Car("BMW", y, z, s) {
		cout << "Constructing BMW_Car\n";
		m_DriveMode = "Rear-wheel";
	}

	string get_DriveMode() {
		return m_DriveMode;
	}
};

class AUDI_Car: public Car {
	private:
	string m_DriveMode;

	public:
	AUDI_Car(string y, int z, int s) : Car("AUDI", y, z, s) {
		cout << "Constructing AUDI_Car\n";
		m_DriveMode = "Front-wheel";
	}

	string get_DriveMode() {
		return m_DriveMode;
	}
};

class BENZ_Car: public Car {
	private:
	string m_DriveMode;

	public:
	BENZ_Car(string y, int z, int s) : Car("BENZ", y, z, s) {
		cout << "Constructing BENZ_Car\n";
		m_DriveMode = "Front-wheel";
	}

	string get_DriveMode() {
		return m_DriveMode;
	}
};

int main() {
	BMW_Car car_1("X5", 2023, 6);
	cout << car_1.m_brand;
	cout << " : Drive mode = " << car_1.get_DriveMode() << endl;

	AUDI_Car car_2("A1", 2023, 5);
	cout << car_2.m_brand;
	cout << " : Drive mode = " << car_2.get_DriveMode() << endl;

	BENZ_Car car_3("S6", 2023, 6);
	cout << car_3.m_brand;
	cout << " : Drive mode = " << car_3.get_DriveMode()  << "\n" << endl;

	cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.set_Gas_grade(95);
	cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.fuel_up(300, 99);

	return 0;
}