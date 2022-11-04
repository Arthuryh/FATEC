var regNome = new RegExp("[A-z ]{6,100}");
var regEmail = new RegExp("[a-z0-9]+@[a-z]+\.[a-z]{2,3}");
var regSenha = new RegExp("^(?=.*[A-Z])(?=.*[!#@$%&-+_(){}])(?=.*[0-9])(?=.*[a-z]).{6,25}$");
var regCPF = new RegExp("[0-9]{3}.[0-9]{3}.[0-9]{3}-[0-9]{2}");
var regTel = new RegExp("[0-9]{4,5}-[0-9]{4}");

function validarCad(){
    document.getElementById("txtNomeCad").classList.remove("errotxt");
    document.getElementById("txtEmailCad").classList.remove("errotxt");
    document.getElementById("txtSenhaCad").classList.remove("errotxt");
    document.getElementById("txtConfirmaCad").classList.remove("errotxt");
    document.getElementById("txtCpfCad").classList.remove("errotxt");
    document.getElementById("txtTelCad").classList.remove("errotxt");
    erroNome.innerHTML = "";
    erroEmail.innerHTML = "";
    erroSenha.innerHTML = "";
    erroConfirma.innerHTML = "";
    erroCpf.innerHTML = "";
    erroTelefone.innerHTML = "";
    var tudoOk = true;
    if(!regNome.test(txtNomeCad.value)){
        erroNome.innerHTML = "Informe um nome completo !";
        document.getElementById("erroNome").classList.add("errolbl");
        document.getElementById("txtNomeCad").classList.add("errotxt");
        document.getElementById("txtNomeCad").focus();
        tudoOk = false;
    }
    if(!regEmail.test(txtEmailCad.value)){
        erroEmail.innerHTML = "Informe um email válido !";
        document.getElementById("erroEmail").classList.add("errolbl");
        document.getElementById("txtEmailCad").classList.add("errotxt");
        document.getElementById("txtEmailCad").focus();
        tudoOk = false;
    }
    if(!regSenha.test(txtSenhaCad.value)){
        erroSenha.innerHTML = "Informe uma senha forte!<br>De 6 dígitos, com Letra Maiúscula, Caracter especial e Número!";
        document.getElementById("erroSenha").classList.add("errolbl");
        document.getElementById("txtSenhaCad").classList.add("errotxt");
        document.getElementById("txtConfirmaCad").classList.add("errotxt");
        document.getElementById("txtSenhaCad").focus();
        tudoOk = false;      
    }
    if(txtConfirmaCad.value !== txtSenhaCad.value){
        erroConfirma.innerHTML = "As senhas não são iguais !";
        document.getElementById("erroConfirma").classList.add("errolbl");
        document.getElementById("txtConfirmaCad").classList.add("erro");
        document.getElementById("txtConfirmaCad").focus();
        tudoOk = false;      
    }
    if(!regCPF.test(txtCpfCad.value)){
        erroCpf.innerHTML = "Informe um CPF válido !";
        document.getElementById("erroCpf").classList.add("errolbl");
        document.getElementById("txtCpfCad").classList.add("errotxt");
        document.getElementById("txtCpfCad").focus();
        tudoOk = false;      
    }
    if(!regTel.test(txtTelCad.value)){
        erroTelefone.innerHTML = "Informe um telefone valido !";
        document.getElementById("erroTelefone").classList.add("errolbl");
        document.getElementById("txtTelCad").classList.add("errotxt");
        document.getElementById("txtTelCad").focus();
        tudoOk = false;
    }
    if(tudoOk == true) {
        frm2.submit();
    }
}

function validarLogin() {
    document.getElementById("txtEmailLog").classList.remove("errotxt");
    document.getElementById("txtSenhaLog").classList.remove("errotxt");
    lblEmailLog.innerHTML = "";
    lblSenhaLog.innerHTML = "";
    var tudoOk = true;

    if(!regEmail.test(txtEmailLog.value)){
        lblEmailLog.innerHTML = "Email incorreto ou não cadastrado !";
        document.getElementById("lblEmailLog").classList.add("errolbl");
        document.getElementById("txtEmailLog").classList.add("errotxt");
        document.getElementById("txtEmailLog").focus();
        tudoOk = false;
    }
    if(!regSenha.test(txtSenhaLog.value)){
        lblSenhaLog.innerHTML = "Senha incorreta !";
        document.getElementById("lblSenhaLog").classList.add("errolbl");
        document.getElementById("txtSenhaLog").classList.add("errotxt");
        document.getElementById("txtSenhaLog").focus();
        tudoOk = false;
    }

    if(tudoOk == true) {
        frm1.submit();
    }
}

