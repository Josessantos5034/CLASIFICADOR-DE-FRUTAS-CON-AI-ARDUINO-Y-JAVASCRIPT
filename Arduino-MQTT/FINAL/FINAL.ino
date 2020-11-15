int Led = 5; // LED
// MOTOR DE LA BANDA TRANSPORTADORA
#define STEP 19      // pin STEP de A4988 a pin 4
#define DIR 18    // pin DIR de A4988 a pin 
void setup() {
  pinMode(Led, OUTPUT);
  pinMode(STEP, OUTPUT);  // pin 4 como salida
  pinMode(DIR, OUTPUT);   // pin 5 como salida
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char Letra = Serial.read();
    if (Letra == 'M') { // MANZANA
      digitalWrite(Led,1);
      digitalWrite(DIR, HIGH);    // giro en un sentido
  for(int i = 0; i < 200; i++){     // 200 pasos para motor de 0.9 grados de angulo de paso
    digitalWrite(STEP, HIGH);       // nivel alto
    delay(10);          // por 10 mseg
    digitalWrite(STEP, LOW);        // nivel bajo
    delay(10);     
    }
    delay(2000);
    }
    
   else if (Letra == 'J') { // NARANJA
      digitalWrite(Led,1);
      delay(400);
    }else if (Letra == 'P') { // PERA
      digitalWrite(Led,1);
      delay(600);
    }else if (Letra == 'N') { //NADA
      digitalWrite(Led,0);
      digitalWrite(DIR, LOW);     // giro en sentido opuesto
  for(int i = 0; i < 200; i++){
    digitalWrite(STEP, HIGH); 
    delay(10);
    digitalWrite(STEP, LOW);
    delay(10);
  }
  delay(2000); 
    }
  }
}
