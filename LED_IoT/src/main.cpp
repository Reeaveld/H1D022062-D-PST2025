#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "hidup_jokowi"; // Replace with your network SSID
const char* password = "00000000"; // Replace with your network password

ESP8266WebServer server(80); // Create a web server on port 80
String webpage;

void setup() {
  Serial.begin(9600); // Start the serial communication
  delay(10); 

  pinMode(D0, OUTPUT); // Initialize the LED pin as an output
  pinMode(D1, OUTPUT); // Initialize the LED pin as an output
  pinMode(D2, OUTPUT); // Initialize the LED pin as an output

  // Konek ke Wi-Fi

  Serial.println();
  Serial.println("Konfigurasi akses poin...");

  // Mengatur Wi-fI

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password); // Start the access point with the given SSID and password

  // Cek status koneksi Wi-Fi
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP()); // Print the IP address of the access point

  // Isi dari Webpage
  webpage+= "<h1>Web Control ESP8266</h1>";
  webpage+= "<h2>Rifqi Alrasid</h2>";
  webpage+= "<p>LED 1: ";
  webpage+= "<a href=\"LED1ON\"\"><button>ON</button></a><a href=\"LED1OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 2: ";
  webpage+= "<a href=\"LED2ON\"\"><button>ON</button></a><a href=\"LED2OFF\"\"><button>OFF</button></a></p><br>";
  webpage+= "<p>LED 3: ";
  webpage+= "<a href=\"LED3ON\"\"><button>ON</button></a><a href=\"LED3OFF\"\"><button>OFF</button></a></p>";

  // Membuat tampilan webpage
  server.on("/", []() {
    server.send(200, "text/html", webpage); // Send the webpage to the client
  });

  // Bagian ini untuk merespon perintah yang masuk
  server.on("/LED1ON", []() {
    server.send(200, "text/html", webpage); // Send the webpage to the client
    digitalWrite(D0, HIGH); // Turn on LED 1
    delay(1000);
  });
  server.on("/LED2ON", []() {
    server.send(200, "text/html", webpage); // Send the webpage to the client
    digitalWrite(D1, HIGH); // Turn on LED 1
    delay(1000);
  });
  server.on("/LED3ON", []() {
    server.send(200, "text/html", webpage); // Send the webpage to the client
    digitalWrite(D2, HIGH); // Turn on LED 1
    delay(1000);
  });
  server.on("/LED1OFF", []() {
    server.send(200, "text/html", webpage); // Send the webpage to the client
    digitalWrite(D0, LOW); // Turn on LED 1
    delay(1000);
  });
  server.on("/LED2OFF", []() {
    server.send(200, "text/html", webpage); // Send the webpage to the client
    digitalWrite(D1, LOW); // Turn on LED 1
    delay(1000);
  });
  server.on("/LED3OFF", []() {
    server.send(200, "text/html", webpage); // Send the webpage to the client
    digitalWrite(D2, LOW); // Turn on LED 1
    delay(1000);
  });

  server.begin(); // Start the server
  Serial.println("Webserver dijalankan"); // Print a message indicating the server has started
}

void loop() {
  // put your main code here, to run repeatedly:
  
  server.handleClient(); // Handle incoming client requests m
}