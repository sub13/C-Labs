#include <iostream>
#include <cstring>

using namespace std;

int countStack = 0;

class Stack
{

private:
	int size = 0;
public:
	int* elem = new int(1);
	void empty();
	void output();

	Stack(int size, int elem[])
	{
		this->size = size;
		this->elem = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->elem[i] = elem[i];
		countStack++;
	};
	Stack()
	{
		countStack++;
	};


	Stack operator + (int b)
	{
		if (this->size == 0)
		{
			this->size++;
			this->elem = new int[this->size];
			this->elem[this->size - 1] = b;
		}
		else
		{
			int buf[this->size];
			for (int i = 0; i <= this->size; i++)
				buf[i] = this->elem[i];
			this->size++;
			this->elem = new int[this->size];
			for (int i = 0; i < this->size; i++)
				this->elem[i] = buf[i];
			this->elem[this->size - 1] = b;
		}
		Stack a;
		a.elem = this->elem;
		a.size = this->size;
		return a;
	}

	Stack& operator = (Stack& b)
	{
		this->size = b.size;
		int* elem = new int(b.size);
		this->elem = elem;
		for (int i = 0; i < this->size; i++)
			this->elem[i] = b.elem[i];
		delete[] b.elem;
		return *this;
	}

	Stack operator - (int countHead)
	{
		Stack a;
		if (this->size == 0 || countHead > this->size || countHead == this->size || countHead == 0)
		{
			cout << "Ошибка! Нельзя извлечь элемент из стека\n";
			return a;
		}
		else
		{
			int buf1[this->size - countHead];
			int buf2[countHead];
			for (int i = 0; i < this->size - countHead; i++)
				buf1[i] = this->elem[i];
			for (int i = 0; i != countHead; i++)
				buf2[i] = this->elem[(size - 1) - i];
			//int number = this->elem[this->size - countHead];
			this->size -= countHead;
			this->elem = new int[this->size];
			for (int i = 0; i < this->size; i++)
				this->elem[i] = buf1[i];
			a.elem = new int[countHead];
			a.size = countHead;
			int j = 0;
			for (int i = a.size - 1; i >= 0; i--)
			{
				a.elem[j] = buf2[i];
				j++;
			}
			return a;
		}
	}
	~Stack();
};

Stack::~Stack()
{
	//cout<<"Для стека под номером: "<< countStack <<" вызвался деструктор!\n";
	delete this->elem;
}


void Stack::output()
{
	cout << "Стек под номером: " << countStack << "\n";
	cout << "Размер стека : " << size << "\n";
	cout << "Содержимое стека : " << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << elem[i] << "\n";
	}
}


void input()
{
	int size;
	cout << "Введите размер стека 1:\n";
	cin >> size;
	int temp[size];
	cout << "Введите по одному элементы стека:\n";
	for (int i = 0; i < size; i++)
		cin >> temp[i];
	Stack newStack(size, temp);
	cout << "Введите размер стека2:\n";
	cin >> size;
	int temp2[size];
	cout << "Введите по одному элементы стека:\n";
	for (int i = 0; i < size; i++)
		cin >> temp2[i];
	Stack newStack2(size, temp2);
	chooseOperation(newStack, newStack2);
}

void chooseOperation(Stack& newStack, Stack& newStack2)
{
	int key = 1;
	int elem;
	int countPopElement;
	cout << "выбирете операцию для стека:\n";
	cout << "1.Добавление элемента к стеку 1;2.Добавление элемента к стеку 2;3.Извлечение элемента со стека 1;4.Извлечение элемента со стека 2;5.Присваивание двух стеков;6.Перезадать стеки;7.Выйти из программы";
	while (key == 1)
	{
		char keyChar;
		cin >> keyChar;
		switch (keyChar)
		{
		case '1': { cout << "Введите элемент для стека1\n"; cin >> elem; pushStack(newStack, elem); break; }
		case '2': { cout << "Введите элемент для стека2\n"; cin >> elem; pushStack(newStack2, elem); break; }
		case '3': { cout << "Введите количество извлеченных элементов из стека 1:\n"; cin >> countPopElement; popStack(newStack,countPopElement); }
		case '4': { cout << "Введите количество извлеченных элементов из стека 2:\n"; cin >> countPopElement; popStack(newStack2,countPopElement); break; }
		case '5': { steck2ToSteck1(newStack, newStack2); break; }
		case '6': { key = 0; break; }
		case '7': {return; }
		}
	}		
	void input();
}

				
void pushStack(Stack& newstack,int elem)
{
	newstack = newstack + elem;
}

void steck2ToSteck1(Stack& newStack, Stack& newStack2)
{
	newStack = newStack2;
}

void popStack(Stack& newstack, int countPopElement)
{
	newstack = newstack - countPopElement;
}


				//void testStack()
				//{
				//	
				//	Stack stack1;
				//	Stack stackPOP;
				//	stack1 = stack1 + 1;
				//	stack1 = stack1 + 2;
				//	stack1 = stack1 + 3;
				//	stack1 = stack1 + 5;
				//	int z[2];
				//	z[0] = 1;
				//	z[1] = 2;
				//	Stack stack2(2, z);
				//	stack1.output();
				//	stack2.output();
				//	stackPOP = stack1 - 2;
				//	stackPOP.output();
				//	input();
				//	

				//	присвоить стек 1 к стеку 2 и наоборот, затем сделать новый объект (отдельную память)
				//}


main()
{
	input();
	setlocale(LC_ALL, "Russian");
}
