#include <stdalign.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <linux/kd.h>
#include <linux/input.h>
#include <linux/vt.h>
#include <fcntl.h>
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
#include <linux/if_tun.h>
#include <linux/if_vlan.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <linux/if_arp.h>
#include <linux/if_packet.h>

#include <iostream>
#include <climits>

// This C++ code checks if the hexadecimal value 0x48 (which is equivalent to decimal 72) 
// can be represented by a uint8_t (an unsigned 8-bit integer) and a char (a signed character). 
// It then prints out the results of these checks

int main() {
    // Hexadecimal representation
    int hexValue = 0x48;

    // uint8_t representation
    uint8_t uint8Value = 72;

    // Check if the two values are equivalent
    if (hexValue == uint8Value) {
        std::cout << "hex 48 is equivalent to uint8_t 72." << std::endl;
    } else {
        std::cout << "hex 48 is not equivalent to uint8_t 72." << std::endl;
    }

    // TODO: Add code to check if the value can be represented
    // as a signed char
    if (hexValue <= SCHAR_MAX) {
        char signedCharValue = hexValue;
        std::cout << "hex 48 can be represented as signed char." << std::endl;
    } else {
        std::cout << "hex 48 cannot be represented as signed char." << std::endl;
    }

    return 0;
}

#include <iostream>
#include <iomanip>

int think_obs() {
    // Hexadecimal representation
    int hexValue = 0x48;

    // uint8_t representation
    uint8_t uint8Value = 72;

    // Output the representations
    std::cout << "Hexadecimal 0x48 is: " << std::dec << hexValue << " in decimal." << std::endl;
    std::cout << "uint8_t 72 is: " << std::hex << static_cast<int>(uint8Value) << " in hexadecimal." << std::endl;

    return 0;
}

int compareHexDec() {
    // Hexadecimal representation
    int hexValue = 0x48;

    // Decimal representation
    int decValue = 72;

    // Convert hex to decimal
    int hexToDec = hexValue;

    // Compare the converted hex value to the decimal value
    if (hexToDec == decValue) {
        std::cout << "hex 48 is equivalent to decimal 72." << std::endl;
    } else {
        std::cout << "hex 48 is not equivalent to decimal 72." << std::endl;
    }

    return 0;
}

int hexToDecConversion() {
    // Hexadecimal representation
    int hexValue = 0x48;

    // Perform hexadecimal to decimal conversion
    int decValue = (hexValue / 16 * 10) + (hexValue % 16);

    // Print the result
    std::cout << "hex 48 converted to decimal is: " << decValue << std::endl;

    return 0;
}

int compareHexDecConv() {
    // Hexadecimal representation
    int hexValue = 0x48;

    // Decimal representation
    int decValue = 72;

    // Perform hexadecimal to decimal conversion
    int hexToDec = (hexValue / 16 * 10) + (hexValue % 16);

    // Compare the converted hex value to the decimal value
    if (hexToDec == decValue) {
        std::cout << "hex 48 converted to decimal is equivalent to decimal 72." << std::endl;
    } else {
        std::cout << "hex 48 converted to decimal is not equivalent to decimal 72." << std::endl;
    }

    return 0;
}

int connectToUint8t() {
    // Hexadecimal representation
    int hexValue = 0x48;

    // uint8_t representation
    uint8_t uint8Value = 72;

    // Check if the two values are equivalent
    if (hexValue == uint8Value) {
        std::cout << "hex 48 is equivalent to uint8_t 72." << std::endl;
    } else {
        std::cout << "hex 48 is not equivalent to uint8_t 72." << std::endl;
    }

    // TODO: Add code to check if the value can be represented
    // as a signed char
    if (hexValue <= SCHAR_MAX) {
        char signedCharValue = hexValue;
        std::cout << "hex 48 can be represented as signed char." << std::endl;
    } else {
        std::cout << "hex 48 cannot be represented as signed char." << std::endl;
    }

    return 0;
}

