<?php
	
	date_default_timezone_set('Mexico/General');
	$hora=date('h:m:s');
	include 'conexion.php';
	
	$sql = mysqli_query($cx,"SELECT * FROM temperatura WHERE 1");		
	while($row=mysqli_fetch_row($sql)){
		$temd=$row[1];
		$temt=$row[2];
		$hum= $row[3];
		//echo "Son las $hora HRS y la Temperatura es de: $tem  °C  </td>";
				
			
	}
?>

<table>
	<tr><td colspan="3">Hora : <?php echo $hora; ?></td></tr>
	<tr><td colspan="2" class="dh">DHT11</td><td class="te">Thermistor</td></tr>
	<tr><td colspan="2" class="dh"><img src=/imagenes/dht11.png></td><td class="te"><img src=/imagenes/thermistor.png></td></tr>
	<tr><td class="dh">Humedad</td><td class="dh">Temp1</td><td class="te">Temp2</td></tr>
	<tr><td class="dh"><?php echo $hum; ?> %</td><td class="dh"><?php echo $temd; ?> c°</td><td class="te"><?php echo $temt; ?> c°</td></tr>
</table>