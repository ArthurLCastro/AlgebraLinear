# **Projeto Determinates (1 ponto)**

## **1. Objetivo:**
Determinar o determinante de uma matriz quadrada. A dimensão da matriz é arbitrária.

## **2. Funcionamento:**
Executando-se [main.exe](main.exe) uma apresentação é mostrada com o título e outras informações do Projeto.<br>
O programa solicita ao usuário a ordem da matriz quadrada e em seguida os valores de cada elemento.<br>
A matriz é apresentada na tela junto ao **determinante** calculado!

## **3. Compilação:**
Para compilar o programa [main.cpp](main.cpp) é necessário que se tenha um compilador instalado como:
- **Windows:** [MinGW](https://sourceforge.net/projects/mingw-w64/)
- **Linux:** gcc / g++

Como o programa não é composto apenas de um arquivo _main.cpp_, mas utiliza também a biblioteca [Matrizes](../../Matrizes/Matrizes.cpp), pode-se usar o arquivo [Makefile](Makefile) para gerar o [main.exe](main.exe) via linha de comandos.

### **3.1. Windows**:

- O primeiro passo é abrir o local do arquivo _Makefile_ no CMD:

        cmd> cd C:\...\AlgebraLinear\Desafios\projDet

- Com o comando **dir** podemos listar os arquivos da pasta. O resultado deve ser algo como:

        cmd> dir
        ...
        20/09/2019  15:48    <DIR>          .
        20/09/2019  15:48    <DIR>          ..
        20/09/2019  15:47             3.518 main.cpp
        20/09/2019  15:47               993 Makefile
        20/09/2019  17:16               870 README.md
        ...

- Devemos executar o comando **make all** e aguardar o fim da compilação:

        cmd> make all

- Agora podemos verificar se o arquivo **main.exe** foi gerado:

        cmd> dir
        ...
        20/09/2019  23:03    <DIR>          .
        20/09/2019  23:03    <DIR>          ..
        20/09/2019  15:47             3.518 main.cpp
        20/09/2019  23:03            96.713 main.exe
        20/09/2019  23:03            26.312 main.o
        20/09/2019  23:03               993 Makefile
        20/09/2019  23:03            31.740 Matrizes.o
        20/09/2019  23:00             1.568 README.md
        ...

- E executá-lo:

        cmd> .\main.exe

<!-- ### **3.2. Linux**:

- O primeiro passo é abrir o local do arquivo _Makefile_ no terminal:

        $ cd /home/.../AlgebraLinear/Desafios/projDet

- Com o comando "**ls**" podemos listar os arquivos da pasta. O resultado deve ser algo como:

        $ ls

- Devemos executar o comando **make all** e aguardar o fim da compilação:

        $ make all

- Agora podemos verificar se o arquivo **main.exe** foi gerado:

        $ ls

- E executá-lo:

        $ ./main -->

## **4. Restrições de uso e Melhorias futuras:**
Alguns testes foram efetuados e o programa parece atender às expectativas calculando o **Determinante de uma Matriz** corretamente. Os códigos foram criados no intuito de generalizar o cálculo de determinantes, baseando-se no **Teorema de Laplace**, tendo em vista funcionar para matrizes de qualquer ordem que seja inserida.<br><br>
Porém, um problema foi percebido para matrizes de ordem maior que "10" (Matriz com 100 elementos).<br><br>
Uma suspeita do que pode estar causando este erro é que a quantidade de dados inseridos à Pilha(Stack) esteja ultrapassando o limite máximo permitido pela máquina e isto esteja acarretando o fechamento do programa. Pois durante o cálculo dos cofatores há uma grande taxa de recursividade ao reduzir a ordem da matriz inserida pelo usuário e calcular cada determinante das "matrizes menores" até que estas possuam ordem "1".<br>