# Programming #

## Firmware and App by Maarten Weyn ##

This Project currently lacks the whole programming/software part. Luckily Maarten Weyn already made the inverse kinematics work and wrote also an Smartphone App for simple Control of this Robot via BLE. Take a look into his Repository as well:
https://github.com/maartenweyn/SpotMicro_ESP32

### Quickstart Maartens Firmware ###

* calibrate your servos (do this before assembly, otherwise you have more work to do). You can find here a [quick explanation of how to achieve this](https://github.com/michaelkubina/SpotMicroESP32/tree/master/assembly#servo-calibration).
* install the [ESP-IDF in VSCode](https://github.com/michaelkubina/SpotMicroESP32/tree/master/code#esp-idf) for the firmware-developement and get [Cordova](https://github.com/maartenweyn/SpotMicro_ESP32/tree/master/code/cordova) for the app-developement running
* clone [maartens firmware-repo](https://github.com/maartenweyn/SpotMicro_ESP32/tree/master/code/esp-idf/ik_test) and 
	* account for the missing relay in his code. You can overcome the relay being in the way in two ways:
		* connect NC instead of NO (always active after power-up, if no signal to the relay) to your PCA9685 V+ (terminal block) and switch it back, once you have a solid code-base that accounts for it.
		* OR do the code-thing right away and leave it as it is...like this:
			**config.h**
			```
			#define RELAY_IO    27
			```

			**main.c -> void app_main()**
			
			```
			...
			gpio_pad_select_gpio(RELAY_IO);
			gpio_set_direction(RELAY_IO, GPIO_MODE_OUTPUT);
			gpio_set_level(RELAY_IO,1); // 1 = on, 0 = off
			```
	* clone the [esp-dsp (digital signal processing)](https://github.com/espressif/esp-dsp) **component** into maartens repo's corresponding component folder
	* compile and flash
* compile the cordova app and flash onto your android phone (or iphone, but i dont own an iphone and cant help here)
* install [arduino ide](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)
	* get this [firmware for your ESP32-CAM](https://github.com/easytarget/esp32-cam-webserver)
	* add your local wifi credentials to the configuration
	* flash the ESP32_CAM with this firmware and access the live-stream/cam interface via your webbrowser

## Firmware by Guna ##

An walking gait implementation and voice-commanding was achieved by Guna R. from the slacks #spotmicro-esp32 channel, whis is build upon Maartens software (see Repo above). You definitly have to take a look there as well and contribute:
https://github.com/cholan2100/ceasar


**Work-in-Progress : still a lot to do**

This section currently contains some basic test-programs for servo-calibration and circuit-/module-tests. 

## Arduino IDE ##

You can use the Arduino IDE for the developement of your ESP32 programs. A good resource for the setup can be found here:

[Setup Arduino IDE](https://randomnerdtutorials.com/installing-the-esp32-board-in-arduino-ide-windows-instructions/)

## ESP-IDF ##

The ESP-IDF is the developement framework provided by Espressif. Here's the official documentation how to get started:

[Setup ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html#get-started)

### Quick Installation Guide - Downloads ###

If you don't want to get into the hurdle to install the ESP-IDF via the official documentation, you can follow this quick installation guide. It has been only tested for Windows 10 machines, so the Steps on Linux or Mac OS X will vary.

For a complete Installation you will need to install:

* [Python](https://www.python.org/downloads/)
* [Git](https://git-scm.com/download/win)
* [MinGW-w64](http://mingw-w64.org/doku.php/download/mingw-builds)
* [Visual Studio Code (VSCode)](https://code.visualstudio.com/download)
* [C/C++ Extension for VSCode](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
* [ESP-IDF Extension for VSCode (from VSCode Marketplace)](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension)

### Quick Installation Guide - Steps ###

1. Install Python by checking the "Add Python _VERSION_ to PATH" checkbox and simply choose the "Install Now" option. If you are interested in a more detailed description how to further setup Python, it can be found here: [Official Python Install Guide](https://docs.python.org/3/using/windows.html)
1. Install Git
1. Install MinGW-w64 and choose a simpler installation directory path like C:\MinGW\
1. Install VSCode - if you are interested in some more informations about the VSCode Setup than take a look at the [Official VSCode Setup Documentation](https://code.visualstudio.com/docs/setup/setup-overview)
1. Start VSCode and 
	1. install the C/C++ Extension from the VSCode Marketplace
	1. install the ESP-IDF Extension from the VSCode Marketplace. Use the Express Install as mentioned here: [VSCode ESP-IDF Extension Github](https://github.com/espressif/vscode-esp-idf-extension/blob/master/docs/SETUP.md#setup-wizard)
		1. update some of your *system variables*
			1. add ";%IDF_PATH%\tools" to PATH
			1. add a new variable named "IDF_PATH" with the value "C:\Users\INSERT_YOUR_USER_DIRECTORY\esp\esp-idf"
	1. add the path to the MinGW C-Standard Libraries Headers to your C/C++ configuration in VSCode
		1. Press F1 for the Command Menu
		1. type and choose "C/C++: Edit Configuration (UI)" and navigate to the "advanced settings" at the bottom
		1. add your path (example below) to the browse.path:  
			${config:idf.espIdfPath}/components  
			${config:idf.espIdfPathWin}/components  
			${workspaceFolder}  
			*C:\MinGW\mingw64\x86_64-w64-mingw32\include*
1. Done!

### Starting a new Project ###

Either open a available project/firmware (like the one from Maarten Weyn or Guna) in VSCode or start your own via:

1. Add a folder to your Workspace "Edit -> Add Folder to Workspace"
1. Press F1 for the Command Menu and type "ESP-IDF: Create Project" - a more detailed description can be found here: [Official VSCode-ESP-IDF-Extension How-to-Use](https://github.com/espressif/vscode-esp-idf-extension#how-to-use)
	1. Choose the App-Template
	1. Change "project" within the CMakeLists.txt to whatever you want to call yours
1. Have fun coding!

Everything you need to know, can be found in the [Official ESP-IDF API Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/index.html)	alongside with many linked example-projects to their [Github Examples Page](https://github.com/espressif/esp-idf/tree/master/examples).
