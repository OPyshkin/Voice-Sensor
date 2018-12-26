const int micPin0 = A0;
const int vibrOut1 = 2;
const int vibrOut2 = 3;
const int vibrOut3 = 4;
int counter = 0;
int arr[25];
long sum=0;
const int SILENT= 150;
const int MID = 350;
void setup() {
Serial.begin(115200);
pinMode(vibrOut1, OUTPUT);
pinMode(vibrOut2, OUTPUT);
pinMode(vibrOut3, OUTPUT);
pinMode(micPin0, INPUT);


}

void loop() 
{
  for ( int i =0;i <300; i++)
  {
  
  
  int mic0 =1023 -  analogRead(micPin0);
  //Serial.print(mic0);
  //Serial.println("");
  sum = sum+ mic0;
  
  
  }
  int result = sum/300;
  Serial.println(result);
  if (result >MID)
  {
    Serial.println("Loud");
    digitalWrite(vibrOut1, HIGH);
    digitalWrite(vibrOut2, HIGH);
    digitalWrite(vibrOut3, HIGH);
  }
  else if (result >SILENT & result <MID)
  {
    digitalWrite(vibrOut1, HIGH);
    Serial.println("Middle");
  }
  else 
  {
    Serial.println("Silent");
    digitalWrite(vibrOut1, LOW);
    digitalWrite(vibrOut2, LOW);
    digitalWrite(vibrOut3, LOW);
  }
  sum = 0;
  /*
  counter++;
  arr[counter] = vibrLevel;
  if (counter == 24)
  {
    for( int i=0; i<25; i++)
    {
     Serial.print(arr[i]); 
     Serial.print(" ");
    }
    Serial.print("0 ");
    Serial.print(mic0);
    Serial.print(" vibrLevel  ");
    Serial.println(vibrLevel);
    Serial.print(" counter ");
    Serial.println(counter);
  counter =0;
    
  }*/
  
  

}
