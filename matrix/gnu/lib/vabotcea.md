Okay, you're asking how to use the hyperbolic cosine (`cosh`) and hyperbolic sine (`sinh`) functions within programming libraries.

You're in luck! These functions are standard mathematical operations and are included in the built-in math libraries of almost all major programming languages. You typically don't need to install external packages for them.

Here's how you'd typically find and use them in several popular languages:

**General Concepts:**

*   **Math Library/Module:** Most languages have a standard library dedicated to mathematical functions (often called `math`, `Math`, `cmath`, etc.).
*   **Floating-Point Numbers:** These functions usually operate on and return floating-point numbers (like `float`, `double`, or equivalent).
*   **Input:** The input `x` to `cosh(x)` and `sinh(x)` is a dimensionless real number (representing the hyperbolic angle parameter).

**Examples:**

1.  **Python:**
    *   Uses the `math` module.
    *   Functions: `math.cosh(x)`, `math.sinh(x)`

    ```python
    import math

    x = 1.0

    cosh_result = math.cosh(x)
    sinh_result = math.sinh(x)

    print(f"cosh({x}) = {cosh_result}") # Output: cosh(1.0) = 1.5430806348152437
    print(f"sinh({x}) = {sinh_result}") # Output: sinh(1.0) = 1.1752011936438014
    ```

2.  **JavaScript:**
    *   Uses the built-in global `Math` object.
    *   Functions: `Math.cosh(x)`, `Math.sinh(x)`

    ```javascript
    let x = 1.0;

    let coshResult = Math.cosh(x);
    let sinhResult = Math.sinh(x);

    console.log(`cosh(${x}) = ${coshResult}`); // Output: cosh(1.0) = 1.5430806348152437
    console.log(`sinh(${x}) = ${sinhResult}`); // Output: sinh(1.0) = 1.1752011936438014
    ```

3.  **Java:**
    *   Uses static methods from the `java.lang.Math` class (automatically available).
    *   Functions: `Math.cosh(x)`, `Math.sinh(x)` (typically operate on `double`).

    ```java
    public class HyperbolicDemo {
        public static void main(String[] args) {
            double x = 1.0;

            double coshResult = Math.cosh(x);
            double sinhResult = Math.sinh(x);

            System.out.println("cosh(" + x + ") = " + coshResult); // Output: cosh(1.0) = 1.5430806348152437
            System.out.println("sinh(" + x + ") = " + sinhResult); // Output: sinh(1.0) = 1.1752011936438014
        }
    }
    ```

4.  **C++:**
    *   Uses the `<cmath>` header (preferred C++ way) or `<math.h>` (C-style).
    *   Functions: `std::cosh(x)`, `std::sinh(x)` (usually operate on `double`, with `float` and `long double` overloads available).

    ```c++
    #include <iostream>
    #include <cmath> // Include the cmath header

    int main() {
        double x = 1.0;

        double cosh_result = std::cosh(x); // Use std::cosh
        double sinh_result = std::sinh(x); // Use std::sinh

        std::cout << "cosh(" << x << ") = " << cosh_result << std::endl; // Output: cosh(1.0) = 1.54308
        std::cout << "sinh(" << x << ") = " << sinh_result << std::endl; // Output: sinh(1.0) = 1.1752

        return 0;
    }
    ```

5.  **C#:**
    *   Uses static methods from the `System.Math` class.
    *   Functions: `Math.Cosh(x)`, `Math.Sinh(x)` (note the PascalCase convention). Operate on `double`.

    ```csharp
    using System;

    public class HyperbolicDemo
    {
        public static void Main(string[] args)
        {
            double x = 1.0;

            double coshResult = Math.Cosh(x);
            double sinhResult = Math.Sinh(x);

            Console.WriteLine($"cosh({x}) = {coshResult}"); // Output: cosh(1.0) = 1.5430806348152437
            Console.WriteLine($"sinh({x}) = {sinhResult}"); // Output: sinh(1.0) = 1.1752011936438014
        }
    }
    ```

**In summary:**

To use `cosh` and `sinh` in your code:

1.  Identify the standard math library/module/class for your language.
2.  Import or include it if necessary (often not needed for Java, JavaScript, C#).
3.  Call the respective `cosh` and `sinh` functions, passing your numeric variable as the argument.