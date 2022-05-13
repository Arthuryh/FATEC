-- Gerado por Oracle SQL Developer Data Modeler 21.2.0.183.1957
--   em:        2021-10-20 14:33:45 BRT
--   site:      Oracle Database 11g
--   tipo:      Oracle Database 11g



DROP TABLE t_spv_bairro CASCADE CONSTRAINTS;

DROP TABLE t_spv_cidade CASCADE CONSTRAINTS;

DROP TABLE t_spv_clas_fiscal CASCADE CONSTRAINTS;

DROP TABLE t_spv_cliente CASCADE CONSTRAINTS;

DROP TABLE t_spv_cliente_endereco CASCADE CONSTRAINTS;

DROP TABLE t_spv_endereco CASCADE CONSTRAINTS;

DROP TABLE t_spv_estado CASCADE CONSTRAINTS;

DROP TABLE t_spv_fone_cliente CASCADE CONSTRAINTS;

DROP TABLE t_spv_item_nf CASCADE CONSTRAINTS;

DROP TABLE t_spv_nota_fiscal CASCADE CONSTRAINTS;

DROP TABLE t_spv_operadora CASCADE CONSTRAINTS;

DROP TABLE t_spv_produto CASCADE CONSTRAINTS;

DROP TABLE t_spv_tipo_endereco CASCADE CONSTRAINTS;

DROP TABLE t_spv_tipo_fone CASCADE CONSTRAINTS;

DROP TABLE t_spv_tipo_logradouro CASCADE CONSTRAINTS;

DROP TABLE t_spv_unid_comercial CASCADE CONSTRAINTS;

-- predefined type, no DDL - MDSYS.SDO_GEOMETRY

-- predefined type, no DDL - XMLTYPE

CREATE TABLE t_spv_bairro (
    cd_bairro NUMBER(6) NOT NULL,
    cd_cidade NUMBER(4) NOT NULL,
    nm_bairro VARCHAR2(40) NOT NULL
);

ALTER TABLE t_spv_bairro ADD CONSTRAINT pk_spv_bairro PRIMARY KEY ( cd_bairro );

CREATE TABLE t_spv_cidade (
    cd_cidade NUMBER(4) NOT NULL,
    cd_estado NUMBER(2) NOT NULL,
    nm_cidade VARCHAR2(60) NOT NULL
);

ALTER TABLE t_spv_cidade ADD CONSTRAINT pk_spv_cidade PRIMARY KEY ( cd_cidade );

CREATE TABLE t_spv_clas_fiscal (
    nr_cfop          NUMBER(4) NOT NULL,
    ds_tipo_operacao NUMBER(1) NOT NULL,
    nm_nat_operacao  VARCHAR2(40) NOT NULL,
    ds_nat_operacao  VARCHAR2(200) NOT NULL
);

ALTER TABLE t_spv_clas_fiscal
    ADD CONSTRAINT ck_spv_clas_fiscal_tipo CHECK ( ds_tipo_operacao = 1
                                                   OR ds_tipo_operacao = 2 );

ALTER TABLE t_spv_clas_fiscal ADD CONSTRAINT pk_spv_clas_fiscal PRIMARY KEY ( nr_cfop );

ALTER TABLE t_spv_clas_fiscal ADD CONSTRAINT un_spv_clas_fiscal_natureza UNIQUE ( nm_nat_operacao );

CREATE TABLE t_spv_cliente (
    cd_cliente    NUMBER(5) NOT NULL,
    nm_cliente    VARCHAR2(50) NOT NULL,
    dt_nasc       DATE,
    ds_genero     CHAR(2) NOT NULL,
    ds_end        VARCHAR2(100) NOT NULL,
    nr_telefone   NUMBER(11),
    ds_email      VARCHAR2(60),
    nr_cpf        NUMBER(9) NOT NULL,
    nr_cpf_digito NUMBER(2) NOT NULL,
    nr_rg         NUMBER(8) NOT NULL,
    nr_rg_digito  CHAR(1) NOT NULL
);

COMMENT ON COLUMN t_spv_cliente.nr_telefone IS
    'ddd+n
99 - 99999 - 9999';

