#include <SPI.h>
#include <SD.h>
File myFile;
int x;

void setup() {
Serial.begin(9600);
while (!Serial) {
; // wait for serial port to connect. Needed for native USB port only
}
Serial.print("Initializing SD card...");
if (!SD.begin()) {
Serial.println("initialization failed!");
while (1);
}
Serial.println("initialization done.");

// open the file. note that only one file can be open at a time,
// so you have to close this one before opening another.
myFile = SD.open("test.csv", FILE_WRITE);
if (myFile) {
Serial.println("Writing to test.csv...");
myFile.print("Stud_ID");
myFile.print("  \t");
myFile.print("Roll no"); 
myFile.print("  \t");
myFile.println("Maths_marks");
 { for (x = 201; x < 206; x += 1)   
  
  {
  myFile.print(x);
  myFile.print("         \t");
  myFile.print(x%10);
  myFile.print("         \t");
  myFile.println(x%10+55);   
 }  
}
}
// close the file:
myFile.close();

  if (SD.exists("test.csv")) {
    Serial.println("test.csv exists.");
  } 
  else {
    Serial.println("test.csv doesn't exist.");
  }

  
  Serial.println("Removing last line...");
  SD.remove("test.csv");

 // NEW FILE AFTER REMOVING PREVIOUS  
myFile = SD.open("test1.csv", FILE_WRITE);
Serial.println("New table after removing last line");
if (SD.exists("test1.csv"))
{

if (myFile) {
Serial.print("Stud_ID");
Serial.print("  \t");
Serial.print("Roll no"); 
Serial.print("  \t");
Serial.println("Maths_marks");
 { for (x = 201; x < 205; x += 1)   
  
  {
  Serial.print(x);
  Serial.print("         \t");
  Serial.print(x%10);
  Serial.print("         \t");
  Serial.println(x%10+55);   
 } 
 } 
}
}

myFile.close();

myFile = SD.open("test1.txt");
 if (myFile) {
Serial.println("test1.txt:");

    // read from the file until there's nothing else in it:
while (myFile.available()) {
Serial.write(myFile.read());
    }
    // close the file:
 myFile.close();

  
}
}

void loop() {

}
