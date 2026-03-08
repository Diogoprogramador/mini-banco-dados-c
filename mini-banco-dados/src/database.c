#include "database.h"

// Criar novo banco de dados
BancoDados* criar_banco() {
    BancoDados* bd = (BancoDados*)malloc(sizeof(BancoDados));
    if (bd) {
        bd->total_registros = 0;
        bd->proximo_id = 1;
    }
    return bd;
}

// Liberar memória do banco
void liberar_banco(BancoDados* bd) {
    if (bd) {
        free(bd);
    }
}

// Inserir novo registro
int inserir_registro(BancoDados* bd, Registro reg) {
    if (!bd || bd->total_registros >= MAX_REGISTROS) {
        return 0; // Falha
    }
    
    reg.id = bd->proximo_id++;
    reg.data_cadastro = time(NULL);
    reg.ativo = 'S';
    
    bd->registros[bd->total_registros] = reg;
    bd->total_registros++;
    
    return reg.id; // Sucesso, retorna ID
}

// Buscar registro por ID
Registro* buscar_registro(BancoDados* bd, int id) {
    if (!bd) return NULL;
    
    for (int i = 0; i < bd->total_registros; i++) {
        if (bd->registros[i].id == id && bd->registros[i].ativo == 'S') {
            return &bd->registros[i];
        }
    }
    return NULL;
}

// Atualizar registro
int atualizar_registro(BancoDados* bd, int id, Registro novo) {
    Registro* reg = buscar_registro(bd, id);
    if (!reg) return 0;
    
    // Mantém ID, data_cadastro e status ativo
    strcpy(reg->nome, novo.nome);
    strcpy(reg->email, novo.email);
    strcpy(reg->telefone, novo.telefone);
    reg->idade = novo.idade;
    
    return 1; // Sucesso
}

// Deletar registro (soft delete)
int deletar_registro(BancoDados* bd, int id) {
    Registro* reg = buscar_registro(bd, id);
    if (!reg) return 0;
    
    reg->ativo = 'N'; // Marca como inativo
    return 1; // Sucesso
}

// Listar todos os registros ativos
void listar_registros(BancoDados* bd) {
    if (!bd || bd->total_registros == 0) {
        printf("Nenhum registro encontrado.\n");
        return;
    }
    
    printf("\n=== LISTA DE REGISTROS ===\n");
    printf("%-5s %-20s %-25s %-15s %-5s %-12s\n", 
           "ID", "NOME", "EMAIL", "TELEFONE", "IDADE", "CADASTRO");
    printf("------------------------------------------------------------\n");
    
    for (int i = 0; i < bd->total_registros; i++) {
        if (bd->registros[i].ativo == 'S') {
            Registro reg = bd->registros[i];
            char data_str[12];
            strftime(data_str, sizeof(data_str), "%d/%m/%Y", localtime(&reg.data_cadastro));
            
            printf("%-5d %-20s %-25s %-15s %-5d %-12s\n",
                   reg.id, reg.nome, reg.email, reg.telefone, reg.idade, data_str);
        }
    }
    printf("\nTotal: %d registros ativos\n", bd->total_registros);
}

// Salvar banco em arquivo
int salvar_arquivo(BancoDados* bd, const char* filename) {
    if (!bd) return 0;
    
    FILE* file = fopen(filename, "wb");
    if (!file) return 0;
    
    // Salva cabeçalho
    fwrite(&bd->total_registros, sizeof(int), 1, file);
    fwrite(&bd->proximo_id, sizeof(int), 1, file);
    
    // Salva registros
    fwrite(bd->registros, sizeof(Registro), bd->total_registros, file);
    
    fclose(file);
    return 1;
}

// Carregar banco do arquivo
int carregar_arquivo(BancoDados* bd, const char* filename) {
    if (!bd) return 0;
    
    FILE* file = fopen(filename, "rb");
    if (!file) return 0;
    
    // Carrega cabeçalho
    fread(&bd->total_registros, sizeof(int), 1, file);
    fread(&bd->proximo_id, sizeof(int), 1, file);
    
    // Carrega registros
    fread(bd->registros, sizeof(Registro), bd->total_registros, file);
    
    fclose(file);
    return 1;
}

// Funções utilitárias
void limpar_tela() {
    system("clear || cls");
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
    getchar();
}

void imprimir_registro(Registro reg) {
    char data_str[12];
    strftime(data_str, sizeof(data_str), "%d/%m/%Y", localtime(&reg.data_cadastro));
    
    printf("\n--- DADOS DO REGISTRO ---\n");
    printf("ID: %d\n", reg.id);
    printf("Nome: %s\n", reg.nome);
    printf("Email: %s\n", reg.email);
    printf("Telefone: %s\n", reg.telefone);
    printf("Idade: %d\n", reg.idade);
    printf("Data Cadastro: %s\n", data_str);
    printf("Status: %s\n", reg.ativo == 'S' ? "Ativo" : "Inativo");
    printf("-------------------------\n");
}
