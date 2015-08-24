# Features in openTx: #


---

**`*`** - New in last firmware

  * Calculation _**speed optimizations**_
  * Less Flash, Less RAM used (depending on FW options)

> # Main view #
  * _**Virtual Switches Screen**_ for showing Custom Switches CS1-CSC state
  * _**CH1-8 and CH9-16 values and bars**_ screens switchable with LEFT/RIGHT
  * One Warning screen for _**all switches**_
  * _**LowEEPROM Warning**_ screens with non blocking transmission
<a href='Hidden comment: 
=General setup=
'></a>
> # RADIO SETUP #
  * _**Graphical Sliders**_ for Speaker and Haptic length
  * _**Speaker Mode/Length/Strength**_ separated (compile option)
  * _**Haptic Mode/Length/Strength**_ separated (compile option)
  * Graphical _**ON/OFF Check boxes**_
  * **_Backlight mode_** respond on Key press, Stick move or both
  * Changing _**Stick Mode**_ without mix mess-up.

> # MODEL SETUP #
> ## MODELSEL ##
  * Select Model with LONG MENU (not EXIT)
  * Copy Model with MENU press
  * Move Model with DOUBLE MENU press
  * More accurate _**Free EEPROM**_ calculation
  * Checking switches, Throttle stick and LowEEPROM on model load.

> ## SETUPmodel ##
  * Switching _**Lower/Uper case characters in Model Name**_ with Long LEFT/RIGHT press
  * A full featured _**Timer2**_
  * Model based _**Throttle warning**_
  * It's possible to switch  _**TX Stick Mode**_ without messing everything in mixes
  * The _**throttle trace**_ in statistics and THt/s/% for Timers can be dependent on Channels and Pots, not only Thr
  * THt means trigger: the timer starts at _**THR trigger**_ and doesn't stop when Thr is again at idle
  * Model based _**Startup Switches warning**_
    1. On S-Warning press MENU to toggle ON / OFF
    1. Place your switches in the default position
    1. Press LONG MENU to store them, they will be displayed near the ON / OFF
  * Graphical _**ON/OFF Check boxes**_
  * Options not included in compiled FW are displayed in square bracket `[PXX], [DSM2]`

> ## FLIGHT PHASES ##
  * _**5 Flight Phases**_ with Fade In/Out and elective self trims.
  * Fade In/Out from 0 to 7.5 seconds
  * **Bold FPx** for active Flight Phases

> ## DR/EXPO ##
  * _**DR/Expo**_ with Curve and Flight Phase support
  * **Bold weight** for active DR/EXPO
  * **_More Flight Phases_** on one DR/EXPO line

> ## MIXER ##
  * _**Inverted curves**_ in Mixes and Expos
  * _**Switches like a Mix Sources**_
  * **_3POS_** source in Mixers and Custom Switches means ID0/1/2 which returns -100% / 0 / +100%
  * Simple _**Difference for Ailerons**_
  * _**Trims like a slider**_ - trims can be used as source of mix (_**TrmR, TrmE, TrmT, TrmA**_)
  * Trims in mixes can be selected from OFF, ON, Rud, Ele, Thr, Ail - it's possible to _**cross trims between sticks**_
  * **_Fast Inverting values_** by pressing +- at same time
  * Slow and Delay Up/Down from 0 to 7.5 seconds
  * **Bold source** for active mixes
  * **_More Flight Phases_** on one mix line
  * **`*`** **_Extended Weight and Offset_** to +/-245

> ## LIMITS ##
  * **_PPM Center Adjustment_** in limits (compile option - ppmca)
  * _**PPM Limit Units**_ percent or microseconds (compile option - ppmus)
  * _**Symmetrical**_ limits (compile option - symlimits)
  * _**Channel**_ value _**2 Offset**_ pressing MENU then LONG MENU on Offset
  * **_Trims 2 Offset_**

