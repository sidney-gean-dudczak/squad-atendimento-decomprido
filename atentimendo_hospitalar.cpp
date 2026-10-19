#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct No {
    string nome;
    int urgencia;
    No* prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};

struct FilaPacientes {
    No* frente = nullptr;
    No* tras = nullptr;

    void enqueue(const string& nome, int urgencia) {
        No* novo = new No(nome, urgencia);
        if (frente == nullptr) {
            frente = novo;
            tras = novo;
        } else {
            tras->prox = novo;
            tras = novo;
        }
    }

    string dequeue() {
        if (frente == nullptr) return "";
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
        if (frente == nullptr) return "";
        return frente->nome;
    }

    bool isEmpty() const {
        return frente == nullptr;
    }

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
        if (topo == nullptr) return "";
        No* temp = topo;
        string nomeRemovido = temp->nome;
        topo = topo->prox;
        delete temp;
        return nomeRemovido;
    }

    string peek() const {
        if (topo == nullptr) return "";
        return topo->nome;
    }

    bool isEmpty() const {
        return topo == nullptr;
    }

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
        if (head == nullptr) return "";
        No* temp = head;
        string nomeRemovido = temp->nome;
        head = head->prox;
        delete temp;
        return nomeRemovido;
    }

    void percorrer(const string& prefixo = "") const {
        if (!prefixo.empty()) cout << prefixo << ": ";
        if (head == nullptr) {
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

    bool temMedico() const {
        return head != nullptr;
    }

    ~ListaMedicos() {
        while (head != nullptr) {
            No* t = head;
            head = head->prox;
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
        cout << " - " << at << "\n";
        aux.push(at);
    }

    while (!aux.isEmpty()) {
        hist.push(aux.pop());
    }
}

int main() {
    FilaPacientes fila;
    PilhaHistorico historico;
    ListaMedicos medicos;

    int opcao = -1;

    while (opcao != 0) {
        cout << "\n--- SISTEMA DE ATENDIMENTO ---\n";
        cout << "1. Cadastrar Medico\n";
        cout << "2. Cadastrar Paciente\n";
        cout << "3. Atender Paciente\n";
        cout << "4. Ver Proximo Paciente\n";
        cout << "5. Ver Ultimo Atendimento\n";
        cout << "6. Imprimir Relatorio\n";
        cout << "7. Listar Medicos\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            string nome;
            cout << "Nome do medico: ";
            cin.ignore();
            getline(cin, nome);
            medicos.adicionarMedico(nome);
            cout << "Medico cadastrado com sucesso!\n";
        }
        else if (opcao == 2) {
            string nome;
            int urgencia;
            cout << "Nome do paciente: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Urgencia (1-Baixa, 2-Media, 3-Alta): ";
            cin >> urgencia;

            if (urgencia < 1 || urgencia > 3) {
                cout << "Erro: Urgencia deve ser 1, 2 ou 3.\n";
            } else {
                fila.enqueue(nome, urgencia);
                cout << "Paciente adicionado a fila!\n";
            }
        }
        else if (opcao == 3) {
            if (fila.isEmpty()) {
                cout << "Erro: Nao ha pacientes na fila!\n";
            } else if (!medicos.temMedico()) {
                cout << "Erro: Nao ha medicos disponiveis!\n";
            } else {
                string paciente = fila.dequeue();
                string medico = medicos.chamarMedico();

                cout << "Atendimento: " << medico << " atendeu " << paciente << "\n";
                historico.push(medico + " -> " + paciente);
                medicos.adicionarMedico(medico);
            }
        }
        else if (opcao == 4) {
            if (fila.isEmpty()) {
                cout << "Fila vazia!\n";
            } else {
                cout << "Proximo paciente: " << fila.frente_peek() << "\n";
            }
        }
        else if (opcao == 5) {
            if (historico.isEmpty()) {
                cout << "Nenhum atendimento no historico!\n";
            } else {
                cout << "Ultimo atendimento: " << historico.peek() << "\n";
            }
        }
        else if (opcao == 6) {
            imprimirHistorico(historico);
        }
        else if (opcao == 7) {
            medicos.percorrer("Medicos disponiveis");
        }
        else if (opcao == 0) {
            cout << "Saindo do programa...\n";
        }
        else {
            cout << "Opcao invalida! Tente novamente.\n";
        }

        if (opcao != 0) {
            cout << "\n";
            system("pause");
            system("cls");
        }
    }

    return 0;
}
