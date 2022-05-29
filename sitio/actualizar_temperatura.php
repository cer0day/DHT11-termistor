<?php   
    
    // Si se recibe Datos con el Método GET, los procesamos
    if (isset($_GET['temd']) && isset($_GET['temt'])&& isset($_GET['hum'])){
        $temd = $_GET['temd'];
        $temt = $_GET['temt'];
        $hum = $_GET['hum'];
        
        include 'conexion.php';
        mysqli_query ($cx, "UPDATE temperatura SET temd=$temd, temt=$temt, hum=$hum");
     }
?>