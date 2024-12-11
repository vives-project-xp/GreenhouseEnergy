# Uitbreiding Guide

**Let op**: Voordat je verder leest, blader eerst door deze GitHub-repository en lees vooral de README en de Installation Guide volledig door. Dit biedt essentiële basisinformatie voor de uitbreiding.

## Algemeen
Het ontwerpen van een uitbreiding kent veel mogelijke scenario's, waardoor het onmogelijk is om alle mogelijke situaties volledig te beschrijven. De energie-eis van jouw systeem zal grotendeels de bepalende factor zijn voor de opstelling.

Om deze reden starten we met een aantal voorbeeldscenario’s die een indicatie geven van de vereisten in verschillende situaties. Aan de hand van deze scenario's kun je een weloverwogen keuze maken voor jouw specifieke opstelling.

---

## Scenario’s

### Scenario 1: Gemiddeld dagelijks verbruik van 1 kWh
- **Inverter**: Victron Phoenix 48/1200 (VE.Direct)
- **Charger**: SmartSolar 100/30 MPPT
- **Batterij**:
  - 48V met een minimale capaciteit van 3 kWh.
  - **Opties**:
    - 2 parallelle batterijpacks, elk 13s15p.
    - 3 parallelle batterijpacks, elk 13s10p.
- **Zonnepanelen**:
  - Eén of twee panelen van 400 Wp is voldoende.
  - **Aanbevolen**: parallelle opstelling voor betere betrouwbaarheid bij slecht weer.
  - **Maximale configuratie**: 3 panelen in serie, 3 parallel (resulterend in een configuratie van 100/33 V en 30/11 A).
- **Zekeringen en schakelaars**: Geschikt voor 30A en 48V.
- **Schematische voorstelling**:

![image](https://github.com/user-attachments/assets/6012edfb-80f1-4d9d-8b40-6e8feae693fe)



### Scenario 2: Gemiddeld dagelijks verbruik van 5 kWh
- **Inverter**: Victron MultiPlus-II 48/5000/70-50 230V
- **Charger**: Victron SmartSolar MPPT 250/100
- Geen load connectors; rechtstreeks aangesloten op de batterij.
- **Batterij**:
- 48V met een capaciteit van minstens 10 kWh.
- **Mogelijke configuratie**: 4 parallelle packs, elk 13s20p.
- **Zonnepanelen**:
- Minstens 6 panelen van 400 Wp in een combinatie van serie en parallel voor een optimale balans tussen voltage en stroom.
- **Zekeringen en schakelaars**: Geschikt voor hogere stroomsterktes, minimaal 100A.
- **Schematische voorstelling**:

![victron 5kWh](https://github.com/user-attachments/assets/20904c97-2b2b-43b5-8c70-f17192275a93)



### Scenario 3: Gemiddeld dagelijks verbruik van 10 kWh
- **Inverter**: Victron Quattro 48/10000/140-100/100
- **Charger**: Victron SmartSolar MPPT 250/100
- **Batterij**:
- 48V met een minimale capaciteit van 20 kWh.
- **Mogelijke configuratie**: 6 parallelle batterijpacks, elk 13s30p.
- **Zonnepanelen**:
- Twaalf panelen van 400 Wp.
- **Aanbevolen configuratie**: twee strings van zes panelen in serie.
- **Zekeringen en schakelaars**: Geschikt voor stroomsterktes tot 200A.
- **Schematische voorstelling**:

![image](https://github.com/user-attachments/assets/06eac37b-138a-4965-af20-17aead99801d)


---

## Kosten schattingen

### Kosten Scenario 1 (1 kWh per dag)
- **Inverter**: Victron Phoenix 48/1200 (€350 - €450)
- **Charger**: SmartSolar 100/30 MPPT (€250 - €300)
- **Batterij**:
- Cell-prijs (bijvoorbeeld 18650-cellen): ± €2 per cel.
- 390 cellen = €780
- Inclusief BMS en behuizing: €200 - €300 extra.
- **Zonnepanelen**: 
- 1 of 2 panelen van 400 Wp (€150 - €200 per paneel = €150 - €400)
- **Montagemateriaal**: €50
- **Zekeringen en schakelaars**: €50 - €100
- **Totale kosten**: €1.400 - €2.100

### Kosten Scenario 2 (5 kWh per dag)
- **Inverter**: Victron MultiPlus-II 48/5000/70-50 (€1.200 - €1.500)
- **Charger**: Victron SmartSolar MPPT 250/100 (€700 - €1.000)
- **Batterij**:
- 13s20p = 260 cellen x 4 = 1.040 cellen = ± €2.080
- Inclusief BMS en behuizing: €400.
- **Zonnepanelen**: 
- 6 x 400 Wp (€150 - €200 per paneel = €900 - €1.200)
- **Montagemateriaal**: €200 - €300
- **Zekeringen en schakelaars**: €50
- **Totale kosten**: €5.380 - €6.500

### Kosten Scenario 3 (10 kWh per dag)
- **Inverter**: Victron Quattro 48/10000/140-100/100 (€2.500 - €3.000)
- **Charger**: Victron SmartSolar MPPT 250/100 (€700 - €1.000)
- **Batterij**:
- 13s30p = 390 cellen x 6 = 2.340 cellen = ± €4.680
- Inclusief BMS en behuizing: €600 - €800.
- **Zonnepanelen**: 
- 12 x 400 Wp (€150 - €200 per paneel = €1.800 - €2.400)
- **Montagemateriaal**: €300 - €500
- **Zekeringen en schakelaars**: €100 - €200
- **Totale kosten**: €9.980 - €11.900
