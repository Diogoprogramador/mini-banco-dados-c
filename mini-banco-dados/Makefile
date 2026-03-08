# Makefile para Mini Banco de Dados em C
# Autor: Diogo

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRC_DIR = src
BUILD_DIR = build
TARGET = mini-banco

# Arquivos fonte
SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/database.c
OBJECTS = $(BUILD_DIR)/main.o $(BUILD_DIR)/database.o

# Regra principal
all: $(TARGET)

# Criar diretório build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compilar o programa
$(TARGET): $(BUILD_DIR) $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "=== COMPILADO COM SUCESSO ==="
	@echo "Execute: ./$(TARGET)"

# Compilar arquivos objeto
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/database.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/database.o: $(SRC_DIR)/database.c $(SRC_DIR)/database.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/database.c -o $(BUILD_DIR)/database.o

# Executar o programa
run: $(TARGET)
	./$(TARGET)

# Limpar arquivos compilados
clean:
	rm -rf $(BUILD_DIR) $(TARGET)
	@echo "=== LIMPEZA CONCLUIDA ==="

# Debug
debug: CFLAGS += -DDEBUG
debug: $(TARGET)

# Instalar (opcional)
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
	@echo "=== INSTALADO COM SUCESSO ==="

# Ajuda
help:
	@echo "Comandos disponíveis:"
	@echo "  make        - Compilar o programa"
	@echo "  make run    - Compilar e executar"
	@echo "  make clean  - Limpar arquivos compilados"
	@echo "  make debug  - Compilar com debug"
	@echo "  make install- Instalar no sistema"
	@echo "  make help   - Mostrar esta ajuda"

.PHONY: all run clean debug install help
