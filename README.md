# 🏥 Sistema de Atendimento Hospitalar em C++

> **Desafio Squad** · PSC II · Engenharia de Software · Faculdade Campo Real  
> **Professor:** Giovane Galvão  

---

## 📌 Sobre o Projeto

Este projeto consiste em um **Sistema de Atendimento Hospitalar** desenvolvido em C++ puro, sem a utilização da biblioteca padrão de estruturas de dados (**sem STL** como `std::vector`, `std::queue`, `std::stack` ou `std::list`).

O sistema realiza a triagem de pacientes, o gerenciamento de médicos plantonistas e o registro do histórico de atendimentos utilizando **alocação dinâmica de memória** (`new` / `delete`) e ponteiros manipulados manualmente.

---

## 🏗️ Estruturas de Dados Implementadas

O sistema integra três estruturas de dados lineares encadeadas:

| Requisito | Estrutura | Tipo | Descrição |
| :--- | :--- | :--- | :--- |
| **R1** | `FilaPacientes` | **FIFO** (*First-In, First-Out*) | Gerencia a fila de espera dos pacientes (`enqueue`, `dequeue`, `frente_peek`, `tamanho`). |
| **R2** | `PilhaHistorico` | **LIFO** (*Last-In, First-Out*) | Registra o histórico dos atendimentos realizados (`push`, `pop`, `peek`). |
| **R3** | `ListaMedicos` | **Lista Encadeada** | Gerencia os médicos disponíveis (`adicionarMedico`, `chamarMedico`, `percorrer`). |
| **R4** | `imprimirHistorico` | **Relatório** | Imprime o histórico completo do topo à base sem destruir os dados (utiliza pilha auxiliar). |

---

## 🛠️ Recursos e Validações do Menu

- **Loop Interativo (`while`) e Estruturas `if / else if`**: Navegação contínua até a opção de saída (`0`).
- **Tratamento de Entradas Inválidas**: Previne falhas se o usuário digitar letras ou símbolos onde são esperados números.
- **Mensagens de Erro Claras**: Alertas para tentativa de atendimento sem pacientes na fila ou sem médicos disponíveis, e validações para níveis de urgência.

---

## 🚀 Como Compilar e Executar

### Comando de Compilação
```bash
g++ -std=c++17 -Wall -o atendimento atendimento_simples.cpp
```

### Comando de Execução
```bash
# Windows
.\atendimento.exe

# Linux / macOS
./atendimento
```

---

## 🖥️ Exemplo de Saída no Terminal

```text
=====================================================
  SISTEMA DE ATENDIMENTO HOSPITALAR - SQUAD PSC II  
=====================================================
  [1] Cadastrar Medico (R3)
  [2] Cadastrar Paciente na Fila (R1)
  [3] Realizar Atendimento
  [4] Ver Proximo Paciente na Fila (R1 Peek)
  [5] Ver Ultimo Atendimento Registrado (R2 Peek)
  [6] Imprimir Relatorio de Atendimentos (R4)
  [7] Listar Medicos Disponiveis (R3)
  [0] Sair do Sistema
=====================================================
Escolha uma opcao: 1

Digite o nome do medico: Dra. Ana Lima
[SUCESSO] Medico 'Dra. Ana Lima' cadastrado com sucesso!

Escolha uma opcao: 2

Digite o nome do paciente: Eduardo
Digite o nivel de urgencia (1=Baixa, 2=Media, 3=Alta): 3
[SUCESSO] Paciente 'Eduardo' inserido na fila!!

Escolha uma opcao: 3

[ATENDIMENTO REALIZADO] Dra. Ana Lima atende Eduardo (urgencia=3)

=== Relatorio de Atendimentos ===
  - Dra. Ana Lima -> Eduardo (urgencia=3)
```

---

## 📋 Checklist de Entrega

- [x] **R1**: Fila de Pacientes (`enqueue`, `dequeue`, `frente_peek`, `tamanho`)
- [x] **R2**: Histórico com Pilha (`push`, `pop`, `peek`)
- [x] **R3**: Lista de Médicos (`adicionarMedico`, `chamarMedico`, `percorrer`)
- [x] **R4**: Relatório completo mantendo integridade da pilha
- [x] **Zero STL**: Sem bibliotecas prontas como `<vector>`, `<queue>` ou `<stack>`
- [x] **Gerenciamento de Memória**: Toda alocação com `new` possui `delete` correspondente
- [x] **Menu Interativo**: Navegação com tratamento de erros de entrada
- [x] **Exemplo de Saída**: Demonstração do terminal no README