ALTER TABLE t_spv_cliente
    ADD CONSTRAINT ck_spv_cliente_genero CHECK ( upper(ds_genero) = 'H'
                                                 OR upper(ds_genero) = 'M'
                                                 OR upper(ds_genero) = 'NB' );

ALTER TABLE t_spv_cliente ADD CONSTRAINT pk_spv_cliente PRIMARY KEY ( cd_cliente );

ALTER TABLE t_spv_cliente ADD CONSTRAINT un_spv_cliente_cpf UNIQUE ( nr_cpf,
                                                                     nr_cpf_digito );

CREATE TABLE t_spv_cliente_endereco (
    nr_cep         NUMBER(8) NOT NULL,
    cd_cliente     NUMBER(5) NOT NULL,
    cd_tipo_end    NUMBER(2) NOT NULL,
    nr_logradouro  NUMBER(5) NOT NULL,
    ds_complemento VARCHAR2(30)
);

ALTER TABLE t_spv_cliente_endereco
    ADD CONSTRAINT pk_spv_cliente_endereco PRIMARY KEY ( nr_cep,
                                                         cd_cliente,
                                                         cd_tipo_end );

CREATE TABLE t_spv_endereco (
    nr_cep        NUMBER(8) NOT NULL,
    cd_tipo_log   NUMBER(2) NOT NULL,
    cd_bairro     NUMBER(6) NOT NULL,
    ds_logradouro VARCHAR2(60) NOT NULL
);

ALTER TABLE t_spv_endereco ADD CONSTRAINT pk_spv_endereco PRIMARY KEY ( nr_cep );

CREATE TABLE t_spv_estado (
    cd_estado NUMBER(2) NOT NULL,
    nm_estado VARCHAR2(30) NOT NULL,
    sg_estado CHAR(2) NOT NULL
);

ALTER TABLE t_spv_estado ADD CONSTRAINT pk_spv_estado PRIMARY KEY ( cd_estado );

CREATE TABLE t_spv_fone_cliente (
    cd_cliente   NUMBER(5) NOT NULL,
    nr_ddd       NUMBER(2) NOT NULL,
    nr_telefone  NUMBER(9) NOT NULL,
    cd_tipo_fone NUMBER(2) NOT NULL,
    cd_operadora NUMBER(2) NOT NULL,
    nr_ramal     NUMBER(4)
);

ALTER TABLE t_spv_fone_cliente
    ADD CONSTRAINT pk_spv_fone_cliente PRIMARY KEY ( nr_ddd,
                                                     nr_telefone,
                                                     cd_cliente );

CREATE TABLE t_spv_item_nf (
    nr_nota_fiscal      NUMBER(5) NOT NULL,
    cd_produto          NUMBER(5) NOT NULL,
    qt_comercializada   NUMBER(4) NOT NULL,
    vl_preco_unitario   NUMBER(7, 2) NOT NULL,
    vl_preco_total_item NUMBER(8, 2) NOT NULL
);

ALTER TABLE t_spv_item_nf ADD CONSTRAINT ck_spv_item_nf_preuni CHECK ( vl_preco_unitario > 0 );

ALTER TABLE t_spv_item_nf ADD CONSTRAINT ck_spv_item_nf_qtde CHECK ( qt_comercializada > 0 );

ALTER TABLE t_spv_item_nf ADD CONSTRAINT pk_spv_item_nf PRIMARY KEY ( nr_nota_fiscal,
                                                                      cd_produto );

CREATE TABLE t_spv_nota_fiscal (
    nr_nota_fiscal NUMBER(5) NOT NULL,
    cd_cliente     NUMBER(5) NOT NULL,
    nr_cfop        NUMBER(4) NOT NULL,
    dt_emissao     DATE NOT NULL,
    dt_saida       DATE NOT NULL,
    vl_total_nf    NUMBER(9, 2) NOT NULL,
    vl_desconto    NUMBER(3, 1)
);

ALTER TABLE t_spv_nota_fiscal ADD CONSTRAINT ck_spv_nota_fiscal_data CHECK ( dt_saida >= dt_emissao );

