#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    int    urgencia;
    No*    prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};No
{
    string nome;
    int urgencia; // 1=baixa, 2=media, 3=alta (usado apenas por Paciente)
    No *prox;
    No(const string &n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};

struct FilaPacientes
{
    No *frente = nullptr;
    No *tras = nullptr;

    void enqueue(const string& nome, int urgencia) {
        No* novo = new No(nome, urgencia);
        if (isEmpty()) {
            frente = novo;
            tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
    }

    // TODO 2: Implemente dequeue()
    //         Remove e retorna o nome do paciente na frente da fila
    string dequeue()
    {
        // Dica: guarde o nome antes de deletar, atualize 'frente'
        //       se frente ficar nullptr, atualize 'tras' também!
        return ""; // substitua pelo retorno correto
    }

    // TODO 3: Implemente frente_peek() — ver quem está na frente sem remover
    string frente_peek() const
    {
        return ""; // substitua pelo retorno correto
    }

    bool isEmpty() const { return frente == nullptr; }

    // BÔNUS: Implemente tamanho() que conta os nós na fila
    int tamanho() const
    {
        // ...
        return 0;
    }

    ~FilaPacientes()
    {
        while (!isEmpty())
            dequeue();
    }
};




