# Embedded C: Register & Bitwise Manipulation Cheat Sheet

This module documents the fundamental bitwise operations required for low-level embedded software engineering and register-level programming on microcontrollers (ARM Cortex-M, ESP32, AVR).

---

## 🔑 The Golden Rules of Embedded Bitwise

In hardware, registers control peripherals (GPIO, Timers, ADC, UART, I2C). Writing a full byte or word blindly will destroy existing configurations. You must manipulate **only the target bits**.

### 1. Set Bit $n$ (Force to `1` / HIGH)
```c
REG |= (1 << n);
```
- **Operator:** Bitwise OR (`|`)
- **Mechanism:** Any bit ORed with `1` becomes `1`. Any bit ORed with `0` remains unchanged.
- **Use Case:** Turn on an LED, enable an interrupt, start an ADC conversion.

---

### 2. Clear Bit $n$ (Force to `0` / LOW)
```c
REG &= ~(1 << n);
```
- **Operator:** Bitwise AND (`&`) with bitwise NOT (`~`)
- **Mechanism:** `~(1 << n)` creates a mask where bit $n$ is `0` and all other bits are `1`. ANDing keeps all other bits intact while forcing bit $n$ to `0`.
- **Use Case:** Turn off a pin, disable a clock, clear an interrupt flag.

---

### 3. Toggle Bit $n$ (Flip state `0` $\leftrightarrow$ `1`)
```c
REG ^= (1 << n);
```
- **Operator:** Bitwise XOR (`^`)
- **Mechanism:** XOR with `1` inverts the bit. XOR with `0` preserves the bit.
- **Use Case:** Blink an LED inside a timer interrupt handler without reading current state.

---

### 4. Read / Test Bit $n$
```c
if (REG & (1 << n)) {
    // Pin n is HIGH (1)
} else {
    // Pin n is LOW (0)
}
```
- **Use Case:** Reading a digital sensor or button input pin.

---

### 5. Modify a Multi-Bit Field (Interview Favorite)
Often, a single peripheral setting spans 2, 3, or 4 bits (e.g., GPIO speed, ADC prescaler, UART baud rate divisor).

**Formula:**
```c
REG = (REG & ~(MASK << SHIFT)) | (VALUE << SHIFT);
```
1. **Clear phase:** `REG & ~(MASK << SHIFT)` wipes out the old configuration in those bit slots.
2. **Set phase:** `| (VALUE << SHIFT)` writes the new value into the clean slot.

---

## 🏃 How to Run
Compile with any standard C compiler or online tool:
```bash
gcc register_operations.c -o register_operations
./register_operations
```
