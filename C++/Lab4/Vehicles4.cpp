#include <iostream>
#include <cstring>

using namespace std;


class Vehicles
{

private:
	static int countVehicles;
protected:
	int classCountVehicles;

public:
	unsigned int numberWheels;
	float maxSpeed;
	unsigned int numberSeats;
	string typeEngine;
	string manufactured;
	string model;
	string nameObject = "Транспорт";

	static void showCountVehicles();
	void set_maxSpeed(float maxSpeed);
	void set_typeEngine(string typeEngine);
	void show();

	Vehicles(int numberWheels,int numberSeats, string manufactured, string model)
	{
		this->numberWheels = numberWheels;
		this->numberSeats = numberSeats;
		this->manufactured = manufactured;
		this->model = model;
		countVehicles++;
		classCountVehicles = countVehicles;
	}
	Vehicles()
	{
		cout << "Введите количество колес:\n ";
		cin >> numberWheels;
		cout << "Введите количество мест:\n";
		cin >> numberSeats;
		cout << "Введите модель транспорта строкой:\n";
		cin >> model;
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
	void set_typeCar(string typeCar);
	void set_typeBodyCar(string typeBodyCar);

	Car(int numberWheels, int numberSeats, string manufactured, string model) : Vehicles(numberWheels, numberSeats, manufactured, model)
	{
		this->nameObject = "Автомобиль";
	}

	Car() : Vehicles()
	{
		this->nameObject = "Автомобиль";
	}
};

class Motorcycle :public Vehicles
{
public:
	void show();

	string motorcycleType;

	Motorcycle(int numberWheels,  int numberSeats, string manufactured, string model, string motorcycleType) : Vehicles(numberWheels, numberSeats, manufactured, model)
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
	unsigned int numberBus;
public:

	void set_numberBus(unsigned int numberBus);
	void show();

	Bus(int numberWheels, int numberSeats, string manufactured, string model) : Car(numberWheels, numberSeats, manufactured, model)
	{
		this->nameObject = "Автобус";
	}
	Bus() : Car()
	{
		this->nameObject = "Автобус";
	}

};

class badNumberBus
{
	public:
	string error = "Неверный номер автобуса";	
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

void Vehicles::set_maxSpeed(float maxSpeed)
{
	if (maxSpeed < 0)
	{
		throw maxSpeed;
		return;
	}
	if (maxSpeed > 500)
	{
		throw maxSpeed;
		return;
	}
	this->maxSpeed = maxSpeed;
}

void Vehicles::set_typeEngine(string typeEngine)
{
	if (typeEngine == "бензиновый" || typeEngine == "электро-двигатель" || typeEngine == "дизельный" || typeEngine == "газовый" || typeEngine == "гибрид")
	{
		this->typeEngine = typeEngine;
	}
	else
	{
		throw "Ошибка, как правило для наземного трансопрта такого типа двигателя не существует!\nПожалуйста выбирете из следующих вариантов:бензиновый,электро-двигатель,дизельный,газовый,гибрид";
	}
}

void Car::set_typeCar(string typeCar)
{
	if (typeCar == "пассажирский" || typeCar == "грузовой" || typeCar == "легковой" || typeCar == "грузопассажирский" || typeCar == "специальный")
	{
		this->typeCar = typeCar;
	}
	else
	{
		throw "Ошибка, автомибиля данного назначения не существует!\nПожалуйста выбирете из следующих вариантов:пассажирский,грузовой,легковой,грузопассажирский,специальный";
	}
}

void Car::set_typeBodyCar(string typeBodyCar)				
{
	string arrayBodyCar [] = { "cедан", "хэтчбек", "универсал", "лифтбэк", "купе", "кабриолет", "родстер", "тарга", "лимузин", "стретч", "внедорожник", "кроссовер", "фургон", "минивэн", "микроавтобус", "aвтобус" };	
	for (int i = 0; i < 16; i++)
	{
		const char* temp1 = typeBodyCar.c_str();;
		const char* temp2 = arrayBodyCar[i].c_str();;
		if (strcmp(temp1,temp2))
		{
			this->typeBodyCar = typeBodyCar;
			return;
		}
	}
	string temp = "Ошибка, автомибиля c данным типом кузова не существует!\nПожалуйста выбирете из следующих вариантов:";
	for (int j = 0; j < 16; j++)
	{
		temp +=","; 
		temp += arrayBodyCar[j];
	}	
	throw temp;
}

void Bus::set_numberBus(unsigned int numberBus)
{
	if (numberBus > 9999)
	{
		badNumberBus busError1;
		
		throw busError1;
		return;
	}
	this->numberBus = numberBus;
}


int Vehicles::countVehicles = 0;

int main()
{
	try
	{
		Vehicles fordMustang(4, 2, "Ford", "Mustang");
		fordMustang.set_maxSpeed(250);
		fordMustang.set_typeEngine("бензиновый");

		Car teslaM(4, 5, "Tesla", "M");
		teslaM.set_maxSpeed(220);
		teslaM.set_typeEngine("электро-двигатель");
		teslaM.set_typeBodyCar("седан");
		teslaM.set_typeCar("легковой");

		Bus bus18(12, 160, "МАЗ", "105");
		bus18.set_maxSpeed(85);
		bus18.set_typeEngine("электро-двигатель");
		bus18.set_typeBodyCar("автобус");
		bus18.set_typeCar("пассажирский");
		bus18.set_numberBus(18);

		Motorcycle yamaha(2, 1, "Yamaha", "FJ1100", "cпорт-турист");
		yamaha.set_maxSpeed(260);
		yamaha.set_typeEngine("бензиновый");

		teslaM.show();
		yamaha.show();
		bus18.show();
		Vehicles::showCountVehicles();
	}
	catch (string errorMessage)
	{
		cout << " При создании объекта было вызвано исключение!\n Собщение исключения: " << errorMessage << endl;
	}
	catch (float maxSpeed)
	{
		cout << " При создании объекта было вызвано исключение!\n Невозможно установить, такую " << maxSpeed << "скорость" << endl;
	}
	catch(badNumberBus Bus)
	{
		cout << Bus.error;
	}
	cout << "для выхода из программы нажмите любую кнопку!";
	string n;
	cin >> n;
	return 0;
}







