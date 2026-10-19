#include <iostream>
#include <string>
using namespace std;

struct No {
    char letra;
    No* prox;
};

No* topo = NULL;

void empilhar(char letra) {
    No* novo = new No;
    novo->letra = letra;
    novo->prox = topo;
    topo = novo;
}

void mostrarInvertida() {
    while (topo != NULL) {
        No* temp = topo;

        cout << topo->letra;

        topo = topo->prox;
        delete temp;
    }
}

int main() {
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    for (int i = 0; i < palavra.size(); i++) {
        empilhar(palavra[i]);
    }

    cout << "Palavra invertida: ";
    mostrarInvertida();

    return 0;
}