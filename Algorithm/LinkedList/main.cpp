#include <iostream>
using namespace std;

struct node {
	struct student {
		int id;
		char grade;
	}s;
	struct node* next;
	node(int _id, char _grade) { s.id = _id, s.grade = _grade, next = NULL; }
};
typedef struct node node;

node* head = NULL;

void print_node(void) {
	node* ptr = head;
	while (ptr != NULL) {
		cout << ptr->s.id << ": " << ptr->s.grade << endl;
		ptr = ptr->next;
	}
}

// head���� ������ id�� ���ϸ�, ������������ ��带 �����մϴ�.
void insert_node(int _id, char _grade) {
	node* newNode = new node(_id, _grade);
	if (head == NULL) head = newNode;
	else {
		node* ptr = head;
		while (ptr != NULL) {
			// �߰� ����
			if (ptr->next != NULL && ptr->next->s.id > _id) {
				newNode->next = ptr->next;
				ptr->next = newNode;
				return;
			}
			// �� ����
			if (ptr->next == NULL) {
				ptr->next = newNode;
				return;
			}
			ptr = ptr->next;
		}
	}
}

void delete_node(int _id) {
	if (head == NULL) return;

	node* prevNode = NULL;
	node* removeNode = head;
	while (removeNode != NULL) {
		if (removeNode->s.id == _id) {
			if (head == removeNode) head = removeNode->next;	// ���� ��� ��尡 ù ��°�� ���� ���
			else prevNode->next = removeNode->next;
			delete(removeNode);
			return;
		}
		prevNode = removeNode;
		removeNode = removeNode->next;
	}
}

int main(void) {
	insert_node(1, 'A');
	insert_node(7, 'C');
	insert_node(5, 'C');
	insert_node(3, 'B');
	print_node();
	cout << endl;

	delete_node(1);
	delete_node(5);
	print_node();

	return 0;
}