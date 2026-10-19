#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct No {
    string nome;
    int    urgencia;
    No*    prox;
    No(const string& n, int u = 0) : nome(n), urgencia(u), prox(nullptr) {}
};

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

int main() {
    FilaPacientes  fila;
    PilhaHistorico historico;
    ListaMedicos   medicos;

    int opcao = -1;

    while (opcao != 0) {
        cout << "\n=====================================================\n";
        cout << "  SISTEMA DE ATENDIMENTO HOSPITALAR   \n";
        cout << "=====================================================\n";
        cout << "  [1] Cadastrar Medico\n";
        cout << "  [2] Cadastrar Paciente na Fila\n";
        cout << "  [3] Realizar Atendimento\n";
        cout << "  [4] Ver Proximo Paciente na Fila\n";
        cout << "  [5] Ver Ultimo Atendimento Registrado\n";
        cout << "  [6] Imprimir Relatorio de Atendimentos\n";
        cout << "  [7] Listar Medicos Disponiveis\n";
        cout << "  [0] Sair do Sistema\n";
        cout << "=====================================================\n";
        cout << "Escolha uma opcao: ";

        if (!(cin >> opcao)) {
            cout << "\nDigite um numero de 0 a 7.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            opcao = -1;
            system("pause");
            system("cls");
            continue;
        }

        if (opcao == 1) {
            string nome;
            cout << "\nDigite o nome do medico: ";
            cin.ignore();
            getline(cin, nome);
            if (nome.empty()) {
                cout << "o medico precisa ter nome.\n";
            } else {
                medicos.adicionarMedico(nome);
                cout << " Medico '" << nome << "' cadastrado com sucesso.\n";
            }
            system("pause");
            system("cls");
        } 
        else if (opcao == 2) {
            string nome;
            int urgencia;
            cout << "\nDigite o nome do paciente: ";
            cin.ignore();
            getline(cin, nome);
            
            if (nome.empty()) {
                cout << "nome invalido.\n";
            } else {
                cout << "Digite o nivel de urgencia (1=Baixa, 2=Media, 3=Alta): ";
                if (!(cin >> urgencia) || (urgencia < 1 || urgencia > 3)) {
                    cout << "Digite apenas 1, 2 ou 3.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                } else {
                    fila.enqueue(nome + " (urgencia=" + to_string(urgencia) + ")", urgencia);
                    cout << "Paciente " << nome << "' inserido na fila!\n";
                }
            }
            system("pause");
            system("cls");
        } 
        else if (opcao == 3) {
            if (fila.isEmpty()) {
                cout << "\nNao ha pacientes na fila para atender!\n";
            } else if (!medicos.temMedico()) {
                cout << "\nNao ha medicos disponiveis no momento!\n";
            } else {
                string paciente = fila.dequeue();
                string medico   = medicos.chamarMedico();

                cout << "\nATENDIMENTO REALIZADO " << medico << " atende " << paciente << "\n";

                historico.push(medico + " -> " + paciente);

                medicos.adicionarMedico(medico);
            }
            system("pause");
            system("cls");
        } 
        else if (opcao == 4) {
            if (fila.isEmpty()) {
                cout << "\nNao ha pacientes na fila!\n";
            } else {
                cout << "\nProximo paciente: " << fila.frente_peek() << "\n";
                cout << "Total na fila: " << fila.tamanho() << " paciente(s)\n";
            }
            system("pause");
            system("cls");
        } 
        else if (opcao == 5) {
            if (historico.isEmpty()) {
                cout << "\nNenhum atendimento foi registrado no historico ainda!\n";
            } else {
                cout << "\nULTIMO ATENDIMENTO" << historico.peek() << "\n";
            }
            system("pause");
            system("cls");
        } 
        else if (opcao == 6) {
            imprimirHistorico(historico);
            system("pause");
            system("cls");
        } 
        else if (opcao == 7) {
            cout << "\n";
            medicos.percorrer("Medicos disponiveis");
            system("pause");
            system("cls");
        } 
        else if (opcao == 0) {
            cout << "\nEncerrando o sistema... Ate logo!\n";
        } 
        else {
            cout << "\nOpcao invalida! Digite um numero de 0 a 7.\n";
            system("pause");
            system("cls");
        }
    }

    return 0;
}
