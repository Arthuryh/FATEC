/*2.1 Na tabela “T_SLV_CATEGORIA”, crie a instrução SQL, comando DDL para 
alterar o nome da coluna “ds_sigla_categoria” para “ds_sigla_categ”.

2.2 Na tabela “T_SLV_CATEGORIA”, crie a instrução SQL, comando DDL para 
alterar o nome da UNIQUE constraint “UN_SLV_CATEGORIA_DESC” para 
“UN_SLV_CATEG_DESC”.

2.3 Na tabela “T_SLV_AUTOR”, crie a instrução SQL, comando DDL para 
alterar o tamanho da coluna “nm_segundo_autor” para 30 caracteres.

2.4 Na tabela “T_SLV_AUTOR”, crie a instrução SQL, comando DDL para
adicionar coluna “ds_email”, com tipo de dado VARCHAR2, tamanho 40 
caracteres e obrigatória.

2.5 Na tabela “T_SLV_AUTOR”, crie a instrução SQL, comando DDL para
alterar o tamanho da coluna “ds_email” para 60 caracteres e elimine a 
constraint NOT NULL da coluna “ds_email”, utilizando uma única 
instrução.

2.6 Na tabela “T_SLV_AUTOR_LIVRO”, crie a instrução SQL, comando DDL 
para alterar o tamanho da coluna “nr_isbn” para 13 dígitos.

2.7 Na tabela “T_SLV_LIVRO”, crie a instrução SQL, comando DDL para alterar
o tamanho da coluna “nr_isbn” para 13 dígitos. Observe que esta coluna 
é uma chave primária, uma vez alterada, se faz necessário alterar a chave 
estrangeira também, como feito primeiramente no item 2.6.

2.8 Na tabela “T_SLV_AUTOR”, crie a instrução SQL, comando DDL para 
alterar adicionar a coluna “nm_pais_origem” (nome do país de origem do 
autor), com tipo de dado VARCHAR2, tamanho 30 caracteres e não 
obrigatório (opcional).

2.9 Na tabela “T_SLV_LIVRO”, crie a instrução SQL, comando DDL para alterar 
adicionar a constraint UNIQUE para a coluna “nm_titulo”. Nomeie a 
constraint como: “UN_SLV_LIVRO_TITULO”.

2.10 Na tabela “T_SLV_AUTOR_LIVRO”, crie a instrução SQL, comando 
DDL para eliminar a constraint chave estrangeira 
“FK_SLV_AUTOR_LIVRO_AUTOR”.

2.11 Na tabela “T_SLV_LIVRO”, crie a instrução SQL, comando DDL para 
eliminar a constraint chave primária “PK_SLV_LIVRO”, com a opção 
“CASCADE”, que elimina o relacionamento existente.

2.12 Na tabela “T_SLV_CATEGORIA”, crie a instrução SQL, comando 
DDL para desabilitar a constraint UNIQUE “UN_SLV_CATEGORIA_SIGLA” 
associada a coluna “ds_sigla_categ”.*/

--Q1--
ALTER TABLE T_SLV_AUTOR RENAME COLUMN ds_sigla_categoria TO ds_sigla_categ;

--Q2--
ALTER TABLE T_SLV_CATEGORIA RENAME CONSTRAINT UN_SLV_CATEGORIA)DESC TO UN_SLV_CATEG_DESC;

SELECT CONSTRAINT_NAME, CONSTRAINT_TYPE, SEARCH_CONDITION
  FROM USER_CONSTRAINTS
 WHERE TABLE_NAME = 'T_SLV_CATEGORIA';

--Q3--
ALTER TABLE T_SLV_AUTOR MODIFY nm_segundo_autor VARCHAR2(30);

--Q4--
ALTER TABLE T_SLV_AUTOR ADD ds_email VARCHAR2(40) NOT NULL; 

--Q5--
ALTER TABLE T_SLV_AUTOR MODIFY ds_email VARCHAR2(60) NULL;

--Q6--
ALTER TABLE T_SLV_AUTOR_LIVRO MODIFY nr_isbn NUMBER(13);

--Q7--
ALTER TABLE T_SLV_LIVRO MODIFY nr_isbn NUMBER(13);

--Q8--
ALTER TABLE T_SLV_AUTOR ADD nm_pais_origem VARCHAR2(30) NULL; 

--Q9--
ALTER TABLE T_SLV_LIVRO ADD CONSTRAINT UN_SLV_LIVRO_TITULO UNIQUE (nm_titulo);

--Q10--
ALTER TABLE T_SLV_AUTOR_LIVRO DROP CONSTRAINT FK_SLV_AUTOR_LIVRO_AUTOR; 

--Q11--
ALTER TABLE T_SLV_LIVRO DROP CONSTRAINT PK_SLV_LIVRO CASCADE;

--Q12--
ALTER TABLE T_SLV_CATEGORIA DISABLE CONSTRAINT UN_SLV_CATEGORIA_SIGLA;