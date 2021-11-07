# GSM alarm system with ultrasonic sensor

This GSM alarm system turns on siren and calls defined phone number when sensor detects movement. It contains one LED for indication, when specific SMS ("ON") is sent to a module from
authorised phone number, LED turns on and system is now in "Active mode". In this mode system will turn on siren and call defined phone number if ultrasonic sesnor detects object
50cm or closer to it (distance can be changed easily in if statement). To turn off alarm system, simply send SMS ("OFF") a module and LED for indication will turn off.

System is based on Arduino nano platform connected with GPRS GSM SIM900 shield (pins 7 and 8 of Arduino to RX and TX of GSM module).

## Components

* LED for indication
* Ultrasonic sensor
* Siren
* Arduino Nano
* GSM GPRS SIM900 shield
