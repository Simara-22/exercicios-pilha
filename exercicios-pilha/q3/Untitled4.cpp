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

void removerDuplicados() {
    No* atual = topo;

    while (atual != NULL) {
        No* aux = atual;

        while (aux->prox != NULL) {
            if (aux->prox->valor == atual->valor) {
                No* temp = aux->prox;
                aux->prox = temp->prox;
                delete temp;
            } else {
                aux = aux->prox;
            }
        }

        atual = atual->prox;
    }
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
    empilhar(10);
    empilhar(30);
    empilhar(20);

    cout << "Pilha original: ";
    mostrar();

    removerDuplicados();

    cout << "Pilha sem duplicados: ";
    mostrar();

    return 0;
}