Mai intai de toate am citit din fisier cuvintele, primul cuvant fiind comanda, apoi tipul de date pe care vreu sa il inserez in vector. Am salvat numele si numerele in char pointeri. Pentru numere am aplicat functia atoi pentru a salva numerele sub forma de intregi in pointerul de tip data_structure. Campul data din acest pointer l-am alocat cu lungimea primului cuvant + 1 pentru \0 si inca doua zone de memorie pentru fiecare tip de date + lungimea celui de-al doilea cuvant +1. In len am numarat tipul de date de tip data_structure pe care le-am salat in vector, si am avut nevoie de o functie care imi numara de octeti pe care il ocupa vectorul la momentul apelului functiei. In functia add_last am apelat functia de numarat octeti ca sa stiu de la ce adresa incep sa memorez in vector,am calculat intr-un int (lungime_data) cati octeti o sa ocupe datele ce urmeaza sa fie memorate in vector. Si apoi folosind functia memcpy am adaugat in vector datele. Bineinteles inainte am realocat memorie pentru vector. In functia add_at am mutat datele incepand cu pozitia unde trebuia sa inserez datele noi, mai la dreapta in vector cu o poziie, iar pe pozitia in care trebuia sa introduc datele am pus zerouri, apoi am facut ce am facut si in functia add_last. Functia find, seamna cu functia print, am parcurs vectorul si in cazul in care se gasea ceva pe pozitia primita ca input am afisat. Am parcurs vectorul pana ala \0 ca sa pot extrage cuvantul si apoi in functie de fiecare tip de date am pastrat si numerele. Cuvintele le-am salvat in niste char* si au trebuit eliberate la final de utilizare. In functia delete_at am parcurs vectorul pana la pozitia ce trebuia eliminata si tot ce a fost de facut a fost sa fac sa "copiez" datele urmatoare in vector peste cele ce trebuiau sterse. Am realocat memorie pentru vector si micsorat numarul de structuri din vector. Functia de print a fost aproape la fel ca si find, am parcurs vectorul, in functie de cate informatii de numarul de structuri pe care le aveam in el si am afisat charurile si inturile in functie de fiecare tip de date.  
