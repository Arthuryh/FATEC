create database lbd01;
use lbd01;

create table vendedor(codigo bigint primary key auto_increment,
vendedor varchar(100),
telefone varchar(100),
comissao float(10,2),
email varchar(100));

create table cliente(codigo bigint primary key auto_increment,
nome varchar(100), idade int(10), cidade varchar(50));

start transaction;
insert into vendedor(vendedor,telefone,comissao, email) values ('ronaldo', '1234-5432', 5.0,'ronaldo@net.com');
insert into vendedor(vendedor,telefone,comissao, email) values ('jorge', '4321-5432', 6.0,'jorge@net.com');
insert into vendedor(vendedor,telefone,comissao, email) values ('gabriel', '9876-5432', 7.0,'gabriel@net.com');

update vendedor set comissao = comissao + comissao * 0.1;

insert into cliente(nome,idade,cidade) values ('arthur', 22, 'são paulo');
insert into cliente(nome,idade,cidade) values ('gabriel', 18, 'são paulo');
insert into cliente(nome,idade,cidade) values ('joao', 25, 'são paulo');

update cliente set idade = idade+1 where cidade = 'são paulo';

delete from cliente where codigo = 1;
delete from vendedor where codigo = 2;

commit;
rollback;