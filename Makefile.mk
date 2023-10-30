# Nome do programa de saída
TARGET = meu_programa

# Compilador C++
CXX = g++

# Flags do compilador
CXXFLAGS = -std=c++17 -Wall

# Diretórios dos arquivos de origem
PRIM_DIR = Prim
VIZINHANCA_DIR = Vizinhança

# Diretório onde os objetos compilados serão armazenados
OBJDIR = obj

# Lista de arquivos de origem no diretório 'Prim'
PRIM_SOURCES = $(wildcard $(PRIM_DIR)/*.cpp)

# Lista de arquivos de origem no diretório 'Vizinhança'
VIZINHANCA_SOURCES = $(wildcard $(VIZINHANCA_DIR)/*.cpp)

# Lista de arquivos-objeto para 'Prim' e 'Vizinhança'
PRIM_OBJECTS = $(patsubst $(PRIM_DIR)/%.cpp, $(OBJDIR)/$(PRIM_DIR)/%.o, $(PRIM_SOURCES))
VIZINHANCA_OBJECTS = $(patsubst $(VIZINHANCA_DIR)/%.cpp, $(OBJDIR)/$(VIZINHANCA_DIR)/%.o, $(VIZINHANCA_SOURCES))

# Regra principal para construir o programa
$(TARGET): $(PRIM_OBJECTS) $(VIZINHANCA_OBJECTS)
    $(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar arquivos-objeto em 'Prim'
$(OBJDIR)/$(PRIM_DIR)/%.o: $(PRIM_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -c -o $@ $<

# Regra para compilar arquivos-objeto em 'Vizinhança'
$(OBJDIR)/$(VIZINHANCA_DIR)/%.o: $(VIZINHANCA_DIR)/%.cpp
    $(CXX) $(CXXFLAGS) -c -o $@ $<

# Regra para limpar arquivos intermediários
clean:
    $(RM) $(PRIM_OBJECTS) $(VIZINHANCA_OBJECTS)

.PHONY: clean
