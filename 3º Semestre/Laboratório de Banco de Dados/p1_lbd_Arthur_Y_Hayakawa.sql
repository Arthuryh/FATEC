create database p1_lbd;
use p1_lbd;

SET SQL_SAFE_UPDATES = 0;

create table entregador(
codigoEntregador bigint primary key auto_increment,
nome varchar(50) not null,
telefone varchar(50) not null);

create table produto(
codigoProduto bigint primary key auto_increment,
nome varchar(50) not null,
valor decimal (20,2) not null,
qtd int not null);

create table cliente(
codigoCliente bigint primary key auto_increment,
nome varchar(50) not null,
email varchar(50) not null,
telefone varchar(20) not null,
endereco varchar(100) not null,
cep varchar(9) not null,
cidade varchar(50) not null);

create table pedido(
codigoPedido bigint primary key auto_increment,
codigoCliente bigint,
codigoEntregador bigint,
foreign key (codigoCliente) references cliente(CodigoCliente),
foreign key (codigoEntregador) references entregador(CodigoEntregador),
total decimal (20,2),
dataPedido timestamp,
desc_status varchar(50));

create table item(
codigoItem bigint primary key auto_increment,
codigoPedido bigint,
codigoProduto bigint,
foreign key (codigoPedido) references pedido(CodigoPedido),
foreign key (codigoProduto) references produto(CodigoProduto),
qtd int not null,
valor decimal (20,2) not null);

insert into entregador(nome,telefone)values('Paulo','1111-1111');
insert into entregador(nome,telefone)values('Pedro','2222-2222');
insert into entregador(nome,telefone)values('Joao','3333-3333');

insert into produto(nome,valor,qtd)values('morango',12.00,15);
insert into produto(nome,valor,qtd)values('limao',13.00,20);
insert into produto(nome,valor,qtd)values('abacaxi',13.00,20);

insert into cliente(nome,email,telefone,endereco,cep,cidade)values('maria','maria@maria.com','1111-1111','rua 1','12345-123','sao paulo');
insert into cliente(nome,email,telefone,endereco,cep,cidade)values('joao','joao@joao.com','2222-2222','rua 2','53421-123','brasilia');
insert into cliente(nome,email,telefone,endereco,cep,cidade)values('paulo','paulo@paulo.com','3333-3333','rua 3','32145-123','acre');

insert into pedido(codigoCliente,codigoEntregador,total,dataPedido,desc_status)values(1,1,20.00,9/18/2020,'pedido-concluido');
insert into pedido(codigoCliente,codigoEntregador,total,dataPedido,desc_status)values(2,2,30.00,9/20/2020,'pedido-concluido');
insert into pedido(codigoCliente,codigoEntregador,total,dataPedido,desc_status)values(3,3,40.00,9/21/2020,'pedido-concluido');

insert into item(codigoPedido,codigoProduto,qtd,valor)values(1,1,2,20.00);
insert into item(codigoPedido,codigoProduto,qtd,valor)values(2,2,3,20.00);
insert into item(codigoPedido,codigoProduto,qtd,valor)values(3,3,4,20.00);

update produto set valor = valor + valor * 0.1;


SELECT Item.codigoProduto 'CODIGO PRODUTO', SUM(qtd) AS 'QTDE VENDIDA', valor as 'VALOR PEDIDO' FROM Item 
INNER JOIN Pedido
ON Pedido.codigoPedido = Item.codigoPedido
GROUP BY codigoProduto
ORDER BY 'QTDE VENDIDA' DESC;

/*nao consegui fazer a 5 :(  */