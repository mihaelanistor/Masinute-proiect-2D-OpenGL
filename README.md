# Masinute-proiect-2D-OpenGL

Descriere

	Nume proiect : Masinute
	
	Proiectul consta intr-un joc ce are ca scop traversarea unui drum aglomerat si ajungerea la casuta, fara a fi lovit de masini de mai multe ori decat numarul de vieti.

	Pentru desenarea fundalului am folosit poligoane (dreptunghiuri) si linii (continue si punctate), de diferite culori.
	Pentru desenarea casei, copacului, merelor, inimii, masinilor si jucatorului (doi oameni si un cos, in care culeg mere) am folosit poligoane (oarecare, cerc, dreptunghi, trapez), linii si puncte.
	O parte din masini merg mereu spre stanga si restul mereu spre dreapta, iar cand ajung la una din extremitatile ferestrei sunt translatate in cealalta extremitate.
	Jucatorul se poate deplasa (prin translatie) in sus, jos, stanga sau dreapta cu ajutorul unei functii pentru tastatura.
	Atunci cand jucatorul se intersecteaza cu una din masini, acesta este trimis la punctul de ajutor, i se scade o viata, iar daca nu a ajuns la 0 vieti, poate continua jocul.
	Atunci cand jucatorul atinge un mar, acesta dispare si este adaugat un punct in plus.

Implementare

	Toate corpurile (mai putin jucatorul) sunt desenate cu centrul de greutate in punctul (300,200) apoi translatate in 0 pentru aplicarea rotatie (unde este cazul) si scalarii (au fost desenate mai mari pentru a simplifica calculele coordonatelor), iar apoi translatate in puncte fixe (mere, inima, etc) sau in puncte a caror coordonate sunt modificate la fiecare afisare pentru a crea iluzia de miscare (masini).
	Coordonata X a masinilor este modificata cu alpha1(> 0), pentru cele care merg spre dreapta si cu alpha2(< 0), cele care merg spre stanga. Aceste valori depind de nivelul de dificultate ales ( nivelul de dificultate poate fi schimbat oricand in timpul jocului cu tastele: 1,2,3; cand incepe jocul nivelul e 2).
	Jucatorul este desenat cu centrul de greutate in (0,0), incadrat intr-un patrat(cu latura 40) pentru a simplifica calculele de intersectie cu masinile, acesta este translatat la punctul de coordonate j si i , calculate la fiecare intrare de la tastatura (“w” = creste coordonata pe axa Oy,  “s” = scade coordonata pe Oy, respectiv “a” si “d” pentru axa Ox; space = nu modifica coordonatele => jucatorul nu se misca) .

Platforma

  	Ubuntu 15.10
	Editor: Vim 7.4

Compilare + rulare:

	g++ MihaelaNistor252.cpp -lGL -lGLU -lglut -lm && ./a.out

	Pentru rulare pe Windows codul sursa trebuie modificat astfel:

		- se adauga #include <windows.h>
		- se inlocuieste #include <GL/ … > cu #include<gl/ … >
		- se inlocuieste int main() { … ; return 0;} cu void main() { … ; }


Testare

	Jucatorul se deplaseaza cu tastele:

	w = sus
	a = stanga
	s = jos
	d = dreapta
	space = sta

	Nivelul de dificultate se schimba cu tastele:

	1 = usor
	2 = mediu
	3 = greu

	Dupa un joc terminat ( fie jucatorul a ajuns la casa – sus, stanga - , fie a pierdut toate vietile):

	tasta y = restart joc	

Link video:

	https://drive.google.com/open?id=1-svPvnQHpoiYJvy10ri8V8tvs7bNVqMJ
