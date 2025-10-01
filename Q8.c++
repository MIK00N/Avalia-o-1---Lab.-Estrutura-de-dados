#include <iostream>
using namespace std;

// Estrutura do nó
struct Node {
    int info;
    Node* prev;
    Node* next;
};

// Classe da Lista Duplamente Encadeada
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // a) Inserir elemento em qualquer posição
    void insert(int value, int pos) {
        Node* newNode = new Node{value, nullptr, nullptr};

        // Inserir no início
        if (pos == 0 || head == nullptr) {
            newNode->next = head;
            if (head != nullptr)
                head->prev = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        int count = 0;

        // Avança até a posição desejada ou até o final
        while (temp->next != nullptr && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        newNode->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = newNode;
        newNode->prev = temp;
        temp->next = newNode;
    }

    // b) Imprimir lista
    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // c) Buscar elemento (recursivo)
    Node* searchRecursive(Node* current, int value) {
        if (current == nullptr) return nullptr;        
        if (current->info == value) return current;    
        return searchRecursive(current->next, value);  
    }

    Node* search(int value) {
        return searchRecursive(head, value);
    }
    // d) Excluir elemento em qualquer posição
    void remove(int pos) {
        if (head == nullptr) return;

        Node* temp = head;

        // Remover do início
        if (pos == 0) {
            head = temp->next;
            if (head != nullptr)
                head->prev = nullptr;
            delete temp;
            return;
        }

        int count = 0;
        while (temp != nullptr && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) return; // posição inválida

        if (temp->prev != nullptr)
            temp->prev->next = temp->next;
        if (temp->next != nullptr)
            temp->next->prev = temp->prev;

        delete temp;
    }
};

// Exemplo de uso
int main() {
    DoublyLinkedList lista;

    lista.insert(10, 0); // [10]
    lista.insert(20, 1); // [10, 20]
    lista.insert(30, 2); // [10, 20, 30]
    lista.insert(15, 1); // [10, 15, 20, 30]
    lista.print();

    Node* achou = lista.search(20);
    if (achou != nullptr)
        cout << "Elemento 20 encontrado!" << endl;
    else
        cout << "Elemento 20 não encontrado." << endl;

    lista.remove(1); // remove o elemento da posição 1 (15)
    lista.print();

    lista.remove(0); // remove o primeiro (10)
    lista.print();

    return 0;
}