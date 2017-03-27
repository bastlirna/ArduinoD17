# Arduino Workshop pro pokroèilé (no dobøe, lehce pokroèilé)

Tento wokrshop je zamìøen hlavnì na programování, nebudeme ani tak øešit jak pøipojit k Arduino teplomìr, display nebo tlaèítko (to už patrnì víte) nebo co je to promìnná, jak ji definovat nebo jak napsat *for* cyklus (to už byste mìli taky vìdìt, pokud pøijdete). My se podíváme na to, jak napsat program, který zvládne nìkolik vìcí najednou (multitasking), program který má složitou logiku a jak napsat program, aby ho ještì nìkdo nìkdy zvládnul pøeèíst (vèetnì jeho autora).

## Prerekvizity

Úèastník by mìl:

- umìt programovat (ideálnì znal C/C++)
- umìt programovat Arduino
- umìt k Arduinu pøipojit periferie (tlaèítko, LED, i2c ic, ...)

Ideální úèastník je èlovìk, který si zaèíná používat Arduino (napø. absolvoval https://arduino101.cz/) a má už nìjaké zkušenosti s progamováním (napø. PHP, Java, ...) 

## Osnova

- Píšeme neblokující kód
- Píšeme kooperativní multitasking
- Píšeme stavový automat

## Co se nauèíte

- jak nepoužívat `delay` (nikdy!)
- na co jsou dobré ukazatele, a hlavnì ukazatele na funkce
- jak èlenit složitý kód
- jak efektivnì používat Arduino IDE (a proè ho nepoužívat a pøejít na nìco jiného...)

## Úkol

Bìhem workshopu budete mít pouze jeden jediný úkol: **naprogramujte ratrapánky** ... že nevíte co to je? Ratrapánky jsou [stopy](https://cs.wikipedia.org/wiki/Stopky), které umí mìøit mezièas. 

Bìhem workshopu budete používat [EduShield](https://www.edushield.cz/cs/).

### Požadavky

- Stopky budou na displeji zobrazovat ubìhnutý èas ve formátu `00.00`, kde první èást jsou vteøiny a druhá èást setiny vteøin. Stopky mìøí èas do 99.99 vteøin (pro jednoduchost).
- Po zapnutí se stopky dostanou do poèáteèního stavu, kde na displeji vidíte `00.00` a stopky èekají na spuštìní.
- Stopky se spustí krátkým stiskem tlaèítka.
- Následující krátké spuštìní zaznamená mezièas. Mezièas se zobrazí na 1 vteøinu na displeji (stopky mezitím bìží dál).
- Mezivýsledek se ukládá do pamìti (stopky uloží až 20 mezièasù).
- Dlouhým stiskem tlaèítka (delším než 1 vteøina) se stopky zastaví, na displeji zùstane svítit celkový èas a všechny mezivýsledky se vypíšou na seriový port v textové podobì.
- Následujícím stiskem tlaèítka se stopky dostanou do poèáteèního stavu.


