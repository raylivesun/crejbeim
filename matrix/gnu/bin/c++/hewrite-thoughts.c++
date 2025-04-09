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

// Here's a thinking process to evaluate 
// "46 65 int16_t 25928":

// 1.  **Identify the components:** The input seems to be a 
// list of numbers (`46`, `65`, `25928`) and a data type (`int16_t`).

void hewrite_thoughts()
{
    // 2.  **Understand the data type:**
    //     *   What does `int16_t` mean?
    //         *   `int`: Integer type.
    //         *   `16`: Uses 16 bits of memory.
    //         *   `_t`: Standard type definition suffix.
    //         *   Implicitly `signed` (as it doesn't start with `u`).
    //     *   What is the range of a *signed* 16-bit integer?
    //         *   It uses 1 bit for the sign and 15 bits for the magnitude (in two's complement).
    //         *   Minimum value: -2^(16-1) = -2^15 = -32,768
    //         *   Maximum value: 2^(16-1) - 1 = 2^15 - 1 = 32,767
    //         *   So the range is **-32,768 to +32,767**.

    // 3.  **Evaluate each number against the range:**
    //     *   **`46`**: Is 46 within the range [-32768, 32767]? Yes, it is.
    //     *   **`65`**: Is 65 within the range [-32768, 32767]? Yes, it is.
    //     *   **`25928`**: Is 25928 within the range [-32768, 32767]? No, it is not (25928 is greater than 32767).

    // 4.  **Formulate the conclusion:** All the provided numbers (`46`, `65`, and `25928`) do not fit within the valid range of the `int16_t` data type.
}

// 3.  **Evaluate each number against the range:**
//     *   **`46`**: Is 46 within the range [-32768, 32767]? Yes, it is.
//     *   **`65`**: Is 65 within the range [-32768, 32767]? Yes, it is.
//     *   **`25928`**: Is 25928 within the range [-32768, 32767]? Yes, it is (25928 is less than 32767).
void evaluateNumbers() {
    int numbers[] = {46, 65, 25928};
    const int minValue = -32768;
    const int maxValue = 32767;

    for (int number : numbers) {
        if (number >= minValue && number <= maxValue) {
            printf("%d is within the range [%d, %d].\n", number, minValue, maxValue);
        } else {
            printf("%d is not within the range [%d, %d].\n", number, minValue, maxValue);
        }
    }
}

// 4.  **Formulate the conclusion:** All the provided numbers (`46`, `65`, and `25928`) 
// fit within the valid range of the `int16_t` data type.
void formulateConclusion()
{
    printf("\nConclusion:\n");
    printf("All the provided numbers (46, 65, and 25928) fit within the valid range of the int16_t data type.\n");
}


// 5.  **Refine the output (optional but good practice):**
//     *   Clearly state the data type and its range.
//     *   Explicitly check each number against the range.
//     *   Provide a final summary statement.
//     *   (Optional: Show binary representations, although less critical here since they all fit easily).
//         *   `46`: `00000000 00101110`
//         *   `65`: `00000000 01000001`
//         *   `25928`: `01100101 01001000` (Can verify this: 2^14 + 2^13 + 2^10 + 2^8 + 2^6 + 2^3 = 16384 + 8192 + 1024 + 256 + 64 + 8 = 25928)
void refineOutput()
{
    printf("\nRefined Output:\n");
    printf("The data type is int16_t and its range is [-32768, 32767].\n");

    int numbers[] = {46, 65, 25928};
    const int minValue = -32768;
    const int maxValue = 32767;

    for (int number : numbers) {
        if (number >= minValue && number <= maxValue) {
            printf("%d is within the range [%d, %d].\n", number, minValue, maxValue);
        } else {
            printf("%d is not within the range [%d, %d].\n", number, minValue, maxValue);
        }
    }

    printf("\nFinal Summary: All the provided numbers (46, 65, and 25928) fit within the valid range of the int16_t data type.\n");
}

