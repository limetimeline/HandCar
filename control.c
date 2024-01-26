int IN1Pin = 6;
int IN2Pin = 7;
int IN3Pin = 8;
int IN4Pin = 9;
int ENAPin = 5;
int ENBPin = 10;
int SPEED = 180;
void setup() {
  Serial.begin(9600);
  pinMode(IN1Pin, OUTPUT);
  pinMode(IN2Pin, OUTPUT);
  pinMode(IN3Pin, OUTPUT);
  pinMode(IN4Pin, OUTPUT);
  analogWrite(ENAPin, SPEED);
  analogWrite(ENBPin, SPEED);
}
void loop()
{
   if(Serial.available())  //시리얼모니터에서 데이터가 들어오면
  {
    char in_data;         // 입력된 데이터 저장을 위한 변수
    in_data = Serial.read();  //입력된 데이터 in_data에 저장
     Serial.print("data : ");
     Serial.println(in_data);
     /* 후진 */
     if(in_data == 's')
     {
     digitalWrite(IN1Pin, HIGH);
     digitalWrite(IN2Pin, LOW);
     digitalWrite(IN3Pin, HIGH);
     digitalWrite(IN4Pin, LOW);
     delay(1000);
     }
     /* 전진 */
     else if(in_data == 'w')
     {
     digitalWrite(IN1Pin, LOW);
     digitalWrite(IN2Pin, HIGH);
     digitalWrite(IN3Pin, LOW);
     digitalWrite(IN4Pin, HIGH);
     delay(1000);
     }
     /* 우회전 */
     else if(in_data == 'd')
     {
     digitalWrite(IN1Pin, HIGH);
     digitalWrite(IN2Pin, LOW);
     digitalWrite(IN3Pin, LOW);
     digitalWrite(IN4Pin, HIGH);
     }
     /* 좌회전 */
     else if(in_data == 'a')
     {
     digitalWrite(IN1Pin, LOW);
     digitalWrite(IN2Pin, HIGH);
     digitalWrite(IN3Pin, HIGH);
     digitalWrite(IN4Pin, LOW);
     }
     /* 정지 */
     else if(in_data == 'x')
     {
     digitalWrite(IN1Pin, HIGH);
     digitalWrite(IN2Pin, HIGH);
     digitalWrite(IN3Pin, HIGH);
     digitalWrite(IN4Pin, HIGH);
     }
  }
}
