#include <iostream>

// --- ESTRUTURA DO NÓ ---
struct NO {
    int info;     
    NO* prox;    
    NO* ant;      
};

// --- CLASSE DA LISTA DUPLAMENTE ENCADEADA ---
class ListaDupla {
private:
    NO* inicio;   
    NO* fim;      
    int tamanho;  

public:
    ListaDupla();

    ~ListaDupla();

    // Funções de operação da lista
    bool ListaVaziaLD();
    void InserirInicioLD(int k);
    void MostrarLD();
};

// --- IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE ---

// Construtor: Inicia uma lista vazia
ListaDupla::ListaDupla() {
    inicio = NULL;
    fim = NULL;
    tamanho = 0;
    std::cout << "Lista criada com sucesso!" << std::endl;
}

// Destrutor: Limpa todos os nós da memória para evitar vazamentos
ListaDupla::~ListaDupla() {
    NO* atual = inicio;
    while (atual != NULL) {
        NO* proximo = atual->prox;
        delete atual;
        atual = proximo;
    }
    std::cout << "\nLista destruida com sucesso!" << std::endl;
}

// Verifica se a lista está vazia
bool ListaDupla::ListaVaziaLD() {
    return (inicio == NULL);
}

// --- FUNÇÃO INSERE (MODIFICADA) ---
// Insere um registro no início, impedindo a inserção de duplicados
void ListaDupla::InserirInicioLD(int k) {
    // PASSO 1: Percorrer a lista para verificar se o elemento 'k' já existe.
    NO* atual = inicio;
    while (atual != NULL) {
        if (atual->info == k) {
            // Se encontrou o elemento, informa o ocorrido e sai da função.
            std::cout << "-> Elemento " << k << " ja existe na lista. Insercao cancelada." << std::endl;
            return; 
        }
        atual = atual->prox;
    }

    // Se o loop terminou, o elemento não foi encontrado e pode ser inserido.
    std::cout << "-> Inserindo o elemento " << k << " no inicio..." << std::endl;
    NO *novo = new NO;
    novo->info = k;
    novo->ant = NULL;

    if (ListaVaziaLD()) {
        novo->prox = NULL;
        inicio = fim = novo;
    } else {
        novo->prox = inicio;
        inicio->ant = novo;
        inicio = novo;
    }
    tamanho++; // Incrementa o tamanho da lista
}

// Mostra todos os elementos da lista
void ListaDupla::MostrarLD() {
    std::cout << "\n--- Exibindo a Lista ---" << std::endl;
    if (ListaVaziaLD()) {
        std::cout << "A lista esta vazia." << std::endl;
        return;
    }

    NO* atual = inicio;
    std::cout << "NULL <- ";
    while (atual != NULL) {
        std::cout << "[" << atual->info << "] ";
        if (atual->prox != NULL) {
            std::cout << "<-> ";
        }
        atual = atual->prox;
    }
    std::cout << "-> NULL" << std::endl;
    std::cout << "Tamanho da lista: " << tamanho << std::endl;
    std::cout << "------------------------" << std::endl;
}


int main() {
    ListaDupla minhaLista;

    minhaLista.InserirInicioLD(10);
    minhaLista.InserirInicioLD(20);
    minhaLista.InserirInicioLD(30);

    minhaLista.InserirInicioLD(20);

  
    minhaLista.InserirInicioLD(40);

    minhaLista.InserirInicioLD(10);

    minhaLista.MostrarLD();

    return 0; 
}