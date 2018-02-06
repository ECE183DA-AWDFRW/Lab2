#include <ESP8266WiFi.h>
WiFiServer server(80); //Initialize the server on Port 80
const short int LED_PIN = 16;//GPIO16
const int trigPin = D4;  //D4
const int echoPin = D5;  //D5
// defines variables
long duration;
int distance;
int frequency; //Specified in Hz
int buzzPin=D6; 

void freePlay(int timeRemaining) {
  while (timeRemaining > 0){
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    distance = duration*0.034/2;
    // Prints the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    frequency = (-38*distance)+2038;
    tone(buzzPin, frequency);
    delay(30);
    timeRemaining = timeRemaining - 30;
  }
}

void setup() {
  WiFi.mode(WIFI_AP); //Our ESP8266-12E is an AccessPoint
  WiFi.softAP("WhyDunWork", "asdf"); // Provide the (SSID, password); .
  server.begin(); // Start the HTTP Server
  //Looking under the hood
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200);
  IPAddress HTTPS_ServerIP= WiFi.softAPIP(); // Obtain the IP of the Server
  Serial.print("Server IP is: "); // Print the IP to the monitor window
  Serial.println(HTTPS_ServerIP);
  pinMode(LED_PIN, OUTPUT); //GPIO16 is an OUTPUT pin;
  digitalWrite(LED_PIN, HIGH); //Initial state is OFF
}


void loop() {
   noTone(buzzPin);
   digitalWrite(LED_PIN, HIGH);
   WiFiClient client = server.available();
   if (!client) {
     return; 
   }
   //Looking under the hood
   Serial.println("Somebody has connected :)");
   //Read what the browser has sent into a String class
   //and print the request to the monitor
   String request = client.readStringUntil('/r');
   //Looking under the hood
   Serial.println("Request Is: ");
   Serial.println(request);
   // Handle the Request

   //Play for 10s based off distance
   if (request.indexOf("/10") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     freePlay(5000);
     noTone(buzzPin); 
   }
   //Play for 20s based off distance
   else if (request.indexOf("/20") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     freePlay(20000);
     noTone(buzzPin); 
   }
   //Play for 30s based off distance
   else if (request.indexOf("/30") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     freePlay(30000);
     noTone(buzzPin); 
   }
   //Play a note
   else if (request.indexOf("/C") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     tone(buzzPin, 523, 1000);
   }
   else if (request.indexOf("/D") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     tone(buzzPin, 587, 1000);
   }
   else if (request.indexOf("/E") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     tone(buzzPin, 659, 1000);
   }
   else if (request.indexOf("/F") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     tone(buzzPin, 698, 1000);
   }
   else if (request.indexOf("/G") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     tone(buzzPin, 784, 1000);
   }
   else if (request.indexOf("/A") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     tone(buzzPin, 880);
   }
   else if (request.indexOf("/B") != -1){
     noTone(buzzPin);
     digitalWrite(LED_PIN, LOW);
     tone(buzzPin, 988, 1000);
   }
   delay(1000);
   noTone(buzzPin); 
   // Prepare the HTML document to respond and add buttons:
   String s = "HTTP/1.1 200 OK\r\n";
   s += "Content-Type: text/html\r\n\r\n";
   s += "<!DOCTYPE HTML>\r\n<html>\r\n";
   s += "<br><h1>What Do I Do</h1><br>";
   s += "<br><input type=\"button\" name=\"b1\" value=\"10s\" onclick=\"location.href='/10'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"20s\" onclick=\"location.href='/20'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"30s\" onclick=\"location.href='/30'\">&nbsp";
   s += "<br><input type=\"button\" name=\"b1\" value=\"C\" onclick=\"location.href='/C'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"D\" onclick=\"location.href='/D'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"E\" onclick=\"location.href='/E'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"F\" onclick=\"location.href='/F'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"G\" onclick=\"location.href='/G'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"A\" onclick=\"location.href='/A'\">&nbsp";
   s += "<input type=\"button\" name=\"b1\" value=\"B\" onclick=\"location.href='/B'\">&nbsp";
   s += "<br><br><br> </html>\n";
   //Serve the HTML document to the browser.
   client.flush(); //clear previous info in the stream
   client.print(s); // Send the response to the client
   delay(1);
   Serial.println("Client disonnected"); //Looking under the hood
}
