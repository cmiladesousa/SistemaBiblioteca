# SistemaBiblioteca
Trabalho desenvolivdo para a disciplina de Linguagem de Programação I no qual foi desenvolivido um programa que gerencia inventário, empréstimos e usuários de uma biblioteca

## Formas de Executar o programa

### Utilizando o CMake
É possivel executar o programa utilizando a ferramenta CMake e criando um diretório build. confira a documentação clicando [aqui](https://cmake.org/cmake/help/latest/guide/tutorial/index.html). Ao baixar o cmake e configurar o arquivo build usando o comando `cmake`, execute o programa no terminal usando os comandos a seguir:
```
cmake
make
./program arquivoEntrada.txt

```
### Diretamente no terminal
Caso não tenha o CMake instalado no seu computador, é possivel executar o programa diretamente no terminal com o seguinte comando:
```
g++ src/historico.cpp src/usuario.cpp src/node.cpp src/arvore.cpp src/login.cpp src/main.cpp -o program
./program arquivoEntrada.txt

```

  
