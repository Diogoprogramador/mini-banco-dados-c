#include "database.h"

// Função para menu
int gerar_menu() {
    int opcao;
    
    limpar_tela();
    printf("=====================================\n");
    printf("    MINI BANCO DE DADOS EM C\n");
    printf("=====================================\n");
    printf("1. Inserir novo registro\n");
    printf("2. Buscar registro por ID\n");
    printf("3. Listar todos os registros\n");
    printf("4. Atualizar registro\n");
    printf("5. Deletar registro\n");
    printf("6. Salvar dados em arquivo\n");
    printf("7. Carregar dados do arquivo\n");
    printf("0. Sair\n");
    printf("=====================================\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    
    return opcao;
}

// Função para ler dados do usuário
Registro ler_registro() {
    Registro reg;
    
    printf("\n--- NOVO REGISTRO ---\n");
    printf("Nome: ");
    scanf(" %[^\n]", reg.nome);
    
    printf("Email: ");
    scanf(" %[^\n]", reg.email);
    
    printf("Telefone: ");
    scanf(" %[^\n]", reg.telefone);
    
    printf("Idade: ");
    scanf("%d", &reg.idade);
    
    return reg;
}

int main() {
    BancoDados* bd = criar_banco();
    int opcao, id;
    Registro reg;
    const char* arquivo = "database.dat";
    
    if (!bd) {
        printf("Erro ao criar banco de dados!\n");
        return 1;
    }
    
    do {
        opcao = gerar_menu();
        
        switch (opcao) {
            case 1: // Inserir
                reg = ler_registro();
                id = inserir_registro(bd, reg);
                if (id > 0) {
                    printf("\nRegistro inserido com sucesso! ID: %d\n", id);
                } else {
                    printf("\nErro ao inserir registro!\n");
                }
                pausar();
                break;
                
            case 2: // Buscar
                printf("\nDigite o ID para buscar: ");
                scanf("%d", &id);
                
                Registro* encontrado = buscar_registro(bd, id);
                if (encontrado) {
                    imprimir_registro(*encontrado);
                } else {
                    printf("\nRegistro nao encontrado!\n");
                }
                pausar();
                break;
                
            case 3: // Listar
                listar_registros(bd);
                pausar();
                break;
                
            case 4: // Atualizar
                printf("\nDigite o ID para atualizar: ");
                scanf("%d", &id);
                
                if (buscar_registro(bd, id)) {
                    printf("\n--- ATUALIZAR REGISTRO ---\n");
                    reg = ler_registro();
                    
                    if (atualizar_registro(bd, id, reg)) {
                        printf("\nRegistro atualizado com sucesso!\n");
                    } else {
                        printf("\nErro ao atualizar registro!\n");
                    }
                } else {
                    printf("\nRegistro nao encontrado!\n");
                }
                pausar();
                break;
                
            case 5: // Deletar
                printf("\nDigite o ID para deletar: ");
                scanf("%d", &id);
                
                if (buscar_registro(bd, id)) {
                    if (deletar_registro(bd, id)) {
                        printf("\nRegistro deletado com sucesso!\n");
                    } else {
                        printf("\nErro ao deletar registro!\n");
                    }
                } else {
                    printf("\nRegistro nao encontrado!\n");
                }
                pausar();
                break;
                
            case 6: // Salvar
                if (salvar_arquivo(bd, arquivo)) {
                    printf("\nDados salvos com sucesso em '%s'!\n", arquivo);
                } else {
                    printf("\nErro ao salvar dados!\n");
                }
                pausar();
                break;
                
            case 7: // Carregar
                if (carregar_arquivo(bd, arquivo)) {
                    printf("\nDados carregados com sucesso de '%s'!\n", arquivo);
                } else {
                    printf("\nErro ao carregar dados ou arquivo nao encontrado!\n");
                }
                pausar();
                break;
                
            case 0: // Sair
                printf("\nSaindo do sistema...\n");
                break;
                
            default:
                printf("\nOpcao invalida!\n");
                pausar();
                break;
        }
        
    } while (opcao != 0);
    
    liberar_banco(bd);
    return 0;
}
