# Gerenciador de Músicas - SidemaFy

### Autores

- ANGELO RAPHAEL CAMPELO
- FRANCISCO WILLEM ROMÃO MOREIRA 

## Compilação

Este roteiro tem como objetivo descrever os passos para compilar e executar o sistema que utiliza o CMake como ferramenta de compilação. 

## Pré-requisitos

- CMake instalado na máquina
- Compilador C++ (ex: gcc, clang) instalado na máquina

## Passo 1: Clonar o repositório

Clone o repositório do programa em sua máquina local usando o comando:

```
git clone https://github.com/angelo-rbs/lp-sidemafy.git
```
## Passo 2: Criar o diretório de compilação

Crie um diretório de compilação na raiz do repositório usando o comando:

```
mkdir build
cd build
```

## Passo 3: Configurar o CMake

Dentro do diretório de compilação, configure o CMake com o comando:

```
cmake ..
```

Este comando irá criar os arquivos de configuração necessários para a compilação.

## Passo 4: Compilar o programa

Compile o programa usando o comando:

```
make
```

Este comando irá gerar o executável do programa, que será chamado `program`.

## Passo 5: Executar o programa

Execute o programa com o comando:

```
./program
```

Este comando irá executar o programa e exibir a saída na tela.


O programa possui dois métodos de menu: `showMenu()` e `showSubMenu()`. Vamos explicar as saídas de cada um deles:

- `showMenu()`: 
  - "Selecione uma opcao:" - Mensagem que solicita ao usuário que selecione uma das opções do menu.
  - "1. Gerenciar musicas" - Opção do menu que permite o gerenciamento de músicas.
  - "2. Gerenciar playlists" - Opção do menu que permite o gerenciamento de playlists.
  - "3. Sair" - Opção do menu que permite sair do programa.
  - "Opcao: " - Mensagem que solicita ao usuário que digite o número correspondente à opção desejada.

- `showSubMenu()`: 
  - "Selecione uma opcao:" - Mensagem que solicita ao usuário que selecione uma das opções do submenu.
  - "1. Adicionar" - Opção do submenu que permite adicionar uma música a uma playlist.
  - "2. Remover" - Opção do submenu que permite remover uma música de uma playlist.
  - "3. Listar" - Opção do submenu que permite listar as músicas de uma playlist.
  - "4. Voltar" - Opção do submenu que permite voltar ao menu principal.
  - "Opcao: " - Mensagem que solicita ao usuário que digite o número correspondente à opção desejada.

## Conclusão

Seguindo esses passos, você será capaz de compilar e executar o programa que utiliza o CMake como ferramenta de compilação. Caso ocorram erros durante a compilação, verifique se os pré-requisitos foram atendidos e se o código fonte está livre de erros de sintaxe.

## Limitações

Gostaria de compartilhar as limitações que encontramos durante o projeto. Desde o início, tivemos dificuldades para implementar a lista encadeada sem usar a biblioteca STL, o que aumentou a complexidade do código e tornou a implementação mais trabalhosa. Além disso, o código ainda não está completo e precisa de mais modificações para conseguir rodar. 

Outro desafio que encontramos foi adicionar novos métodos dentro da lista para usar nos gerenciadores de playlist e de música. Por agora, ainda falta implementar métodos novos na lista encadeada. Esses métodos precisam ser cuidadosamente pensados para garantir que tudo funcione corretamente.

Lamentamos que não conseguimos entregar o projeto completo e rodando como esperado. Esperamos ter aprendido com essas dificuldades. Obrigado pela compreensão.

