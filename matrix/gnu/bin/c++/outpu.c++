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

int main(int argc, char *argv[])
{
    printf("1.  **`int8_t`**: This is a data type commonly found in C and C++.\n");
    printf("    *   `int`: Specifies an integer type.\n");
    printf("    *   `8`: Specifies that it uses exactly 8 bits of memory.\n");
    printf("    *   `_t`: A standard suffix indicating it's a defined type.\n");
    printf("    *   **Signed**: By default (and standard definition), `intN_t` is a *signed* integer type. This means it uses one bit for the sign (positive/negative) and the remaining bits for the magnitude, typically using two's complement representation.\n");
    return 0;
}

// 2.  **Range of `int8_t`**: An 8-bit signed integer 
// can represent values from **-128** to **+127**.
void *thread_function(void *arg) {
    printf("This is a thread function.\n");
    return nullptr;
}
void signal_handler(int signum) {
    printf("Signal %d received.\n", signum);
}
void setup_signal_handler() {
    signal(SIGINT, signal_handler);
}
void setup_thread() {
    pthread_t thread;
    pthread_create(&thread, nullptr, thread_function, nullptr);
    pthread_join(thread, nullptr);
}


// 3.  **`48` and `72`**: These are decimal integer values.
void explain_values() {
    printf("3.  **`48` and `72`**: These are decimal integer values.\n");
    printf("    *   `48`: Represents the decimal number forty-eight.\n");
    printf("    *   `72`: Represents the decimal number seventy-two.\n");
}

// **Conclusion:**

// Both the numbers `48` and `72` **can be correctly represented** 
//by the `int8_t` data type because they fall within its valid 
// range of -128 to 127.

// In binary (as 8-bit two's complement):
// *   `48` is `00110000`
// *   `72` is `01001000`
void explain_binary_representation() {
    printf("Both the numbers `48` and `72` **can be correctly represented** by the `int8_t` data type because they fall within its valid range of -128 to 127.\n");
    printf("In binary (as 8-bit two's complement):\n");
    printf("*   `48` is `00110000`\n");
    printf("*   `72` is `01001000`\n");
}

