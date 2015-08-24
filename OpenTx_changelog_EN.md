<a href='Hidden comment: 

'></a>

# openTx version history #



## 2923 / Jan 08 2014 ##

### [ARM boards] ###
  * Audio freeze bug fixed
  * Aurora gimbals support

### [FrSky Taranis] ###
  * DSM2 Support
  * New S.PORT sensors support
  * Audio freeze bug fixed
  * Telemetry corruption
  * A2 alarms reinstated in D16 mode for X8R2Analog sensor
  * Telemetry lost alarm no more triggered by a telemetry reset


---


## 2834 / Oct 29 2013 ##

### [all] ###
  * Mixer bug when a MULTIPLY mix used with a slow fixed
  * GVAR popup removed
  * Sticky virtual switches are reset when Reset Flight function is called
  * Altitude played without decimal when >= 10m

### [Boards with SD card] ###
  * Check to avoid too long paths when playing SD files


---


## 2768 / Sep 20 2013 ##

### [all] ###
  * Name badly displayed after SD Model Restore

### [stock] ###
  * Custom switches not working when comparing a timer with a value (stock only without telemetry mod)

### [Boards with SD card] ###
  * Fixes in logging function
  * Confirmation Popup before SD Format

### [FrSky Taranis] ###
  * Model image not reloaded after Copy/Move/Delete/Restore


---


## 2751 / Sep 01 2013 ##

### [all] ###
  * Fixes in translations (FR, IT, PT)


---


## 2746 / Aug 30 2013 ##

### [all] ###
  * Limits are now [-125:0] and [0:125] instead of [-125:25] and [-25:125]
  * INPUTS instead of STICKS for BL activation
  * Curves presets bug fix

### [stock] ###
  * Fix bug with Battery calibration
  * 14051 can be used for THR and AIL connections (telemetry)
  * CH1 PPM output was truncated

### [Boards with SD card] ###
  * Flight mode sound files now are read from: /SOUNDS/(lang)/modelname/fpname-ON.wav and /SOUNDS/(lang)/modelname/fpname-OFF.wav

### [FrSky Taranis] ###
  * Rx voltage was not displayed on main screen if VFAS or CELLS chosen
  * GVARS can now refer to the GVAR of another phase
  * Vario and Altitude bug fixes
  * PPM\_UNIT=PREC0 / US taken into account in channels view
  * DJT removed and receiver number hidden from PXX settings when proto != D16


---


## 2688 / Jul 28 2013 ##

### [stock] ###
  * Fix bug with imperial units

### [gruvin9x] ###
  * Fix bug with imperial units
  * Fix small bug with SOMO 14D

### [Boards with SD card] ###
  * Telemetry logs now split by date


---


## 2667 / Jul 25 2013 (Taranis only) ##

### [FrSky Taranis] ###
  * Backlight brightness adjustment added
  * SWR units removed (audio)
  * Copy/paste/delete of custom switches and custom functions


---


## 2647 / Jul 21 2013 ##

### [all] ###
  * Fix for Replace type mixes with Slow Down >0
  * Fix for custom switches that refer another custom switch
  * Negative timer display fix

### [SD-card enabled boards] ###
  * Logs now include more values, fix for some negative numbers

### [ARM boards] ###
  * All fonts now support language-specific special characters
  * Useless sources (e.g. empty channels) don't appear in the sources anymore

### [FrSky Taranis] ###
  * Fix for a decoding bug in telemetry data
  * Sliders' center points now included in calibration


---


## 2604 / Jul 13 2013 (Taranis only) ##

### [FrSky Taranis] ###
  * Contrast adjustment added


---


## 2590 / Jul 8 2013 (Taranis only) ##

### [FrSky Taranis] ###
  * First official release version!


---


## 2491 / Jun 24 2013 ##

### [all] ###
  * PlaySound has now a repeat argument
  * FAI mode added (disable telemetry other than A1/A2/RSSI for contests)
  * Delays now also apply to 3POS switch!
  * RSSI alarms default thresholds now 45 / 42

