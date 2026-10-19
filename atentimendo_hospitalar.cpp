#include <iostream>
#include <string>
using namespace std;

struct No {
    string nome;
    int    urgencia;
    No*    prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};No


struct FilaPacientes {
    No* frente = nullptr;
    No* tras   = nullptr;

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

    string dequeue() {
        if (isEmpty()) return "";
        
        No* temp = frente;
        string nomeRemovido = temp->nome;
        frente = frente->prox;
        
        if (frente == nullptr) {
            tras = nullptr;
        }
        
        delete temp;
        return nomeRemovido;
    }

    string frente_peek() const {
        if (isEmpty()) return "";
        return frente->nome;
    }

    bool isEmpty() const { return frente == nullptr; }

    int tamanho() const {
        int count = 0;
        No* p = frente;
        while (p != nullptr) {
            count++;
            p = p->prox;
        }
        return count;
    }

    ~FilaPacientes() {
        while (!isEmpty()) dequeue();
    }
};
struct PilhaHistorico {
    No* topo = nullptr;

    void push(const string& nome) {
        No* novo = new No(nome);
        novo->prox = topo;
        topo = novo;
    }

    string pop() {
        if (isEmpty()) return "";
        
        No* temp = topo;
        string nomeRemovido = temp->nome;
        topo = topo->prox;
        
        delete temp;
        return nomeRemovido;
    }

    string peek() const {
        if (isEmpty()) return "";
        return topo->nome;
    }

    bool isEmpty() const { return topo == nullptr; }

    ~PilhaHistorico() {
        while (!isEmpty()) pop();
    }
};
struct ListaMedicos {
    No* head = nullptr;

    void adicionarMedico(const string& nome) {
        No* novo = new No(nome);
        if (head == nullptr) {
            head = novo;
        } else {
            No* p = head;
            while (p->prox != nullptr) {
                p = p->prox;
            }
            p->prox = novo;
        }
    }

    string chamarMedico() {
        if (!temMedico()) return "";
        
        No* temp = head;
        string nomeRemovido = temp->nome;
        head = head->prox;
        
        delete temp;
        return nomeRemovido;
    }

    void percorrer(const string& prefixo = "") const {
        if (!prefixo.empty()) cout << prefixo << ": ";
        if (!temMedico()) {
            cout << "(lista vazia)\n";
            return;
        }
        
        No* p = head;
        while (p != nullptr) {
            cout << "[" << p->nome << "]";
            if (p->prox != nullptr) cout << " -> ";
            p = p->prox;
        }
        cout << "\n";
    }

    bool temMedico() const { return head != nullptr; }

    ~ListaMedicos() {
        while (head) {
            No* t = head;
            head  = head->prox;
            delete t;
        }
    }
};

void imprimirHistorico(PilhaHistorico& hist) {
    cout << "\n=== Relatorio de Atendimentos ===\n";
    if (hist.isEmpty()) {
        cout << "(nenhum atendimento registrado)\n";
        return;
    }

    PilhaHistorico aux;
    
    while (!hist.isEmpty()) {
        string at = hist.pop();
        cout << "  - " << at << "\n";
        aux.push(at);
    }

    while (!aux.isEmpty()) {
        hist.push(aux.pop());
    }
}




