bron: https://samueladesola.medium.com/how-to-set-up-esp32-wroom-32-b2100060470c

## Stap 1: Arduino IDE
Gewoon downloaden op de site (https://www.arduino.cc/en/software)

## Stap 2: board selectie
 - Voeg "https://dl.espressif.com/dl/package_esp32_index.json" toe aan Preferences>Additionals boards manager URLs in arduino IDE.
 - Installeer "esp32" van Boards manager in arduino IDE, als je het niet direct vind moet je wat wachten tot de aanpassingen van vorige stap zijn gesynchroniseerd.
 - Selecteer "ESP32 Dev Module" als ontwikkel bord.
## Stap3: Drivers
### Linux
Je kan kijken of de driver beschikbaar is op je systeem door dit uit te voeren:
`ls -al /lib/modules/"$(uname -r)"/kernel/drivers/usb/serial/cp210x.ko`
Hierna kan je de driver activeren op de volgende manier:
`sudo modprobe cp210x`
### Windows
Je deze downloaden op https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers.

## U bent klaar
Nu kunt u code compileren en flashen.
