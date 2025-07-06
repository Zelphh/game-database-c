
PROJETO: games_database

AUTOR: Matheus Melle Tártari

DISCIPLINA: Linguagem de Programação [LPG002]

PROFESSORA: Marisangila Alves

---

### SOBRE O PROJETO

Este projeto é um sistema de gerenciamento para uma biblioteca pessoal de jogos, desenvolvido em linguagem C. O programa é executado via terminal e permite ao usuário realizar as quatro operações básicas de um banco de dados (CRUD):

1.  **Criar (Create)**: Adicionar novos jogos à lista.
2.  **Ler (Read)**: Buscar um jogo específico ou listar todos os jogos cadastrados.
3.  **Atualizar (Update)**: Editar as informações de um jogo existente.
4.  **Deletar (Delete)**: Remover um jogo da lista.

Os dados são armazenados de forma persistente em um arquivo de texto formatado como CSV, chamado `jogos.csv`. Este arquivo é lido quando o programa inicia e é completamente reescrito com os dados atualizados quando o programa é encerrado, garantindo a integridade das informações.

-----------------------------------------------------

### ESTRUTURA DA PASTA RAIZ

A pasta raiz do projeto deve conter os seguintes arquivos para que a compilação e execução ocorram corretamente:

├── main.c              # Arquivo principal, contém a função main() e o menu de navegação.

├── jogo.h              # Arquivo de cabeçalho com a definição da struct 'Jogo' e os protótipos das funções.

├── jogo.c              # Implementação das funções de manipulação dos jogos (adicionar, buscar, etc.).

├── system.h            # Cabeçalho para funções auxiliares do sistema.

├── system.c            # Implementação das funções auxiliares (limpar console, limpar buffer).

└── jogos.csv           # (Opcional) Arquivo de banco de dados. Será criado automaticamente na primeira execução se não existir.

-----------------------------------------------------

### COMO COMPILAR E EXECUTAR

Para compilar e executar o projeto, é necessário ter um compilador C instalado no sistema, como o GCC, que é padrão em sistemas Linux e pode ser facilmente instalado no Windows (via MinGW ou WSL) e no macOS (via Xcode Command Line Tools).

**Passo 1: Abrir o Terminal**
Abra um terminal (ou Prompt de Comando/PowerShell no Windows) e navegue até a pasta raiz do projeto.

**Passo 2: Compilar o Código**
Execute o seguinte comando para compilar todos os arquivos de código-fonte (`.c`) e gerar um único arquivo executável:

gcc main.c jogo.c system.c -o games_database

Detalhes do comando:
- `gcc`: Invoca o compilador.
- `main.c jogo.c system.c`: São os arquivos de código-fonte que serão compilados.
- `-o games_database`: Define o nome do arquivo executável de saída como "games_database".
