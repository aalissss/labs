#include <iostream>
using namespace std;

//односвязный список
struct node {
	int data;
	node* next;
};

node* top = nullptr;

//функция, добавляющая элемент на вершину стека 
void push(int data) {
	node* newnode = new node;
	(*newnode).data = data;
	(*newnode).next = top;
	top = newnode;
}

//функция, удаляющая элемент с вершины стека
int pop() {
	if (top == nullptr) {
		cout << "Stack is empty" << endl;
		return -1;
	}
	int data = (*top).data;
	node* temp = top;
	top = (*top).next;
	delete temp;
	return data;
}

//функция, проверяющая пустоту списка
bool isempty() {
	return top == nullptr;
}

int main(int argc, char *argv[])
{
	int data, i;
	bool inputParam;

	if (argc == 1) {
		inputParam = true;
	}
	else {
		if ((strcmp(argv[1], "true") == 0) || (strcmp(argv[1], "false") == 0)) {
			if (strcmp(argv[1], "true") == 0) {
				inputParam = true;
			}
			else {
				inputParam = false;
			}
		}
		else {
			cout << "Error! Parameter must be true or false!" << endl;
			return -1;
		}

		if (inputParam) {
			cout << "Enter a number. The input mustend with the number zero (0): ";
		}
	}

	while (true) {
		cin >> data;
		if (data == 0) {
			break;
		}
		push(data);
	}

	if (inputParam) {
		cout << "result: " << endl;
	}
	while (!isempty()) {
		i = pop();
		if (i > 0) {
			cout << i << endl;
		}
	}
	return 0;
}