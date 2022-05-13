/*1-Faça uma consulta de todos os campos na tabela cliente*/
select * from cliente;



/*2-Consulte os campos nome e idade da tabela cliente onde o sexo=’F’*/
select nome, idade from cliente where sexo ='F';



/*3-Consulte os campos da tabela de cliente quando o sexo=’F’ e a idade for>=18, ordenando pela idade e nome*/
select * from cliente where sexo='F' and idade >=18 order by idade and nome;



/*4-consulte os campos produto,valor e quantidade da tabela produto e estoque ordenando pela quantidade em estoque decrescente*/
select nome as produto, valor, estoque as quantidade from produto order by quantidade desc;



/*5- Agrupe os pedidos por vendedor , mostrando o numero de pedidos , total dos pedidos e media dos pedidos.*/
select pedidos, count(quantidade),
sum(quantidade), avg(quantidade) from pedido group by vendedor;



/*6- Verifique no banco de dados o menor e o maior valor de pedido*/
Select Min(valor), Max(valor) from pedidos;