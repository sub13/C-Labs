﻿#include <iostream>
#include <cstring>

using namespace std;


class Vehicles
{

private:
static int countVehicles;
protected: 
int classCountVehicles;

public:
	int numberWheels;
	float maxSpeed;
	int numberSeats;
	string typeEngine;
	string manufactured;
	string model;
	string nameObject = "Транспорт";

	static void showCountVehicles();	
	virtual void show();
	
	Vehicles(int numberWheels, float maxSpeed, int numberSeats, string typeEngine, string manufactured, string model)
	{
		this->numberWheels = numberWheels;
		this->maxSpeed = maxSpeed;
		this->numberSeats = numberSeats;
		this->typeEngine = typeEngine;
		this->manufactured = manufactured;
		this->model = model;
		countVehicles++;
		classCountVehicles = countVehicles;
	}
	Vehicles()
	{
		cout << "Введите количество колес:\n ";
		cin >> numberWheels;
		cout << "Введите максимальную скорость:\n";
		cin >> maxSpeed;
		cout << "Введите количество мест:\n";
		cin >> numberSeats;
		cout << "Введите модель транспорта строкой:\n";
		cin >> model;
		cout << "Введите тип двигателя:\n";
		cin >> typeEngine;
		cout << "Введите Производителя:\n";
		cin >> manufactured;
		countVehicles++;
		classCountVehicles = countVehicles;
	}



	~Vehicles();
};


class Car : public Vehicles
{
protected:
	string typeBodyCar;
	string typeCar;
public:
	void show();

	Car (int numberWheels, float maxSpeed, int numberSeats, string typeEngine, string manufactured, string model, string typeBodyCar, string typeCar): Vehicles(numberWheels, maxSpeed, numberSeats, typeEngine, manufactured, model)
	{
		this->nameObject = "Автомобиль";
		this->typeBodyCar = typeBodyCar;
		this->typeCar = typeCar;
	} 

	Car() : Vehicles()
	{
		this->nameObject = "Автомобиль";
		cout << "Введите тип автомобильного кузова:\n";
		cin >> typeBodyCar;
		cout << "Введите тип автомобиля(например:грузовой):\n";
		cin >> typeCar;
	}
};

class Motorcycle :public Vehicles
{
public:
	void show();

	string motorcycleType;

	Motorcycle(int numberWheels, float maxSpeed, int numberSeats, string typeEngine, string manufactured, string model, string motorcycleType) : Vehicles(numberWheels, maxSpeed, numberSeats, typeEngine, manufactured, model)
	{
		this->nameObject = "Мотоцикл";
		this->motorcycleType = motorcycleType;
	}
	Motorcycle() : Vehicles()
	{
		this->nameObject = "Мотоцикл";
		cout << "Введите тип мотоцикла(например:кроссовый):\n";
		cin >> motorcycleType;
	}

};


class Bus :public Car
{
private:
	int numberBus;
public:
	void show();
	Bus(int numberWheels, float maxSpeed, int numberSeats, string typeEngine, string manufactured, string model, string typeBodyCar, string typeCar, int numberBus) : Car(numberWheels, maxSpeed, numberSeats, typeEngine, manufactured, model, typeBodyCar, typeCar)
	{
		this->nameObject = "Автобус";
		this->numberBus = numberBus;
	}
	Bus() : Car()
	{
		this->nameObject = "Автобус";
		cout << "Введите номер автобуса:\n";
		cin >> numberBus;
	}

};

void Vehicles::show()
{
	cout << "Класс наземный транспорт!\n";
	cout.setf(ios::left);
	cout.width(20);
	cout << "Количество колес: " << numberWheels << ";" << " максимальная скорость:" << maxSpeed << ";" << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "Количество мест: " << numberSeats << ";" << "Модель транспорта: " << model << ";" << endl;
	cout << "Тип двигателя: " << typeEngine << ";" << " Производитель транспорта: " << manufactured << ";" << endl;
	cout << "\n";
}



void Car::show()
{
	cout << "Класс:" << nameObject << "\n";
	cout.setf(ios::left);
	cout.width(20);
	cout << "Количество колес: " << numberWheels << ";" << " максимальная скорость:" << maxSpeed << ";" << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "Количество мест: " << numberSeats << ";" << "Тип автомобиля: " << typeCar << ";" << endl;
	cout << "Тип двигателя: " << typeEngine << ";" << " Производитель автомобиля: " << manufactured << ";" << endl;
	cout << "Модель автомобиля: " << model << ";" << " Тип кузова автомобиля: " << typeBodyCar << ";" << endl;
	cout << "\n";
}


void Motorcycle::show()
{
	cout << "Класс:" << nameObject << "\n";
	cout.setf(ios::left);
	cout.width(20);
	cout << "Количество колес: " << numberWheels << ";" << " максимальная скорость:" << maxSpeed << ";" << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "Количество мест: " << numberSeats << ";" << "Тип мотоцикла: " << motorcycleType << ";" << endl;
	cout << "Тип двигателя: " << typeEngine << ";" << " Производитель мотоцикла: " << manufactured << ";" << endl;
	cout << "Модель мотоцикла: " << model << ";" << endl;
	cout << "\n";
}


void Bus::show()
{
	cout << "Класс:" << nameObject << "\n";
	cout.setf(ios::left);
	cout.width(20);
	cout << "Количество колес: " << numberWheels << ";" << " максимальная скорость:" << maxSpeed << ";" << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "Количество мест: " << numberSeats << ";" << "Тип автобуса: " << typeCar << ";" << endl;
	cout << "Тип двигателя: " << typeEngine << ";" << " Производитель автобуса: " << manufactured << ";" << endl;
	cout << "Модель автобуса: " << model << ";" << " Тип кузова автобуса: " << typeBodyCar << ";" << endl;
	cout << "Номер автобуса: " << numberBus << ";" << endl;
	cout << "\n";
}

void Vehicles::showCountVehicles()
{
	cout << "Количество объектов класса наземный транспорт = " << countVehicles << "\n";
}

Vehicles::~Vehicles()
{
	cout << "Сейчас вызвался деструктор для транспорта типа: " << this->nameObject << "\n";
	countVehicles--;
	classCountVehicles = countVehicles;
}




int Vehicles::countVehicles = 0;

int main()
{
	Vehicles vehicles1(4, 250, 2, "бензиновый", "Ford", "Mustang");
	Car fordM(4, 210, 5, "электро-двигатель", "Tesla", "M", "седан", "пассажирский");
	Bus bus18(8,100,100,"электро-двигатель","МАЗ","12","автобус","пассажирский",18);
	Motorcycle yamaha(2, 300, 1, "бензиновый", "Yamaha", "speed", "гоночный");	
	vehicles1.show();
	fordM.show();
	yamaha.show();
	bus18.show();
	Vehicles::showCountVehicles();
	Vehicles *pointerVehicles1 = new Car (4, 210, 5, "электро-двигатель", "Tesla", "M", "седан", "пассажирский");
	pointerVehicles1->show();
	fordM.show();
	string n;
	cin >> n;
	return 0;
}







