#include<ESP8266WiFi.h>
#include<ESP8266WebServer.h>

ESP8266WebServer server;

char* ssid = "Ultimate Hacker";
char* password = "crompton";


// All alphabets will be a matrix of 3x5
int _[] = {0,0,0,0,0, 0,0,0,0,0, 0,0,0,0,0};
int A[] = {0,1,1,1,1, 1,0,1,0,0, 0,1,1,1,1};
int B[] = {1,1,1,1,1, 1,0,1,0,1, 0,1,0,1,0};
int C[] = {0,1,1,1,0, 1,0,0,0,1, 1,0,0,0,1};
int D[] = {1,1,1,1,1, 1,0,0,0,1, 0,1,1,1,0};
int E[] = {1,1,1,1,1, 1,0,1,0,1, 1,0,1,0,1};
int F[] = {1,1,1,1,1, 1,0,1,0,0, 1,0,1,0,0};
int G[] = {0,1,1,1,0, 1,0,1,0,1, 0,0,1,1,0};
int H[] = {1,1,1,1,1, 0,0,1,0,0, 1,1,1,1,1};
int I[] = {0,0,0,0,1, 1,0,1,1,1, 0,0,0,0,1};
int J[] = {1,0,0,0,0, 1,0,0,0,1, 1,1,1,1,1};
int K[] = {1,1,1,1,1, 0,0,1,0,0, 0,1,0,1,1};
int L[] = {1,1,1,1,1, 0,0,0,0,1, 0,0,0,0,1};
int M[] = {1,1,1,1,1, 0,1,1,0,0, 0,1,1,1,1};
int N[] = {1,1,1,1,1, 1,0,0,0,0, 0,1,1,1,1};
int O[] = {0,1,1,1,0, 1,0,0,0,1, 0,1,1,1,0};
int P[] = {1,1,1,1,1, 1,0,1,0,0, 0,1,0,0,0};
int Q[] = {0,1,1,1,1, 1,0,0,1,1, 0,1,1,1,1};
int R[] = {1,1,1,1,1, 1,0,1,0,0, 0,1,0,1,1};
int S[] = {0,1,0,0,1, 1,0,1,0,1, 1,0,0,1,0};
int T[] = {1,0,0,0,0, 1,1,1,1,1, 1,0,0,0,0};
int U[] = {1,1,1,1,1, 0,0,0,0,1, 1,1,1,1,1};
int V[] = {1,1,1,1,0, 0,0,0,0,1, 1,1,1,1,0};
int W[] = {1,1,1,1,0, 0,0,1,1,0, 1,1,1,1,0};
int X[] = {1,1,0,1,1, 0,0,1,0,0, 1,1,0,1,1};
int Y[] = {1,1,0,0,0, 0,0,1,0,0, 1,1,1,1,1};
int Z[] = {1,0,0,1,1, 1,0,1,0,1, 1,1,0,0,1};
int letterSpace;
int dotTime;

char text[] = "PROJECT___";


// Setup function for Arduino
void setup()
{
  // Setting the ports of the leds to OUTPUT
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
 
  // Defining the space between the letters (ms)
  letterSpace = 4;
  // Defining the time dots appear (ms)
  dotTime = 2;

  
 WiFi.begin(ssid, password);
//Serial.begin(115200);

// Connecting to Wi-Fi
while(WiFi.status() != WL_CONNECTED){
  //Serial.print(".");
  delay(500);
  }

// Printing IP Address once connected
  //Serial.println("");
  //Serial.print("IP Address ");
  //Serial.print(WiFi.localIP());

  // Server setup
  server.on("/", toggleLED);
  server.begin();
  //Serial.println("Server started");
}




// Function to display a letter
void displayLetter(int letter[])
{
  int y;
 
  // Printing the first y column of the letter
  for (y=0; y<5; y++)
  {
    digitalWrite(y+1, letter[y+10]);
  }
  delay(dotTime);
 
  // Printing the second y column of the letter
  for (y=0; y<5; y++)
  {
    digitalWrite(y+1, letter[y+5]);
  }
  delay(dotTime);
 
  // Printing the third y column of the letter
  for (y=0; y<5; y++)
  {
    digitalWrite(y+1, letter[y]);
  }
  delay(dotTime);
 
  // Printing the space between the letters
  for (y=0; y<5; y++)
  {
    digitalWrite(y+1, 0);
  }
  delay(letterSpace);
}




// Loop Function of Arduino
void loop()
{
  // Print text here
  server.handleClient(); 
 displayText(text);
 //Serial.println("Loop  ");
 //Serial.println(text);
  
}




// Function to toggle LED
void toggleLED(){
  server.send(200, "text/plain", "LED toggled");
  String msg = server.arg("msg");
  //Serial.println(msg);
  strcpy(text, msg.c_str());
  //Serial.println("TL ");
  //Serial.println(text);
  //digitalWrite(pinLED, !digitalRead(pinLED));
  server.send(204, "");
  }





// Function to display Text
void displayText(char str[])
{
    int len = strlen(str); // define str[] length
    int i;
    for(i = len-1; i>=0; i--)
    {
  
        switch((int)str[i]){

          case 95: displayLetter(_); break;
          case 65: displayLetter(A); break;
          case 66: displayLetter(B);break;
          case 67: displayLetter(C);break;
          case 68: displayLetter(D);break;
          case 69: displayLetter(E);break;
          case 70: displayLetter(F);break;
          case 71: displayLetter(G);break;
          case 72: displayLetter(H);break;
          case 73: displayLetter(I);break;
          case 74: displayLetter(J);break;
          case 75: displayLetter(K);break;
          case 76: displayLetter(L);break;
          case 77: displayLetter(M);break;
          case 78: displayLetter(N);break;
          case 79: displayLetter(O);break;
          case 80: displayLetter(P);break;
          case 81: displayLetter(Q);break;
          case 82: displayLetter(R);break;
          case 83: displayLetter(S);break;
          case 84: displayLetter(T);break;
          case 85: displayLetter(U);break;
          case 86: displayLetter(V);break;
          case 87: displayLetter(W);break;
          case 88: displayLetter(X);break;
          case 89: displayLetter(Y);break;
          case 90: displayLetter(Z);break;
    
          
          }
          
    }     
}
