# Übungsblatt 8

## Aufgabe 1
- a) Primärrepräsentant von [12] 3 ist 0
- b) Primärrepräsentant von [18726] 5 ist 1
- c) Primärrepräsentant von [1817263129873773557622255221118761876836827638129837733339117263876213888281726626113] 10 ist 3
- d) Primärrepräsentant von [198273133] 20761 ist 5583 (nicht einfach lösbar)

## Aufgabe 2 (KLAUSURAUFGABE!!!)
a) 17 == 13 mod 4 wahr
> 17 - 13 = 4 und 4 ist durch 4 teilbar oder 17 % 4 = 13 % 4

b) [15]4 = 3 falsch, da links eine Menge und rechts eine Zahl ist

## Aufgabe 4
Gruppe benötigt Halbgruppe mit:
- neutrales Element
- inverses Element

Halbgruppe benötigt Algebra mit:
- Menge nicht leer
- ° ist assoziativ

Algebra ist gegeben

### Menge nicht leer
klar durch Voraussetzung der gegebenen Algebra

### ° ist assoziativ
(x°y)°z = x°(y°z)
-> Vorlesung Seite 423

- (x+y%8)+z%8 = x+(y+z%8)%8
- Das innere %8 kann man nach außen ziehen

## neutrales Element
0 (klar)

> Beweis: x°e = e°x = x

## inverses Element
> gesucht: x + y = 0

- 0: 0
- 1: 7
- 2: 6
- 3: 5
- 4: 4
- 5: 3
- 6: 2
- 7: 1

=> alle Zahlen haben ein inverses Element

## Aufgabe 5
Wenn man die Bits zählt, dann ist die Laufzeit exponentiell O(x^n)

[Laufzeitabschätzung: O(n) (Größe der Zahl selbst)]