#summary Polish translation of openTx for FrSky radios

<a href='Hidden comment: 
TODO:
'></a>

# openTx dla FrSky Taranis #

Instrukcję napisał [Andre Bernet](http://www.andrebernet.ch), jest ona oparta na openTx [r2768](https://code.google.com/p/opentx/source/detail?r=2768). Tłumaczenie na język polski - [Mariusz Dąbrowski](http://code.google.com/u/116222781215586067487).
Komercyjne wykorzystanie jest zabronione bez wyraźnego upoważnienia autorów i tłumaczy. Nie gryziemy, ale chcemy wiedzieć co się dzieje, więc po prostu zapytaj :)

Poniższa wersja tłumaczenia jest wersją roboczą, tekst wymaga jeszcze redakcji i korekt. W wypadku niejasności czy wątpliwości dotyczących zagadnień poruszanych w niniejszej instrukcji, proszę odwołać się do wersji oryginalnej. Pamiętaj, używasz tej instrukcji na własną odpowiedzialność!

Jak każdy prawdopodobnie już wie, FrSky wybrało openTx jako system operacyjny dla swojego nowego radia [Taranis](http://www.frsky-rc.com/NewProducts/) :)

Intencją tej strony jest opisanie oprogramowania openTx, zainstalowanego w aparaturze Taranis, i zaoferowanie nieco wyjaśnień na temat jego filozofii i sposobu konfiguracji modeli.
Wersja openTx dla Taranisa posiada wszystkie funkcje wersji 9x, zawiera dodatki z wersji sky9x (dźwięk/głos, karta SD do przechowywania modeli/plików dźwiękowych/logów, dostęp do karty SD i pamięci ustawień/modeli przez USB), interfejs użytkownika dostosowany do większego ekranu i innego ułożenia przycisków i oczywiście wprowadza wsparcie dla dodatkowych możliwości sprzętu Taranisa.



### Co znajdziesz w Twojej paczce ###

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/Taranis-3.jpg](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/Taranis-3.jpg)

  * Aluminiowe pudełko
  * Nadajnik!
  * Pakiet zasilający - 6-cel NiMH
  * Ładowarka, która jest podłączana do gniazda ładowania w radiu
  * Ładny pasek na szyję
  * Zależnie od wybranego zestawu - odbiornik X8R

Używanie niektórych zaawansowanych funkcji (powiadomienia głosowe, zapis danych telemetrii, własne rysunki modeli) będzie wymagało uzupełnienia aparatury o kartę microSD (nie dostarczana w komplecie). Zespół openTx usilnie poleca zainstalowanie karty, gdyż powiadomienia głosowe są kluczowe dla wykorzystanie możliwości informowania o groźnych sytuacjach jak słaby sygnał lub uszkodzona antena. Jeśli pakiet powiadomień głosowych nie jest dostępny, alarmy będą sygnalizowane różnymi kombinacjami dźwięków, ale z uwagi na dużą liczbę możliwych alarmów, trudno jest zapamiętać jak reagować na poszczególne dźwięki, zwłaszcza jeśli odezwą się w czasie lotu.

## Nadajnik ##

FrSky Taranis jest przełomową aparaturą gdyż po raz pierwszy zdarza się, że renomowany gracz w przemyśle R/C i twórcy oprogramowania open-source sterującego nadajnikiem blisko współpracują aby poprawiać zarówno sprzętową jak i programową stronę produktu i tworzą nadajnik open-source przeznaczony na masowy rynek. Oznacza to, że Taranis będący tania aparaturą, jest wolny od typowych ograniczeń marketingowych jakie większość producentów narzuca swoim produktom, i oferuje funkcjonalność, która dorównuje a nawet przewyższa najlepsze oferty w tym przemyśle.

Jest ona ponadto przyszłościowa, bo oba zespoły są gotowe odpowiadać na pytania i sugestie. Możliwa jest szybka ewolucja dla nadążania za potrzebami różnych użytkowników. Jeśli masz trochę doświadczenia w programowaniu - cały kod źródłowy oprogramowania nadajnika jest dostępny abyś mógł się nim bawić i dostosowywać do swoich potrzeb.

### Przegląd funkcji radia ###

  * Duży, podświetlany ekran LCD 212\*64
  * Drążki zawieszone na czterech łożyskach kulkowych, wyposażone w potencjometry wysokiej jakości
  * Liczne elementy sterujące (4 drążki, 4 trymery, 2 suwaki, 2 potencjometry, 8 przełączników), wszystkie można dowolnie wykorzystywać.
  * 60 pamięci dla konfiguracji modeli
  * 32 kanały logiczne
  * Wewnętrzny moduł nadawczy z telemetrią, będący w stanie transmitować do 16 kanałów z prędkością odświeżania 9ms. Obsługuje on istniejący protokół D8 (można go używać ze wszystkimi odbiornikami serii D i VxR-II) jak również nowe tryby D16 i LR12
  * Kieszeń na zewnętrzny moduł nadawczy zgodny z JR (bez zasilania 6V) obsługujący transmisję do 16 kanałów (zależnie od modułu) z użyciem różnych popularnych protokołów (PXX dla modułów FrSky oraz PPM dla modułów innych producentów). Wsparcie dla szeregowego protokołu DSM2 dla samodzielnie wykonywanych modułów Spektrum zostanie dodane w przyszłości, w nowych wersjach oprogramowania.
  * Przypisanie kanałów nadajnika jest dowolne, więc gdy zostanie dołączony zewnętrzny moduł nadawczy, masz wybór między bezpiecznym systemem, w którym te same kanały są transmitowane poprzez zewnętrzny i zewnętrzny moduł nadawczy, albo transmisją do 32 niezależnych kanałów jednocześnie lub kombinację obu tych rozwiązań.
  * Wewnętrzny moduł nadawczy (a także zewnętrzny, gdy zainstalowany jest XJT od FrSky) obsługuje przypisywanie odbiornika do modelu oraz umożliwia wygodną konfigurację zachowania odbiornika po utracie sygnału (failsafe) z poziomu nadajnika. Dostępne są 3 tryby: podtrzymanie poprzedniego stanu (Hold), wstrzymanie sterowania mechanizmów wykonawczych (Stop pulses), własne ustawienia pozycji mechanizmów wykonawczych (Custom positions). Ta funkcjonalność jest dostępna wyłącznie w odbiornikach serii X.
  * Telemetria wyświetlana na 3 ekranach, których wygląd można dostosować do własnych potrzeb. W pełni konfigurowalne powiadomienia głosowe. Telemetria obsługuje dotychczasowe odbiorniki oraz czujniki, jak również nowe czujniki dołączane przez Smart Port. Konfigurowalne jednostki miar - anglosaskie lub metryczne. Zintegrowany wariometr z sygnalizacją akustyczną (wymagany czujnik w modelu). Zapis danych (wymaga karty microSD).
  * Możliwość wyboru trybu pracy drążków (Mode 1 - Mode 4). Zupełnie dowolne przyporządkowanie kanałów wyjściowych.
  * 2 timery, ich stany mogą być zapisywane gdy nadajnik jest wyłączany.
  * 64 miksery
  * 9 trybów (faz) lotu
  * 16 definiowalnych krzywych (od 3 do 17 punktów), dowolnie definiowalne współrzędne x
  * 32 wirtualne (logiczne) przełączniki
  * Standardowe (typu JR) gniazdo jack do połączenia nadajników w system uczeń-nauczyciel (sygnał PPM). Aparatura jest w stanie odbierać do 8 kanałów albo wysyłać do 16 kanałów. Tryb uczeń/nauczyciel i parametry sygnału są, dla wygody użytkownika, zapisywane oddzielnie dla każdego modelu.
  * [companion9x](http://code.google.com/p/companion9x/) Oprogramowanie dla Windows/Mac/Linux do zapisywania, edycji i wymiany ustawień twoich modeli, jak również do symulacji ustawień modeli.
  * Połączenie USB dla aktualizacji wewnętrznego oprogramowania, dostępu do karty microSD oraz dla programu companion9x
  * Możliwość kalibracji drążków przez użytkownika
  * Wsparcie dla wielu języków: angielskiego, francuskiego, włoskiego, niemieckiego, szwedzkiego, hiszpańskiego, portugalskiego, czeskiego i także Twojego, jeśli przyczynisz się do stworzenia własnego pliku tłumaczeń! (Radio jest dostarczane z zainstalowanym językiem angielskim, aby zmienić język, wymagana jest aktualizacja oprogramowania)
  * Oprogramowanie jest tworzone przez wspólnotę open-source, więc inaczej niż w przypadku wielkich producentów, jeśli potrzebujesz nietypowej funkcji lub masz dobre sugestie usprawnień, zgłoś to i nie bądź zaskoczony jeśli zostanie zaimplementowana kilka dni później! Odwiedź http://www.openrcforums.com by spotkać twórców!


### Sprzęt ###

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/Taranis.jpg](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/Taranis.jpg)

Aparatura ma względnie typowy wygląd oraz ułożenie elementów sterujących, i tak:
  * 2 drążki i związane z nimi trymery, opisane w oprogramowaniu jako Thr, Rud, Ele, Ail, odpowiednio, TrmT, TrmR, TrmE, TrmA. Przyporządkowanie drążków do nazw jest zgodne z wybranym trybem pracy drążków (Mode). Trymery można przypisywać dowolnie (np. dla cross-trimming), mogą być także użyte niezależnie od drążków.
  * 2 potencjometry S1 i S2
  * 2 boczne suwaki LS i RS
  * 6 przełączników 3-pozycyjnych (SA-SE, SG)
  * 1 przełącznik 2-pozycyjny (SF)
  * 1 przełącznik chwilowy (SH)
Kiedy wybieramy konkretny przełącznik do aktywacji funkcji odnosimy się do niego za pomocą jego nazwy, po której następuje jego fizyczne ustawienie (SAgóra, SC-, SFdół). ! przed nazwą oznacza NIE, więc !SBdół oznaczałoby, że funkcja jest aktywna gdy SB NIE jest w dolnym położeniu czyli jest przełączony w górę, lub w pozycji środkowej.

Wewnętrzny moduł nadawczy używa obrotowej anteny, a pod okrągłą siateczką zlokalizowany jest głośnik zdolny do odtwarzania mowy. Duży, podświetlany wyświetlacz LCD (z odcieniami szarości) i 6 klawiszy edycyjnych zajmuje większość dolnej części.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/photo06.jpg](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/photo06.jpg)

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/photo07.jpg](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/photo07.jpg)

Z tyłu radia widać kieszeń na moduł radiowy zgodny z JR, wraz z gniazdem jack w stylu JR do połączenia kablem dwóch nadajników, złącze USB oraz gniazdo słuchawkowe. Komora baterii mieści gniazdo karty microSD, port szeregowy i oczywiście złącze baterii.

Dostarczona bateria to 6 ogniw NiMH, ale złącze pasuje do wtyczki balancera JST dla pakietu 2s Li-Po. Komora baterii ma rozmiary 108x31x28mm. Zakres napięć zasilających to 5.5-13V dla podzespołów wewnętrznych, ale bądź świadomy tego, że zewnętrzne moduły mogą wymagać co najwyżej 12V, więc jeśli używasz modułów, uważaj na ich wymagania i wybierz odpowiednią baterię.

Po prawej stronie radia znajdziesz wejście ładowarki z diodą świecącą ładowania tuż obok - z tyłu radia. Gdy podłączysz dostarczony zasilacz, dioda zaświeci się, i zgaśnie gdy bateria zostanie naładowana (ładowanie pustej baterii trwa 2-3 godziny).

**UWAGA: Radio posiada wbudowany układ ładowania akumulatorów NiMH, zaprojektowany do ładowania dostarczonej baterii (6 ogniw).**
  * **Nie podłączaj inteligentnej ładowarki do złącza ładowania. Ono powinno być zasilane wyłącznie z 12V DC, polaryzacja nie gra roli.**
  * **Nie używaj złącza ładowania jeśli zmieniłeś baterię na inny typ (inny skład chemiczny lub liczba cel).**

Drążki mają ustawianą długość i siłę oporu, a każda z osi pionowych jest wyposażona w funkcję zablokowania sprężyny jak również zapadkę oraz hamulec. To oznacza, że nie ma potrzeby zamiany elementów aby zmienić "Mode" oraz to, że jeśli chcesz, możesz mieć zarówno obie jak i wcale nie mieć założonych sprężyn osi pionowej.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/screws.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/screws.png)

Wewnątrz, drążki mają trzy różne rodzaje śrub:

  * zapadka osi Y i/lub siła "delikatnego hamowania" (niebieski)
  * blokowanie sprężyny osi Y, wkręć ją aby zablokować sprężynę (zielony)
  * naciąg sprężyny osi X i Y (czerwony), wkręcić dla większej siły, zewnętrzna śruba jest, oczywiście, dla osi Y.

Warto zauważyć, że jeśli lubisz mieć słabe napięcie drążka, łatwo o nieprecyzyjne centrowanie gdy śruby regulacji napięcia są zbyt odkręcone. Po prostu dokręć je na tyle mocno aby centrowanie było wystarczająco dobre.

## Przegląd oprogramowania ##

Teraz jest odpowiednia chwila aby zacząć ładować baterię, aby po przeczytaniu tego rozdziału przećwiczyć w praktyce to czego się nauczyłeś.

### Przyciski nawigacyjne ###

Taranis posiada 6 klawiszy: typowy zestaw +/-/ENTER/EXIT, dodatkowo dwa klawisze kontekstowe MENU i PAGE.

Na ekranach głównych, klawisz PAGE będzie przełączał między różnymi widokami (ekranami) opisanymi w następnym rozdziale. DŁUGIE naciśnięcie klawisza PAGE wywołuje wyświetlanie telemetrii. KRÓTKIE przyciśnięcie klawisza MENU otwiera menu modelu, zaś DŁUGIE naciśnięcie otwiera menu ustawień radia. W tych dwóch menu, KRÓTKIE naciśnięcie klawisza PAGE powoduje przejście do następnej strony, zaś DŁUGIE naciśnięcie przechodzi z powrotem do poprzedniej strony. EXIT przechodzi z powrotem do ekranów głównych. Na wszystkich stronach menu modelu, DŁUGIE naciśnięcie klawisza MENU przywołuje monitor kanałów pozwalający szybko sprawdzić wpływ zmian w ustawieniach na wynik działania wyjść nadajnika.

Nawigacja w menu jest prosta: klawisze +/- służą do przesuwania kursora w górę/w dół między edytowalnymi polami lub liniami pól - zależnie od konkretnego ekranu.

ENTER wchodzi w linię pól edycyjnych, jeśli jest taka możliwość, następnie w tryb edycji. W trybie edycji, +/- będą zmieniać wartość, ENTER lub EXIT zatwierdzają wprowadzone dane i powracają do nawigacji między polami. EXIT zawsze powoduje powrót do poprzedniego poziomu nawigacji.

W trybie edycji, mamy dostępne cztery 2-klawiszowe skróty:
  * +/- wciśnięte razem: Odwrócenie wartości
  * -/ENTER: Ustawienie wartości na 100
  * EXIT/PAGE: Ustawienie wartości na -100
  * MENU/PAGE: Ustawienie wartości na 0

Inna poręczna funkcjonalność to automatyczny wybór fizycznych wejść w odpowiednich polach. Zamiast wybierania źródła lub przełącznika przy pomocy klawiszy + i -, po prostu porusz potencjometrem lub przełącz przełącznik a zostanie on rozpoznany. Dla przełączników, także położenie jest automatycznie wybierane, zaś kombinacja klawiszy +/- pozwoli wybrać odwrotną pozycję jeśli jest taka potrzeba.

### Ekrany główne ###

Mamy 3 główne ekrany pokazujące te same podstawowe informacje w górnej części i różne wejścia/wyjścia w części dolnej. Na głównych ekranach, DŁUGIE naciśnięcie klawisza ENTER przywołuje menu, gdzie możesz wyzerować timery, dane telemetrii (minimalna/maksymalna wysokość, położenie GPS punktu startu...), lub wszystkie z nich, przywołać widok statystyk (wykres użycia drążka gazu, timery), lub pokazać listę autorów oprogramowania. Jak wspomniano powyżej, KRÓTKIE naciśnięcie klawisza PAGE przełącza między ekranami.

