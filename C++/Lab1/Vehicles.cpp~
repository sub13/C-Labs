#include <iostream>
#include <cstring>

using namespace std;


class Vehicles
{
	public: 
		void charact();
		int numberWheels;
		float maxSpeed;
		int numberSeats;
		string type;
		Vehicles(int numberWheels,float maxSpeed,int numberSeats,string type)
		{
			this->numberWheels = numberWheels;
			this->maxSpeed = maxSpeed;
			this->numberSeats = numberSeats;
			this->type = type;
		};
		Vehicles()
		{
			cout << "Введите количество колес:\n ";
			cin >> numberWheels;
			cout << "Введите максимальную скорость:\n";
			cin >> maxSpeed;
			cout << "Введите количество мест:\n";
			cin >> numberSeats;
			cout << "Введите тип транспорта строкой:\n";
			cin >> type;
		};
		~Vehicles(); 
};

void Vehicles::charact()
{
	cout <<"Класс наземный транспорт!\n";
	cout.setf(ios::left);
	cout.width(20);
	cout <<  "Количество колес: " << numberWheels << ";" <<" максимальная скорость:"  << maxSpeed << ";" << endl;
	cout.setf(ios::right);
	cout.width(20);
	cout << "Количество мест: " << numberSeats << ";" << " тип наземного транспорта: " << type << ";" << endl;
	cout << "\n";
}

Vehicles::~Vehicles()
{
	cout<<"Сейчас вызвался деструктор для транспорта типа: "<< this->type << "\n";
}

main()
{
	Vehicles vehicles1(4,200,2,"автомобиль"),*pointerVehicles1;
	vehicles1.charact();
	Vehicles vehicles2;
	vehicles2.charact();
	pointerVehicles1 = &vehicles1;
	pointerVehicles1->maxSpeed = 300;
	pointerVehicles1->charact();
}







