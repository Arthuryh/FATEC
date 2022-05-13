/*1- crie as tabelas abaixo e insira os valores demostrados:*/

create database bd01;
use bd01;

create table pedido(
    codigo bigint primary key auto_increment,
    codigoCliente bigint,
    codigoVendedor bigint,
    dataPedido timestamp,
    codigoEntrega bigint);
    
insert into pedido(codigo,codigoCliente,codigoVendedor,dataPedido,
 codigoEntrega) values(10308, 2, 7, 9/18/2020, 3);
 
 insert into pedido(codigo,codigoCliente,codigoVendedor,dataPedido,
 codigoEntrega) values(10309, 37, 3, 9/19/2020, 3);

insert into pedido(codigo,codigoCliente,codigoVendedor,dataPedido,
 codigoEntrega) values(10310, 77, 8, 9/20/2020, 2);
 
 insert into pedido(codigo,codigoCliente,codigoVendedor,dataPedido,
 codigoEntrega) values(1, 88, 89, 9/20/2020, 21);
 
 create table Cliente(
    codigoCliente bigint primary key auto_increment,
    nome varchar(50),
    contato varchar(50),
    logradouro varchar(50),
    cidade varchar(20),
    cep bigint,
    pais varchar(20));
    
insert into Cliente(nome,contato,logradouro,
 cidade,cep,pais) values("Alfreds","Maria Anders","Obere Str 57","Berlin",12209,"Germany");
 
insert into Cliente(nome,contato,logradouro,
 cidade,cep,pais) values("Ana Julia","	Ana Julia","Av. Nazare 2222","SP",5021,"Brasil");
 
 insert into Cliente(nome,contato,logradouro,
 cidade,cep,pais) values("Antonio Moreno","Antonio Moreno","Rua Bom Pastor","SP",5023,"Brasil");
 
/*2-Faça o inner join entre as tabelas PEDIDO e CLIENTE, mostrando o codigo do pedido, data do pedido, nome do cliente*/
 select p.codigo, p.dataPedido,c.nome from cliente c inner join pedido p on p.codigo = c.codigoCliente;
 
/*3-Faça o LEFT JOIN  entre as tabelas PEDIDO e CLIENTE para mostrar os pedidos que não tem cadastro de cliente*/
 select * from cliente c left join pedido p on p.codigo = c.codigoCliente;
 
/*4-Faça o RIGHT JOIN  entre as tabelas PEDIDO e CLIENTE para mostrar os clientes que não tem pedido*/
select * from cliente c right join pedido p on p.codigo = c.codigoCliente;
 
/*5-Faça uma consulta do plano cartesiano das duas tabelas*/
select * from pedido p cross join Cliente c;
select * from cliente, pedido;