Pasek tytułowy ekranu zawiera napięcie baterii nadajnika, siłę sygnału (dla odbiorników FrSky), napięcie głównego pokładowego źródła zasilania (może to być bateria odbiornika, bateria napędu, lub cokolwiek innego zależnie od wybranego czujnika w opcji "Voltage" parametrów telemetrii), ikony stanu aparatury (obecność karty SD, aktywne połączenie USB, tryb połączenia uczeń-nauczyciel, włączone logowanie), głośność dźwięku i czas.

Inne "zawsze obecne" elementy to nazwa modelu, tryb lotu i pozycje trymerów/potencjometrów. Logo można dostosować do własnych potrzeb, jeśli masz w radiu kartę microSD, będziesz w stanie tu załadować zdjęcie Twojego modelu!

Pierwszy z ekranów głównych pokazuje stany fizycznych przełączników u dołu z lewej i 2 timery (jeśli są włączone) z prawej.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/01_main_timer.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/01_main_timer.png)

Drugi, pokazuje pozycje drążków i przełączników, tutaj można wygodnie sprawdzić czy wszystkie elementy sterujące reagują tak jak powinny.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/02_main_g.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/02_main_g.png)

Trzeci, pokazuje fizyczne przełączniki z lewej i stany 32 przełączników logicznych z prawej.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/03_main_CS.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/03_main_CS.png)

Ostatni ekran, to monitor kanałów, pokazujący stan wyjść serw dla wszystkich 32 kanałów (+/- zmieniają stronę). Jeśli zdefiniowano nazwy kanałów na stronie serw, dla wygody, pokażą się one tutaj zamiast numerów.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/04_main_channel_mon.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/04_main_channel_mon.png)

### Ekrany telemetrii ###

DŁUGIE naciśnięcie klawisza PAGE z dowolnego z głównych ekranów, przywołuje ekrany telemetrii. Klawisze PAGE oraz +/- będą cykliczne przełączać między ekranem stanu zasilania (napięcie, prąd, moc lub A1/A2 jeśli nie ustawione, napięcia poszczególnych cel pochodzące z czujnika FLVS-01 - jeśli jest podłączony), ekranem minimów/maksimów i współrzędnymi GPS oraz własnymi ekranami telemetrii. W menu ustawień telemetrii, można zdefiniować zawartość własnych ekranów (maksimum trzech), każdy z nich może pokazywać do 12 parametrów.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/05_telem_pwr.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/05_telem_pwr.png)

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/06_telem_gps.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/06_telem_gps.png)

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/07_telem_custom.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/07_telem_custom.png)

### Ustawienia ogólne radia ###

DŁUGIE naciśnięcie klawisza MENU, przywołuje, w znacznej części nie wymagające wyjaśnień, menu ustawień radia.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/08_radio_setup.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/08_radio_setup.png)

  * Date/Time (data/czas): tutaj można je ustawić, w celach informacyjnych, ale także aby dostarczyć właściwego czasu do logów i innych plików zapisywanych przez aparaturę.
  * Battery range (zakres napięć baterii): zakres graficznego wskaźnika napięcia baterii na głównych ekranach. Należy ustawić stosownie do rodzaju baterii jaką używasz.
  * Sound settings (ustawienia dźwięku): Tryb, głośność ogólna, indywidualna głośność źródeł dźwięku (piknięcia, pliki dźwiękowe, wariometr, tło muzyczne), długość i wysokość piknięć.
  * Contrast (kontrast): Ustawienie kontrastu wyświetlacza.
  * Alarms -> Sound off (Alarmy -> dźwięk wyłączony): Jeśli "Sound Mode" jest ustawiony na "Quiet", radio nie będzie wydawało dźwięku, nawet w przypadku ostrzeżeń o np. słabej baterii. Ten alarm przypomni Ci o tym podczas włączania radia. Alarm o bezczynności poinformuje Cię, że zapomniałeś wyłączyć radio.
  * Backlight -> Mode (podświetlenie -> tryb): Jeśli ustawione na Keys (klawisze), Controls (sterowanie) lub Both (oba), podświetlenie będzie włączone gdy poruszysz drążek/przełącznik i/lub gdy naciśniesz klawisz. Zostanie ono włączone na czas określony poniżej (Duration).
  * Backlight -> Alarm (podświetlenie -> alarm): Podświetlenie zacznie migać gdy pojawi się alarm.
  * Splash screen (ekran powitalny): Na Taranisie ekran powitalny jest pokazywany zawsze, gdyż załadowanie danych z EEPROM chwilę trwa. Włączenie tej opcji powoduje, że ekran powitalny będzie wyświetlany dłużej.
  * GPS time zone (strefa czasowa GPS) jest tutaj aby było możliwe pokazywanie właściwego czasu dostarczanego przez GPS, format współrzędnych pozwala dostosować format ich wyświetlania do Twoich upodobań.
  * Country code (kod kraju): Musi być zgodny z Twoją lokalizacją geograficzną aby parametry nadawanego sygnału radiowego były zgodne z wymaganiami regulacji prawnych.
  * Voice language (język głosu): Pozwala Ci wybrać język komunikatów głosowych. Zwróć uwagę, że lista zawiera wszystkie wspierane języki, ale musisz także upewnić się, że pakiet plików głosowych dla tego języka został załadowany na kartę SD (do podkatalogu SOUNDS).
  * Units (jednostki): Pozwala wybrać między jednostkami metrycznymi i anglosaskimi dla parametrów telemetrii.
  * FAI mode (tryb FAI) (jeśli opcja "FAI choice" została wybrana w companion9x): Blokuje wyświetlanie wszystkich danych z telemetrii innych niż RSSI i napięcie, aby zachować zgodność z wymaganiami zawodów. To działa tylko w jednym kierunku, jeśli włączysz tę opcję, nie będziesz jej mógł już wyłączyć (aby zabezpieczyć przed oszukiwaniem). Pozwala to przyjść na lotnisko, wszystko sprawdzić / wykonać testowe loty z telemetrią i włączyć ograniczony tryb bezpośrednio w aparatur przed rozpoczęciem zawodów.
  * Default channel order (domyślna kolejność kanałów): Definiuje kolejność 4 domyślnych mikserów, które są wstawiane na kanałach 1-4 podczas tworzenia nowego modelu. Ustaw zgodnie ze swoimi preferencjami. Oczywiście kolejność może zostać później zmieniona, ta opcja ma po prostu oszczędzać czas.
  * Mode: tryb pracy drążków, np. Mode 1 dla gazu i lotek na prawym drążku, Mode 2 dla gazu i steru kierunku na lewym drążku.

#### Przeglądarka SD ####

KRÓTKIE naciśnięcie klawisza PAGE przywołuje ekran przeglądarki karty SD

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09_SD.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09_SD.png)

Pozwala ona przeglądać zawartość karty SD.

Naciśnięcie ENTER na nazwie pliku lub folderu, przywołuje menu kontekstowe z podstawowymi operacjami plikowymi (kopiowanie/usuwanie). Zależnie od rodzaju pliku mogą pojawić się także inne opcje.

Foldery są zorganizowane następująco:

  * BMP folder: To tutaj powinieneś umieścić pliki .bmp o rozmiarach 64x32 w czterech stopniach szarości, których chcesz użyć jako rysunków modeli. Nazwa pliku musi mieć nie więcej niż 10 znaków (nie licząc rozszerzenia). Kolekcja takich plików jest dostępna [tutaj](http://openrcforums.com/forum/viewtopic.php?f=92&t=3530). Ustawienie kursora na właściwym pliku spowoduje jego wyświetlenie po prawej stronie ekranu, a w menu kontekstowym znajdziesz opcję przypisania wybranego obrazka do aktualnego modelu.
  * LOGS folder: Jeśli uzywałeś funkcji logowania, tutaj znajdziesz logi z zapisanymi parametrami telemetrii. Pliki będą utworzone z taką samą nazwą jak nazwa modelu z dodana datą. Jeden plik logu jest tworzony danego dnia dla każdego modelu osobno.
  * MODELS folder: Tutaj będą pliki konfiguracyjne modeli zapisane komendą "Archive model" z ekranu wyboru modelu. Podobnie, modele które chcesz załadować komendą "Restore model" z tej samej strony, powinny uprzednio zostać tutaj zapisane.
  * SOUNDS folder: Tutaj powinny zostać umieszczone paczki plików głosowych. Pliki ZIP zawierające pakiet standardowych głosów można pobrać z wnętrza programu companion9x, lub [tutaj](http://85.18.253.250/voices/opentx-taranis/). Rozpakuj plik ZIP w katalogu głównym karty SD, a zostaną utworzone potrzebne podkatalogi (np. SOUNDS/en dla pakietu angielskiego). Każdy plik, który chcesz aby był dostępny dla funkcji specjalnej "Play Track" także powinien zostać umieszczony wewnątrz katalogu językowego. W tym katalogu menu kontekstowe zawiera funkcję podglądu.

Karta microSD może być sformatowana przez wybranie odpowiedniej opcji w menu, które pojawia się gdy naciśniemy DŁUGO klawisz MENU. Będzie wymagane potwierdzenie.

#### Tryb trenera (uczeń-nauczyciel) ####

KRÓTKIE naciśnięcie klawisza PAGE wywołuje stronę ustawień trybu trenera:

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09b_trainer.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09b_trainer.png)

Ta strona umożliwia Ci konfigurowanie ustawień funkcji trenera dla nauczyciela (upewnij się że tryb trenera w konfiguracji modelu jest ustawiony na Master). Dla każdej z 4 głównych funkcji, możesz ustawić tryb pracy portu trenera (OFF - wyłączony, += dla Add - dodawanie, := dla Replace - zastępowanie), współczynnik skalowania i kanał wejściowy.

Zacznij od ustawienia trybu dla każdej funkcji (typowym sposobem jej wykorzystania jest Replace tzn. gdy funkcja trenera jest aktywna, kontrola nad tą funkcją jest w pełni przekazana uczniowi, Add pozwala zarówno uczniowi jak i nauczycielowi sprawować wspólnie kontrolę nad tą funkcją). Następnie wybierz źródłowy kanał zgodnie z jego wykorzystaniem w aparaturze ucznia, i ustaw wstępnie współczynnik skalowania na 100%. Teraz upewnij się, że radio ucznia jest podłączone i rozpoznane (poruszanie drążkami radia ucznia powinno zmieniać 4 liczby u dołu ekranu) upewnij się, że wszystkie ich trymery są w położeniu neutralnym, a wszystkie drążki są w położeniach środkowych (włączając w to drążek gazu). Wybierz pole CAL i naciśnij ENTER dwukrotnie. Liczby powinny teraz być równe 0.0 lub być bliskie zeru.

Teraz porusz drążkami radia ucznia i sprawdź czy liczby zmieniają się od -100 do 100. Jeśli osiągają te wartości zanim drążek znajdzie się w skrajnym położeniu, zredukuj współczynnik skalowania. Jeśli nigdy nie osiągają zakresu -100 do +100 nawet przy pełnym wychyleniu drążków, użyj pola "multiplier" aby je zwiększyć.

Wejście trenera jest teraz skonfigurowane. Zauważ, że to ustawienie jest globalne, ono zależy od radia ucznia - niezależnie od wybranego modelu. W celu użycia funkcji trenera dla konkretnego modelu, będziesz potrzebował przypisać przełącznik, do funkcji specjalnej "Trainer" dla tego modelu. Później napiszemy o tym więcej.

#### Wersja ####

Ten ekran pozwala Ci zobaczyć wersję aktualnie załadowanego oprogramowania openTx.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09c_version.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09c_version.png)

Kiedy zgłaszasz błąd, proszę upewnij się, że dołączyłeś numer rewizji, który widzisz w linii SVN.

#### Diagnostyka ####

Dwie następne strony służą do diagnostyki przełączników i wejść analogowych, pokazują one co oprogramowanie radia odczytuje z klawiszy i potencjometrów. To jest pierwsze miejsce, do którego należy się udać jeśli masz kłopot ze źle reagującymi drążkami / potencjometrami / przełącznikami. Jeśli coś tu jest źle (niejednoznaczne centrowanie drążków lub odczytywanie punktów krańcowych, migotanie wartości,...) to możesz być pewien, że problem jest związany ze sprzętem, a nie z błędną konfiguracją modelu.

Strona analogowa prezentuje także ustawienie kalibracji baterii. Powinno być ono prawidłowe od nowości, ale jeśli nie, przesuń kursor do tego pola i skoryguj je tak aby wyświetlana wartość odpowiadała napięciu mierzonemu woltomierzem na zaciskach baterii.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09d_switchdiag.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09d_switchdiag.png)

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09e_anadiag.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/09e_anadiag.png)

#### Kalibracja ####

To jest miejsce gdzie możesz skalibrować drążki i potencjometry. Postępuj zgodnie z instrukcją na ekranie, tylko zauważ, że gdy jesteś proszony o wycentrowanie drążków, dotyczy to także drążka gazu i obu bocznych suwaków. Potencjometry S1 i S2 nie muszą być centrowane, tylko położenia krańcowe są kalibrowane.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/10_calib.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/10_calib.png)

### Menu modelu ###

KRÓTKIE naciśnięcie klawisza MENU z ekranów głównych przywołuje ekran wyboru modelu. Dostępne tam menu umożliwia wybieranie, usuwanie, archiwizowanie i odtwarzanie na/z karty SD. Menu  jest osiągalne przez DŁUGIE naciśnięcie klawisza ENTER. Modele mogą być kopiowane lub przesuwane (jedno KRÓTKIE naciśnięcie na klawisz ENTER podświetla linię, +/- tworzy kopię modelu i umieszcza na pożądanej pozycji, zaś dwa KRÓTKIE naciśnięcia tworzą kropkowaną ramkę, a +/- przesuwają wybrany model na inną pozycję).

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/11_modelsel.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/11_modelsel.png)

#### Ustawienia modelu ####

