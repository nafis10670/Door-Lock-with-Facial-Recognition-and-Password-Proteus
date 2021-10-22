#include <LiquidCrystal.h>
#include <Servo.h>
#include <Keypad.h>

Servo myservo;
const int led = 11;
const int alarm_led = 12;
int data = 0;
int servo_pos = 0;
int alarm_count = 0;
int flag = 0;
const int max_password = 4;
char my_password[max_password] = "";
LiquidCrystal lcd(A4, A5, A3, A2, A1, A0);
const byte rows=4;
const byte cols=3;

char key[rows][cols]={
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[rows]={2,3,4,5};
byte colPins[cols]={6,7,8};
Keypad keypad= Keypad(makeKeymap(key),rowPins,colPins,rows,cols);
char* password="0123"; //Setting the password
int currentposition=0; //Position of LCD Cursor

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(alarm_led, OUTPUT);
  myservo.attach(9);
  digitalWrite (led, LOW);
  digitalWrite(alarm_led, LOW);
  Serial.begin(9600);
  Serial.println("Connection Established!");
  DisplayScreen();
  lcd.begin(16,2);
}

void loop(){
  int l;
  char code = keypad.getKey();
  
  if(currentposition == 0){
    DisplayScreen();
  }
  
  if(Serial.available() > 0)
  {
    data = Serial.read();
  }
  
  if (flag == 0 && data == '1')
  {
    OpenDoor();
    flag = 1;
  }
  else if (data == '0')
  {
    digitalWrite (led, LOW);
    flag = 0;
  }

  if(code!=NO_KEY){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PASSWORD:");
    lcd.setCursor(7,1);
    lcd.print(" ");
    lcd.setCursor(7,1);

    for(currentposition=0;currentposition<=max_password;++currentposition){
      lcd.print("*");
      my_password[currentposition] = code;        
    }

    if(my_password == password){
      OpenDoor();
      my_password[0] = "\0";
    }

    else{
      alarm_count++;
      my_password[0] = "\0";
      if(alarm_count >= 3){
        Ring_Alarm();
      }
      else{
        incorrect();  
      }
      
      //currentposition = 0;
    }
  }
}

void DisplayScreen(){
  lcd.setCursor(0,0);
  lcd.println(" ENTER CODE OR");
  lcd.setCursor(0,1); 
  lcd.println("FACE RECOGNITION");
}

void OpenDoor(){
  delay(900);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.println(" Access Granted");
  
  digitalWrite (led, HIGH);
    
  for(servo_pos = 0; servo_pos <= 90; servo_pos += 1){
    myservo.write(servo_pos);
    delay(20);   
  }
    
  delay(3000);
    
  for(servo_pos = 90; servo_pos >= 0; servo_pos -= 1){
    myservo.write(servo_pos);
    delay(20);
  }
  digitalWrite(led, LOW);
}

void incorrect()
{
  delay(500);
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("CODE");
  lcd.setCursor(6,0);
  lcd.print("INCORRECT");
  lcd.setCursor(15,1);
  lcd.println(" ");
  lcd.setCursor(4,1);
  lcd.println("NO ACCESS");
   
  lcd.setCursor(13,1);
  lcd.println(" ");
  Serial.println("CODE INCORRECT YOU ARE UNAUTHORIZED");
  delay(3000);
  lcd.clear();
  DisplayScreen();
}



void SerialFlush(){
  while(Serial.available() > 0){
    char t = Serial.read();
  }
}

void Ring_Alarm(){
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("SOUNDING ALARM ");
  
  digitalWrite(alarm_led, HIGH);
  delay(500);
  digitalWrite(alarm_led, LOW);
  delay(500);
  digitalWrite(alarm_led, HIGH);
  delay(500);
  digitalWrite(alarm_led, LOW);
  delay(500);
  digitalWrite(alarm_led, HIGH);
  delay(500);
  digitalWrite(alarm_led, LOW);
  delay(500);
  DisplayScreen();
  alarm_count = 0;
}
