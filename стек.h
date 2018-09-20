#include "stdafx.h"
#include <locale>
#include <iomanip> //Для setw
#include <cassert> // для тестов


#include <iostream>

using namespace std;

template <typename T> //Шаблон

class Stack
{
private:
	T* stackPtr; //Указатель на голову стека
	int size; // размер стека
	T top; //вершина стека
public:
	Stack (int =10); //по умолч размер стека 
	~Stack();
	bool push(const T); //поместить элемент в стек 
	bool pop(); //удалить элемент из стека (предполагается дополнить функцию)
	void printStack();
};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "");
	int n;
	cout<< "Введите число элементов в стеке от 1 до 10"<<endl;
	cin >>n;
	
	Stack <int> myStack(n);
	cout<<"Помещение элементов в стек"<<endl;
	int ct=0; //счетчик числа элементов
	int temp=0;

	while(ct!=n)
	{
		cin>>temp;
		myStack.push(temp);
		ct++;	
	}

	cout<<"Содержимое стека:"<<endl;
	myStack.printStack();
	myStack.pop();
	myStack.pop();
	cout<<"Содержимое стека после удаления 2-х элементов:"<<endl;
	myStack.printStack();

	system("pause");
	return 0;
}

template <typename T>	Stack <T>::Stack(int s)
{
	assert((s>=1)&&(s<=10));
	size=s>0?s:10; //проверка размера стека
	
	stackPtr=new T[size]; //выделить память под стек
	top=-1; //стек пуст
}

template <typename T>	Stack <T>::~Stack()
{
	delete[] stackPtr; //освобождение выделенной области памяти
}

template <typename T> bool Stack <T>::push(const T value)
{
	//if (top==size-1)
		//return false; //стек полон

	//top++;
	//stackPtr[top]=value; // поместить элемент в стек

	stack* newstack = new stack();
	newstack->data = pdata;
	newstack->next = sp;
	sp = newstack;
	return true;
}

template <typename T> bool Stack <T>::pop()
{
	if (top==-1)
		return false; 
	
	stackPtr[top]=0;
	top--;	
	size--;
	return true;
}

template <typename T> void Stack <T>::printStack()
{
	int i=0;
	for(i=size-1; i>=0; i--)
	{
		cout<<setw(4)<<stackPtr[i]<<endl;
	}
}