#include <stdio.h>
#include <stdlib.h>

// Definição das estruturas de dados
typedef struct Reg {
    int infor;
    struct Reg *prox;
} No;

typedef struct TipoPilha {
    No *Topo;
    int tamanho;
} Pilha;

// Inicializa a pilha
void inicializarPilha(Pilha *pilha) {
    pilha->Topo = NULL;
    pilha->tamanho = 0;
}

// a) Inserir elementos (Push)
void push(Pilha *pilha, int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memoria para o novo no.\n");
        return;
    }
    
    novoNo->infor = valor;
    novoNo->prox = pilha->Topo;
    pilha->Topo = novoNo;
    pilha->tamanho++;
}

// b) Excluir elementos (Pop)
int pop(Pilha *pilha) {
    if (pilha->tamanho == 0) {
        printf("A pilha esta vazia. Nao e possivel remover elementos.\n");
        return -1; // Valor de erro
    }
    
    No *noRemovido = pilha->Topo;
    int valor = noRemovido->infor;
    pilha->Topo = noRemovido->prox;
    free(noRemovido);
    pilha->tamanho--;
    
    return valor;
}

// c) Listar o conteudo da pilha
void listarPilha(Pilha *pilha) {
    if (pilha->tamanho == 0) {
        printf("A pilha esta vazia.\n");
        return;
    }
    
    No *atual = pilha->Topo;
    printf("Conteudo da pilha (do topo para a base):\n");
    while (atual != NULL) {
        printf("%d\n", atual->infor);
        atual = atual->prox;
    }
}

// d) Verificar se um dado elemento esta presente na pilha
int buscarElemento(Pilha *pilha, int valor) {
    No *atual = pilha->Topo;
    while (atual != NULL) {
        if (atual->infor == valor) {
            return 1; // Elemento encontrado
        }
        atual = atual->prox;
    }
    return 0; // Elemento nao encontrado
}

// Exemplo de uso
int main() {
    Pilha minhaPilha;
    inicializarPilha(&minhaPilha);

    // Inserindo elementos na pilha
    push(&minhaPilha, 10);
    push(&minhaPilha, 20);
    push(&minhaPilha, 30);
    printf("Elementos inseridos.\n");

    // Listando o conteúdo
    listarPilha(&minhaPilha);

    // Verificando a presença de um elemento
    int elementoProcurado = 20;
    if (buscarElemento(&minhaPilha, elementoProcurado)) {
        printf("\nO elemento %d esta na pilha.\n", elementoProcurado);
    } else {
        printf("\nO elemento %d nao esta na pilha.\n", elementoProcurado);
    }

    // Removendo um elemento
    int valorRemovido = pop(&minhaPilha);
    printf("\nElemento removido do topo: %d\n", valorRemovido);

    // Listando o conteúdo novamente
    listarPilha(&minhaPilha);

    // Verificando a presença de um elemento que foi removido
    elementoProcurado = 30;
    if (buscarElemento(&minhaPilha, elementoProcurado)) {
        printf("\nO elemento %d esta na pilha.\n", elementoProcurado);
    } else {
        printf("\nO elemento %d nao esta na pilha.\n", elementoProcurado);
    }

    return 0;
}