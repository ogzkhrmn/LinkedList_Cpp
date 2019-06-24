#include "LinkedList.h"

int main()
{
	LinkedList<int> list;

	list.insertFirst(3);
	list.insertFirst(2);
	list.insertFirst(1);
	list.insertLast(4);
	list.insertFirst(0);
	list.insertLast(5);

	list.deleteFirst();
	list.deleteLast();
	list.print();
	cout << list.get(0) << endl;
	cout << list.get(3) << endl;
	cout << list.get(2) << endl;
	return 0;
}