ALTER TABLE t_spv_nota_fiscal
    ADD CONSTRAINT ck_spv_nota_fiscal_desconto CHECK ( vl_desconto >= 0
                                                       AND vl_desconto <= 25 );

ALTER TABLE t_spv_nota_fiscal ADD CONSTRAINT pk_spv_nota_fiscal PRIMARY KEY ( nr_nota_fiscal );

CREATE TABLE t_spv_operadora (
    cd_operadora NUMBER(2) NOT NULL,
    nm_operadora VARCHAR2(20) NOT NULL
);

ALTER TABLE t_spv_operadora ADD CONSTRAINT pk_spv_operadora PRIMARY KEY ( cd_operadora );

CREATE TABLE t_spv_produto (
    cd_produto          NUMBER(5) NOT NULL,
    cd_unid_cml         NUMBER(3) NOT NULL,
    ds_produto          VARCHAR2(40) NOT NULL,
    ds_completa_produto VARCHAR2(100) NOT NULL,
    qt_estoque          NUMBER(4) NOT NULL,
    vl_preco_unitario   NUMBER(7, 2) NOT NULL
);

ALTER TABLE t_spv_produto ADD CONSTRAINT ck_spv_produto_preuni CHECK ( vl_preco_unitario > 0 );

ALTER TABLE t_spv_produto ADD CONSTRAINT pk_spv_produto PRIMARY KEY ( cd_produto );

ALTER TABLE t_spv_produto ADD CONSTRAINT un_spv_produto_desc UNIQUE ( ds_produto );

CREATE TABLE t_spv_tipo_endereco (
    cd_tipo_end NUMBER(2) NOT NULL,
    nm_tipo_end VARCHAR2(20) NOT NULL
);

ALTER TABLE t_spv_tipo_endereco ADD CONSTRAINT pk_spv_tipo_endereco PRIMARY KEY ( cd_tipo_end );

CREATE TABLE t_spv_tipo_fone (
    cd_tipo_fone NUMBER(2) NOT NULL,
    nm_tipo_fone VARCHAR2(20) NOT NULL
);

ALTER TABLE t_spv_tipo_fone ADD CONSTRAINT pk_spv_tipo_fone PRIMARY KEY ( cd_tipo_fone );

CREATE TABLE t_spv_tipo_logradouro (
    cd_tipo_log NUMBER(2) NOT NULL,
    nm_tipo_log VARCHAR2(20) NOT NULL
);

ALTER TABLE t_spv_tipo_logradouro ADD CONSTRAINT pk_spv_tipo_logradouro PRIMARY KEY ( cd_tipo_log );

CREATE TABLE t_spv_unid_comercial (
    cd_unid_cml    NUMBER(3) NOT NULL,
    ds_unid_cml    VARCHAR2(30) NOT NULL,
    sigla_unid_cml CHAR(6) NOT NULL
);

ALTER TABLE t_spv_unid_comercial ADD CONSTRAINT pk_spv_unid_comercial PRIMARY KEY ( cd_unid_cml );

ALTER TABLE t_spv_unid_comercial ADD CONSTRAINT un_spv_unid_comercial_desc UNIQUE ( ds_unid_cml );

ALTER TABLE t_spv_endereco
    ADD CONSTRAINT fk_spv_bairro FOREIGN KEY ( cd_bairro )
        REFERENCES t_spv_bairro ( cd_bairro );

ALTER TABLE t_spv_bairro
    ADD CONSTRAINT fk_spv_bairro_cidade FOREIGN KEY ( cd_cidade )
        REFERENCES t_spv_cidade ( cd_cidade );

ALTER TABLE t_spv_cidade
    ADD CONSTRAINT fk_spv_cidade_estado FOREIGN KEY ( cd_estado )
        REFERENCES t_spv_estado ( cd_estado );

ALTER TABLE t_spv_cliente_endereco
    ADD CONSTRAINT fk_spv_cliende_cliente FOREIGN KEY ( cd_cliente )
        REFERENCES t_spv_cliente ( cd_cliente );

ALTER TABLE t_spv_cliente_endereco
    ADD CONSTRAINT fk_spv_cliende_ende FOREIGN KEY ( nr_cep )
        REFERENCES t_spv_endereco ( nr_cep );

