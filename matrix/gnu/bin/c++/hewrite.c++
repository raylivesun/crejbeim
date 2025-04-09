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

// Okay, let's evaluate these numbers against the `int16_t` data type.

// 1.  **`int16_t`**: This is a standard C/C++ integer type.
//     *   `int`: Integer type.
//     *   `16`: Uses exactly **16 bits** of memory.
//     *   `_t`: Standard type suffix.
//     *   **Signed**: It's a *signed* integer type (using two's complement).
void analyzeInt16_t() {
    // int16_t properties
    printf("int16_t:\n");
    printf("  *   int: Integer type.\n");
    printf("  *   16: Uses exactly **16 bits** of memory.\n");
    printf("  *   _t: Standard type suffix.\n");
    printf("  *   Signed: It's a *signed* integer type (using two's complement).\n");
}

// 2.  **Range of `int16_t`**: A 16-bit signed integer can represent values from:
//     *   -2<sup>(16-1)</sup> to +2<sup>(16-1)</sup> - 1
//     *   -2<sup>15</sup> to +2<sup>15</sup> - 1
//     *   **-32,768** to **+32,767**
void determineRangeOfInt16_t() {
    // Determine the range of int16_t
    printf("Range of int16_t: %d to %d\n", INT16_MIN, INT16_MAX);
}

// Okay, let's evaluate these numbers against the `int16_t` data type.

// 1.  **`int16_t`**: This is a standard C/C++ integer type.
//     *   `int`: Integer type.
//     *   `16`: Uses exactly **16 bits** of memory.
//     *   `_t`: Standard type suffix.
//     *   **Signed**: It's a *signed* integer type (using two's complement).

// 2.  **Range of `int16_t`**: A 16-bit signed integer can represent values from:
//     *   -2<sup>(16-1)</sup> to +2<sup>(16-1)</sup> - 1
//     *   -2<sup>15</sup> to +2<sup>15</sup> - 1
//     *   **-32,768** to **+32,767**

// 3.  **Numbers to check**: `46`, `65`, `25928`

// 4.  **Evaluation**:
//     *   Is `46` within the range [-32768, 32767]? **Yes**.
//     *   Is `65` within the range [-32768, 32767]? **Yes**.
//     *   Is `25928` within the range [-32768, 32767]? **Yes**.

// **Conclusion:**

// All three numbers (`46`, `65`, and `25928`) **can be correctly represented** by the `int16_t` data type as they all fall within its valid range of -32,768 to 32,767.
void evaluateNumbersAgainstInt16_t() {
    // 1.  **`int16_t`**: This is a standard C/C++ integer type.
    printf("1.  **`int16_t`**: This is a standard C/C++ integer type.\n");
    printf("    *   `int`: Integer type.\n");
    printf("    *   `16`: Uses exactly **16 bits** of memory.\n");
    printf("    *   `_t`: Standard type suffix.\n");
    printf("    *   **Signed**: It's a *signed* integer type (using two's complement).\n");

    // 2.  **Range of `int16_t`**: A 16-bit signed integer can represent values from:
    printf("2.  **Range of `int16_t`**: A 16-bit signed integer can represent values from:\n");
    printf("    *   -2<sup>(16-1)</sup> to +2<sup>(16-1)</sup> - 1\n");
    printf("    *   -2<sup>15</sup> to +2<sup>15</sup> - 1\n");
    printf("    *   **-32,768** to **+32,767**\n");

    // 3.  **Numbers to check**: `46`, `65`, `25928`
    int numbersToCheck[] = {46, 65, 25928};
    int numbersToCheckLength = sizeof(numbersToCheck) / sizeof(numbersToCheck[0]);

    printf("3.  **Numbers to check**: ");
    for (int i = 0; i < numbersToCheckLength; i++) {
        printf("%d", numbersToCheck[i]);
        if (i < numbersToCheckLength - 1) {
            printf(", ");
        }
    }
    printf("\n");

    // 4.  **Evaluation**:
    printf("4.  **Evaluation**:\n");
    for (int i = 0; i < numbersToCheckLength; i++) {
        int number = numbersToCheck[i];
        printf("    *   Is %d within the range [-32768, 32767]? **%s**.\n", number, (number >= INT16_MIN && number <= INT16_MAX) ? "Yes" : "No");
    }

    // **Conclusion:**
    printf("**Conclusion:**\n");
    for (int i = 0; i < numbersToCheckLength; i++) {
        int number = numbersToCheck[i];
        printf("All three numbers (%d, %d, and %d) **%s be correctly represented** by the `int16_t` data type as they all fall within its valid range of -32,768 to 32,767.\n", number, numbersToCheck[(i + 1) % numbersToCheckLength], numbersToCheck[(i + 2) % numbersToCheckLength], (number >= INT16_MIN && number <= INT16_MAX) ? "can" : "cannot");
    }
}

int main() {
    evaluateNumbersAgainstInt16_t();
    return 0;
}