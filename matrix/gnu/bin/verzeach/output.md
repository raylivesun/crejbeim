Okay, let's break this down:

1.  **`int8_t`**: This is a data type commonly found in C and C++.
    *   `int`: Specifies an integer type.
    *   `8`: Specifies that it uses exactly 8 bits of memory.
    *   `_t`: A standard suffix indicating it's a defined type.
    *   **Signed**: By default (and standard definition), `intN_t` is a *signed* integer type. This means it uses one bit for the sign (positive/negative) and the remaining bits for the magnitude, typically using two's complement representation.

2.  **Range of `int8_t`**: An 8-bit signed integer can represent values from **-128** to **+127**.

3.  **`48` and `72`**: These are decimal integer values.

**Conclusion:**

Both the numbers `48` and `72` **can be correctly represented** by the `int8_t` data type because they fall within its valid range of -128 to 127.

In binary (as 8-bit two's complement):
*   `48` is `00110000`
*   `72` is `01001000`