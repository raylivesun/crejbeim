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

// Okay, let's break this down. It looks like you're asking if the sequence 
// of four 8-bit values (`48`, `65`, `72`, `65`) can be combined to form the 
// `uint32_t` value `1701995848`.

// 1.  **`uint32_t`**:
//     *   `u`: Unsigned (0 and positive values).
//     *   `int`: Integer type.
//     *   `32`: Uses exactly 32 bits (which is 4 bytes).
//     *   `_t`: Standard type suffix.
//     *   **Range**: 0 to 2<sup>32</sup> - 1 (0 to 4,294,967,295).
int main() {
    uint32_t val = (48 << 24) | (65 << 16) | (72 << 8) | 65;
    printf("0x%x\n", val);
    return 0;
}

// 2.  **Combining Bytes**: To form a 32-bit integer from four 8-bit 
//     bytes (`48`, `65`, `72`, `65`), we need to consider **endianness** 
//     (the order in which bytes are arranged in memory).

//     *   **Byte values in Hexadecimal**:
//         *   `48` (decimal) = `0x30` (hex)
//         *   `65` (decimal) = `0x41` (hex)
//         *   `72` (decimal) = `0x48` (hex)
//         *   `65` (decimal) = `0x41` (hex)
void combineBytes() {
    uint32_t bigEndianValue = (48 << 24) | (65 << 16) | (72 << 8) | 65;
    uint32_t littleEndianValue = (65 << 24) | (72 << 16) | (65 << 8) | 48;
    printf("Big-Endian: 0x%X = %u\n", bigEndianValue, bigEndianValue);
    printf("Little-Endian: 0x%X = %u\n", littleEndianValue, littleEndianValue);
    printf("Target Value: 0x%X = %u\n", 1701995848, 1701995848);
    printf("Big-Endian: %u != %u\n", bigEndianValue, 1701995848);
    printf("Little-Endian: %u != %u\n", littleEndianValue, 1701995848);
    printf("Target Value in Hex: 0x%X\n", 1701995848);
    printf("Bytes needed for 0x%X: Big-Endian (65 72 65 48), Little-Endian (48 65 72 65)\n", 1701995848);
    printf("These do not correspond to the input decimal values 48 65 72 65.\n");
    printf("If the input was correct, the resulting uint32_t would differ from the target.\n");
    printf("If the target value was intended, the input sequence needed would be 101 114 101 72 (Big Endian) or 72 101 114 101 (Little Endian).\n");    
}

// *   **Big-Endian**: The first byte is the most significant byte (MSB).
// *   `0x30` `0x41` `0x48` `0x41` -> `0x30414841`
// *   `0x30414841` (hex) = `(3 * 16^7) + (0 * 16^6) + (4 * 16^5) + (1 * 16^4) + (4 * 16^3) + (8 * 16^2) + (4 * 16^1) + (1 * 16^0)`
// *   `= 805,306,368 + 0 + 4,194,304 + 65,536 + 16,384 + 2,048 + 64 + 1`
// *   `= 809,584,705` (decimal)
void bigEndian() {
    uint32_t bigEndianValue = (48 << 24) | (65 << 16) | (72 << 8) | 65;
    uint32_t littleEndianValue = (65 << 24) | (72 << 16) | (65 << 8) | 48;
    printf("Big-Endian: 0x%X = %u\n", bigEndianValue, bigEndianValue);
    printf("Little-Endian: 0x%X = %u\n", littleEndianValue, littleEndianValue);
    printf("Target Value: 0x%X = %u\n", 1701995848, 1701995848);
    printf("Big-Endian: %u != %u\n", bigEndianValue, 1701995848);
    printf("Little-Endian: %u != %u\n", littleEndianValue, 1701995848);
    printf("Target Value in Hex: 0x%X\n", 1701995848);
    printf("Bytes needed for 0x%X: Big-Endian (65 72 65 48), Little-Endian (48 65 72 65)\n", 1701995848);
    printf("These do not correspond to the input decimal values 48 65 72 65.\n");
}

// *   **Little-Endian**: The first byte is the least significant byte (LSB). The sequence is effectively reversed when forming the number.
// *   Bytes in order: `48`, `65`, `72`, `65` (hex: `0x30`, `0x41`, `0x48`, `0x41`)
// *   Number formed: `0x41` `0x48` `0x41` `0x30` -> `0x41484130`
// *   `0x41484130` (hex) = `(4 * 16^7) + (1 * 16^6) + (4 * 16^5) + (8 * 16^4) + (4 * 16^3) + (1 * 16^2) + (3 * 16^1) + (0 * 16^0)`
// *   `= 1,073,741,824 + 16,777,216 + 4,194,304 + 524,288 + 16,384 + 256 + 48 + 0`
// *   `= 1,095,254,320` (decimal)
void littleEndian() {
    uint32_t bigEndianValue = (48 << 24) | (65 << 16) | (72 << 8) | 65;
    uint32_t littleEndianValue = (65 << 24) | (72 << 16) | (65 << 8) | 48;
    printf("Big-Endian: 0x%X = %u\n", bigEndianValue, bigEndianValue);
    printf("Little-Endian: 0x%X = %u\n", littleEndianValue, littleEndianValue);
    printf("Target Value: 0x%X = %u\n", 1701995848, 1701995848);
    printf("Big-Endian: %u != %u\n", bigEndianValue, 1701995848);
    printf("Little-Endian: %u != %u\n", littleEndianValue, 1701995848);
    printf("Target Value in Hex: 0x%X\n", 1701995848);
    printf("Bytes needed for 0x%X: Big-Endian (65 72 65 48), Little-Endian (48 65 72 65)\n", 1701995848);
    printf("These do not correspond to the input decimal values 48 65 72 65.\n");
    printf("If the input was correct, the resulting uint32_t would differ from the target.\n");
    printf("If the target value was intended, the input sequence needed would be 101 114 101 72 (Big Endian) or 72 101 114 101 (Little Endian).\n");
    printf("The target value 1701995848 in hex is 0x65726548.\n");

}

// 3.  **Target Value**: `1701995848`
//     *   Let's convert the target value to hexadecimal:
//     *   `1701995848` (decimal) = `0x65726548` (hex)
void targetValue() {
    uint32_t bigEndianValue = (48 << 24) | (65 << 16) | (72 << 8) | 65;
    uint32_t littleEndianValue = (65 << 24) | (72 << 16) | (65 << 8) | 48;
    printf("Big-Endian: 0x%X = %u\n", bigEndianValue, bigEndianValue);
    printf("Little-Endian: 0x%X = %u\n", littleEndianValue, littleEndianValue);
    printf("Target Value: 0x%X = %u\n", 1701995848, 1701995848);
    printf("Big-Endian: %u != %u\n", bigEndianValue, 1701995848);
    printf("Little-Endian: %u != %u\n", littleEndianValue, 1701995848);
    printf("Target Value in Hex: 0x%X\n", 1701995848);
    printf("Bytes needed for 0x%X: Big-Endian (65 72 65 48), Little-Endian (48 65 72 65)\n", 1701995848);
    printf("These do not correspond to the input decimal values 48 65 72 65.\n");
    printf("If the input was correct, the resulting uint32_t would differ from the target.\n");
    printf("If the target value was intended, the input sequence needed would be 101 114 101 72 (Big Endian) or 72 101 114 101 (Little Endian).\n");
    printf("The target value 1701995848 in hex is 0x65726548.\n");
}
