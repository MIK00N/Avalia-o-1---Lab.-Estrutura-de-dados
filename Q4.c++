#include <iostream>
using namespace std;

typedef struct Reg{
int info;
Reg *next;
}Node;

class LinkedList{

Node* first = NULL;
public:

void insert(int n){
    Node* newNode= new Node{n, first};
    first = newNode;
}

void print()
{
    Node* current = first;

    while(current->next != NULL)
    {
        cout << current->info << endl;
        current = current->next;
    }
}

void del(int n)
{
    Node* current = first;
    Node* previous = nullptr;
    
    while(current->next != NULL)
    {
            if(current->info == n)
            {
                if(previous == nullptr)
                {
                    first = current->next;
                }
                else
                {
                    previous->next = current->next;
                }
                delete current;
                return;
            }

            previous = current;
            current = current->next;
    } 
}

};

int main() {
    LinkedList list;
    int op = 0,n;
    
    while(op != 4){
        
        cout<<"========================="<<endl;
        cout<<"escolha um alternativa"<<endl;
        cout<<"1 - inserir"<<endl;
        cout<<"2 - percorrer/printar"<<endl;
        cout<<"3 - deletar um elemento"<<endl;
        cout<<"4 - sair"<<endl;
        cout<<"========================="<<endl;
        
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                cout<<"informe o elemento a ser inserido"<<endl;
                scanf("%d", &n);
                list.insert(n);
            break;

            case 2:
                list.print();
                system("pause");
            break;

            case 3:
                cout<<"informe o elemento a ser deletado"<<endl;
                scanf("%d", &n);
                list.del(n);
            break;

            default:

            break;
        }
    }
    
}