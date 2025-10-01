#include <iostream>

// --- ESTRUTURA DO NÓ (sem alterações) ---
struct NO {
    int info;
    NO* prox;
    NO* ant;
};

// --- CLASSE DA LISTA CIRCULAR DUPLAMENTE ENCADEADA ---
class ListaCircularDupla {
private:
    NO* inicio;
    NO* fim;
    int tamanho;

public:
    // Construtor
    ListaCircularDupla();

    // Destrutor (modificado para listas circulares)
    ~ListaCircularDupla();

    // Funções de operação da lista
    bool ListaVazia();
    void Inserir(int k); // Inserir no fim da lista
    void Retirar(int k); // Retirar um elemento específico
    void Mostrar();      // Mostrar a lista de forma circular
};

// --- IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE ---

// Construtor: Inicia uma lista vazia (sem alterações)
ListaCircularDupla::ListaCircularDupla() {
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
    std::cout << "Lista Circular Dupla criada com sucesso!" << std::endl;
}

// Destrutor: Limpa todos os nós da memória
ListaCircularDupla::~ListaCircularDupla() {
    if (!ListaVazia()) {
        NO* atual = inicio;
        NO* proximoNo;
        // Percorre a lista até o fim, quebrando o ciclo para evitar loop infinito
        fim->prox = NULL; 
        while (atual != NULL) {
            proximoNo = atual->prox;
            delete atual;
            atual = proximoNo;
        }
    }
    std::cout << "\nLista Circular Dupla destruida com sucesso!" << std::endl;
}

// Verifica se a lista está vazia (sem alterações)
bool ListaCircularDupla::ListaVazia() {
    return (inicio == NULL);
}

// --- FUNÇÃO INSERIR (adaptada para circular) ---
// Insere um registro no final da lista
void ListaCircularDupla::Inserir(int k) {
    NO* novo = new NO;
    novo->info = k;

    // CASO 1: A lista está vazia
    if (ListaVazia()) {
        inicio = novo;
        fim = novo;
        novo->prox = inicio; // O novo nó aponta para si mesmo
        novo->ant = fim;     // O novo nó aponta para si mesmo
    }
    // CASO 2: A lista não está vazia
    else {
        // O novo nó é inserido entre o 'fim' atual e o 'inicio'
        novo->prox = inicio;    // O próximo do novo nó é o início
        inicio->ant = novo;     // O anterior do início é o novo nó
        novo->ant = fim;        // O anterior do novo nó é o fim antigo
        fim->prox = novo;       // O próximo do fim antigo é o novo nó
        fim = novo;             // O novo nó se torna o novo fim
    }
    tamanho++;
    std::cout << "-> Elemento " << k << " inserido na lista." << std::endl;
}

// --- FUNÇÃO RETIRAR (nova implementação para circular) ---
void ListaCircularDupla::Retirar(int k) {
    if (ListaVazia()) {
        std::cout << "-> Lista vazia. Impossivel retirar o elemento " << k << "." << std::endl;
        return;
    }

    NO* atual = inicio;
    bool encontrou = false;

    // Procura o elemento na lista
    for (int i = 0; i < tamanho; i++) {
        if (atual->info == k) {
            encontrou = true;
            break;
        }
        atual = atual->prox;
    }

    if (!encontrou) {
        std::cout << "-> Elemento " << k << " nao encontrado na lista." << std::endl;
        return;
    }

    // CASO 1: A lista tem apenas um elemento
    if (tamanho == 1) {
        inicio = NULL;
        fim = NULL;
    }
    // CASO 2: A lista tem mais de um elemento
    else {
        // "Pula" o nó a ser removido
        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;

        // Ajusta os ponteiros 'inicio' e 'fim' se necessário
        if (atual == inicio) {
            inicio = atual->prox;
        }
        if (atual == fim) {
            fim = atual->ant;
        }
    }

    delete atual; // Libera a memória
    tamanho--;
    std::cout << "-> Elemento " << k << " retirado com sucesso." << std::endl;
}


// --- FUNÇÃO MOSTRAR (adaptada para circular) ---
void ListaCircularDupla::Mostrar() {
    std::cout << "\n--- Exibindo a Lista Circular ---" << std::endl;
    if (ListaVazia()) {
        std::cout << "A lista esta vazia." << std::endl;
        std::cout << "---------------------------------" << std::endl;
        return;
    }

    NO* atual = inicio;
    std::cout << "FIM -> ";
    // Usa um laço 'do-while' para garantir que imprima mesmo se houver um só elemento
    do {
        std::cout << "[" << atual->info << "] ";
        if (atual != fim) {
            std::cout << "<-> ";
        }
        atual = atual->prox;
    } while (atual != inicio);

    std::cout << "-> INICIO" << std::endl;
    std::cout << "Tamanho da lista: " << tamanho << std::endl;
    std::cout << "Inicio: [" << inicio->info << "], Fim: [" << fim->info << "]" << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

int main() {
    ListaCircularDupla minhaLista;
    minhaLista.Mostrar();

    minhaLista.Inserir(10);
    minhaLista.Inserir(20);
    minhaLista.Inserir(30);
    minhaLista.Mostrar();

    minhaLista.Retirar(20); // Retira do meio
    minhaLista.Mostrar();

    minhaLista.Retirar(10); // Retira o início
    minhaLista.Mostrar();

    minhaLista.Inserir(40);
    minhaLista.Inserir(50);
    minhaLista.Mostrar();

    minhaLista.Retirar(50); // Retira o fim
    minhaLista.Mostrar();
    
    minhaLista.Retirar(99); // Tenta retirar elemento inexistente
    
    minhaLista.Retirar(30);
    minhaLista.Retirar(40);
    minhaLista.Mostrar();

    return 0;
}