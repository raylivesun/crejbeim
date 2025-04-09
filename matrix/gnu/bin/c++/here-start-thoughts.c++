#include <stdio.h>

#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <sys/epoll.h>
#include <sys/utsname.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <linux/if_arp.h>
#include <linux/if.h>

// Here's my thinking process to arrive at the answer:

// 1.  **Understand the Goal:** The user provides a sequence of numbers 
// (`48 65 72 65`) and a target data type (`uint32_t`) followed by a single 
// large number (`1701,995,848`). The request implies converting the sequence 
//of smaller numbers into a single `uint32_t` value and comparing it to the 
// provided target number.

// 2.  **Identify the Data Type:** `uint32_t`
//     *   `u`: Unsigned (non-negative values only).
//     *   `int`: Integer.
//     *   `32`: Uses exactly 32 bits.
//     *   `_t`: Standard type suffix.
//     *   **Range:** 0 to 2^32 - 1 = 0 to 4,294,967,295.

void analyzeUint32_t() {
    // uint32_t properties
    printf("uint32_t:\n");
    printf("  *   unsigned: The integer cannot be negative and uses all bits to represent the magnitude.\n");
    printf("  *   int: Stands for **integer**.\n");
    printf("  *   32: Specifies that it uses exactly **32 bits** of memory.\n");
    printf("  *   _t: Standard suffix indicating a defined type (from `<stdint.h>` or `<cstdint>`).\n");
}

// 2.  **Identify the Data Type:** `uint32_t`
//     *   `u`: Unsigned (non-negative values only).
//     *   `int`: Integer.
//     *   `32`: Uses exactly 32 bits.
//     *   `_t`: Standard type suffix.
//     *   **Range:** 0 to 2<sup>32</sup> - 1 = 0 to 4,294,967,295.

void identifyUint32_t() {
    printf("Data Type: uint32_t\n");
    printf("  * u: Unsigned (non-negative values only).\n");
    printf("  * int: Integer.\n");
    printf("  * 32: Uses exactly 32 bits.\n");
    printf("  * _t: Standard type suffix.\n");
    printf("  * Range: 0 to 2^32 - 1 = 0 to 4,294,967,295.\n");
}


// 3.  **Interpret the Input Sequence:** `48 65 72 65`
//     *   These look like ASCII values or byte values. Since we're dealing 
//     with a 32-bit integer (which is 4 bytes), it's highly likely these 
//     represent four individual 8-bit bytes that need to be combined.
//     *   `48` is the ASCII code for '0'.
//     *   `65` is the ASCII code for 'A'.
//     *   `72` is the ASCII code for 'H'.
//     *   `65` is the ASCII code for 'A'.
//     *   So the sequence corresponds to the characters "0AHA". This isn't 
//     strictly necessary for the calculation, but it's a good sanity check 
// and common pattern.
void interpretInputSequence() {
    uint8_t bytes[] = {48, 65, 72, 65};
    char chars[] = {static_cast<char>(bytes[0]), static_cast<char>(bytes[1]), static_cast<char>(bytes[2]), static_cast<char>(bytes[3]), '\0'};
    printf("The sequence corresponds to the characters: %s\n", chars);
}


// 5.  **Perform the Calculation (Try Both Endiannesses):**

//     *   **Big-Endian Calculation:**
//         *   `48` (0x30) << 24 = 0x30000000
//         *   `65` (0x41) << 16 = 0x00410000
//         *   `72` (0x48) << 8  = 0x00004800
//         *   `65` (0x41) << 0  = 0x00000041
//         *   Combine (OR or add): 0x30000000 | 0x00410000 | 0x00004800 | 0x00000041 = 0x30414841
//         *   Convert 0x30414841 to decimal:
//             *   (3 * 16^7) + (0 * 16^6) + (4 * 16^5) + (1 * 16^4) + (4 * 16^3) + (8 * 16^2) + (4 * 16^1) + (1 * 16^0)
//             *   (3 * 268435456) + 0 + (4 * 1048576) + (1 * 65536) + (4 * 4096) + (8 * 256) + (4 * 16) + (1 * 1)
//             *   805306368 + 4194304 + 65536 + 16384 + 2048 + 64 + 1 = **809584705**

void calculateUint32_t() {
    uint32_t bigEndian = (48 << 24) | (65 << 16) | (72 << 8) | (65 << 0);
    uint32_t littleEndian = (65 << 24) | (72 << 16) | (65 << 8) | (48 << 0);
    printf("Big-Endian: 0x%X = %u\n", bigEndian, bigEndian);
    printf("Little-Endian: 0x%X = %u\n", littleEndian, littleEndian);
}


