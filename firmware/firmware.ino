
#include <WiFi.h>
#include <HTTPClient.h>

#define TRIGGER_PIN 13     
#define ECHO_PIN 12        
#define BUTTON_PIN 22  

const int PIN_PIR = 23;

const char* ssid = "<WIFI-SSID>";          // Substitua pelo seu SSID
const char* password = "<WIFI-PASSWORD";     // Substitua pela sua senha Wi-Fi

const char* serverUrl = "<SERVER-URL>"; // URL do servidor (exemplo)

long duration;             
int distancia;             
int contador = 0;     

void setup() {
  Serial.begin(115200);
  pinMode(TRIGGER_PIN, OUTPUT);    
  pinMode(ECHO_PIN, INPUT);        
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  
  Serial.println("Sistema de Monitoramento de Dispenser Iniciado");
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");

  pinMode(PIN_PIR, INPUT);
  Serial.print("Sensor de movimento: ok\n");
}

void registrar_evento() {
  String jsonStr = "{\"evento\":\"higienizacao\"}";

  HTTPClient http;
  http.begin(serverUrl);

  // Define o tipo de conteúdo como JSON
  http.addHeader("Content-Type", "application/json");

  // Envia a requisição POST com o JSON
  int httpResponseCode = http.POST(jsonStr);

  // Verifica o código de resposta HTTP
  if (httpResponseCode > 0) {
    Serial.print("Código de resposta HTTP: ");
    Serial.println(httpResponseCode);
    String response = http.getString();
    Serial.println("Resposta do servidor:");
    Serial.println(response);
  } else {
    Serial.print("Erro ao enviar requisição. Código: ");
    Serial.println(httpResponseCode);
  }

  // Finaliza a requisição
  http.end();
}

void loop() {
  // Gera um pulso de 10 microssegundos no pino Trigger para iniciar a medição
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distancia = duration * 0.034 / 2;

  Serial.print("Distancia registrada: ");
  Serial.println(distancia);

  bool estaNaDistancia = distancia > 0 && distancia <= 20;
  bool haMovimento = digitalRead(PIN_PIR) == HIGH;

  if (estaNaDistancia && haMovimento) {
    Serial.println("Pessoa detectada próxima ao dispenser");

    if (digitalRead(BUTTON_PIN) == LOW) {
      delay(50); // debounce 
      
      if (digitalRead(BUTTON_PIN) == LOW) {
        contador++;
        
        Serial.print("Dispenser utilizado. Total de usos: ");
        Serial.println(contador);

        registrar_evento();
        
        while (digitalRead(BUTTON_PIN) == LOW);
      }
    }
  }

  delay(100);
}
