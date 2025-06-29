# Solar Panel Light Tracker

An Arduino-based solar panel positioning system that uses four LDRs and two servos to continuously orient a solar panel toward the brightest light source. Also measures panel input voltage and load current, and allows LED control via serial commands.

---

## 📋 Contents

- `tracker.ino` — Main Arduino sketch  
- _(Add any wiring diagrams or supplemental files here)_

---

## 🚀 Features

- **Solar Panel Tracking**  
  - Four Light-Dependent Resistors (LDRs) on A0–A3 sense light intensity  
  - Two servos (pins 9 & 8) pan and tilt the panel toward the brightest quadrant  

- **Voltage & Current Monitoring**  
  - Measures panel input voltage through a 30 kΩ/7.5 kΩ divider on A4  
  - Reads load current from a 0.185 V/A sensor on A5 (with 2.5 V offset)  
  - Reports real-time voltage & current in the Serial Monitor  

- **Serial-Controlled Status LED**  
  - Send `1` or `0` over Serial to turn the built-in LED (pin 13) ON/OFF  

---

## 🔧 Hardware Setup

1. **Servos**  
   - Servo 1 → D9 (tilt)  
   - Servo 2 → D8 (pan)  
   - Power both from 5 V & GND

2. **LDR Sensor Array**  
   - LDR1 → A0  
   - LDR2 → A1  
   - LDR3 → A2  
   - LDR4 → A3  
   - Each paired with a fixed resistor in a voltage divider to ground

3. **Voltage Divider (Input Voltage Measurement)**  
   - R1 = 30 kΩ → 5 V  
   - Divider midpoint → A4  
   - R2 = 7.5 kΩ → GND

4. **Current Sensor (Load Current Measurement)**  
   - Sensor output → A5  
   - VCC & GND per sensor datasheet

5. **Status LED**  
   - Built-in LED on pin 13  

---

## ⚙️ Installation & Usage

1. **Clone & open**  
   ```bash
   git clone https://github.com/your-username/solar-tracker.git
   cd solar-tracker
   open tracker.ino
