#include<iostream>

using namespace std;

class ListNode
{
	friend class List; 

public:
	ListNode(const int &info) : data(info), next(0){} 
	int getData() const{
		return data;
	} 
private:
	int data; 
	ListNode *next; 
}; 

class List
{
private:
	ListNode *firstPtr; 
	ListNode *lastPtr; 

	
	ListNode *getNewNode(const int &value)
	{
		return new ListNode(value);
	} 

public:
	List() : firstPtr(0), lastPtr(0){} 
	~List(){
		if (!isEmpty()) 
		{
			cout << "Destroying nodes ...\n";

			ListNode *currentPtr = firstPtr;
			ListNode *tempPtr;

			while (currentPtr != 0) 
			{
				tempPtr = currentPtr;
				cout << tempPtr->data << '\n';
				currentPtr = currentPtr->next;
				delete tempPtr;
			} 
		} 

		cout << "All nodes destroyed\n\n";
	}
	void insertAtFront(const int &value){
		ListNode *newPtr = getNewNode(value);

		if (isEmpty()) 
			firstPtr = lastPtr = newPtr; 
		else
		{
			newPtr->next = firstPtr;
			firstPtr = newPtr;
		}
	}
	void insertAtBack(const int &value)
	{
		ListNode *newPtr = getNewNode(value);

		if (isEmpty()) 
			firstPtr = lastPtr = newPtr; 
		else
		{
			lastPtr->next = newPtr;
			lastPtr = newPtr;
		}

	}
	bool removeFromFront(int &value)
	{
		if (isEmpty()) 
			return false; 
		else
		{
			ListNode *tempPtr = firstPtr;

			if (firstPtr == lastPtr)
				firstPtr = lastPtr = 0; 
			else
				firstPtr = firstPtr->next; 

			value = tempPtr->data; 
			delete tempPtr; 
			return true; 
		} 
	} 

	
	bool removeFromBack(int &value)
	{
		if (isEmpty()) 
			return false;
		else
		{
			ListNode *tempPtr = lastPtr;

			if (firstPtr == lastPtr) 
				firstPtr = lastPtr = 0;
			else
			{
				ListNode *currentPtr = firstPtr;

				            
				while (currentPtr->next != lastPtr)
					currentPtr = currentPtr->next; 

				lastPtr = currentPtr; 
				currentPtr->next = 0; 
			} 

			value = tempPtr->data; 
			delete tempPtr; 
			return true; 
		} 
	} 


	bool isEmpty() const{
		return firstPtr == 0;
	}
	void print() const{
		if (isEmpty()) 
		{
			cout << "The list is empty\n\n";
			return;
		} 

		ListNode *currentPtr = firstPtr;

		cout << "The list is: ";

		while (currentPtr != 0)
		{
			cout << currentPtr->data << ' ';
			currentPtr = currentPtr->next;
		} 

		cout << "\n\n";
	} 

	bool removeEachWhere(int &value)
	{
		if (isEmpty()) 
			return false;
		else
		{
			ListNode* current = firstPtr;

			ListNode * prev = (ListNode *)malloc(sizeof(ListNode));
			while (current != NULL)
			{
				if (current->data != value)
				{
					prev = current;
					current = current->next;
				}
				else
				{
					prev->next = current->next;
					delete current;
					return true;
				}
			}
		}

	}
	bool insertEachWhere(int &value, int &set)
	{
		ListNode *newPtr = getNewNode(set);
		if (isEmpty()) 
			return false;
		else
		{
			ListNode* current = firstPtr;

			ListNode * prev = (ListNode *)malloc(sizeof(ListNode));;
			while (current != NULL)
			{
				if (current->data != value)
				{
					prev = current;
					current = current->next;
				}
				else
				{
					prev->next = newPtr;
					prev->next->next = current->next;
					delete current;
					return true;
				}
			}
		}
	}

	bool search(int &value)
	{
		if (isEmpty()) 
			return false;
		else
		{
			ListNode* current = firstPtr;

			while (current != NULL)
			{
				if (current->data == value)
				{
					cout << value;
					return true;

				}
				current = current->next;
			}
		}
	}


	bool order()
	{
		if (isEmpty()) 
			return false;
		else
		{
			ListNode* current = firstPtr->next;
			int temp;
			for (; current; current = current->next)
				for (ListNode * prev = firstPtr; prev->next; prev = prev->next)
					if (prev->data > prev->next->data)
					{
						temp = prev->next->data;
						prev->next->data = prev->data;
						prev->data = temp;

					}
		}
		return true;
	}

};

int main()
{

	int v1 = 1, v2 = 2, v3 = 3, v4 = 5, v5 = 9, v6 = 10, v7 = 12, v8 = 13, v9 = 41;
	List d;

	d.insertAtFront(v1);
	d.print();
	d.insertAtFront(v2);
	d.print();
	d.insertAtFront(v3);
	d.print();
	d.insertAtFront(v4);
	d.print();
	cout << endl;
	d.insertAtBack(v5);
	d.print();
	d.insertAtBack(v6);
	d.print();
	d.insertAtBack(v7);
	d.print();
	d.insertAtBack(v8);
	d.print();
	cout << endl;
	d.removeEachWhere(v3);
	d.print();
	d.insertEachWhere(v2, v9);
	d.print();

	d.search(v7);

	d.order();
	d.print();
	//list *head = new list();
	//list *cur;
	//head->next = 0;
	//cur=head->next = new list;
	//head->next->d = 1;
	//head->next->next = 0;
	//head->next->next = new list;
	//head->next->next -> d = 5;
	//head->next->next->next = 0;
	//for (cur = head->next; cur != 0; cur = cur->next)
	//	cout << cur->d<<endl;
	//cout << head->next->next->d <<"\t"<< head->next->d << endl;




	system("pause");
	return 0;

}