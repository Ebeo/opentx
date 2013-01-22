// NON ZERO TERMINATED STRINGS
#define LEN_OFFON              "\003"
#define TR_OFFON               "AV ""P\203 "

#define LEN_MMMINV             "\003"
#define TR_MMMINV              "---""INV"

#define LEN_NCHANNELS          "\004"
#define TR_NCHANNELS           "4KN 6KN 8KN 10KN12KN14KN16KN"

#define LEN_VBEEPMODE          "\005"
#define TR_VBEEPMODE           "Tyst ""Alarm""EjKnp""Alla "

#define LEN_VBEEPLEN           "\005"
#define TR_VBEEPLEN            "0====""=0===""==0==""===0=""====0"

#define LEN_VRENAVIG           "\003"
#define TR_VRENAVIG            "No REaREb"

#define LEN_VBLMODE            "\004"
#define TR_VBLMODE             "AV  ""Knpp""Spak""B\200da""P\203  "

#define LEN_TRNMODE            "\003"
#define TR_TRNMODE             " AV"" +="" :="

#define LEN_TRNCHN             "\003"
#define TR_TRNCHN              "KN1KN2KN3KN4"

#define LEN_DATETIME           "\005"
#define TR_DATETIME            "DAG: ""TID: "

#define LEN_VLCD               "\006"
#define TR_VLCD                "NormalOptrex"

#define LEN_VTRIMINC           "\006"
#define TR_VTRIMINC            "Expo  ""xFin  ""Fin   ""Medium""Grov  "

#define LEN_RETA123            "\001"
#if defined(PCBGRUVIN9X)
#if ROTARY_ENCODERS > 2
#define TR_RETA123             "RHGS123abcd"
#else
#define TR_RETA123             "RHGS123ab"
#endif
#else
#define TR_RETA123             "RHGS123"
#endif

#define LEN_VPROTOS            "\006"
#ifdef PXX
#define TR_PXX                 "PXX\0  "
#else
#define TR_PXX                 "[PXX]\0"
#endif
#ifdef DSM2
#define TR_DSM2                "DSM2\0 "
#else
#define TR_DSM2                "[DSM2]"
#endif
#ifdef IRPROTOS
#define TR_IRPROTOS            "SILV  TRAC09PICZ  SWIFT\0"
#else
#define TR_IRPROTOS
#endif
#define TR_VPROTOS             "PPM\0  ""PPM16\0""PPMsim" TR_PXX TR_DSM2 TR_IRPROTOS

#define LEN_POSNEG             "\003"
#define TR_POSNEG              "Pos""Neg"

#define LEN_VCURVEFUNC         "\003"
#define TR_VCURVEFUNC          "---""x>0""x<0""|x|""f>0""f<0""|f|"

#define LEN_VMLTPX             "\010"
#define TR_VMLTPX              "Addera  ""F\202rst\201rk""Ers\201tt\0"

#define LEN_VMLTPX2            "\002"
#define TR_VMLTPX2             "+=""*="":="

#define LEN_VMIXTRIMS          "\003"
#define TR_VMIXTRIMS           "AV ""P\203 ""Rod""Hjd""Gas""Ske"

#define LEN_VCSWFUNC           "\010"
#define TR_VCSWFUNC            "---\0    ""v>ofs\0  ""v<ofs\0  ""|v|>ofs\0""|v|<ofs\0""AND\0    ""OR\0     ""XOR\0    ""v1==v2\0 ""v1!=v2\0 ""v1>v2\0  ""v1<v2\0  ""v1>=v2\0 ""v1<=v2\0 ""d>=ofs\0 ""|d|>=ofs"