> ## CURVES ##
  * 8 curves with _**3, 5, 9 or 17 points**_
  * _**Custom Curves**_ with _**custom X**_ values for each point
  * Editable Global Variables that can be used in Mixes and Expos like Weight, Expo and Offset

> ## CUSTOM SWITCHES ##
  * TX Battery (**_Batt_**), **_Timers_** and **_Telemetry_** inputs in _**Custom Switches**_
  * Trims can be used as source of custom switch, (_**TrmA, TrmT, TrmE, TrmR**_) for V1 and V2 values
  * **Bold CSx** for active Custom Switches
  * **`*`** **_Second AND_** condition where 012TREAG3456789 corresponds to ID0 ID1 ID2 THR RUD ELE AIL GEA CS3 CS4 CS5 CS6 CS7 CS8 CS9

> ## CUSTOM FUNCTIONS ##
  * **_Safety Channels_** (security switches) with ON/OFF switch
  * Graphical _**ON/OFF Check boxes**_
  * **_Trainer_** switches
  * **_Instant_** trim
  * **_Play sounds_** switches
  * **_Haptic_** switches
  * **_Reset_** timers and/or telemetry values
  * **_Vario_** audio alerts
  * **_Play Track_** with voice hardware modification
  * **`*`** **_Play Both_** function where 256/7 means plaing file 256 (switch ON) and 257 (switch OFF) (voice hardware modification)
  * **_Play Value_** of some source (voice hardware modification)
  * selectable _**Backlight**_ switch
  * **_Adjust GV_** - Adjust Global Variables with four different type of sources. To change GV parameter source type press LONG MENU
    1. Souces (sticks, pots, switches ...)
    1. Step +1/-1
    1. GV1-GV5
    1. Constant (-125 to 125)
  * Momentary switches _**GEAm**_ play sound/haptic only once
  * Options not included in compiled FW are displayed in square bracket `[Haptic], [Vario]`
  * **Bold switch** for active Function Switches
  * **`*`** **_Repeat timers_** (15/30/60 seconds) for Play Value, Play Both, Play Track

> ## TELEMETRY ##
  * Support for _**`FrSky` HUB**_ 2.0 sensors
  * **_FAS100_** current sensor support
  * **_Voltage, Current and Consumption_** from battery
  * for easier set up Range and Offset, _**A1/A2**_ displaying _**live value**_ on telemetry setup screen
  * Screen with _**Custom Telemetry**_ view with sensors min/max options
  * Screen with _**Telemetry Bars**_
  * _**Thresholds**_ in Telemetry Bars. A1/A2/RSSI threshold is first alarm value, <br>for other telemetry sensors thresholds are set up by Custom Switch and Function Switch combination.<br>
<ul><li><i><b>Vario acoustic</b></i> warnings limits for falling/elevation<br>
</li><li>supports <b><i>Metric or Imperial units</i></b> (compile option)<br>
</li><li><b><code>*</code></b> Telemetry source <b><i>Batt</i></b> means <b><i>TX</i></b> battery voltage<br>
</li><li><b><i>Cell</i></b> and <b><i>Cells</i></b> telemetry sources are from <b><i>RC model</i></b> battery (<code>FrSky</code> sensors)<br>
</li><li>Two custom telemetry <b><i>screens</i></b> with four Bars or eight Numbers</li></ul>

<blockquote><h2>Other compile options</h2>
</blockquote><ul><li><i><b>Voice</b></i> - hardware modification of stock board to play voice tracks<br>
</li><li><i><b>Curves</b></i> - disable/enable curves in model setup<br>
</li><li><i><b>Autoswitch</b></i> - in model setup menus automatically set switch by moving some of them<br>
</li><li>eeprom <b><i>write Progress Bar</i></b>
</li><li><b><i>Bold</i></b> fonts for active FP, DR/Exop, MIX, Custom switches, Function switches in setup menus<br>
</li><li><b><i>Nographics</i></b> for disabling graphical sliders and ON/OFF checkboxes in setup menus<br>
</li><li><i><b>DBLKEYS</b></i> - while changing values you can <i><b>press two edit keys simultaneously</b></i>
<ol><li>[LEFT+RIGHT] = inverted value<br>
</li><li>[LEFT+DOWN]  = min value<br>
</li><li>[UP+RIGHT]   = max value<br>
</li><li>[UP+DOWN]    = default value<br>
</li></ol></li><li>openTx is prepared for <i><b>translations</b></i> in several languages (done for en, fr, it, se, cz, de)</li></ul>

