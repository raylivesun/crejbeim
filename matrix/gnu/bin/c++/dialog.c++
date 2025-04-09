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

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Okay, let's break that down. You've provided two representations of the same numerical value:\n"
              << "  1.  **`hex 48`**: This is the number represented in **hexadecimal** (base-16).\n"
              << "     *   In hexadecimal, the digits are 0-9 and A-F (representing 10-15).\n"
              << "     *   `48` in hex means: (4 * 16¹) + (8 * 16⁰) = (4 * 16) + (8 * 1) = 64 + 8 = **72** in decimal.\n";
    return 0;
}

void *thread_function(void *arg) {
    std::cout << "This is a thread function." << std::endl;
    return nullptr;
}

void signal_handler(int signum) {
    std::cout << "Signal " << signum << " received." << std::endl;
}
void setup_signal_handler() {
    signal(SIGINT, signal_handler);
}
void setup_thread() {
    pthread_t thread;
    pthread_create(&thread, nullptr, thread_function, nullptr);
    pthread_join(thread, nullptr);
}
// 2.  **Recognize the formats:**
//     *   `hex 48`: Represents the number 48 in hexadecimal (base-16).
//     *   `uint8_t 72`: Represents the number 72 in decimal (base-10), explicitly stating it's stored as an 8-bit unsigned integer (`uint8_t` is a common C/C++ type).

void recognize_formats() {
    std::cout << "Recognizing the formats." << std::endl;
}

// 2.  **`uint8_t 72`**: This is the number **72** represented in **decimal** (base-10).
//     *   `uint8_t` is a data type (common in C/C++ and other languages) meaning an **unsigned integer** that uses **8 bits** of memory.
//     *   An 8-bit unsigned integer can store values from 0 to 2⁸ - 1, which is 0 to 255.
//     *   The value 72 falls within this range.

void check_value_range() {
    std::cout << "Checking value range." << std::endl;
}

// **Conclusion:**

// `hex 48` and `uint8_t 72` represent the **exact same numerical value**.

// *   `48` is the hexadecimal way to write the number.
// *   `72` is the decimal way to write the number.
// *   `uint8_t` specifies how the number 72 is stored in memory 
// (as an 8-bit unsigned integer).

// **Bonus:** In the ASCII character encoding standard, the decimal 
// value 72 (or hex 48) represents the uppercase letter **'H'**.
void concusion() {
    std::cout << "Conclusion: hex 48 and uint8_t 72 represent the same numerical value." << std::endl;
}