KRÓTKIE nacisnięcie klawisza PAGE przywołuje stronę podstawowych ustawień modelu:

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/12_model_setup.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/12_model_setup.png)

  * Model name (nazwa modelu): Zmiana litery w nazwie - klawiszami +/-, przejście do następnej litery - KRÓTKIE naciśnięcie ENTER, DŁUGIE ENTER zmienia aktualną literę na wielką, przed przejściem do następnej.
  * Model image (rysunek modelu): Możesz tu wybrać, jako logo Twojego modelu, plik .bmp o rozdzielczości 64x32 i 16-stopniowej skali szarości, zlokalizowany w folderze BMP karty SD. Aby obejrzeć dostępne obrazki użyj [przeglądarki karty SD](http://code.google.com/p/opentx/wiki/OpenTx_FrSky_PL#Przeglądarka_SD).
  * Timers (timery): W aparaturze są dwa, w pełni programowalne timery, które liczą w górę lub w dół. Jeśli wartość w tym polu jest ustawiona na 0:00, timer będzie liczył w górę, jeśli nie, będzie odliczał w dół od zaprogramowanej wartości. Wyzwalacz timera jest ustalany w polu obok. ABS oznacza odliczanie cały czas, THs liczy gdy drążek (kanał) gazu nie jest w pozycji zerowej. THt uruchamia timer, gdy drążek gazu jest po raz pierwszy przesunięty w górę, TH% liczy proporcjonalnie do wychylenia drążka gazu. Jeśli pole "Persistent" jest zaznaczone, wartość timera zostanie zapisana do pamięci przed wyłączeniem radia, bądź zmianą modelu i załadowana z pamięci gdy model będzie ponownie wybrany. "Minute call" sygnalizuje upływające minuty piknięciem lub głosem. Jeśli timer liczy w dół, upływ ostatniej minuty będzie kilkakrotnie sygnalizowany.
  * Extended limits (rozszerzone limity) pozwalają ustawić limity ruchu serwa aż do 125% zamiast 100%.
  * Extended trims (rozszerzone trymowanie) pozwala trymerom pokryć cały zakres ruchu drążka zamiast +/- 25%. Bądź ostrożny używając tej opcji, gdyż przytrzymanie klawisza trymera zbyt długo, może ustawić trymowanie tak, że modelem nie da się latać. Opcja "Reset" wyzeruje wszystkie trymery (dla wszystkich trybów lotu).
  * Trim step (krok trymera) ustawia precyzję trymowania. Exponential oznacza bardzo drobne kroki w okolicy środka trymera, i tym większe im dalej od tegoż środka.
  * Throttle reverse (odwrócenie gazu): Zapewnia prawidłowe działanie timerów i funkcji związanych z drążkiem gazu dla ludzi, którzy lubią mieć pełny gaz przy drążku opuszczonym do dołu.
  * Throttle source (źródło informacji o gazie) definiuje co wyzwala funkcję THx dla timerów. Zwykle ustawia się to na kanał gazu, zamiast drążka gazu, przez co są brane pod uwagę funkcje odcinania gazu itp.
  * Throttle trim (trymer gazu) : Tryb pracy dla silników spalinowych, gdzie trymer wpływa tylko na wolne obroty, bez oddziaływania na punkt pełnego otwarcia przepustnicy.
  * Throttle Warning (ostrzeżenie o dźwigni gazu): Ostrzeże Cię jeśli w chwili włączenia radia lub załadowania modelu, drążek gazu nie jest w położeniu zerowym.
  * Switch warning (ostrzeżenie o przełącznikach): Określa czy radio wymaga aby przełączniki znajdowały się w ustalonych pozycjach po włączeniu zasilania/zmianie modelu. Aby ustalić te  pozycje należy odpowiednio ustawić przełączniki, a następnie DŁUGO wcisnąć klawisz ENTER.
  * Center beep (piknięcie na środku): Generuje piknięcie gdy drążki lub potencjometry przechodzą przez punkt środkowy swojego ruchu.
  * Internal RF (wewnętrzny moduł nadawczy):
    * Mode: Tryb transmisji modułu (OFF - wyłączony, D16, D8, LR12).
    * Channel range (zakres kanałów): Wybór wewnętrznych kanałów aparatury transmitowanych przez moduł nadawczy.
    * Receiver no (numer odbiornika, tylko dla trybu D16 / LR12): określa zachowanie funkcji "receiver lock". Ten numer jest wysyłany do odbiornika, który odbiera transmisję tylko gdy jest to numer, z którym został on zbindowany. Domyślnie, jest to numer modelu w chwili jego utworzenia. Może on jednak być ręcznie zmieniony i nie zmieni się gdy model jest przesuwany lub kopiowany. Jeśli ręczne ustawienie albo operacja przesunięcia lub kopiowania powoduje, że dwa modele będą miały ten sam numer, pokaże się ostrzeżenie. Do użytkownika należy ocena czy jest to zamierzone czy nie.
    * Pola Bind i Range (kontrola zasięgu) są aktywowane przyciśnięciem klawisza ENTER. Wewnętrzny moduł będzie pikał co kilka sekund aby potwierdzić tryb bindowania lub kontroli zasięgu. Przy kontroli zasięgu, pokaże się okienko z wartością RSSI dla oceny jak zmienia się jakość odbioru.
    * Tryb failsafe (zachowanie odbiornika przy braku sygnału - tylko dla D16 / LR12): Pozwala wybrać między prostym utrzymywaniem ostatniej pozycji, wyłączeniem impulsów PPM (jak w starych odbiornikach 35MHz), lub ustawieniem serw w określonych pozycjach. Dla określenia pozycji serw, pole SET wywoła stronę ustawień failsafe, pozwalającą ustalić pozycję dla każdego kanału z osobna. Wybierz żądany kanał, naciśnij ENTER aby przejść do trybu edycji, przesuń drążek w na odpowiednią pozycję i naciśnij ENTER aby ją zapisać. W trybie D8 to pole jest ukryte, należy ustawić failsafe po stronie odbiornika zgodnie z opisem w jego instrukcji.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/13_failsafeset.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/13_failsafeset.png)
  * Zewnętrzny moduł nadawczy:
    * Module type (typ modułu): PPM dla tradycyjnych modułów, XJT (takie same tryby pracy jak powyżej).
    * Channel range (zakres kanałów) : tak samo jak dla modułu wewnętrznego.
    * Receiver no, Bind, Range check (gdy moduł zewnętrzny to  XJT): Jak powyżej.
    * PPM Frame (Ramka PPM - gdy moduł typu PPM): Pozwala na ustawienie długości ramki, długości impulsu i polaryzacji ramki PPM. Długość ramki jest automatycznie korygowana do bezpiecznej wartości kiedy zmienia się liczba transmitowanych kanałów. Zaawansowani użytkownicy mogą wciąż ją korygować jeśli jest to im potrzebne.
    * Failsafe mode: Gdy moduł jest typu XJT - tak samo jak powyżej.
  * Trainer mode (tryb trenera): Nauczyciel lub uczeń, to ustawienie definiuje w którą stronę działa port trenera. Ikona, pokazująca który tryb jest używany, jest widoczna na głównym ekranie gdy włożona jest wtyczka do portu trenera. W trybie ucznia (wyjściowym), kanały które powinny być wysyłane i parametry ramki PPM można dostosowywać tak jak dla zewnętrznego modułu radiowego.

#### Ustawienia helikoptera ####

KRÓTKIE naciśnięcie klawisza PAGE pokazuje stronę miksera głowicy CCPM dla helikopterów. Ta strona pozwala na ustawienie rodzaju tarczy i ograniczanie wychyleń poprzez ustawienia pierścienia tarczy.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/14_heli.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/14_heli.png)

Parametrami wejściowymi dla tego miksera są drążki Ail (lotki) i Ele (wysokość), dodatkowo wirtualny kanał wybrany w "Collective source". Ten kanał będzie "widział" wpisy dodane na stronie MIXER dla jednej lub wielu krzywych pochylenia.

Wyjścia miksera CCPM to CYC1, CYC2i CYC3, należy je przypisać do kanałów, do których podłączysz serwa, na stronie MIXER.

Zauważ, że ustawienia dokonane tutaj nie dają efektu dopóki nie używasz źródeł CYC1, CYC2, ani CYC3. Wielowirnikowiec lub helikopter bez flybar-a, który używa pokładowych komputerów/mikserów nie będzie ich używał.

#### Tryby lotu ####

Następny ekran to ekran trybów (faz) lotu.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/15_FP.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/15_FP.png)

Dostępne jest 8 trybów (faz) lotu plus tryb domyślny. Każdy z nich może być nazwany, można wybrać przełącznik, który go aktywuje (fizyczny lub logiczny), tablicę wyboru trymerów (litery R, E, T, A oznaczają, że tryb lotu ma osobne ustawienia trymerów dla tego elementu sterującego, ale mogą one być zmienione na cyfry od 0 do 9 co oznacza używanie wartości takich samych jak w innym trybie lotu o wskazanym numerze), oraz parametry spowalniania dla uzyskania płynnych przejść między trybami.

Priorytet trybów lotu jest tak ustalony, że pierwszy tryb lotu z zakresu 1-8, którego przełącznik jest włączony, jest trybem aktywnym.
Jeśli żaden z przełączników trybów lotu nie jest włączony, aktywny jest domyślny tryb FM0.

#### Drążki ####

Następny ekran pozwala na ustawienie jednej lub więcej zasad formowania sygnału wytwarzanego przez drążki dla każdego kierunku (osi) ich wychylania. Jest to pierwszy stopień łańcucha sterowania, tu definiuje się czułość drążków, określa się jak silny będzie wpływ drążków na sterowanie modelem.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/16_inputs.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/16_inputs.png)
![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/17_dr.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/17_dr.png)

Z każdym drążkiem (osią ruchu drążka) można powiązać tyle linii tabeli konfiguracyjnej ile potrzeba (DŁUGIE wciśnięcie ENTER wyświetla menu). Pierwsza linia (od góry), której przełącznik jest włączony będzie aktywna. Ta zasada jest zwykle używana do uzyskania podwójnych, potrójnych,... ustawień czułości (dual rates - D/R). Dla każdego wiersza tabeli można zdefiniować nazwę, czułość jak również wykładniczy współczynnik czułości (exponential - EXP). Dodatnia wartość EXP umożliwia uzyskanie małej czułości w okolicach neutralnego położenia drążka. Czułość rośnie w miarę wychylania drążka. Dla ujemnego EXP, czułość jest największa w okolicach położenia neutralnego i maleje w miarę wychylania. Zamiast zwykłej funkcji wykładniczej można użyć krzywej (standardowej lub samodzielnie zdefiniowanej).

Lista trybów pozwala wybrać, w którym trybie lub trybach lotu (podświetlone cyfry) dany wiersz tabeli może być aktywny. Jeśli dany tryb nie jest wybrany, włączenie przełącznika nie spowoduje aktywacji wiersza tabeli.

Parametr "Side" ogranicza efekt działania linii tabeli, tylko do jednej strony wychylenia drążka.

Podsumowanie wybranych trybów lotu dla każdej linii jest pokazywane na głównym ekranie.

#### Mikser ####

Następna strona to miejsce gdzie działania elementów sterujących będą mapowane na serwa. openTx nie posiada żadnych predefiniowanych funkcji miksowania, które są związane z określonym typem modelu czy sytuacją, on raczej daje Ci podstawy na których możesz budować. Kluczem do konfiguracji modelu w openTx nie jest myślenie o "włączeniu miksera delty" jak w pewnych radiach, ale raczej myślenie jaki efekt sterowania w modelu chcesz uzyskać w odpowiedzi na działania elementów sterujących radia. Mikser to jest to miejsce gdzie cała ta logika jest wprowadzana.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/18_mixer.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/18_mixer.png)

Poszczególne kanały są wyjściami, na przykład CH1 jest wtyczką serwa numer 1 w twoim odbiorniku (przy domyślnych ustawieniach protokołu transmisji). Kanał bez linii miksera po prostu będzie centrował serwo, które byłoby do niego podłączone.

Każda linia miksera łączy jedno wejście z kanałem, w którym jest wstawiona. Wejścia mogą być takie:
  * 4 osie wychylenia drążków
  * 4 potencjometry i suwaki
  * Wyjścia miksera helikoptera (CYC1-3)
  * Stała wartość (MAX)
  * 8 przełączników fizycznych
  * 32 przełączniki logiczne
  * Kanały wejściowe portu trenera (PPM1-8)
  * Każdy z 32 kanałów radia, co umożliwia używanie kanałów jako wirtualnych funkcji dla przejrzystości konfiguracji (zmiksuj kilka wejść w jedną, wielokrotnie używaną, funkcję, która następnie może być przypisana do jednego lub więcej kanałów). Zauważ, że ustawienia ze strony serw nie są tu brane pod uwagę.

Wszystkie wejścia działają w zakresie od -100% do +100%. Drążki, potencjometry, kanały, źródła CYC, wejście portu trenera będą zmieniać się proporcjonalnie w tym zakresie. Przełączniki 3-pozycyjne zwracają -100%, 0% lub +100%. przełączniki 2-pozycyjne (i te logiczne) zwracają -100% lub 100%. MAX to zawsze 100%.

Jeśli chcesz kontrolować serwo, dołączone do wtyczki numer 2 Twojego odbiornika przy pomocy drążka steru wysokości, po prostu tworzysz linię miksera w kanale CH2 z Ele jako źródłem. Proste!

W każdym kanale, możesz mieć tyle linii miksera ile potrzebujesz. Możesz wybierać, które z nich działają. Aby stworzyć nowa linię, mógłbyś DŁUGO nacisnąć klawisz ENTER i wybrać insert before/after (wstaw przed/po). Domyślnie wszystkie linie w tym samym kanale sumują się, ale linia może także mnożyć linie ją poprzedzające lub je zastępować.

Dla przejrzystości, każda linia, która jest aktualnie aktywna i przyczynia się do wyznaczania sygnału wyjściowego dla kanału, będzie miała swoje źródło wyświetlane jako **pogrubione**. To może być bardzo poręczne jeśli istnieje wiele linii albo przy sprawdzaniu funkcji przełączników.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/19_editmix.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/19_editmix.png)

Dla każdej linii miksera, jest dostępne kilka parametrów:
  * Nazwa - dla wygody
  * Waga wejścia (w %). Określa ona jak duża część sygnału wejściowego ma być zmiksowana. Wartość ujemna odwraca odpowiedź.
  * Przesunięcie, które może być dodane do sygnału wejściowego.
  * Trymery, dla drążków domyślnie jest to trymer związany z drążkiem, ale może zostać wybrany inny trymer (dla funkcji cross-trimming, na przykład) albo całkiem wyłączony. Dla innych wejść, trymer jest domyślnie wyłączony, ale oczywiście może być wybrany jeśli jest to potrzebne.
  * Może być wprowadzone zarówno ustawienie różnicowe (redukuje odpowiedź o wskazany procent po jednej stronie wychylenia) jak i krzywa (wbudowana lub własna). Kiedy własna krzywa jest wybrana, naciśnięcie klawisza MENU przywołuje edytor krzywych.
  * Mogą być wybrane tryby lotu, w których mikser jest aktywny (zobacz D/R).
  * Przełącznik (fizyczny lub logiczny) służący do aktywowania linii miksera.
  * Może być wygenerowane ostrzeżenie dźwiękowe (1, 2 lub 3 piknięcia) kiedy tylko linia jest aktywna.
  * Ustawienie "Multpx" definiuje jak aktualna linia miksera współpracuje z innymi w tym samym kanale. "Add" po prostu dodaje jej wyjście do innych, "Multipl" pomnoży rezultat działania linii powyżej aktualnej, przez wyjście aktualnej linii, a "Replace" zastąpi to co było zrobione dotychczas, przez wyjście linii aktualnej. Kombinacje tych operacji umożliwiają tworzenie skomplikowanych operacji matematycznych.
  * Odpowiedź wyjściowa może być opóźniona i/lub spowolniona w stosunku do zmiany wejścia. Spowolnienie może być użyte na przykład do powolnego wypuszczania podwozia obsługiwanego przez normalne serwo. Czas określa ile sekund sygnał wyjściowy będzie potrzebował do zmiany w zakresie -100 do +100%.

Jako mały przykład, jeśli chciałbyś dodać nieco kompensacji na kanale steru wysokości gdy zwiększasz gaz, mógłbyś pójść taką prostą drogą:
  * Na jaką powierzchnię sterową chciałbym wpłynąć? _Na ster wysokości, który jest podłączony do CH2._
  * Kiedy chciałbym aby on się poruszył? _Kiedy poruszę drążkiem gazu_, jako dodatek do czegokolwiek co byłoby do tej pory związane z kanałem CH2 (zwykle byłby to drążek steru wysokości).

Poszedłbyś do CH2, wstawił nową linię z wejściem Thr. Typ byłby "Add" jako że kompensację należy dodać do "normalnej" odpowiedzi steru wysokości. Jako że wymagana kompensacja jest prawdopodobnie mała, nastawiłbyś małą wagę, może 5%. Na ziemi, przy odłączonym silniku, sprawdzisz czy ster wysokości jest kompensowany w odpowiednim kierunku. Jeśli nie, odwróciłbyś wagę na -5%.

Mógłbyś potem przypisać przełącznik, aby być w stanie aktywować/dezaktywować kompensację w czasie lotu żeby zobaczyć czy wielkość kompensacji jest rzeczywiście odpowiednia. Jeśli korekcja jest bardziej skomplikowana, możesz chcieć przypisać i stworzyć krzywą, która pasuje do tego co chciałbyś uzyskać.

#### Serwa ####

Strona serw jest interfejsem między logiką ustawień i prawdziwym światem serw, dźwigni i powierzchni sterowych. Jak dotąd, ustawiliśmy to, co chcemy aby nasze różne elementy sterujące robiły, teraz jest czas aby zaadaptować to do mechanicznych charakterystyk modelu.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/20_outputs.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/20_outputs.png)

