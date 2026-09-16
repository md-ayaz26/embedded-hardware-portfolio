# Embedded Systems & Hardware Engineering Portfolio

> **Mohammad Ayaz Riyaz**  
> 2nd Year B.Tech — Electronics & Telecommunication Engineering (ENTC)  
> **PVG's College of Engineering and Technology (PVGCOET), Pune**  
> Focus: Embedded Systems | Firmware (C / Embedded C) | PCB Design (KiCad) | IoT

---

## 🎯 Technical Focus & Skillset

- **Languages:** C, Embedded C, Python (basics/scripting)
- **EDA & Hardware Tools:** KiCad 10 (Schematic capture, PCB layout, DRC/ERC, Gerber generation)
- **Target Architectures & Boards:** ESP32, STM32 (ARM Cortex-M), ATmega / Arduino
- **Peripherals & Protocols:** GPIO, Timers, Interrupts, ADC, PWM, UART, I2C, SPI, CAN bus
- **Tools & Workflow:** Git, GitHub, VS Code, PlatformIO / STM32CubeIDE

---

## 🚀 Featured Hardware Projects

### 🔌 [Sensor Power & I2C Baseboard (v1.0)](./kicad-hardware/Sensor_Power_Baseboard/Sensor_Power_Baseboard/)

A modular 2-layer PCB designed from scratch in KiCad 10 to supply regulated 3.3V power via USB-C and provide a terminated I2C bus header for environmental and motion sensors (OLED, BME280, MPU6050).

<p align="center">
  <img src="./kicad-hardware/Sensor_Power_Baseboard/Sensor_Power_Baseboard/images/pcb_3d_angle.png" alt="3D Render of Sensor Power Baseboard" width="650"/>
</p>

- **Power Input:** USB-C with $5.1\text{ k}\Omega$ CC pull-down resistors for USB-PD source negotiation.
- **Regulation:** AMS1117-3.3 LDO with $10\,\mu\text{F} / 100\text{ nF}$ input decoupling and $22\,\mu\text{F} / 100\text{ nF}$ output stability capacitors.
- **Sensor Bus:** 4-pin $2.54\text{ mm}$ pitch header with dedicated $4.7\text{ k}\Omega$ I2C pull-up resistors.
- **Status:** ✅ Completed (Passed ERC & DRC with 0 errors; Gerbers packaged and ready for fabrication).

---

## 📁 Repository Structure & Projects

```text
├── firmware/
│   └── bitwise-c/              # [✅ Completed] Low-level bit masking, register flipping, and GPIO drills
├── kicad-hardware/
│   └── Sensor_Power_Baseboard/ # [✅ Completed] 2-layer custom USB-C to 3.3V power & sensor baseboard
└── notes/                      # Technical notes on protocols, datasheets, and circuit analysis
```

| # | Project / Module | Domain | Status | Key Highlights |
|---|---|---|---|---|
| 01 | **[Register & Bitwise Manipulation](./firmware/bitwise-c/)** | Embedded C | ✅ Completed | Direct register bit-masking, bit-flipping, port manipulation |
| 02 | **[Sensor Power & I2C Baseboard](./kicad-hardware/Sensor_Power_Baseboard/Sensor_Power_Baseboard/)** | KiCad Hardware | ✅ Completed | 5V to 3.3V LDO regulator, USB-C CC logic, I2C sensor bus, Gerbers |
| 03 | **I2C Sensor Driver from Scratch** | Firmware | ⚪ Planned | Reading sensor data via bare register/protocol calls |
| 04 | **Automotive / Industrial CAN Node** | Embedded / Auto | ⚪ Planned | CAN bus transceiver integration and packet telemetry |

---

## 📬 Contact & Links
- **GitHub:** [md-ayaz26](https://github.com/md-ayaz26)
