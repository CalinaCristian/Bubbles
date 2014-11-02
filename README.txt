Calina Cristian-Florin , 313CA




Programul rezolva doar varianta simpla. Nu am luat in considerare varianta complicata.

Metoda pe care am abordat-o in vederea rezolvarii cerintei exercitiului a respectat algoritmul recomandat de pe site.

Astfel , la inceput am declarat functiile ce urmeaza sa fie folosite in main pentru a modulariza programul (acestea au fost in numar de 5 si sunt explicate in program).

In main am declarat mai intai variabilele respectand ordinea si tipul lor din exercitiu, dupa aceea am citit respectivele variabile.

In primul rand am initializat vectorul de marcare (j) numai cu valorea 0. Dupa aceea am verificat daca baloanele erau in camera si am marcat in vectorul de marcare toate baloanele ce trebuiesa fie sterse(j[i]=1) , iar daca mai aveam cel putin 1 balon ramas in camera am dat unei variabile aux valoarea 1 (aux fiind initializat cu 0).

Dupa aceea am verificat in cazul in care mai sunt cel putin 2 baloane daca oricare dintre acestea se ciocnesc cu un alt balon (Primul l-am verificat cu toate celelalte , dupa aceea al 2-lea si tot asa , marcandu-le in vectorul de marcare cu 1 in caz afirmativ de ciocnire).

A urmat stergerea acestora prin apelarea functiei stergere (care sparge baloanele prin atribuirea valorii balonului urmator la balonul ce trebuie sters , inclusiv atribuirea valorii vectorului de marcare, iar apoi scaderea numarului de baloane ramase in main pentru a scapa de ultimul balon care va avea valoarea egala cu cel precedent).Dupa aceea,in caz ca mai existau baloane in camera (aux=1) se incepea simularea pe intervalul (0,1) si asa mai departe. In caz contrar, (aux=0), afisam direct "0" fara a intra in simulare.

In simulare am folosit acelasi algoritm ca si cel de dinainte , verificand si marcand baloanele ce se ciocnesc cu peretii iar apoi cele care se ciocnesc intre ele , apoi stergandu-le. In caz ca se stergea cel putin un balon in intervalul respectiv am luat o variabila sters careia ii dadeam valoarea 1 si astfel daca mai exista cel putin 1 balon in camera dupa stergere iar variabila sters era 1 afisam secunda, numarul baloanelor ramase precum si coordonatele acestora pe linii separate. In cazul in care nu mai erau baloane in camera se afisa capatul superior ar intervalului si se oprea simularea.Daca mai erau baloane, se trecea la secunda urmatoare si se reincepea simularea pana cand se ajungea la timpul maxim dat de la tastatura sau se terminau baloanele.

Mentionez ca am depasit limita de 80 de caractere pe o linie in unele cazuri datorita faptului ca nu am folosit variabile globale si a trebuit sa am multi parametrii la unele functii. De asemenea , nu am amestecat taburile cu spatiile ci am folosit doar spatii. Programul a trecut de toate cele 8 teste.

