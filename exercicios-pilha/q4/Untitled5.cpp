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

bool verificar(string palavra) {
    for (int i = 0; i < palavra.size(); i++) {
        empilhar(palavra[i]);
    }

    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] != topo->letra) {
            return false;
        }

        No* temp = topo;
        topo = topo->prox;
        delete temp;
    }

    return true;
}

int main() {
    string palavra;

    cout << "Digite uma palavra: ";
    cin >> palavra;

    if (verificar(palavra)) {
        cout << "A palavra e um palindromo.";
    } else {
        cout << "A palavra nao e um palindromo.";
    }

    return 0;
}