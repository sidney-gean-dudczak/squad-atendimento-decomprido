# squad-atendimento-decomprido
## integrantes: Sidney Gean, Juan Bet, Natanael Padilha, Rafael Marcelino

# Sistema de Atendimento Hospitalar em C++

Desafio Squad - PSC II - Engenharia de Software - Campo Real
Professor: Giovane Galvao

## Sobre o Projeto
Este projeto consiste em um Sistema de Atendimento Hospitalar desenvolvido em C++ sem a utilizacao da biblioteca padrao de estruturas de dados (sem STL como vector, queue, stack ou list).

O sistema realiza a triagem de pacientes, o gerenciamento de medicos plantonistas e o registro do historico de atendimentos utilizando alocacao dinamica de memoria (new / delete) e ponteiros manipulados manualmente.

## Estruturas de Dados Implementadas
- R1: FilaPacientes (FIFO) - Gerencia a fila de espera dos pacientes (enqueue, dequeue, frente_peek, tamanho).
- R2: PilhaHistorico (LIFO) - Registra o historico dos atendimentos realizados (push, pop, peek).
- R3: ListaMedicos (Lista Encadeada) - Gerencia os medicos disponiveis (adicionarMedico, chamarMedico, percorrer).
- R4: imprimirHistorico (Relatorio) - Imprime o historico completo do topo a base sem destruir os dados usando pilha auxiliar.

## Recursos do Menu Interativo
- Loop continuo com while e controle por if / else if.
- Tratamento de entradas invalidas (cin.fail()).
- Mensagens de erro claras para fila vazia, sem medicos ou opcoes fora da faixa.

## Como Compilar e Executar
g++ -std=c++17 -Wall -o atendimento atendimento-v3.cpp
./atendimento

## Checklist de Entrega
- [x] R1: Fila de Pacientes (FIFO)
- [x] R2: Historico com Pilha (LIFO)
- [x] R3: Lista de Medicos (Lista Encadeada)
- [x] R4: Relatorio de Historico Completo
- [x] Sem STL (vector, queue, stack)
- [x] Gerenciamento manual de memoria (new / delete)
- [x] Menu interativo com tratamento de erros
