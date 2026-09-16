/**
 * @file register_operations.c
 * @brief Essential Bitwise Operations for Microcontroller Register Manipulation
 * @author Ayaz (PVGCOET Pune)
 * 
 * In embedded systems, hardware peripherals (GPIO, Timers, ADC, UART) are controlled
 * through Memory-Mapped Registers. We do NOT use high-level abstractions like digitalWrite().
 * Instead, we manipulate individual bits in registers using bitwise operators.
 */

#include <stdio.h>
#include <stdint.h>

// Helper function to print an 8-bit register in binary format with bit positions
void print_register(const char *label, uint8_t reg) {
    printf("%-35s [0x%02X] : ", label, reg);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (reg >> i) & 1);
        if (i == 4) printf(" "); // Visual separator between nibbles
    }
    printf(" (b7..b0)\n");
}

int main(void) {
    printf("============================================================\n");
    printf("  EMBEDDED C: BITWISE REGISTER MANIPULATION DRILL\n");
    printf("============================================================\n\n");

    // Simulated 8-bit GPIO Port Direction/Output Register
    // Initially, all pins are LOW (0b0000 0000)
    uint8_t GPIO_PORT = 0x00;
    print_register("1. Initial state (All pins LOW)", GPIO_PORT);

    /* -------------------------------------------------------------
     * RULE 1: SETTING A BIT (Force to 1) -> Use Bitwise OR ( |= )
     * Formula: REG |= (1 << PIN_NUMBER)
     * Turn ON LED connected to Pin 3
     * ------------------------------------------------------------- */
    #define LED_PIN 3
    GPIO_PORT |= (1 << LED_PIN);
    print_register("2. Set Bit 3 (Turn ON LED)", GPIO_PORT);

    /* -------------------------------------------------------------
     * RULE 2: SETTING MULTIPLE BITS SIMULTANEOUSLY
     * Turn ON Pin 1 and Pin 6 using a bitmask
     * ------------------------------------------------------------- */
    GPIO_PORT |= (1 << 1) | (1 << 6);
    print_register("3. Set Bits 1 & 6 simultaneously", GPIO_PORT);

    /* -------------------------------------------------------------
     * RULE 3: CLEARING A BIT (Force to 0) -> Use Bitwise AND with NOT ( &= ~ )
     * Formula: REG &= ~(1 << PIN_NUMBER)
     * Turn OFF Pin 3 (LED OFF)
     * ------------------------------------------------------------- */
    GPIO_PORT &= ~(1 << LED_PIN);
    print_register("4. Clear Bit 3 (Turn OFF LED)", GPIO_PORT);

    /* -------------------------------------------------------------
     * RULE 4: TOGGLING A BIT (Invert state) -> Use Bitwise XOR ( ^= )
     * Formula: REG ^= (1 << PIN_NUMBER)
     * Useful for blinking an LED or alternating states in timer ISR
     * ------------------------------------------------------------- */
    #define BUZZER_PIN 6
    GPIO_PORT ^= (1 << BUZZER_PIN); // Was 1, will become 0
    print_register("5. Toggle Bit 6 (Buzzer from 1 -> 0)", GPIO_PORT);

    GPIO_PORT ^= (1 << BUZZER_PIN); // Was 0, will become 1
    print_register("6. Toggle Bit 6 again (0 -> 1)", GPIO_PORT);

    /* -------------------------------------------------------------
     * RULE 5: CHECKING / READING A BIT -> Use Bitwise AND ( & )
     * Formula: (REG & (1 << PIN_NUMBER)) != 0
     * Checking if a sensor or push button is triggered
     * ------------------------------------------------------------- */
    #define SENSOR_PIN 1
    printf("\n--- Reading Pin States ---\n");
    if (GPIO_PORT & (1 << SENSOR_PIN)) {
        printf(">> SENSOR_PIN (Pin 1) is HIGH (Active)\n");
    } else {
        printf(">> SENSOR_PIN (Pin 1) is LOW (Inactive)\n");
    }

    /* -------------------------------------------------------------
     * RULE 6: ADVANCED (MULTI-BIT FIELDS)
     * How to set a 3-bit field (e.g., Prescaler bits 2..4)
     * without modifying other bits!
     * 
     * Target: Set bits [4:2] to value 5 (binary 101)
     * Step A: Clear bits [4:2] using a mask: ~(0b111 << 2) -> ~(0x07 << 2)
     * Step B: OR the new value shifted: (0b101 << 2)
     * ------------------------------------------------------------- */
    printf("\n--- Multi-bit Field Configuration (Timer / ADC mode) ---\n");
    uint8_t CONFIG_REG = 0b10000011; // Initial dummy register
    print_register("Config Reg before change", CONFIG_REG);

    uint8_t field_mask = (0x07 << 2);    // 0001 1100 (bits 2, 3, 4)
    uint8_t new_value  = 0b101;          // Value 5 to write into bits 4..2

    // Apply: Clear target bits, then write new value
    CONFIG_REG = (CONFIG_REG & ~field_mask) | (new_value << 2);
    print_register("Config Reg after bits [4:2] = 5", CONFIG_REG);

    printf("\n============================================================\n");
    printf("  All operations completed successfully!\n");
    printf("============================================================\n");

    return 0;
}
