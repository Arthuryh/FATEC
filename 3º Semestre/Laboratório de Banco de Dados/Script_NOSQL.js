use lbd; //para usar o banco 'x'
show collections; //para mostrar as coleções 
show roles; //para mostrar as colunas
db.produto.find(); //para mostrar o conteúdo do documento

db.pedido.save({total:"20",dataPedido:"13/05/2022:14:31",codigoCliente:"1",codigoEntregador:"1"});
db.pedido.save({total:"18",dataPedido:"13/05/2022:15:27",codigoCliente:"3",codigoEntregador:"2"});
db.pedido.save({total:"16",dataPedido:"01/05/2022:14:31",codigoCliente:"2",codigoEntregador:"3"});
db.pedido.save({total:"78",dataPedido:"06/05/2022:12:31",codigoCliente:"1",codigoEntregador:"4"});

db.produto.save({nome:"Bolo de cenoura",valor:"20",qtd:"28"});
db.produto.save({nome:"Bolo de chocolate",valor:"22",qtd:"18"});
db.produto.save({nome:"Bolo de fuba",valor:"18",qtd:"68"});

db.colors.save({name:"red",value:"FF0000"});

db.usuarios.insert({​nome:"Norton Glaser",​cidade:"São Paulo",​estado:"SP"​}​);​ //criação do esquema
db.usuarios.remove({estado:"Santa Catarina"}) //apagar determinado dado
db.usuarios.remove(); //apagar tudo do documento
db.usuarios.update({cidade: { $eq:"Campinas"}, $set:{estado: "SP"}, {multi: true} } ); //atualização de determinado dado
db.usuario.find( {estado: { $eq: "SP"} }); //consulta de determiando dado
db.usuarios.find(​ {idade:{$gt:25, $lte:50}}​); //comparação numérica
db.usuarios.find(​{nome:/^Maria/}​) //busca com operador like "/^xxxx/"
db.usuarios.find({cidade : "Campinas"}).sort({nome:1}); //busca com ordenação crescente
db.usuarios.find({cidade : "Campinas"}).sort({nome:-1}) //busca com ordenação decrescente