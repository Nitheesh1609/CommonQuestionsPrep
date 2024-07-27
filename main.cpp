#include <iostream>

/*
 * Linked List Add at Front Delete at End;
 */
struct Node{
    int data;
    struct Node * next;
};

//add
struct Node * create_node(int data){
    struct Node * temp = new struct Node;
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

int add_node(struct Node **head, int data){
    struct Node *temp = create_node(data);
    if(*head == nullptr){
        *head = temp;
        std::cout << "First";
        return 0;
    }
    temp->next = *head;
    *head = temp;
    return 0;
}

int delete_node(struct Node **head, int *data){
   struct Node * tmp = *head, *prev= nullptr;
    while(tmp->next != nullptr){
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = nullptr;
    *data = tmp->data;
    tmp = tmp->next;
    delete tmp;
    return 0;
}

void print(struct Node **head){
    struct Node *tmp = *head;
    while(tmp != nullptr){
        std::cout << "Value is " << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

int main() {
    struct Node *head = nullptr;
    struct Node *tail = nullptr;
    int errp=0;
    errp = add_node(&head,5);
    if(errp != 0){
         std::cout << "Error" ;
         return -1;
    }
    errp = add_node(&head,10);
    if(errp != 0){
        std::cout << "Error" ;
        return -1;
    }
    errp = add_node(&head,15);
    if(errp != 0){
        std::cout << "Error" ;
        return -1;
    }
    print(&head);
    int data;
    errp = delete_node(&head, &data);
    if(errp != 0){
        std::cout << "Error" ;
        return -1;
    }
    std::cout << "Deleted Value is " << data << std::endl;
    print(&head);
    return 0;
}
