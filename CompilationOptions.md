# Introduction #

Here is the list of all compile options available in openTx so that you may choose the ones that you need / want.

To compile the firmware here is the syntax:
```
make OPTION1=VALUE1 OPTION2=VALUE2...
```

# Options #
<table border='1'>
<blockquote><tr>
<blockquote><td><b><i>Option</i></b></td>
<td><b><i>Default</i></b></td>
<td><b><i>Alternatives</i></b></td>
<td><b><i>Description</i></b></td>
</blockquote></tr>
<tr>
<blockquote><td>3POS</td>
<td><b>NO</b></td>
<td>POT1, POT2, POT3</td>
<td>Enable another 3 position switch to replace a pot</td>
</blockquote></tr>
<tr>
<blockquote><td>ARITHMETIC_OVERFLOW_CHECK</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Adds additional code to prevent arithmetic overflows</td>
</blockquote></tr>
<tr>
<blockquote><td>AUDIO</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Better Audio feedback (needs audio TX modification)</td>
</blockquote></tr>
<tr>
<blockquote><td>AUTOSOURCE</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Sources automatic selection</td>
</blockquote></tr>
<tr>
<blockquote><td>AUTOSWITCH</td>
<td><b>NO</b></td>
<td>YES</td>
<td>In model setup menus automatically set switch <br> by moving some of them</br></td>
</blockquote></tr>
<blockquote><tr>
</blockquote><blockquote><td>BATTGRAPH</td>
<td><b>NO</b></td>
<td>YES</td>
<td>TX battery graph on main screen</td>
</blockquote></tr>
<tr>
<blockquote><td>BLUETOOTH</td>
<td><b>NO</b></td>
<td>YES</td>
<td>When sky9x board used: Bluetooth support added</td>
</blockquote></tr>
<tr>
<blockquote><td>BOLD</td>
<td><b>YES</b></td>
<td>NO</td>
<td>In setup menu will be bold active FPs, DR/Expos, <br>Mixes and Switches</br> </td>
</blockquote></tr>
<tr>
<blockquote><td>CORRECT_NEGATIVE_VALUES</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Corrects different rounding for negative values. <br>Instead of -99.9 you see -100.0, but uses more flash</br></td>
</blockquote></tr>
<tr>
<blockquote><td>CURVES</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Curves support </td>
</blockquote></tr>
<tr>
<blockquote><td>DBLKEYS</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Double key press [+/-] invert, [+/UP] max, <br> [-/DOWN] min, [UP/DOWN] reset to default)</br></td>
</blockquote></tr>
<tr>
<blockquote><td>DEBUG</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Activates debug mode</td>
</blockquote></tr>
<tr>
<blockquote><td>DEFAULT_MODE</td>
<td><b>NO</b></td>
<td>1, 2, 3, 4</td>
<td>Default TX mode</td>
</blockquote></tr>
<tr>
<blockquote><td>DSM2</td>
<td><b>NO</b></td>
<td>SERIAL, PPM</td>
<td>DSM2 protocol</td>
</blockquote></tr>
<tr>
<blockquote><td>EEPROM_PROGRESS_BAR</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Progress bar on EEPROM writing</td>
</blockquote></tr>
<tr>
<blockquote><td>EXT</td>
<td><b>STD</b></td>
<td>FRSKY, JETI, NMEA, <br>ARDUPILOT, MAVLINK,</br>TELEMETREZ</td>
<td>Telemetry extension (needs TX modification)</td>
</blockquote></tr>
<tr>
<blockquote><td>FAI</td>
<td><b>NO</b></td>
<td>YES, CHOICE</td>
<td>Enables FAI rules restrictions</td>
</blockquote></tr>
<tr>
<blockquote><td>FLIGHT_MODES</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Flight modes support </td>
</blockquote></tr>
<tr>
<blockquote><td>FONT</td>
<td><b>STD</b></td>
<td>STD, SQT5</td>
<td>Select font. The SQT5 font is heavier and looks <br> best on the low contrast display of the Taranis</br></td>
</blockquote></tr>
<tr>
<blockquote><td>FRSKY_HUB</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Frsky Hub supported (when EXT=FRSKY) </td>
</blockquote></tr>
<tr>
<blockquote><td>GAUGES</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Telemetry screen also as GAUGES</td>
</blockquote></tr>
<tr>
<blockquote><td>GPS</td>
<td><b>YES</b></td>
<td>NO</td>
<td>GPS data support (saves 1.5k flash if disabled)</td>
</blockquote></tr>
<tr>
<blockquote><td>GRAPHICS</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Graphical sliders and check boxes </td>
</blockquote></tr>
<tr>
<blockquote><td>GVARS</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Global Variables</td>
</blockquote></tr>
<tr>
<blockquote><td>HAPTIC</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Haptic feedback (needs haptic TX modification)</td>
</blockquote></tr>
<tr>
<blockquote><td>HELI</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Heli support and menus </td>
</blockquote></tr>
<blockquote><tr>
<td>NAVIGATION</td>
<td><b>NO</b></td>
<td>POT1, POT2, POT3,<br>POTS, ROTENC</br></td>
<td>Use only POT1/2/3 in menus navigation <br>or all POTS, or Rotary encoder</br></td>
</blockquote></tr>
<tr>
<blockquote><td>PCB</td>
<td><b>9X</b></td>
<td>9X128, 9XR, 9XR128, <br>9XR2561, GRUVIN9X, </br>MEGA2560, SKY9X,<br>TARANIS</br></td>
<td>Stock 9X/9XR or with Atmega 128, <br>gruvin9x, ersky9x, X9D boards</br></td>
</blockquote></tr>
<blockquote><tr>
</blockquote><blockquote><td>PCBREV</td>
<td><b>REV1</b> (gruvin9x) <br><b>REVC</b> (ersky9x)</br></td>
<td>REV0, REVA, REVB</td>
<td>Revision of the board <br>(ersky9x REVC/B/A or gruvin9x REV1/0)</br></td>
</blockquote></tr>
<blockquote><tr>
</blockquote><blockquote><td>PPM_CENTER_ADJUSTABLE</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Adjustable PPM center for servos in limits menu</td>
</blockquote></tr>
<blockquote><tr>
</blockquote><blockquote><td>PPM_LIMITS_SYMETRICAL</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Symetrical PPM limits for servos in limits menu</td>
</blockquote></tr>
<blockquote><tr>
</blockquote><blockquote><td>PPM_UNIT</td>
<td><b>PERCENT_PREC1</b></td>
<td>PERCENT_PREC0, US</td>
<td>Units for PPM center in % or µs with precision 0 or 1 </td>
</blockquote></tr>
<tr>
<blockquote><td>PWM_BACKLIGHT</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Fade IN/OUT Backlight using PWM</td>
</blockquote></tr>
<tr>
<blockquote><td>PXX</td>
<td><b>NO</b></td>
<td>YES</td>
<td>PXX protocol (dev in progress...)</td>
</blockquote></tr>
<tr>
<blockquote><td>RTCLOCK</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Real time clock for gruvin9x, sky9x, x9d boards </td>
</blockquote></tr>
<tr>
<blockquote><td>SP22</td>
<td><b>NO</b></td>
<td>YES</td>
<td><code>SmartieParts</code> 2.2 Backlight support</td>
</blockquote></tr>
<tr>
<blockquote><td>SPLASH</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Splash displayed on Tx start </td>
</blockquote></tr>
<tr>
<blockquote><td>TEMPLATES</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Templates screen enabled </td>
</blockquote></tr>
<tr>
<blockquote><td>TRANSLATIONS</td>
<td><b>EN</b></td>
<td>CZ, DE, ES, FR, IT, PL,<br>PT, SE</br></td>
<td>User interface language</td>
</blockquote></tr>
<tr>
<blockquote><td>TTS</td>
<td>same as <br>TRANSLATIONS</br></td>
<td>CZ, DE, ES, EN, FR, IT,<br>PL, PT, SE, SK</br></td>
<td>Voice language</td>
</blockquote></tr>
<tr>
<blockquote><td>TX_CADDY</td>
<td><b>NO</b></td>
<td>YES</td>
<td>For auto-switching between DSM2/X <br>and Fr-Sky transmitter modules on gruvin9x board</br></td>
</blockquote></tr>
<tr>
<blockquote><td>UNITS</td>
<td><b>METRIC</b></td>
<td>IMPERIAL</td>
<td>Metric or Imperial units </td>
</blockquote></tr>
<tr>
<blockquote><td>VARIO</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Enable variable tone telemetry vario (when EXT=FRSKY)</td>
</blockquote></tr>
<tr>
<blockquote><td>VOICE</td>
<td><b>NO</b></td>
<td>YES</td>
<td>Play Voice files (needs voice TX modification)</td>
</blockquote></tr>
<tr>
<blockquote><td>WS_HOW_HIGH</td>
<td><b>YES</b></td>
<td>NO</td>
<td>Winged Shadow How High supported (when EXT=FRSKY) </td>
</blockquote></tr>
</table>