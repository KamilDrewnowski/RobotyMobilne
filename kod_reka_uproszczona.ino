#include <SoftwareSerial.h>                   //importuj bibliotekę SoftwareSerial
 
SoftwareSerial Bluetooth(0, 1);             //Utworz instancje Bluetooth 10-RX 11-TX
int dioda = 13;                                //dioda podłączona do pinu 9. (PWM)
int BluetoothDane;                            //do zmiennej int będą zapisywane odebrane dane
 
 
void setup() {
 
  Serial.begin(9600);                         //uruchom UART z prędkością 9600 baud
  Bluetooth.begin(9600);                      //uruchom SerialSoftware z prędkością 9600 baud
  Serial.println(BluetoothDane);
  Bluetooth.println("Polaczyles sie wlasnie z modulem Bluetooth HC-05");
  pinMode(dioda,OUTPUT);                      //ustaw diodę jako wyjście
 
}
 
void loop() {
   if (Bluetooth.available())                  //Jeśli są jakieś dane
  {             
   
   BluetoothDane=Bluetooth.read();             //przypisz zmiennej BluetoothDane odczytane dane z modułu
    Serial.println(BluetoothDane);


   \\\\\\\\\\\\\\\\PALEC 1\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   if(BluetoothDane==49)                      //jeżeli odebrane dane to 1
      { 
       digitalWrite(dioda,HIGH);               //zapal diodę
       Serial.println("Zapalano diodę");       //wydrukuj na monitorze komunikat
      }
  
   if(BluetoothDane==50)                      //jeżeli odebrane dane to 0
      {                 
       digitalWrite(dioda,LOW);                  //zgaś diodę
       Serial.println("Zgaszono diodę");    //wydrukuj na monitorze komunikat      
      }


  \\\\\\\\\\\\\\\\PALEC 2\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   if(BluetoothDane==51)                      //jeżeli odebrane dane to 2
      {                
       digitalWrite(dioda,HIGH);                  //ustaw wartość PWM na 25%
       Serial.println("Zapalono diodę");
      }
     
   if(BluetoothDane==52)                      //jeżeli odebrane dane to 5
      {
       digitalWrite(dioda,LOW);                 //ustaw wartość PWM na 50%
       Serial.println("Zgaszono diodę");
      }


      \\\\\\\\\\\\\\\\PALEC 3\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
   if(BluetoothDane==53)                     //jeżeli odebrane dane to 7
      {
        digitalWrite(dioda,HIGH);
       Serial.println("Zapalano diodę");
      }
     
   if(BluetoothDane==54)                     //jeżeli odebrane dane to 9
      {
       digitalWrite(dioda,LOW);                //ustaw wartość PWM na 100%
       Serial.println("Zgaszono diodę");
      }


      \\\\\\\\\\\\\\\\PALEC 4\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
    if(BluetoothDane==55)                     //jeżeli odebrane dane to 7
      {
        digitalWrite(dioda,HIGH);
       Serial.println("Zapalano diodę");
      }
     
   if(BluetoothDane==56)                     //jeżeli odebrane dane to 9
      {
       digitalWrite(dioda,LOW);                //ustaw wartość PWM na 100%
       Serial.println("Zgaszono diodę");
      }


 
  }
 
delay(100);                                   //odczekaj 100ms   
}
