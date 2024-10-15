#include <stdio.h>

int main() {
	//To jest komentarz
	printf("Namaste!");
	
	/*A to komentarz wielolinijkowy
	Za pomocą funkcji printf() drukujemy kolejną linijkę tekstu*/
	printf("Namaste to tradycyjne indyjskie przywitanie\n");
	
	// To jest moja dopisana linijka
	printf("Hello World!");

	// 1 Po usunięciu \n przy wyświetlaniu nie przechodzi do następnej linijki 

	// 2 Dopisanie \t spowoduje wyświetlenie tab

	// 5 Wpisanie return 0; po pierwszej linijce drukującej tekst spowoduje zakończenie programu od razu po wyświetleniu tej linijki

	// 6 Po zakomentowaniu ostatniej linijki return 0; program i tak wykona się poprawnie i zwróci 0 ponieważ najnowsza wersja języka C robi to domyślnie. Zatem linijka return 0; jest opcjonalna

	// 7 Wyskoczy błąd, ponieważ program spodziewa się w danym miejscu średnika
}