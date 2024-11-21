(Je kan deze tests uitvoeren op verschillende temperatuuren om zo te kijken binnen welke temperatuurs ranges de batterijen goed werken.)

## Lek stroom test

Laadt de batterijen volledig op en laat ze liggen voor een week, als ze na een week nog steeds vol zijn dan heeft de batterij een kleine lekstroom.

## SoH test van de bms

Steek de batterijen in de bms, die dan de interne weerstand van de batterijen meet en zo de SoH bepaaldt.

## Capaciteits test (tijdsrovend, gebruik de test van de bms).

Laadt de batterijen volledig op en laat ze gecontrolleerd ontladen om zo erachter te komen hoeveel Ah of Wh er nog in zit.

## Totale test

Sluit het prototype aan op de BMS en bekijk de totale SoC, als dit in persentages wordt uitgedrukt dan moet je berekenen hoeveel Ah er in de batterijen zit (SoC/100 * totale Capaciteit Batterij * aantal batterijen), na het gecontrolleerd leeglopen moet er nog overschieten van wat je had - wat je verbruikt had.

## Oplaadt test

Probeer batterijen op te laden via de BMS, ze zouden niet meer dan 100% mogen worden en allemaal opgeladen moeten zijn als de BMS aangeeft dat de SoC 100% is.
