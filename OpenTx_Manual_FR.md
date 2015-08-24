<a href='Hidden comment: 
TODO:
* Bases de companion9x un peu plus élaborées, voire manuel séparé?
* Fonctions avancées / sky9x (carte SD, voix, logs)
* "wikifier" les différentes modifs hardware
* Liste des sources, éléments de télémétrie etc
'></a>
<a href='Hidden comment: Marche pas encore....
[http://opentx.googlecode.com/svn/wiki/gadgets/printwikis.html?_gnpi_subversion="svn"&_gnpi_wikilist="OpenTx_Manual_FR" Version imprimable]
'></a>

# openTx - Manuel d'utilisation #

![https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/9x_header.png](https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/9x_header.png)

Manuel écrit par Franck Aguerre sur la base d'openTx [r1568](https://code.google.com/p/opentx/source/detail?r=1568) / Nov. 2012

## Table des matières ##




## Avertissement ##

CE LOGICIEL EST FOURNI « TEL QUEL » SANS GARANTIE D'AUCUNE SORTE, EXPLICITE OU IMPLICITE, Y COMPRIS ET SANS LIMITATION, LES GARANTIES DE VALEUR MARCHANDE OU D'ADAPTATION À UN USAGE PARTICULIER. VOUS PORTEZ LA TOTALITÉ DU RISQUE DE QUALITÉ ET DE PERFORMANCE DU PROGRAMME. VOUS PRENEZ À VOTRE CHARGE LE COÛT DE TOUTE INTERVENTION, RÉPARATION OU CORRECTION AU CAS OÙ LE PROGRAMME S'AVÉRERAIT DÉFECTUEUX.

[Retour à la table des matières](http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res)

## Introduction ##

La radio IMAX/FLYSKY/TURNIGY/EURGLE 9x est un ensemble d'origine chinoise à micro-contrôleur. L'émetteur comporte un écran LCD de 128\*64 pixels, 2 manches 2 axes, 3 potentiomètres, 5 interrupteurs 2 positions, un interrupteur 3 positions, un interrupteur momentané et 4 trims digitaux.

Hormis une qualité de réalisation plus qu'honorable et un tarif particulièrement abordable, moins d'une centaine d'euros, sa particularité est d'utiliser une architecture électronique suffisamment simple pour permettre sa rétro-conception. De plus, le micro-contrôleur utilisé (Atmega64A) est flashable (re-programmable), ce qui rend possible le remplacement du logiciel (le firmware, ou FW) d'origine, peu réussi. Il ne restait plus qu'à attendre qu'une personne ayant les compétences nécessaires fasse ce constat pour que naisse le premier firmware alternatif pour 9x.

C'est Thomas Husterer qui fit ce premier pas en avril 2010 avec son logiciel th9x en open-source. Autrement plus élégant, souple et puissant que le logiciel d'origine, celui-ci a entraîné de nouveaux développeurs dans son sillage, toujours dans le principe open-source, avec à chaque fois des améliorations notables (dans l'ordre : er9x par Erez Raviv, gruvin9x par Bryan Rentoul, ersky9x par Mike Blandford, openTx par Bertrand Songis) y compris au niveau matériel : cartes de programmation, cartes mères plus puissantes, vibreur ou sortie audio, adaptateur SD, encodeurs pour navigation à la Multiplex, télémesure, etc.

Tous ces projets sont hébergés ici :
  * th9x : http://code.google.com/p/th9x/
  * er9x : http://code.google.com/p/er9x/
  * gruvin9x : http://code.google.com/p/gruvin9x/
  * ersky9x : http://code.google.com/p/ersky9x/
Il y a aussi, avec une logique différente, Radioclone de Rafal Tomczak : http://radioclone.org/

openTx (http://code.google.com/p/opentx/) représente la dernière évolution et aussi, à mon sens, l'arrivée à maturité de ces projets en offrant plus de fonctionnalités et de souplesse de programmation qu'aucune radio commerciale n'est en mesure d'offrir, indépendamment de sa gratuité ou du faible coût d'achat de l'émetteur.
openTx est épaulé par le logiciel companion9x (http://code.google.com/p/companion9x/, pour Windows, Linux et Mac) qui permet de mettre à jour le FW, mais aussi de sauvegarder, programmer et même simuler les programmes de modèles sur, raffinement s'il en est, une radio virtuelle.

A noter aussi qu'étant donnée la simplicité de l'architecture électronique de la 9x, il est tout à fait envisageable de réaliser sa propre carte mère... et même sa radio autour !
  * Le schéma d'origine (attention, il s'agit de la V1, quelque peu différente de la V2 actuelle) : http://9xforums.com/forum/viewtopic.php?f=44&t=199
  * Un exemple de circuit perso : http://www.rcgroups.com/forums/showthread.php?t=1631369

Il existe aussi deux cartes mères d'upgrade, adaptables sur la 9x ou sur un émetteur perso : http://gruvin9x.com/shop/ et http://www.ersky9x.net/
Outre des capacités mémoire et une puissance de calcul nettement plus élevées que celles de la carte mère d'origine, ces cartes mère offrent de nouvelles possibilités : gestion de carte SD, encodeurs rotatifs, enregistrement des chronos à l'extinction, etc. Ces 2 cartes sont également supportées par openTx, avec des fonctionnalités supplémentaires.

### Le principe Open Source ###

openTx et companion9x sont des projets Open Source sous licence GNU v2. Malgré la somme de travail qu'ils représentent, ils sont donc libres de téléchargement, consultation, redistribution, modification (aux risques et périls de l'utilisateur...) et d'utilisation, sous réserve de respecter les termes de la licence GNU v2 notamment en cas de réutilisation du code.

Il est possible de contribuer au développement de ces projets en remontant des bugs ou des propositions de nouvelles fonctionnalités sur la page ad-hoc du projet, en ouvrant un « issue » :
  * http://code.google.com/p/opentx/issues/list
  * http://code.google.com/p/companion9x/issues/list

A cet effet, il est important de :
  * bien caractériser, au préalable, le bug ou, pour la proposition, son intérêt et sa cohérence
  * le décrire (en anglais... pas le choix!) de manière précise et synthétique
  * pour un bug, ne pas oublier de donner le n° de version du firmware / logiciel et les options sélectionnées.

Un forum dédié permet aussi d'échanger sur le sujet :
http://9xforums.com/forum/viewforum.php?f=45

### Modifier la 9x pour openTx ###

Un document décrivant les différentes étapes de modification de la 9x est proposé dans la rubrique téléchargement d'openTx :
http://code.google.com/p/opentx/downloads/list

Celui-ci n'est valable que pour la carte mère d'origine, les cartes d'upgrade ayant déjà leur propre interfaces de reprogrammation.

### Choisir sa "version" d'openTx ###

Une fois sa radio modifiée et prête à recevoir un nouveau firmware, il est temps de se procurer une copie d'openTx.
Pour ce faire, télécharger [companion9x](http://code.google.com/p/companion9x/), le logiciel multiplateformes Windows / Mac / Linux qui complémente openTx. Après l'installation, ouvrir la boîte de dialogue des préférences. On y trouvera une liste déroulante contenant les différents firmwares supportés (companion9x permet également la gestion des autres firmwares alternatifs courants pour la 9x), et lorsque le firmware sélectionné est openTx, une liste de cases à cocher pour différentes options.

En effet, pour des raisons techniques (la mémoire disponible dans le processeur de la 9x étant limitée), il n'est plus possible sur la carte d'origine d'inclure à la fois toutes les nouvelles fonctionnalités développées récemment. Un système d'options a ainsi été mis en place, permettant à chacun de générer sa propre version de firmware en fonction des fonctionnalités qui lui seront utiles.

Il est un peu prématuré de parler de ces options en détail à ce stade, mais étant donné que le choix est présenté au nouvel utilisateur avant même le flashage du firmware, et certains des écrans présentés plus tard dépendant de leur choix, nous allons les décrire brièvement ici avant de les détailler plus tard. Le manuel s'y référera en **GRAS**.

| frsky | A utiliser si l'on a modifié sa radio pour afficher les données de télémesure FrSky selon le guide.<br>Ne s'applique <b>pas</b> si l'on utilise un module d'émission frsky sans pour autant avoir fait la modification en question. <br>
<tr><td> telemetrez </td><td> Support de la carte telemetrEZ de smartieParts.com                                                                                                                                                                                  </td></tr>
<tr><td> jeti  </td><td> Permet à la 9x d'émuler une jetibox pour l'affichage de données et la configuration de matériel Jeti.<br>Nécessite également une modification matérielle pour raccorder le module Jeti à la radio.                                  </td></tr>
<tr><td> ardupilot </td><td> Implémente l'affichage des données de télémesure d'un aéronef équipé d'ardupilot.<br>Nécessite également la modification matérielle pour la connexion du modem radio.                                                               </td></tr>
<tr><td> nmea  </td><td> Permet l'affichage de données GPS sur l'écran de la radio.<br>Nécessite également la modification matérielle pour la réception des données.                                                                                         </td></tr>
<tr><td> heli  </td><td> Inclut l'écran et les fonctionnalités de mixage CCPM pour faciliter la configuration de modèles d'hélicoptères.                                                                                                                     </td></tr>
<tr><td> templates </td><td> Inclut un écran offrant quelques gabarits de configuration standards pouvant être appliqués lors de la création<br>d'un nouveau modèle. Ceux-ci sont également disponibles dans companion9x.                                        </td></tr>
<tr><td> nosplash </td><td> Désactive l'écran d'accueil affiché au démarrage de la radio et le supprime de la mémoire, pour faire de la place<br>pour d'autres fonctionnalités.                                                                                 </td></tr>
<tr><td> nofp  </td><td> Désactive la fontionnalité des phases de vol.                                                                                                                                                                                       </td></tr>
<tr><td> nocurves </td><td> Désactive les courbes personnalisables.                                                                                                                                                                                             </td></tr>
<tr><td> audio </td><td> A utiliser si l'on souhaite remplacer le buzzer de la radio par un haut-parleur piezo ou à bobine.<br>Permet des sons différenciés pour les touches, les trims, différents choix de tonalités d'alarme, et en cas<br>d'utilisation de la télémesure <b>FRSKY</b> un variomètre audio. </td></tr>
<tr><td> voice </td><td> Ajoute le support des alarmes vocales et de l'énoncé des paramètres de télémesure.<br>Nécessite une modification matérielle pour l'ajout d'un module vocal.                                                                         </td></tr>
<tr><td> haptic </td><td> Support du retour haptique, nécessite l'installation matérielle d'un vibreur.                                                                                                                                                       </td></tr>
<tr><td> PXX   </td><td> Support du protocole PCM FrSky (expérimental)                                                                                                                                                                                       </td></tr>
<tr><td> DSM2  </td><td> Support des protocoles DSM2 / DSMX Spektrum. Nécessite l'installation d'un module d'émission Spektrum.                                                                                                                              </td></tr>
<tr><td> ppmca </td><td> Ajoute un réglage permettant l'ajustage des neutres de servos sans influer sur leurs courses.                                                                                                                                       </td></tr>
<tr><td> ppmus </td><td> Affiche les positions de servos en us au lieu des % habituels.                                                                                                                                                                      </td></tr>
<tr><td> gvars </td><td> Ajoute le support de variables globales, qui peuvent être ensuite utilisées en remplacement des réglages<br>individuels des paramètres numériques.                                                                                  </td></tr>
<tr><td> symlimits </td><td> Permet de changer le comportement par défaut des subtrims, les rendant plus adaptés aux modèles<br>complexes où plusieurs fonctions influent sur le même servo.                                                                     </td></tr>
<tr><td> potscroll </td><td> Permet la navigation dans les menus et l'édition de valeurs à l'aide des potentiomètres P1, P2 et P3 de la radio.                                                                                                                   </td></tr>
<tr><td> rotenc </td><td> Ajoute le sopport de l'encodeur rotatif (nécessite une modification hardware)                                                                                                                                                       </td></tr>
<tr><td> sp22  </td><td> A cocher en cas d'utilisation d'un programmeur SmartieParts version 2.2 ou plus récente, le contrôle du<br>rétroéclairage étant autrement inversé.                                                                                  </td></tr>
<tr><td> autoswitch </td><td> Permet la sélection simplifiée des interrupteurs dans les champs y relatifs.<br>Au lieu de défiler la liste avec les touches, il suffit de basculer l'interrupteur souhaité.                                                        </td></tr>
<tr><td> dblkeys </td><td> Permet d'accélérer l'entrée de paramètres numériques avec des combinaisons de 2 touches.                                                                                                                                            </td></tr>
<tr><td> nographics </td><td> Désactive les cases à cocher, les remplaçant par un simple ON/OFF.                                                                                                                                                                  </td></tr>
<tr><td> battgraph </td><td> Ajoute un affichage de la tension batterie sous forme graphique                                                                                                                                                                     </td></tr>
<tr><td> nobold </td><td> Désactive la mise en gras des mixeurs, inters et autres éléments actifs.                                                                                                                                                            </td></tr>
<tr><td> nottrace </td><td> Désactive l'affichage graphique de l'historique des gaz dans l'écran des statistiques .                                                                                                                                             </td></tr>
<tr><td> pgbar </td><td> Affiche une petite barre de progression montrant la sauvegarde des paramètres en mémoire.                                                                                                                                           </td></tr>
<tr><td> imperial </td><td> Affichage des données de télémesure en unités impériales.                                                                                                                                                                           </td></tr>
<tr><td> nogps </td><td> Désactive le support du GPS.                                                                                                                                                                                                        </td></tr>
<tr><td> novario </td><td> Désactive la fonction variomètre audio.                                                                                                                                                                                             </td></tr>
<tr><td> nogauges </td><td> Supprime l'affichage des valeurs de télémesure par barres.                                                                                                                                                                          </td></tr></tbody></table>

Les points importants pour le choix initial d'un firmware sont les suivants:<br>
<ul><li><b>HELI</b>: Bienvenu si l'on prévoit d'utiliser la radio pour commander des modèles d'hélicoptères.<br>
</li><li><b>FRSKY</b>: A choisir en fonction des modifications matérielles effectuées. Si les inters THR et AIL apparaissent toujours actifs sur l'écran de la radio, c'est en général que cette option ne correspond pas au matériel.<br>
</li><li><b>TEMPLATES</b>: Utile pour les débutants qui souhaitent des exemples de programmation sur la radio. Cette option occupant un espace mémoire considérable, et les mêmes gabarits étant disponibles dans companion9x, elle peut être désactivée avec peu de désagrément une fois qu'on a compris le fonctionnement d'openTx.<br>
</li><li><b>AUDIO</b>, <b>VOICE</b>, <b>HAPTIC</b>, <b>SP22</b>, <b>JETI</b>, <b>ARDUPILOT</b>, <b>NMEA</b>: Egalement à choisir en fonction des modifications matérielles.<br>
</li><li><b>DSM2</b>: A choisir si l'on prévoit d'utiliser la 9x pour commander des modèles équipés de récepteurs Spektrum, et de construire le module approprié.<br>
</li><li><b>PPMCA</b>, <b>SYMLIMITS</b>, <b>GVARS</b>: Utiles principalement pour des modèles complexes. Les modélistes débutants peuvent les laisser désactivées au début pour éviter trop de confusion.<br>
</li><li><b>DBLKEYS</b>, <b>AUTOSWITCH</b>: Pratique, recommandé.<br>
</li><li><b>NOBOLD</b>: A laisser désactivé, la mise en gras aide vraiment à la compréhension!<br>
</li><li><b>NOGRAPHICS</b>, <b>PGBAR</b>, <b>IMPERIAL</b>: Cosmétique uniquement, selon préférence.</li></ul>

Choisir également la langue, cliquer sur OK pour sauvegarder les changements, réouvrir les préférences et cliquer sur télécharger.<br>
Le firmware peut ensuite être flashé en utilisant Flasher->Ecrire la mémoire flash, et en sélectionnant le fichier téléchargé. Une fois le flashage effectué avec succès, la radio affichera une alerte d'EEPROM invalide qui est normale (l'installation est "fraîche", aucun réglage en mémoire) et qui peut être quittancée. La mémoire sera formattée, et la radio prête à l'emploi.<br>
<br>
<h3>Vue de l'émetteur et nomenclature</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/openTx_identification_organes_CMD_9x.jpg' />

<table><thead><th> Entrées proportionnelles: </th><th> Entrées digitales (interrupteurs): </th></thead><tbody>
<tr><td> 1. Gaz (Thr) : manche de gaz<br> 2. Prf (Ele) : manche de profondeur<br> 3. Ail (Ail) : manche d'ailerons<br> 4. Dir (Rud) : manche de dérive<br> 5. P1/P2/P3 : potentiomètres<br> 6. Trims de manche (impulsion par impulsion ou continu)</td><td> 1. THR<br> 2. RUD<br> 3. ELE<br> 4. ID0/1/2 (3-POS)<br> 5. AIL<br> 6. GEA<br> 7. TRN </td></tr></tbody></table>

Tous ces organes sont librement affectables dans openTx, y compris les trims digitaux qui peuvent être utilisés indépendamment des manches auxquels ils se rapportent.<br>
<br>
Pour tous les interrupteurs, la position « 0 » (inactif, par opposition à actif = 1) est « poussé vers l'avant ». Ils peuvent être utilisés en inverse (activation en position 0) quand leur désignation est précédée du symbole « ! », ce qui signifie dans openTx un « non » logique. Ainsi lorsque lon choisit l'interrupteur ELE, « ELE » indique le fonctionnement normal et « !ELE » indique un fonctionnement inversé. L'option de compilation <b>AUTOSWITCH</b> en simplifie l'utilisation, avec une reconnaissance automatique des interrupteurs lors de sa manipulation en phase d'affectation.<br>
<br>
Une désignation d'interrupteur finissant par « m » (ex : TRNm) indique un interrupteur momentané (à « bascule »), associé à l'interrupteur physique du même nom : quand ce dernier est actionné, le premier s'active pendant un court instant.<br>
<br>
<h3>Interface de dialogue utilisateur</h3>

Elle est assurée par un clavier à six boutons situés de part et d'autre de l'écran : un bouton « menu », un bouton « exit » et quatre flèches de navigation. Ces boutons seront identifiés dans ce manuel en gras et entre crochets, par exemple : <b>[</b><b>MENU]</b>.<br>
Certaines fonctions demandent d'appuyer sur le bouton pendant plus d'une seconde, c'est à dire un appui long qui sera noté ainsi : <b>[</b><b>MENU LONG]</b>.<br>
<br>
Concernant les flèches de navigation, il faut faire abstraction des indications gravées sur le clavier, notamment les « + » et  « - » positionnés à l'inverse de ce qui serait logique. Pour les plus bricoleurs, il est possible d'intervertir ces boutons. Pour éviter toute confusion, ces boutons seront identifiés dans cette notice en tant que <b>[</b><b>LEFT]</b> (gauche) et <b>[</b><b>RIGHT]</b> (droite).<br>
<br>
<h3>Navigation</h3>

D'une manière générale :<br>
<ul><li><b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b> / <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b> déplacent le curseur haut / bas / gauche / droite.<br>
</li><li>Le bouton <b>[</b><b>MENU]</b> est utilisé pour sélectionner, éditer, changer un état.<br>
</li><li>Le bouton <b>[</b><b>EXIT]</b> est utilisé pour sortir, comme on peut le deviner. Une pression amène généralement le curseur en haut de l'écran, une pression supplémentaire ramène à l'écran principal.</li></ul>

Depuis le menu principal :<br>
<ul><li><b>[</b><b>RIGHT LONG]</b> ouvre le menu « modèle ».<br>
</li><li><b>[</b><b>LEFT LONG]</b> ouvre le menu « paramètres généraux ».<br>
</li><li><b>[</b><b>MENU LONG]</b> ouvre le dernier écran utilisé.<br>
</li><li><b>[</b><b>UP LONG]</b> ouvre le menu « statistiques ».<br>
</li><li><b>[</b><b>DOWN LONG]</b> ouvre le menu « télémesure ».</li></ul>

Depuis un écran, <b>[</b><b>EXIT LONG]</b> ramène directement à l'écran principal.<br>
<br>
Une fois dans un menu, tant que le curseur est situé dans le coin supérieur droit de l'écran, les différents écrans sont parcourus en utilisant <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b>.<br>
<br>
<h3>Edition / Sauvegarde</h3>

De manière générale, il n'y a pas de fonction « annuler », toute modification est instantanément enregistrée sur l'EEPROM du micro-contrôleur. Un petit délai (une ou deux secondes) est cependant conseillé avant d'éteindre la radiocommande après une modification pour garantir sa sauvegarde à coup sûr.<br>
<br>
La modification d'une valeur se fait en deux temps : <b>[</b><b>MENU]</b> pour l'éditer en la mettant en surbrillance, puis <b>[</b><b>RIGHT]</b> / <b>[</b><b>LEFT]</b> pour la modifier.<br>
Dans le cas d'une zone à deux états (case à cocher, flèche de sens, etc.), c'est le bouton <b>[</b><b>MENU]</b> qui assure la modification de l'état.<br>
Pour certaines valeurs (gains et valeur de différentiel notamment), <b>[</b><b>MENU LONG]</b> permet d'affecter une variable globale (cf. menu « Courbes 8/12 ») à la place d'une valeur numérique.<br>
Pour sortir du mode édition, presser <b>[</b><b>MENU]</b> ou <b>[</b><b>EXIT]</b>.<br>
<br>
Si l'option <b>DBLKEYS</b> est activée, les raccourcis clavier suivants sont disponibles lors de l'édition d'une valeur :<br>
<ul><li><b>[</b><b>LEFT]</b> + <b>[</b><b>RIGHT]</b> : inverse le signe de la valeur.<br>
</li><li><b>[</b><b>UP]</b> + <b>[</b><b>RIGHT]</b> : met la valeur à 100%.<br>
</li><li><b>[</b><b>DOWN]</b> + <b>[</b><b>LEFT]</b> : met la valeur à -100%.<br>
</li><li><b>[</b><b>UP]</b> + <b>[</b><b>DOWN]</b>: met la valeur à 0.</li></ul>

<h3>Les écrans d'openTx</h3>

Voici un aperçu de la structuration de navigation des menus d'openTx. A noter que les numéros d'écran (en haut à droite) peuvent changer en fonction des options choisies.<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/openTx_synoptique.png' />

<ul><li>L'écran CONF. HELI n'apparaîtra que si l'option <b>HELI</b> est activée.<br>
</li><li>L'écran PHASES DE VOL n'apparaîtra pas si l'option <b>NOFP</b> est sélectionnée.<br>
</li><li>L'écran DR/EXPO est nommé MANCHES en cas d'utilisation des options <b>PPMCA</b> et/ou <b>SYMLIMITS</b>
</li><li>L'écran LIMITES est nommé SORTIES en cas d'utilisation des options <b>PPMCA</b> et/ou <b>SYMLIMITS</b>
</li><li>L'écran COURBES n'apparaîtra pas si l'option <b>NOCURVES</b> est sélectionnée.<br>
</li><li>L'écran TELEMESURE est lié à l'option <b>FRSKY</b>
</li><li>L'écran GABARITS n'apparaîtra que si l'option <b>TEMPLATES</b> est activée.</li></ul>

<h3>Comment ça marche</h3>

Tout d'abord, voici un premier aperçu du fonctionnement d'openTx au travers du diagramme de cheminement des ordres depuis les organes de commande et de commutation jusqu'aux servos.<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/openTx_cheminement_ordres.png' />

Ce diagramme est volontairement simplifié aux principaux cheminements des ordres, les choses peuvent être plus complexes dans le détail. Par exemple, les <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Fonctions_personnalis%C3%A9es_(10/12)'>fonctions personnalisées</a>, non représentées ici, peuvent interagir avec les <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Courbes_et_variables_globales_(8/12)'>variables globales</a> pour les réglages en vol, ou avec les <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Interrupteurs_personnalisables_(9/12)'>interrupteurs personnalisés</a>. De même, ces derniers peuvent utiliser des informations issues de la télémesure, ou être conditionnés à des interrupteurs physiques.<br>
<br>
Les entrées analogiques (manches et potentiomètres) ne sont pas utilisées telles quelles, mais après un filtre de calibration garantissant des courses de -100% à +100% de butée à butée (avec 0% pour point milieu). Pour les manches, ces entrées calibrées peuvent ensuite être directement utilisées dans le mixeur ou bien après application d'un formatage (dual-rate, expo, mais aussi courbe).<br>
<br>
Les trims digitaux fonctionnent indépendamment des manches auxquels ils se rapportent, ce qui permet au besoin de les différencier par phase de vol (si activées) ou même de les utiliser comme entrée de mixeur.<br>
<br>
Le Mixeur est l'articulation majeure d'openTx, sa fonction consistant à mettre en relation les différents organes de commande ou de commutation (= entrées) avec les sorties (= voies =  servos). Cette mise en relation peut être tout aussi bien basique (un manche = une voie) que complexe (plusieurs entrées sur une voie donnée, avec différenciation par phase de vol), suivant le besoin.<br>
<br>
Les ordres issus du Mixeur ne sont pas directement dirigés vers les servos, mais passent d'abord un formatage de sortie (Limites) qui régule l'ordre envoyé à chaque servo en le décalant (sub-trim), en l'inversant (sens) ou en écrêtant tout dépassement (limite). Puis finalement les voies sont encodées et envoyées aux servos via le couple module HF / récepteur.<br>
<br>
<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Écran principal</h2>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/01_1.png' />

L'écran principal est découpé en 2 parties. La partie supérieure comporte les éléments suivants :<br>
<ul><li>Le nom du modèle.<br>
</li><li>Le nom de la phase de vol (si l'option <b>PHASES</b> est activée).<br>
</li><li>La tension de la batterie de l'émetteur.<br>
</li><li>La position des trims.<br>
</li><li>Le chrono 1 et son mode de fonctionnement (paramétrage dans « Réglages modèles 2/12 »).</li></ul>

La partie inférieure comporte quatre écrans accessibles par <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b> :<br>
<br>
<table><thead><th> Visualisation des 16 sorties du récepteur sur deux pages<br>(via <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b>) </th><th> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/01_1.png' /> </th></thead><tbody>
<tr><td> Valeurs numériques en % des 16 sorties du récepteur sur deux pages<br>(via <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b>) </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/01_2.png' /> </td></tr>
<tr><td> Position des manches et état des interrupteurs sur deux pages<br>(via <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b>): d'abord les entrées physiques (manches, pots, inters)<br>puis les interrupteurs virtuels (SW1..SWC) </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/01_4.png' /><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/01_5.png' /> </td></tr>
<tr><td> Chrono 2 (paramétrage dans <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR?ts=1352728638&updated=OpenTx_Manual_FR#Configuration_du_mod%C3%A8le_(2/12)'>Configuration du modèle (2/12)</a>).<br><b>[</b><b>EXIT]</b> le remet à zéro </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/01_3.png' /> </td></tr></tbody></table>

Dans la vue principale, un appui sur <b>[</b><b>EXIT]</b> réinitialise les compteurs de la vue courante tandis que <b>[</b><b>EXIT LONG]</b> réinitialise tous les compteurs ainsi que les données de télémesure.<br>
<br>
<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Écrans de statistiques</h2>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/02_1.png' />  <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/02_2.png' />

Depuis l'écran principal, presser <b>[</b><b>UP LONG]</b> donne accès aux écrans de statistiques.<br>
<br>
Le premier affiche les différents compteurs :<br>
<ul><li>Temps total d'allumage de la radio<br>
</li><li>Chrono 1 (paramétrage dans <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR?ts=1352728638&updated=OpenTx_Manual_FR#Configuration_du_mod%C3%A8le_(2/12)'>Configuration du modèle (2/12)</a>)<br>
</li><li>Chrono 2 (paramétrage dans <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR?ts=1352728638&updated=OpenTx_Manual_FR#Configuration_du_mod%C3%A8le_(2/12)'>Configuration du modèle (2/12)</a>)<br>
</li><li>Durée d'utilisation moteur absolue (en minutes / secondes)<br>
</li><li>Durée d'utilisation moteur relativement à la durée totale d'allumage de la radio (en %)</li></ul>

Un graphique temporel de la consigne moteur est aussi affiché, à moins que l'option <b>NOTTRACE</b> ait été choisie.<br>
<br>
Le second montre des compteurs internes de l'émetteur, « tmain » représente le temps de calcul. Ce temps augmente avec la complexité des mixages, et peut devenir important (temps de réponse perceptible) suivant la configuration du modèle.<br>
<br>
Tous ces compteurs peuvent être remis à zéro par un appui sur <b>[</b><b>MENU]</b>.<br>
<br>
<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Paramètres généraux</h2>

Depuis l'écran principal, <b>[</b><b>LEFT LONG]</b> donne accès aux paramètres de la radiocommande. Ces réglages sont indépendants du modèle sélectionné.<br>
<br>
Les écrans de ce menu sont les suivants :<br>
<ol><li>Configuration radio<br>
</li><li>Ecolage<br>
</li><li>Info. version<br>
</li><li>Diagnostics<br>
</li><li>Entrées analogiques<br>
</li><li>Calibration</li></ol>

<h3>Réglages Radio (1/6)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/04_1.png' />

Cet écran permet de régler les paramètres généraux de l'émetteur :<br>
<ol><li>Son / mode :<br>
<ul><li>Aucun : pas d'alarme sonore (attention, y compris si la batterie est vide).<br>
</li><li>Alarm : uniquement les alarmes (batterie vide, radio inactive).<br>
</li><li>NoKey : bips normaux mais pas sur les touches d'édition.<br>
</li><li>Tout : tous les bips activés.<br>
</li></ul></li><li>Son / durée :  5 durées de bips possibles.<br>
</li><li>Tonalité : ajustement de la fréquence des bips (si l'option <b>AUDIO</b> est activée).<br>
</li><li>Vibreur / mode : réglage du mode du vibreur (si l'option <b>HAPTIC</b> est activée).<br>
<ul><li>Aucun : Vibreur désactivé.<br>
</li><li>Alarm : uniquement les alarmes (batterie vide, radio inactive).<br>
</li><li>NoKey : Vibrations normales mais pas sur les touches d'édition.<br>
</li><li>Tout : Vibration à chaque opération.<br>
</li></ul></li><li>Vibreur / force : force du vibreur (de 0 à 5) (si l'option <b>HAPTIC</b> est activée).<br>
</li><li>Contraste : contraste de l'afficheur LCD, de 20 (le plus clair) à 45 (le plus sombre).<br>
</li><li>Alarme / batterie faible : seuil de tension de batterie vide.<br>
</li><li>Alarme / inactivité : délai de non-utilisation des manches à partir duquel la radio alerte l'utilisateur, de 1 à 250 min (0 pour désactiver la fonction).<br>
</li><li>Alarme / mémoire faible : affiche une alerte si l'eeprom dispose de moins de 200 octets de libres lors de l'allumage de l'émetteur.<br>
</li><li>Alarme / sons désactivés : affiche une alerte au démarrage si "Son / mode" est sur « Aucun ».<br>
</li><li>Filtre ADC : filtre de Conversion Analogique Numérique de la position des manches.<br>
<ul><li>SIMP : 1024 pas, temps de calcul (et donc latence) très réduit.<br>
</li><li>OSMP : 2048 pas, légèrement plus lent que SIMP.<br>
</li><li>FILT : filtrage en cas de bruit excessif sur la conversion (servos qui frétillent). Attention, temps de latence supplémentaire de 30 ms.<br>
</li></ul></li><li>Inversion gaz : position inversée du ralenti de manche des gaz.<br>
</li><li>Bips chrono / minutes : bip à chaque minute quand le compteur tourne.<br>
</li><li>Bips chrono / compte à rebours : 30, 20, 10, 3, 2 et 1 s avant la fin du compteur, puis en continu après dépassement (ce dernier peut être rendu silencieux en vol par une courte pression sur <b>[</b><b>EXIT]</b>.<br>
</li><li>Rétroéclairage / alame : activation du rétro-éclairage lors d'une alarme.<br>
</li><li>Rétroéclairage / mode : mode d'activation du rétro-éclairage.<br>
<ul><li>Toujours ON.<br>
</li><li>Toujours OFF.<br>
</li><li>Btns : Activation par clavier.<br>
</li><li>Stks : Activation par manches.<br>
</li><li>Tout : Activation par clavier + manches.<br>
</li></ul></li><li>Rétroéclairage / durée : par pas de 5 s.<br>
</li><li>Ecran d'accueil : affiche l'écran d'accueil au démarrage (se passe par un appui sur n'importe quel manche/touche). Cette ligne n'existe pas si l'option <b>NOSPLASH</b> est choisie.<br>
</li><li>Fuseau horaire : pour l'heure affichée par le GPS de télémesure (option <b>FRSKY</b> uniquement).<br>
</li><li>Coordonnées GPS : type d'affichage des coordonnées (option <b>FRSKY</b> uniquement).<br>
</li><li>Ordre des voies RX : définit l'ordre des mixages de base (G = Gaz, P = Profondeur, A = Ailerons, D = Dérive) générés automatiquement sur les quatre premières voies à la création d'un modèle.<br>
</li><li>Mode : attribution des manches de l'émetteur aux fonctions principales (gaz, tangage, roulis, lacet).</li></ol>

<h3>Ecolage (2/6)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/05_1.png' />

Cet écran permet d'affecter les voies d'une radio « élève » (signal PPM, via la prise écolage) aux manches de la radio « maître » et de calibrer leur neutre.<br>
<ol><li>Mode :<br>
<ul><li>OFF.<br>
</li><li>+= : ajoute la valeur du manche élève à celle du maître.<br>
</li><li>:= : remplace la valeur du manche maître par celle de l'élève.<br>
</li></ul></li><li>% : taux de proportionnalité (gain) appliqué aux ordres de l'élève.<br>
</li><li>Source : entrée élève à affecter au manche maître.</li></ol>

Pour la calibration du neutre du PPM envoyé par l'émetteur élève, mettre en surbrillance  « Cal » et presser <b>[</b><b>MENU]</b>.<br>
<br>
Le multiplicateur est un gain global appliqué à tous les ordres issus de l'émetteur élève. Celui-ci est à  régler après calibration des neutres pour arriver à 100% quand le manche de l'élève est en butée.<br>
<br>
<b>NOTA</b>
<ul><li>L'émetteur élève doit être non-programmable ou doté d'une programmation neutre (voie = manche).<br>
</li><li>Cet écran ne s'applique qu'aux 4 voies de commande principales. Les autres voies provenant de l'émetteur élève (jusqu'à 8) sont toutefois disponibles, et peuvent être utilisées au travers des mixeurs.<br>
</li><li>L'interrupteur d'activation de l'écolage se définit dans la programmation du modèle (cf. paragraphe <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Fonctions_personnalis%C3%A9es_(10/12)'>Fonctions personnalisées (10/12)</a>).<br>
</li><li>Le fonctionnement général de la prise d'écolage est identique aux radios JR / Graupner / Spektrum, c'est-à-dire que la prise est une entrée (maître) lorsque linterrupteur de la radio est sur ON, et en sortie (élève) lorsque l'interrupteur est sur OFF. Dans ce deuxième cas, la radio s'allume toute seule à l'insertion du connecteur, et l'écran ci-dessus affiche "Elève". Des exceptions sont néanmoins possibles lors du choix de protocoles spéciaux (cf. paragraphe <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Configuration_du_mod%C3%A8le_(2/12)'>Configuration du modèle (2/12)</a>).</li></ul>

<h3>Info version (3/6)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/06_1.png' />

Cet écran affiche la version du firmware utilisé :<br>
<ul><li>SVN : La révision SVN du firmware. C'est cette ligne qui représente la version utilisée, à mentionner en cas de questions ou de rapport de bug.<br>
</li><li>DATE : Date de compilation du firmware.<br>
</li><li>TIME : Heure de compilation du firmware.<br>
</li><li>EEPR : La version de l'EEPROM et sa variante (FrSky, GVARS, etc.).</li></ul>

<h3>Diagnostics (4/6)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/07_1.png' />

Cet écran permet de vérifier le bon fonctionnement des boutons, interrupteurs et trims en affichant leur état (on = passage de 0 à 1 et mise en surbrillance).<br>
<br>
<h3>Entrées analogiques (5/6)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/08_1.png' />

Cet écran affiche les valeurs brutes des entrées analogiques en hexadécimal, de 0 à 0x03FF (0..1023), ainsi que la valeur en % après calibration. Les entrées sont les suivantes :<br>
<ul><li>A1..A4 : manches<br>
</li><li>A5..A7 : potentiomètres</li></ul>

Il est aussi possible d'étalonner la mesure de la tension batterie : <b>[</b><b>DOWN]</b> pour mettre la valeur en surbrillance, puis <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b> pour la diminuer / augmenter afin de la caler sur une mesure au voltmètre.<br>
<br>
<h3>Calibration des entrées analogiques (6/6)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/09_1.png' />

Cet écran permet de calibrer les entrées analogiques A1  A7.<br>
<br>
Pour effectuer la calibration :<br>
<ol><li>Presser <b>[</b><b>MENU]</b>.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/09_2.png' />
</li><li>Mettre les manches et les potentiomètres au neutre.<br>
</li><li>Presser <b>[</b><b>MENU]</b>.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/09_3.png' />
</li><li>Bouger les manches et les potentiomètres de butée à butée (sans forcer...).<br>
</li><li>Presser <b>[</b><b>MENU]</b>, les valeurs sont sauvegardées.</li></ol>

<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Réglages des modèles</h2>

Depuis l'écran principal, presser <b>[</b><b>RIGHT LONG]</b> donne accès au menu de sélection/édition des modèles. Il permet de régler les paramètres propres au modèle en cours, au travers des écrans suivants (déplacement entre écrans par <b>[</b><b>RIGHT]</b> et <b>[</b><b>LEFT]</b> sur le numéro de page) :<br>
<ol><li>Mémoires des modèles.<br>
</li><li>Réglages du modèle.<br>
</li><li>Réglages hélicoptères (si l'option <b>HELI</b> est activée).<br>
</li><li>Phases de vol (si l'option <b>PHASES</b> est activée).<br>
</li><li>Manches (DR/Expo).<br>
</li><li>Mixeurs.<br>
</li><li>Sorties (Limites).<br>
</li><li>Courbes  (si l'option <b>COURBES</b> est activée).<br>
</li><li>Interrupteurs personnalisables.<br>
</li><li>Fonctions spéciales.<br>
</li><li>Télémesure (si l'option <b>FRSKY</b> est activée)<br>
</li><li>Assistant de création de mixeurs (si l'option <b>TEMPLATES</b> est activée)</li></ol>

<h3>Mémoires des modèles (1/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/10_1.png' />

Cet écran liste les modèles déjà existants (jusqu'à 16), et permet de charger, dupliquer, déplacer ou effacer un modèle existant ou d'en créer un nouveau.<br>
<br>
La gestion de la mémoire est dynamique, avec un affichage de l'espace libre (en octets, en haut de l'écran) et de l'espace utilisé par chaque modèle (à sa droite), ce dernier étant proportionnel à sa complexité (mixages, courbes, options, etc.).<br>
<br>
L'étoile « <b><code>*</code></b> » sur la gauche indique le modèle en cours.<br>
<br>
<b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b> permet de se déplacer dans la liste des modèles.<br>
Un appui sur <b>[</b><b>MENU LONG]</b> permet le chargement du modèle sélectionné ou la création d'un nouveau modèle si la mémoire sélectionnée est vide.<br>
<br>
<h4>Pour créer un modèle :</h4>

<ul><li>Se positionner sur la ligne vierge à utiliser avec les touches <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/10_2.png' />
</li><li>Appuyer sur la touche <b>[</b><b>MENU LONG]</b> pour demander la création.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/10_3.png' />
</li><li>Le nouveau modèle est automatiquement chargé, son nom par défaut (modifiable) étant attribué sous la forme « MODELE » + numéro de ligne.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/10_4.png' /></li></ul>

<h4>Pour supprimer un modèle :</h4>

<ul><li>Se positionner sur la ligne à supprimer avec les touches <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>.<br>
</li><li>Appuyer sur la touche <b>[</b><b>MENU]</b> pour sélectionner la ligne (elle passe en surbrillance).<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/13_1.png' />
</li><li>Appuyer sur la touche <b>[</b><b>EXIT LONG]</b> pour demander la suppression (non autorisée, par sécurité, sur le modèle en cours).<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/13_2.png' />
</li><li>Confirmer avec la touche <b>[</b><b>MENU]</b> ou annuler avec la touche <b>[</b><b>EXIT]</b>.</li></ul>

<h4>Pour dupliquer un modèle :</h4>

<ul><li>Se positionner sur la ligne à copier avec les touches <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>.<br>
</li><li>Appuyer sur la touche <b>[</b><b>MENU]</b> pour sélectionner la ligne (elle passe en surbrillance).<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/11_1.png' />
</li><li>Appuyer sur <b>[</b><b>UP]</b> ou <b>[</b><b>DOWN]</b> pour la dupliquer vers le haut ou vers le bas.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/11_2.png' />
</li><li>Une fois l'emplacement de destination choisi, appuyer sur <b>[</b><b>MENU]</b> pour confirmer ou <b>[</b><b>EXIT]</b> pour annuler l'opération.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/11_3.png' /></li></ul>

<h4>Pour déplacer un modèle :</h4>

<ul><li>Se positionner sur la ligne à copier avec les touches <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>.<br>
</li><li>Appuyer deux fois sur la touche <b>[</b><b>MENU]</b> pour sélectionner la ligne (elle passe en surbrillance entourée d'un pointillé).<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/12_1.png' />
</li><li>Appuyer sur <b>[</b><b>UP]</b> ou <b>[</b><b>DOWN]</b> la déplacer vers le haut ou vers le bas.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/12_2.png' />
</li><li>Une fois l'emplacement de destination choisi, appuyer sur <b>[</b><b>MENU]</b> pour confirmer ou <b>[</b><b>EXIT]</b> pour annuler l'opération.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/12_3.png' /></li></ul>

<b>NOTA</b>

Les fonctions créer / effacer / déplacer / dupliquer des lignes sont particulièrement importantes dans openTx, car elles sont aussi utilisées dans d'autres écrans (« manches » et « mixeurs ») pour gérer à la carte leur fonctionnement.<br>
Une opération de copie ou de déplacement peut être annulée en cours d'exécution en appuyant sur la touche <b>[</b><b>EXIT]</b>.<br>
<br>
<h3>Configuration du modèle (2/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/14_1.png' />

Voici le détail des options :<br>
<ol><li>Nom :  pour l'éditer, presser <b>[</b><b>MENU]</b>.<br>Après appui sur <b>[</b><b>MENU]</b> le premier caractère est en surbrillance. <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b> change le caractère. <b>[</b><b>RIGHT]</b> / <b>[</b><b>LEFT]</b> déplacer le curseur. <b>[</b><b>RIGHT LONG]</b> ou <b>[</b><b>LEFT LONG]</b> bascule la lettre en majuscule / minuscule. <b>[</b><b>MENU]</b> / <b>[</b><b>EXIT]</b> termine l'édition.<br>Nota : le numéro de modèle est indiqué dans la ligne supérieure, à côté de CONF.<br>
</li><li>Chronos 1 et 2 :<br>Réglage de la valeur de départ de ce compteur : si 00:00, le chrono est croissant, sinon il est décompteur à partir de la valeur de départ. <b>[</b><b>RIGHT]</b> / <b>[</b><b>LEFT]</b> bascule en secondes ou minutes. <b>[</b><b>MENU]</b> édite la valeur (le curseur clignote), <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b> / <b>[</b><b>RIGHT]</b> / <b>[</b><b>LEFT]</b> la modifie. <b>[</b><b>MENU]</b> / <b>[</b><b>EXIT]</b> termine l'édition.<br>Trigger :  choix du mode de déclenchement du compteur (ne pas oublier l'option « ! » si besoin d'inverser le sens de déclenchement) :<br>
<ul><li>OFF : inutilisé.<br>
</li><li>ABS : actif en permanence.<br>
</li><li>GZ%/GZs/GZt : actif en fonction du régime moteur (voir plus loin pour sa configuration). GZ% indique que la vitesse de défilement est proportionnelle à la consigne de gaz. GZt indique que le chrono démarre dès que la consigne moteur est supérieure à -100% (moteur stoppé) et ne s'arrête plus, alors que GZs s'arrête quand le manche des gaz revient à -100%.<br>
</li><li>Interrupteur : chaque chrono peut être déclenché / arrêté par un interrupteur.<br>
</li></ul></li><li>Limites Et. (étendues) : autorise des débattements jusqu'à 125% au lieu de 100%. A réserver à des besoins spécifiques, car un débattement de 100% sur openTx correspond déjà au débattement maxi de la plupart des radiocommandes commerciales (de par la gestion différente des fins de courses).<br>
</li><li>Trims Et. (étendus) : étend la course des trims de 25% de la course du manche à 100%. A noter que si le réglage du trim dépasse +/-25%, il clignotera sur l'écran principal pour notifier au pilote qu'un réglage mécanique est fortement conseillé.<br>
</li><li>Pas trim : mode de fonctionnement des trims digitaux.<br>
<ul><li>Expo : exponentiel, réglage fin autour du neutre puis avec des pas de + en + élevés.<br>
</li><li>ExFin : extra fin 1 pas par clic.<br>
</li><li>Fin : 2 pas par clic.<br>
</li><li>Moyen  : 4 pas par clic.<br>
</li><li>Gros : 8 pas par clic.<br>
</li></ul></li><li>Source gaz : identification de la source de la fonction gaz.<br>
<ul><li>Gaz : manche de gaz.<br>
</li><li>P1..P3 : potentiomètres.<br>
</li><li>CH1..CH16 : voie physiques ou virtuelles.<br>
</li></ul></li><li>Trim Gaz : adapte le trim de gaz à l'utilisation avec un moteur thermique, en ajustant le ralenti sans pour autant modifier le plein régime.<br>
</li><li>Alerte Gaz : active une alarme au démarrage de l'émetteur si le manche ou la voie de gaz (cf. ci-avant) n'est pas complètement réduit (= -100%).<br>
</li><li>Alerte Int (Interrupteurs) : vérifie l'état des interrupteurs au démarrage et alerte en cas d'écart avec l'état programmé. TRE0GA correspond à THR, RUD, etc. Pour définir l'état par défaut des interrupteurs, les positionner puis presser <b>[</b><b>MENU LONG]</b>.<br>
</li><li>Bips Centre : signale le passage au neutre des manches et potentiomètres. DPGA123 correspond à Dérive, Profondeur, Gaz, Ailerons, P1, P2 et P3 (utiliser <b>[</b><b>RIGHT]</b> / <b>[</b><b>LEFT]</b> pour sélectionner la voie et <b>[</b><b>MENU]</b> pour activer/désactiver).<br>Le bip est activé quand le caractère correspondant est en surbrillance. Utile notamment pour retrouver le centre des potentiomètre en plein vol.<br>
</li><li>Proto : protocole d'encodage des ordres.<br>
<ol><li>PPM : le standard classique.<br>
<ul><li>PPM : fontionnement normal, un nombre de voies de 4 à 16 (xxCH) est transmis au module d'émission, la prise d'écolage est disponible en entrée. Les voies inutilisées peuvent servir à d'éventuelles fonctions virtuelles créées par mixeur.<br>
</li><li>PPM16 : le nombre de voies configuré est transmis au module d'émission, les 8 suivantes sont envoyées sur le port écolage.<br>
</li><li>PPMsim : aucun signal n'est envoyé au module d'émission, tandis que le port écolage est forcé en sortie pour une utilisation avec simulateur ou en écolage avec le module HF d'origine (avec inter de la radio sur ON).<br>
</li><li>Trame PPM : Paramètres du protocole PPM (longueur de trame, polarité, durée de l'impulsion de séparation).<br>
</li></ul></li><li>PXX : Protocole FrSky PCM, en développement (option <b>PXX</b>).<br>
<ul><li>NumRX : Numéro de récepteur pour la fonction Model Match.<br>
</li><li>Sync : définition du failsafe.<br>
</li></ul></li><li>DSM2 : Protocole Spektrum (Option <b>DSM2</b>). Le binding se fait en maintenant l'inter TRN actif lors de la mise sous tension de la radio. <b>L'écran d'accueil doit être désactivé, et aucune alarme ne doit apparaître</b>, sinon le binding ne s'effectuera pas.<br>
<ul><li>LP2/LP4 : Pour module "courte portée" récupéré d'une radio LP4DSM.<br>
</li><li>DSMseu : Modulation DSM2 uniquement.<br>
</li><li>DSMX : Modulation auto DSMX/DSM2.<br>
</li><li>NumRX : Numéro de récepteur pour la fonction Model Match.<br>
</li><li>RANGE : Sélectionner et presser <b>[</b><b>MENU]</b> pour activer le test de portée. L'indicateur devient "range" et la radio bipe jusqu'à la fin du test par <b>[</b><b>MENU]</b> ou <b>[</b><b>EXIT]</b>.</li></ul></li></ol></li></ol>

<h3>Réglages hélicoptère (3/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/15_1.png' />

Cet écran (si l'option <b>HELI</b> est activée) est dédié au réglage d'un hélicoptère CCPM (servos de cyclique agissant aussi sur le pas).<br>
<br>
Les options sont les suivantes :<br>
<ol><li>Type de plateau cyclique: permet de définir le type de tête rotor.<br>
<ul><li>120 : tête standard à 120°, avec le servo central à l'avant ou à l'arrière.<br>
</li><li>120X : comme 120° mais tourné de 90° (le servo central est sur un côté).<br>
</li><li>140 : tête à 140°, avec le servo central à l'avant ou à l'arrière.<br>
</li><li>90 : tête à 90°, un servo de tangage à l'avant ou à l'arrière et 2 servos de roulis à 180° l'un de l'autre.<br>
</li></ul></li><li>Collectif : définit la source du pas collectif, soit directement le manche de gaz soit une voie (non utilisée par un servo) permettant ainsi de bénéficier d'une ou plusieurs courbe(s) de pas (via un ou plusieurs ligne(s) de mixage associée(s) à cette voie).<br>
</li><li>Limite Cyclique : limitations de l'amplitude de mouvement du plateau cyclique en tangage et roulis.<br>
</li><li>Direction PRF / AIL / COL : permet d'inverser le sens d'action des fonctions tangage / roulis / pas collectif. A utiliser de concert avec les sens de rotation des servos et le signe des mixeurs pour obtenir les bons sens de déplacement des servos pour chaque fonction.<br>La méthodologie de réglage est la suivante :<br>
<ul><li>Attribuer à chaque voie un mixeur (cf. paragraphe <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR?ts=1352728638&updated=OpenTx_Manual_FR#Mixeur_(6/12)'>Mixeur (6/12)</a>) avec comme entrée CYC1, 2 et 3.<br>
</li><li>Régler le sens des servos dans le menu Servos (ou Limites) pour que le manche de pas actionne tous les servos dans le même sens.<br>
</li><li>Régler le sens des fonctions dans le menu décrit ici.</li></ul></li></ol>

<h3>Phases de vol (4/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/16_1.png' />

Cet écran (si l'option <b>PHASES</b> est activée) permet de gérer cinq phases de vol dont une par défaut (PV0), chacune pouvant être librement nommée. La phase active est affichée en gras (sauf si l'option <b>NOBOLD</b> est activée).<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/16_2.png' />
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/16_3.png' />

Pour modifier les paramètres d'une phase de vol, choisissez-la avec les touches <b>[</b><b>UP]</b> et <b>[</b><b>DOWN]</b> et appuyez sur <b>[</b><b>MENU]</b> :<br>
<ol><li>Nom : libellé de la phase (jusqu'à 6 caractères).<br>
</li><li>Interrupteur : sélectionner l'interrupteur (physique ou virtuel) d'activation de la phase.<br>
</li><li>Trims : chaque trim (Dérive / Profondeur / Gaz / Ailerons) peut avoir une valeur propre dans cette phase ou une valeur commune avec d'autres phases (0 à 4).<br>
</li><li>Fondu ON : permet une transition en douceur en entrant dans cette phase, sur une durée de 0 à 7,5 secondes pas pas de 0,5 s.<br>
</li><li>Fondu OFF : même chose en sortie de cette phase de vol.<br>
Pour revenir à l'écran précédent, appuyer sur <b>[</b><b>EXIT]</b>.</li></ol>

<h3>Formatage des manches (DR/EXPO) (5/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/17_1.png' />

Cet écran permet de formater l'ordre de chaque manche (Dérive / Profondeur / Gaz / Ailerons), via un gain (historiquement appelé Dual-Rate, pour double-débattement), une fonction exponentielle ou même une courbe.<br>
<br>
En règle générale, un gain de 75% donne un débattement équivalent à celui de 100% sur la majorité des radio commerciale. Il est aussi préférable d'utiliser une valeur inférieure à 100% pour laisser de la latitude au trim avant l'écrêtage des limites en fin de course. Il est aussi important de noter que c'est ici que se définit le débattement de chaque fonction, et non dans le menu limite comme cela est souvent (et à tort) pratiqué, ce dernier servant à ajuster la réponse de chaque servo, quelle que soit la ou les fonction(s) qui le pilote(nt).<br>
<br>
A chaque manche peut correspondre plusieurs lignes de formatage (jusqu'à 14 au total, avec un compteur en haut de l'écran), de manière à différencier les réglages pour certaines phases de vol ou simplement via un interrupteur. Comme pour les phases de vol, les formatages actifs sont affichés en gras. Par défaut (pas de ligne créée pour le manche), le gain est de 100% et aucune courbe ni différenciation par phase ou autre n'est appliquée.<br>
<br>
Le processus de gestion des lignes est identique à celui utilisé pour les mémoires de modèles, le revoici cependant pour bien s'en imprégner.<br>
<br>
<h4>Pour créer une ligne :</h4>
S'il aucune ligne de formatage n'est appliquée au manche, se positionner sur la ligne vide correspondante avec les touches <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b> et appuyer sur <b>[</b><b>MENU LONG]</b> pour créer une ligne de formatage et ouvrir son écran de paramétrage.<br>
Si une ligne de formatage est déjà affectée au manche, se placer dessus avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>, la sélectionner avec <b>[</b><b>MENU]</b> et appuyer sur <b>[</b><b>RIGHT LONG]</b> ou <b>[</b><b>LEFT LONG]</b> pour créer la nouvelle ligne respectivement au-dessus ou au-dessous.<br>
<br>
<h4>Pour supprimer une ligne :</h4>
Se placer sur la ligne à supprimer avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>, la sélectionner avec <b>[</b><b>MENU]</b> et appuyer sur <b>[</b><b>EXIT LONG]</b>.<br>
<br>
<h4>Pour dupliquer une ligne :</h4>

<ul><li>Se placer sur la ligne à copier avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>, la sélectionner avec <b>[</b><b>MENU]</b> (elle passe en surbrillance).<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/18_1.png' />
</li><li>Se positionner sur la ligne de destination avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/18_2.png' />
Appuyer sur <b>[</b><b>MENU]</b> pour effectuer la duplication.</li></ul>

<h4>Pour déplacer une ligne :</h4>

<ul><li>Se placer sur la ligne à déplacer avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>, la sélectionner en appuyant deux fois sur <b>[</b><b>MENU]</b> (elle passe en surbrillance entourée en pointillé).<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/19_1.png' />
</li><li>Se positionner sur la ligne de destination avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/19_2.png' />
</li><li>Appuyer sur <b>[</b><b>MENU]</b> pour effectuer le déplacement.<br>
Il est possible d'interrompre à tout moment une opération de duplication ou déplacement en appuyant sur la touche <b>[</b><b>EXIT]</b>.</li></ul>

<h4>Pour éditer les valeurs d'une ligne :</h4>

Se placer sur la ligne à éditer avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b> et appuyer sur <b>[</b><b>MENU LONG]</b> pour ouvrir l'écran de paramétrage.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/17_2.png' />

Cet écran est composé de deux parties : à gauche les paramètres et à droite la courbe de sortie avec le curseur graphique (et ses coordonnées) associé à la position du manche. Le graphique affiche toujours l'ordre de sortie final du manche, y compris si la ligne en cours d'édition est inactive.<br>
<br>
Les paramètres sont les suivants :<br>
<ol><li>Ratio : gain appliqué à l'ordre (0 à +100%).<br>
</li><li>Expo: taux d'exponentiel (-100% à +100%).<br>
</li><li>Courbe : remplace l'exponentiel par une courbe<br>
<ul><li>soit prédéfinie : x>0, x<0, |x|, f>0, f<0, |f| (voir <a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Edition_d%27un_mixage'>Edition d'un mixage</a> pour la signification des différents choix).<br>
</li><li>soit personnalisée : CB1..CB8 (3 à 17 points, détails ci-après), à éditer avec <b>[</b><b>MENU]</b>.<br>
</li></ul></li><li>Phase : phase(s) pour laquelle la ligne est active (actif = en surbrillance).<br>
</li><li>Interrupteur : activation spécifique de la ligne (en complément de la phase).<br>
</li><li>Côté : plage sur laquelle la ligne est active (partout, lorsque l'entrée est négative ou lorsqu'elle est positive), indiqué par une flèche sur la ligne de formatage correspondante. Cela permet, via deux lignes de formatage, de différencier par côté la réponse du manche.</li></ol>

<h3>Mixeur (6/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/20_1.png' />

Le rôle du mixeur est de relier des entrées (appelées aussi sources : manches, potentiomètres, interrupteurs physique ou virtuel, trims digitaux, valeur statique) aux sorties (= voies = servos), avec la possibilité de croiser / modifier les ordres donnés par ces entrées.<br>
<br>
Pour bien situer le fonctionnement d'openTx :<br>
<ul><li>La majorité des radiocommandes commerciales, excepté Multiplex dont la logique est similaire à celle d'openTx, proposent un panel de mixages pré-définis et à la structure figée (delta, etc.). Ces mixages sont activés au besoin et épaulés par quelques mixages libres, généralement basiques et souvent peu pratiques à cause de l'ambigüité souvent présente entre voies et fonctions (ailerons par ex.). Le tout part généralement des organes de commande avec une réaffectation éventuelles des voies.<br>
</li><li>A contrario, openTx autorise un routage totalement libre, partant de la finalité (les gouvernes, via les voies) et offrant la possibilité de chaîner ou d'intriquer les mixages pour créer des fonctions complexes. Par exemple, la sortie d'un mixage peut ne pas être affectée physiquement à un servo mais servir comme entrée à un ou plusieurs autres mixages (par ex. pour gérer la courbure d'une aile). Ou bien, un mixage peut influencer son voisin en le multipliant ou le remplaçant suivant le contexte. De plus, openTx permet la différenciation des mixages par phase de vol, ce que très peu de radiocommandes commerciales, même très haut de gamme, offrent.</li></ul>

Le bénéfice de cette approche est triple :<br>
<ul><li>La structure de mixage est univoque, un seul coup d'oeil dans le menu Mixeur permet de déterminer exhaustivement la provenance des ordres reçus par chaque servo.<br>
</li><li>La puissance de programmation est, objectivement, sans équivalence...<br>
</li><li>La souplesse, l'efficacité et la rapidité de programmation (aussi complexe soit-elle) sont elles aussi sans équivalence.</li></ul>

Il y a une contrepartie à cette latitude quasi totale de programmation. En effet, la construction et la structuration des mixages nécessitent un minimum de réflexion de la part de l'utilisateur, qui doit a minima se poser les questions suivantes :<br>
<ul><li>Quels sont les servos à actionner et quelles voies leur attribuer ?<br>
</li><li>Quels sont les ordres que doit recevoir chaque voie ?<br>
</li><li>Avec ou sans phase de vol ?<br>
</li><li>Comment minimiser le nombre de valeurs à programmer / régler et éviter les redondances (par ex., une courbe ou une variable globale peut définir un taux de différentiel global sur toute la voilure d'un planeur quadroflap, ou une voie virtuelle peut définir une fonction, par ex. une courbure de voilure, en groupant plusieurs entrées) ?</li></ul>

<h4>Écran principal</h4>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/20_1.png' />

Chaque ligne du mixeur correspond à un mixage. Les fonctions d'édition, de suppression, de copie et déplacement des lignes sont exactement les mêmes que pour le formatage des manches (DR/expo), permettant de créer à la carte sa propre structure de mixages.<br>
La aussi, les lignes actives sont indiquées en gras.<br>
<br>
CHx correspond à la voie x du récepteur. Sur cet exemple basique (défini par défaut à la création d'un modèle et entièrement modifiable), le manche de gaz est affecté sur voie 1, avec un taux de mixage de 100% (gain de 1 pour 1), de même pour les manches de profondeur, ailerons et dérive sur respectivement les voies 2, 3 et 4.<br>
<br>
Les gains sont directement modifiables avec <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b> après y avoir accédé avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>. Sauf besoin spécifique, il est fortement conseillé (pour s'y retrouver...)  de laisser les gains à +/-100%, en considérant qu'ils s'agit plutôt d'une activation et en s'appuyant sur les formatages de manches pour ajuster les débattements par fonction.<br>
<br>
Pour aller plus loin, voici un exemple de programmation un peu plus complexe, en l'occurence un motoplaneur avec un servo par aileron et une fonction snap-flap (entrée profondeur ajoutée sur les deux servos d'ailerons) :<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/22_1.png' />

A l'image des formatages de manches, plusieurs lignes (jusqu'à 32) peuvent être actives simultanément.<br>
<br>
De même, plusieurs lignes peuvent être affectées à une voie, avec un mode d'application spécifique (sur la voie concernée) :<br>
<ul><li>« += » : la ligne est ajoutée au résultat des lignes précédentes (mode par défaut).<br>
</li><li>« <b><code>*</code></b>= » : la ligne multiplie le résultat de toutes les lignes précédentes.<br>
</li><li>« := » : la ligne remplace toutes les lignes précédentes.</li></ul>

Les valeurs « 20 » affichées à droite correspondent au différentiel d'ailerons (cf. ci-après).<br>
<br>
<b>NOTA</b>

En l'absence d'ordre (pas de mixage ou mixage inactif) sur une voie, sa valeur de sortie est de 0% (position médiane) et non -100% (butée basse).<br>
<br>
<h4>Edition d'un mixage</h4>


<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/21_1.png' />

Les options disponibles sont les suivantes :<br>
<ol><li>Source : ordre utilisé en entrée par le mixage<br>
<ul><li>Tout organe physique : manches, potentiomètres, interrupteurs, trims digitaux.<br>
</li><li>Interrupteurs virtuels : SW1...SWC.<br>
</li><li>MAX :  entrée statique, la valeur de sortie du mixage est « Ratio » quand le mixage est actif, sinon 0 (transparent).<br>
</li><li>3POS : renvoie « -Ratio », 0, « +Ratio » suivant la position de l'interrupteur à 3 positions.<br>
</li><li>CYC1, CYC2, CYC3: sorties du mixage hélicoptère (menu Héli 3/10). CYC1 correspond à la sortie principale de tangage pour les plateaux classique et à la sortie principale de roulis en plateau 120X.<br>
</li><li>PPM1..PPM8 : entrées PPM de la prise écolage. Permet par exemple d'ajouter des fonctions de rotation de caméra en FPV.<br>
</li><li>CH1..CH16 : sorties des autres mixages, utilisable pour réaliser des fonctions complexes par chaînage.<br>
</li></ul></li><li>Ratio : gain du mixage qui multiplie la valeur de sortie (de -125% à 125%, défaut = +/-100%).<br>
</li><li>Décalage : décale la valeur d'entrée (de -125 à 125%, défaut = 0).<br>
</li><li>Trim : si « ON » la valeur du trim associé au manche en entrée de mixage est prise en compte dans le mixage, si « OFF » le trim est ignoré. Il est aussi possible d'utiliser un trim (Dérive / Profondeur / Gaz / Ailerons) différent de celui par défaut.<br>
</li><li>DRex : prise en compte du formatage de manche, sinon c'est l'ordre brut issu du manche qui est utilisé.<br>
</li><li>Courbe :<br>
<ul><li>Diff : différentiel (0 par défaut).<br>
</li><li>x>0 : la valeur de la source ne sera prise en compte que si positive (sinon 0),<br>
</li><li>x<0 : idem mais pour des valeurs négatives.<br>
</li><li>|x| : la valeur prise en compte sera la valeur absolue.<br>
</li><li>f>0 : si la source est positive la valeur sera « + Ratio » sinon 0.<br>
</li><li>f<0 : si la source est négative la valeur sera « - Ratio » sinon 0.<br>
</li><li>|f| : la sortie sera « + Ratio » ou « -Ratio » suivant le signe de la source.<br>
</li><li>CB1...CB8 : courbes personnalisables, définies dans le menu « COURBES 8/12 ». Depuis le mixage, presser <b>[</b><b>MENU]</b> permet d'éditer directement la courbe. Chaque courbe peut être utilisée par plusieurs mixages, soit telle quelle, soit en inverse (« ! »), ce qui est particulièrement utile pour, par exemple, définir un différentiel global d'ailerons et volets.<br>
</li></ul></li><li>Inter : permet d'affecter un interrupteur d'activation du mixage. Le mixage est actif en permanence si aucun interrupteur n'est sélectionné.<br>
</li><li>Phase : phases de vol pour lesquelles le mixage est actif. Par défaut, toutes les phases sont sélectionnées.<br>
</li><li>Alerte: actionne une alarme sonore (1, 2 ou 3 bips répétés en continu) lorsque le mixage est actif (uniquement valable si un interrupteur est sélectionné).<br>
</li><li>Opération : définie le mode d'application du mixage sur la voie concernée.<br>
<ul><li>Ajoute : la ligne est ajoutée au résultat des lignes précédentes (mode par défaut).<br>
</li><li>Multiplie : la ligne multiplie le résultat des lignes précédentes.<br>
</li><li>Remplace : la ligne remplace toutes les lignes précédentes, à utiliser avec un interrupteur ou une phase de vol.<br>
</li></ul></li><li>Retard haut / bas : retarde l'activation / désactivation du mixage (en secondes, par défaut instantané).<br>
</li><li>Ralenti haut / bas : ralentit le changement de valeur du mixage (en secondes, par défaut instantané). Une valeur de 2 secondes signifie que la sortie du mixage mettra 2 secondes à passer de -100% à +100%.</li></ol>

<h3>Formatage des sorties (Limites) (7/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/23_1.png' />

Cet écran permet de définir, pour chaque voie (CH1...CH16), les paramètres suivants (de gauche à droite dans l'écran) :<br>
<ol><li>Offset (ou subtrim) : décale le centre de la voie.<br>Les manches peuvent être utilisés pour le régler : mettre la valeur en surbrillance, déplacer le manche de manière à mettre le servo à la position voulue, puis presser <b>[</b><b>MENU LONG]</b>.<br>
</li><li>Min/Max : butées mini / maxi (-100 / +100% à -125 / +125% si limites étendues) au-delà duquel l'ordre est écrété (d'où l'intérêt d'utiliser des dual-rate inférieur à 100% pour laisser de la marge au trims de manches et aux différents mixages pouvant s'appliquer sur la voie). Les limites servent aussi de gains de sortie, soit relatifs soit absolus (cf. ci-après).<br>
</li><li>-> / <- : sens de rotation du servo (si option <b>PPMCA</b>, sinon représenté comme "---" ou "INV").<br>
</li><li>1500 (si option <b>PPMCA</b>) : neutre de servo (en µs). Décale la course entière du servo pour corriger par exemple un mauvais centrage de palonnier. Contrairement au subtrim l'amplitude de la course n'est pas modifiée, et le décalage n'apparaît pas sur l'écran de position des servos.<br>
</li><li>^ / =  (si option <b>SYMLIMITS</b>) : détermine l'effet du subtrim.<br>
<ul><li>^ (par défaut) : décale uniquement le centre de la courbe de réponse du servo, sans déplacer les limites (gains relatifs, en rouge sur le graphique ci-dessous).<br>
</li><li>= : Décale toute la courbe (gains absolus, en bleu ci-dessous). <br>L'utilisation de « = » est indispensable dès que la voie reçoit plus d'un mixage pour conserver la linéarité de réponse de toutes les fonctions qui pilotent cette voie. Dans ce cas, l'utilisation d'un dual-rate inférieur à 100% est encore plus conseillée pour éviter un écrêtage en fin de course.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/openTx_décalages_subtrim.png' /></li></ul></li></ol>

La fonction « Trims => Offsets » transfère la position des trims de manches vers les offsets (avec prise en compte du mixeur et du formatage de manches), puis remet les trims à zéro.<br>
<br>
Lors de la sélection d'une voie, sa valeur de sortie (en µs si option <b>PPMCA</b>, sinon en %) est affichée en haut de l'écran :<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/23_3.png' />

<b>NOTA</b>

Hormis le neutre et le sens de rotation, la fonction principale des limites est de régler le gain de chaque demi-course de servo pour symétriser lesdites demi-courses (= avoir un débattement identique de part et d'autre du neutre pour une consigne donnée). Cela vaut aussi entre des servos ayant la même fonction (ex. servos d'ailerons). Bien évidemment, il convient de s'assurer sur le modèle que les servos puissent débattre intégralement sans aller en butée mécanique.<br>
<br>
<h3>Courbes et variables globales (8/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/24_1.png' />

Les courbes (de 3 à 17 points) sont utilisées par les formatages de manches ou les mixages pour définir des réactions personnalisées.<br>
<br>
Les variables globales se substituent à la valeur numérique d'un taux de mixage, de dual-rate ou d'expo. Ces variables peuvent être, au besoin, liées à une fonction associées à un interrupteur (cf. « Fonctions associées à des interrupteurs » 10/12) pour permettre leur modification en vol par un organe de commande (trim électronique ou potentiomètre). De plus, chaque variable peut avoir une valeur différente par phase de vol, ce qui peut substantiellement diminuer le nombre de mixages pour les différenciation de taux (différentiel, courbure de profil, etc.) par phase.<br>
<br>
Chaque courbe ou variable globale est utilisable par autant de fonctions que nécessaire.<br>
<br>
<h4>Pour éditer une courbe :</h4>

<ol><li>Se placer sur la ligne souhaitée avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>, la courbe correspondante apparaît.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/25_1.png' />
</li><li>Appuyer une fois sur <b>[</b><b>MENU]</b> pour l'éditer.<br>
</li><li>Appuyer sur <b>[</b><b>EXIT]</b> pour éditer le nombre de points et le type de la courbe (le signe « ' »indique que l'abscisse de chaque point est modifiable, en plus de l'ordonnée).<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/25_2.png' />
</li><li>Appuyer sur <b>[</b><b>MENU]</b> pour passer en édition des coordonnées du point (Y uniquement ou X et Y avec « ' »).<br>
</li><li>Déplacer le curseur d'un point à l'autre avec <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b>, et modifier l'ordonnée du point avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>. Si « ' », appuyer sur <b>[</b><b>MENU]</b> pour éditer le point et modifier ses coordonnées avec <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b> et <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>. <b>[</b><b>EXIT]</b> permet de sortir de l'édition pour passer au point suivant.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/25_3.png' /></li></ol>

N.B. : Quelques courbes préenregistrées sont disponibles. Pour les choisir, appuyer sur <b>[</b><b>MENU LONG]</b>

<h4>Pour modifier une variable globale (GV) :</h4>

<ul><li>Se placer sur la ligne souhaitée avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>.<br>
</li><li>Modifier sa valeur avec <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b>.</li></ul>

<h4>Pour utiliser une variable globale à à la place d'un taux:</h4>

<ul><li>Se placer sur le taux (ici un différentiel d'ailerons) à lier à une variable globale.<br>
</li><li>Appuyer une fois sur <b>[</b><b>MENU LONG]</b> pour basculer en liste de variables globales.<br>
</li><li>Sélectionner la variable globales souhaitées avec <b>[</b><b>LEFT]</b> / <b>[</b><b>RIGHT]</b>.<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/21_3.png' />
</li><li>Pour désactiver l'association du taux avec une variable globale, appuyer une fois sur <b>[</b><b>MENU LONG]</b>. La valeur réglée est bien entendu conservée.</li></ul>

<h3>Interrupteurs personnalisables (9/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/26_1.png' />

Les interrupteurs personnalisables, au nombre de 12 (IP1...IPC) sont des interrupteurs virtuels utilisant des conditions logiques pour leur activation. Comme pour les mixages, il est possible de réaliser des chaînages entre interrupteurs virtuels.<br>
<br>
Pour chaque interrupteur, les paramètres sont les suivants (de gauche à droite) :<br>
<ol><li>Condition logique :<br>
<ul><li>test : v>offset, v<offset, |v|>offset, |v|<offset d>=offset et |d|>=offset.<br>
</li><li>opérateurs logiques : ET (les deux opérandes doivent être à ON pour activer SW), OU (au moins un des deux opérandes doit à être à ON pour activer SW), OU-exclusif (un seul des deux opérandes doit à être à ON pour activer SW).<br>
</li><li>comparaison de deux sources (==, !=, >, <, >=, <=).<br>
</li></ul></li><li>Entrée testée : premier opérande d'une comparaison logique ou première source à comparer.<br>
</li><li>Valeur seuil du test : seconde opérande d'une comparaison logique ou seconde source à comparer.</li></ol>

<h3>Fonctions personnalisées (10/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/27_1.png' />

Cet écran permet de créer des fonctions personnalisées et, au besoin, de les associer à un interrupteur (physique, virtuel, activation permanente):<br>
<ol><li>Securité : forçage à une valeur prédéfinie de n'importe quelle voie CH1..CH16.<br>
</li><li>Ecolage.<br>
</li><li>Ecolage pour une seule voie (DIR / PRF / GAZ / AIL).<br>
</li><li>Trim Instant. : pour trimmer instantanément le modèle à partir de la position des manches.<br>
</li><li>Bip.<br>
</li><li>Vibreur (option <b>HAPTIC</b>).<br>
</li><li>Remise à 0 : chrono 1 ou 2, les deux chrono à la fois, données de télémesure.<br>
</li><li>Vario (option <b>AUDIO</b>).<br>
</li><li>Jouer fichier (option <b>AUDIO</b> sur carte Sky9x).<br>
</li><li>Dire valeur (option <b>VOICE</b>).<br>
</li><li>Rétroéclairage.<br>
</li><li>Modification GV1...5 (option <b>GVARS</b>): permet d'associer à une variable globale un organe de réglage (potentiomètre, trim digital, manche, etc.).</li></ol>

Les interrupteurs associés sont les suivants :<br>
<ol><li>ON : toujours actif.<br>
</li><li>Interrupteurs physiques.<br>
</li><li>Interrupteurs virtuels.<br>
</li><li>Interrupteurs momentanés.</li></ol>

<h3>Paramétrage de la télémesure (11/12)</h3>


<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/28_1.png' />

Cet écran (si l'option <b>FRSKY</b> est activée) permet le paramétrage de la télémesure FrSky, ainsi que la configuration des alarmes associées.<br>
<br>
<h4>Entrées analogiques A1 et A2:</h4>
Pour chaque entrée, il est possible de régler les paramètres suivants :<br>
<ol><li>Plage : calibre le gain de l'affichage de la tension (à régler avec un voltmètre)<br>
</li><li>Décalage : fixe le zéro de la mesure.<br>
</li><li>Deux alarmes, avec:<br>
<ul><li>le niveau de l'alarme (---, jaune, orange, rouge)<br>
</li><li>le sens de l'alarme à partir du seuil (< ou >)<br>
</li><li>la valeur du seuil<br>
Lorsqu'une valeur est modifiée, elle est immédiatement envoyée au module FrSky.</li></ul></li></ol>

<h4>Niveaux de réception (RSSI) Tx et Rx :</h4>
Même principe, il est possible de définir deux alarmes pour le niveau de réception :<br>
<ul><li>le niveau de l'alarme (---, jaune, orange, rouge)<br>
</li><li>la valeur du seuil<br>
Lorsqu'une valeur est modifiée, elle est immédiatement envoyée au module FrSky.</li></ul>

<h4>Autres mesures :</h4>
<ol><li>Proto : protocole série utilisé par le récepteur de télémesure. Les options sont : None (non utilisé), le Hub FrSky, ou le module Winged Shadow How High (il donne seulement l'altitude, mais il est plus précis).<br>
</li><li>Pales : nombre de pales de l'hélice pour l'affichage du compte tour.<br>
</li><li>Tension : entrée utilisée pour la mesure de la tension d'une propulsion électrique.<br>
</li><li>Courant : entrée utilisée pour la mesure de l'intensité d'une propulsion électrique.</li></ol>

<h4>Vario :</h4>
<ol><li>Source : type de variomètre utilisé.<br>
</li><li>Limite : définit une alarme d'altitude avec un seuil de déclenchement.</li></ol>

<h4>Affichage personnalisé des capteurs sur l'écran de télémesure :</h4>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/28_4.png' />

Il est possible d'afficher jusqu'à 8 capteurs sur l'écran de télémesure, avec les paramètres suivants:<br>
<ol><li>Source : mesure à afficher.<br>
</li><li>Min : valeur mini possible.<br>
</li><li>Max : valeur maxi possible.</li></ol>

Ces sources sont aussi utilisables pour définir des interrupteurs virtuels. Les jalons affichés sur l'écran de télémesure sont automatiquement issus des infos venant des alarmes FrSky ou des Inters virtuels. Ainsi, si vous positionnez un inter virtuel lorsque l'altitude est de 400m, vous verrez apparaître une marque à 400m.<br>
<br>
<h3>Gabarits (12/12)</h3>

<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/29_1.png' />

Les gabarits (si option <b>TEMPLATES</b>) permettent de mettre en place les mixages de base d'une configuration de modèle donnée. La navigation se fait dans l'écran, comme à l'habitude avec <b>[</b><b>UP]</b> / <b>[</b><b>DOWN]</b>, puis <b>[</b><b>MENU LONG]</b> pour activer le gabarit. Cela ajoutera le gabarit aux mixages existants du modèle courant, ou les remplacera suivant le cas.<br>
<br>
Les gabarits disponibles sont les suivants :<br>
00 : supprime tous les mixages du Mixeur.<br>
01 : 4 voies simple.<br>
02 : fonction de coupure de gaz.<br>
03 : mixages d'empennage en V (dérive / profondeur).<br>
04 : mixages d'ailes delta ou incidence intégrale (ailerons / profondeur).<br>
05 : eCCPM : mixages pour pas collectif sur hélicoptère électrique.<br>
06 : configuration hélicoptère, à utiliser en amont d'ECCPM pour réinitialiser les mixage et les courbes.<br>
07 : servo test, sur la voie 15. A mettre en entrée des voies à tester, les servos se déplaçant lentement de -100% à +100%.<br>
<br>
<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Écrans de télémesure</h2>

Ces écrans sont accessibles  (si l'option FRSKY est activée) en appuyant sur la touche <b>[</b><b>DOWN LONG]</b> depuis l'écran principal. Leur affichage dépend de la configuration réalisée dans le menu Télémesure 11/12.<br>
Le défilement des écrans est assuré par les touches <b>[</b><b>UP]</b> et <b>[</b><b>DOWN]</b> , tandis que la touche <b>[</b><b>MENU]</b> réinitialise les données de télémesure. Enfin <b>[</b><b>EXIT]</b> renvoie au menu principal.<br>
<br>
<table><thead><th> Les jauges graphiques : </th><th> Les tensions d'accu(s) </th></thead><tbody>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/03_3.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/03_4.png' /> </td></tr>
<tr><td> Les données de l'altimètre, compte-tours... </td><td> Les données GPS :      </td></tr>
<tr><td> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/03_5.png' /> </td><td> <img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/03_6.png' /> </td></tr></tbody></table>

Sont affichées ici la latitude, la longitude et l'altitude du modèle, ainsi que la distance du modèle au pilote. En réinitialisant les données de télémesure, la première position GPS reçue devient alors la position de départ pour les futurs calculs.<br>
<br>
<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Exemples de mixages et bonnes pratiques associées</h2>

<h3>Fonction coupe-gaz</h3>
<ol><li>Se positionner sur la ligne du mixage de base utilisant l'entrée « gaz ».<br>
</li><li>Presser <b>[</b><b>MENU]</b> pour sélectionner la ligne, <b>[</b><b>RIGHT LONG]</b> pour la dupliquer en-dessous, puis éditer le mixage avec <b>[</b><b>MENU LONG]</b>.<br>
</li><li>Changer la source par « MAX », le ratio par -100 et sélectionner un interrupteur (ou une phase de vol) pour son activation.<br>
</li><li>Mettre Remplace dans le champ « Opération ».<br>
</li><li>Sortir de l'édition avec <b>[</b><b>EXIT]</b>. Le résultat est le suivant :<br><br><img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/22_2.png' />
CH3 est maintenant pilotée par deux mixages :<br>
</li></ol><ul><li>le premier transmet la valeur du manche des gaz et est actif tout le temps.<br>
</li><li>le second remplace le premier par la valeur de -100% quand l'interrupteur GAZ est à ON.</li></ul>

<h3>Activation d'un chauffe-bougie lorsque les gaz sont <20%</h3>
<ol><li>Dans « Interrupteurs personnalisés » :<br>
<ul><li>mettre en surbrillance SW1.<br>
</li><li>sélectionner la condition v<ofs.<br>
</li><li>sélectionner Gaz comme source.<br>
</li><li>choisir un offset de  -80%.<br>
</li></ul></li><li>Dans « Mixeur », créer deux mixages sur la voie du chauffe-bougie :<br>
<ul><li>activation : source = MAX, ratio = +100%, interrupteur = SW1.<br>
</li><li>désactivation :  source = MAX, ratio = -100%, interrupteur = !SW1.</li></ul></li></ol>

Rappel : ce second mixage est indispensable car, en l'absence d'ordre, la sortie d'une voie est de 0% (position médiane) et non -100% (butée basse).<br>
<br>
<h3>Mixages delta / incidence intégrale (avec différentiel global d'ailerons)</h3>
<ol><li>Dans la voie de l'aile(ron) gauche :<br>
<ul><li>créer une ligne de mixage avec source = Prof, ratio = +100%.<br>
</li><li>créer une ligne de mixage avec source = Ail, ratio = +100%, diff = GVx.<br>
</li></ul></li><li>Dans la voie de l'aile(ron) droit :<br>
<ul><li>créer une ligne de mixage avec source = Prof, ratio = +100%.<br>
</li><li>créer une ligne de mixage avec source = Ail, ratio = -100%, diff = GVx.</li></ul></li></ol>

Rappel : les débattements des fonctions ailerons et profondeur se différencient indépendamment grâce aux dual-rates propres à chaque manche.<br>
<br>
<h3>Différentiel global de voilure (ailerons, volets, dérive, etc.)</h3>
<ol><li>Avec une courbe 3 points (solution 1) :<br>
<ul><li>dans « Mixeur », créer une ligne de mixage sur la voie de la gouverne 1.<br>
</li><li>l'éditer, mettre ratio = +100% et activer une courbe à 3 points (pour 20% de différentiel, mettre : -80% (par ex.), 0%, +100%).<br>
</li><li>créer une ligne de mixage sur la voie de la gouverne 2.<br>
</li><li>l'éditer, mettre ratio = 100% et activer la courbe précédente en inverse (ex : !CB).<br>
</li><li>pour modifier le différentiel, éditer la courbe et modifier la valeur de -80%.<br>
</li></ul></li><li>Avec une variable globale (solution 2) :<br>
<ul><li>dans « Mixeur », créer une ligne de mixage sur la voie de la gouverne 1.<br>
</li><li>l'éditer, mettre ratio = +100% et différentiel = GV1.<br>
</li><li>créer une ligne de mixage sur la voie de la gouverne 2.<br>
</li><li>l'éditer, mettre ratio = -100% et différentiel = GV1.<br>
</li><li>pour modifier le différentiel, éditer la valeur de GV1 ou, encore mieux, lier GV1 à un potentiomètre (via une fonction associées à un interrupteur) pour régler sa valeur directement en vol.</li></ul></li></ol>

En cas de besoin de différencier par phase de vol le différentiel, dupliquer les mixages (avec une courbe ou un variable dédiée à chaque paire) et les lier chacun à une phase de vol dédiée. Ou, encore mieux avec les cartes mères d'upgrade, utiliser les variables globales différenciées par phase.<br>
<br>
<h3>Fonction courbure d'aile (dynamique (snap-flap) + statique) + AF pour quadroflap</h3>
<ol><li>Dans une voie inutilisée (ex. CH10), créer la fonction « courbure » :<br>
<ul><li>créer une ligne de mixage avec source = Prof, ratio = xx% (ou GVx), trim et D/R = OFF.<br>
</li><li>ajouter une ligne de mixage avec source = MAX, ratio = xx% (ou GVx). Ou, seconde solution très élégante, avec source = Trim de gaz, ratio = 100%.<br>
</li><li>si besoin, dupliquer ces lignes pour les différencier par phase de vol (inutile avec Trim).<br>
</li></ul></li><li>Dans une voie inutilisée (ex. CH11), créer la fonction « courbure + AF » pour volets :<br>
<ul><li>créer une ligne de mixage avec source = CH10, ratio = 100%.<br>
</li><li>créer une ligne de mixage avec source = Gaz, ratio = xx%.<br>
</li></ul></li><li>Dans une voie inutilisée (ex. CH12), créer la fonction « courbure + AF » pour aileron :<br>
<ul><li>créer une ligne de mixage avec source = CH10, ratio = 50% (couplage classique).<br>
</li><li>créer une ligne de mixage avec source = Gaz, ratio = xx%.<br>
</li></ul></li><li>Dans les voies de volets :<br>
<ul><li>créer une ligne de mixage avec source = Aile, ratio = +/-50%, diff = GVy<br>
</li><li>créer une ligne de mixage avec source = CH11, ratio = 100%.<br>
</li></ul></li><li>Dans les voies d'ailerons :<br>
<ul><li>créer une ligne de mixage avec source = Aile, ratio = +/-100%, diff = GVy<br>
</li><li>créer une ligne de mixage avec source = CH12, ratio = 100%.</li></ul></li></ol>

Le principe est de grouper les entrées par fonction plutôt que de toutes les mettre directement sur les voies de destination. Le bénéfice est double : le nombre de mixage est réduit, tandis que les réglages sont grandement simplifiés (une seule valeur par fonction est plus rapide -et logique- à régler que plusieurs fois la même valeur dupliquée dans différents mixages).<br>
<br>
Une autre bonne pratique, qui en découle consiste -à chaque fois que cela est possible- à considérer les taux de mixage comme des activations par défaut, c'est à dire avec des taux de +/-100%. Le réglage des débattements par fonction étant confié aux formatages de manches, via les dual-rate.<br>
<br>
Cet exemple complexe peut évidemment être simplifié pour des besoins plus simples, (deux ailerons full-span, pas de courbure statique, etc.), avec potentiellement en conséquence un seul étage de fonction au lieu de deux.<br>
<br>
<h3>Multi-affectation du manche de gaz AF+Gaz sur moto-planeur</h3>
<ol><li>Dans le mixage de la voie de gaz :<br>
<ul><li>utiliser une courbe 3pts' : (-100%,-100%), (+25%,-100%), (+100%,+100%).<br>
</li></ul></li><li>Dans le mixage de la voie/fonction d'AF :<br>
<ul><li>utiliser une courbe 3pts' : (-100%,+100%), (-25%,-100%), (+100%,-100%).</li></ul></li></ol>

Ainsi, le manche de gaz permet de commander de manière proportionnelle les fonctions gaz et aérofreins, le tout sans avoir à le lâcher pour manoeuvrer un interrupteur ou un potentiomètre, Le découpage se fait en trois tiers :<br>
<ul><li>Tiers inférieur : AF.<br>
</li><li>Tiers central : zone neutre.<br>
</li><li>Tiers supérieur : gaz.<br>
Pour la sécurité d'utilisation, il n'est pas inutile d'ajouter sur chaque voie un mixage (MAX -100%, Remplace) lié à un interrupteur ou une phase de vol. Ou utiliser une fonction de sécurité liée à un interrupteur.</li></ul>

<h3>Optimiser l'utilisation de la course mécanique d'un servo de volet ou d'aileron utilisé en AF</h3>
<ol><li>Dans le menu limites :<br>
<ul><li>décentrer volontairement les servos (d'une valeur identique) avec le sub-trim, par ex. de 25% vers le bas pour les volets ou 25% vers le haut pour les ailerons.<br>
</li></ul></li><li>Sur le modèle :<br>
<ul><li>décaler le palonnier pour remettre la gouverne au neutre.</li></ul></li></ol>

La course mécanique de chaque servo est ainsi répartie d'une manière adaptée au besoin en débattement des gouvernes. En effet, les volets se baissent généralement bien plus qu'ils ne se lèvent, et inversement pour les ailerons. Attention, cela ne fonctionne qu'avec l'option « = » (utilisée pour chaque servo).<br>
<br>
<h3>Mixages pour plateau cyclique 120° « from scratch » (sans l'option <b>HELI</b>)</h3>
<ol><li>Sur une voie libre, fonction courbe de pas (ex. CH10) :<br>
<ul><li>une ligne de mixage avec source = Gaz, ratio = +100%, courbe.<br>
</li></ul></li><li>Sur la voie du servo frontal :<br>
<ul><li>une ligne de mixage avec source = Prof, ratio = +100%.<br>
</li><li>une ligne de mixage avec source = CH10, ratio = +100%.<br>
</li></ul></li><li>Sur la voie du servo latéral 1 :<br>
<ul><li>une ligne de mixage avec source = Prof, ratio = -50%.<br>
</li><li>une ligne de mixage avec source = Ail, ratio = +86%.<br>
</li><li>une ligne de mixage avec source = CH10, ratio = -100%.<br>
</li></ul></li><li>Sur la voie du servo latéral 2 :<br>
<ul><li>une ligne de mixage avec source = Prof, ratio = -50%.<br>
</li><li>une ligne de mixage avec source = Ail, ratio = -86%.<br>
</li><li>une ligne de mixage avec source = CH10, ratio = -100%.</li></ul></li></ol>

Le calcul des ratios se fait par trigonométrie, en considérant comme débattement de référence celui qui donne le plus petit débattement angulaire du plateau pour un débattement de servo donné (= servo frontal en fonction profondeur).<br>
<br>
<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Introduction à companion9x</h2>

Companion9x est le logiciel (sous Windows, Linux ou  Mac) associé à openTx, permettant de :<br>
<ul><li>télécharger les firmwares openTx avec les options de compilation souhaitées<br>
</li><li>lire / écrire la mémoire flash de la radio (firmware)<br>
</li><li>lire / écrire la mémoire eeprom de la radio (mémoires modèles)<br>
</li><li>créer / modifier des fichiers eeprom (effacer, ajouter, glisser / déposer depuis un autre fichier)<br>
</li><li>créer / modifier des mémoires de modèles dans des fichiers eeprom<br>
</li><li>comparer deux programmations de modèles<br>
</li><li>simuler le fonctionnement de la radio et de la programmation d'un modèle</li></ul>

Ecran principal :<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/c9x_main_window.png' />

Ecran de paramétrage des firmwares, accessible depuis le menu « Fichier » (passer la souris sur les cases permet d'afficher une étiquette explicative de l'option) :<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/c9x_preferences.png' />

Ecran de programmation d'un modèle (structure identique à celle d'openTx), accessible en double-cliquant sur le nom du modèle dans la liste de l'eeprom :<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/c9x_mixer_screen.png' />

Un très bel écran d'assistant de configuration automatique de modèles (gabarit) :<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/c9x_model_wizard.png' />

L'écran de simulation de la radio, on peut même naviguer dans le soft comme sur la vraie radio (!) :<br>
<br>
<img src='https://opentx.googlecode.com/svn/wiki/images_openTx_manual_FR/c9x_simu.png' />

<a href='http://code.google.com/p/opentx/wiki/OpenTx_Manual_FR#Table_des_mati%C3%A8res'>Retour à la table des matières</a>

<h2>Pour conclure</h2>

Si ce travail vous plaît et vous rend service, n'hésitez surtout pas à en parler autour de vous. A défaut de posséder la radio la plus chère ou la plus belle du marché, vous pourrez sans complexe revendiquer d'être l'heureux utilisateur d'une radio économique, fiable, et permettant de programmer tout ce qu'il est possible d'imaginer. Le tout avec une rigueur, une efficacité et une simplicité sans concurrence.<br>
<br>
Et, justement, une programmation aussi simple et logique que puissante ne devrait-elle pas être le premier objectif d'une radiocommande... programmable ? A méditer...