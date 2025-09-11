#include <iostream>

using namespace std;

typedef struct Reg{
    int info;
    Reg* next;
}Node;

class Linkedlist
{
    Node* first = nullptr;

    public:
    void insert(int n)
    {
        Node* newNode = new Node;
        newNode->info = n;
        if(first == NULL)
        {
            newNode->next = first;
            first = newNode;
        }
        else
        {
            newNode->next = first;
            first = newNode;  
        }
    }

    void print()
    {
        Node* aux = first;
        while(aux != nullptr){
            printf("%d\n", aux->info);
            aux = aux->next;
        }
    };
};

int main(){
    Linkedlist List;
    
    int n, op;
    while(op != 3){
        cout<<"ESCOLHA ENTRE AS OPCOES"<<endl; 
        cout<<" [1]- inserir"<<endl;
        cout<<" [2]- percorrer/printar"<<endl;
        
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                cout<<"infomer um numero"<<endl;
                scanf("%d", &n);
                List.insert(n);
            break;

            case 2:
                List.print();
                system("pause");
            break;
        }
    }
};