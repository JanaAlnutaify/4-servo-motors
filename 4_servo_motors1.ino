#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

void setup() {
  motor1.attach(9);
  motor2.attach(10);
  motor3.attach(11);
  motor4.attach(12);
}

void loop() {

  // Sweep لمدة ثانيتين
  unsigned long startTime = millis();

  while (millis() - startTime < 2000) {

    // من 0 إلى 180 درجة
    for (int angle = 0; angle <= 180; angle++) {
      motor1.write(angle);
      motor2.write(angle);
      motor3.write(angle);
      motor4.write(angle);

      delay(15);

      if (millis() - startTime >= 2000) {
        break;
      }
    }

    // من 180 إلى 0 درجة
    for (int angle = 180; angle >= 0; angle--) {
      motor1.write(angle);
      motor2.write(angle);
      motor3.write(angle);
      motor4.write(angle);

      delay(15);

      if (millis() - startTime >= 2000) {
        break;
      }
    }
  }

  // بعد انتهاء الـ Sweep
  // تثبيت جميع المحركات عند 90 درجة
  motor1.write(90);
  motor2.write(90);
  motor3.write(90);
  motor4.write(90);

  // منع إعادة تشغيل الـ Sweep
  while (true) {
  }
}