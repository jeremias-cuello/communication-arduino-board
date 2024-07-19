#define PIN_RED 3
#define PIN_GREEN 2

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RED, OUTPUT);
  pinMode(PIN_GREEN, OUTPUT);
}

void loop() {

  String receivedData;

  if(Serial.available() > 0){
    receivedData = Serial.readStringUntil('\n');;

    Serial.println("Un mesaje con endLine"); // sera el primero en leer
    if(receivedData.equalsIgnoreCase("ON")){
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, HIGH);
      Serial.println("Encendido.");
    }else if(receivedData.equalsIgnoreCase("OFF")){
      digitalWrite(PIN_RED, HIGH);
      digitalWrite(PIN_GREEN, LOW);
      Serial.println("Apagado.");
    } else if(receivedData.equalsIgnoreCase("DISABLE")){
      digitalWrite(PIN_RED, LOW);
      digitalWrite(PIN_GREEN, LOW);
      Serial.println("Desactivado.");
    } else{
      Serial.println("--- ERROR ---");
    }

    Serial.println("FIN");
  }
}
