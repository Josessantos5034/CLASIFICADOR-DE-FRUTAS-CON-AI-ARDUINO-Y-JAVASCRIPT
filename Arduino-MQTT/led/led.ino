int Led = 5; // LED
// MOTOR DE LA BANDA TRANSPORTADORA
int in1 = 12;  // Pin que controla el sentido de giro Motor A 
int in2 = 13;  // Pin que controla el sentido de giro Motor A 
void setup() {
  pinMode(Led, OUTPUT);
  pinMode(in1, OUTPUT);    // Configura  los pines como salida
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char Letra = Serial.read();
    if (Letra == 'M') { // MANZANA
      digitalWrite(Led,1);
      digitalWrite(in1, 1);  
      digitalWrite(in2, 0);
      delay(200); // SE MOVERA ...
    }
    else if (Letra == 'J') { // NARANJA
      digitalWrite(Led,1);
      digitalWrite(in1, 1); 
      digitalWrite(in2, 0);
      delay(400);
    }else if (Letra == 'P') { // PERA
      digitalWrite(Led,1);
      digitalWrite(in1, 1);
      digitalWrite(in2, 0);
      delay(600);
    }else if (Letra == 'N') { //NADA
      digitalWrite(Led,0);
      digitalWrite(in1,0); 
      digitalWrite(in2,0);
    }
  }
}
