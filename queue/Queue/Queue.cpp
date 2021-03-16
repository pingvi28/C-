#include <iostream>
#include <queue> //надо подключать библиотеку для очереди

using namespace std;

int main() {
	int start = 0, ends =  0;
	int qu[5];

	cout << "(mas)  enter 5 elements: " << endl; // затем перернеос строки

	for (int h = 0; h < 5; h++) {
		int a;
		cin >> a;
		qu[ends++] = a; // добавляем в очередь элементы
	}

	cout << endl;

	cout << "Last item in the queue: " << qu[ends -1] << endl; // выв. последенго

	cout << "First item in the queue: " << qu[start] << endl; // выв. 1 эл.
	start++; //  смещаем элемент в очереди

	cout << "New first item in the queue (after deleting): " << qu[start] << endl;

	if (start != ends) { cout << "queue is't empty" << endl; } // проверяем пуста ли очередь (нет)

	system("pause");

	return 0;
}

