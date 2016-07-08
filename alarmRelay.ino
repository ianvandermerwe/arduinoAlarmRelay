//INPUT
int motionSensor = A0;
int button = A1;

//OUTPUT
int alarm = 6;
int relay = 7;
int led = 5;

//STATES
int alarmState = 0;
int alarmActive = 0;

void setup() {
  pinMode(motionSensor,INPUT);
  pinMode(relay,OUTPUT);
  pinMode(alarm,OUTPUT);
  pinMode(button,INPUT_PULLUP);
}

void loop() {
  if(digitalRead(button)==LOW) // WATCH FOR BUTTON PRESS
  {
    //INSTANTLY KILL ALARM ON PRESS
    analogWrite(alarm,0);
    digitalWrite(relay,LOW);
    ledFlash();
    
    if(alarmActive == 0)
    {
      delay(10000);
      alarmActive = 1;
    }
    else
    {
      alarmActive = 0;
    }
    
    alarmState = 0;
  }
  
  //--------------
  //ACTIVATE ALARM
  //--------------
  if(alarmActive == 0)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
  //--------------
  //ACTIVATE ALARM
  //--------------

  //STATE TOGGLE OPEN
  if(alarmActive == 1)
  {
    if(digitalRead(motionSensor) == HIGH)
    {
      alarmState = 1;
    }
  }
  //STATE TOGGLE CLOSE

  //RELAY OPEN
  if(alarmState == 1)
  {
    analogWrite(alarm,200);
    delay(100);
    analogWrite(alarm,300);
    delay(100);
    analogWrite(alarm,200);
    
    digitalWrite(relay,HIGH);
  }
  else
  {
    analogWrite(alarm,0);
    digitalWrite(relay,LOW);
  }
  //RELAY CLOSE
}

void ledFlash()
{
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
  digitalWrite(led,HIGH);
  delay(200);
  digitalWrite(led,LOW);
  delay(200);
  digitalWrite(led,HIGH);
}


