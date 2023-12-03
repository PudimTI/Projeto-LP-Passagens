# Projeto-LP-Passagens
Projeto final de Linguagem de Programação do segundo semestre de ADS

## Grupo
O grupo do projeto é composto por:
- Gabriel Janotto Pereira
- João Pedro Vaz
- Kelvyn Cortez

## Video de Apresentação
Esse é o video de apresentação do funcionamento do projeto

[![Watch the video](https://i.stack.imgur.com/Vp2cE.png)](https://youtu.be/b5qJN1agmvA)

## Descrição
O projeto trata-se do 6 tema proposto pelo professor Marcos Roberto de Morais, Sistema de Controle de Fluxo
de Passageiros de uma Estação de Metrô.

A proposta do projeto visa a criação de um typedef Struct para os Passageiros de um metro, contendo seu ID do cartão, 
o Nome, o horario de entrada, o horario de saída, a estação de entrada e a estação de saída. Para isso foi criada diversas funções
na qual será destacada ao decorrer desse documento.

## Instalação
A portabilidade do projeto foi realizada atraves do Github. Criando um novo repositorio
com nome Projeto-LP-Passagens hospedado no perfil do aluno João Pedro Vaz (PudimTI).

O projeto foi codificado utilizando a IDE Clion da Jetbrains e utilizando o software Github for Desktop para a comunicação 
com o repositorio online e portabilidade para diversos computadores, incluindo notebooks do laboratorio disponibilizado 
pela Faculdade Fatec e os pessoais dos integrantes do grupo.

Toda linha do tempo de comits está disponivel no repositorio do projeto.

## Funcionalidades

### Main
Esta função é a Main do codigo onde nela o usuario ira utilizar um menu disponibilizando o acesso as
outras funçoes encontradas no codigo
#### Uso
Nesta função o usuario sera apresentado com um menu de opçoes que o levara ate as outras funçoes do codigo,
cada função possui um numero que ao digitar ira levar o usuario ate a função desejada, caso insira uma opção invalido o usuario sera notificado
e o menu ira iniciar novamente
### Inicializar

### Cadastrar Passageiro
Esta função tem como objetivo realizar o cadastro de novos passageiros, utilizando a estrutura Passageiro o usuario ira 
inserir o nome do novo passageiro enquanto o codigo ira atribuir a esse passageiro um ID.
#### Uso
Ao utilizar esta função o usuario deve inserir o nome do usuario para criar o ID é cadastrar o novo usuario.
### Regitrar Entrada
Esta função tem como objetivo registrar o horario de entrada do passageiro em estação e em qual estação ele entrou,
em caso do usuario inserira um passageiro não cadastrado o codigo ira redirecionar o usuario para função cadastrarPassgeiro.
#### Uso
Nesta função o usuario começará inserindo o ID do passageiro e o numero da estação na qual o passagero esta entrando, caso o
usuario insira um ID ainda não cadastrado no sistema sera redirecionado para a função Cadastra Passageiro mencionada anteriomente,
após isso o usuario devera registrar o horário de entrada do passageiro em ordem de Hora/Minuto/Segundo.
### Regitrar Saída
Esta função tem como objetivo registrar o horario de saída do passageiro em estação e em qual estação ele saiu,
em caso do usuario inserira um passageiro não cadastrado o codigo ira redirecionar o usuario para função cadastrarPassgeiro, 
esta função também verifica se o horario de saída do passageiro foi regitrado antes do horario de entrada.
#### Uso
Ao Utilizar a função o usuario ira começar inserindo o ID do passageiro e o numero da estação de que o passagero esta saíndo, caso o
usuario insira um ID ainda não cadastrado no sistema sera redirecionado para a função Cadastra Passageiro mencionada anteriomente,
após isso o usuario devera registrar o horário de saída do passageiro em ordem de Hora/Minuto/Segundo, caso insira um horario que se
passe antes do horario de entrada do passageiro sera notificado e a função ira encerrar.
### Gerar Relatorio
Esta função cria um arquivo contendo um relatorio geral de todos os passageiros que entraram e saíram das estaçoes 
dentro de um intervalo de tempo especifico inserido pelo usuario.

#### Uso


### Visualizar Fluxo de Estação
Essa função percorre o Struct Passageiros e filtra os passageiros que correspondem a condição de: a estação de entrada 
ou de saida do Passageiro apontado pelo ponteiro é igual a recebida pelo parametro.
Também exibe o total de passageiros que passaram pela estação apresentando a Matriz totalPassageiros correspondente pela condição apresentada acima.

