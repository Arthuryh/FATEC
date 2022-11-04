<!DOCTYPE html>
<html>
    <head>
        <title>PHP - Atividade</title>
        
        <!-- CSS only -->
        <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-iYQeCzEYFbKjA/T2uDLTpkwGzCiq6soy8tYaI1GyVh/UjpbCx/TYkiZhlZB6+fzT" crossorigin="anonymous">

    </head>
    <body class="container bg-dark text-bg-dark">
        <h1 class="text-center">PW08 - ATIVIDADE PHP</h1>
        <form method="post" class="form-control text-center text-bg-dark bg-dark" action="pw08.php">
            

            n1: <input type="number" required id="n1" name="n1"><br>
            n2: <input type="number" required id="n2" name="n2"><br>
            <nav class="navbar navbar-expand-sm justify-content-center">
                <ul class="navbar-nav">
                  <li><button class="nav-item btn btn-outline-danger" id="btnsoma" name="btnsoma">Soma</button></li>
                  <li><button class="nav-item btn btn-outline-danger" id="btnsub" name="btnsub">Subtração</button></li>
                  <li><button class="nav-item btn btn-outline-danger" id="btnmult" name="btnmult">Multiplicação</button></li>
                  <li><button class="nav-item btn btn-outline-danger" id="btndiv" name="btndiv">Divisão</button></li>
                  <li><button class="nav-item btn btn-outline-danger" id="btntaboada" name="btntaboada">Taboada</button></li>
                </ul>
              </div> 
            </nav>
        </form>
        <?php  if(isset($_POST["btnsoma"])) soma(); ?>
        <?php  if(isset($_POST["btnsub"])) subtracao(); ?>
        <?php  if(isset($_POST["btnmult"])) multiplicacao(); ?>
        <?php  if(isset($_POST["btndiv"])) divisao(); ?>
        <?php  if(isset($_POST["btntaboada"])) taboada(); ?>
    </body>
</html>

<?php
    function soma() {
        $a = $_POST["n1"];
        $b = $_POST["n2"];
        $c = $a + $b;
        
        echo "<h4 class='text-center'>Resultado: $c</h4>";
    }

    function subtracao() {
        $a = $_POST["n1"];
        $b = $_POST["n2"];
        $c = $a - $b;

        echo "<h4 class='text-center'>Resultado: $c</h4>";
    }

    function multiplicacao() {
        $a = $_POST["n1"];
        $b = $_POST["n2"];
        $c = $a * $b;

        echo "<h4 class='text-center'>Resultado: $c</h4>";
    }

    function divisao() {
        $a = $_POST["n1"];
        $b = $_POST["n2"];
        $c = $a / $b;

        echo "<h4 class='text-center'>Resultado: $c</h4>";
    }
    
    function taboada() {
        $a = $_POST["n1"];
        $b = $_POST["n2"];

        for($d = 1; $d <= $b; $d++) {
            $c = $a * $d;
            echo "<h4 class='text-center'>Taboada $a x $d: $c</h4>";
        }

    }
?>