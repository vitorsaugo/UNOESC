function mostrarAlerta(idResposta, mensagem, tipo) {
    let resposta = document.getElementById(idResposta);

    resposta.innerHTML = `
        <div class="alert alert-${tipo}" role="alert">
            ${mensagem}
        </div>
    `;
}


function pergunta1() {
    let nascimento = Number(document.getElementById("pergunta1").value);

    if (isNaN(nascimento) || nascimento <= 0) {
        mostrarAlerta("resposta1", "Digite um ano valido.", "danger");
        return;
    }

    let anoAtual = new Date().getFullYear();
    let idade = anoAtual - nascimento;

    mostrarAlerta(
        "resposta1",
        "Voce tem " + idade + " anos.",
        "success"
    );
}


function pergunta2() {
    let salario = Number(document.getElementById("pergunta2").value);

    if (isNaN(salario) || salario <= 0) {
        mostrarAlerta("resposta2", "Digite um salario valido.", "danger");
        return;
    }

    let salarioMinimo = 1621;
    let aumento;

    if (salario <= salarioMinimo) {
        aumento = salario * 15 / 100;
    } else {
        aumento = salario * 8 / 100;
    }

    let novoSalario = salario + aumento;

    mostrarAlerta(
        "resposta2",
        "Seu novo salario e de: R$ " + novoSalario.toFixed(2),
        "success"
    );
}

function pergunta3() {
    let idade1 = Number(document.getElementById("pergunta3").value);
    if (isNaN(idade1) || idade1 < 0) {
        mostrarAlerta("resposta3", "Digite um numero valido", "danger");
    }
    suaidade = idade1;

    if (suaidade >= 18) {
        mostrarAlerta("resposta3", `Você é maior de idade, tem ${suaidade} anos`, "success");
    } else {
        mostrarAlerta("resposta3", `Você é menor de idade, tem ${suaidade} anos`, "success");
    }
}

function pergunta4() {
    let nota1 = Number(document.getElementById("nota1").value);
    let nota2 = Number(document.getElementById("nota2").value);
    let nota3 = Number(document.getElementById("nota3").value);

    let media = (nota1 + nota2 + nota3) / 3;

    mostrarAlerta("resposta4", `A média é ${media}`, "success");

}

function pergunta5() {
    let codigo = Number(document.getElementById("codigoItem").value);
    let quantidade = Number(document.getElementById("quantidade").value);

    if (codigo == 100) {
        preco = 5.50;
    } else if (codigo == 101) {
        preco = 6.00;
    } else if (codigo = 102) {
        preco = 6.50;
    } else if (codigo = 103) {
        preco = 6.75;
    } else if (codigo = 104) {
        preco = 7.50;
    } else {
       mostrarAlerta("resposta5", "Codigo invalido.", "danger");
       return;
    }

    let total = preco * quantidade;

    mostrarAlerta("resposta5", `O valor total é de R$ ${total.toFixed(2)}`, "success")

    
}
