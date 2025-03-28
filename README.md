﻿# IoT-miniproject
สรุปโครงงาน “เซ็นเซอร์แจ้งเตือนการบุกรุกผ่าน Blynk”

โครงงานนี้เป็นการพัฒนา ระบบตรวจจับการบุกรุก โดยใช้ PIR Motion Sensor HC-SR501 ร่วมกับ NodeMCU ESP8266 และ Active Buzzer Module โดยมีการแจ้งเตือนผ่าน แอปพลิเคชัน Blynk เพื่อให้ผู้ใช้งานสามารถรับการแจ้งเตือนแบบเรียลไทม์เมื่อมีการตรวจพบความเคลื่อนไหว

⸻

องค์ประกอบหลักของโครงการ

การออกแบบฮาร์ดแวร์

	1.ใช้ PIR Motion Sensor HC-SR501 ตรวจจับการเคลื่อนไหว
	2.ใช้ NodeMCU ESP8266 เป็นตัวประมวลผลและเชื่อมต่ออินเทอร์เน็ต
	3.ใช้ Active Buzzer Module (Active Low) ส่งเสียงแจ้งเตือนเมื่อมีการบุกรุก
	4.เชื่อมต่ออุปกรณ์เข้าด้วยกันผ่านวงจรไฟฟ้า พร้อมทดสอบความเสถียรของระบบ

การพัฒนาและเชื่อมต่อซอฟต์แวร์

	1.เขียนโค้ด C++ (Arduino IDE) เพื่อควบคุมการทำงานของเซ็นเซอร์และบัซเซอร์
	2.ใช้ Blynk IoT Platform สำหรับแสดงผลและแจ้งเตือนผ่านมือถือ
	3.เชื่อมต่อ NodeMCU ESP8266 กับ Wi-Fi เพื่อให้สามารถรับ-ส่งข้อมูลแบบเรียลไทม์
	4.ทดสอบการเชื่อมต่อและประสิทธิภาพของแอปพลิเคชัน Blynk

การทดสอบระบบและวิเคราะห์ผลลัพธ์

	1.ทดสอบการตรวจจับการเคลื่อนไหว โดยทดลองใช้งานในสภาพแวดล้อมที่แตกต่างกัน
	2.วัดความเร็วในการแจ้งเตือน โดยทดสอบระยะเวลาที่ใช้ในการส่งข้อมูลจากเซ็นเซอร์ไปยังแอป Blynk
	3.วิเคราะห์ข้อจำกัดของระบบ เช่น ข้อผิดพลาดในการตรวจจับ หรือสัญญาณรบกวน

⸻

ผลลัพธ์ของโครงการ
	1.ระบบสามารถตรวจจับการเคลื่อนไหวได้แม่นยำ 95% ในระยะ 1-3 เมตร
	2.ใช้เวลาแจ้งเตือนเฉลี่ย 1.2 วินาที ผ่านแอปพลิเคชัน Blynk
	3.ปุ่มควบคุมในแอปพลิเคชันมีการตอบสนองภายใน 0.8 วินาที
	4.สามารถใช้งานได้จริงและเหมาะสำหรับระบบรักษาความปลอดภัยภายในบ้าน

⸻

ข้อเสนอแนะในการพัฒนาเพิ่มเติม
	1.ปรับปรุงระบบ ลดการแจ้งเตือนผิดพลาด จากสิ่งมีชีวิตขนาดเล็ก
	2.เพิ่มระบบ บันทึกข้อมูลการบุกรุก ลงฐานข้อมูล Firebase
	3รองรับการแจ้งเตือนผ่าน LINE Notify หรือ Telegram

⸻

สรุปโดยรวม

โครงงานนี้เป็นการประยุกต์ใช้ Internet of Things (IoT) และ ระบบฝังตัว (Embedded Systems) เพื่อพัฒนา ระบบแจ้งเตือนการบุกรุกที่สามารถใช้งานได้จริง โดยอาศัยการทำงานของเซ็นเซอร์ตรวจจับความเคลื่อนไหวและการแจ้งเตือนผ่านแอปพลิเคชันมือถือ ถือเป็นแนวทางที่มีประโยชน์ในการพัฒนาระบบรักษาความปลอดภัยที่มีต้นทุนต่ำแต่มีประสิทธิภาพสูง

เพิ่มเติม
 libraries ดาวน์โหลด -> https://drive.google.com/drive/folders/1ZHA0fQdYv1UkNHEGD_DIbEfIXUWZ9a_v?usp=drive_link
Additional boards manager URL : http://arduino.esp8266.com/stable/package_esp8266com_index.json 
