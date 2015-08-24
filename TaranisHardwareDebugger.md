### The Hardware you'll need ###

  * This board: STM32F4 DISCOVERY USB STM32F407VGT6 STM32 ARM Cortex-M4 Development Board (you will find it on [eBay](http://cgi.ebay.fr/ws/eBayISAPI.dll?ViewItem&item=151033382663))
  * These 1.25 plugs: Mini. Micro 1.25 T-1 4-Pin JST Connector w/.Wire x 10 sets (you will also find them on [ebay](http://cgi.ebay.fr/ws/eBayISAPI.dll?ViewItem&item=181198791446#ht_3569wt_1031))
  * One 100 Ohms SMD resistor
  * One JWT 4 pins connector (I got them from [HobbyKing](http://www.hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=29279))
  * The mini USB cable (the one you use to flash your radio everyday)


### The Software you'll need ###

  * STM32 ST-LINK utility with the associated driver ([here](http://www.st.com/web/en/catalog/tools/PF258168))
  * OpenOCD 0.7.0 (André prepared a beautiful zip for us [here](https://code.google.com/p/opentx/downloads/detail?name=openocd-0.7.0.zip))
  * The GCC ARM toolchain ([here](https://launchpad.net/gcc-arm-embedded/+download))


### Preparation ###

  * Solder the 100 Ohm resistor on the empty [R2](https://code.google.com/p/opentx/source/detail?r=2) slot of the discovery board (next to the SWD connector)
  * Solder the mini JST plug on the Taranis board here:
  * Prepare your cable according to this schema:
    * JTMS -> SWDIO
    * JTCK -> SWCLK
    * GND  -> GND
    * VCC  -> VDD

![https://opentx.googlecode.com/svn/wiki/images_debugger/taranis_swd.jpg](https://opentx.googlecode.com/svn/wiki/images_debugger/taranis_swd.jpg)

![https://opentx.googlecode.com/svn/wiki/images_debugger/discovery.jpg](https://opentx.googlecode.com/svn/wiki/images_debugger/discovery.jpg)

### Installation ###

  * Install the STM32 ST-LINK utility, it will automatically install the driver for the board
  * Plug the board through the mini-usb cable. The board will be detected and the driver correctly setup
  * Start the STM32 ST-LINK utility, go in the ST-LINK menu and choose Firmware Update. Check that the board is correctly detected and start the update.

### Start the debugging ###

  * Connect everything
  * Start a cmd window and launch OpenOCD with this script:
```
   openocd-stlinkv2.bat
```
  * Start another cmd window, go inside the openTX src directory and launch gdb this way:
```
   "C:\Program Files (x86)\GNU Tools ARM Embedded\4.7 2013q3\bin\arm-none-eabi-gdb.exe" opentx.elf
```
  * Now inside gdb:
```
   target remote :3333
   monitor reset
   break perMain
   cont
```
> The program should stop in perMain
```
 set unexpectedShutdown = 1
 cont
```
> You should now see the asterisk in the notification bar
```
 set unexpectedShutdown = 0
 cont
```
> The asterisk should be removed now!

Enjoy!