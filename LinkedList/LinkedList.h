#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
public:
	friend ostream& operator<<(ostream&, const LinkedList&);
	LinkedList();
	LinkedList(int);
	~LinkedList();
	void insertFirst(const int&);
	void insertLast(const int&);
	void deleteFirst();
	void deleteLast();
	bool isEmpty() const;
	void print() const;
	T get(unsigned int i) const;
private:
	LinkedList<T>* first;
	LinkedList<T>* last;
	LinkedList<T>* nextPtr;
	T value;
};

template <class T>
LinkedList<T>::LinkedList()
{
	first = last = nextPtr = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(int value)
{
	first = new LinkedList();
	first->value = value;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	//should delete all list
}

template <class T>
void LinkedList<T>::insertFirst(const int& value)
{
	auto* newPtr = new LinkedList();
	newPtr->value = value;
	if (isEmpty())
	{
		first = last = newPtr;
	}
	else
	{
		newPtr->nextPtr = first;
		first = newPtr;
	}
}

template <class T>
void LinkedList<T>::insertLast(const int& value)
{
	auto* newPtr = new LinkedList();
	newPtr->value = value;
	if (isEmpty())
	{
		first = last = newPtr;
	}
	else
	{
		last->nextPtr = newPtr;
		last = newPtr;
	}
}

template <class T>
void LinkedList<T>::print() const
{
	if (isEmpty())
	{
		cout << "List is emtpy";
	}
	LinkedList<T>* list = first;
	do
	{
		cout << list->value << " ";
		list = list->nextPtr;
	}
	while (list != nullptr);
	cout << endl;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
	return first == nullptr;
}


template <class T>
void LinkedList<T>::deleteFirst()
{
	if (!isEmpty())
	{
		if (first == last)
			first = last = nullptr;
		else
			first->first->nextPtr;
	}
}

template <class T>
void LinkedList<T>::deleteLast()
{
	if (!isEmpty())
	{
		if (first == last)
			first = last = nullptr;
		else
		{
			LinkedList<T>* curr = first;
			while (curr->nextPtr != last)
				curr = curr->nextPtr;
			last = curr;
			curr->nextPtr = nullptr;
		}
	}
}


template <class T>
T LinkedList<T>::get(unsigned int i) const
{
	LinkedList<T>* curr = first;
	int elem = 0;
	while (elem++ < i)
		curr = curr->nextPtr;
	return curr->value;
}
