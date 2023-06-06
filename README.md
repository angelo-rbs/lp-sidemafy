# Gerenciador de Músicas - SidemaFy

Alunos:
Ângelo Raphael Campelo de Araújo Barbosa
Tobias dos Santos Neto

# Como compilar:

Na pasta base execute o seguinte comando para criar a pasta de build:

cmake -S . -B build

Após isto, navegue ao diretório de build e execute o comando

make

para criar o arquivo executável Sidemafy. Este por sua vez pode ser executado segundo ./Sidemafy, para um início limpo,
isto é, sem músicas e playlists prévias, ou por passagem de parâmetro que seja um arquivo de texto no formato orientado.
Se o arquivo de texto se chamar "data.txt", por exemplo, para inicializar o Sidemafy com seus dados deve-se executar

./Sidemafy data.txt

# Funcionalidades

A aplicação dispõe das funcionalidades evidentes destacadas nos menus de música e playlist e seu fácil manuseio, intruído por
orientações constante via console dispensam maiores explicações sobre.

# Limitações

A aplicação em sua versão atual consegue carregar as playlists e músicas de um arquivo fonte, mas ainda não consegue 
escrever nele atualizando os dados apropriadamente ao fim de sua execução. 
