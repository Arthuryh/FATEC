/* 
DROP TABLE t_slv_autor          CASCADE CONSTRAINTS; 
DROP TABLE t_slv_autor_livro    CASCADE CONSTRAINTS; 
DROP TABLE t_slv_categoria      CASCADE CONSTRAINTS; 
DROP TABLE t_slv_livro          CASCADE CONSTRAINTS; 
*/ 


-- CRIAÇÃO DA TABELA AUTOR 
CREATE TABLE t_slv_autor ( 
    cd_autor           NUMBER(3)    NOT NULL, 
    nm_primeiro_autor  VARCHAR2(20) NOT NULL, 
    nm_segundo_autor   VARCHAR2(40) NOT NULL 
); 

-- ADIÇÃO DA CONSTRAINT CHAVE PRIMARIA 
ALTER TABLE t_slv_autor ADD CONSTRAINT pk_slv_autor PRIMARY KEY ( cd_autor ); 

  
-- CRIAÇÃO DA TABELA AUTOR_LIVRO 
CREATE TABLE t_slv_autor_livro ( 
    nr_isbn             NUMBER(8) NOT NULL, 
    cd_autor            NUMBER(3) NOT NULL, 
    st_autor_principal  NUMBER(1) NOT NULL 
); 

 
-- ADIÇÃO DA CONSTRAINT CHECK 
ALTER TABLE t_slv_autor_livro 
    ADD CONSTRAINT ck_slv_autor_livro_status CHECK ( st_autor_principal IN (1,2) ); 

-- Equivalente 
-- st_autor_principal IN (1,2) 
-- 
-- st_autor_principal = 1 OR st_autor_principal = 2 
  

-- ADIÇÃO DA CONSTRAINT CHAVE PRIMARIA (COMPOSTA) 
ALTER TABLE t_slv_autor_livro ADD CONSTRAINT pk_slv_autor_livro PRIMARY KEY ( nr_isbn, cd_autor ); 


-- CRIAÇÃO DA TABELA CATEGORIA 
CREATE TABLE t_slv_categoria ( 
    cd_categoria        NUMBER(3)       NOT NULL, 
    ds_sigla_categoria  CHAR(3)         NOT NULL, 
    ds_categoria        VARCHAR2(30)    NOT NULL 
); 

 
-- ADIÇÃO DA CONSTRAINT CHAVE PRIMARIA 
ALTER TABLE t_slv_categoria ADD CONSTRAINT pk_slv_categoria PRIMARY KEY ( cd_categoria ); 


-- ADIÇÃO DA CONSTRAINT UNIQUE 
ALTER TABLE t_slv_categoria ADD CONSTRAINT un_slv_categoria_sigla UNIQUE ( ds_sigla_categoria ); 

 
-- ADIÇÃO DA CONSTRAINT UNIQUE 
ALTER TABLE t_slv_categoria ADD CONSTRAINT un_slv_categoria_desc UNIQUE ( ds_categoria ); 

  
-- CRIAÇÃO DA TABELA LIVRO 
CREATE TABLE t_slv_livro ( 
    nr_isbn       NUMBER(8)         NOT NULL, 
    cd_categoria  NUMBER(3)         NOT NULL, 
    nm_titulo     VARCHAR2(50)      NOT NULL, 
    ds_sinopse    VARCHAR2(200)     NOT NULL, 
    nr_edicao     NUMBER(2)         NOT NULL, 
    nr_ano        NUMBER(4)         NOT NULL 
); 

 
-- ADIÇÃO DA CONSTRAINT CHECK 
ALTER TABLE t_slv_livro ADD CONSTRAINT ck_slv_livro_edicao CHECK ( nr_edicao > 0 ); 

 
-- ADIÇÃO DA CONSTRAINT CHECK 
ALTER TABLE t_slv_livro ADD CONSTRAINT ck_slv_livro_ano CHECK ( nr_ano > 0 ); 


-- ADIÇÃO DA CONSTRAINT CHAVE PRIMARIA 
ALTER TABLE t_slv_livro ADD CONSTRAINT pk_slv_livro PRIMARY KEY ( nr_isbn ); 

  

  
-- ADIÇÃO DA CONSTRAINT CHAVE ESTRANGEIRA - RELACIONAMENTOS 
-- RELACIONAMENTO ENTRE AUTOR_LIVRO (FK-destino) E AUTOR (PK-origem) 
   ALTER TABLE t_slv_autor_livro 
ADD CONSTRAINT fk_slv_autor_livro_autor  
   FOREIGN KEY ( cd_autor ) -- FK NA TABELA t_slv_autor_livro 
    REFERENCES t_slv_autor ( cd_autor ); -- TABELA ORIGEM/ PK NA TABELA ORIGEM 

         

-- RELACIONAMENTO ENTRE AUTOR_LIVRO E LIVRO 
   ALTER TABLE t_slv_autor_livro 
ADD CONSTRAINT fk_slv_autor_livro_livro  
   FOREIGN KEY ( nr_isbn ) 
    REFERENCES t_slv_livro ( nr_isbn ); 

  

-- RELACIONAMENTO ENTRE LIVRO E CATEGORIA 
   ALTER TABLE t_slv_livro 
ADD CONSTRAINT fk_slv_livro_categoria  
   FOREIGN KEY ( cd_categoria ) 
    REFERENCES t_slv_categoria ( cd_categoria ); 

 

DESC t_slv_autor; 
DESC t_slv_autor_livro; 
DESC t_slv_categoria; 
DESC t_slv_livro; 

  

  

SELECT CONSTRAINT_NAME, CONSTRAINT_TYPE, SEARCH_CONDITION 
  FROM ALL_CONSTRAINTS 
WHERE TABLE_NAME = 'T_SLV_AUTOR';  

  

SELECT CONSTRAINT_NAME, CONSTRAINT_TYPE, SEARCH_CONDITION 
  FROM ALL_CONSTRAINTS 
WHERE TABLE_NAME = 'T_SLV_AUTOR_LIVRO';  

  

SELECT CONSTRAINT_NAME, CONSTRAINT_TYPE, SEARCH_CONDITION 
  FROM ALL_CONSTRAINTS 
WHERE TABLE_NAME = 'T_SLV_CATEGORIA';  

  

SELECT CONSTRAINT_NAME, CONSTRAINT_TYPE, SEARCH_CONDITION 
  FROM ALL_CONSTRAINTS 
WHERE TABLE_NAME = 'T_SLV_LIVRO';  