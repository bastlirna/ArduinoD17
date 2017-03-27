# Arduino Workshop pro pokro�il� (no dob�e, lehce pokro�il�)

Tento wokrshop je zam��en hlavn� na programov�n�, nebudeme ani tak �e�it jak p�ipojit k Arduino teplom�r, display nebo tla��tko (to u� patrn� v�te) nebo co je to prom�nn�, jak ji definovat nebo jak napsat *for* cyklus (to u� byste m�li taky v�d�t, pokud p�ijdete). My se pod�v�me na to, jak napsat program, kter� zvl�dne n�kolik v�c� najednou (multitasking), program kter� m� slo�itou logiku a jak napsat program, aby ho je�t� n�kdo n�kdy zvl�dnul p�e��st (v�etn� jeho autora).

## Prerekvizity

��astn�k by m�l:

- um�t programovat (ide�ln� znal C/C++)
- um�t programovat Arduino
- um�t k Arduinu p�ipojit periferie (tla��tko, LED, i2c ic, ...)

Ide�ln� ��astn�k je �lov�k, kter� si za��n� pou��vat Arduino (nap�. absolvoval https://arduino101.cz/) a m� u� n�jak� zku�enosti s progamov�n�m (nap�. PHP, Java, ...) 

## Osnova

- P�eme neblokuj�c� k�d
- P�eme kooperativn� multitasking
- P�eme stavov� automat

## Co se nau��te

- jak nepou��vat `delay` (nikdy!)
- na co jsou dobr� ukazatele, a hlavn� ukazatele na funkce
- jak �lenit slo�it� k�d
- jak efektivn� pou��vat Arduino IDE (a pro� ho nepou��vat a p�ej�t na n�co jin�ho...)

## �kol

B�hem workshopu budete m�t pouze jeden jedin� �kol: **naprogramujte ratrap�nky** ... �e nev�te co to je? Ratrap�nky jsou [stopy](https://cs.wikipedia.org/wiki/Stopky), kter� um� m��it mezi�as. 

B�hem workshopu budete pou��vat [EduShield](https://www.edushield.cz/cs/).

### Po�adavky

- Stopky budou na displeji zobrazovat ub�hnut� �as ve form�tu `00.00`, kde prvn� ��st jsou vte�iny a druh� ��st setiny vte�in. Stopky m��� �as do 99.99 vte�in (pro jednoduchost).
- Po zapnut� se stopky dostanou do po��te�n�ho stavu, kde na displeji vid�te `00.00` a stopky �ekaj� na spu�t�n�.
- Stopky se spust� kr�tk�m stiskem tla��tka.
- N�sleduj�c� kr�tk� spu�t�n� zaznamen� mezi�as. Mezi�as se zobraz� na 1 vte�inu na displeji (stopky mezit�m b�� d�l).
- Meziv�sledek se ukl�d� do pam�ti (stopky ulo�� a� 20 mezi�as�).
- Dlouh�m stiskem tla��tka (del��m ne� 1 vte�ina) se stopky zastav�, na displeji z�stane sv�tit celkov� �as a v�echny meziv�sledky se vyp�ou na seriov� port v textov� podob�.
- N�sleduj�c�m stiskem tla��tka se stopky dostanou do po��te�n�ho stavu.


