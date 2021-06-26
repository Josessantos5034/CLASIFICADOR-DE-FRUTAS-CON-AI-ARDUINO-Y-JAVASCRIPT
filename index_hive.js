let BrokerMQTT = '96bbf8b5e7e94b3bb8ced4ebbf367e63.s1.eu.hivemq.cloud';
let PuertoMQTT = 8883;
let ClienteIDMQTT = "MQTT-P5";
let UsuarioMQTT = "JC5034";
let ContrasenaMQTT = "uTEC2021";
let Opciones = {
    host: BrokerMQTT,
    port: PuertoMQTT,
    protocol: 'mqtts',
    clientId: ClienteIDMQTT,
    username: UsuarioMQTT,
    password: ContrasenaMQTT
  };
var mqtt = require('mqtt');
var client  = mqtt.connect(BrokerMQTT, Opciones);

client.on('connect', function () {
  client.subscribe('proyecto/clasificar', function (err) {
    console.log('MQTT Activado')
  })
})

client.on('message', function (topic, message) {
  // message is Buffer
  console.log(message.toString())
})
