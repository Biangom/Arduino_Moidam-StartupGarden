
// 초음파센서를 쓰진 않지만
// 나중에 쓸지 모르므로 예약 핀번호 선언
int echo = 11;
int trig = 12;

#include <Servo.h> 
 
int servoPin = 9;

Servo servo; 

int angle = 0; // 서보모터 각도 위치
int sw = 8;

void setup() {
    Serial.begin(9600);

    // Trig를 출력, Echo를 입력으로 설정
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(13, OUTPUT); // setting basic LED
    pinMode(sw, INPUT_PULLUP); //INPUT_PULLUP모드 적용

    servo.attach(servoPin); 
}

void loop() {
    bool check = false;
    int logic = digitalRead(sw);

    if( logic == LOW && check == false)
    {
        check = true;
         // scan from 0 to 180 degrees
//          for(angle = 0; angle < 180; angle++) 
//          { 
//            servo.write(angle); 
//            delay(3); 
//          }  
          // now scan back from 180 to 0 degrees
          for(angle = 180; angle > 0; angle--) 
          { 
            servo.write(angle); 
            delay(2); 
          } 
    }
    else if(logic == HIGH) {
        check = false;
    }
}
