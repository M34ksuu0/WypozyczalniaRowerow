# 🚲 Wypożyczalnia Rowerów – C++
📌 Opis projektu

Program konsolowy napisany w języku C++, służący do obsługi wypożyczalni rowerów. Umożliwia zarządzanie rowerami, ich wypożyczanie oraz zwracanie z automatycznym obliczaniem kosztów.

Projekt wykorzystuje struktury (struct), wektor (vector) oraz obsługę wyjątków (try, throw, catch).

⚙️ Funkcjonalności

Program oferuje następujące opcje:

Dodawanie roweru

    ID roweru
    Opis roweru
    Rodzaj roweru
    Cena za godzinę
    Automatyczne ustawienie statusu na dostępny
    Sprawdzanie, czy ID nie jest już zajęte
    Wypożyczanie roweru
    Wyszukiwanie roweru po ID
    Sprawdzanie dostępności
    Zmiana statusu na wypożyczony
    Obsługa błędów, np. próba wypożyczenia zajętego roweru
    Zwracanie roweru
    Wyszukiwanie roweru po ID
    Podanie liczby godzin wypożyczenia
    Obliczanie kosztu na podstawie stawki godzinowej
    Zmiana statusu na dostępny
    Walidacja liczby godzin (wartość musi być większa od 0)
    Wyświetlanie rowerów
    Lista wszystkich rowerów
    Czytelna tabela tekstowa
    Wyświetlanie ID, opisu, rodzaju, ceny i statusu
    Wyjście z programu
    Zakończenie działania aplikacji za pomocą opcji 0.
    
🛠️ Technologie i wykorzystane elementy C++

C++

struct – struktury przechowujące dane rowerów i wyjątki

vector – dynamiczna lista rowerów

string – przechowywanie opisów i rodzajów rowerów

iomanip – formatowanie tabeli i cen

try, throw, catch – obsługa wyjątków

Funkcje – podział programu na poszczególne operacje

📋 Struktura danych

Każdy rower przechowuje następujące informacje:

Pole	    Typ	    Opis
id	        int	    Unikalny identyfikator roweru
opis	    string	Opis roweru
rodzaj	    string	Rodzaj roweru
cena	    double	Cena za godzinę
wypozyczony	bool	Status wypożyczenia

🖥️ Menu programu
=========== WYPOZYCZALNIA ROWEROW ==========
1. Dodaj rower
2. Wypozycz rower
3. Zwroc rower
4. Wyswietl rowery
0. Wyjscie
============================================

Projekt wzorcowy do przygotowania się do egzaminu INF.04
