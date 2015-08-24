<a href='Hidden comment: 

'></a>

# Historique des versions d'openTx #



## 2923 / 08 Jan 2014 ##

### [Cartes ARM ] ###
  * Correction d'un bug pouvant causer le blocage de l'audio
  * Support des manches d'Aurora corrigé

### [FrSky Taranis] ###
  * Support du DSM2
  * Support pour le GPS S.PORT
  * Correction d'un bug pouvant causer le blocage de l'audio
  * Correction d'un bug pouvant causer la corruption de valeur de télémétrie
  * Alarmes A2 réactivées en mode D16 pour le capteur X8R2Analog
  * L'Alarme de télémétrie perdue n'est plus déclenchée lors d'une RAZ de la télémétrie


---


## 2834 / 29 Oct 2013 ##

### [Tous] ###
  * Correction d'un bug dans le mixeur lors de l'utilisation du ralenti avec un mix type Remplace
  * Avertissement de changement des variables globales supprimé
  * Inters virtuels remis à 0 lors d'un "Réinitialiser Vol"
  * Lecture vocale de l'altitude sans décimale quand >= 10m

### [Cartes avec SD] ###
  * Vérification de la longueur des chemins d'accès


---


## 2768 / 20 Sep 2013 ##

### [Tous] ###
  * Nom de modèle mal affiché après déplacement/copie/restauration

### [stock] ###
  * Inters personnalisés comparant un chrono avec une valeur fixe ne fonctionnaient pas (uniquement si pas de modif télémesure)

### [Cartes avec SD] ###
  * Corrections dans la fonction de log
  * Fenêtre de confirmation pour le formatage de la carte SD

### [FrSky Taranis] ###
  * Photo du modèle pas rechargée après déplacement/copie/restauration/effacement


---


## 2751 / 01 Sep 2013 ##

### [Tous] ###
  * Correction de traductions (FR, IT, PT)


---


## 2746 / 30 Aou 2013 ##

### [Tous] ###
  * Limites maintenant [-125:0] et [0:125] au lieu de [-125:25] and [-25:125]
  * Le rétroéclairage est maintenant activé par toutes les commandes au lieu des manches uniquement
  * Correction d'un bug dans les modèles de courbes

### [stock] ###
  * Correction d'un bug de calibration de batterie
  * Les inters THR and AIL peuvent maintenant être connectés au 14051 (modif télémesure)
  * Le signal PPM du canal 1 était tronqué

### [Cartes avec SD] ###
  * Fichiers son par défaut pour les modes de vol: /SOUNDS/(lang)/modelname/fpname-ON.wav et /SOUNDS/(lang)/modelname/fpname-OFF.wav

### [FrSky Taranis] ###
  * La tension de récepteur n'était pas affichée sur l'écran d'accueil si VFAS ou CELS étaient choisis
  * Les GVARS peuvent maintenant faire référence aux GVARS des autres phases de vol
  * Correction de bugs pour l'altitude et le vario
  * PPM\_UNIT=PREC0 / US pris en compte dans le moniteur de canaux
  * DJT supprimé de la liste des protocoles et no de récepteur caché si le protocole n'est pas D16


---


## 2688 / 28 Jul 2013 ##

### [stock] ###
  * Correction d'un bug avec les unités impériales

### [gruvin9x] ###
  * Correction d'un bug avec les unités impériales
  * Correction d'un bug audio

### [Cartes avec SD] ###
  * Logs de télémesure maintenant séparés par jour


---


## 2667 / 25 Jul 2013 (Taranis uniquement) ##

### [FrSky Taranis] ###
  * Réglage de la luminosité du rétroéclairage
  * Unités du SWR supprimées (audio)
  * Copier/coller/effacer pour les inters personnalisés et fonctions spéciales


---


## 2647 / 21 Jul 2013 ##

