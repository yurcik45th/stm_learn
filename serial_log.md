Here’s a **full basic guide** for using **Serial logs** in C++ (`Arduino.h`) on a **Bluepill STM32**:

---

### 1. **Wiring**
- Connect **A9** (TX) to USB-UART adapter **RX**.
- Connect **A10** (RX) to USB-UART adapter **TX** (optional, only needed if you send data to board).
- Connect **GND** from Bluepill to USB-UART adapter **GND**.

---

### 2. **Setup in Code**

```cpp
#include <Arduino.h>

void setup() {
  Serial.begin(9600);  // Start UART1 at 9600 baud
  while (!Serial);     // Wait for serial port to connect (only needed for some boards)
}

void loop() {
  Serial.println("Hello, world!");
  delay(1000);
}
```

- `Serial.begin(9600)` — initializes UART1 (pins A9/A10).
- `Serial.println()` — sends a message to your PC over USB-UART.

---

### 3. **View Logs**

- Open **PlatformIO Serial Monitor** (`PlatformIO → Monitor` OR shortcut `Ctrl + Alt + M`)  
- OR use **Arduino IDE Serial Monitor** if programming via Arduino.

Make sure monitor speed = **9600 baud** (must match `Serial.begin()`).

---

### 4. **Real Useful Cases**

| Use Case | Code Example |
|:---------|:-------------|
| **Print variables** | `Serial.println(sensorValue);` |
| **Debug flow** | `Serial.println("Button Pressed");` |
| **Print formatted text** | `Serial.printf("X: %d, Y: %d\n", x, y);` |
| **Monitor errors** | `if (error) Serial.println("Error detected!");` |
| **Check PWM/Duty** | `Serial.println(dutyCycle);` |
| **Timing** | `Serial.println(millis());` |

---

### 5. **Advanced**
- Multiple UARTs: Bluepill has **Serial1**, **Serial2**, **Serial3**.
  - Example:  
    ```cpp
    Serial2.begin(115200);  // Use Serial2 (pins A2/A3)
    Serial2.println("From Serial2");
    ```

- Change Baudrate:  
  Higher baud like `115200` is faster and stable.

- Use `Serial.read()` to **receive** data if needed.

---

**Tip:** Always start logging simple prints like "Start" first to confirm connection.  
If you don't see anything → check wires, COM port, and baudrate.

---

Would you like me to also show examples like:  
- Debugging PWM signal  
- Printing incoming receiver data  
- Measuring execution time?  
(very handy for your Bluepill project) 🚀


---

**Example:**

To log text + value **together on one line**, do:

```cpp
Serial.print("The speed of motor is: ");
Serial.println(valueOfMotorSpeed);
```

✅ This prints the value right **after** the text, then **moves to next line**.

---

If you want **everything in one command**, you can use:

```cpp
Serial.printf("The speed of motor is: %d\n", valueOfMotorSpeed);
```

✅ `%d` is for integers.
✅ `\n` moves to **new line** automatically.

---

**Important:**
If you use only `Serial.print()`, it **stays on same line**.
Only `Serial.println()` or `\n` goes to **next line**.

---

**Example output:**
```
The speed of motor is: 1200
The speed of motor is: 1250
The speed of motor is: 1300
```

(Each log on new line ✅)

---

Want examples for float values too? (like motor voltage = 12.56V) 🚀


