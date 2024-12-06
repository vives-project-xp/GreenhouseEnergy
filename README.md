# Greenhouse Energy

## Index

- [The project](#the-project)
- [Wie zijn we](#wie-zijn-we)
- [Hardware](#hardware-en-functies)
- [Bill of Materials](#bill-of-materials)
- [Batterij](#de-batterij)


## The project
We kregen eerst de opdracht om elektriciteit te voorzien voor alle projecten die in de serre staan, maar na wat reflectie met de coaches kwamen we overeen dat we enkel een batterij oplaad systeem moesten ontwikkelen met monitoring voorzieningen. Nadien zullen de coaches een converter voorzien om de door ons opgewekte stroom naar 240V AC om te zetten en in het 2de semester komt er waarschijnlijk een opvolgend project die dan alles vervolledigd.

## Wie zijn we
- Seraphin Sampers (Scrum master, Researcher, IoT designer)
- Olivier Westerman (Communications, Administratie, Planning)
- Joshua Meuleman (Allround, Hardware specialist)

## Architectuur:
![MPPT charger (1)](https://github.com/user-attachments/assets/39b41f7b-f0f4-48fb-b6cf-715077c069bb)

## Hardware en Functies
- BMS: Gezondheid van de batterij beschermen en sensordata leveren via UART.
- MPPT Charge controller: Opladen van de batterij aan het juiste voltage met de input van de zonnepanelen.
- Batterijen 13-Serieel NRC8650PF ,INR18650E en NRC8650B met 3.7V samen 48V, in een modulair systeem om meer parallel te kunnen plaatsen.
- Zekeringen tussen de MPPT, Batterij, Zonnepanelen (toekomstige uitbreiding) en Inverter (toekomstige uitbreiding).

## Bill of Materials
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

# De Batterij:
## Afmetingen
max 40cm(lengte) - 30cm (breedte) - 10cm (hoogte)
## Specificaties:
| Batterij              | Berekend | Gemeten |
|---------------------------|-------------|---------------|
| Voltage | min 39V , average 48V, max 54.2V | average 48.2V |
| Ontlaadstroom      | max 20A |  nvt    | 
| Oplaadstroom      | max 20A |  nvt    | 
| Capaciteit           | 1.25 kWh         |   1.12 kWh|


![Batterij Schematic](https://github.com/user-attachments/assets/7456a43b-e366-4438-bcc8-47521168dfc4)

