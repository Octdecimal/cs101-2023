#include<iostream>

using namespace std;
class Engine {
	private:
	    int m_EngineCapacity;
		int m_Horsepower;
		bool m_EngineRunning;
	public:
	    Engine(int EngineCapacity = 2000, int Horsepower = 200) {
			m_EngineCapacity = EngineCapacity;
			m_Horsepower = Horsepower;
			m_EngineRunning = false;
		}
		bool (Engine)
};
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
				cout << "Error: Gas_grade: " << gas << ", Correct Gas_grade: " << m_Gas_grade << "\n";
			}
			if((v < m_FueltankCapacity) and (gas == m_Gas_grade)) {
				cout << "fuel_up: " << v << " Gas_grade: " << gas << "\n";
			}
			return v;
		};
		int set_Gas_grade(int Gas_grade) {
			m_Gas_grade = Gas_grade;
			return m_Gas_grade; 
		};
		int get_Gas_grade() {
			return m_Gas_grade;
		};
};

class Car {
	public:
	string m_brand;
	string m_model;
	int m_year;
	int m_MaxSeating;
	Fueltank m_Fueltank;
	Car(string x, string y, int z, int s) {
		m_brand = x;
		m_model = y;
		m_year = z;
		m_MaxSeating = s;
    }
	string get_brand() {
		return m_brand;
	}
	int get_m_MaxSeating() {
		return m_MaxSeating;
	}
	int get_Gas_grade() {
		return m_Fueltank.get_Gas_grade();
	}
	int set_Gas_grade(int gas = 98) {
		cout << "Set_Gas_grade : " << gas << "\n";
		return m_Fueltank.set_Gas_grade(gas);
	}
	int fuel_up(int v, int gas = 98) {
		return m_Fueltank.fuel_up(v, gas);
	}
};

class BMW_Car: public Car {
	private:
	string m_DriveMode;

	public:
	BMW_Car(string y, int z, int s) : Car("BMW", y, z, s) {
		cout << "Constructing BMW_Car" << endl;
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
		cout << "Constructing AUDI_Car" << endl;
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
		cout << "Constructing BENZ_Car" << endl;
		m_DriveMode = "Front-wheel";
	}

	string get_DriveMode() {
		return m_DriveMode;
	}
};

int main() {
    AUDI_Car car_2("A1", 2023, 5);
	cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.set_Gas_grade(95);
	cout << car_2.get_brand() << " : Gas_grade = " << car_2.get_Gas_grade() << endl;
	car_2.fuel_up(300, 99);

	return 0;
}