Dla każdego kanału możemy zdefiniować:
  * nazwę, która będzie pokazana na ekranie miksera gdy kursor jest w linii należącej do tego kanału, na ekranie monitora kanałów i na stronie ustawień zachowania odbiornika po utracie sygnału (failsafe).
  * Przesunięcie trymera serwa (subtrim). Zauważ, że trymer serwa i trymer drążka to dwa różne rodzaje regulatorów.
  * Górny i dolny limit wychyleń. Są to "twarde" limity, tzn. nigdy nie będą one nadpisane, więc tak długo jak są one ustawione tak aby Twoje serwo nigdy nie "siłowało" się próbując przesunąć dźwignię poza zakres możliwości, ono naprawdę nigdy nie będzie tego robić. Służą one również jako wzmocnienie lub "ustawienia punktów krańcowych", więc zmniejszenie limitu, zmniejszy zakres ruchu, a nie będzie go obcinać.
  * Odwrócenie kierunku działania serwa.
  * Korekcja centrowania. To jest ustawienie podobne w działaniu do trymera serwa, z taką różnicą, że korekcja zrobiona tutaj, przesunie cały zakres ruchu serwa (włączając limity), i nie będzie widoczna na monitorze kanałów.
  * Zachowanie trymera serwa: Kiedy ta opcja jest ustawiona na wartość domyślną, regulacja trymera serwa przesunie tylko punkt centralny ruchu serwa. Otrzymując z miksera polecenie od -100% do +100%, serwo będzie się poruszać dokładnie pomiędzy dolnym i górnym limitem bez obcinania zakresu i bez strefy martwej. To wprowadza zróżnicowaną relację między drążkiem a ruchem serwa dla wychyleń drążka w każdą ze stron. Zależnie od sytuacji może to być wygodne albo problematyczne. Ustawienie tego parametru na "=" zmienia efekt trymowania serwa na coś w rodzaju "symetrycznego" przesunięcia zakresu ruchu serwa. Polecenie pełnego ruchu z miksera, może teraz być obcięte przez limit, który jest po tej samej stronie co trymer serwa, zaś na przeciwnej stronie serwo nie osiągnie limitu. W ten sposób po obu stronach drążka, określony ruch zawsze da w wyniku taki sam ruch serwa. Użycie domyślnego trybu ("^") pozwala na szybsze ustawianie serw które są sterowane przez jeden element sterujący. Ustawienie "=" jest wymagane dla utrzymania prawidłowej odpowiedzi powierzchni sterujących przy użyciu wychyleń różnicowych i/lub miksowaniu wielu źródeł razem. Tryb "=" typowo wymaga zredukowania wychyleń (D/R) tak aby pozostawić margines między pełnym zakresem sterowania wychyleniem i zdefiniowanymi limitami.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/openTx_subtrim_modes.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/openTx_subtrim_modes.png)

Ostatnia linia po CH32 to funkcja "Trims to Offsets". Jest ona używana aby wziąć ustawienia trymerów drążków dla aktualnie wybranego trybu lotu, przepisać ich zawartość do trymerów serw, wyzerować trymery drążków dla aktualnego trybu i skorygować trymery drążków dla wszystkich pozostałych trybów lotu. Jeśli jesteś blisko końca zakresu trymerów drążków, zamiast być zmuszonym do korygowania każdej wartości jedna po drugiej, wszystko co musisz zrobić to nacisnąć DŁUGO ENTER na tej linii i reszta magicznie robi się sama. Bądź świadom, że nadal powinieneś sprawdzić czy nie mądrzej byłoby poprawić problem mechanicznie. W szczególności, wielkie wartości trymów, zależnie od ustawień zachowania się trymerów serw mogą doprowadzić do niewystarczających jak i niesymetrycznych wychyleń, ich ograniczania/powstania nieczułej strefy.

#### Krzywe ####

Do kształtowania wejść jak i do mikserów mogą być używane własne krzywe. Jest dostępne 16 krzywych kilku typów (3, 5, 9, 17-punktowe, ze stałymi albo definiowalnymi współrzędnymi x).  3pt to 3-punktowa krzywa ze stałymi x-ami, 9pt' to 9-punktowa krzywa z definiowanymi x-ami.

Następujące krzywe są dostępne dodatkowo, oprócz krzywych "wbudowanych":
  * x>0, x<0: Jeśli wejście jest, odpowiednio dodatnie albo ujemne zwraca wejście, w przeciwnym wypadku - zero.
  * |x|: Zwraca wartość bezwzględną (moduł) wejścia.
  * f>0, f<0: Jeśli wejście jest, odpowiednio dodatnie albo ujemne zwraca 100%, w przeciwnym wypadku 0.
  * |f|: Jeśli wejście jest ujemne zwraca -100%. Jeśli wejście jest dodatnie zwraca +100%.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/21_curves.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/21_curves.png)

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/21b_editcurve.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/21b_editcurve.png)

Edytor krzywych pozwala na definiowanie nazwy dla wybranej krzywej, jej typu i oczywiście określanie współrzędnych. Gdy kursor wskazuje jedną z edytowalnych współrzędnych, DŁUGIE naciśnięcie klawisza ENTER powoduje wyświetlenie menu, z którego można wybrać standardową krzywą, dokonać lustrzanego odbicia krzywej w poziomie lub wyzerować wszystkie punkty.

#### Zmienne globalne ####

Zmienne globalne są wartościami, które mogą zastąpić zwykłe liczby w każdym miejscu gdzie występuje Waga, Offset, Różnicowość czy ustawienie Expo. Ich głównym zastosowaniem jest grupowanie nastawiania kilku parametrów, które powinny mieć taką samą wartość. Na przykład, różnicowość lotek w szybowcu z czterema powierzchniami sterowymi uruchamianymi funkcją lotek. Próbując znaleźć złoty środek dla siły różnicowości w modelu, zamiast w kółko poprawiać wartość parametru różnicowości w czterech mikserach, można skonfigurować wszystkie 4 z użyciem zmiennej globalnej (np. odpowiednio GV1 i -GV1, wybranej przez DŁUGIE naciśnięcie klawisza ENTER w polu "Differential"). W takiej sytuacji, nastawienie GV1 na tej stronie jest jedyna zmianą potrzebną do zaktualizowania wszystkich różnicowości.

Zmienne globalne są powiązane z trybami lotu, więc zamiast tworzyć oddzielne linie miksera dla poszczególnych trybów lotu, każda z inną wartością parametru, można użyć jako parametru zmiennej globalnej przyjmującej różne wartościami dla każdego trybu lotu. Może to znacząco pomóc w uproszczeniu konfiguracji miksera przez unikanie powielonych wpisów.

Zmienne globalne mogą być korygowane w czasie lotu dzięki funkcji specjalnej "Adjust GVx", która będzie opisana później. Pomaga to ustawiać parametry, które łatwiej jest wyregulować w locie jak np. współczynnik D/R, wychylenia wykładnicze (EXP) lub, znowu, różnicowość.

Ekran zmiennych globalnych pozwala na ustawianie, dla wygody użytkownika, nazwy dla każdej z 5 dostępnych zmiennych, a także podglądanie/ustawianie wartości, które będą one mieć po włączeniu każdego z 9 trybów lotu.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/22_gvars.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/22_gvars.png)

#### Przełączniki logiczne ####

Są to logiczne przełączniki używane do porównywania wartości i łączenia rozmaitych warunków

Pierwsza kolumna "operations" zawiera jedną z kilku operacji arytmetycznych, logicznych albo różnicowych. W operacjach arytmetycznych "a" i "b" reprezentują zmienne, x reprezentuje stałą. Zmienne mogą być dowolnym źródłem np. wszystkie te dostępne w mikserach plus 5 zmiennych globalnych i wszystkie parametry telemetrii. W operacjach logicznych dostępne źródła to wszystkie fizyczne oraz logiczne przełączniki. Funkcje różnicowe porównują zmianę zmiennej od czasu jej ostatniego dopasowania do innej wartości.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/23_CS.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/23_CS.png)

  * a~x: aktywny gdy zmienna "a" jest w przybliżeniu równa stałej "x" (z uwzględnieniem histerezy, gdyż np. wartość wychylenia drążka prawie nigdy nie będzie dokładnie równa stałej)
  * a<x, a>x: aktywny gdy zmienna "a" jest, odpowiednio, mniejsza lub większa niż stała "x"
  * |a|<x, |a|>x: Aktywny gdy wartość bezwzględna (moduł) wartości zmiennej "a" jest, odpowiednio, mniejsza lub większa niż stała "x"
  * a<b,a>b,a=b: Jak powyżej, ale dla dwóch zmiennych
  * AND, OR, XOR: Logiczny iloczyn, suma albo alternatywa
  * d≥x, |d|≥x: aktywny gdy wybrana zmienna, albo odpowiednio - jej wartość bezwzględna, zmieniła się bardziej niż "x" od ostatniego sprawdzenia, które włączyło przełącznik. Na przykład d≥x Alt 16 spowoduje załączenie przełącznika za każdym razem gdy wysokość zwiększy się co najmniej o 16m. |d|≥x Alt 16 spowoduje załączenie przełącznika za każdym razem gdy wysokość zwiększy się lub zmniejszy o 16m.
  * TIM: Przełącznik czasowy. TIM 0.5 2.0 byłby aktywny 0.5s, nieaktywny przez 2s, i tak w kółko.

Przełączniki logiczne oferują jeszcze trzy parametry: dodatkowy warunek AND (jeśli został wpisany, musi być spełniony aby przełącznik logiczny był aktywny), czas trwania (minimalny czas, przez który przełącznik jest włączony, nawet jeśli włączający go warunek przestaje być spełniony natychmiast) oraz opóźnienie (które dotyczy zarówno włączenia jak i wyłączenia). Spójrz na belkę nagłówka tabeli aby stwierdzić jakie jest znaczenie wartości wskazanej kursorem.

DŁUGIE naciśniecie klawisza ENTER na nazwie przełącznika logicznego wywołuje menu kopiowania/wklejania/usuwania wiersza tabeli umożliwiające wygodniejsze wprowadzanie wielu podobnych ustawień.

#### Funkcje specjalne ####

Jest to miejsce gdzie przełączniki mogą być przyporządkowane do uruchamiania dodatkowych funkcji takich jak tryb uczeń-nauczyciel, odtwarzanie dźwięku, głosowe odczytywanie zmiennych itd.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/24_CF.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/24_CF.png)

Pierwsza kolumna tabeli wskazuje wyzwalacz funkcji. Może to być przełącznik (fizyczny lub logiczny) lub "ON" (funkcja zawsze włączona). DŁUGIE wciśnięcie klawisza ENTER przechodzi w tryb "przełączania" (pojawia się "t" na końcu nazwy wyzwalacza). Tryb ten oznacza iż wybrana funkcja będzie włączona gdy przełącznik jest włączany i pozostanie włączona aż do momentu gdy przełącznik zostanie wyłączony i włączony ponownie.

Przewijając listę wyzwalaczy, znajdziesz kilka dodatkowych opcji: "One" (włącza funkcję tylko raz w momencie włączenia nadajnika lub załadowania modelu), SHdownS (krótkie naciśnięcie przełącznika chwilowego) SHdownL (długie naciśniecie przełącznika chwilowego).

