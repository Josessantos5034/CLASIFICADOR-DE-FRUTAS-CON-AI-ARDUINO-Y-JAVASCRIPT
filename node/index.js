
let BrokerMQTT = 'mqtt://broker.shiftr.io';
let PuertoMQTT = 1883;
let ClienteIDMQTT = "MQTT-Nodejs";
let UsuarioMQTT = "joseluis5034";
let ContrasenaMQTT = "robotica2020";

const SerialPort = require('serialport');
const port = new SerialPort("COM3", {
  baudRate: 921600
})

let Opciones = {
  port: PuertoMQTT,
  clientId: ClienteIDMQTT,
  username: UsuarioMQTT,
  password: ContrasenaMQTT
}

var mqtt = require('mqtt')
var client = mqtt.connect(BrokerMQTT, Opciones);

client.on('connect', function() {
  client.subscribe('/Proyecto/CLASIFICAR', function(err) {
    console.log("MQTT Activado")
  })
})

client.on('message', function(topic, message) {
  let Mensaje = message.toString();
  if (Mensaje == "MANZANA") {
    console.log("manzana")
    port.write("M");
  } else if (Mensaje == "NARANJA") {
    console.log("naranja")
    port.write("J");
  }else if (Mensaje == "PERA") {
    console.log("pera")
    port.write("P");
  }
})
