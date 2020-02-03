//hi here we will use arduino and gsm module to send and receive SMS. 
// this is the code 
// upload the code to arduino
// click on serial monitor
 
 #include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10);   //connect RX to pin 10 , connect TX to pin 9

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      SendMessage();             // call the function which will send sms
      break;
    case 'r':
      RecieveMessage();          // call the function which will receive sms
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}


 void SendMessage()  // function for sending sms
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+94771843336\"\r"); // Replace x with your mobile number(not the number which insert in to gsm module)
  delay(1000);
  mySerial.println("hi thushapan..I am from arduino GSM Module");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
 
