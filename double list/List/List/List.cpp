#include <iostream>
using namespace std;

// объявление структуры
struct Node //как "поле" идет
{
    struct Node* prev; // Указатель на предыдущий узел
    struct Node* next; // Указатель на следующий узел
    int data;  // Содержимое узла, данные
};

//вставка узла (node) в начало нашего списка, передаем начало списка и данные
void insert_front(struct Node** head, int new_data)
{
    struct Node* newNode = new Node; //выделение памяти. те ссылаясь на структуру, создаем новую

    newNode->data = new_data;//в новый узел определеляем данные (обращение по указаетелю

    //новый узел главный, а предыдущий ноль (типо до нет,ибо мы добавляем в самое начало)
    newNode->next = (*head);
    newNode->prev = NULL;

    //previous становится новым узлом, если новая ссылка не ноль
    if ((*head) != NULL)
        (*head)->prev = newNode;

    (*head) = newNode;  // 
}

//вставка узла, после того, как мы дали предыдущий узел(ссылку)
void insert_After(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL) {
        cout << "Previous node is required , it cannot be NULL";
        return;
    }

    struct Node* newNode = new Node;

    newNode->data = new_data;
    newNode->next = prev_node->next;  //newNode.next = prev_Node.next;
    prev_node->next = newNode;  //  установили новыйузел к следующему из предыдущих узлов
    newNode->prev = prev_node;

    //
    if ((newNode->next) != NULL) {
        newNode->next->prev = newNode;
    }
}
// добавления узла с конца списка
void insert_end(struct Node** head, int new_data) {
    struct Node* newNode = new Node;
    newNode->data = new_data;
    struct Node* last = *head; // последняя ссылка становится главной

    newNode->next = NULL; //  в нашем списук узед последний, поэтому следующая ссылка равна нулю

    // провекра на наличие
    if ((*head) == NULL) {
        newNode->prev = NULL;
        *head = newNode;
       // return;
    }
    //
    while (last->next != NULL) {
        last = last->next;
        last->next = newNode;
        newNode->prev = last; // добавили ссылку
        //return;
    }
}

void display(struct Node* node) {
    struct Node* last;

    while (node != NULL) {
        cout << node->data << " <===> ";
        last = node;
        node = node->next;
    }

    if (node == NULL) {
        cout << " node is nill " << endl;
    }
}


int main(){
    struct Node* node = NULL;
    insert_end(&node, 4);
    insert_front(&node, 2);
    insert_front(&node, 1);
    insert_end(&node, 5);
    insert_After(node->next, 3);

    cout << "Doubly linked list is as follows: " << endl << endl;
    display(node);

    delete node;
    return 0;
}