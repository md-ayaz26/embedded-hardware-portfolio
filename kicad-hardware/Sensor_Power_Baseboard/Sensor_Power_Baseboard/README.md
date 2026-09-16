# Sensor Power & I2C Baseboard

A modular, industry-standard power delivery and sensor breakout circuit designed in KiCad 10.

---

## ⚡ Circuit Specifications & Engineering Design Rationale

### 1. USB-C 5V Input & CC Pull-Downs
- **Connector:** USB-C 16-Pin Receptacle (`USB_C_Receptacle_USB2.0_16P`)
- **CC Pin Configuration:** $5.1\text{ k}\Omega$ pull-down resistors ($R_1, R_2$) from CC1 and CC2 to ground.
  - *Engineering Rationale:* Standard USB Type-C power sources (laptops, chargers) remain at 0V until they detect $5.1\text{ k}\Omega$ pull-down resistors on the CC lines, signaling a valid device connection.
- **Unused USB 2.0 Data Lines ($D^+, D^-$):** Terminated with No-Connect flags as this board operates in dedicated power-sink mode.

### 2. Voltage Regulation (5V $\rightarrow$ 3.3V)
- **LDO Regulator:** `AMS1117-3.3` (SOT-223)
- **Decoupling & Filtering Network:**
  - Input: $10\,\mu\text{F}$ bulk capacitor ($C_1$) + $100\text{ nF}$ high-frequency ceramic bypass capacitor ($C_2$) to filter input ripple and transient spikes.
  - Output: $22\,\mu\text{F}$ stability capacitor ($C_3$) + $100\text{ nF}$ bypass capacitor ($C_4$) to maintain regulator control loop stability and low output impedance.
- **Power Indicator:** Green LED ($D_1$) with a $1\text{ k}\Omega$ current-limiting resistor ($R_3$), drawing $\approx 1.3\text{ mA}$ to minimize idle quiescent draw.

### 3. I2C Sensor Interface
- **Bus Connector:** 4-pin $2.54\text{ mm}$ pitch header (`3V3`, `GND`, `SDA`, `SCL`) compatible with standard OLED displays, BME280, MPU6050, etc.
- **Pull-Up Resistors:** Dedicated $4.7\text{ k}\Omega$ pull-up resistors ($R_4, R_5$) on SDA and SCL lines to ensure crisp I2C clock and data edges on open-drain signals.

---

## 📄 Schematic Deliverables
- **KiCad Schematic Source:** `Sensor_Power_Baseboard.kicad_sch`
- **PDF Export:** [Sensor_Power_Baseboard.pdf](./Sensor_Power_Baseboard.pdf)
