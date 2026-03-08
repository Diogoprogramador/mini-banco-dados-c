# 🗄️ Mini Banco de Dados em C

## 👤 Autor
**Diogo** - Desenvolvedor C

## 📅 Data
Criado: 2026-03-08

## 🎯 Sobre o Projeto

Mini banco de dados completo implementado em C puro, com funcionalidades CRUD, persistência em arquivo e interface interativa. Projeto ideal para demonstrar conhecimentos em programação estruturada, manipulação de arquivos e gerenciamento de memória.

### ✅ Características Principais

- ✅ **CRUD Completo**: Create, Read, Update, Delete
- ✅ **Persistência de Dados**: Salvar/Carregar em arquivo binário
- ✅ **Interface Interativa**: Menu console intuitivo
- ✅ **Gerenciamento de Memória**: Alocação dinâmica segura
- ✅ **Validação de Dados**: IDs únicos e controle de status
- ✅ **Soft Delete**: Registros marcados como inativos
- ✅ **Compilação Automatizada**: Makefile profissional

## 📁 Estrutura do Projeto

```
mini-banco-dados/
├── src/
│   ├── main.c           # Programa principal e menu
│   ├── database.c       # Implementação das funções CRUD
│   └── database.h       # Headers e estruturas de dados
├── Makefile             # Compilação automatizada
├── README.md            # Documentação
├── build/               # Arquivos compilados
├── mini-banco           # Executável
└── database.dat         # Arquivo de dados (criado automaticamente)
```

## 🛠️ Tecnologias Utilizadas

- **C** - Linguagem principal
- **GCC** - Compilador
- **Make** - Build automation
- **STDIO/STDLIB** - Bibliotecas padrão

## 🚀 Como Compilar e Executar

### Pré-requisitos
```bash
# Verificar se GCC está instalado
gcc --version

# Instalar GCC se necessário (Ubuntu/Debian)
sudo apt update && sudo apt install gcc make
```

### Compilação
```bash
# Compilar o projeto
make

# Ou compilar e executar direto
make run

# Limpar arquivos compilados
make clean

# Ver ajuda de comandos
make help
```

### Execução
```bash
# Após compilação
./mini-banco
```

## 📊 Funcionalidades Detalhadas

### 1. 📝 Inserir Registro
- Nome completo
- Email válido
- Telefone
- Idade
- ID gerado automaticamente
- Data de cadastro automática

### 2. 🔍 Buscar Registro
- Busca por ID único
- Exibição formatada dos dados
- Verificação de status ativo

### 3. 📋 Listar Registros
- Tabela formatada com todos os registros ativos
- Informações: ID, Nome, Email, Telefone, Idade, Data Cadastro
- Contador total de registros

### 4. ✏️ Atualizar Registro
- Busca por ID
- Atualização de todos os campos exceto ID
- Mantém data de cadastro original

### 5. 🗑️ Deletar Registro
- Soft delete (marca como inativo)
- Preserva histórico de dados
- Registro não aparece mais nas listagens

### 6. 💾 Persistência de Dados
- Salvar em arquivo binário `database.dat`
- Carregar dados do arquivo
- Preserva estrutura completa

## 🏗️ Estrutura de Dados

### Registro
```c
typedef struct {
    int id;                    // ID único automático
    char nome[MAX_NOME];       // Nome completo
    char email[MAX_EMAIL];     // Endereço de email
    char telefone[MAX_TELEFONE]; // Telefone
    int idade;                 // Idade
    time_t data_cadastro;      // Timestamp de criação
    char ativo;                // 'S' ou 'N'
} Registro;
```

### Banco de Dados
```c
typedef struct {
    Registro registros[MAX_REGISTROS];  // Array de registros
    int total_registros;                 // Total de registros
    int proximo_id;                      // Próximo ID a gerar
} BancoDados;
```

## 📋 Limitações e Especificações

- **Capacidade**: Até 1000 registros
- **Tamanho campos**: Nome(50), Email(50), Telefone(20)
- **Arquivo dados**: Binário para performance
- **Plataforma**: Linux/Windows/Mac (com GCC)

## 🐛 Solução de Problemas

### Erros Comuns
1. **Erro de compilação**: Verifique se GCC está instalado
2. **Permissão negada**: Use `chmod +x mini-banco`
3. **Arquivo não encontrado**: Verifique caminho do database.dat
4. **Segmentation fault**: Verifique entrada de dados válidos

### Dicas de Uso
- **Backup**: Copie `database.dat` regularmente
- **Performance**: Para muitos dados, considere árvore B
- **Extensão**: Adicione índices para busca mais rápida

## 🔧 Personalização

### Adicionar Novos Campos
```c
// Em database.h - struct Registro
char novo_campo[TAMANHO];

// Em ler_registro() - main.c
printf("Novo Campo: ");
scanf(" %[^\n]", reg.novo_campo);
```

### Mudar Capacidade
```c
// Em database.h
#define MAX_REGISTROS 2000  // Mudar para novo valor
```

## 📈 Métricas do Projeto

- **Linhas de código**: ~400
- **Arquivos fonte**: 3 (.c/.h)
- **Funções**: 15 principais
- **Estruturas**: 2 structs
- **Tempo compilação**: <1s
- **Memória utilizada**: ~1MB

## 🎓 Conceitos Demonstrados

- **Programação Estruturada** em C
- **Alocação Dinâmica** de memória
- **Manipulação de Arquivos** binários
- **Estruturas de Dados** customizadas
- **Gerenciamento de Estado** da aplicação
- **Interface Console** profissional
- **Build Automation** com Makefile

## 🤝 Contribuições

### Como Contribuir
1. Fork do projeto
2. Criar branch para nova funcionalidade
3. Commit das mudanças
4. Push para o branch
5. Abrir Pull Request

### Sugestões de Melhorias
- [ ] Implementar busca por nome/email
- [ ] Adicionar ordenação de registros
- [ ] Criar sistema de logs
- [ ] Implementar validação de email
- [ ] Adicionar criptografia de dados
- [ ] Criar interface gráfica (GTK/Qt)

## 📝 Licença

Este projeto está sob licença MIT. Sinta-se livre para usar, modificar e distribuir.

## 📞 Contato

- **Autor**: Diogo
- **Data**: 2026-03-08
- **Projeto**: Mini Banco de Dados em C

---

## 🎉 Resultados

### Arquivos Gerados
✅ `src/main.c` - Programa principal e interface  
✅ `src/database.c` - Lógica de persistência e CRUD  
✅ `src/database.h` - Estruturas e headers  
✅ `Makefile` - Compilação automatizada  
✅ `README.md` - Documentação completa  

### Funcionalidades Implementadas
🗄️ **CRUD completo** com validação  
💾 **Persistência binária** eficiente  
🎯 **Interface console** intuitiva  
🔧 **Build system** profissional  
📚 **Documentação** detalhada  

---

**Desenvolvido com 💻 por Diogo**  
*Programação C Profissional e Estruturada*
