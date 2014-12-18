ESP8266 - Driver for the 24xx32, 24xx64, 24xx128, 24xx256 and 24xx512 series serial EEPROM from ATMEL
=====================================================================================================

<b>Схема подключения ATMEL AT24C512 к ESP-01:</b><br>
Вывод EEPROM 4 (GND) подключен к GND ESP-01<br>
Вывод EEPROM 8 (Vcc) подключен к Vcc (3.3 Вольта) ESP-01<br>
Вывод EEPROM 5 (SDA) подключен к GPIO2 ESP-01<br>
Вывод EEPROM 6 (SCL) подключен к GPIO0 ESP-01 (смотрите файл i2c.h)<br>
Вывод EEPROM 7 (WP)  подключен к GND ESP-01<br>
Вывод EEPROM 1 (A0)  подключен к GND ESP-01<br>
Вывод EEPROM 2 (A1)  подключен к GND ESP-01<br>

<b>Сборка под Windows:</b><br>
1. <a href="http://programs74.ru/get.php?file=EspressifESP8266DevKitX86">Скачайте</a> и установите компилятор и SDK.<br>
2. <a href="http://sourceforge.net/projects/mingw/files/Installer/">Скачайте</a> и установите MinGW. Запускаем mingw-get-setup.exe, в процессе установки выберите режим без GUI, то есть уберите галочку "...also install support for the graphical user interface".<br>
3. <a href="http://programs74.ru/get.php?file=EspressifESP8266DevKitAddon">Скачайте</a> (84Mb) набор моих скриптов для автоматизации установки дополнительных модулей для MinGW.<br>
4. Запустите из моего набора файл install-mingw-package.bat. Он установит основные модули для MinGW, установка должна пройти без ошибок.<br>
5. Установите <a href="http://git-scm.com/download/win">Git for Windows</a> (после установки потребуется перезагрузить компьютер).<br>
6. Запускаем консоль C:\MinGW\msys\1.0\msys.bat<br>
7. В консоле выполните:<br>
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
EEPROM 6 (SCL) to GPIO0 ESP-01 (see file i2c.h)<br>
EEPROM 7 (WP)  to GND ESP-01<br>
EEPROM 1 (A0)  to GND ESP-01<br>
EEPROM 2 (A1)  to GND ESP-01<br>

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
