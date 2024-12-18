#include <iostream>
#include <string>

using namespace std;

struct stack
{
	char date;
	int size = 0;
	stack* next;
};

bool check(char a, char b)
{
	if (a == '{')
	{
		if (b == '}')
		{
			return 1;
		}
		return 0;
	}
	if (a == '(')
	{
		if (b == ')')
		{
			return 1;
		}
		return 0;
	}
	if (a == '[')
	{
		if (b == ']')
		{
			return 1;
		}
		return 0;
	}
}

void push(stack*& Stack, char date)
{
	stack* buff = new stack;
	buff->date = date;
	buff->next = Stack;
	Stack = buff;
	Stack->size++;
}

void pop(stack*& Stack)
{
	if (Stack == NULL)
	{
		return;
	}
	else
	{
		stack* buff = new stack;
		buff = Stack;
		Stack = Stack->next;
		delete buff;
	}

}

char top(stack*& Stack)
{
	if (Stack == NULL)
	{
		return 0;
	}
	else
	{
		return Stack->date;
	}
}

int main()
{
	stack* Stack = new stack;
	bool correct = 1;
	bool noBr = 1;
	string str;
	cout << "Enter string with brackets: ";
	getline(cin, str);

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') //если открывающиеся, то запись//
		{
			push(Stack, str[i]);
			noBr = 0;
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') //если закрывающиеся, то//
		{
			noBr = 0;
			if (Stack->size == 0) //если стек пуст//
			{
				correct = 0;
				break;
			}
			else if (!check(top(Stack), str[i])) //если не соответствует последней открытой//
			{
				correct = 0;
				break;
			}
			else if (check(top(Stack), str[i])) //если соответствует//
			{
				pop(Stack); //удаляется {1 2 3 5 a s d}  {1 2 3 5 DER}

			}
		}
		else
		{
			continue;
		}
	}
	if (noBr)
	{
		cout << endl <<"No brackets." << endl;
	}
	else if (correct)
	{
		cout << "Brackets are placed correctly." << endl;
	}
	else
	{
		cout << "Brackets are placed incorrectly." << endl;
	}
	return 0;
}