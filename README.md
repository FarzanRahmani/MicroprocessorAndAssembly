# Microprocessor and Assembly

AVR assembly and embedded C laboratory work from my B.Sc. in Computer Engineering at Iran University of Science and Technology. Author: Farzan Rahmani.

The exercises progress from basic microcontroller programming to timers, displays, analog input, serial communication, and interrupts.

## Experiments

| Directory | Focus |
| --- | --- |
| `HW1/`–`HW3/` | Introductory assembly exercises and seven-segment examples |
| `HW4 (7 Segment and timer, clock)/` | Timers and seven-segment clock display |
| `HW5 (LED Matrix, display A to F)/` | LED-matrix scanning and character patterns |
| `HW6 (LCD, clock)/` | LCD interface and clock |
| `HW7 (ADC, Temp sensor and lcd)/` | ADC, LM35 temperature sensing, and LCD output |
| `HW8 (key pad, calculator)/` | Keypad input and calculator |
| `HW9 (serial port, USART, Terminal)/` | USART and terminal communication |
| `HW10 (external interrupts)/` | External-interrupt exercises |
| `exam_19/`, `sample_exams.zip`, `test/` | Exam work, sample material, and introductory tests |

Main homework folders include lab PDFs, code, and supporting project artifacts.

## Toolchain

The C sources use **CodeVisionAVR** conventions and headers such as `mega32.h`, `delay.h`, and `alcd.h`. For example, `HW7.c` identifies an **ATmega32** with an **8 MHz** clock. These files are not standard desktop C programs and are not directly interchangeable with avr-gcc projects.

## Reproducing a Lab

1. Read the corresponding `AZ-*.pdf` and inspect the source header for the selected chip and clock.
2. Open the available project in a compatible AVR development environment, or recreate its compiler/device settings.
3. Check I/O pin mappings, LCD connections, timers, ADC reference, and peripheral configuration against the lab circuit.
4. Build firmware with the matching toolchain and load it into the associated simulator or correctly wired target hardware.

Use each lab's own settings rather than assuming the `HW7` configuration applies everywhere. Existing compiler outputs are historical artifacts; rebuild from source when changing the circuit or toolchain. Supporting utilities may be platform-specific.

## License

See [LICENSE](LICENSE) for repository license terms. Generated-code notices and third-party utilities retain their original attribution and terms.
