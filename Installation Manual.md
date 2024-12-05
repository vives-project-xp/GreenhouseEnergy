# Greenhouse Battery: Installation Manual

## Inhoudstafel

1. [Benodigdheden](#1-benodigdheden)  
    1.1 [Materialen](#11-materialen)  
    1.2 [Gereedschap](#12-gereedschap)  
    1.3 [3D Prints](#13-3d-prints)  
2. [Batterij Pack](#2-batterij-pack)  
    2.1 [Testen van Batterijen](#21-testen-van-batterijen)  
    2.2 [Opladen van de Batterijen](#22-opladen-van-de-batterijen)  
    2.3 [Lekstroom Test](#23-lekstroom-test)  
    2.4 [3D Prints Voorbereiden](#24-3d-prints-voorbereiden)  
    2.5 [Cel Configuratie](#25-cel-configuratie)  
    2.6 [Puntlassen](#26-puntlassen)  
    2.7 [BMS Bevestigen](#27-bms-bevestigen)  
    2.8 [PVC Shrink Wrap](#28-pvc-shrink-wrap)  
3. [MPPT Charge Controller](#3-mppt-charge-controller)  
4. [Data Collectie](#4-data-collectie)  
    4.1 [Protocol](#41-protocol)  
    4.2 [Configureren van Arduino IDE](#42-configureren-van-arduino-ide)  
    4.3 [Code voor ESP32](#43-code-voor-esp32)  

---

## 1. Benodigdheden

### 1.1 Materialen

| Naam                      | Hoeveelheid | Prijs/eenheid | EAN nummer          |
|---------------------------|-------------|---------------|---------------------|
| Samsung INR18650-35E      | min 13, max 260 | €2.99       | 9009316342928      |
| Nikkelstrip               | 1m          | €2.95         | 7417940525969      |
| JK Smart BMS              | 1           | €64.20        | 7417940530888      |
| MPPT Charger              | 1           | €88.53        | 8719076043027      |
| Zwarte Kabel 10mm²        | 2m          | €2.38         | 1524488 - 62       |
| Rode Kabel 10mm²          | 2m          | €2.64         | 602648 - 62        |
| Zwarte Kabel 16mm²        | 2m          | €3.64         | 602660 - 62        |
| Rode Kabel 16mm²          | 2m          | €3.64         | 602650 - 62        |
| Zekering 48v 20a          | 1           | €0.86         | 2298-APT-20A-ND    |
| Zekering 48v 30a          | 1           | €0.86         | 2298-APT-30A-ND    |
| Jumper kabel              | 10          | €0.02         | Generisch          |
| Logic Level Shifter       | 1           | €3.12         | BOB12009           |
| ESP32-C3-DevkitM-1        | 1           | €6.00         | 1965-ESP32-C3-DEVKITM-1-ND |
| Mini Micro JST 2,0 mm 4-poliger stekker | 1 | €0.4     | Generisch          |
| PVC shrinkwrap            | 300mm diameter, 3m lang | €16.99 | B0DMNPQVVZ |

### 1.2 Gereedschap

- **Multimeter**: bv. Strex Digitale Multimeter - AC / DC  
- **Puntlasser**: bv. WANGCL 18650 battery spot welding  
- **Batterijlader**: bv. IMREN 18650 Batteries Battery Charger  
- **Striptang**  
- **Kniptang**  
- **Soldeerbout**: bv. YIHUA 929D-V Electric desoldering iron  
- **3D printer**: bv. Creality Ender 3  
- **Schuurpapier/Dremel**: bv. Dremel 3000 Multi Tool 130 W  
- **Heteluchtpistool**: bv. AIUNAOM Thermische heteluchtpistool  

### 1.3 3D prints

[STL Bottom](https://github.com/vives-project-xp/GreenhouseEnergy/blob/main/Design/Brackets%203D/Bottom_volledig.stl)
[STL Top](https://github.com/vives-project-xp/GreenhouseEnergy/blob/main/Design/Brackets%203D/Top_Volledig.stl)

## 2. Batterij Pack

### 2.1 Testen van Batterijen

Vooraleer je de INR18650-35E in je project kunt verwerken dien je ze grondig te testen op defecten, let hierbij op:

- **Corrosie op metalen oppervlakken**:  
  Deze kunnen indicatief zijn dat er interne corrosie aanwezig is, wat de batterij brandgevaarlijk maakt.
- **Beschadiging van het omhulsel**:  
  Op lange termijn is er een grotere kans op corrosie en verdere defecten.

Gebruik je digitale multimeter om de spanningen van iedere INR18650-35E te meten. De waarden zouden tussen de **3.3V en 4.2V** moeten liggen. Meet je minder dan 3.3V, dan is de cel ‘undercharged’. Er bestaat een kans om deze cel nog te redden door die met een kleine stroom (max 300mA) op te laden, onder toezicht.

### 2.2 Opladen van de Batterijen

Iedere INR18650-35E cel dient opgeladen te worden naar dezelfde (maximale spanning) vooraleer er kan gepuntlast worden.  
Gebruik hiervoor je batterijlader ingesteld op een stroom van max 1A.

### 2.3 Lekstroom Test

Laat de opgeladen batterijen 14-21 dagen onaangeroerd liggen en meet opnieuw de spanningen van iedere INR18650-35E cel.  
Is deze gezakt van **4.20V naar 4.00V** of lager, dan heeft deze cel een te grote lekstroom en gebruik je deze best niet voor je batterij pack.

### 2.4 3D prints voorbereiden

De voorziene STL hebben de exacte afmetingen voor je batterij, maar er is een grote kans dat er tijdens het printen afwijkingen zijn gecreëerd.  
Gebruik hiervoor wat schuurpapier, een vijl en/of dremel om hier en daar wat filament weg te schuren.  

**Aanpak:**  
- Gebruik een afgekeurde cel om iedere uitsparing te testen.  
- Markeer welke uitsparingen breder moeten gemaakt worden.  
- Schuur systematisch alle gemarkeerde gaten.  
- Besteed ook aandacht aan de aansluitpunten en schaaf bij als deze niet mooi op elkaar passen.

### 2.5 Cel configuratie

[Blueprint van de batterijpack]

Plaats alle cellen in hun 3D-print brackets zoals aangeduid in de blueprint.  
Deze opstelling komt overeen met een **13s13p configuratie** (*s = serieel, p = parallel*).

**Uitleg configuratie:**  
- **13 serieel** = 13 × 3.7V = **48.1V** (nominale gewenste spanning).  
- **Parallel:** Verbind beide positieve polen en beide negatieve polen van de cellen. Dit vergroot de batterijcapaciteit.  
- **Serieel:** Verbind de positieve pool van de eerste cel met de negatieve pool van de tweede. Dit verhoogt de spanning.

### 2.6 Puntlassen

[Afbeelding van de cel configuratie]

Gebruik de nikkelstrip en puntlasser om de verbindingen te maken volgens de blueprint:  
- Knip stukken van de nikkelstrip in de juiste lengte.  
- Leg de nikkelstrip op de pool van de cel en gebruik de puntlasser om de nikkel aan de cel te smelten.  

**Opmerkingen:**  
- Plaats extra lengte nikkelstrip (2 cm) op de **BATT+** en **BATT-** om later op te solderen.  
- Controleer met een multimeter dat iedere seriële celgroep (13 parallelle cellen) **4.2V** bijdraagt aan de totale spanning.  
- Totaal spanning over **BATT-** en **BATT+** moet **54.2V** zijn (13 × 4.2V).

### 2.7 BMS bevestigen

[Blueprint van de batterijpack]

- Plaats de JK Smart-BMS op de platte bovenkant van de batterijpack.  
- Soldeer rode kabeltjes aan iedere nikkelbrug tussen de celgroepen, zoals aangegeven in de blueprint.  
- Zorg voor nette verbindingen door onnodige lengte kabels af te knippen.  
- Soldeer de kabels alleen op de nikkelstrip, niet op de celpool, om beschadigingen te voorkomen.  

Bevestig de BMS met hotglue of adhesive tape op de batterijpack.  
Soldeer de **BATT+** en **BATT-** met 16mm² kabels aan de BMS voor verbinding met de volledige opstelling.

### 2.8 PVC shrink wrap

- Knip de rol PVC shrink wrap doormidden voor een groter vel.  
- Leg deze over de batterijpack en BMS totdat alles netjes bedekt is.  
- Gebruik een heteluchtpistool om de shrinkwrap te laten krimpen, zodat de batterijpack stevig ingepakt is.

## 3. MPPT Charge Controller

[Macro schema]

De MPPT charger heeft verbindingen voor:  
- **BATT** (batterijpack)  
- **PV** (zonnepanelen)  
- **LOAD** (verbruikers of inverter)

**Instructies:**  
- Strip de juiste kabels en verbind deze op de aangeduide plaatsen.  
- Plaats zekeringen zoals aangegeven in het schema.  
- Overweeg een differentieelschakelaar bij de LOAD, al is dit een duurdere optie.

## 4. Data collectie

[Opstelling ESP] 
### 4.1 Protocol: 
[Documentatie VE Direct protocol]

Onze gekozen MPPT charger gebruikt een propriëtair protocol genaamd **VE Direct** om data via UART uit te zenden.  
Bekijk de documentatie zorgvuldig voor meer details.

**Samenvatting:**  
- De charger stuurt iedere seconde data via UART.  
- Dit kan worden uitgelezen op een ESP32 en gedeeld via de ingebouwde Wifi- of Bluetooth-module van de ESP32.  
- Een **APA logic level shifter** is nodig om de 5V UART van de charger om te zetten naar 3V3 voor de ESP32.

### 4.2 Configureren van Arduino IDE
bron: https://samueladesola.medium.com/how-to-set-up-esp32-wroom-32-b2100060470c

- Stap 1: Arduino IDE
Gewoon downloaden op de site (https://www.arduino.cc/en/software)

- Stap 2: board selectie
 - Voeg "https://dl.espressif.com/dl/package_esp32_index.json" toe aan Preferences>Additionals boards manager URLs in arduino IDE.
 - Installeer "esp32" van Boards manager in arduino IDE, als je het niet direct vind moet je wat wachten tot de aanpassingen van vorige stap zijn gesynchroniseerd.
 - Selecteer "ESP32 Dev Module" als ontwikkel bord.
- Stap3: Drivers
**Linux**
Je kan kijken of de driver beschikbaar is op je systeem door dit uit te voeren:
`ls -al /lib/modules/"$(uname -r)"/kernel/drivers/usb/serial/cp210x.ko`
. Hierna kan je de driver activeren op de volgende manier:
`sudo modprobe cp210x`
. In sommige distros moet je jezelf ook nog toegang geven tot de esp op de usb via volgend commando:
`sudo usermod -aG dialout $(whoami)`
**Windows**
Je deze downloaden op https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers.

### 4.3 Code voor ESP32: 
**Code via Arduino IDE:**  
[Code]





