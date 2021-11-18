#include <iostream>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node** head, int node_data) {
    struct Node* newNode = new Node;

    newNode->data = node_data;

    newNode->next = (*head);

    (*head) = newNode;
}

void append(struct Node** head, int node_data) {
    struct Node* newNode = new Node;
    struct Node *tmp = *head;

    newNode->data = node_data;
    newNode->next = NULL;

    if(*head == NULL) {
      *head = newNode;
      return;
    }

    while(tmp->next != NULL) {
      tmp = tmp->next;
    }

    tmp->next = newNode;
    return;
  
}

void insertAfter(struct Node* target, int node_data) {
    if (target == NULL) {
	std::cout << "Target can not be NULL\n";
	return;
    }

    struct Node* newNode = new Node;
    newNode->data = node_data;

    newNode->next = target->next;
    target->next = newNode;
}

void displayList(struct Node* head) {
    while(head != NULL) {
	std::cout << head->data << " ";
	head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    struct Node* head = NULL;

    append(&head, 1);
    push(&head, 2);
    push(&head, 3);
    append(&head, 4);

    insertAfter(head->next, 5);
	
    std::cout << "Final linked list: " << std::endl;
    displayList(head);

    return 0;
}
