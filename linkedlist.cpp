#include <iostream>


template<class T>
class Node {
private:

public:
	T data;
	Node<T>* next;

	Node(T value){
		data = value;
		next = nullptr;
	}
};


template<class T>
class LinkedList {
private:
	Node<T>* head;

public:

	LinkedList() {
		head = nullptr;
	}

	void appendNode(T value){
		Node<T>* nodePtr;
		Node<T>* newNode;
		newNode = new Node<T>(value);

		if (!head) {
			head = newNode;
		} else {
			nodePtr = head;
			while (nodePtr->next) {
				nodePtr = nodePtr->next;
			}
			nodePtr->next = newNode;
		}
	}

	void prependNode(T value){
		Node<T>* newNode;
		newNode = new Node<T>(value);
		if(!head){
			head = newNode;
		} else{
			newNode->next = head;
			head = newNode;
		}

	}

	void deleteNode(T searchValue){
		Node<T>* previousNode;
		Node<T>* nodePtr;

		if(!head){
			return;
		}

		if(head->data == searchValue){
			nodePtr = head;
			head = head->next;
			delete nodePtr;
		}else{

			nodePtr = head;

			while(nodePtr != nullptr && nodePtr->data != searchValue){
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			if(nodePtr){
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}

	}

	void displayList() {

		Node<T>* nodePtr = head;

		while (nodePtr) {
			std::cout << nodePtr->data << std::endl;
			nodePtr = nodePtr->next;
		}
		delete nodePtr;
	}

};

int main(){

	LinkedList<int> list;
	for(int i = 0; i < 90; i++){
		//list.appendNode(i);
		list.prependNode(i);
	}

	for(int i = 50; i < 100; i+=2){
		list.deleteNode(i);
	}


	list.displayList();

	return 0;
}
