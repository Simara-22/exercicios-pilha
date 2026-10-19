#include <iostream>
using namespace std;

struct No {
    int valor;
    No* prox;
};

No* topo = NULL;

void empilhar(int valor) {
    No* novo = new No;
    novo->valor = valor;
    novo->prox = topo;
    topo = novo;
}

void removerMeio() {
    int tamanho = 0;
    No* aux = topo;

    while (aux != NULL) {
        tamanho++;
        aux = aux->prox;
    }

    if (tamanho == 0) {
        return;
    }

    int meio = tamanho / 2;
    aux = topo;

    if (meio == 0) {
        topo = topo->prox;
        delete aux;
        return;
    }

    for (int i = 0; i < meio - 1; i++) {
        aux = aux->prox;
    }

    No* temp = aux->prox;
    aux->prox = temp->prox;
    delete temp;
}

void mostrar() {
    No* aux = topo;

    while (aux != NULL) {
        cout << aux->valor << " ";
        aux = aux->prox;
    }

    cout << endl;
}

int main() {
    empilhar(10);
    empilhar(20);
    empilhar(30);
    empilhar(40);
    empilhar(50);

    cout << "Pilha original: ";
    mostrar();

    removerMeio();

    cout << "Pilha sem o meio: ";
    mostrar();

    return 0;
}