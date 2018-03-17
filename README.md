# line_tracker


Attention!!! Different folders for different versions of of IDEs. For Arduino IDE, all the needed libraries is included inside. There is no need to install.

### Component used:

Controller Board: Arduino Romeo V2.2 (You might need to change the Motor.h if you are using a different motor driver)

IR Sensor: Pololu Analog IR Sensor (Apply for other analog IR sensors as well, you can tweak parameters in the IR sessions inside Config.h)

LDR(Optional)

LED Strip(Optional): Adafruit Neopixel 8 LED strip.

### Basic Tuning Concept:

PD controller: I is programed, but not used.

Basics: You can refer to the Wikipedia introduction [link](https://en.wikipedia.org/wiki/PID_controller).

### Advanced Tuning Concept [Optional]:

Manually smoothen the motion base on the history of the angular command.

### Tuning:

If you are using similar setup, you only need to tune by changing parameters inside Config.h file.

If your setup is very different, you might also want to alter some codes inside Motor.h and .ino file.


Email: brian97cbn@gmail.com

Special thanks to Ultragriffy, bharatkareti, KavNair, Teresawidjaja & asilentsilver