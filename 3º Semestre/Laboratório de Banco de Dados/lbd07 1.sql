#1-Crie um index na tabela produto(nome)
create index idx_produto_1 on produto(nome);
select * from produto where nome = "Bolo de cenoura";

#2-Crie um index na tabela cliente(nome,email)
create index idx_cliente_1 on cliente(nome, email);
select * from cliente where nome = "suzana" and email = "suzana@norton.net.bridx_cliente_1idx_cliente_1";

select * from produto;
#3-Crie uma trigger na tabela pedido, cliente, produto para o evento
#--DELETE e UPDATE que guarde na tabela AUDITLOG os dados removidos ou alterados

#pedido
create trigger tr_pedido_log_upd before update on pedido
FOR EACH ROW
insert into AUDITLOG(codigo, nTotal, vTotal, nStatus, vStatus, dataAlteracao)
values (OLD.codigo, NEW.total, OLD.total, NEW.status, OLD.status, current_timestamp());

create trigger tr_pedido_log_del before delete on pedido
FOR EACH ROW
insert into AUDITLOG(codigo, vTotal, vDataPedido, vStatus, vCodigoCliente, vCodigoEntregador, dataAlteracao) 
values (OLD.codigo, OLD.total, OLD.dataPedido, OLD.status, OLD.codigoCliente, OLD.codigoEntregador, current_timestamp());

#cliente
create trigger tr_cliente_upd before update on pedido
FOR EACH ROW
insert into AUDITLOG(codigo, nEmail, vEmail, nTel, vTel, dataAlteracao) 
values (OLD.codigo, NEW.email, OLD.email, NEW.telefone, OLD.telefone, current_timestamp());

create trigger tr_cliente_del before delete on pedido
FOR EACH ROW
insert into AUDITLOG(codigo, vNome, vEmail, vTelefone, vEndereco, vCep, vCidade, dataAlteracao) 
values (OLD.codigo, OLD.nome, OLD.email, OLD.telefone, OLD.endereco, OLD.cep, OLD.cidade, current_timestamp());

select * from produto;
#produto
create trigger tr_produto_upd before update on pedido
FOR EACH ROW
insert into AUDITLOG(codigo, nNome, vNome, nValor, vValor, nQtd, vQtd, dataAlteracao) 
values (OLD.codigo, NEW.nome, OLD.nome, NEW.valor, OLD.valor, NEW.qtd, OLD.qtd, current_timestamp());

create trigger tr_produto_del before delete on pedido
FOR EACH ROW
insert into AUDITLOG(codigo, vNome, vValor, vQtd, dataAlteracao) 
values (OLD.codigo, OLD.nome, OLD.valor, OLD.qtd,current_timestamp());

select * from vendedor;

#4- crie uma view chamada vw_comissaoVendedor que calcule a comissao dos
#vendedores de acordo com o valor total dos pedidos feitos, mostre o codigo
#do vendedor, nome vendedor, valorComissao
create view vw_comissaoVendedor as
select codigoVendedor, count(codigo) as qtdPedidos,
sum(total) as totalPedidos, sum(total)/count(qtdPedidos) as valorComissao from pedido
group by codigoVendedor;