Dostępne są następujące funkcje:
  * Safety CHx: Gdy funkcja jest aktywna, stan wyjścia kanału CHx jest wymuszany zgodnie z wybrana wartością. Jest tutaj checkbox włączający tę funkcję, co zwykle robi się po sprawdzeniu, że wartość jest prawidłowo ustawiona, a przełącznik jest wyłączony. Dokładne sprawdzenie jest szczególnie ważne, gdy zmieniasz ustawienia, a zasilanie Twojego modelu jest włączone.
  * Trainer, TrainerXXX: Odblokowuje tryb uczeń-nauczyciel, globalnie lub dla poszczególnych drążków. Jeśli użyjesz funkcji bez wskazania indywidualnego drążka, zadziała ona dla wszystkich czterech.
  * Instant trim: Funkcja szybkiego trymowania. Gdy funkcja zostanie aktywowana, aktualne pozycje drążków będą dodane do odpowiednich trymerów. Ta funkcja jest zwykle przypisywana do przełącznika chwilowego i używana przy oblocie gdy, jak można przewidywać, pozycje trymerów są dalekie od właściwych. Zamiast gorączkowo, klikać przyciski trymerów, można przytrzymać drążki w pozycji, w której model leci prosto i raz przycisnąć przycisk szybkiego trymowania. Najlepiej, usunąć tę funkcję po oblataniu modelu aby uniknąć omyłkowego jej włączenia co mogłoby spowodować katastrofalnie błędne trymowanie.
  * Play Sound: Gra prosty dźwięk, który można wybrać z listy.
  * Reset: Kasuje wybraną wartość (Timer 1, Timer 2, jeden z parametrów telemetrii, lub wszystkie z nich)
  * Vario: Włącza dźwięki wariometru (zobacz [ustawienia telemetrii](http://code.google.com/p/opentx/wiki/OpenTx_FrSky_PL#Telemetria))
  * Play track: Odtwarza plik dźwiękowy z karty SD, powtarzając co wskazany czas
  * Play value: Odczytuje aktualną wartość wybranego parametru, powtarzając co wskazany czas
  * SD Logs: Zapisuje wartości pomiarów telemetrii na karcie SD co wskazany czas
  * Volume: Ustawia głośność dźwięków według wskazanego regulatora
  * Backlight: Włącza podświetlanie ekranu
  * BgMusic, BgMusic || (pause): Odtwarza wybrany plik dźwiękowy z karty SD. "BgMusic Pause" wstrzymuje odtwarzanie i wznawia je gdy funkcja jest nieaktywna. Gdy funkcja "BgMusic" jest nieaktywna odtwarzanie jest całkiem zatrzymywane.
  * Adjust GVx: Ustawianie zmiennej globalnej (GVAR). Gdy funkcja jest aktywna, ustawia odpowiednią zmienna globalną według wartości wskazanego źródła. Źródło, może być wybrane z jednej z czterech grup cyklicznie przełączanych przy pomocy DŁUGIEGO wciśnięcia klawisza MENU:
    * Stała wartość
    * Regulator lub kanał z np. określoną krzywą/wagą/przesunięciem dla ograniczenia zakresu ustawiania
    * Inna GVAR
    * +1/-1, dla zwiększenia/zmniejszenia GVAR przy każdej aktywacji.

DŁUGIE wciśnięcie klawisza ENTER na nazwie funkcji wywołuje menu, które pozwala skopiować/wstawić/usunąć wiersz tabeli dla ułatwienia wprowadzania wielu podobnych ustawień.

#### Telemetria ####

Ta strona gromadzi wszystkie podstawowe ustawienia związane z telemetrią.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/25_telemetry.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/25_telemetry.png)

  * A1 i A2 są dwoma portami analogowymi dostępnymi na odbiornikach D8R. Odbiorniki X8R mają tylko wejście A1, które mierzy napięcie zasilania odbiornika. Parametr "Range" ustawia maksymalne mierzone napięcie, np. 3.3V / (współczynnik podziału). Na przykład dla wewnętrznego czujnika napięcia w odbiorniku (1:4), byłoby to 13.2V. Dla czujnika FBVS-01 z domyślnym współczynnikiem podziału 1:6, byłoby to 19.8V. Liczba przy "Ax channel" będzie pokazywać aktualnie mierzoną wartość i może być użyta do potwierdzenia prawidłowego ustawienia "Range" przez porównanie odczytu z zewnętrznym woltomierzem. Można dodatkowo użyć przesunięcia i własnych jednostek (A, m/s, m, °, %...) dla ułatwienia skalowania sygnału wejściowego przy przystosowywaniu analogowych czujników innych producentów.
  * Alarmy "Low" i "Critical" dla A1, A2, i RSSI będą wyzwalać dźwiękowe ostrzeżenia, gdy mierzona wartość spada poniżej zdefiniowanych poziomów. Gdy w nadajniku jest obecna karta microSD z pakietem głosów, te alarmy będą oznajmiane czystym głosem (np. "A1 low", "A2 Critical, "RF signal Low"). Jeśli karta nie jest obecna, każdy alarm wyzwoli odmienną sekwencję piknięć. Rekomendujemy używanie zdolności nadajnika do wytwarzania głosu gdyż 6 różnych sekwencji pikania może być trudne do zapamiętania zwłaszcza w sytuacji stresowej.
  * Blades: Liczba łopat (śmigła) potrzebna dla czujnika prędkości obrotowej.
  * Voltage/Current (Napięcie/prąd): Pozwala wybrać wejście dla obliczania mocy i funkcji zliczania mAh. Te parametry powinny wskazywać wejścia, do których podłączyłeś odpowiednie czujniki.
  * Variometer source (źródło sygnału wariometru): Rodzaj czujnika, który jest zainstalowany w Twoim modelu. "Alti" jest dla starego czujnika wysokości FrSky, "Alti+" jest dla wysokiej rozdzielczości czujników innych producentów (w przypadku jednego z nich openTx sam wylicza prędkość pionową z informacji o wysokości którą odbiera), "Vario" jest dla nowych czujników wariometrycznych FrSky jak również dla [openxvario](http://code.google.com/p/openxvario/) (prędkość pionowa jest wyliczana przez czujnik). "Limit " ustawia odpowiednio maksymalną oczekiwaną prędkość opadania, dolną i górną granice strefy martwej (brak dźwięku), oraz maksymalną prędkość wznoszenia dla dźwięków generowanych przez funkcję specjalną "Vario".
Po tych podstawowych parametrach następują wzory trzech własnych ekranów telemetrii. Ekrany te mogą być oglądane po DŁUGIM naciśnięciu klawisza PAGE na głównym ekranie. Każdy ekran może pokazywać parametry w postaci liczb (9 parametrów na głównej części ekranu i 3 w dolnym pasku) lub 4 paskowe wskaźniki graficzne z konfigurowanymi górnymi i dolnymi limitami.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/07_telem_custom.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/07_telem_custom.png)
![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/07b_telem_bars.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/07b_telem_bars.png)

Każde pole może być jednym z wielu dostępnych parametrów, naturalnie, odpowiednie czujniki i/lub hub muszą być zainstalowane w modelu:

  * Tmr1,2: Oba timery
  * SWR: Jakość pracy anteny nadajnika. Powinien być zawsze poniżej 51. W przeciwnym wypadku wyskoczy okienko i zabrzmi alarm aby skłonić cię do sprawdzenia anteny nadajnika. Wartość sama w sobie niewiele znaczy.
  * RSSI: Mniejsza z wartości RSSI z nadajnika i odbiornika w trybie D8. W trybie D16, RSSI odbiornika.
  * A1,2: Analogowe porty w odbiornikach serii D (w X8R tylko A1 jest dostępne - mierzy napięcie zasilania odbiornika)
  * Alt: Wysokość według czujnika barometrycznego.
  * Rpm: Prędkość obrotowa silnika. Liczba łopat (śmigła) jest nastawiana powyżej.
  * Fuel: Poziom paliwa
  * T1,T2: Temperatura z czujników 1 i 2
  * Spd, Dist, GAlt: Prędkość według GPS, odległość od punktu startu, wysokość według GPS.
  * Cell: Napięcie najsłabszej celi według FLVS-01
  * Cels: Suma napięć wszystkich cel według FLVS-01
  * Vfas: Napięcie mierzone przez FAS-40/100
  * Curr: Natężenie prądu, źródło danych konfigurowane powyżej (FAS lub wejście analogowe)
  * Cnsp: Zużyte mAh baterii (czujnik prądu musi być prawidłowo skonfigurowany)
  * Powr: Moc, czujniki napięcia i prądu konfigurowane powyżej
  * AccX,Y,Z: Wartości przyspieszeń według TAS-01
  * Hdg: Kierunek lotu (kurs) według GPS
  * Vspd: Prędkość pionowa (obliczona przez aparaturę lub raportowana przez czujnik wybrany powyżej)
  * xxx+/xxx-: Wartości minimalne i maksymalne powyższych parametrów

#### Wzory modeli ####

Wzory są aktualnie "punktem startowym" dla ustawień modeli. Kiedy konkretny wzór zostanie wybrany DŁUGIM naciśnięciem ENTER, będzie dodany lub zastąpi miksery i ustawienia aktualnie wybranego modelu ustawieniami typowymi dla przypadku którego ten wzór dotyczy (najlepiej używać wzorów dla nowo stworzonego modelu). Mogą być one używane jako baza do zbudowania pożądanej konfiguracji lub po prostu do zrozumienia idei tego co jest wymagane dla danego typu modelu.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/27_templates.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/27_templates.png)

## Pierwsze kroki ##

Teraz, kiedy znasz już podstawy a Twoja bateria jest naładowana, co powiesz na odrobinę praktyki? Pierwsza rzecz do zrobienia z Twoją aparaturą to kalibracja drążków i potencjometrów. Przy pierwszym włączeniu zasilania, ekran kalibracji powinien pojawić się automatycznie. Postępuj zgodnie z instrukcją i zwróć uwagę, że istotne jest ustawienie drążka gazu w środkowej pozycji, gdy zostaniesz poproszony o ustawienie punktów środkowych drążków, ale nie jest to wymagane dla potencjometrów. Następny krok, to konfiguracja ustawień ogólnych. Przejdź do odpowiedniej strony przez DŁUGIE naciśnięcie klawisza MENU, ustaw datę, czas i taką jak lubisz głośność dźwięków (typowo, na dolnym końcu suwaka głośności jeśli używasz słuchawek, górny koniec jest dobry gdy używasz wewnętrznego głośnika), pobaw się ustawieniami podświetlania, ustaw kod kraju dla modułu nadawczego, domyślną kolejność kanałów zgodnie z Twoimi preferencjami, i tryb drążków (Mode) tak aby pasował to Twojego sposobu latania. Wskaźnik baterii i alarm jej niskiego poziomu są fabrycznie ustawione dla dostarczonej baterii.

Aparatura stworzy dla Ciebie "pusty" model, więc gdy powrócisz do głównego ekranu, będziesz w stanie przejść do ekranu ustawień modelu przez KRÓTKIE naciśnięcie klawisza MENU, następnie KRÓTKIE naciśnięcie PAGE. Tam będziesz chciał upewnić się, że ustawiłeś tryb pracy modułu nadawczego zgodnie z parametrami odbiornika, którego chcesz używać. Gdy używasz wewnętrznego modułu nadawczego, wybierz pole "Bind" i naciśnij ENTER aby zbindować twój odbiornik. Moduł nadawczy będzie pikał co kilka sekund. Teraz postępuj zgodnie z instrukcją bindowania Twojego odbiornika (naciśnij i przytrzymaj przycisk F/S i podłącz zasilanie odbiornika serii D lub X, albo załóż zworkę na piny S kanału 1 i 2 i podłącz zasilanie odbiornika V8x-II). LED odbiornika będzie szybko migał aby potwierdzić bindowanie. Naciśnij EXIT na aparaturze, usuń zworkę z odbiornika (jeśli zakładałeś), wyłącz i ponownie włącz zasilanie odbiornika. Powinieneś móc sterować serwami dołączonymi do kanałów 1-4 przy pomocy drążków.

## Konfiguracja modelu ##

### Podstawy openTx ###

Teraz, kiedy wszystko działa, zatrzymajmy się na chwilę i poznajmy trochę teorii podstaw działania oprogramowania openTx.

Jak pokrótce opisano powyżej, openTx odróżnia się od większości popularnych aparatur filozofią programowania. Właściciele aparatur Multiplexa szybko poczują się jak w domu, gdyż zasady są tu bardzo podobne.

W przeciwieństwie do zwykłych aparatur, które oferują wybór z ograniczonego zbioru predefiniowanych scenariuszy użycia radia (samolot, szybowiec, helikopter) oraz pewnej liczby funkcji zwykle używanych z takimi modelami (sterowanie typu delta, klapolotki, uwypuklenie profilu, motylek...), i mają sztywno przypisane kanały (drążki **zawsze** sterują odpowiednimi dla nich kanałami), openTx oferuje czystą kartę, na której możesz wymalować Twoje ustawienia: ekran mikserów. To podejście zapewnia maksymalna elastyczność, gdyż cokolwiek zrobisz, nie będziesz musiał obchodzić na około tego co oczekuje od Ciebie radio, co jest błogosławieństwem dla każdego, kto musi pracować z nowymi typami modeli, które ciągle "nie istnieją" dla producentów popularnych aparatur, i takich  dla których wbudowane funkcje są po prostu bezużyteczne. Możesz więc spojrzeć na to w ten sposób: Dla niektórych rodzajów modeli, zwykłe predefiniowane funkcje pozwalają skonfigurować model w ciągu sekund (po prostu włącz funkcję), ale dla innych spędzisz całe godziny starając się obejść ich ograniczenia. Z openTx-em, każdy jest mniej więcej na tym samym poziomie - na początku może zająć nieco dłużej ustawienie modelu, który wydaję się prosty, ale ten skomplikowany nie zajmie wiele więcej czasu. Jako że nie ma istniejącej funkcji, którą mógłbyś po prostu włączyć, jest wymagana podstawowa wiedza jak Twój model powinien działać, i co chciałbyś aby każda z powierzchni sterowych robiła. To oznacza, że możesz nawet nauczyć się czegoś o Twoim modelu w procesie jego konfiguracji!

Długa droga sterowania, zaczyna się od sprzętowych elementów sterujących (drążki, potencjometry, przełączniki), przechodzi przez ekran drążków (tu będzie wszystko co dotyczy czułości drążków jak dual rates czy EXP), podąża dalej - do miksera i kończy się zaadaptowaniem do mechanicznych charakterystyk modelu na ekranie serw.

### Wszystko o ekranie mikserów ###

Zaczniemy od tego, gdyż jest to sedno radia. Na ekranie mikserów znajduje się lista 32 kanałów wyjściowych, do których możesz dowiązać jedno lub więcej wejść z długiej listy fizycznych elementów sterujących (drążki, potencjometry, trymery, przełączniki), źródeł logicznych, innych kanałów oraz portu trenera. Przypisanie następuje przez dodanie _linii miksera_. Nowy model będzie miał 4 predefiniowane linie miksera dla kanałów 1, 2, 3 i 4, które łączą z nimi cztery drążki zgodnie z preferowaną kolejnością kanałów, którą wcześniej ustawiłeś. One zostały tam dodane dla Twojej wygody, ale mogą być dowolnie zmodyfikowane lub usunięte.

Usuńmy je wszystkie, podświetlając je, naciskając DŁUGO ENTER i wybierając "Delete" - usuń. Twój ekran mikserów jest teraz pusty, co oznacza, że radio zupełnie nic nie robi. No dobrze, robi, wysyła tyle kanałów ile zdefiniowano na stronie ustawień modelu do odbiornika (domyślnie kanały 1-8), ale ponieważ w mikserze te kanały są puste, żadne serwo się nie porusza, wszystkie będą wycentrowane. Daleko z tym nie zajdziesz, wiec będziesz chciał dodać do kanałów wejścia sterujące. Stworzysz linię miksera dla kanału CH1 przez podświetlenie go i DŁUGIE wciśnięcie ENTER, skończysz na stronie "INSERT MIX". Przewiń do pola "Source" - źródło, naciśnij ENTER i wybierz regulator, który chciałbyś aby oddziaływał na CH1. Możesz to zrobić przeglądając listę klawiszami + i -, lub iść na skróty i po prostu poruszyć żądany regulator (oczywiście, jeśli jest on fizyczny). Porusz drążkiem lotek, a pole zmieni się na "Ail" (może już takie być jeśli Twoja preferowana kolejność kanałów wskazana w ustawieniach ogólnych ma "A" dla pierwszego kanału, gdyż jest to brane pod uwagę). Pozostałe parametry możesz pozostawić bez zmian, co oznacza:
  * Współczynnik miksowania tego wejścia to 100% więc przeskalowane wyjście linii miksera będzie równe jej wejściu. Wartość -50% oznaczałaby, że wyjście byłoby połową wejścia i byłoby odwrócone.
  * Nie ma przesunięcia, więc przy wartości wejścia 0, wyjście linii miksera będzie również zerem. Niezerowa wartość przesunęłaby odpowiedź zgodnie z ustawioną wagą (wyjście = przesunięcie x waga).
  * Trymowanie jest włączone, w innym wypadku mogło by być wyłączone z obliczeń (OFF), lub inny trymer mógłby być używany (na przykład dla uzyskania cross-trimming). D/R i expo (wpisy na ekranie DRĄŻKÓW dla tego kanału) są używane. Odznaczenie tego pola oznaczałoby, że mikser otrzymuje surowe ustawienie drążka nawet kiedy D/R jest aktywne.
  * Różnicowość jest ustawiona na 0, więc wyjście miksera będzie symetryczne po obu stronach. Wartość 20% oznaczałaby, że wyjście linii byłoby o 20% mniejsze po ujemnej stronie niż po dodatniej. Pole "Diff" jest edytowalne i używając na nim klawiszy +/- będziesz mógł wybrać krzywą (predefiniowaną lub własną) zamiast zwykłej wartości liczbowej.
  * Linia miksera jest aktywna dla każdego trybu lotu. Usuwając zaznaczenie niektórych cyfr, dezaktywowałbyś tę linię dla odpowiedniego trybu lotu.
  * żaden przełącznik nie jest przypisany do tej linii, więc jest ona zawsze aktywna (tak długo jak ustawienia trybu lotu na to pozwalają). Wybór przełącznika (fizycznego lub logicznego) pozwoliłby aktywować linię gdy jest potrzebna.
  * Ostrzeżenie jest wyłączone. Jeśli to pole jest ustawione na 1,2 lub 3, krótkie piknięcia co kilka sekund dadzą Ci znać, że ta linia jest aktywna.
  * Multiplex jest ustawiony na "Add", więc wyjście tej linii jest dodawane do poprzednich w tym samym kanale. Jeśli ustawiony na "Multiply" to bieżąca linia miksera pomnoży **obliczony rezultat** innych linii powyżej. Jeśli ustawiony na "Replace" - zamień, to linia zastąpiłaby własnym wyjściem wszystko co stało się powyżej (jeśli jest aktywna).
  * Opóźnienia są zerowe, więc jeśli linia ma przypisany przełącznik, będzie aktywowana/dezaktywowana natychmiastowo gdy przełącznik jest przestawiany. Czas jest podany w sekundach.
  * Nie ma spowalniania, więc wyjście linii reaguje natychmiast na zmiany wejścia. Ustawiony tu czas, jest wyrażony w sekundach potrzebnych dla pokrycia całego zakresu zmian (-100 do +100). Jeśli wybrane są dwie sekundy, wyjście linii będzie potrzebować 0.5 sekundy aby stopniowo przesunąć się od 0 do +50 jeśli wejście zmieniło się tak znacznie lub linia miksera została uaktywniona przełącznikiem.
  * Możesz nazwać linię miksera. Ta nazwa jest pokazywana na głównym ekranie miksera, więc ustawianie nazw jest dobrym pomysłem, pomagającym w utrzymaniu skomplikowanych ustawień, w których możesz mieć wiele linii dla każdego kanału.

Pamiętaj, że w każdej chwili na ekranie miksera oraz okienek dialogowych EDIT/INSERT MIX możesz DŁUGO nacisnąć klawisz MENU aby wywołać monitor kanałów. Ułatwia to wypróbowywanie różnych parametrów i oglądanie ich wpływu na wyjścia kanałów. Dodatkowo, zobaczysz, że na ekranie miksera, każda aktywna linia ma swoją nazwę i wejście wyświetlone jako pogrubione, więc w każdej chwili jest jasne, które linie przyczyniają się do tworzenia sygnałów wyjściowych kanałów.

Opis jest długi, ale w praktyce, jeśli jeszcze raz zrobimy sterowanie CH2 z drążka steru wysokości, zajmie to tylko parę sekund aby wybrać CH2, nacisnąć DŁUGO ENTER, przewinąć do "Source" - źródło, nacisnąć ENTER, poruszyć drążkiem steru wysokości i dwukrotnie wcisnąć EXIT. Konfigurowanie miksera dla szerokiej gamy modeli jest właśnie takie proste. Dodajmy teraz coś, do podstawowych 4 kanałów. Jeśli masz model z klapami mającymi swoje własne serwo, które ma być sterowane przez SB, znajdź wolny kanał do podłączenia Twojego serwa (powiedzmy CH6), przewiń do CH6 na ekranie miksera, wstaw linię miksera, przełącz SB będąc w trybie edycji na polu źródła, a potem naciśnij EXIT dwa razy. Jeśli chcesz dodać pozycje góra/środek/dół, dobrym pomysłem byłoby ustawienie 3-punktowej własnej krzywej. W ustawieniach krzywej, wybierz c1, wyjdź z trybu edycji, pozostając na krzywej naciśnij MENU. Zostaniesz przeniesiony do edytora krzywych. Wybierz typ "3pt", wartość Y dla pierwszego punktu i dopasuj jego pozycję. Zrób to samo dla pozostałych dwóch punktów i wyjdź z edycji.

Teraz coś bardziej "skomplikowanego", jeśli Twój model posiada chowane podwozie, które chciałbyś sterować przełącznikiem SA (ma on 3 pozycje) ale chcesz tylko dwóch wartości wyjściowych (schowane, wypuszczone) nie będzie to działać (wybranie SA jako źródła dla linii miksera da -100%, 0%, +100%). Aby rozwiązać ten problem użyj bardzo wygodnego źródła MAX, które reprezentuje stałą wartość. Stwórz linię miksera w kanale (np. CH5) z MAX jako źródłem i wagą 100%, możesz nazwać ją "Gear Up" - koła w górze. Teraz stwórz drugą linię miksera pod pierwszą naciskając na niej DŁUGIE ENTER i wybierając "Insert After" - wstaw po. Znowu wybierz MAX jako źródło, wagę na -100%, dla której, warto zapamiętać poręczny skrót - wejdź w tryb edycji i jednocześnie naciśnij klawisze + i -. Jest -100%, przewiń do ustawienia "Multpx"i wybierz "Replace". Teraz idź do ustawień przełącznika, wejdź w tryb edycji przełącz SA w pozycję GÓRA (przestaw najpierw na inna pozycję, jeśli już jest ustawiony do góry), i naciśnij + i - razem. Zmieni to "SAup" w "!SAup". To oznacza, że linia jest aktywna gdy tylko SA NIE jest w górnej pozycji. Nazwij linie "Gear Down" - koła w dół i gotowe. Co się dzieje: CH5 będzie domyślnie na 100% (działa pierwsza linia miksera), ALE gdy SA jest w pozycji środkowej albo dolnej, uaktywnia się druga linia i zamienia pierwszą, przekręcając wyjście na -100%. Jeśli powrócisz do ekranu miksera i pobawisz się SA zobaczysz, że gdy nie jest on w górnej pozycji, druga linia zostaje wytłuszczona, gdyż staje się aktywna, zaś pierwsza wygasza się do normalnego stanu, gdyż zostaje dezaktywowana przez typ Replace drugiej linii. Znowu, wygląda to skomplikowanie, ale zajmuje nie więcej niż około 30 sekund gdy jesteś do tego przyzwyczajony.

Jeśli nadążałeś za naszym tokiem rozumowania, dokładnie zrozumiesz, że moglibyśmy ustawić drugą linię aby używała przełącznika "SAup",a role obydwu linii zostałyby zamienione (druga aktywna gdy przełącznik w górze, pierwsza w dwóch pozostałych pozycjach). Ale wtedy nie miałbym okazji aby wyjaśnić działanie "!". Ponadto, osobiście wolę aby domyślna była górna pozycja przełączników, a pierwsza linia miksera w kanale była wartością domyślną.

Następny prosty przykład: Masz dwie lotki, każda z osobnym serwem. Użycie kabla Y do ich połączenia nieco trąci myszką, więc użyjemy dwóch kanałów. Mamy już pierwszą lotkę na CH1, CH5 i 6 są wykorzystane dla podwozia i klap, więc wybierzmy CH7. Mamy drugą lotkę, która musi być poruszana drążkiem lotek, dokładnie tak jak pierwsza, więc po prostu skopiujmy mikser pierwszej lotki podświetlając go, naciskając DŁUGO ENTER i wybierając "copy" - skopiuj. Przesuńmy go do CH7 i potwierdźmy przy pomocy ENTER. Działałoby to świetnie, ale zgodnie z moimi osobistymi upodobaniami zmienimy wagę linii miksera na -100%, ponieważ logicznie druga lotka powinna wychylać się w odwrotną stronę niż pierwsza. Zobaczymy później, że ma to sens.

A teraz czas na nieskomplikowany mikser. Będę leniwy i powiem Ci abyś cofnął się do [opisu ekranu miksera](http://code.google.com/p/opentx/wiki/OpenTx_FrSky_PL#Mikser) i poczytał jeszcze raz o kompensacji gaz -> wysokość. Jestem pewien, że teraz wyda Ci się to dużo prostsze!

Zróbmy teraz mikser delta. Znowu, jaki mamy rodzaj powierzchni sterowych i co chcielibyśmy z nimi zrobić?

Mamy 2 sterolotki. Muszą poruszać się w tę sama stronę gdy poruszamy drążkiem wysokości, ale muszą poruszać się w przeciwne strony gdy poruszany jest drążek lotek.

Wybierzmy dwa kanały dla podłączenia naszych serw. CH3 i 7 - bo tak. Próbuję sprawić, że zapomnisz o starych przyzwyczajeniach do przypisanych na sztywno kanałów ;)

CH3 musi się poruszać zgodnie z drążkiem wysokości, więc stwórzmy linię miksera z "Ele" jako źródłem. CH3 musi się poruszać zgodnie z drążkiem lotek, więc stworzymy drugą linie miksera z "Ail" jako źródłem. "Mutplx" ustawiamy na "Add" gdyż jest to dokładnie to co chcemy zrobić - dwa wejścia muszą być do siebie dodane.

Podyskutujmy trochę o wagach. Są one teraz ustawione na 100%. Oznacza to,że pełne wychylenie drążka lotek, wymusi pełne wychylenie CH3, tak samo dla drążka wysokości. Ale teraz, jeśli je dodamy i przesuniemy drążek w prawy górny róg (zakładając Mode 2) mamy 100% + 100% = 200% sygnału wyjściowego na CH3. Limity ustawione na ekranie serw to 100% - co oznacza, że sygnał wyjściowy zostanie obcięty. Gdy wyjście miksera dla kanału wychodzi poza 100%, serwo nie może się dalej poruszać. Nie różni się to od innych aparatur - predefiniowane miksery delty zwykle dają możliwość ustawienia współczynników dla wychyleń wysokości i lotek - co jest dokładnie tym samym. Jeśli wprowadzisz zbyt duże współczynniki, ruchy drążka będą nieefektywne.

Dyskusja o ustawianiu współczynników może się ciągnąć bez końca - niektórzy są szczęśliwi z powodu 100% i obcinania, niektórzy lubią 50% bez obcinania, a niektórzy jak ja, lubią coś po środku - ja używam 70%.

Powiedzmy, że mamy teraz dwie linie na CH3, 70% Ail i 70% Ele. Jak mówiliśmy, CH7 musi odpowiadać w ten sam sposób na wysokość, więc dodajemy linię 70% Ele. Musi odpowiadać na drążek lotek tym samym ruchem, ale w przeciwna stronę, więc ustawmy... -70%.

To jest powód, dla którego ustawiłem -100% w poprzednim przykładzie programowania lotek. Moglibyśmy ustawić obie lotki na 100% a następnie odwrócić kierunek pracy serwa aby osiągnąć ten sam rezultat. ALE w scenariuszu z deltą to by nie zadziałało.

### Ekran serw ###

Mikser jest już skonfigurowany, zachowanie elementów sterujących zdefiniowane, następny krok to określenie sposobu w jaki rozkazy są wykonywane przez serwa. W tym momencie będziesz chciał podłączyć serwa do odbiornika, usuń dźwignie z serw, śmigła z silników (bezpieczeństwo przede wszystkim) i podłącz zasilanie odbiornika. Jeśli nie zrobiłeś tego wcześniej, zbinduj odbiornik.

Wycentruj wszystkie dźwignie (możesz patrzeć na monitor i celować w zero), zamontuj dźwignie serwa tak aby były jak najbardziej prostopadłe do popychaczy, którymi będą poruszać. Prawo Murphy-ego zapewnia, że jest to zawsze pomiędzy wypustami na osi serwa, więc skoryguj położenie dźwigni używając "PPM center adjustment" aby uzyskać perfekcyjną prostopadłość. Użycie tego parametru zamiast trymera serwa (subtrim) pozwala uniknąć utraty zakresu ruchu, i zapewnia, że wychylenia widoczne w monitorze kanałów wynikają ze sterowania. Połącz dźwignie, popychacze i cięgna tak, aby powierzchnie sterujące były w położeniu neutralnym (albo po środku oczekiwanych wychyleń np. dla klap).

<a href='Hidden comment: 
TODO: Clarify the chapter below and provide complete translation
Now move the radio"s controls carefully to exercise the servos but being aware of possible mechanical binding. Set servo reverse where needed. Adjust the linkages in order to have a little more throw than what you"ll ever need in both directions. If there is a little binding on one side to reach the appropriate side on the other and/or the throws are not symmetrical it"s not a problem.
'></a>

Teraz poruszaj ostrożnie drążkami aby poćwiczyć serwa, ale uważając na ograniczenia mechaniczne. Jeśli to konieczne, ustaw odwrócenie kierunku serw. Wyreguluj dźwignie i cięgna aby mieć w obu kierunkach nieco więcej wychyleń niż potrzebowałbyś. Jeśli serwo napotyka opór po jednej stronie i/lub wychylenia nie są całkiem symetryczne - nie jest to problemem.

Następnie wyreguluj limity (maksymalne i minimalne). Powinny być ustawione tak aby:
  * Mieć nieco większe wychylenia niż kiedykolwiek mógłbyś potrzebować
  * Nie było mechanicznego blokowania
  * Wychylenia były takie same po obu stronach, przy pełnych wychyleniach elementów sterujących.

Skończyliśmy z tym ekranem. Mam nadzieję, że nadałeś nazwy swoim kanałom ;)