#define LEN_VFSWFUNC           "\015"
#if defined(VARIO)
#define TR_VVARIO              "Vario        "
#else
#define TR_VVARIO              "[Vario]      "
#endif
#if defined(AUDIO)
#define TR_SOUND               "Spela Ljud\0  "
#else
#define TR_SOUND               "Pip\0         "
#endif
#if defined(HAPTIC)
#define TR_HAPTIC              "Vibrator\0    "
#else
#define TR_HAPTIC              "[Vibrator]\0  "
#endif
#if defined(VOICE)
#define TR_PLAY_TRACK          "Spela Sp\200r\0  "
#define TR_PLAY_VALUE          "Spela V\201rde\0 "
#else
#define TR_PLAY_TRACK          "[Spela Sp\200r]\0"
#define TR_PLAY_VALUE          "[Spela V\201rde]\0"
#endif
#if defined(PCBSKY9X)
#if defined(SDCARD)
#define TR_SDCLOGS             "[SDCARD Logg]"
#else
#define TR_SDCLOGS             "[SDCARD Logg]"
#endif
#define TR_FSW_VOLUME          "Volym\0       "
#define TR_FSW_BG_MUSIC        "Bg Musik\0    ""BgMusic Pause"
#elif defined(PCBGRUVIN9X)
#if defined(SDCARD)
#define TR_SDCLOGS             "SDCARD Loggar"
#else
#define TR_SDCLOGS             "[SDCARD Logg]"
#endif
#define TR_FSW_VOLUME
#define TR_FSW_BG_MUSIC
#else
#define TR_SDCLOGS
#define TR_FSW_VOLUME
#define TR_FSW_BG_MUSIC
#endif
#ifdef GVARS
#define TR_FSW_ADJUST_GVAR     "Adjust \0     "
#else
#define TR_FSW_ADJUST_GVAR
#endif
#ifdef DEBUG
#define TR_FSW_TEST            "Test\0        "
#else
#define TR_FSW_TEST
#endif

#define TR_VFSWFUNC            "S\201kra\0       ""Trainer\0     ""S\201tt Trim    " TR_SOUND TR_HAPTIC "Nollst\201ll    " TR_VVARIO TR_PLAY_TRACK TR_PLAY_VALUE TR_SDCLOGS TR_FSW_VOLUME "Bakgrundsljus" TR_FSW_BG_MUSIC TR_FSW_ADJUST_GVAR TR_FSW_TEST

#define LEN_VFSWRESET          "\006"
#define TR_VFSWRESET           "Timer1""Timer2""Allt  ""Telem."

#define LEN_FUNCSOUNDS         "\006"
#define TR_FUNCSOUNDS          "Pip1  ""Pip2  ""Pip3  ""Varn1 ""Varn2 ""F\200r   ""Ring  ""SciFi ""Robot ""Pip   ""Tada  ""Syrsa ""Siren ""Alarm ""Ratata""Tick  "

#define LEN_VTELEMCHNS         "\004"
#define TR_VTELEMCHNS          "---\0""Tmr1""Tmr2""Tx\0 ""Rx\0 ""A1\0 ""A2\0 ""H\202jd""Varv""Tank""T1\0 ""T2\0 ""Fart""Avst""GHjd""Batt""Cels""Vfas""Curr""Cnsp""Powr""AccX""AccY""AccZ""Hdg\0""VFrt""A1-\0""A2-\0""Hjd-""Hjd+""Rpm+""T1+\0""T2+\0""Frt+""Avs+""Cur+""Acc\0""Tid\0"

#ifdef IMPERIAL_UNITS
#define LENGTH_UNIT            "fot"
#define SPEED_UNIT             "knp"
#else
#define LENGTH_UNIT            "m\0 "
#define SPEED_UNIT             "kmh"
#endif

#define LEN_VTELEMUNIT         "\003"
#define TR_VTELEMUNIT          "v\0 ""A\0 ""m/s""-\0 " SPEED_UNIT LENGTH_UNIT "@\0 ""%\0 ""mA\0""mAh""W\0 "
#define STR_V                  (STR_VTELEMUNIT+1)
#define STR_A                  (STR_VTELEMUNIT+4)

#define LEN_VALARM             "\003"
#define TR_VALARM              "---""Gul""Ora""R\202d"

#define LEN_VALARMFN           "\001"
#define TR_VALARMFN            "<>"

#define LEN_VTELPROTO          "\007"
#define TR_VTELPROTO           "---\0   ""Hub\0   ""WSHH\202g.""Halcyon"

#define LEN_VOLTSRC            "\003"
#define TR_VOLTSRC             "---""A1\0""A2\0""FAS""Cel"

#define LEN_VARIOSRC           "\004"
#define TR_VARIOSRC            "Data""A1\0 ""A2\0"

#define LEN_VSCREEN            "\004"
#define TR_VSCREEN             "Nums""Bars"

#define LEN_GPSFORMAT          "\004"
#define TR_GPSFORMAT           "HMS NMEA"

#define LEN_VUNITSFORMAT       "\004"
#define TR_VUNITSFORMAT        "MetrImpr"

