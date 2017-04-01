# Arduino Workshop pro pokročilé (no dobře, lehce pokročilé)

Tento wokrshop je zaměřen hlavně na programování, nebudeme ani tak řešit jak připojit k Arduino teploměr, display nebo tlačítko (to už patrně víte) nebo co je to proměnná, jak ji definovat nebo jak napsat *for* cyklus (to už byste měli taky vědět, pokud přijdete). My se podíváme na to, jak napsat program, který zvládne několik věcí najednou (multitasking), program který má složitou logiku a jak napsat program, aby ho ještě někdo někdy zvládnul přečíst (včetně jeho autora).

## Prerekvizity

Účastník by měl:

- umět programovat (ideálně znal C/C++)
- umět programovat Arduino
- umět k Arduinu připojit periferie (tlačítko, LED, i2c ic, ...)

Ideální účastník je člověk, který si začíná používat Arduino (např. absolvoval https://arduino101.cz/) a má už nějaké zkušenosti s progamováním (např. PHP, Java, ...) 

## Osnova

- Píšeme neblokující kód
- Píšeme kooperativní multitasking
- Píšeme stavový automat

## Co se naučíte

- jak nepoužívat `delay` (nikdy!)
- na co jsou dobré ukazatele, a hlavně ukazatele na funkce
- jak členit složitý kód
- jak efektivně používat Arduino IDE (a proč ho nepoužívat a přejít na něco jiného...)

## Úkol

Během workshopu budete mít pouze jeden jediný úkol: **naprogramujte ratrapánky** ... že nevíte co to je? Ratrapánky jsou [stopy](https://cs.wikipedia.org/wiki/Stopky), které umí měřit mezičas. 

Během workshopu budete používat [EduShield](https://www.edushield.cz/cs/).

### Požadavky

- Stopky budou na displeji zobrazovat uběhnutý čas ve formátu `00.00`, kde první část jsou vteřiny a druhá část setiny vteřin. Stopky měří čas do 99.99 vteřin (pro jednoduchost).
- Po zapnutí se stopky dostanou do počátečního stavu, kde na displeji vidíte `00.00` a stopky čekají na spuštění.
- Stopky se spustí krátkým stiskem tlačítka.
- Následující krátké spuštění zaznamená mezičas. Mezičas se zobrazí na 1 vteřinu na displeji (stopky mezitím běží dál).
- Mezivýsledek se ukládá do paměti (stopky uloží až 20 mezičasů).
- Dlouhým stiskem tlačítka (delším než 1 vteřina) se stopky zastaví, na displeji zůstane svítit celkový čas a všechny mezivýsledky se vypíšou na seriový port v textové podobě.
- Následujícím stiskem tlačítka se stopky dostanou do počátečního stavu.


### Nápověda
- funkce [millis()](https://www.arduino.cc/en/reference/millis) na stránkách Arduina
- vysvětlení [konečného automatu (FSM)](http://voho.eu/wiki/konecny-automat/)
- odchycení zákmitů tlačítek pomocí funkce [Bounce()](https://github.com/thomasfredericks/Bounce2/wiki)
- oficiální knihovna k EduShieldu [na GITu](https://github.com/maly/edushield)