### [stock] ###
  * Flash savings
  * Vario sink tones removed
  * Audio files renumbered (see [here](http://openrcforums.com/forum/viewtopic.php?f=45&t=3706#p54008))

### [sky9x] ###
  * Audio mixer: several sounds can now be played simulataneously, and beeps won't interrupt and clear voice alerts anymore. Note that sound files now need to have sampling rates of either 8, 16 or 32kHz and may need to be replaced.


---


## 2413 / May 22 2013 ##

### [all] ###
  * Calibration screen automatically appears following an EEPROM format
  * Wraparound in popup menus

### [stock] ###
  * More options supported (novario / nogps / nogauges)
  * Flash savings
  * Mavlink huge rework by Rienk!

### [sky9x] ###
  * Audio language can now be selected in the general settings! Note that the sound files need to be moved to subfolders of the SOUNDS folder (SOUNDS/en for English, same with it, fr, de, pt, se, cz)
  * More settings for the 2nd PPM port


---


## 2215 / Apr 05 2013 ##

### [all] ###
  * New option AUTOSOURCE to automatically select the stick / pot / switch which is moved when editing a Mix source

### [stock] ###
  * All prompts renumbered to have the "custom" prompts starting at 0 and to be able to use PlayTrack(GVAR) with Adjust(GVAR) to play tracks sequences

### [gruvin9x] ###
  * Possibility to have both BEEPER and SPEAKER enable in the same time

### [sky9x] ###
  * Fixed a bug with audio stopped until next reboot in BackgroundMusic with no track selected
  * Imperial is now an option selectable in the menus
  * Possibility to have both BEEPER and SPEAKER enable in the same time
  * New menu in Main Views / Telemetry Views
  * Vario sounds improved!
  * SD Folders renamed. "9XSOUNDS" becomes "SOUNDS", don't forget to update your cards!

### [FrSky Taranis] ###
  * Too many things to list them all!


---


## 2129 / Mar 21 2013 ##

### [all] ###
  * Rotary encoder feature completely reimplemented
  * New custom switch function v1==x (where == means almost equals)
  * New custom switch function Timer (pulled from er9x)
  * Custom switches now have an extra AND switch
  * Switches and Mix sources order have been reordered to allow one of the next supported options: EXTRA\_3POS
  * Throttle trace precision increased (there were only 16levels)
  * Custom Functions screen reworked to allow more flexibility (momentary switches)
  * New Play Both function (not on ARM boards)
  * Repeat argument for Play Track / Play Both / Play Value functions
  * Timer minute beep now spoken
  * Heli and Thr Cut templates fixed (thanks to Gabriel)
  * Tx Battery added to the sources list (for Play Value or Custom Switches)
  * Possibility to have a silent vario on negative speeds re-enabled
  * Tx Battery graph
  * AdjustGVAR reimplemented (using 4 different modes: numeric value, source, another GVAR or +1/-1, long press MENU to change between modes)
  * PlayTrack can now take a GVAR as argument
  * Minute Beep and Countdown Beep are now timer dependant, instead of applied to all timers of all models
  * PPM frame length automatically adjusted to a safe value when changing the number of channels (still adjustable later)
  * Telemetry screens improved (labels for all items)
  * Mixer weight and offset can now support values up to +/-245%
  * JETI telemetry fixed

### [stock] ###
  * Around 500bytes flash saving, thanks to Andreas who is a new openTx commiter.
  * LONG key press duration is longer
  * Mixer speed improved (around 25%)

### [Atmega 128] ###
  * 6 flight phases instead of 5
  * 16 expos instead of 14
  * 15 custom switches instead of 12
  * 24 custom functions instead of 16
  * Voice queue increased to 16 instead of 8
  * Mixer speed improved (around 25%)

### [gruvin9x] ###
  * 6 flight phases instead of 5
  * 16 expos instead of 14
  * 15 custom switches instead of 12
  * 24 custom functions instead of 16
  * Mixer speed improved (around 25%)

### [sky9x] ###
  * The SD is not started at all in case of reboot
  * Better frequency precision for AUDIO
  * Rotary encoder steps setting


---


## 1947 / Feb 10 2013 ##

### [All] ###
  * Battery warning less obnoxious
  * DSM options clarified
  * Vario support in telemetry data
  * Pot calibration only needs ends, no center anymore

### [stock] ###
  * Rotary encoder support

### [9XR] ###
  * Support added

### [sky9x] ###
  * Rotary encoder button may be used to clear alarms / warnings
  * Larger current range for telemetry
  * Support of s16le wav files


---


## 1692 / Nov 28 2012 ##

### [stock] ###
  * Flash savings
  * Fixed backlight / inactivity timeouts

### [sky9x] ###
  * Fixed bug preventing selection of sound files in the custom functions


---


## 1670 / Nov 22 2012 ##

### [stock] ###
  * Flash savings
  * Screen redraw optimisations
  * Stick -> servo latency reduced
  * Fixed DSM2 instability

### [gruvin9x] ###
  * Fixed WDT reset when changing protocol
  * Fixed stack overflow during backup / restore of models

### [sky9x] ###
  * Rotary encoder navigation improved


---


## 1641 / Nov 18 2012 ##

### [all] ###
  * Full German translation

### [stock] ###
  * Flash savings

### [gruvin9x] ###
  * Bugfixes


---


## 1563 / Nov 9 2012 ##

### [all] ###
  * **New EEPROM format (212), upgrade via C9X required**
  * GVARS new feature! (phases dependant on all boards except stock)
  * Telemetry Screens now dynamic (2 bars / 2 displays / 1bar+1display)
  * Telemetry Bars increased precision
  * [voice] Only 1 digit precision when playing telemetry values
  * General Menu reorganized
  * Throttle Trace resetted when the model is changed

### [stock] ###
  * Flash saving again!

### [atmega 128 on stock board] ###
  * Now supported!
  * 4k useable eeprom, extra graphics and flight-phase specific GVARS!

### [gruvin9x] ###
  * DSM2=PPM now ok

### [sky9x] ###
  * Automatic EEPROM conversion from previous version (212=>213)
  * Up to 3 Telemetry Screens
  * Background Music
  * Coprocessor now supported
  * Lists within Function Switches / Model archive - restore are now sorted alphabetically


---


## 1439 / Sep 29 2012 ##

### [all] ###
  * WSHH can be used as a vario (waiting for tests)
  * Inactivity alarm bug fix (when > 10 minutes)

### [stock] ###
  * Voice Mod bugs fixes
  * Flash savings

### [gruvin9x] ###
  * DBLKEYS option now ok
  * SD Card Logs improvements
  * SD Card Format function (in SD Manager, pressing [MENU Long] on the title)
  * SD File Manager sorts files in alphabetical order
  * Remanent Timers

### [sky9x] ###
  * Mass Storage !!!
  * SD Card Logs
  * SD Card Format function (in SD Manager, pressing [MENU Long] on the title)
  * SD Card Information (type, sectors, speed, size)
  * SD File Manager sorts files in alphabetical order
  * Rotary encoder support
  * When an alarm raises (consumption, temperature), it's displayed on the main screen in place of the Batt Voltage
  * Remanent Timers


---


> ## 1361 / Sep 04 2012 ##

> ### [all] ###
  * English TTS prompts have been improved (thanks Martin for that!)
  * Trim / Keys correctly displayed in DIAG screen (with a 18bytes flash saving on stock)
  * DBLKEYS far more reactive (with a 120bytes flash saving on stock)
  * Inactivity alarm enabled during first Warning Screens (THR / Switches / Alerts)
  * 3 new sounds: Beep1 .. Beep3 with short simple sounds
  * T-Cut template replaced by the Sticky T-Cut
  * An asterisk on a black background will appear on the main screen in case of a reboot of the Tx (should never appear of course, but... better to know if your Tx rebooted during a flight so you can file a bug report)

### [sky9x] ###
  * Temperature alarm
  * Consumption alarm (port from ersky9x)
  * 32000+ files may be displayed in the SD file manager ... for those who have many models


---


## 1335 / Aug 30 2012 ##

### [all] ###
  * Expos and Mixes may belong to a list of Flight Phases (not only FPx and !FPx)
  * Limits may be "symetrical". I let Kilrah explain ;)
  * Many voice improvements (on all platforms). We now have en, it, fr and cz TTS voices
  * Mixer may use as sources "raw" inputs (sticks without any DR/Expos applied). I let Kilrah explain ...
  * DSM Range Check (thanks to Bryan from gruvin9x)
  * New Custom Switches functions: d>=ofs (means difference between 2 values >= ofs) and |d|>=ofs<br>Typical usage: you want to know the Batt value each time it decreases by 0.1V or the Altitude each time it changes by 10meters.<br>
<ul><li>Trainer functions / Instant Trim now have a checkbox to easily enable / disable them<br>
</li><li>Inverting the throttle channel on limits screen now shows a popup warning for confirmation<br>
</li><li>Inactivity alarm more frequent again (every 5 secs)<br>
</li><li>PPM polarity display corrected, was inverted<br>
</li><li>Free EEPROM count corrected<br>
</li><li>Haptic feedback fixes<br>
</li><li>[MENU long] on a switch in Function Switches screen toggles between normal and momentary switch (THR <=> THRm, !THR <=> !THRm)<br>
</li><li>Differential now have 1% steps instead of 2% steps<br>
</li><li>New DBLKEYS option, when editing parameters:<br>
<ul><li>right/left => invert<br>
</li><li>up/down => reset<br>
</li><li>up/right => +100<br>
</li><li>down/left => -100<br>
</li></ul></li><li>Trims don't stop for good when reaching the middle anymore, but just pause half a second<br>
</li><li>Power reading fixed when current source is A1 or A2<br>
</li><li>Templates fixed to take account of the new curve system<br>
</li><li>RSSI Tx and Rx before A1 and A2 in telemetry item list - <b>this is not updated automatically, PLEASE CHECK YOUR SETTINGS!</b>
</li><li>Telemetry-based custom switches do not trigger anymore when no data is received<br>
</li><li>Trim handling fixed on mixes using curves and differential<br>
</li><li>AUTOSWITCH option now reflects switches' physical positions<br>
</li><li>Expo / DRs now allows for EITHER a curve OR an expo value, not both (saves memory, and expo can be replicated on the curve if needed).</li></ul>

<h3>[stock]</h3>
<ul><li>Volume with Voice Mod</li></ul>

<h3>[gruvin9x]</h3>
<ul><li>DSM2 fixed<br>
</li><li>PPM16 fixed<br>
</li><li>Rotary encoder beeps fixed</li></ul>

<h3>[sky9x]</h3>
<ul><li>USB bootloader launched only if Tx is OFF<br>
</li><li>Audio fixes<br>
</li><li>SD card fixes</li></ul>

<hr />

<h2>1195 / Aug 1 2012</h2>
<h3>[all]</h3>
<ul><li>New curves system, all curves can now have 3, 5, 9 or 17 points, both with fixed, even-spaced X coordinates (e.g. 5pt), or user-defined X coordinates (e.g. 5pt')<br>
</li><li>Curves can be completely disabled (NOCURVES option) to save flash if not needed</li></ul>

<h3>[stock]</h3>
<ul><li>SmartieParts V2.2 backlight support (SP22 option)<br>
</li><li>Voice support (experimental)</li></ul>

<h3>[gruvin9x]</h3>
<ul><li>Voice support</li></ul>

<h3>[sky9x]</h3>
<ul><li>SD card logging of telemetry data</li></ul>