// *   **Little-Endian Calculation:**
// *   `65` (0x41) << 24 = 0x41000000
// *   `72` (0x48) << 16 = 0x00480000
// *   `65` (0x41) << 8  = 0x00004100
// *   `48` (0x30) << 0  = 0x00000030
// *   Combine (OR or add): 0x41000000 | 0x00480000 | 0x00004100 | 0x00000030 = 0x41484130
// *   Convert 0x41484130 to decimal:
//     *   (4 * 16^7) + (1 * 16^6) + (4 * 16^5) + (8 * 16^4) + (4 * 16^3) + (1 * 16^2) + (3 * 16^1) + (0 * 16^0)
//     *   (4 * 268435456) + (1 * 16777216) + (4 * 1048576) + (8 * 65536) + (4 * 4096) + (1 * 256) + (3 * 16) + 0
//     *   1073741824 + 16777216 + 4194304 + 524288 + 16384 + 256 + 48 + 0 = **1095254320**
void littleEndianCalculation() {
    uint32_t value = (65 << 24) | (72 << 16) | (65 << 8) | (48 << 0);
    printf("Little-Endian: 0x%X = %u\n", value, value);
}

// 6.  **Compare with the Target Value:** The target value is `1701995848`.
//     *   My Big-Endian result: `809584705`
//     *   My Little-Endian result: `1095254320`
//     *   Neither of these matches `1701995848`.

void compareWithTargetValue() {
    uint32_t targetValue = 1701995848;
    uint32_t bigEndianResult = 809584705;
    uint32_t littleEndianResult = 1095254320;

    printf("Comparing with target value: %u\n", targetValue);
    if (bigEndianResult == targetValue) {
        printf("Big-Endian result matches the target value.\n");
    } else {
        printf("Big-Endian result does not match the target value.\n");
    }

    if (littleEndianResult == targetValue) {
        printf("Little-Endian result matches the target value.\n");
    } else {
        printf("Little-Endian result does not match the target value.\n");
    }
}


// 7.  **Re-evaluate the Input Interpretation:** Is there another way 
// to interpret `48 65 72 65`?
//     *   Perhaps the numbers *aren't* bytes in order.
//     *   Maybe the *characters* "48 65 72 65" themselves are being hashed or encoded? 
//  Unlikely given the context.
//     *   Let's look at the target number `1701995848` in hexadecimal.
//         *   `1701995848` / 16 = 106374740 R 8
//         *   `106374740` / 16 = 6648421 R 4
//         *   `6648421` / 16 = 415526 R 5
//         *   `415526` / 16 = 25970 R 6
//         *   `25970` / 16 = 1623 R 2
//         *   `1623` / 16 = 101 R 7
//         *   `101` / 16 = 6 R 5
//         *   `6` / 16 = 0 R 6
//         *   Reading remainders bottom-up: `0x65726548`
void reevaluateInputInterpretation() {
    uint32_t targetValue = 1701995848;

    printf("Target value: %u\n", targetValue);
    printf("Target value in hexadecimal: 0x%X\n", targetValue);

    uint32_t remainder = targetValue;
    char hexString[9] = {0}; // 8 bytes for the hex string, 1 byte for the null terminator

    for (int i = 7; i >= 0; i--) {
        hexString[i] = (remainder % 16) + '0';
        remainder /= 16;
    }

    printf("Target value in hexadecimal (read from right to left): %s\n", hexString);
}

// 8.  **Analyze the Hexadecimal Value:** `0x65726548`
//     *   Break it into bytes: `65`, `72`, `65`, `48`
//     *   Convert these hex bytes to decimal:
//         *   `0x65` = (6 * 16) + 5 = 96 + 5 = 101
//         *   `0x72` = (7 * 16) + 2 = 112 + 2 = 114
//         *   `0x65` = 101
//         *   `0x48` = (4 * 16) + 8 = 64 + 8 = 72
//     *   This sequence `101 114 101 72` doesn't match the input `48 65 72 65`.
void analyzeHexadecimalValue() {
    uint32_t hexValue = 0x65726548;
    uint8_t bytes[4] = {
        (hexValue >> 24) & 0xFF,
        (hexValue >> 16) & 0xFF,
        (hexValue >> 8) & 0xFF,
        hexValue & 0xFF
    };

    printf("Hexadecimal value 0x%X breaks into bytes: %u, %u, %u, %u\n", hexValue, bytes[0], bytes[1], bytes[2], bytes[3]);

    printf("Converted to decimal:\n");
    printf("0x%X = %u\n", bytes[0], bytes[0]);
    printf("0x%X = %u\n", bytes[1], bytes[1]);
    printf("0x%X = %u\n", bytes[2], bytes[2]);
    printf("0x%X = %u\n", bytes[3], bytes[3]);

    printf("Decimal sequence: %u %u %u %u\n", bytes[0], bytes[1], bytes[2], bytes[3]);
    printf("This sequence doesn't match the input 48 65 72 65.\n");
}

