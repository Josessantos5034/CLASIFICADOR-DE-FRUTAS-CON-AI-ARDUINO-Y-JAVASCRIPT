#define posicion_manzana 0
#define posicion_naranja 120
#define posicion_pera 240

int GradoActual = 0;
int GradoDeseado = 0;

const int P_Step = 19;
const int P_Dir = 18;
const int led_estado = 5;
const int led_pera = 3;
const int led_naranja = 2;
const int led_manzana = 6;
void setup() {
  pinMode(P_Step, OUTPUT);
  pinMode(P_Dir, OUTPUT);
  pinMode(led_estado, OUTPUT);
  digitalWrite(led_estado, 1);
  Serial.begin(9600);
}

void loop() {
  DetectarMensaje();
  ActualizarPosicionMotores();
}

void ActualizarPosicionMotores() {

  Serial.print(GradoActual);
  Serial.print("-");
  Serial.print(GradoDeseado);
  Serial.println();
  if (GradoActual < GradoDeseado) {
    SubirGrado();

  }
  else if ( GradoActual > GradoDeseado) {
    BajarGrado();

  }

}

void SubirGrado() {
  Serial.println("Moviendo Abajo");
  GradoActual++;

}

void BajarGrado() {
  Serial.println("Moviendo Abajo");
  GradoActual--;

}

void DetectarMensaje() {
  if (Serial.available()) {
    char Letra = Serial.read();
    digitalWrite(led_estado, 0);
    if (Letra == 'M') {
      GradoDeseado = posicion_manzana;
      Serial.println("Cambiando a Manzana");
      digitalWrite(P_Dir, HIGH);
      for (int i = 0; i < posicion_manzana ; i++) {
        digitalWrite(P_Step, HIGH);
        delay(10);
        digitalWrite(P_Step, LOW);
        delay(10);
      }
      delay(2000);
    } else if (Letra == 'J') {
      GradoDeseado = posicion_naranja;
      Serial.println("Cambiando a Naranja");
      digitalWrite(P_Dir, HIGH);
      for (int i = 0; i < posicion_naranja ; i++) {
        digitalWrite(P_Step, HIGH);
        delay(10);
        digitalWrite(P_Step, LOW);        
        delay(10);
      }
      delay(2000);
    } else if (Letra == 'P') {
      GradoDeseado = posicion_pera;
      Serial.println("Cambiando a Pera");
      digitalWrite(P_Dir, HIGH);
      for (int i = 0; i < posicion_pera ; i++) {
        digitalWrite(P_Step, HIGH);
        delay(10);
        digitalWrite(P_Step, LOW);
        delay(10);
      }
      delay(2000);
    }
    digitalWrite(led_estado, 1);
  }
}