ALTER TABLE t_spv_cliente_endereco
    ADD CONSTRAINT fk_spv_cliende_tipo_ende FOREIGN KEY ( cd_tipo_end )
        REFERENCES t_spv_tipo_endereco ( cd_tipo_end );

ALTER TABLE t_spv_fone_cliente
    ADD CONSTRAINT fk_spv_fonecli_cliente FOREIGN KEY ( cd_cliente )
        REFERENCES t_spv_cliente ( cd_cliente );

ALTER TABLE t_spv_fone_cliente
    ADD CONSTRAINT fk_spv_fonecli_operadora FOREIGN KEY ( cd_operadora )
        REFERENCES t_spv_operadora ( cd_operadora );

ALTER TABLE t_spv_fone_cliente
    ADD CONSTRAINT fk_spv_fonecli_tipo_fone FOREIGN KEY ( cd_tipo_fone )
        REFERENCES t_spv_tipo_fone ( cd_tipo_fone );

ALTER TABLE t_spv_item_nf
    ADD CONSTRAINT fk_spv_itemnf_nf FOREIGN KEY ( nr_nota_fiscal )
        REFERENCES t_spv_nota_fiscal ( nr_nota_fiscal );

ALTER TABLE t_spv_item_nf
    ADD CONSTRAINT fk_spv_itemnf_produto FOREIGN KEY ( cd_produto )
        REFERENCES t_spv_produto ( cd_produto );

ALTER TABLE t_spv_endereco
    ADD CONSTRAINT fk_spv_logradouro FOREIGN KEY ( cd_tipo_log )
        REFERENCES t_spv_tipo_logradouro ( cd_tipo_log );

ALTER TABLE t_spv_nota_fiscal
    ADD CONSTRAINT fk_spv_nf_clas_fiscal FOREIGN KEY ( nr_cfop )
        REFERENCES t_spv_clas_fiscal ( nr_cfop );

ALTER TABLE t_spv_nota_fiscal
    ADD CONSTRAINT fk_spv_nf_cliente FOREIGN KEY ( cd_cliente )
        REFERENCES t_spv_cliente ( cd_cliente );

ALTER TABLE t_spv_produto
    ADD CONSTRAINT fk_spv_produto_unid_cml FOREIGN KEY ( cd_unid_cml )
        REFERENCES t_spv_unid_comercial ( cd_unid_cml );



-- Relatório do Resumo do Oracle SQL Developer Data Modeler: 
-- 
-- CREATE TABLE                            16
-- CREATE INDEX                             0
-- ALTER TABLE                             42
-- CREATE VIEW                              0
-- ALTER VIEW                               0
-- CREATE PACKAGE                           0
-- CREATE PACKAGE BODY                      0
-- CREATE PROCEDURE                         0
-- CREATE FUNCTION                          0
-- CREATE TRIGGER                           0
-- ALTER TRIGGER                            0
-- CREATE COLLECTION TYPE                   0
-- CREATE STRUCTURED TYPE                   0
-- CREATE STRUCTURED TYPE BODY              0
-- CREATE CLUSTER                           0
-- CREATE CONTEXT                           0
-- CREATE DATABASE                          0
-- CREATE DIMENSION                         0
-- CREATE DIRECTORY                         0
-- CREATE DISK GROUP                        0
-- CREATE ROLE                              0
-- CREATE ROLLBACK SEGMENT                  0
-- CREATE SEQUENCE                          0
-- CREATE MATERIALIZED VIEW                 0
-- CREATE MATERIALIZED VIEW LOG             0
-- CREATE SYNONYM                           0
-- CREATE TABLESPACE                        0
-- CREATE USER                              0
-- 
-- DROP TABLESPACE                          0
-- DROP DATABASE                            0
-- 
-- REDACTION POLICY                         0
-- 
-- ORDS DROP SCHEMA                         0
-- ORDS ENABLE SCHEMA                       0
-- ORDS ENABLE OBJECT                       0
-- 
-- ERRORS                                   0
-- WARNINGS                                 0
