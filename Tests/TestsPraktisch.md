## Eerste test
Om erachter te komen hoeveel watt een batterij in het totaal heeft moeten we de Capaciteits test uitvoeren.
Voor een hele set te testen hebben we voor de INR 18650E batterij een ideale stroom gevonden: 3.5A. Omdat ze met 2 parralel staan per cel is de ideale ontlaad stroom voor de hele set 7A, omdat we geen weerstand konden vinden die 7A nemen we een max stroom van 1.8A (0.6A per weerstand).
We hebben dus een spanning van 48V en we willen 1.8A, dan hebben we 26 Ohm nodig, dan hebben we voor 3 parralle weerstanden 78Ohm nodig en zal er 0.6A per weerstand vloeien.

Opstelling:

+| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -|  (13 batterijen in serie)<br>
 |                                                                                      <br>
 |----[W]--------+------------------------------+-------------------------------+      (W is de wattmeter)<br>
                 |                              |                               |<br>
                 [R1]                           [R2]                            [R3]   (3 weerstanden parallel)<br>
                 |                              |                               |<br>
                 +------------------------------+-------------------------------+<br>

Als er een weerstand niet meer werkt dan doen we het met 1.2A weerstand: 40Ohm en 80Ohm per weerstand:

+| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -| +| -|  (13 batterijen in serie)<br>
 |                                                                                      <br>
 |----[W]--------+-----------------------+                                      (W is de wattmeter)<br>
                 |                       |<br>
                 [R1]                    [R2]                                  (2 weerstanden parallel)<br>
                 |                       |<br>
                 +-----------------------+<br>

Met de watt meter kijken we periodiek hoeveel arbeid er wordt gelevert door de batterij en dan weten we hoeveel Wh er in de batterijen zit.
Af en toe schakelen we de wattmeter om naar een volt meter om te kijken of de batterijen ontladen zijn.
Voledig ontlaad spanning: 3*13 = 39V
