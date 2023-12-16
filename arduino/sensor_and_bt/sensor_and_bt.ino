#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(4, 5);

int trigPin = 6;  // 초음파 거리 센서 trigPin
int echoPin = 7;  // 초음파 거리 센서 echoPin
int VibPin1 = 3;  // 진동 모터
int VibPin2 = 9;
int VibPin3 = 10; 
int VibPin4 = 11;

void setup() {
  Serial.begin(9600);  // 시리얼 통신을 위해 시리얼 통신속도를 9600으로 설정
  softwareSerial.begin(9600);

  pinMode(VibPin1, OUTPUT);  // 진동 모터
  pinMode(VibPin2, OUTPUT);  // 진동 모터
  pinMode(VibPin3, OUTPUT);  // 진동 모터
  pinMode(VibPin4, OUTPUT);  // 진동 모터
  pinMode(echoPin, INPUT);   // 초음파 거리 센서 echoPin 입력
  pinMode(trigPin, OUTPUT);  // 초음파 거리 센서 trigPin 출력
}

void loop() {

  char direction = softwareSerial.read();
  // 초음파 거리 센서
  long duration, distance;      // duration, distance 변수 설정
  digitalWrite(trigPin, HIGH);  // trigPin에서 초음파 발생(echoPin도 HIGH)
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);                 // echoPin 이 HIGH를 유지한 시간을 저장
  distance = ((float)(340 * duration) / 10000) / 2;  // 거리 계산

  //초음파 거리 센서 시리얼 모니터에 결과 출력
  Serial.print("Distance:");  // 물체와 초음파 거리 센서간 거리 표시
  Serial.print(distance);
  Serial.println("cm");
  Serial.print("direction:");
  Serial.println(direction);
  




  if (distance <= 50)  // 물체가 특정 거리 내 진입함
  {
    analogWrite(VibPin1, 100);
    analogWrite(VibPin2, 100);
    analogWrite(VibPin3, 100);
    analogWrite(VibPin4, 100);
    delay(200);
    analogWrite(VibPin1, 0);
    analogWrite(VibPin2, 0);
    analogWrite(VibPin3, 0);
    analogWrite(VibPin4, 0);
    delay(100);
    analogWrite(VibPin1, 100);
    analogWrite(VibPin2, 100);
    analogWrite(VibPin3, 100);
    analogWrite(VibPin4, 100);
    delay(200);
    analogWrite(VibPin1, 0);
    analogWrite(VibPin2, 0);
    analogWrite(VibPin3, 0);
    analogWrite(VibPin4, 0);
  } else {
    switch (direction) {
      case'1':
        analogWrite(VibPin1, 100);
        analogWrite(VibPin2, 100);
        delay(500);
        analogWrite(VibPin1, 0);
        analogWrite(VibPin2, 0);
        break;
      case'2':
        analogWrite(VibPin1, 100);
        delay(500);
        analogWrite(VibPin1, 0);
        break;
      case'4':
        analogWrite(VibPin4, 100);
        delay(500);
        analogWrite(VibPin4, 0);
        break;
      case'5':
        analogWrite(VibPin3, 100);
        analogWrite(VibPin4, 100);
        delay(500);
        analogWrite(VibPin3, 0);
        analogWrite(VibPin4, 0);
        break;
      default:
        break;

    }
  }

}