### Ekran drążków ###

Prawdopodobnie zauważyłeś, że jest jedna rzecz, której jeszcze nie zrobiliśmy - ustawienia czułości drążków. Zrobimy to właśnie teraz.

Dla każdego drążka, stwórz linię definiującą czułość i ustaw współczynnik skalowania aby uzyskać pożądaną wieklośc wychyleń. Jest to domyślna czułość drążków, więc nie wybieraj przełącznika.

Jeśli potrzebujesz przełączanych ustawień czułości (dual rates - D/R), stwórz nową linię **przed** ta domyślną, wprowadź inny współczynnik skalowania/skalowanie wykładnicze (expo), wybierz przełącznik. Powtórz tyle razy ile potrzebujesz. Co jest istotne - **pierwsza linia** której przełącznik jest włączony (zaczynając od góry) będzie aktywną. Jeśli stworzysz linię ustawień czułości poniżej linii bez przełącznika - nigdy nie będzie użyta. Jeśli wybierasz kombinację przełączników, która może spowodować, że przełączniki dwóch linii będą włączone - myśl o priorytetach - ta która jest najwyżej zastąpi pozostałe. Idealnie byłoby gdybyś tak wybrał swoje przełączniki aby to się nigdy nie zdarzyło.

Teraz możemy iść polatać!

## Wskazówki programowania modeli ##

Czas na małe podsumowanie. Jak widzieliśmy, liczba możliwości realizacji tej samej rzeczy jest dosłownie - nieskończona. Wspomnijmy więc o kilku dobrych nawykach przy konfigurowaniu modelu. Jeśli będziesz się ich trzymał, pomogą Ci ustawić Twój model szybciej, utrzymać przejrzystość ustawień i zrozumieć to co zrobiłeś, nawet 6 miesięcy później. W przypadku prostego 4-kanałowego modelu gdzie każde serwo jest sterowane jednym wejściem sterującym, jeśli chcesz zmniejszyć wychylenia lotek, możesz zrobić to zarówno przez D/R drążka lotek, poprzez zmianę wagi linii miksera łączącego drążek lotek z kanałem lotek, a także zmieniając limity dla tego kanału. Dla tak prostego modelu nie ma znaczenia gdzie to zrobisz, ale gdy tylko zajmiesz się bardziej skomplikowanymi modelami z klapolotkami, mikserem motylka itd., zrobienie tego na przykład w limitach, uczyni niemożliwym poprawne skonfigurowanie modelu.

  * Zacznij od ustawienia miksera. Tak jak zrobiliśmy powyżej, myśl o tym jakie stery masz w modelu i co powinny one robić, wybierz który kanał odbiornika chcesz użyć dla każdego z nich. W każdym z tych kanałów stwórz jedną linię miksera dla każdego elementu sterującego w radiu, który ma na niego działać. Zdecyduj do jakiego względnego zakres ruchu każdy z nich ma doprowadzić, przyjmując 100% jako bazę. Zapomnij na razie o wychyleniach, jeśli jeden element sterujący ma powodować połowę ruchu, który powoduje inny regulator, ustaw jeden na 100%, drugi na 50%. Dbaj oto aby mikser był przeznaczony tylko do "logiki" ustawień. Jeśli na przykład w skomplikowanym szybowcu masz więcej niż jedną powierzchnię sterową, która powinna otrzymać tę samą grupę mikserów, wyizoluj je jako "funkcję" na wolnym "wirtualnym" kanale, którego wiesz, że nie będziesz używał do serw np. CH10. Następnie odwołuj się do niego w wymaganych kanałach wyjściowych przy pomocy linii miksera 100% CH10. Zaoszczędzi to linii miksera i przyczyni się do przejrzystości ustawień. Nazwij Twoje kanały i miksery, które wymagają wyjaśnień.
  * Ustaw parametry serw. Zatroszcz się o regulacje mechaniczne modelu, im lepiej są zrobione, tym łatwiej skonfigurować radio i tym precyzyjniejsze będzie sterowanie. Jeśli potrzebujesz użyć trymerów serw aby sztucznie przesunąć dźwignie (na przykład w przypadku klapolotek, które potrzebują znacznie większych wychyleń po dolnej stronie niż po górnej), pamiętaj o użyciu trybu wyjścia "=" aby zachować symetrię.
  * Zawsze ustawiaj rozmiary wychyleń używając ekranu drążków.

Wychylenia są ustawione, mikser realizuje logikę, a wyjścia odpowiadają mechanicznym parametrom modelu. Każda cześć ustawień jest przejrzyście oddzielona, jeśli będziesz coś musiał zmienić, dowolna korekta będzie wymagała interwencji tylko na jednym z ekranów. Jeśli się rozbijesz lub zmienisz coś mechanicznie, będzie to ekran serw. Jeśli wychylenia są zbyt duże - ekran drążków. Jeśli rozmiar kompensacji lub współczynnik miksowania jest zły - ekran miksera.

Pamiętaj, że istnieją przełączniki logiczne, które mogą być wykorzystane do łączenia rozmaitych funkcji, mogą na przykład dopuścić aktywację pewnych mikserów tylko jeśli inny mikser jest aktywny itd.

Dobrą praktyką jest zrobienie użytku z funkcji "Safety CHx" do zdefiniowania przełącznika bezpieczeństwa dla kanału gazu dla modeli elektrycznych. Wybierz przełącznik zabezpieczający dla gazu, wybierz właściwą funkcję dla kanału gazu, ustaw wartość na -100, następnie zaznacz checkbox. Powinieneś zawsze konfigurować model gdy jest pozbawiony zasilania albo co najmniej bez zamontowanego śmigła, ale zabezpieczający checkbox jest tutaj po to aby uniknąć wymuszenia w kanale domyślnej wartości 0 (średni gaz) podczas przeglądania listy funkcji jeśli, przypadkiem, przełącznik aktywujący jest włączony.

Funkcja "Instant trim" - szybkie trymowanie pozwala dodać aktualne pozycje drążków do ich odpowiednich trymerów. Jest to użyteczne, na przykład w nowym modelu który może być bardzo źle wytrymowany. Zamiast być zmuszonym do naciskania i przytrzymywania trymerów aż do uzyskania właściwego efektu, po prostu przytrzymaj drążki tak aby uzyskać prosty lot i trzaśnij przełącznik funkcji "Instant trim" (powinien to być ten chwilowy). Ta funkcja specjalna powinna być zablokowana jak tylko model zostanie wytrymowany gdyż włączenie jej przez pomyłkę może mieć efekt odwrotny do zamierzonego.

Jak tylko skończysz latać, możesz użyć opcji "Trims -> Offsets", na dole ekranu serw, do przeniesienia zawartości trymerów drążków do ustawień trymerów serw (subtrim). Bądź jednak świadomy, że jeśli tryb pracy serwa nie jest ustawiony na "=", zbyt duża wartość trymera serwa może prowadzić do niesymetrycznych wychyleń i wpływać na ustawienia takie jak różnicowość.