<b><a href='https://code.google.com/p/opentx/wiki/OpenTx_Manual_FR'>French Wiki User Guide</a></b>

<b><a href='http://9xforums.com/wiki/index.php/openTx_user_guide'>9xforums Wiki User Guide</a></b>

<b><a href='http://open9x.googlecode.com/files/Open9x%20Manual.pdf'>English User Guide Download</a></b>

<b><a href='https://opentx.googlecode.com/files/OpenTX%20Manual%20CZ.pdf'>Czech User Guide Download</a></b>

<b><a href='http://opentx.googlecode.com/files/OpenTx%20Manual%20DE.pdf'>German User Guide Download</a></b>

<table><thead><th> <b>MAIN SCREEN</b> views </th><th> </th><th> </th></thead><tbody>
<tr><td> <i><b>Two timers</b></i> and <i><b>THRt</b></i></td><td> <i><b>Statistics</b></i> with custom Timers 1 and 2 <br>by press LONG UP on previous screen</td><td> <i><b>Delays</b></i> <br> press UP on previous screen</td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_01.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/statistic.png' /> </td><td><img src='https://opentx.googlecode.com/svn/wiki/images3/screenshot-1.png' /> </td></tr>
<tr><td> <i><b>HW switches display</b></i><br>and <i><b>shaded ID0/1/2 when TRN</b></i> </td><td> <i><b>Custom switches</b></i> display<br>pressing LEFT/RIGHT on previous screen </td><td> <i><b>Telemetry Bars</b></i> with <i><b>thresholds</b></i> <br> press LONG DOWN for Telemetry screens</td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_02.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_14.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_30.png' /> </td></tr>
<tr><td> <i><b>Telemetry</b></i> A1/A2, min/max, Cells, RSSI  <br> UP/DOWN to switch telemetry screens </td><td> <i><b>Telemetry</b></i> GPS view HMS or NMEA<br> elective in General Settings  </td><td> <i><b>Custom Telemetry</b></i> view with Timers, <br> min/max values and more </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_19.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_20.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_21.png' /> </td></tr>
<br></tbody></table>

<table><thead><th> <b>GENERAL SETTINGS</b> </th><th> </th><th> </th></thead><tbody>
<tr><td> <i><b>Radio Setup</b></i> by press LONG LEFT<br> Speaker, Haptic and other HW settings</td><td> <i><b>Gps</b></i> settings HMS or NMEA<br> and Time Zone</td><td><i><b>Backlight mode</b></i> OFF/Keys/Sticks/Both/ON<br> See also fuction switch "Backlight"</td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_26.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_29.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_71.png' /> </td></tr>
<br></tbody></table>

