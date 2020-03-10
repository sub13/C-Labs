#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>

using namespace std;


bool keyMenu = true;
void input();

class Stack
{
	private:
		int size = 0;
	public:
		int *elem = new int(1);
		void empty();
		void output();
		
		Stack(int size, int elem[])
		{
			this->size = size;
			this->elem = new int[this->size];
			for(int i = 0; i < this->size; i++)
				this->elem[i] = elem[i];
		};
		Stack()
		{
		};

		Stack(const Stack &b)
		{
			size = b.size;
			elem = new int(b.size);
			for (int i = 0; i < size; i++)
				elem[i] = b.elem[i];
		};

		Stack operator + (int b)
		{
			if(size == 0)
			{
				size++;
				elem = new int[size];
				elem[size - 1] =  b;
			}
			else
			{
				int buf[size];
				for(int i = 0; i <= size; i++)
					buf[i] = elem[i];
				size++;
				elem = new int[size];
				for(int i = 0; i < size; i++)
					elem[i] = buf[i];
				elem[size - 1] =  b;
			}
			Stack a; 
			a.elem = elem;
			a.size = size;
			return a;
		}
		
		Stack& operator = (Stack b)
		{
			size = b.size;
			int* tempElem = new int(b.size);
			elem = tempElem;
			for (int i = 0; i < size; i++)
				elem[i] = b.elem[i];
			return * this;
		}

		Stack operator - (int countHead)
		{
			Stack a; 
			if(size == 0 || countHead > size || countHead == size || countHead == 0)
			{
				cout << "Ошибка! Нельзя извлечь элемент из стека\n";
				return a;
			}
			else
			{
				int buf1[size - countHead];
				int buf2[countHead];
				for(int i = 0; i < size - countHead; i++)
					buf1[i] = elem[i];
				for(int i = 0; i != countHead ; i++)
					buf2[i] = elem[(size - 1) - i];
				size -= countHead;
				elem = new int[size];
				for(int i = 0; i < size; i++)
					elem[i] = buf1[i];
				a.elem = new int[countHead];
				a.size = countHead;
				int j = 0;
				for(int i = a.size - 1; i >= 0; i--)
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
	delete[] elem; // после того как вызвался деструктор старая память очищается!!!
}


void chooseOperation(Stack &newStack,Stack &newStack2);

void input()
{
	int size;
	string tempInput;
	cout << "Введите размер стека 1:\n";
	cin >> tempInput;
	if(tempInput.length() > 7)
	{
		cout << "Размер стека слишком большой!Максимальный размер = 9999999.\n";
		getchar();
		getchar();
		cout << "\033c";
		return;
	}
	size = stoi(tempInput); 
	int temp[size];
	cout << "Введите по одному элементы стека:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> tempInput;
		if(tempInput.length() > 7)
		{
			cout << "Размер элемента слишком большой!Максимальный размер = 9999999.\n";
			getchar();
			getchar();
			cout << "\033c";			
			return;
		}		
		temp[i] = stoi(tempInput);
	}
	Stack newStack(size, temp);
	cout << "Введите размер стека2:\n";
	cin >> tempInput;
	if (tempInput.length() > 7)
	{
		cout << "Размер стека слишком большой!Максимальный размер = 9999999.\n";
		getchar();
		getchar();
		cout << "\033c";
		return;
	}
	size = stoi(tempInput);
	int temp2[size];
	cout << "Введите по одному элементы стека:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> tempInput;
		if(tempInput.length() > 7)
		{
			cout << "Размер элемента слишком большой!Максимальный размер = 9999999.\n";
			getchar();
			getchar();
			cout << "\033c";
			return;
		}		
		temp2[i] = stoi(tempInput);
	}
	Stack newStack2(size, temp2);
	chooseOperation(newStack, newStack2);
}


void Stack::output()
{
	cout <<"Размер стека : "<< size << "\n";
	cout <<"Содержимое стека : "<< "\n";
	for(int i = 0; i < size; i++)
		cout << elem[i] << "\n";
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


void chooseOperation(Stack &newStack, Stack &newStack2)
{
	cout << "\033c";  
	int key = 1;
	int elem;
	string checkInput;
	int countPopElement;
	char keyChar;
	while (key == 1)
	{
		cout << "Выбирете операцию для стека:\n";
		cout.setf(ios::left);	
		cout.width(20);
		cout << "1.Добавление элемента к стеку 1;";
		cout.setf(ios::right);
		cout.width(20);
		cout << " 2.Добавление элемента к стеку 2;" << endl;
		cout.setf(ios::left);	
		cout.width(20);
		cout << "3.Извлечение элемента со стека 1;";
		cout.setf(ios::right);
		cout.width(20);
		cout << " 4.Извлечение элемента со стека 2;" << endl;
		cout.setf(ios::left);	
		cout.width(20);
		cout << "5.Присваивоить стек 1 к стеку 2;";
		cout.setf(ios::right);
		cout.width(20);
		cout << " 6.Перезадать стеки;" << endl;
		cout.setf(ios::left);	
		cout.width(20);
		cout << "7.Выйти из программы";
		cout.setf(ios::right);
		cout.width(20);
		cout << " 8.Присвоить стек 2 к стеку 1;\n";
		cout << "\nСтек под номер 1:\n";
		newStack.output();
		cout << "\nCтек под номер 2:\n";		
		newStack2.output();
		cin >> keyChar;
		switch (keyChar)
		{
		case '1': cout << "Введите элемент для стека1\n"; cin >> checkInput; 
		if(checkInput.length() > 7)
		{
			cout << "Размер элемента слишком большой!Максимальный размер = 9999999.\n";
			getchar();
			getchar();			
			checkInput ="";
			cin >> elem;			
			break;
		}
		elem = stoi(checkInput);		
		pushStack(newStack, elem); break; 
		case '2': cout << "Введите элемент для стека2\n"; cin >> checkInput; 
		if(checkInput.length() > 7)
		{
			cout << "Размер элемента слишком большой!Максимальный размер = 9999999.\n";
			getchar();
			getchar();
			cin >> elem;			
			checkInput ="";			
			break;
		}
		elem = stoi(checkInput);	
		pushStack(newStack2, elem); break; 
		case '3': cout << "Введите количество извлеченных элементов из стека 1:\n"; cin >> countPopElement;popStack(newStack,countPopElement);break;
		case '4': cout << "Введите количество извлеченных элементов из стека 2:\n"; cin >> countPopElement;popStack(newStack2,countPopElement); break;
		case '5': steck2ToSteck1(newStack2, newStack); break;
		case '6': key = 0; break; 
		case '7': keyMenu = false; cout << "\033c"; return;
		case '8': steck2ToSteck1(newStack, newStack2); break;
		}
		cout << "\033c";	
	}		
	input();
}



main()
{	
	while (keyMenu) 
		input();	
}