// 9.  **Reconsider the Hexadecimal Value and Endianness:** The hex value is `0x65726548`.
//     *   **If this represents a Big-Endian value**, the bytes in memory (from low address 
//      to high) would be `65`, `72`, `65`, `48`. In decimal, that's `101`, `114`, `101`, `72`.
//     *   **If this represents a Little-Endian value**, the bytes in memory (from low 
// address to high) would be `48`, `65`, `72`, `65`. In decimal, that's `72`, `101`, `114`, 
// `101`.
void reconsiderHexValueAndEndianness() {
    uint32_t hexValue = 0x65726548;

    // Big-Endian interpretation
    uint8_t bigEndianBytes[4] = {
        (hexValue >> 24) & 0xFF,
        (hexValue >> 16) & 0xFF,
        (hexValue >> 8) & 0xFF,
        hexValue & 0xFF
    };
    printf("Big-Endian bytes: %u, %u, %u, %u\n", bigEndianBytes[0], bigEndianBytes[1], bigEndianBytes[2], bigEndianBytes[3]);
    printf("Big-Endian decimal: %u, %u, %u, %u\n", bigEndianBytes[0], bigEndianBytes[1], bigEndianBytes[2], bigEndianBytes[3]);

    // Little-Endian interpretation
    uint8_t littleEndianBytes[4] = {
        hexValue & 0xFF,
        (hexValue >> 8) & 0xFF,
        (hexValue >> 16) & 0xFF,
        (hexValue >> 24) & 0xFF
    };
    printf("Little-Endian bytes: %u, %u, %u, %u\n", littleEndianBytes[0], littleEndianBytes[1], littleEndianBytes[2], littleEndianBytes[3]);
    printf("Little-Endian decimal: %u, %u, %u, %u\n", littleEndianBytes[0], littleEndianBytes[1], littleEndianBytes[2], littleEndianBytes[3]);
}

// 11. **Let's redo the Little-Endian byte order for `0x65726548`:**
//     *   The value is `0x65726548`.
//     *   MSB (Most Significant Byte) = `0x65`
//     *   ... = `0x72`
//     *   ... = `0x65`
//     *   LSB (Least Significant Byte) = `0x48`
//     *   In Little-Endian memory layout (lowest address first): LSB ... MSB
//     *   Memory bytes: `48`, `65`, `72`, `65`
//     *   Converting *these memory bytes* to decimal:
//         *   `0x48` = 72
//         *   `0x65` = 101
//         *   `0x72` = 114
//         *   `0x65` = 101
//     *   This is still not matching the input `48 65 72 65`.
void redoLittleEndianByteOrder() {
    uint32_t hexValue = 0x65726548;

    uint8_t littleEndianBytes[4] = {
        hexValue & 0xFF,
        (hexValue >> 8) & 0xFF,
        (hexValue >> 16) & 0xFF,
        (hexValue >> 24) & 0xFF
    };
    printf("Little-Endian bytes: %u, %u, %u, %u\n", littleEndianBytes[0], littleEndianBytes[1], littleEndianBytes[2], littleEndianBytes[3]);
    printf("Little-Endian decimal: %u, %u, %u, %u\n", littleEndianBytes[0], littleEndianBytes[1], littleEndianBytes[2], littleEndianBytes[3]);
    printf("This is still not matching the input 48 65 72 65.\n");
}

// 12. **Crucial Realization:** I might have been overthinking the conversion 
// from hex *bytes* back to decimal. The input sequence `48 65 72 65` are *already* 
// the decimal values of the bytes. I don't need to convert them *from* hex again.
void crucialRealization() {
    uint8_t decimalBytes[4] = {48, 65, 72, 65};

    printf("Decimal bytes: %u, %u, %u, %u\n", decimalBytes[0], decimalBytes[1], decimalBytes[2], decimalBytes[3]);
}

