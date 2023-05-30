#include <OneWire.h>  
#include <DallasTemperature.h>
#include <SD.h>
#include <SPI.h>
#include <DHT.h>
#include <Wire.h>

#define dados1 2
#define dados2 3
#define dados3 4
#define dados4 5
#define DHTPIN 6
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
OneWire oneWire1(dados1);
OneWire oneWire2(dados2);
OneWire oneWire3(dados3);
OneWire oneWire4(dados4);  
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);
DallasTemperature sensors3(&oneWire3);
DallasTemperature sensors4(&oneWire4);
float dht22h;
float dht22t;

File myFile;
int pinoSS = 10;

void setup(void) {
 Serial.begin(9600);
 Wire.begin();
 sensors1.begin();
 sensors2.begin();
 sensors3.begin();
 sensors4.begin();
 dht.begin();
 pinMode(pinoSS, OUTPUT);
 if (SD.begin()) {
      Serial.println("SD Card pronto para uso.");
    }


    else {
      Serial.println("Falha na inicialização do SD Card.");
    return;
    }
myFile = SD.open("comp.txt", FILE_WRITE);
}


void loop(void) {
  printValues();
  delay(3600000);
}


void printValues(void) {
 dht22h = dht.readHumidity();
 dht22t = dht.readTemperature();
 sensors1.requestTemperatures();
 sensors2.requestTemperatures();
 sensors3.requestTemperatures();
 sensors4.requestTemperatures();

 myFile = SD.open("comp.txt", FILE_WRITE);
 if(myFile) {
   myFile.print("(A)      (B)      (C)      (D)      (I)      (J)      (K)      (L)      (E)      (F)      (G)      (H)      (M)      (N)      (O)      (P)      DHT      DHT");
   myFile.println();
   myFile.print(sensors1.getTempCByIndex(0));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors1.getTempCByIndex(1));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors1.getTempCByIndex(2));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors1.getTempCByIndex(3));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors2.getTempCByIndex(0));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors2.getTempCByIndex(1));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors2.getTempCByIndex(2));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors2.getTempCByIndex(3));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors3.getTempCByIndex(0));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors3.getTempCByIndex(1));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors3.getTempCByIndex(2));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors3.getTempCByIndex(3));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors4.getTempCByIndex(0));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors4.getTempCByIndex(1));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors4.getTempCByIndex(2));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(sensors4.getTempCByIndex(3));
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(dht22t);
   myFile.print("°C");
   myFile.print("  ");
   myFile.print(dht22h);
   myFile.print("%");
   myFile.print("  ");
   myFile.println();
   myFile.println();
 }
myFile.close();


myFile = SD.open("comp.txt");
  Serial.println("Conteúdo do Arquivo:");
   if (myFile) {
     while (myFile.available()) {
       Serial.write(myFile.read());
     }
   myFile.close();
   }
}