## Zaawansowana funkcjonalność ##

### Tryby lotu ###

Tryby lotu w openTx są relatywnie łatwe w porównaniu z większością aparatur. Ustawienia są proste: Nazwa (wyświetlana na głównych ekranach), przełącznik do aktywacji, ustawienia trymowania i dwa parametry płynnego włączania/wyłączania. Jednak są silnym narzędziem ponieważ główne ustawienia są po prostu zlokalizowane gdzie indziej: przy drążkach i mikserach. Każde z nich mają listę wyboru trybów lotu, która determinuje w jakich trybach są aktywne. Niemal wszystko jest robione poprzez dedykowane miksery. Miksery, które są kontrolowane przez tryb lotu są aktywowane/dezaktywowane płynnie zgodnie z ustawieniami trybu. Jako że trymy mogą być specyficzne dla trybów lotu (domyślnie - są), wykorzystanie trybów lotu do uaktywniania takich rzeczy jak podwozie czy klapy pozwala używać różnych zestawów trymów np. aby przeciwdziałać dodatkowemu oporowi, który często ma wpływ na pochylenie modelu.

### Szczegóły telemetrii ###

Dalej zakładamy, że Twoje radio ma załadowana kartę microSD i prawidłowy pakiet głosów. Jeszcze raz - rekomendujemy użycie zdolności radia do odtwarzania głosu bo posiada ono zaawansowane możliwości ostrzegania głosem, zamienne piknięcia używane w przypadku braku pakietu głosowego mogą być trudne do zrozumienia w stresującej sytuacji.

Prawdopodobnie najważniejszą wartością, której dostarcza telemetria jest RSSI. Wskazuje ona jak silny sygnał nadajnika dociera do odbiornika i ostrzeże Cię z wyprzedzeniem gdy grozi Ci ryzyko utraty kontroli nad modelem. Może się to zdarzyć z powodu zewnętrznych zakłóceń, dużej odległości, źle ustawionych lub uszkodzonych anten itd.
Strona [ustawień telemetrii](http://code.google.com/p/opentx/wiki/OpenTx_FrSky_PL#Telemetria) oferuje Ci ustawienie dwóch poziomów alarmów sygnalizowanych głosem ("RF signal low" - niski poziom sygnału i "RF signal critical" - krytyczny poziom sygnału). Są one domyślnie ustawione na poziomach, które są uważane za odpowiednie i bezpieczne dla normalnych lotów w zasięgu wzroku (45 i 42), ale jeśli chcesz je własnoręcznie skorygować, mogą Ci się przydać następujące wyjaśnienia:

RSSI na urządzeniach FrSky jest przedstawiane w skali logarytmicznej (db), nie w procentach. To oznacza, że gdy RSSI jest wysokie, mała różnica w odległości pomiędzy nadajnikiem i odbiornikiem będzie prowadziła do dużej zmiany wartości RSSI. To jest zupełnie normalne aby widzieć wartość około 100 gdy jest się tuż obok modelu, która szybko spada do około 70 gdy tylko przespacerujesz się na drugi koniec pola lotów. Kiedy odczyt jest w okolicach 50, potrzeba dużego dodatkowego dystansu aby osiągnąć poziom alarmowy: 45. Podstawowa zasada jest taka, że podwojenie dystansu między pilotem i modelem powoduje spadek RSSI o 6dB co powinno wyjaśniać poprzednie spostrzeżenia. Jeśli jesteś w odległości 5m od modelu, potrzeba jedynie następnych 5m aby RSSI spadło o 6dB, ale jeśli jesteś w odległości 600m od modelu, potrzeba kolejnych 600m aby zredukować wartość RSSI o "te same" 6dB.

Utrata kontroli nastąpi gdy RSSI osiągnie wartość około 38, więc ustawienie alarmu przy 10 jest bezużyteczne. Z powyższych wyjaśnień, możesz zrozumieć, że pomiędzy domyślnym alarmem krytycznym (42) i typową utratą kontroli mamy margines około 4dB, lub stosunek odległości około 1.5. Alarmy są więc raczej konserwatywne, w normalnych warunkach, nawet jeśli usłyszałeś alarm krytyczny, byłbyś wciąż daleko od utraty kontroli (powinieneś być w odległości około 1000m lub więcej, mając w zapasie kolejne 500m). Okresowe utraty sygnału z powodu lokalnych zaników i niezgodności położenia anten mogą jednak zdarzać się coraz częściej i częściej.

Jak wspomniano, domyślne alarmy są uważane za bezpieczne dla zwykłych lotów w zasięgu wzroku, ale na przykład z wyposażeniem FPV, zwłaszcza gdy jest ono połączone z systemami automatycznego powrotu do punktu startu i odpowiednio skonfigurowanym failsafe, margines bezpieczeństwa może zostać zmniejszony i możesz uzyskać mniej więcej podwojenie standardowego zasięgu systemu. Od Ciebie zależą (bezpieczne!) eksperymenty gdyż w sytuacji zredukowanego marginesu bezpieczeństwa, wpływ zewnętrznych źródeł zakłóceń staje się bardziej zauważalny więc przewidzenie zachowania danej instalacji w konkretnym modelu jest niemożliwe.

Taranis, posiada także alarm, który ostrzeże Cię o utracie połączenia telemetrycznego oraz jego przywróceniu. Link telemetryczny zachowuje się podobnie do linku zdalnego sterowania, jest nadawany z tą samą mocą, więc powinien mieć w gruncie rzeczy taki sam zasięg, a konserwatywne alarmy linku zdalnego sterowania opisane powyżej powinny zapewnić, że połączenie telemetryczne jest zawsze dostępne. Jednak jest możliwe że z nieznanej przyczyny (tolerancje produkcyjne, których rezultatem jest nieco inny zasięg linku w górę i w dół, lokalne zakłócenia w pobliżu aparatury,...) link telemetryczny zerwie się przedwcześnie, w takim przypadku ostrzeżenie o braku telemetrii jest istotne, gdyż musisz wiedzieć, że alarmy oparte na danych z telemetrii NIE będą się pojawiać. Oczywiście, jeśli radio nie może pobierać informacji o RSSI z odbiornika, nie może ostrzec Cię o niskim RSSI. Podobnie, jeśli np. opierasz się na informacji z pokładowego czujnika napięcia lub prądu aby wiedzieć kiedy lądować, alarmy które ustawiłeś nie pojawią się jeśli dane telemetryczne są niedostępne. Zdawaj sobie sprawę z ważności ostrzeżenia dźwiękowego "Telemetry lost" - utrata telemetrii i reaguj prawidłowo, czy to przestawiając się na inne źródło informacji lub wracaj i kieruj się do lądowania i zbadaj przyczynę utraty dostarczania telemetrii.

Zauważ, że kiedy aparatura i odbiornik są bardzo blisko jedno drugiego (zwykle mniej niż 1m) możesz otrzymać fałszywe alarmy "telemetry lost" - utrata telemetrii i "telemetry recovered" - powrót telemetrii. To nie jest usterka i efekt ustąpi gdy urządzenia zostaną od siebie oddalone.

Reszta tematów dotyczących telemetrii była już wcześniej poruszona. Strona ustawień telemetrii pozwala Ci konfigurować rozmaite parametry, które zostały wyjaśnione przy przeglądzie menu. Ekrany telemetrii pokazują dane zgodnie z konfiguracją. Jeśli masz w swojej aparaturze kartę microSD, możesz użyć funkcji specjalnej "SD Logs" aby zapisywać dane telemetryczne podczas lotu. Mogą one być później odtworzone w companion9x lub obrabiane w arkuszu kalkulacyjnym.

### Dźwięki ###

Jedną z ważniejszych funkcji radia są komunikaty głosowe. Przy założeniu, że karta microSD zawierająca zestaw dźwięków (możliwych do pobrania z wewnątrz companion9x) znajduje się w gnieździe w komorze baterii, radio będzie w stanie odtwarzać pliki dźwiękowe w odpowiedzi na rozmaite zdarzenia jak osiągnięcie punktu centralnego/końcowego trymera, przełączenie przełącznika (fizycznego albo logicznego) aktywującego odtwarzanie tła muzycznego, i ostatnie, ale nie najmniej ważne, będzie możliwe komunikowanie dowolnej wartości (telemetria, parametr, pozycja drążka) czystym głosem. Własne dźwięki mogą być umieszczane na karcie SD w folderze SOUNDS/language. Język jest wybierany w ogólnych ustawieniach radia i może być zmieniany w locie tak długo jak pakiet dźwiękowy dla tego języka jest załadowany na kartę.

Pliki ZIP ze standardowymi pakietami głosów można pobrać z wewnątrz companion9x, lub [tutaj](http://85.18.253.250/voices/opentx-taranis/). Rozpakuj plik ZIP do głównego katalogu karty, spowoduje to utworzenie potrzebnych podkatalogów (np. SOUNDS/en dla angielskiego pakietu).

Jeśli życzysz sobie stworzyć własne pliki, wymagany format to:
  * WAV, 8 lub 16 bitów, Mono
  * prędkość próbkowania 8, 16 lub 32kHz
  * PCM lub skompresowane u-law albo a-law
Dźwięki z wyżej wymienionych zasobów są zrealizowane w najlepszej jakości tzn. 16bit, 32kHz, PCM.

Operowanie dźwiękami jest stosunkowo łatwe, składa się tylko z pięciu (i pół) funkcji specjalnych:
  * Play Track: Po prostu odtwórz plik audio z karty SD gdy powiązany przełącznik jest aktywny. Jest tu dostępna opcja "Repeat" (powtórz), gdy jest ustawiona dźwięk będzie powtarzany tak długo jak przełącznik jest aktywny. Ta funkcja może być używana do ogłaszania trybów lotu, pozycji podwozia, klap itd. gdy powiązany z nimi przełącznik jest przełączany.
  * Play Value: Mówi wartość wybranego parametru gdy przełącznik jest aktywny. Parametr "Repeat" jest również dostępny.
  * BgMusic: Rozpoczyna odtwarzanie tła muzycznego (może to oczywiście być plan czasowy lotu). Przełącznik musi pozostawać włączony aby odtwarzanie trwało.
  * BgMusic ||: Zawiesza odtwarzanie tła muzycznego jeśli trwało i wznawia odtwarzanie gdy funkcja staje się nieaktywna. Przycisk funkcji BgMusic musi pozostawać aktywny przez cały czas inaczej ścieżka dźwiękowa będzie odtwarzana od początku.
  * Vario: Odtwarza dźwięk szybowcowego wariometru na podstawie wysokości lub prędkości pionowej przesłanej telemetrią.
  * Volume: Reguluje ogólną głośność dźwięku według wartości wejścia np. potencjometru.

Następujący przykład pokazuje użycie kilku funkcji specjalnych do ogłaszania bieżących informacji o aktywowanych przełącznikach, a ponadto odtwarzanie wartości timera nr 2, a następnie zużycia prądu (liczba mAh uzyskana z pokładowego czujnika prądu FrSky FAS-100) wyzwalane przełącznikiem SHdown.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/28_audioCFs.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/28_audioCFs.png)

Dodatkowo, oprócz dźwięków odtwarzanych przez funkcje specjalne, są pewne predefiniowane dźwięki, które będą automatycznie odtwarzane, gdy wystąpi zdarzenie, a odpowiednio nazwany plik jest umieszczony we właściwym folderze.

Aktualnie, są obsługiwane następujące zdarzenia:

  * Zmiana trybu lotu:
    * Gdy tryb lotu jest aktywowany, plik /SOUNDS/(lang)/modelname/flightmodename-ON.wav jest odtwarzany, jeśli jest obecny.
    * Gdy tryb lotu jest dezaktywowany, plik /SOUNDS/(lang)/modelname/flightmodename-OFF.wav jest odtwarzany, jeśli jest obecny.

Nazwy folderów "modelname" (nazwa modelu) i "flightmodename" (nazwa trybu lotu) muszą być dokładnie takie same (z dokładnością do wielkości liter) jak, odpowiednio, nazwa Twojego modelu i nazwa trybu lotu. Spacje należy zastąpić przez znak podkreślenia. Oczywiście tylko pliki, które umieścisz na karcie będą odtwarzane. Jeśli informowanie, o którymś zdarzeniu Cię nie interesuje, po prostu nie wstawiaj pliku dla niego.


### Korzystanie ze zmiennych globalnych ###

Już wspominaliśmy, w jaki sposób zmienne globalne mogą być używane do grupowania wielu ustawień w jednym miejscu oraz do sprawienia aby ustawienia były uzależnione od trybów lotu. Było również powiedziane, że zmienne globalne mogą być korygowane w czasie lotu - jest to osiągalne za pośrednictwem funkcji specjalnych AdjustGVx. Za każdym razem gdy przełącznik funkcji jest włączany, wartość zmiennej globalnej podąża za wybranym wejściem. Dla przypomnienia, są 4 grupy wejść przełączane przez DŁUGIE naciśnięcie ENTER na polu wprowadzania wartości. Nie zapomnij zaznaczyć checkboxa zabezpieczającego gdy skończyłeś konfigurację i upewniłeś się, że przełącznik jest wyłączony. To zabezpieczenie jest po to aby uniknąć nadpisania Twojej zmiennej przez pomyłkę podczas przewijania listy wejść.

Jest to sposób na korygowanie wartości w locie. Przełącznik funkcji specjalnej pełni funkcję "blokady" zamrażającej wartość lub zezwalającej na korekcję. Gdy zmienna jest aktualizowana, okienko z nazwą zmiennej i nową jej wartością pojawia się na głównych ekranach.

Jednym ze źródeł dostępnych dla korekcji zmiennych globalnych jest lista kanałów. Jest to prawdopodobnie podstawowy sposób, którego będziesz używał do korekcji zmiennych globalnych - z prostego powodu: powiedzmy, że chcesz skorygować współczynnik D/R przy pomocy potencjometru S1. Jeśli wybierzesz GV1 jako parametr wagi linii konfiguracji D/R i po prostu użyjesz  funkcji specjalnej Adjust GV1 z S1 jako źródłem, będziesz korygował Twoje D/R w zakresie pomiędzy -100% i 100%. Możliwość zablokowania albo nawet odwrócenia działania drążków nie brzmi strasznie fajnie, więc pewnie będziesz chciał ograniczyć zakres zmian. Najłatwiejszym sposobem jest użycie w tym celu wolnego kanału. Stwórz linię w mikserze dla, powiedzmy, CH12, i użyj parametru weight/offset/curve (waga/przesunięcie/krzywa) aby sprawić, że sygnał wyjściowy kanału pokryje zakres, powiedzmy, +50 do +80% dla całego zakresu pracy potencjometru. Następnie ustaw źródło korekcji zmiennej (Adjust GV1) na kanał 12.


### Kilka przykładów współdziałania ###

Cała moc systemu pochodzi od kombinacji różnych jego właściwości. Przełączniki logiczne mogą być używane do tworzenia warunków, które uruchomią odtwarzanie dźwięków, na przykład użycie przełącznika logicznego "CS1|d|≥x Alt 16" jako wyzwalacza do "Play Value Alt" spowoduje głośne odczytywanie wysokości za każdym razem gdy zmieni się ona o 16m. "CS2 a<x Spd 35" wyzwalający "Play Track lowspd" odtworzy plik "lowspd.wav" z karty SD (w którym można zapisać dźwięk "Mała prędkość") gdy odczytana z GPS prędkość spadnie poniżej 35km/h. Jeśli chciałbyś aby więcej parametrów było kolejno odczytywanych na żądanie, możesz ustawić kilka funkcji specjalnych "Play Value", wszystkie wyzwalane przez przełącznik chwilowy (SHdown) tak jak opisano powyżej. Naciśnięcie przełącznika wyzwoli odtwarzanie wszystkich parametrów jeden po drugim.

Ale jak wiemy, przełączniki logiczne mogą być używane wszędzie tam gdzie można definiować użycie przełączników, nic nie stoi na przeszkodzie aby użyć tego samego CS2 do wyzwolenia automatycznego opuszczenia klap gdy tylko prędkość spadnie poniżej 35km/h. Tak, tak, wszystko może być użyte do wpływania na cokolwiek.

## Wprowadzenie do companion9x ##

Jak krótko wspominaliśmy, do openTx dołączony jest jego komputerowy odpowiednik, który pracuje pod Windows, Mac OS i Linux, [companion9x](http://code.google.com/p/companion9x/).

To oprogramowanie pozwoli Ci tworzyć kopie, edytować i udostępniać ustawienia Twojego radia. Może ono również symulować ustawienia modelu oraz interfejs aparatury na komputerze, więc jest to świetne narzędzie do eksperymentowania nawet bez użycia radia. Jeśli masz radio, companion9x przyspiesza ustawianie nowych modeli dzięki temu, że interfejs PC nie jest ograniczony do małego ekranu i tylko kilku przycisków.

### Podstawowe pojęcia ###

Companion9x wykonuje dwa zadania:
  * Zarządzanie ustawieniami radia i modeli
  * Pobieranie nowego oprogramowania dla radia i przesyłanie go do aparatury.

Jest istotna rzeczą aby zrozumieć w jaki sposób różne rzeczy są zapisywane w radiu. Będziemy często mówić o dwóch rodzajach pamięci: Flash i EEPROM.
  * Flash jest pamięcią gdzie znajduje się oprogramowanie radia - "system operacyjny". "Flashowanie radia" oznacza zmianę oprogramowania systemowego, którą będziesz zazwyczaj robił w celu aktualizacji do nowej wersji bądź w celu zmiany języka. Modele i ustawienia nie są dotykane podczas flashowania oprogramowania systemowego. W Taranisie, flashowanie odbywa się przy **WYŁĄCZONEJ** aparaturze. Więc, aby to robić, wyłącz radio, następnie podłącz je do portu USB komputera.
  * EEPROM jest oddzielną pamięcią ustawień/modeli. Odczytywanie jej pozwala na tworzenie kopii bezpieczeństwa i edycję ustawień w companion9x, zapisywanie wysyła rezultat edycji z powrotem do radia. Na Taranisie robi się to przy **WŁĄCZONYM** radiu. Włącz aparaturę, usuń wszystkie ostrzeżenia aby dostać się do głównego ekranu, następnie podłącz kabel USB. W komputerze zobaczysz dwa napędy dysków, jeden jest kartą SD, drugi jest wirtualnym dyskiem pamięci EEPROM.

W związku z obsługą dwóch rodzajów pamięci, companion9x będzie obsługiwał dwa różne rodzaje plików. Pierwszy to pliki firmware (oprogramowania systemowego), które można pobrać z poziomu okna dialogowego "Preferences", nie są one edytowalne, mogą tylko być przesyłane z/do radia. Drugi rodzaj, to pliki EEPROM, dla których companion9x dostarcza edytor, który pozwala zmieniać wszystko w taki sam sposób jak można to robić w samej aparaturze.

Podczas tworzenia (File->New) lub otwierania (zarówno przez przeciągnięcie na główne okno jak i przez polecenie menu File->Open) pliku EEPROM, pojawi się okno dokumentu. Kilka takich okien może być otwartych jednocześnie, pozwalając na kopiowanie modeli lub ustawień między plikami. Próba otwarcia pliku firmware w ten sam sposób powoduje wyświetlenie błędu mówiącego, że plik jest niepoprawny - to nie oznacza, że firmware jest niepoprawny, tylko to że nie jest to plik z ustawieniami.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/document.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/document.png)

Okno dokumentu składa się z wpisu "General Settings" - ogólne ustawienia, na którym możesz kliknąć podwójnie aby dostać się do ustawień radia oraz wielu wpisów dla modeli (60 dla Tarnisa). Model, którego nazwa jest wyświetlana jako **pogrubiona** jest aktualnie wybranym w aparaturze. Może być on wybrany w companion9x przez kliknięcie prawym klawiszem na nazwę modelu i wybranie "Use as default" - użyj jako domyślny. Podwójne kliknięcie na nazwę modelu otworzy edytor dla tego modelu, tworząc nowy gdy nazwa była pusta.

Operacje na pamięci radia są obsługiwane przez różne opcje menu "Burn" - wypalanie:

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/read_write.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/read_write.png)

  * Read EEPROM from TX - odczyta zawartość pamięci EEPROM z radia i otworzy ją jako nowy dokument w companion9x. Dokument jest otwierany w celu edycji, ale nie jest automatycznie zapisywany na dysk.
  * Write EEPROM to TX - wysyła obecnie otwarty i wybrany dokument (jeśli masz otwarty więcej niż jedn, kliknij najpierw na tym, który chcesz przesłać aby go wybrać) do radia.
  * Read EEPROM memory to File - odczyta zawartość pamięci EEPROM z radia i zapisze w pliku. Jest to preferowany sposób tworzenia kopii zapasowej ustawień radia gdyż ustawienia są zapisywane dokładnie takie jak są, bez żadnej ingerencji companion9x. Wybierz opcję, wybierz lokalizację oraz nazwę pliku i zapisz.
  * Write EEPROM memory from File - pozwala wybrać plik i prześle jego zawartość do radia. Jest to preferowany sposób odtworzenia zapisanego stanu radia, bez przetwarzania przez comapnion9x.
  * Write Flash memory - zamieni oprogramowanie systemowe radia korzystając z oprogramowania z wybranego pliku. Gdy tylko wybierzesz plik, masz możliwość zastąpienia ekranu powitalnego przez obrazek, który wskażesz lub przez domyślny obrazek wskazany w preferencjach companion9x.
  * Read Flash memory - zapisze kopię oprogramowania systemowego załadowanego do radia we wskazanym pliku.