<table><thead><th> <b>MODEL SETTINGS</b> </th><th> </th><th> </th></thead><tbody>
<tr><td><i><b>T-Trace</b></i> for statistics and THt/s/% source<br>Changing <i><b>Up/Low case in model name</b></i><br>by pressing LONG LEFT/RIGHT  </td><td> Thr. and Startup <i><b>Model based warnings</b></i><br>press LONG MENU on S-Warning<br>to store start-up switches position</td><td>  </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_32.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/ModelWarnings.png' /> </td><td>  </td></tr>
<tr><td> <i><b>Flight Phases</b></i> <br>with <b>Bold</b> active FP1 </td><td> <i><b>Switch, selectable Trims, Fade</b></i> </td><td> </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_03.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_04.png' /> </td><td>  </td></tr>
<tr><td><i><b>DR/EXPO</b></i> for Rud/Ele/Thr/Ail<br>Depends on <code>FlightPhase</code>, Switch, Side<br>Applied is Weight, Expo, Curve</td><td> <i><b>Channel value 2 Offset</b></i> (Trim not cleared) <br>press MENU + LONG MENU on Offset</td><td> <i><b>Trims 2 Offset</b></i> (Trims are cleared)<br>press MENU on <b>Trims=>Offsets</b> </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/DrExpo.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_05.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_27.png' /> </td></tr>
<tr><td> <i><b>Curves</b></i> from 3 to 17 points and<br><i><b>Custom curves</b></i> with X and Y values<br>for each point (pt')</td><td> <i><b>Custom Switches</b></i> with <b><i>Timers1/2,</i><br>Telemetry, PPM</b><i>and more sources.</i><br><b>Bold</b> active CSx </td><td> <i><b>Trainer, Trainer per Stick, Play sounds</b></i>,<br>Channel <i><b>Security</b></i> with value,<br>Channel <i><b>Instant</b></i> value to <i><b>Trims</b></i> </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_06.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/CustomSwitches_07.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_09.png' /> </td></tr>
<tr><td> <i><b>Thr trim</b></i> like a <i><b>Slider:</b></i> in Mix select source <br>TrmR/TrmE/TrmT/TrmA </td><td> <i><b>Mix Sources</b></i><br> <i><b>Ail</b></i> is stick, <i><b>AIL</b></i> is switch </td><td> <i><b>How the FULL was changed</b></i><br>AIL or other HW/SW switch is 0 or 100 </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_08.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/MixesSources_12.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/Full-1.png' /> </td></tr>
<tr><td> <i><b>Aileron Diffentiating</b></i> 1<sup>st</sup> ability<br>Differentiated curve from -60 to +100</td><td> <i><b>Aileron Diffentiating</b></i> 1<sup>st</sup> ability<br>CH1 with <b>100% Ail</b> and <b>curve1</b></td><td> <i><b>Aileron Diffentiating</b></i> 1<sup>st</sup> ability<br>CH5 with <b>-100% Ail</b> and <b>inverted curve1</b></td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/AilDiff01.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/AilDiff02.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/AilDiff03.png' /> </td></tr>
<tr><td> <i><b>Aileron Diffentiating in MIX</b></i> 2<sup>nd</sup> ability<br>CH1 with <b>100% Ail</b> and <b>40% Differential</b></td><td> <i><b>Aileron Diffentiating in MIX</b></i> 2<sup>nd</sup> ability<br>CH6 with <b>100% Ail</b> and <b>-40% Differential</b></td><td>  </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/AilDiff04.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/AilDiff05.png' /> </td><td>  </td></tr></tbody></table>

<p align='Center'><b>TELEMETRY SETUP</b></p>

<table><thead><th> <i><b>Telemetry</b></i> A1/A2 settings <br>first alarm in A1/A2 is <i><b>threshold</b></i> in bars</th><th> <i><b>Telemetry</b></i> RSSI and Hub <br>first alarm in RSSI is <i><b>threshold</b></i> in bars</th><th> <i><b>Custom Telemetry</b></i> with Timers, <br> <b><i>min/max</i></b> values and more</th></thead><tbody>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_22.png' />                      </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_23.png' />                   </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_24.png' />          </td></tr>
<tr><td> <i><b>Telemetry Bars</b></i>                                                                      </td><td> Set Custom Switch threshold <br> for Telemetry Bar (CS4=T1>70°)                                </td><td> And then set Function SW (CS4)<br>for Telemetry Bar threshold                         </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_25.png' />                      </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_28.png' />                   </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images3/snapshot_31.png' />          </td></tr></tbody></table>

<a href='Hidden comment: 
|| _*What*_ || _*What*_ || _*What*_ ||
|| https://opentx.googlecode.com/svn/wiki/images3/statistic.png || https://opentx.googlecode.com/svn/wiki/images3/statistic.png || https://opentx.googlecode.com/svn/wiki/images3/statistic.png ||
'></a>