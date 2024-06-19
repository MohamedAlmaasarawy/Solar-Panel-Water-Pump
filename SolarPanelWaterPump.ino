/*
 * Created: 24/12/2023 8:13:47 PM
 * Group Project:Ahmed Bahaa, Mohamed mamdouh, Mohamed Tamer, Ahmed Hany 
 */ 
#include <Servo.h>

Servo myservo1, myservo2;
int LDR1 = A0, LDR2 = A1, LDR3 = A2, LDR4 = A3;
int rRDL1 = 0, rRDL2 = 0, rRDL3 = 0, rRDL4 = 0;
int max1=0, max2=0, max3=0;
int ser1 = 80, ser2=0;

// Define analog input
#define ANALOG_IN_PIN A4
 
// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;
 
// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0; 
 
// Float for Reference Voltage
float ref_voltage = 5.0;
 
// Integer for ADC value
int adc_value = 0;
char Incoming_value = 0;


void setup() {
  myservo1.attach(9);
  myservo2.attach(8);

  Serial.begin(9600);
  myservo1.write(ser1);
  myservo2.write(100);
  pinMode(13, OUTPUT);
}

void loop() {

    if (Serial.available() > 0)
  {
    Incoming_value = Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
    if (Incoming_value == '1')
       digitalWrite(13, HIGH);
    else if (Incoming_value == '0')
       digitalWrite(13, LOW);
  }
  // Read the Analog Input
  adc_value = analogRead(ANALOG_IN_PIN);
  
  // Determine voltage at ADC input
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;
  int adc = analogRead(A5);
  float voltage = adc*5/1023.0;
  float current = (voltage-2.5)/0.185;
  
  // Calculate voltage at divider input
  in_voltage = adc_voltage*(R1+R2)/R2;
  
  // Print results to Serial Monitor to 2 decimal places
  Serial.print("Input Voltage : ");
  Serial.println(in_voltage, 2  );
  
    rRDL1 = analogRead(LDR1) / 100;
  rRDL2 = analogRead(LDR2) / 100;
  rRDL3 = analogRead(LDR3) / 100;
  rRDL4 = analogRead(LDR4) / 100;

  max1 = max(rRDL1, rRDL2);
  max2 = max(rRDL3, rRDL4);
  max3 = max(max1, max2);
  
  //Serial.println(String(max3));
  //Serial.println(String(rRDL1) +", "+String(rRDL2) +", "+String(rRDL3) +", "+String(rRDL4));


  if(rRDL1<max3 && rRDL2<max3)
  {
    if(ser1<140)
      ser1+=1;
    myservo1.write(ser1);
  }
  if(rRDL3<max3 && rRDL4<max3)
  {
    if(ser1>0)
      ser1-=1;
    myservo1.write(ser1);
  }

  if(rRDL2<max3 && rRDL3<max3)
  {
    Serial.println("servo2 +" + String(ser2));
    if(ser2<180)
      ser2+=1;
    myservo2.write(ser2);
  }
  if(rRDL1<max3 && rRDL4<max3)
  {
    Serial.println("servo2 -" + String(ser2));
    if(ser2>0)
      ser2-=1;
    myservo2.write(ser2);
    
  }
  delay(15);
}