function validarEsq() {
    document.getElementById("txtEmailEsq").classList.remove("errotxt");
    lblEmailEsq.innerHTML = "";
    var tudoOk = true;

    if(!regEmail.test(txtEmailEsq.value)){
        lblEmailEsq.innerHTML = "Email incorreto ou não cadastrado !";
        document.getElementById("lblEmailEsq").classList.add("errolbl");
        document.getElementById("txtEmailEsq").classList.add("errotxt");
        document.getElementById("txtEmailEsq").focus();
        tudoOk = false;
    }

    if(tudoOk == true) {
        frm3.submit();
    }
}

function carregarPag(pagina) {
    if(pagina == "prod1") {
        padraoPagina("Cypher","Cypher é um agente de VALORANT que é a personificação do arquétipo do espião e do infiltrado. Cypher depende de emboscar inimigos com várias armadilhas, que atordoam, restringem e retardam os inimigos em seu alcance.",
        "R$110,00","Tamanho:60x60<br>Peso:100g","p1","p1a","p1b");
    }

    if(pagina == "prod2") {
        padraoPagina("Killjoy","Killjoy é um agente de VALORANT especializado em controle de multidões por meio de gadgets, bots e maravilhas da engenharia. Alarmbot e Nanoswarm permitem que Killjoy implante ferramentas que procuram e danificam alvos ou explodem para causar dano de um estado secreto. Sua Torreta, por outro lado, pode ser colocada em uma área crítica no mapa, como locais de plantas Spike, atrás de cantos ou outras posições estratégicas para causar dano aos inimigos em seu alcance.",
        "R$125,00","Tamanho:75x75<br>Peso:125g","p2","p2a","p2b");
    }
    
    if(pagina == "prod3") {
        padraoPagina("Sage","Sage é uma agente de VALORANT, cujas habilidades fazem dela um suporte fundamental no jogo. Sage equipa vários orbes que podem retardar inimigos, curar aliados ou erguer paredes para controlar o campo de batalha. Sua suprema, Ressurreição, pode até trazer aliados mortos de volta à vida, balançando o equilíbrio de poder em uma partida em segundos. Sage prospera quando está atrás de sua equipe, escondida do fogo inimigo.",
        "R$130,00","Tamanho:65x65<br>Peso:110g","p3","p3a","p3b");
    }
    
    if(pagina == "prod4") {
        padraoPagina("Jett","Jett é um agente de VALORANT especializado em mobilidade e assassinatos. Como um verdadeiro ninja, este agente sul-coreano pode percorrer distâncias curtas para alcançar inimigos ou escapar de situações perigosas, e até mesmo se impulsionar para alcançar lugares altos e surpreender alvos à espreita que pensam que estão seguros lá em cima. A combinação da habilidade Cloudburst e o Blade Storm ultimate fazem de Jett um pesadelo de combate corpo a corpo, pois ela pode executar inimigos que nem percebem o que os atingiu.",
        "R$115,00","Tamanho:73x73<br>Peso:115g","p4","p4a","p4b");
    }
}

function padraoPagina(titulo, descricao, precoProduto, especsProduto, src1, src2, src3) {
    document.getElementById("tituloProduto").innerHTML = titulo;
    document.getElementById("descricaoProduto").innerHTML = descricao;
    document.getElementById("precoProduto").innerHTML = precoProduto;
    document.getElementById("especsProduto").innerHTML = especsProduto;
    document.getElementById("carrou1").src="img/produtos/"+src1+".webp";
    document.getElementById("carrou2").src="img/produtos/"+src2+".webp";
    document.getElementById("carrou3").src="img/produtos/"+src3+".webp";
}

function store_prod (guardado) {
    sessionStorage.setItem("first", guardado);
    location.href = "product_detail.html";
}

function get_prod () {
    var first = sessionStorage.getItem("first");
    carregarPag(first);
}

function store_busca (guardado) {
    sessionStorage.setItem("busca", guardado);
    location.href = "busca.html";
}

function get_busca () {
    var first = sessionStorage.getItem("busca");
    document.getElementById("produto-procurado").innerHTML = first;
}

function limparCarrinho(){
    document.getElementById("conteudo").remove();
    document.getElementById("frm4").innerHTML = "<h1>CESTA VAZIA</h1>";
}