### [Tous] ###
  * Correction d'un bug dans le mixeur quand une ligne de type Remplacer avait un paramètre Retard bas >0
  * Correction d'un bug dans le calcul des inters perso dépendant d'autres inters persos
  * Correction de l'affichage des timers en négatif

### [Cartes avec SD] ###
  * Nouvelles valeurs ajoutées aux logs, correction pour certains numbres négatifs

### [Cartes ARM ] ###
  * Toutes les tailles de police supportent maintenant les caractères spéciaux spécifiques à chaque langue
  * Les sources inutilisées (p.ex. canaux vides) n'apparaissent plus dans la liste des sources

### [FrSky Taranis] ###
  * Correction d'un bug dans le décodage de la télémétrie
  * Le point central des gâchettes est maintenant pris en compte dans la calibration


---


## 2604 / 13 Jul 2013 (Taranis uniquement) ##

### [FrSky Taranis] ###
  * Ajout d'un réglage du contraste

## 2590 / 8 Jul 2013 (Taranis uniquement) ##

### [FrSky Taranis] ###
  * Première version officielle!


---


## 2491 / 24 Juin 2013 ##

### [Tous] ###
  * Jouer Son possède maintenant une option de répétition
  * FAI mode ajouté (désactive la télémesure sauf A1/A2/RSSI pour les concours)
  * Les délais de mixeurs s'appliquent maintenant aussi aux inters 3 positions
  * RLes alarmes RSSI par défaut correspondent maintenant aux valeurs recommandées de 45 / 42

