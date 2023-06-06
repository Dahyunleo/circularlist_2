#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
// Structure for a node
typedef struct Node {
    element data;
    struct Node* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;	// (1)
        head->link = node;		// (2)
    }
    return head;	// 변경된 헤드 포인터를 반환한다. 
}
ListNode* insert_last(ListNode* head, element data)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;	// (1)
        head->link = node;		// (2)
        head = node;		// (3)
    }
    return head;	// 변경된 헤드 포인터를 반환한다. 
}

struct Node* deleteFirstNode(struct Node* head) {
    // If the list is empty, return
    if (head == NULL) {
        printf("List is empty");
        return;
    }

    
    // If the list has only one node
    if (head->link == head) {
        free(head);
        return NULL;
    }

    // Find the last node
    struct Node* last = head;
    while (last->link != head) {
        last = last->link;
    }

    struct Node* temp = head;
    head = head->link;

    last->link = head;

    //free(temp);
    return head;

    
}

struct Node* deleteLastNode(struct Node* head) {

    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
        


    if (head->link == head) {
        free(head);
        return NULL;
    }


    struct Node* second_last =head;
    while (second_last->link->link != head) {
        second_last = second_last->link;
    }


    struct Node* last = second_last->link;
    second_last->link = head;
    free(last);
    return head;
}


void print_List(struct Node* head) {
    // If the list is empty, return
    
    if (head == NULL)return;

    struct Node* temp= head->link;
    do {
        printf("%d->", temp->data);
        temp = temp->link;
    } while (temp != head);
    printf("%d->", temp->data);
}




void menu() {
    printf("\n-----Menu-----\n");
    printf("1. Insert first\n");
    printf("2. Insert last\n");
    printf("3. Delelte First \n");
    printf("4. Delete last\n");
    printf("5. Print List\n");
    printf("0. Exit\n");
    printf("Enter the number:");
}

int main() {
    struct Node* head = NULL;
    int choice, data;

    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            printf("Exiting program.\n");
            return 0;
        case 1:
            printf("Input the number:");
            scanf("%d", &data);
            head = insert_first(head, data);
            
            //printf("%s has been added.\n", data);

            break;
        case 2:
            printf("Input the number:");
            scanf("%d", &data);
            head=insert_last(head, data);
            break;
        case 3:
            head=deleteFirstNode(head);
            printf("First node has been deleted\n");
            break;
        case 4:
            head=deleteLastNode(head);
            printf("Last Node has beem deleted.\n");
            break;
        case 5:
            print_List(head);
            break;
        
        }
    }
}