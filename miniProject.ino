#define BLYNK_TEMPLATE_ID "TMPL63rHiHPOZ"
#define BLYNK_TEMPLATE_NAME "pir sensor"
#define BLYNK_AUTH_TOKEN "kMdL67sXc6GnYbU33gVHdfGVsZxEt0qr" // ใส่ Auth Token ของคุณ

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define PIR_PIN D5       // ขา PIR Motion Sensor
#define BUZZER_PIN D6    // ขา Active Buzzer (Active Low)

int motionCount = 0;
bool alertOn = false;  // ค่าควบคุมเสียงเตือนจาก Blynk
bool notified = false; // ค่าควบคุมการแจ้งเตือน

char ssid[] = "Pumpam";      
char pass[] = "1234567890";    

BlynkTimer timer;

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, HIGH); // ปิดเสียง Buzzer (Active Low)

  // เชื่อมต่อ Blynk Cloud
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);

  // ตั้งเวลาส่งข้อมูลไปยัง Blynk ทุก 1 วินาที
  timer.setInterval(10000L, sendMotionCount);
}

void loop() {
  Blynk.run();
  timer.run();

  int motionDetected = digitalRead(PIR_PIN);
  
  if (motionDetected == HIGH) {
    motionCount++;
    Serial.print("Motion Detected! Count: ");
    Serial.println(motionCount);

    // ส่งแจ้งเตือนเมื่อพบการบุกรุกครั้งแรก
    if (!notified) {
      Blynk.logEvent("intrusion_alert", "มีการบุกรุก! ตรวจพบการเคลื่อนไหว"); // แจ้งเตือนผ่าน Blynk
      notified = true; // ป้องกันการแจ้งเตือนซ้ำ
    }

    if (alertOn) {
      digitalWrite(BUZZER_PIN, LOW); // เปิดเสียง Buzzer
    }
  } else {
    Serial.println("No Motion");
  }
}

// ส่งข้อมูลจำนวนการเคลื่อนไหวไปยัง Blynk
void sendMotionCount() {
  Blynk.virtualWrite(V2, motionCount);
}

// ควบคุมการแจ้งเตือนจาก Blynk App
BLYNK_WRITE(V1) {
  alertOn = param.asInt(); // ถ้า V1 = 1 → เปิดแจ้งเตือน, V1 = 0 → ปิดแจ้งเตือน
  if (!alertOn) {
    digitalWrite(BUZZER_PIN, HIGH); // ปิดเสียง Buzzer
    notified = false; // รีเซ็ตแจ้งเตือนใหม่
  }
}
