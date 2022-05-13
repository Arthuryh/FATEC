#1-Utilizando a tabela "pedido" liste o valor quando a data do
#pedido estiver entre 01/03/2022 e 31/03/2022 use o operador BETWEEN
select * from pedido where dataPedido between '2022-03-01%' and  '2022-03-31%';

#2-Liste todos os registros da tabela cliente que contiver a letra A
#no nome use o operador LIKE
select nome from cliente where nome like 'A%';

#3-Liste todos os clientes cuja a cidade for SÃO PAULO, 
#CAMPINAS use o operador IN
select * from cliente where cidade in ('SÃO PAULO','CAMPINAS');

#4-liste todos os clientes que ainda nao fizeram pedidos use o operador NOT IN
select * from cliente c where c.codigo not in (select codigoCliente from pedido);

#5-Liste todos os clientes com a idade entre 18 e 30 anos use o operador BETWEEN
select * from cliente where idade between '18' and  '30';

#6-utilizando o campo DataPedido da tabela Pedido some 7 dias para
#simular a data de entrega do mesmo
select codigo, total, dataPedido adddate(dataPedido, 7) from pedido;