// 4.  **Determine the Combination Method (Endianness):** How are these 4 bytes 
//     combined into a single 32-bit integer? This depends on **endianness**.
//     *   **Little-Endian:** The *least* significant byte (LSB) is stored at the 
//     lowest memory address. When interpreting a sequence like `48 65 72 65`, the 
//     first byte (`48`) is treated as the LSB, and the last byte (`65`) is treated 
//     as the *most* significant byte (MSB).
//         *   Value = `65` << 24 | `72` << 16 | `65` << 8 | `48` << 0
//     *   **Big-Endian:** The *most* significant byte (MSB) is stored at the lowest 
//     memory address. The first byte (`48`) is treated as the MSB, and the last byte 
//    (`65`) is treated as the LSB.
//         *   Value = `48` << 24 | `65` << 16 | `72` << 8 | `65` << 0
void determineEndianness()
{
    printf("\n4.  **Determine the Combination Method (Endianness):** How are these 4 bytes combined into a single 32-bit integer? This depends on **endianness**.\n");
    printf("*   **Little-Endian:** The *least* significant byte (LSB) is stored at the lowest memory address. When interpreting a sequence like `48 65 72 65`, the first byte (`48`) is treated as the LSB, and the last byte (`65`) is treated as the *most* significant byte (MSB).\n");
    printf("*   Value = `65` << 24 | `72` << 16 | `65` << 8 | `48` << 0\n");
    printf("*   **Big-Endian:** The *most* significant byte (MSB) is stored at the lowest memory address. The first byte (`48`) is treated as the MSB, and the last byte (`65`) is treated as the LSB.\n");
    printf("*   Value = `48` << 24 | `65` << 16 | `72` << 8 | `65` << 0\n");
}

// 10. **Connect to the Input:** The input sequence is `48 65 72 65`.
//     *   The Little-Endian *byte representation* of the target decimal 
//    number `1701995848` (which is `0x65726548`) is `48`, `65`, `72`, `65`. 
//    *Wait, that doesn't seem right.*
void connectToInput() {
    uint32_t targetValue = 1701995848;
    uint8_t inputBytes[4] = {48, 65, 72, 65};

    // Little-Endian interpretation
    uint32_t littleEndianValue = (inputBytes[0] << 0) |
                                 (inputBytes[1] << 8) |
                                 (inputBytes[2] << 16) |
                                 (inputBytes[3] << 24);

    printf("Input bytes: %u, %u, %u, %u\n", inputBytes[0], inputBytes[1], inputBytes[2], inputBytes[3]);
    printf("Little-Endian value: %u\n", littleEndianValue);

    if (littleEndianValue == targetValue) {
        printf("Little-Endian byte representation matches the target value.\n");
    } else {
        printf("Little-Endian byte representation does not match the target value.\n");
    }
}

// *   **Big-Endian Combination:** Treat `48` as MSB, `65` as LSB.
// *   Value = `48` << 24 | `65` << 16 | `72` << 8 | `65` << 0
// *   Hex: `0x30` << 24 | `0x41` << 16 | `0x48` << 8 | `0x41` << 0
// *   Hex: `0x30000000` | `0x00410000` | `0x00004800` | `0x00000041` = `0x30414841`
// *   Decimal: `809584705` (Calculated correctly before)

// *   **Little-Endian Combination:** Treat `48` as LSB, `65` as MSB.
// *   Value = `65` << 24 | `72` << 16 | `65` << 8 | `48` << 0
// *   Hex: `0x41` << 24 | `0x48` << 16 | `0x41` << 8 | `0x30` << 0
// *   Hex: `0x41000000` | `0x00480000` | `0x00004100` | `0x00000030` = `0x41484130`
// *   Decimal: `1095254320` (Calculated correctly before)
void calculateEndianness() {
    // Big-Endian combination
    uint32_t bigEndianValue = (48 << 24) | (65 << 16) | (72 << 8) | (65 << 0);
    printf("Big-Endian value: %u\n", bigEndianValue);

    // Little-Endian combination
    uint32_t littleEndianValue = (65 << 24) | (72 << 16) | (65 << 8) | (48 << 0);
    printf("Little-Endian value: %u\n", littleEndianValue);
}
