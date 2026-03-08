#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_REGISTROS 1000
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_TELEFONE 20

// Estrutura de dados para registro
typedef struct {
    int id;
    char nome[MAX_NOME];
    char email[MAX_EMAIL];
    char telefone[MAX_TELEFONE];
    int idade;
    time_t data_cadastro;
    char ativo; // 'S' ou 'N'
} Registro;

// Estrutura do banco de dados
typedef struct {
    Registro registros[MAX_REGISTROS];
    int total_registros;
    int proximo_id;
} BancoDados;

// Funções CRUD
BancoDados* criar_banco();
void liberar_banco(BancoDados* bd);
int inserir_registro(BancoDados* bd, Registro reg);
Registro* buscar_registro(BancoDados* bd, int id);
int atualizar_registro(BancoDados* bd, int id, Registro novo);
int deletar_registro(BancoDados* bd, int id);
void listar_registros(BancoDados* bd);
int salvar_arquivo(BancoDados* bd, const char* filename);
int carregar_arquivo(BancoDados* bd, const char* filename);

// Funções utilitárias
void limpar_tela();
void pausar();
void imprimir_registro(Registro reg);
int gerar_menu();

#endif