// 13. **Recalculate using the *input decimal values* as the bytes:**
//     *   Input bytes (decimal): `48`, `65`, `72`, `65`
//     *   Input bytes (hex): `0x30`, `0x41`, `0x48`, `0x41`
void recalculateUsingInputDecimalValues() {
    uint8_t decimalBytes[4] = {48, 65, 72, 65};
    uint32_t bigEndianValue = (decimalBytes[0] << 24) | (decimalBytes[1] << 16) | (decimalBytes[2] << 8) | decimalBytes[3];
    uint32_t littleEndianValue = (decimalBytes[3] << 24) | (decimalBytes[2] << 16) | (decimalBytes[1] << 8) | decimalBytes[0];

    printf("Recalculated using input decimal values:\n");
    printf("Big-Endian: 0x%X = %u\n", bigEndianValue, bigEndianValue);
    printf("Little-Endian: 0x%X = %u\n", littleEndianValue, littleEndianValue);
}

// 14. **Final Check:** Compare calculated values with the target `1701995848`.
//     *   Big-Endian: `809584705` != `1701995848`
//     *   Little-Endian: `1095254320` != `1701995848`
void finalCheck() {
    uint32_t targetValue = 1701995848;
    uint32_t bigEndianValue = 809584705;
    uint32_t littleEndianValue = 1095254320;

    printf("Final check:\n");
    printf("Big-Endian: 0x%X = %u != %u\n", bigEndianValue, bigEndianValue, targetValue);
    printf("Little-Endian: 0x%X = %u != %u\n", littleEndianValue, littleEndianValue, targetValue);
}

// 15. **Conclusion Formulation:**
//     *   State the data type `uint32_t` and its range (0 to 4,294,967,295).
//     *   Explain that the sequence `48 65 72 65` likely represents four 8-bit bytes.
//     *   Explain the concept of endianness (how bytes are ordered).
//     *   Show the calculation for both Big-Endian and Little-Endian interpretation of the input byte sequence.
//     *   Convert the input bytes (48, 65, 72, 65) to hex (0x30, 0x41, 0x48, 0x41) for clarity in calculation.
//     *   Calculate Big-Endian: `0x30414841` = `809584705`.
//     *   Calculate Little-Endian: `0x41484130` = `1095254320`.
//     *   State that neither calculated value matches the target `1701995848`.
//     *   Mention the target value `1701995848` in hex is `0x65726548`.
//     *   Point out the discrepancy: the *bytes* needed to form `1701995848` (either `65 72 65 48` BE or `48 65 72 65` LE, depending on interpretation) do not correspond directly to the *decimal values* `48 65 72 65` when treated as bytes. If the target value `0x65726548` was intended, the input sequence needed would be `101 114 101 72` (Big Endian) or `72 101 114 101` (Little Endian) if interpreting the sequence as decimal byte values. Or, if the *input* sequence `48 65 72 65` (interpreted as ASCII "0AHA") *was* correct, then the resulting `uint32_t` value would be different from the target.
//     * 
void conclusionFormulation() {
    // State the data type and its range
    printf("Data type: uint32_t\n");
    printf("Range: 0 to 4,294,967,295\n");

    // Explain the sequence
    printf("The sequence 48 65 72 65 likely represents four 8-bit bytes.\n");

    // Explain endianness
    printf("Endianness is the order in which bytes are ordered in memory.\n");

    // Convert the input bytes to hex
    uint8_t bytes[4] = {48, 65, 72, 65};
    printf("Input bytes in hex: 0x30, 0x41, 0x48, 0x41\n");

    // Calculate Big-Endian
    uint32_t bigEndianValue = (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
    printf("Big-Endian calculation: 0x%X = %u\n", bigEndianValue, bigEndianValue);

    // Calculate Little-Endian
    uint32_t littleEndianValue = (bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | bytes[0];
    printf("Little-Endian calculation: 0x%X = %u\n", littleEndianValue, littleEndianValue);

    // State that neither calculated value matches the target
    uint32_t targetValue = 1701995848;
    printf("Neither calculated value matches the target %u\n", targetValue);

    // Mention the target value in hex
    printf("Target value in hex: 0x65726548\n");

    // Point out the discrepancy
    printf("Bytes needed for 0x65726548: Big-Endian (65 72 65 48), Little-Endian (48 65 72 65)\n");
    printf("These do not correspond to the input decimal values 48 65 72 65.\n");
    printf("If the input was correct, the resulting uint32_t would differ from the target.\n");
}