### Konfiguracja companion9x dla Taranisa ###

Pierwszą rzeczą jest oczywiście pobranie i zainstalowanie odpowiedniej, dla Twojego systemu operacyjnego,  wersji companion9x z [tej strony](http://code.google.com/p/companion9x/downloads/list). Gdy program zostanie uruchomiony, zobaczysz główne okno. Otwórz okienko dialogowe preferencji przy pomocy File->Preferences.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/28_c9x_prefs.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/28_c9x_prefs.png)

Jest tam całkiem sporo opcji:
  * Wersja językowa oprogramowania
  * Wybór czy automatycznie sprawdzać, przy uruchomieniu programu czy istnieją nowe wersje openTx i companion9x
  * Wybór czy wyświetlać ekran powitalny przy uruchamianiu companion9x
  * Opcje symulatora: Czy pamiętać pozycje przełączników pomiędzy sesjami (użyteczne gdy zamykasz symulator aby poprawić konfigurację i znowu uruchamiasz), kolor podświetlenia, lokalizacja plików ze zrzutami ekranu symulowanego nadajnika
  * Ustawienia zamiany ekranu powitalnego nadajnika. Pobrane oprogramowanie openTx zawiera standardowy ekran powitalny - logo openTx, wielu użytkowników chciałoby go zmienić na swój. W tym celu możesz wskazać folder, w którym przechowujesz swoje własne ekrany powitalne i wybrać domyślnie używany z pliku lub biblioteki companion9x (w bibliotece jeszcze nie ma pasujących do rozmiaru ekranu Taranisa). Ekran powitalny dla Taranisa musi mieć rozmiary 212x64 piksele oraz do 16 poziomów szarości. Będziesz mógł wybrać ekran powitalny przed flashowaniem nadajnika.
  * folder dla kopii zapasowych pamięci EEPROM - nie używany dla Taranisa.
  * Rodzaj oprogramowania, język i opcje: tutaj możesz wybrać jakie oprogramowanie i radio będziesz używał z companion9x. Jest ważne aby te ustawienia zawsze zgadzały się z rodzajem oprogramowania oraz opcjami, które aktualnie są zainstalowane w aparaturze. Dla Taranisa wybór został celowo ograniczony więc większość funkcjonalności jest domyślnie dostępna. Kilka opcji do osobistego wyboru pozostało:
    * noheli: Usuwa stronę menu: Heli CCPM mixer
    * notemplates: Usuwa menu Templates
    * nogvars: Usuwa funkcjonalność zmiennych globalnych i powiązane menu.
    * ppmus: Włącza wyświetlanie wartości kanałów w mikrosekundach zamiast %.
  * SD structure path: opcja dla Taranisa i płyty sky9x, pozwala wybrać folder na Twoim dysku gdzie utworzyłeś kopie tego co znajduje się na karcie SD w radiu. companion9x może użyć, przy wybieraniu obrazów lub dźwięków dokładnie tych samych plików, które są widoczne dla aparatury.
  * Automatically add version number to firmware files: Kiedy pobierany jest plik z oprogramowaniem, jego nazwa zawiera wybrane opcje. Jeśli zaznaczysz ten checkbox, numer wersji także zostanie dodany do nazwy. Ułatwia to przechowywanie plików z różnymi wersjami.
  * Default Stick mode and channel order: Domyślny tryb drążków i kolejność kanałów. Są wykorzystywane gdy w companion9x jest tworzony nowy dokument (EEPROM).
  * Profiles: Pozwala na pamiętanie różnych zestawów ustawień i łatwe przełączanie się między nimi. Na przykład, jeśli masz dwie różne aparatury z różnym oprogramowaniem, to konieczność ponownego wpisywania wszystkich ustawień (wybór oprogramowania, zaznaczanie opcji,...) za każdym razem, kiedy chcesz wykonywać operacje na innym radiu byłaby bardzo niewygodna. Możesz skonfigurować wszystkie ustawienia, wybrać pusty profil, nadać mu nazwę identyfikująca konkretne radio i kliknąć "save". Zrób to samo dla drugiego radia. Będziesz teraz mógł wybrać odpowiedni profil dla radia, z którym chcesz pracować przy pomocy klawisza wyboru profili oraz opcji głównego menu companion9x. Pamiętaj, że profile mogą także pamiętać oraz odtwarzać kalibracje drążków i ustawienia sprzętu (napięcia, alarmy, tryby dźwięku,...) ze strony ustawień ogólnych otwartego dokumentu. Pozwala to kopiować dokument z jednego do drugiego radia bez potrzeby ponownej kalibracji lub ponownego wprowadzenia ustawień sprzętu.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/profile_chooser.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/profile_chooser.png)

  * Joystick: Ta opcja pozwala na skonfigurowanie joysticka dla symulacji drążków radia w symulatorze.

Dla aparatury Taranis, pierwszą rzeczą do zrobienia jest wybranie "openTx for FrSky Taranis" w liście wyboru oprogramowania. Wybierz wersję językową i język głosu. Górny przycisk "Download" otworzy przeglądarkę i załaduje ostatnią dostępną wersję oprogramowania (zgodnie z wybranym językiem i opcjami). Dolny przycisk "Download" otworzy przeglądarkę internetową na stronie pokazującej wybór pakietów głosowych dostępnych dla wybranego języka.

Ustaw Mode i preferowaną kolejność kanałów w listach poniżej, kliknij OK w okienku dialogowym preferencji.

### Symulator radia ###

Możesz teraz stworzyć nowy dokument. Pojawi się okno, jego pierwsza linia daje dostęp do ustawień ogólnych radia, następne odpowiadają kolejnym modelom. Możesz zajrzeć do ustawień, a klikając na pustej linii utworzysz nowy model.

Są dwa sposoby symulacji modelu albo całego radia.
  * W edytorze modeli, dolny przycisk "Simulate" otworzy symulator modelu z aktualnymi ustawieniami. Pamiętaj, jeśli zostanie zrobiona zmiana w modelu w czasie gdy symulator jest otwarty, musi on zostać zamknięty i otwarty ponownie.
  * U dołu okna "document" znajduje się przycisk "Simulate Tx", który otwiera podobny symulator, ale z dodatkową zakładką pokazującą ekran LCD i przyciski radia. Wirtualne radio zawiera te same dane jak dokument w momencie uruchomienia symulatora. Pamiętaj, że zmiany dokonane poprzez interfejs radia nie przenoszą się do dokumentu.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/29_c9x_sim.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/29_c9x_sim.png)

### Flashowanie Twojego Taranisa ###

Jak wspomniano wcześniej, oprogramowanie Twojego radia może być zmieniane, czy to z powodu zmiany wersji językowej czy w celu korzystania z nowych funkcji i poprawek.

Pierwsza rzecz, którą trzeba zrobić jest wyłączenie radia i podłączenie do portu USB komputera.

#### Instalacja drivera (tylko dla Windows) ####

Jest to wymagane tylko wtedy, gdy po raz pierwszy flashujesz Twoje radio na tym komputerze . Jeśli było to już wcześniej robione, omiń ten rozdział.

  * Pobierz program Zadig dla Twojego systemu operacyjnego: [Windows XP](https://companion9x.googlecode.com/files/zadig_xp.exe) albo [Windows Vista i nowsze](https://companion9x.googlecode.com/files/zadig.exe).
  * Uruchom go jako administrator (kliknij prawym klawiszem i wybierz stosowną opcję).
  * W "dużej" liście znajdź i wybierz: "STM32 BOOTLOADER". Kliknij przycisk "Install Driver".

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/zadig.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/zadig.png)

  * Jeśli w liście nie ma takiej pozycji, wybierz Options -> List All Devices, i teraz poszukiwana pozycja powinna się pojawić na liście. Wybierz ją i kliknij przycisk "Replace Driver".

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/zadig_replace.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/zadig_replace.png)

Zadig zainstaluje driver i powinien poinformować o sukcesie. Kiedy to się stanie, potwierdź komunikat i zamknij program.

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/zadig_success.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/zadig_success.png)

Jeśli żadna z tych opcji nie działa, możesz pobrać driver [tutaj](https://code.google.com/p/companion9x/downloads/detail?name=Taranis_WinUSB_driver.zip) i zainstaluj ręcznie (instrukcja dostępna na stronie pobierania).

Gdy driver jest poprawnie zainstalowany, w device managerze powinieneś zobaczyć to:

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/devman.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/devman.png)

#### Instalowanie programu flashującego (dla Mac OS i Linux) ####

Pobierz i zainstaluj pakiet [dfu-util](https://code.google.com/p/companion9x/downloads/detail?name=dfu-util-0.7.mpkg) dla Mac OS X, albo [32-bitowy](https://code.google.com/p/companion9x/downloads/detail?name=dfu-util-0.7_0.7-1~precise_i386.deb) / [64-bitowy](https://code.google.com/p/companion9x/downloads/detail?name=dfu-util-0.7_0.7-1~precise_amd64.deb) pakiet dla Ubuntu 12.04 lub nowszych.

#### Pobieranie i flashowanie oprogramowania nadajnika ####

![https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/flash.png](https://opentx.googlecode.com/svn/wiki/images_openTx_FrSky_EN/flash.png)

  * W oknie preferencji companion9x upewnij się, że właściwe oprogramowanie nadajnika jest wybrane (openTx for FrSky Taranis) oraz czy opcje i wersja językowa odpowiadają Twoim preferencjom. Następnie naciśnij górny przycisk "Download" i wybierz lokalizację pliku. Spowoduje to zbudowanie i pobranie najnowszej dostępnej wersji openTx dla Taranisa.
  * Zamknij okno preferencji i wybierz komendę Burn -> Write Flash memory. Upewnij się, że aparatura jest wyłączona i jest połączona z komputerem.
  * Wybierz plik, który przed chwilą pobrałeś. Będzie automatycznie rozpoznany i zostanie wyświetlona jego wersja.
  * Jeśli życzysz sobie aby zamienić ekran powitalny radia, możesz załadować nowy z pliku lub wybrać z dostępnej biblioteki. Następnie kliknij "Substitute image in firmware".
  * Kliknij "Burn to TX".
  * Gdy pasek postępu przesunie się do końca i pokaże się informacja o poprawnym zakończeniu flashowania, możesz zamknać okienko i odłączyć radio :)
  * Jeśli zobaczysz komunikat o braku programu wykonywalnego dfu-util, otwórz ustawienia narzędzia do flashowania przy pomocy Burn -> Configure menu item. Poszukaj dfu-util, które powinno być tu:
    * Na Windows: W folderze z instalacją companion9x (domyślnie C:\Program Files\companion9x\dfu-util.exe na systemach 32-bitowych, albo C:\Program Files (x86)\companion9x\dfu-util.exe na systemach 64-bitowych).
    * Na Mac OS: /opt/local/bin/dfu-util.
