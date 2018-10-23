Quick startup guide:
* In order to solve permission problems with the serial port on Ubuntu, run: sudo usermod -a -G dialout <your_username>
* Log out and log in again
* Download and install Arduino IDE from https://www.arduino.cc/en/Main/Software
* In Arduino IDE, File -> Preferences, find Additional Boards Manager URLs and enter http://arduino.esp8266.com/stable/package_esp8266com_index.json
* Tools -> Board -> Boards Manager, filter for ESP8266 and install the newest version.
* Tools -> Board -> select "LOLIN (WeMOS) D1 R2 & mini"