#define LEN2_VTEMPLATES        13
#define LEN_VTEMPLATES         "\015"
#define TR_VTEMPLATES          "Nolla Mixar\0\0""Enkel 4kanal\0""Gasklippning\0""V-Stj\201rt    \0""Deltavinge  \0""eCCPM       \0""Helikopter  \0""Servotest   \0"

#define LEN_VSWASHTYPE         "\004"
#define TR_VSWASHTYPE          "--- ""120 ""120X""140 ""90\0"

#define LEN_VKEYS              "\005"
#define TR_VKEYS               " MENU"" EXIT""  Ned""  Upp""H\202ger""V\201nst"

#define LEN_VRENCODERS         "\003"
#define TR_VRENCODERS          "REa""REb"

#define LEN_VSWITCHES          "\003"
#if defined(PCBSKY9X)
#define TR_VSWITCHES           "GAS""ROD""H\205J""ID0""ID1""ID2""SKE""LAN""TRN""BR1""BR2""BR3""BR4""BR5""BR6""BR7""BR8""BR9""BRA""BRB""BRC""BRD""BRE""BRF""BRG""BRH""BRI""BRJ""BRK""BRL""BRM""BRN""BRO""BRP""BRQ""BRR""BRS""BRT""BRU""BRV""BRW"" P\203"
#else
#define TR_VSWITCHES           "GAS""ROD""H\205J""ID0""ID1""ID2""SKE""LAN""TRN""BR1""BR2""BR3""BR4""BR5""BR6""BR7""BR8""BR9""BRA""BRB""BRC"" P\203"
#endif

#define LEN_VSRCRAW            "\004"
#if defined(PCBSKY9X)
#define TR_ROTARY_ENCODERS_VSRCRAW "REa "
#elif defined(PCBGRUVIN9X) && ROTARY_ENCODERS > 2
#define TR_ROTARY_ENCODERS_VSRCRAW "REa ""REb ""REc ""REd "
#elif defined(PCBGRUVIN9X) && ROTARY_ENCODERS <= 2
#define TR_ROTARY_ENCODERS_VSRCRAW "REa ""REb "
#else
#define TR_ROTARY_ENCODERS_VSRCRAW
#endif
#if defined(HELI)
#define TR_CYC_VSRCRAW         "CYK1""CYK2""CYK3"
#else
#define TR_CYC_VSRCRAW         "[C1]""[C2]""[C3]"
#endif

#if EXTRA_3POS == 1
  #define TR_VSRCRAW             "ROD ""H\205J ""GAS ""SKE ""3PO2""P2  ""P3  " TR_ROTARY_ENCODERS_VSRCRAW "TrmR" "TrmH" "TrmG" "TrmS" "MAX ""3PO1" TR_CYC_VSRCRAW
#elif EXTRA_3POS == 2
  #define TR_VSRCRAW             "ROD ""H\205J ""GAS ""SKE ""P1  ""3PO2""P3  " TR_ROTARY_ENCODERS_VSRCRAW "TrmR" "TrmH" "TrmG" "TrmS" "MAX ""3PO1" TR_CYC_VSRCRAW
#elif EXTRA_3POS == 3
  #define TR_VSRCRAW             "ROD ""H\205J ""GAS ""SKE ""P1  ""P2  ""3PO2" TR_ROTARY_ENCODERS_VSRCRAW "TrmR" "TrmH" "TrmG" "TrmS" "MAX ""3PO1" TR_CYC_VSRCRAW
#else
  #define TR_VSRCRAW             "ROD ""H\205J ""GAS ""SKE ""P1  ""P2  ""P3  " TR_ROTARY_ENCODERS_VSRCRAW "TrmR" "TrmH" "TrmG" "TrmS" "MAX ""3POS" TR_CYC_VSRCRAW
#endif

#define LEN_VTMRMODES          "\003"
#define TR_VTMRMODES           "AV ""ABS""THs""TH%""THt"

#define LEN_DSM2MODE           "\007"
#define TR_DSM2MODE            "LP4/LP5DSMonlyDSMX   "

// ZERO TERMINATED STRINGS
#define INDENT                 "\001"
#define LEN_INDENT             1
#define INDENT_WIDTH           (FW/2)

