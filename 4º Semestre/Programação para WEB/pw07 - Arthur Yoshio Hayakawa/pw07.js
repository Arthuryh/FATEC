function soma() {
    if(n1.value=="" || isNaN(n1.value)) {
        alert("Informe um número válido");
        n1.value = "";
        n1.focus();
        return false;
    }

    if(n2.value=="" || isNaN(n2.value)) {
        alert("Informe um número válido");
        n2.value = "";
        n2.focus();
        return false;
    }

    resultado.innerHTML = "Resultado da Soma:"

    var x = parseFloat(n1.value);
    var y = parseFloat(n2.value);
    var z = (x+y);
    res.value = z;
    //alert("Olá " + nome + ", média=" + z);
}

function subtracao(){
    if(n1.value=="" || isNaN(n1.value)) {
        alert("Informe um número válido");
        n1.value = "";
        n1.focus();
        return false;
    }

    if(n2.value=="" || isNaN(n2.value)) {
        alert("Informe um número válido");
        n2.value = "";
        n2.focus();
        return false;
    }

    resultado.innerHTML = "Resultado da Subtração:"

    var x = parseFloat(n1.value);
    var y = parseFloat(n2.value);
    var z = (x-y);
    res.value = z;
}

function multiplicacao(){
    if(n1.value=="" || isNaN(n1.value)) {
        alert("Informe um número válido");
        n1.value = "";
        n1.focus();
        return false;
    }

    if(n2.value=="" || isNaN(n2.value)) {
        alert("Informe um número válido");
        n2.value = "";
        n2.focus();
        return false;
    }

    resultado.innerHTML = "Resultado da Multiplicação:"

    var x = parseFloat(n1.value);
    var y = parseFloat(n2.value);
    var z = (x*y);
    res.value = z;
}

function divisao() {
    if(n1.value=="" || isNaN(n1.value)) {
        alert("Informe um número válido");
        n1.value = "";
        n1.focus();
        return false;
    }

    if(n2.value=="" || isNaN(n2.value) || n2.value=="0") {
        alert("Informe um número válido e diferente de 0");
        n2.value = "";
        n2.focus();
        return false;
    }

    resultado.innerHTML = "Resultado da Divisão:"

    var x = parseFloat(n1.value);
    var y = parseFloat(n2.value);
    var z = (x/y);
    res.value = z;
}