ESP8266 - Driver for the 24xx32, 24xx64, 24xx128, 24xx256 and 24xx512 series serial EEPROM from ATMEL
=====================================================================================================

<b>����� ����������� ATMEL AT24C512 � ESP-01:</b><br>
EEPROM 4 (GND) to GND ESP-01<br>
EEPROM 8 (Vcc) to Vcc (3.3 ������) ESP-01<br>
EEPROM 5 (SDA) to GPIO2 ESP-01<br>
EEPROM 6 (SCL) to GPIO0 ESP-01 (�������� ���� i2c.h)<br>
EEPROM 7 (WP)  to GND ESP-01<br>
EEPROM 1 (A0)  to GND ESP-01<br>
EEPROM 2 (A1)  to GND ESP-01<br><br>

<b>������ ��� Windows:</b><br>
1. <a href="http://programs74.ru/get.php?file=EspressifESP8266DevKitX86">��������</a> � ���������� ���������� � SDK.<br>
2. <a href="http://sourceforge.net/projects/mingw/files/Installer/">��������</a> � ���������� MinGW. ��������� mingw-get-setup.exe, � �������� ��������� �������� ����� ��� GUI, �� ���� ������� ������� "...also install support for the graphical user interface".<br>
3. <a href="http://programs74.ru/get.php?file=EspressifESP8266DevKitAddon">��������</a> (84Mb) ����� ���� �������� ��� ������������� ��������� �������������� ������� ��� MinGW.<br>
4. ��������� �� ����� ������ ���� install-mingw-package.bat. �� ��������� �������� ������ ��� MinGW, ��������� ������ ������ ��� ������.<br>
5. ���������� <a href="http://git-scm.com/download/win">Git for Windows</a> (����� ��������� ����������� ������������� ���������).<br>
6. ��������� ������� C:\MinGW\msys\1.0\msys.bat<br>
7. � ������� ���������:<br>
```
cd /c/Espressif/examples
git clone https://github.com/CHERTS/esp8266-i2c_24xx32
cd esp8266-i2c_24xx32
make
make flash
```

--

<b>For a single device, connect as follows ATMEL AT24C512 to ESP-01:</b><br>
EEPROM 4 (GND) to GND ESP-01<br>
EEPROM 8 (Vcc) to Vcc (3.3 Volts) ESP-01<br>
EEPROM 5 (SDA) to GPIO2 ESP-01<br>
EEPROM 6 (SCL) to GPIO0 ESP-01 (see i2c.h)<br>
EEPROM 7 (WP)  to GND ESP-01<br>
EEPROM 1 (A0)  to GND ESP-01<br>
EEPROM 2 (A1)  to GND ESP-01<br><br>

<b>Building on Windows:</b><br>
1. <a href="http://programs74.ru/get.php?file=EspressifESP8266DevKitX86">Download</a> and install compiler and SDK.<br>
2. <a href="http://sourceforge.net/projects/mingw/files/Installer/">Download</a> and install MinGW. Run mingw-get-setup.exe, the installation process to select without GUI, ie uncheck "... also install support for the graphical user interface".<br>
3. <a href="http://programs74.ru/get.php?file=EspressifESP8266DevKitAddon">Download</a> (84Mb) set my scripts to automate the installation of additional modules for MinGW.<br>
4. Run the file from my set of install-mingw-package.bat. He will establish the basic modules for MinGW, installation should proceed without error.<br>
5. Install <a href="http://git-scm.com/download/win">Git for Windows</a> (after installation to restart the computer).<br>
6. Run the console C:\MinGW\msys\1.0\msys.bat<br>
7. In the console, run:<br>
```
cd /c/Espressif/examples
git clone https://github.com/CHERTS/esp8266-i2c_24xx32
cd esp8266-i2c_24xx32
make
make flash
```