#define TR_POPUPS              "[MENU]\010[EXIT]"
#define OFS_EXIT               7
#define TR_MENUWHENDONE        CENTER"\006[MENU] Avslutar"
#define TR_FREE                "Ledigt"
#define TR_DELETEMODEL         "Radera Modell"
#define TR_COPYINGMODEL        "Kopierar Modell"
#define TR_MOVINGMODEL         "Flyttar Modell"
#define TR_LOADINGMODEL        "Laddar Modell"
#define TR_NAME                "Namn"
#define TR_TIMER               "Timer"
#define TR_ELIMITS             "Gr\201nser++"
#define TR_ETRIMS              "Trimmar++"
#define TR_TRIMINC             "Trim\202kn."
#define TR_TTRACE              "F\202lj Gas"
#define TR_TTRIM               "GasTrim"
#define TR_BEEPCTR             "Centerpip"
#define TR_PROTO               INDENT"Proto"
#define TR_BITMAP              "Bitmap"
#define TR_PPMFRAME            "PPM frame"
#define TR_MS                  "ms"
#define TR_SWITCH              "Brytare"
#define TR_TRIMS               "Trimmar"
#define TR_FADEIN              "Tona In"
#define TR_FADEOUT             "Tona Ut"
#define TR_DEFAULT             "Standard"
#define TR_CHECKTRIMS          "\006Kolla\012Trimmar"
#define OFS_CHECKTRIMS         (9*FW)
#define TR_SWASHTYPE           "Swashtyp"
#define TR_COLLECTIVE          "Kollektiv"
#define TR_SWASHRING           "Swashring"
#define TR_ELEDIRECTION        "H\205JD Riktning"
#define TR_AILDIRECTION        "SKEV Riktning"
#define TR_COLDIRECTION        "KOLL.Riktning"
#define TR_MODE                INDENT"L\201ge"
#define TR_NOFREEEXPO          "Expo saknas!"
#define TR_NOFREEMIXER         "Mixer saknas!"
#define TR_INSERTMIX           "Addera Mix"
#define TR_EDITMIX             "Redigera Mix"
#define TR_SOURCE              INDENT"K\201lla"
#define TR_WEIGHT              "Vikt"
#define TR_EXPO                "Expo"
#define TR_SIDE                "Sida"
#define TR_DIFFERENTIAL        "Diff."
#define TR_OFFSET              INDENT"Offset"
#define TR_TRIM                "Trim"
#define TR_DREX                "DRex"
#define TR_CURVE               "Kurvor"
#define TR_FPHASE              "FlFas"
#define TR_MIXWARNING          "Varning"
#define TR_OFF                 "AV "
#define TR_MULTPX              "Multpx"
#define TR_DELAYDOWN           "Dr\202j Ned"
#define TR_DELAYUP             "Dr\202j Upp"
#define TR_SLOWDOWN            "Tr\202g Ned"
#define TR_SLOWUP              "Tr\202g Upp"
#define TR_MIXER               "Mixar"
#define TR_CV                  "KU"
#define TR_GV                  "GV"
#define TR_ACHANNEL            "A\004kanal  "
#define TR_RANGE               INDENT"Omr\200de"
#define TR_BAR                 "Data"
#define TR_ALARM               INDENT"Alarm"
#define TR_USRDATA             "Anv\201ndardata"
#define TR_BLADES              INDENT"Blad"
#define TR_SCREEN              "Screen "
#define TR_SOUND_LABEL         "Ljud "
#define TR_LENGTH              INDENT"Tid"
#define TR_SPKRPITCH           INDENT"Ton"
#define TR_HAPTIC_LABEL        "Vibrator"
#define TR_HAPTICSTRENGTH      INDENT"Styrka"
#define TR_CONTRAST            "Kontrast"
#define TR_ALARMS_LABEL        "Alarm"
#define TR_BATTERYWARNING      INDENT"Batteri"
#define TR_INACTIVITYALARM     INDENT"Inaktivitet"
#define TR_MEMORYWARNING       INDENT"Lite Minne"
#define TR_ALARMWARNING        INDENT"Ljud AV"
#define TR_RENAVIG             "RotEnc Navig"
#define TR_THROTTLEREVERSE     "Reverserad Gas"
#define TR_BEEP_LABEL          "Pip"
#define TR_MINUTEBEEP          INDENT"Varje Minut"
#define TR_BEEPCOUNTDOWN       INDENT"R\201kna Ned"
#define TR_BACKLIGHT_LABEL     "Belysning"
#define TR_BLDELAY             INDENT"Av efter"
#define TR_SPLASHSCREEN        "Bild vid start"
#define TR_THROTTLEWARNING     "Gasvarn."
#define TR_SWITCHWARNING       "Bryt.varn."
#define TR_TIMEZONE            "Tidszon"
#define TR_RXCHANNELORD        "Kanalordning RX"
#define TR_SLAVE               "Slav"
#define TR_MODESRC             " l\201ge\006% k\201lla"
#define TR_MULTIPLIER          "Styrka"
#define TR_CAL                 "Kalib."
#define TR_VTRIM               "Trim- +"
#define TR_BG                  "BG:"
#define TR_MENUTOSTART         CENTER"\006[MENU] Startar"
#define TR_SETMIDPOINT         CENTER"\010Centrera Allt"
#define TR_MOVESTICKSPOTS      CENTER"\004R\202r Rattar/Spakar"
#define TR_RXBATT              "Rx Batt:"
#define TR_TXnRX               "Tx:\0Rx:"
#define OFS_RX                 4
#define TR_ACCEL               "Acc:"
#define TR_NODATA              "NO DATA"
#define TR_TM1TM2              "TM1\032TM2"
#define TR_THRTHP              "THR\032TH%"
#define TR_TOT                 "TOT"
#define TR_TMR1LATMAXUS        "Tmr1Lat max\006us"
#define STR_US                 (STR_TMR1LATMAXUS+12)
#define TR_TMR1LATMINUS        "Tmr1Lat min\006us"
#define TR_TMR1JITTERUS        "Tmr1 Jitter\006us"
#if defined(PCBSKY9X)
#define TR_TMIXMAXMS           "Tmix max\012ms"
#else
#define TR_TMIXMAXMS           "Tmix max\014ms"
#endif
#define TR_T10MSUS             "T10ms\016us"
#define TR_FREESTACKMINB       "Free Stack\010b"
#define TR_MENUTORESET         "[MENU] Nollar  "
#define TR_PPM                 "PPM"
#define TR_CH                  "KN"
#define TR_MODEL               "Modell"
#define TR_FP                  "FF"
#define TR_MIX                 "MIX"
#define TR_EEPROMLOWMEM        "EEPROM low mem"
#define TR_ALERT               "\016OBS"
#define TR_PRESSANYKEYTOSKIP   "Tryck ned en knapp"
#define TR_THROTTLENOTIDLE     "Gasen ej avst\201ngd!"
#define TR_ALARMSDISABLED      "Alarmen Avst\201ngda!"
#define TR_PRESSANYKEY         "Tryck ned en knapp"
#define TR_BADEEPROMDATA       "EEprom Datafel "
#define TR_EEPROMFORMATTING    "Formaterar EEprom"
#define TR_EEPROMOVERFLOW      "Fel i EEprom"
#define TR_MENURADIOSETUP      "Inst\201llningar"
#define TR_MENUDATEANDTIME     "Dag och Tid"
#define TR_MENUTRAINER         "Trainer (PPM in)"
#define TR_MENUVERSION         "Version"
#define TR_MENUDIAG            "Diagnos"
#define TR_MENUANA             "Analoga V\201rden"
#define TR_MENUCALIBRATION     "Kalibrering"
#define TR_TRIMS2OFFSETS       "\004[Spara Trimv\201rden]"
#define TR_MENUMODELSEL        "Modell"
#define TR_MENUSETUP           "V\201rden"
#define TR_MENUFLIGHTPHASE     "Flygfas"
#define TR_MENUFLIGHTPHASES    "Flygfaser"
#define TR_MENUHELISETUP       "Helikopter"
#if defined(PPM_CENTER_ADJUSTABLE) || defined(PPM_LIMITS_SYMETRICAL) // The right menu titles for the gurus ...
#define TR_MENUDREXPO          "Spakar" 
#define TR_MENULIMITS          "Outputs"
#else
#define TR_MENUDREXPO          "DR/Expo"
#define TR_MENULIMITS          "Gr\201nser"
#endif
#define TR_MENUCURVES          "Kurvor"
#define TR_MENUCURVE           "Kurva"
#define TR_MENUCUSTOMSWITCH    "Logisk Brytare"
#define TR_MENUCUSTOMSWITCHES  "Logiska Brytare"
#define TR_MENUCUSTOMFUNC      "BrytarFunktioner"
#define TR_MENUTELEMETRY       "Telemetri"
#define TR_MENUTEMPLATES       "Mallar"
#define TR_MENUSTAT            "Statistik"
#define TR_MENUDEBUG           "Debug"
#define TR_RXNUM               "RxNum"
#define TR_SYNCMENU            "Synk [MENU]"
#define TR_BACK                "EXIT"
#define TR_LIMIT               INDENT"Niv\200"
#define TR_MINRSSI             "Min Rssi"
#define TR_LATITUDE            "Breddgrad"
#define TR_LONGITUDE           "L\201ngdgrad"
#define TR_GPSCOORD            "GPS-Koordinater"
#define TR_VARIO               "Vario"
#define TR_SHUTDOWN            "ST\204NGER AV"
#define TR_BATT_CALIB          "Kalib. Batteri"
#define TR_CURRENT_CALIB       "Kalib. Str\202m"
#define TR_VOLTAGE             INDENT"Sp\201nning"
#define TR_CURRENT             INDENT"Str\202m"
#define TR_SELECT_MODEL        "V\201lj Modell"
#define TR_CREATE_MODEL        "Skapa Modell"
#define TR_BACKUP_MODEL        "Modell-backup"
#define TR_DELETE_MODEL        "Ta Bort Modell"
#define TR_RESTORE_MODEL       "\203terst\201ll Modell"
#define TR_SDCARD_ERROR        "SDCARD-fel"
#define TR_NO_SDCARD           "SDCARD saknas"
#define TR_INCOMPATIBLE        "Inkompatibel"
#define TR_WARNING             "VARNING"
#define TR_EEPROMWARN          "EEPROM"
#define TR_THROTTLEWARN        "GAS"
#define TR_ALARMSWARN          "ALARM"
#define TR_SWITCHWARN          "BRYTARE"
#define TR_INVERT_THR          "Revers.Gas?"
#define TR_SPEAKER_VOLUME      INDENT"Volym"
#define TR_LCD                 "LCD"
#define TR_BRIGHTNESS          "Ljusstyrka"
#define TR_CPU_TEMP            "CPU temp.\016>"
#define TR_CPU_CURRENT         "Str\202m\022>"
#define TR_CPU_MAH             "F\202rbrukn."
#define TR_COPROC              "CoProc."
#define TR_COPROC_TEMP         "MB temp. \016>"
#define TR_CAPAWARNING         INDENT "L\200g Kapacitet"
#define TR_TEMPWARNING         INDENT "H\202g Temp "
#define TR_FUNC                "Funk"
#define TR_V1                  "V1"
#define TR_V2                  "V2"
#define TR_DURATION            "Tidl\201ngd"
#define TR_DELAY               "F\202rdr\202j"
#define TR_SD_CARD             "SD-kord"
#define TR_SDHC_CARD           "SD/HC-kort"
#define TR_NO_SOUNDS_ON_SD     "Inga ljud i SD"
#define TR_NO_MODELS_ON_SD     "Ingen modell i SD"
#define TR_PLAY_FILE           "Spela"
#define TR_DELETE_FILE         "Radera"
#define TR_COPY_FILE           "Kopia"
#define TR_RENAME_FILE         "Byt namn"
#define TR_REMOVED             " raderad"
#define TR_SD_INFO             "Information"
#define TR_SD_FORMAT           "Format"
#define TR_NA                  "N/A"
#define TR_NO_BITMAPS_ON_SD    "Bilder saknas p\200 SD"
#define TR_HARDWARE            "H\200rdvara"
#define TR_FORMATTING          "Formaterar..."
#define TR_TEMP_CALIB          "Temp.kalib."
#define TR_TIME                "Tid "
#define TR_BAUDRATE            "BT Baudrate"
#define TR_SD_INFO_TITLE       "SD INFO"
#define TR_SD_TYPE             "Typ: "
#define TR_SD_SPEED            "Hastighet:"
#define TR_SD_SECTORS          "Sektorer:"
#define TR_SD_SIZE             "Strl:"
#define TR_CURVE_TYPE          "Typ "
#define TR_GLOBAL_VARS         "Globala Variabler"
#define TR_OWN                 "Egen"
#define TR_DATE                "Datum"
#define TR_ROTARY_ENCODER      "R.Enks"
#define TR_CHANNELS_MONITOR    "KANAL-MONITOR"