### [stock] ###
  * Economies de flash
  * Sons de descente du vario désactivés
  * Fichiers audio renumérotés (voir [ici](http://openrcforums.com/forum/viewtopic.php?f=45&t=3706#p54008))

### [sky9x] ###
  * Mixeur audio: Plusieurs sons peuvent maintenant être lus en même temps et superposés, les bips n'interrompent et n'effacent plus les annonces vocales en cours et en attante. Noter que les fichiers sons doivent maintenant avoir une fréquence d'échantillonnage de 8, 16 ou 32kHz, et devront probablement être remplacés.


---


## 2413 / 22 Mai 2013 ##

### [Tous] ###
  * L'écran de calibration apparaît automatiquement après un formatage d'EEPROM
  * Défilement circulaire dans les menus popup

### [stock] ###
  * Plus d'options (novario / nogps / nogauges)
  * Economies de flash
  * Mise à jour de la librairie Mavlink par Rienk

### [sky9x] ###
  * La langue de l'audio peut maintenant être sélectionnée dans les réglages radio. Noter qu'il est nécessaire de déplacer les fichiers son dans des sous-répertoires du dossier SOUNDS (SOUNDS/en pour l'anglais, idem avec fr, it, de, pt, se, cz)
  * Plus de réglages pour le 2e port PPM


---


## 2215 / 05 Avr 2013 ##

### [Tous] ###
  * Nouvelle option AUTOSOURCE, permet de sélectionner les sources de mixages en bougeant la commande désirée

### [stock] ###
  * Tous les fichiers sons renommés pour augmenter le nombre de sons personnalisés disponibles, et permettre la lecture de fichiers en séquence à l'aide de PlayTrack(GVAR) et Adjust(GVAR)

### [gruvin9x] ###
  * Possibilité d'utiliser le BEEPER en même temps que le SPEAKER.

### [sky9x] ###
  * Correction d'un blocage de l'audio avec la fonction spécial Musique si aucun fichier n'était sélectionné
  * Le choix des unités métriques/impériales est maintenant un réglage radio et plus une option de compilation
  * Possibilité d'utiliser le BEEPER en même temps que le SPEAKER.
  * Nouveau menu de remise à zéro des timers/données de télémesure
  * Sons du vario améliorés
  * Dossiers de la carte SD renommés, "9XSOUNDS" devient "SOUNDS" etc, attention à bien renommer vos dossiers!

### [FrSky Taranis] ###
  * Bien trop de choses pour faire une liste!


---


## 2129 / 21 Mar 2013 ##

### [Tous] ###
  * Réimplémentation du support de l'encodeur rotatif
  * Nouvelle fonction d'inter personnalisé v1==x (== signifiant environ égal)
  * Nouvelle fonction d'inter personnalisé Timer (venu d'er9x)
  * Les inters personnalisés ont maintenant une entrée ET suppléàmentaire
  * Liste des sources réprganisées pour permettre la future option EXTRA\_3POS pour un 2e unterrupteur 3 positions
  * Précision du graphique de gaz améliorée
  * Ecran des fonctions spéciales réarrangé
  * Nouvelle fonction spéciale Lire 2 (pas sur ARM)
  * Réglage de répétition pour les fonctions de lecture volcale
  * Le décompte du timer chaque minute est maintenant parlé
  * Gabarits hélico et coupure gaz corrigés
  * Tension d'accu radio ajoutée à la liste des valeurs de télémesure
  * Possibilité de désactiver les sons du vario en descente
  * Graphique de batterie radio
  * "Ajuster GVAR" réimplémenté (4 modes: valeur numérique, source, une autre GVAR ou incrémentation +1/-1, longue pression sur MENU pour changer de mode)
  * Jouer Fichier peut maintenant être une GVAR
  * Les bips de compte à rebours et de minute sont maintenant indépendants pour les 2 timers et pour chaque modèle
  * Longueur de trame PPMmaintenant ajustée par défaut à une valeur sûre lors du changement de nombre de canaux (peut toujours être changée après).
  * Ecrans de télémesure améliorés (chaque élément a son label)
  * Ratio et décalage des mixeurs peuvent mantenant aller jusqu'à +/-245%
  * Télémesure JETI corrigée

### [stock] ###
  * ~500bytes de flash économisés, merci Andreas!
  * La durée de la pression longue sue les touche est rallongée
  * Calcul du mixeur environ 25% plus rapide

### [Atmega 128] ###
  * 6 phases de vol au lieu de 5
  * 16 expos au lieu de 14
  * 15 inters pers au lieu de 12
  * 24 fonctions spéciales au lieu de 16
  * Queue d'annonces vocales à 16 éléments au lieu de 8
  * Calcul du mixeur environ 25% plus rapide

### [gruvin9x] ###
  * 6 phases de vol au lieu de 5
  * 16 expos au lieu de 14
  * 15 inters pers au lieu de 12
  * 24 fonctions spéciales au lieu de 16
  * Calcul du mixeur environ 25% plus rapide

### [sky9x] ###
  * La carte SD n'est pas montée en cas de reboot intempestif
  * Amélioration de la génération des sons
  * Réglage du nombre de pas de l'encodeur rotatif


---


## 1947 / 10 Fév 2013 ##

### [Tous] ###
  * Alerte batterie faible moins insistante
  * Options DSM plus claires
  * Support du vario dans les données de télémesure
  * La calibration des potentiomètres ne tient plus compte que des extrémités

### [stock] ###
  * Support de l'encodeur rotatif

### [9XR] ###
  * Support ajouté

### [sky9x] ###
  * Le bouton de l'encodeur rotatif peut être utilisé pour quittancer une alarme
  * Plage de mesure de courant étendue
  * Support des fichiers wav s16le


---


## 1692 / 28 Nov 2012 ##

### [stock] ###
  * Optimisations mémoire
  * Correction du délai d'extinction du rétroéclairage et d'inactivité

### [sky9x] ###
  * Correction d'un bug empêchant la sélection de fichiers sons dans les fonctions pers.


---


## 1670 / 22 Nov 2012 ##

### [stock] ###
  * Optimisations mémoire
  * Optimisations du rafraîchissement d'écran
  * Diminution de la latence manche -> servo
  * Correction d'une instabilité avec le protocole DSM2

### [gruvin9x] ###
  * Correction d'un redémarrage lors du changement de protocole
  * Correction d'un bug lors de l'archivage / restauration de modèles sur carte SD

### [sky9x] ###
  * Navigation par encodeur rotatif améliorée


---


## 1641 / 18 Nov 2012 ##

### [Pour tous] ###
  * Traduction allemande complète

### [stock] ###
  * Optimisations mémoire

### [gruvin9x] ###
  * Corrections de bugs


---


## 1563 / 9 Nov 2012 ##

### [Pour tous] ###
  * **Nouveau format d'EEPROM (212), mise à jour par companion9x nécessaire**
  * Nouvelle fonction GVARS, variables globales pouvant être attribuées à la place d'une ou plusieurs valeurs numériques et ajustables en vol. Différenciées par phase de vol sauf pour carte et processeur d'origine.
  * Affichages de télémesure plus flexibles, les 2 écrans peuvent maintenant afficher au choix des valeurs numériques ou une visualisation par barres.
  * Les barres en question sont affichées avec une merillerue précision
  * [voix] 1 seule décimale énoncée au lieu de 2
  * Réorganisation du menu de configuration radio
  * Graphique des gaz remis à zéro au changement de modèle

### [stock] ###
  * Optimisations mémoire

### [atmega 128 sur carte d'origine] ###
  * Support officiel ajouté!
  * 4k (le double) de mémoire de modèles, 128k (le double aussi) de mémoire flash, toutes les options sont ainsi utilisables simultanément, quelques graphiques sympas, et support des GVARs par phase avec nom

### [gruvin9x] ###
  * DSM2=PPM corrigé

### [sky9x] ###
  * Conversion automatique de l'EEPROM de la version précédente à l'actuelle (212->213)
  * Jusqu'à 3 affichages de télémesure
  * Lecture de musique de fond
  * Support du coprocesseur (Date/Heure actuellement)
  * Listes de modèles sur carte SD et éléments de la liste des fonctions personnalisées triés par ordre alphabétique


---


## 1439 / 29 Sep 2012 ##

### [Pour tous] ###
  * WSHH disponible comme source pour le variomètre audio
  * Bug de l'alarme d'inactivité > 10min corrigé

### [stock] ###
  * Corrections pour la gesion de la voix
  * Optimisations mémoire

### [gruvin9x] ###
  * DBLKEYS corrigées
  * Améliorations du logging sur carte SD
  * Fonction de formatage de la carte SD ajoutée ([MENU LONG] sur le titre)
  * Tri alphabétique des fichiers sur la carte SD
  * Les timers sont mémorisés à l'extinction

### [sky9x] ###
  * Lecture / écriture de la carte SD comme disque amovible par USB!
  * Améliorations du logging sur carte SD
  * Fonction de formatage de la carte SD ajoutée ([MENU LONG] sur le titre)
  * Informations sur la carte SD ajoutées
  * Tri alphabétique des fichiers sur la carte SD
  * Support des encodeurs rotatifs
  * Les alarmes de consommation de batterie et température remplacent maintenant la tension sur l'écran principal
  * Les timers sont mémorisés à l'extinction


---


## 1361 / 04 Sep 2012 ##

### [Pour tous] ###
  * Annonces vocales anglaises améliorées
  * Touches / trims affichés correctement sur l'écran DIAG
  * DBLKEYS plus réactifs
  * L'Alarme d'inactivité fonctionne maintenant aussi sur les écrans d'alerte au démarrage
  * 3 nouveaux sons courts disponibles dans les inters de fonction: Beep1 .. Beep3
  * Gabarit de coupure de gaz remplacé par coupure de gaz avec maintien
  * Avertissement sur l'écran d'accueil en cas de redémarrage intempestif du soft

### [sky9x] ###
  * Alarme de température
  * Alarme de consommation (mAh)
  * Support pour plus de 32000 fichiers dans l'explorateur de fichiers pour carte SD


---


## 1335 / 30 Aoû 2012 ##

### [Pour tous] ###
  * Choix libre des phases de vols pour lesquelles chaque expo et mixeur doit être activé
  * Limites symétriques (option SYMLIMITS). Voir manuel.
  * Amélioration du support des annonces vocales. Langues EN, FR, IT, CZ
  * Possibilité d'utiliser l'ordre brut du manche dans les mixeurs (sans tenir compte du DR/expo)
  * Test de portée pour le protocole DSM
  * Nouvelles fonctions pour les interrupteurs personnalisés: d>ofs (différence entre 2 valeurs > valeur fixe), |d|>ofs<br>Exemple d'utilisation: Avertissement lors d'un changement de tension batterie de 0.1V, ou lorsque l'altitude change de plus de 10m<br>
<ul><li>Les inters de fonction Ecolage et Trim instantané peuvent maintenant être activés/désactivés par case à cocher<br>
</li><li>L'inversion du canal de gaz sur l'écran LIMITES demande confirmation<br>
</li><li>Alarme d'inactivité plus fréquente (5 sec)<br>
</li><li>Affichage de la polarité PPM corrigé<br>
</li><li>Comptage de l'EEPROM libre corrigé<br>
</li><li>Correction de la fonction vibreur<br>
</li><li>[MENU long] sur un inter dans les inter de fonctions bascule entre le switch et son équivalent momentané (THR <=> THRm, !THR <=> !THRm)<br>
</li><li>Pas de 1% dans le différentiel au lieu de 2%<br>
</li><li>Nouvelle option DBLKEYS, lors de l'édition de paramètres numériques:<br>
<ul><li>right/left => inverser la valeur<br>
</li><li>up/down => remise à 0<br>
</li><li>up/right => +100<br>
</li><li>down/left => -100<br>
</li></ul></li><li>Les trims ne s'arrêtent plus définitivement au passage à 0, mais marquent une courte pause<br>
</li><li>Correction du calcul de puissance quand Courant = A1 ou A2<br>
</li><li>Correction des gabarits pour tenir compte du nouveau système de courbes<br>
</li><li>RSSI TX et RX déplacés avant A1 et A2 dans la liste des éléments de télémesure. <b>Nécessite un ajsutage manuel des modèlss existants!</b>
</li><li>Les inters personnalisés dépendants des valeurs de télémesure sont désactivés si aucune donnée n'est reçue<br>
</li><li>Correction du fonctionnement des trims dans les mixages utilisant des courbes et du différentiel<br>
</li><li>L'option AUTOSWITCH correspond maintenant à la position physique des inters<br>
</li><li>Les Expos/DR permettent maintenant de choisir une courbe à la place de l'expo</li></ul>

<h3>[stock]</h3>
<ul><li>Réglage du volume pour la voix</li></ul>

<h3>[gruvin9x]</h3>
<ul><li>DSM2 corrigé<br>
</li><li>PPM16 corrigé<br>
</li><li>Bips de l'encodeur rotatif corrigés</li></ul>

<h3>[sky9x]</h3>
<ul><li>Le bootloader USB n'est lancé que si la radio est éteinte à la connexion du câble<br>
</li><li>Corrections pour l'audio<br>
</li><li>Corrections pour la carte SD</li></ul>

<hr />

<h2>1195 / 1 Aoû 2012</h2>
<h3>[Pour tous]</h3>
<ul><li>Nouveau système de courbes, les courbes peuvent chacune avoir à choix 3, 5, 9 ou 17 points, soit avec une abscisse fixe (ex. 5pt), soit avec une abscisse personnalisable (ex. 5pt')<br>
</li><li>Les courbes peuvent être complêtement désactivées (option NOCURVES)</li></ul>

<h3>[stock]</h3>
<ul><li>Support du rétroéclairage de la carte SmartieParts 2.2 (option SP22)<br>
</li><li>Support de la voix (expérimental)</li></ul>

<h3>[gruvin9x]</h3>
<ul><li>Support de la voix</li></ul>

<h3>[sky9x]</h3>
<ul><li>Log des données de télémesure sur carte SD</li></ul>

