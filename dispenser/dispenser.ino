#define SERVO_PIN    PA0 // Pin del servo motor
#define BUZZER_PIN   PA10 // Pin para generar la señal de 1 kHz
//#define BT_RX_PIN    PA2 // Pin RX del módulo Bluetooth HC-05
//#define BT_TX_PIN    PA3 // Pin TX del módulo Bluetooth HC-05
#define SENSOR_PIN   PA1
#define LED1_PIN     PC13

bool sensorProximidadActivado = false;
int activaciones = 0;
char str [128];

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);  
  pinMode(SERVO_PIN, OUTPUT);  
  digitalWrite(LED1_PIN, HIGH);  
  Serial2.begin(9600);
  beep();
  delay(2000);
}
 
void loop() {
  if(sensorActivado()) {
    if (!sensorProximidadActivado) {
      sensorProximidadActivado = true;
      activaciones++;
      bleep();
      sprintf(str, "Dispenser activado %d veces", activaciones);
      Serial2.println(str);
      moveServo();
      playPacmanMusic();
      while(sensorActivado()) {
        delay(500);
      }
    }
  } else {
    sensorProximidadActivado = false;
  }
}

void bleep() {
      digitalWrite(LED1_PIN, LOW);  
      beep();
      digitalWrite(LED1_PIN, HIGH);  
      beep();
      digitalWrite(LED1_PIN, LOW);  
      beep();
      digitalWrite(LED1_PIN, HIGH);  
}

void moveServo(){
      servo(1);
      delay(200);
      servo(0);
}

void playPacmanMusic()
{
  tone(BUZZER_PIN, 493, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 987, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 739, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 622, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 987, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 739, 70.75475);
    delay(70.75475);
    delay(141.5095);
    tone(BUZZER_PIN, 622, 212.26425);
    delay(212.26425);
    delay(70.75475);
    tone(BUZZER_PIN, 523, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 1046, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 783, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 659, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 1046, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 783, 70.75475);
    delay(70.75475);
    delay(141.5095);
    tone(BUZZER_PIN, 659, 212.26425);
    delay(212.26425);
    delay(70.75475);
    tone(BUZZER_PIN, 493, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 987, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 739, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 622, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 987, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 739, 70.75475);
    delay(70.75475);
    delay(141.5095);
    tone(BUZZER_PIN, 622, 212.26425);
    delay(212.26425);
    delay(70.75475);
    tone(BUZZER_PIN, 622, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 659, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 698, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 698, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 739, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 783, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 783, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 830, 70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 880, 70.75475);
    delay(70.75475);
    delay(70.75475);
    tone(BUZZER_PIN, 987, 141.5095);
    delay(141.5095);
    delay(800);
}

void beep() {
  int i;
  for(i = 0; i < 50; i++){
     digitalWrite(BUZZER_PIN, LOW);   
     delayMicroseconds(125);
     digitalWrite(BUZZER_PIN, HIGH);   
     delayMicroseconds(125);
  }
  for(i = 0; i < 50; i++){
     digitalWrite(BUZZER_PIN, LOW);   
     delayMicroseconds(250);
     digitalWrite(BUZZER_PIN, HIGH);   
     delayMicroseconds(250);
  }
  for(i = 0; i < 50; i++){
     digitalWrite(BUZZER_PIN, LOW);   
     delayMicroseconds(125);
     digitalWrite(BUZZER_PIN, HIGH);   
     delayMicroseconds(125);
  }
}

void servo(int pos) {
  if(0 == pos) {
    for(int i=0; i<50; i++) {
      digitalWrite(SERVO_PIN, HIGH);
      delayMicroseconds(500);
      digitalWrite(SERVO_PIN, LOW);
      delayMicroseconds(19500);
    }
  } else {
    for(int i=0; i<50; i++) {
      digitalWrite(SERVO_PIN, HIGH);
      delayMicroseconds(2500);
      digitalWrite(SERVO_PIN, LOW);
      delayMicroseconds(17500);
    }
  }
}

int sensorActivado() {
  int i = 0;
  return !digitalRead(SENSOR_PIN);
}
