# Building OpenTX on a Linux PC #
The following instructions describe how to set up the build environment, retrieve the source code and lastly build OpenTX on a Linux machine. A completely blank machine running Linux Mint 15 (Olivia) has been used to verify the instructions. Almost any other Linux distribution should be usable, but it may be necessary to make slight adjustments due to other packages being installed as default.
## Set up the tool chain for 9x ##
A number of tools and libraries have to be installed. Install them by executing the following command line:

**sudo apt-get install gcc gcc-avr avr-libc build-essential libfox-1.6-dev subversion**

This is all you need to install to build transmitter simulators for any radio and binaries for the 9x and 9xr radios.

## Retrieve the source code ##
The source code is hosted on googlecode. Fetch a copy of the latest version by executing this command:

**svn checkout http://opentx.googlecode.com/svn/trunk/ opentx**

## Build OpenTX ##
Enter the resulting opentx/src directory. You may now execute any of the following commands:
| **make** | This builds in a loadable 9x binary file (opentx.bin) with default selections|
|:---------|:-----------------------------------------------------------------------------|
| **make simu** | This results in an executable 9x simulator that can be started on the PC. To start it enter **./simu** |
| **make simu TRANSLATIONS=SE** | This results in an executable 9x simulator with Swedish texts that can be started on the PC. Enter **./simu** to start it |
| **make simu PCB=TARANIS** | This results in an executable Taranis simulator that can be started on the PC. To start it enter **./simu** |
| **make clean** | Remove compiled files and directories. Good to use when you have messed something up and want a clean start |

Play around with the different build options. You find them listed in the [CompilationOptions](CompilationOptions.md) page.

## Build OpenTX binaries for Taranis ##
Taranis has another processor than the 9x. To compile Taranis binaries you need to install both the 9x tool chain from above  and and an ARM tool chain. You do not need the ARM tool chain if you do not intend to build Taranis binaries. The ARM libraries are not available in the normal repository. The easiest way to install them is to fetch them directly from this location:
https://launchpad.net/gcc-arm-embedded. Look for and download a file called something like _gcc-arm-none-eabi-4\_7-2013q3-20130916-linux.tar.bz2_

Now change to the download directory. Then unpack the file and move it to the proper location. The last thing to do is to add it to the environment variable. Here are the commands that are needed:

**tar xjvf gcc-arm-none-eabi-4\_7-2013q3-20130916-linux.tar.bz2**

**sudo mv gcc-arm-none-eabi-4\_7-2013q3 /opt/ARM**

**echo "PATH=$PATH:/opt/ARM/bin" >> /home/"$(whoami)"/.bashrc**

**source /home/"$(whoami)"/.bashrc**

Check that the path works by checking the version of the installed software

**arm-none-eabi-gcc --version**

You are now able to build Taranis binaries:

| **make PCB=TARANIS** | This builds a loadable Taranis binary file|
|:---------------------|:------------------------------------------|