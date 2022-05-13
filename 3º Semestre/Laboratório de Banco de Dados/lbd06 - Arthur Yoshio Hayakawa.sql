/*1-Faça o union das tabelas cliente e vendedor extraia os campos nome e email ordenados pelo nome de forma crescente*/
select nome, email from cliente
union
select vendedor, email from vendedor order by nome desc;

/*2-Faça o union all das tabelas cliente e vendedor extraia os campos nome e email*/
select nome, email from cliente
union all
select vendedor, email from vendedor;

/*3-Faça o except das tabelas cliente e vendedor extraia os campos nome e email*/
select nome, email from cliente 
where nome not in (select nome from vendedor);

/*4-Faça o intersect das tabelas cliente e vendedor extraia os campos nome e email*/
select nome, email from cliente 
where nome in (select nome from vendedor);