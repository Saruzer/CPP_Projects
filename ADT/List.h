#pragma once
template<typename T>
class List
{
private:
	void Copy(const List& other);
	struct Node {
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;
	size_t size;

public:
	class Iterator 
	{
	public:
		Iterator(Node* node);

		bool operator !=(const Iterator& other) const;
		Iterator& operator++();
		Iterator operator++(int);

		T& operator*();
	private:
		Node* node;
	};
	List();

	List(const List& other);

	List(List&& other) noexcept;

	~List();


	void PushBack(const T& value);
	void PushFront(const T& value);

	void PopBack();
	void PopFront();
	void Remove(const T& value);
	void Clear();

	bool Find(const T& value);

	bool IsEmpty(const T& value) const;
	size_t Size() const;

	Iterator Begin();
	Iterator End();

	List& operator=(const List& other);
	List& operator=(List&& other) noexcept;

};
template<typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) { }
template<typename T>
List<T>::List(const List& other) : head(nullptr), tail(nullptr), size(0) {/* Copy(other) */ }
template<typename T>
List<T>::List(List&& other) noexcept : head(other.head), tail(other.tail), size(other.size) { other.head = nullptr; other.tail == nullptr; other.size = 0; }

template<typename T>
List<T>::~List() { Clear(); }

template<typename T>
void List<T>::Clear()
{
	while (head != nullptr)
	{
		Node* current = head;
		head = head->next;
		delete current;
	}
	tail = nullptr;
	size = 0;
}

template<typename T>
bool List<T>::Find(const T& value)
{
	if (head == nullptr)
		return false;
	Node* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template<typename T>
bool List<T>::IsEmpty(const T& value) const
{
	return head == nullptr;
}

template<typename T>
size_t List<T>::Size() const
{
	return size;

}

template<typename T>
typename List<T>::Iterator List<T>::Begin()
{
	Iterator it(head);
	return it;
}

template<typename T>
typename List<T>::Iterator List<T>::End()
{
	Iterator it(nullptr);
	return it;
}

template<typename T>
void List<T>::PushBack(const T& value)
{
	if (head == nullptr) {
		head = new Node{ value,nullptr };
		tail = head;
	}
	else
	{
		tail->next = new Node{ value,nullptr };
		tail = tail->next;
	}
	size++;
}

template<typename T>
void List<T>::PushFront(const T& value)
{
	if (head == nullptr)
	{
		head = new Node{ value, nullptr };
		tail = head;
	}
	else if (head == tail)
	{
		Node* newNode = new Node{ value,head };
		head = newNode;

		tail = head->next;
	}
	else
	{
		Node* newNode = new Node{ value,head };
		head = newNode;
	}
	size++;
}

template<typename T>
void List<T>::PopBack()
{
	if (head == nullptr) {
		return;
	}
	else if (head->next == nullptr) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* previous = head;
		Node* current = head->next;
		while (current->next != nullptr) {
			previous = current;
			current = current->next;
		}
		delete current;
		previous->next = nullptr;
		tail = previous;
	}
	size--;
}

template<typename T>
void List<T>::PopFront()
{
	if (head == nullptr)
	{
		return;
	}
	else if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* newHead = head->next;
		delete head;
		head = newHead;
	}
	size--;
}

template<typename T>
void List<T>::Remove(const T& value)
{
	Node* previous = nullptr;
	Node* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			if (previous == nullptr)
			{
				head = head->next;

				if (head == nullptr)
				{
					tail = nullptr;
				}
			}
			else
			{
				previous->next = current->next;

				if (current == tail)
				{
					tail = previous;
				}
			}

			size--;
			delete current;
			return;
		}
		previous = current;
		current = current->next;
	}
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this != &other) {
		Clear();
		Copy(other);
	}

	return *this;
}

template<typename T>
List<T>& List<T>::operator=(List<T>&& other) noexcept
{
	if (this != &other) {
		Clear();
		head = other.head;
		tail = other.tail;
		size = other.size;
		other.tail = nullptr;
		other.head = nullptr;
		other.size = 0;
	}

	return *this;
}
template<typename T>
void List<T>::Copy(const List<T>& other)
{
	if (other.head == nullptr) {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	else
	{
		head = new Node{ other.head->data,nullptr };
		Node* current = head;
		Node* otherCurrent = other.head;

		while (otherCurrent->next != nullptr) {
			current->next = new Node{ otherCurrent->next->data,nullptr };

			current = current->next;
			otherCurrent = otherCurrent->next;
		}
		tail = current;

		size = other.size;
	}

}
template<typename T>
List<T>::Iterator::Iterator(Node* node) : node(node)
{

}
template<typename T>
typename bool List<T>::Iterator::operator!=(const Iterator& other) const
{
	return node != other.node;
}
template<typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++()
{
	node = node->next;
	return *this;
}
template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
	Iterator temp(*this);
	node = node->next;
	return temp;
}
template<typename T>
typename T& List<T>::Iterator::operator*()
{
	return node->data;
}

