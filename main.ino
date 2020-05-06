#include <SoftwareSerial.h>                   //importuj bibliotekę SoftwareSerial
#include <Servo.h>
 
SoftwareSerial Bluetooth(0, 1);             //Utworz instancje Bluetooth 10-RX 11-TX
int dioda = 13;                                //dioda podłączona do pinu 9. (PWM)
int BluetoothDane;                            //do zmiennej int będą zapisywane odebrane dane
int poz1;
int poz2;
int poz3;
int poz4;
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;
#define trigPin 7
#define echoPin 6
int dystans=0;

 
 
void setup() {
  Serial.begin(9600);                         //uruchom UART z prędkością 9600 baud
  Bluetooth.begin(9600);                      //uruchom SerialSoftware z prędkością 9600 baud
  Serial.println(BluetoothDane);
  Bluetooth.println("Polaczyles sie wlasnie z modulem Bluetooth HC-05");
  pinMode(dioda,OUTPUT);                      //ustaw diodę jako wyjście
  myservo1.attach(8);
  myservo2.attach(9);
  myservo3.attach(10);
  myservo4.attach(11);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
   Serial.println("Wlaczono mnie");
}
 
void loop() {

   if (Bluetooth.available()){                  //Jeśli są jakieś dane
               
   BluetoothDane=Bluetooth.read();             //przypisz zmiennej BluetoothDane odczytane dane z modułu
   Serial.println(BluetoothDane);

   switch (BluetoothDane){
    //////////KCIUK//////////
    case 49:
      {     
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono kciuk");       //wydrukuj na monitorze komunikat
            for(poz1 = 140; poz1 >= 40; poz1 -= 1){ // kciuk
            myservo1.write(poz1);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
            delay(12);
         }
      digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 50:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono kciuk");       //wydrukuj na monitorze komunikat
             for(poz1 = 40; poz1 <= 140; poz1 += 1){ // kciuk
            myservo1.write(poz1);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
            delay(12);
         }
      digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;

      //////////MALE PALCE//////////
     case 55:
      { 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono male palce");       //wydrukuj na monitorze komunikat
           for(poz2 = 40; poz2 <= 160; poz2 += 1){ // dwa male palce                              /
           myservo2.write(poz2);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
          }
         digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 56:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono male palce");       //wydrukuj na monitorze komunikat
           for(poz2 = 160; poz2 >= 40; poz2 -= 1){ // dwa male palce                              /
           myservo2.write(poz2);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
          }
       digitalWrite(dioda,LOW);               //zgaś diodę      
      }
      break;

      //////////SRODKOWY//////////
     case 53:
      { 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec srodkowy");       //wydrukuj na monitorze komunikat
        for(poz3 = 170; poz3 >= 30; poz3 -= 1){ // srodkowy palec
         myservo3.write(poz3);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
         delay(12);
        }       
       digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 54:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec srodkowy");       //wydrukuj na monitorze komunikat
         for(poz3 = 30; poz3 <= 170; poz3 += 1){ // srodkowy palec
         myservo3.write(poz3);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
         delay(12);
        }  
       digitalWrite(dioda,LOW);               //zgaś diodę      
      }
      break;

    //////////WSKAZUJACY//////////

     case 51:
      { 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec wskazujacy");       //wydrukuj na monitorze komunikat
           for(poz4 = 50; poz4 <= 180; poz4 += 1){ // obrót od 0 do 180 wskazujacy
           myservo4.write(poz4);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
          }
         digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 52:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec wskazujacy");
           for(poz4 = 180; poz4 >= 50; poz4 -= 1){ // obrót od 0 do 180 wskazujacy
           myservo4.write(poz4);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
           }
       digitalWrite(dioda,LOW);               //zgaś diodę   
      }
      break;
      case 57: //Tryb smart
      {

         
          while (BluetoothDane==57){
            Serial.print(zmierzOdleglosc());
            Serial.println(" cm");
            if(dystans<=15){
              digitalWrite(dioda,HIGH);  
                 zamknijcala(); 
                 digitalWrite(dioda,LOW);  
                 delay(10000); 
                 digitalWrite(dioda,HIGH);  
                 otworzcala();
                 digitalWrite(dioda,LOW);  
                 delay(600);
            }
            delay(500); 
            int wychodzenieZeSmart;
        wychodzenieZeSmart=Bluetooth.read();
         if(wychodzenieZeSmart!=-1){
          BluetoothDane=wychodzenieZeSmart;
         }
             Serial.println(BluetoothDane);
            }
      }
      break;
case 113:
      {     
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono kciuk");       //wydrukuj na monitorze komunikat
            for(poz1 = 140; poz1 >= 80; poz1 -= 1){ // kciuk
            myservo1.write(poz1);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
            delay(12);
         }
      digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 119:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono kciuk");       //wydrukuj na monitorze komunikat
             for(poz1 = 40; poz1 <= 80; poz1 += 1){ // kciuk
            myservo1.write(poz1);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
            delay(12);
         }
      digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;

      //////////MALE PALCE//////////
     case 117:
      { 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono male palce");       //wydrukuj na monitorze komunikat
           for(poz2 = 40; poz2 <= 100; poz2 += 1){ // dwa male palce                              /
           myservo2.write(poz2);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
          }
         digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 105:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono male palce");       //wydrukuj na monitorze komunikat
           for(poz2 = 160; poz2 >= 100; poz2 -= 1){ // dwa male palce                              /
           myservo2.write(poz2);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
          }
       digitalWrite(dioda,LOW);               //zgaś diodę      
      }
      break;

      //////////SRODKOWY//////////
     case 116:
      { 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec srodkowy");       //wydrukuj na monitorze komunikat
        for(poz3 = 170; poz3 >= 90; poz3 -= 1){ // srodkowy palec
         myservo3.write(poz3);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
         delay(12);
        }       
       digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 121:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec srodkowy");       //wydrukuj na monitorze komunikat
         for(poz3 = 30; poz3 <= 900; poz3 += 1){ // srodkowy palec
         myservo3.write(poz3);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
         delay(12);
        }  
       digitalWrite(dioda,LOW);               //zgaś diodę      
      }
      break;

    //////////WSKAZUJACY//////////

     case 101:
      { 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec wskazujacy");       //wydrukuj na monitorze komunikat
           for(poz4 = 50; poz4 <= 115; poz4 += 1){ // obrót od 0 do 180 wskazujacy
           myservo4.write(poz4);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
          }
         digitalWrite(dioda,LOW);               //zgaś diodę
      }
      break;
    case 114:
      {                 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę i uruchomiono palec wskazujacy");
           for(poz4 = 180; poz4 >= 115; poz4 -= 1){ // obrót od 0 do 180 wskazujacy
           myservo4.write(poz4);              // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
           delay(12);
           }
       digitalWrite(dioda,LOW);               //zgaś diodę   
      }
      
    default: Serial.println("nie mam informacji");
   }
  }
 
delay(100);                                   //odczekaj 100ms   
}
      


int zmierzOdleglosc() { // funkcja mierzenia odległosci
  long czas;
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
 
  return dystans;
  
}

int zamknijcala(){
      poz1=myservo1.read();
      poz2=myservo2.read();
      poz3=myservo3.read();
      poz4=myservo4.read();
  while(poz1>=40 || poz2<=160 || poz3>=30 || poz4<=180) {
  if(poz1>=40){
    poz1=poz1-1;
    myservo1.write(poz1);
  }
  if(poz2<=160){
    poz2=poz2+1;
    myservo2.write(poz2);
  }
  if(poz3>=30){
    poz3=poz3-1;
    myservo3.write(poz3);
  }
  if(poz4<=180){
    poz4=poz4+1;
    myservo4.write(poz4);
  }
    delay(10);
}
}

int otworzcala(){
      poz1=myservo1.read();
      poz2=myservo2.read();
      poz3=myservo3.read();
      poz4=myservo4.read();
    while(poz1<=140 || poz2>=40 || poz3<=170 || poz4>=50) {
  if(poz1<=140){
    poz1=poz1+1;
    myservo1.write(poz1);
  }
  if(poz2>=40){
    poz2=poz2-1;
    myservo2.write(poz2);
  }
  if(poz3<=170){
    poz3=poz3+1;
    myservo3.write(poz3);
  }
  if(poz4>=50){
    poz4=poz4-1;
    myservo4.write(poz4);
  }
  delay(10);
}
}
