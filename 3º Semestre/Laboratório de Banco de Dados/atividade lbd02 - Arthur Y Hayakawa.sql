/*1-Crie a tabela(vendedor) no banco de Dados com os seguintes campos:
código (auto incremento)
vendedor
telefone
comissão
2-Adicione uma nova coluna email
3-Remova esta coluna
4-Remova a tabela*/

create database lbd02;
use lbd02;

create table vendedor(
codigo bigint primary key
auto_increment,
vendedor varchar(100), 
telefone varchar(50),
comissao int(50));

alter table vendedor add column email varchar(100);
alter table vendedor drop column email;
drop table vendedor;
