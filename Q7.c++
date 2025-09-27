#include <stdio.h>
#include <stdlib.h>

// Definição das structs
typedef struct Reg {
    int infor;
    struct Reg *prox;
} No;

typedef struct TipoFila {
    No *Inicio;
    No *Fim;
    int tamanho;
} Fila;

// Inicializa a fila
void inicializarFila(Fila *fila) {
    fila->Inicio = NULL;
    fila->Fim = NULL;
    fila->tamanho = 0;
}

// a) Inserir elementos (Enqueue)
void enqueue(Fila *fila, int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }
    
    novoNo->infor = valor;
    novoNo->prox = NULL; // O novo nó será o último, então ele aponta para NULL

    if (fila->tamanho == 0) {
        // Se a fila estiver vazia, o novo nó é o início e o fim
        fila->Inicio = novoNo;
        fila->Fim = novoNo;
    } else {
        // O último nó atual aponta para o novo nó
        fila->Fim->prox = novoNo;
        // O novo nó se torna o fim da fila
        fila->Fim = novoNo;
    }
    fila->tamanho++;
}

// b) Excluir elementos (Dequeue)
int dequeue(Fila *fila) {
    if (fila->tamanho == 0) {
        printf("A fila esta vazia. Nao e possivel remover elementos.\n");
        return -1; // Valor de erro
    }
    
    No *noRemovido = fila->Inicio;
    int valor = noRemovido->infor;
    
    fila->Inicio = noRemovido->prox;
    
    // Se o último elemento foi removido, o Fim também deve ser NULL
    if (fila->Inicio == NULL) {
        fila->Fim = NULL;
    }
    
    free(noRemovido);
    fila->tamanho--;
    
    return valor;
}

// c) Listar o conteúdo da fila
void listarFila(Fila *fila) {
    if (fila->tamanho == 0) {
        printf("A fila esta vazia.\n");
        return;
    }
    
    No *atual = fila->Inicio;
    printf("Conteudo da fila (do inicio para o fim):\n");
    while (atual != NULL) {
        printf("%d\n", atual->infor);
        atual = atual->prox;
    }
}

// d) Verificar se um dado elemento está presente na fila
int buscarElemento(Fila *fila, int valor) {
    No *atual = fila->Inicio;
    while (atual != NULL) {
        if (atual->infor == valor) {
            return 1; // Elemento encontrado
        }
        atual = atual->prox;
    }
    return 0; // Elemento não encontrado
}

// Exemplo de uso
int main() {
    Fila minhaFila;
    inicializarFila(&minhaFila);

    // Inserindo elementos (primeiro o 10, depois o 20, etc.)
    enqueue(&minhaFila, 10);
    enqueue(&minhaFila, 20);
    enqueue(&minhaFila, 30);
    printf("Elementos inseridos na fila.\n");

    // Listando o conteúdo
    listarFila(&minhaFila);

    // Removendo um elemento (o 10, que foi o primeiro a entrar)
    int valorRemovido = dequeue(&minhaFila);
    printf("\nElemento removido do inicio: %d\n", valorRemovido);

    // Listando o conteúdo novamente
    listarFila(&minhaFila);

    // Verificando a presença de um elemento
    int elementoProcurado = 20;
    if (buscarElemento(&minhaFila, elementoProcurado)) {
        printf("\nO elemento %d esta na fila.\n", elementoProcurado);
    } else {
        printf("\nO elemento %d nao esta na fila.\n", elementoProcurado);
    }

    return 0;
}