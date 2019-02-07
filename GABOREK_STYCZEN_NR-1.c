//
//  GABOREK_STYCZEN_NR-1.c
//  Gaborek_styczen_-_zadanie_nr_1
//
//  Created by Paweł Gaborek on 10/01/2019.
//  Copyright © 2019 Paweł Gaborek. All rights reserved.

//Zad 1.1
//Utworzyć strukturę Student taką jak powyżej. Napisać metody:
//Student* Create(int age, int height, int semester) // alokuje pamięć itworzy studenta o podanych
//parametrach. WAŻNE - pamięć należy potem zwolnić w main() !
//void PrintStudent(Student *s) // wypisuje wszystkich składowych struktury
//bool AreEqueal(Student* s1, Student" s2) // zwraca informację, czy składowe są takie same (Uwaga - w C int
//zamiast bool)
               
//Zad 1.2.
//Utworzyć tablicę 3 studentów. Zapełnić ją wartościami, wyświetlić, zwolnić pamięć. Tablica powinna być
//utworzona za pomocą metody malloc (proszę pilnować odpowiedniej ilości gwiazdek!)
//Na poprzednich laboratoriach omawiane były tablice. W przypadku tablic, mamy do czynienia ze strukturą
//danych, której rozmiar musi być znany i jest trudny w modyfikacji - np. poprzez dodanie nowego elementu.
//Taka operacja wymagałaby zaalokowania całej tablicy od nowa (z rozmiarem o 1 większym), przepisania tablicy,
//dopisania ostatniego elementu izwolnienia pamięci na starą tablicę - jest do kosztowne. W przypadku struktur
//danych, gdzie chcemy płynnie dodawać i usuwać składowe, używamy list (w niektórych językach programowania
//nazywane też wektorami). Lista składa się ze struktur węzła (ang. node) - czyli zbioru danych pogrupowanych
//w pewnym „obiekcie”. Dla przykładu - jeśli mówimy o liście integerów, struktura pojedynczego węzła listy
//będzie zawierała wartość (czyli typ int) oraz wskaźnik na następny element listy.
//Czyli - każdy węzeł ma jakąś wartość oraz wskaźnik na kolejny element.
//Ponieważ implementujemy listę cykliczną, to ostatni element listy ma następnik ustawiony na PIERWSZY element
//listy. Taka sytuacja powtarza się w nieskończoność, więcdla listy złożonej z elementów: 2,4,8,16 , lista
//wygląda następująco:
//2 -> 4 -> 8 -> 16 -> 2-> 4 -> 8 -> 16 -> 2 -> 4 -> 8 -> 16 -> 2 -> (...)
//W związku z tym, podczas wypisywania listy, czy też ustalania adresu ostatniego elementu, należy zapamietać
//adres pierwszego elementu.
//UWAGA - w przypadku listy jednoelementowej, element wskazuje sam na siebie jako na następnik - jest
//jednocześnie korzeniem (root) iogonem (tail) listy.


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*************************************************************************************************
tworze definicje typu enum dla zmiennej prawda falsz
 *************************************************************************************************/

typedef enum {TRUE = 1, FALSE = 0} bool;

/*************************************************************************************************
tworze strukture studenta o parametrach podanych w zadaniu
 *************************************************************************************************/

struct student
{
    int age;
    int height;
    int semester;
};

/*************************************************************************************************
ponizej funkcja blokujaca pamiec na okreslona ilosc struktor w tablicy
 *************************************************************************************************/

void createStudenci(struct student** studenci, int ilosc)
{
    *studenci = (struct student *) malloc(sizeof(struct student)*ilosc);
}

/*************************************************************************************************
ponizej funkcja tworzaca tablice struktor
 *************************************************************************************************/

void create(struct student* const studenci, int ilosc)
{
    int wiek;
    int wzrost;
    int semestr;
    
    for(int i=0; i< ilosc; i++)
    {
        printf ("Podaj wiek studenta nr %i\n", i+1);
        scanf ("%i", &wiek);
        studenci[i].age = wiek;
        
        printf ("Podaj wzrost studenta nr %i\n", i+1);
        scanf ("i%", &wzrost);
        studenci[i].height = wzrost;
        
        printf ("Podaj semestr studenta nr %i\n", i+1);
        scanf ("%i", &semestr);
        studenci[i].semester = semestr;
    }
}

/*************************************************************************************************
ponizej funkcja zwalniajaca pamiec
 *************************************************************************************************/

void clearMemory(struct student** studenci)
{
    free(*studenci);
    *studenci = NULL;
}

/*************************************************************************************************
ponizej funkcja wyswietlajaca struktury studentow
 *************************************************************************************************/

void PrintStudent(const struct student* const studenci, int ilosc)
{
    for(int i=0; i< ilosc; i++)
    {
        printf("\nWiek studenta nr: %i \t to: %i\n", i+1, studenci[i].age);
        printf("Wzrost studenta nr: %i \t to: %i\n", i+1, studenci[i].height);
        printf("Semestr studenta nr: %i \t to: %i\n", i+1, studenci[i].semester);
    }
}

/*************************************************************************************************
ponizej funkcja porownujaca struktury
 *************************************************************************************************/

bool AreEqueal(struct student* s1)
{
    int wynik_bool;
   
        if ((s1[0].age == s1[1].age) && (s1[0].height == s1[1].height) && (s1[0].semester == s1[1].semester))
        {
            wynik_bool = 1;
        }
        else
            wynik_bool = 0;
    
    return wynik_bool;
}


//rozpoczynam funkcje glowna programu
int main(void)
{
    
    // ponizej ogreslilem wszystkie zmienne globalne a takze na dalem im typ zmiennej
    int wybor;                      // zmienna dla switch, wybor podprogramu
    int wyjscie=0;                  // zmienna dla wyjscia z programu
    char kont;                      // zmienna dla wyjscia z programu
    int porownanie_struktor;        // zmienna dla porownania struktor
    int i;                          // zmienna dla liczby iteracji petli
    int wiek;                       // zmienna dla wprowadzenia wieku
    int wzrost;                     // zmienna dla wprowadzenia wzrostu
    int semestr;                    // zmienna dla semestru
    
    puts ("\nWlasnie uruchomiles program nr 1 (zadania styczniowe)");
    puts ("Glowna funkcje main\n");
    
    while(wyjscie == 0) {
        printf ("\nMasz teraz mozliwosc wyboru ktora czesc programu chcesz uruchomic\n");
        printf ("Mozesz wybrac podprogram nr 1.1, 1.2n");
        printf ("Aby uruchomic program nr: \n");
        printf ("\n1.1 wybierz ''1'' \n");
        printf ("\n1.2 wybierz ''2'' \n");
        printf ("Po wprowadzeniu odpowiedniej liczby potwierdz klawiszem ''ENTER''\n");
        scanf ("%i", &wybor);
        switch (wybor)
        {
            case 1:
                // rozpoczynam program nr 1.1 (styczen)
                printf ("Uruchomiles wlasnie kolejny program, zadanie nr 1.%i\n", wybor);
                puts ("Program utworzy strukture dwoch studentow, a nastepnie porowna obydwie struktury");
                puts ("Po czym zwroci informacje czy sa indentyczne");
                puts ("\n\n\nTeraz program rozpocznie wprowadzanie danych do struktury:");
                
                //!!!!!!===KOMENTARZ===!!!!!!!
                
                //ponizej rozwiazanie wprowadzanie tablicy stroktor inaczej jak Pan zadal w zadania. Poki co
                //nie rozwiazalem wedlug podanego przez Pana schematy. Popracuje jeszcze nad rozwiazaniem
                //wedlug Panskiego schematu.
                
                struct student students[2]; //tworze tablice struktur
                for (i=0 ; i<2 ; i++)
                {
                    printf ("Podaj wiek studenta nr %i\n", i+1);
                    scanf ("%i", &wiek);
                    students[i].age = wiek;
                    
                    printf ("Podaj wzrost studenta nr %i\n", i+1);
                    scanf ("i%", &wzrost);
                    students[i].height = wzrost;
                    
                    printf ("Podaj semestr studenta nr %i\n", i+1);
                    scanf ("%i", &semestr);
                    students[i].semester = semestr;
                }
                puts ("Teraz program wyswietli struktury poszczegolnych studentow");
                PrintStudent(students, 2);
                puts ("\nSuper ! Powyzej wyswietlono struktury studentow");
                puts ("\nTera program powrowna obie struktury");
                puts ("Sprawdzi czy studenci sa wtym samym wieku, czy maja taki sam wzrost oraz czy sa na tym samym semestrze");
                
                porownanie_struktor = AreEqueal(students);
                
                porownanie_struktor == 1 ? FALSE : TRUE;
                    if ( porownanie_struktor == TRUE )
                        printf("\nSuper ! Wartosci podanym strukturach sa takie same\n");
                    else
                        printf("\nPrzykro mi, ale struktury sie roznia\n");
                
                
                break;
            case 2:
                // rozpoczynam program nr 1.2 (styczen)
                printf ("Uruchomiles wlasnie kolejny program, zadanie nr 1.%i\n", wybor);
                puts ("Program utworzy strukture trzech studentow, wypisze po czym zwolni pamiec");
                puts ("\n\n\nTeraz program rozpocznie wprowadzanie danych do struktury:");
                
                //!!!!!!===KOMENTARZ===!!!!!!!
                
                //przy tym zadaniu wzorowalem sie na przykladach ktore
                //na wykladach przedstawial Pan dr Fedorow. Po przeanalizowaniu rozwiazalem
                //zadanie w nastepujacy sposob.
                
                struct student* studenci;
                int iloscStudentow_zad_1_2 = 3;
                createStudenci(&studenci, iloscStudentow_zad_1_2);
                create(studenci, iloscStudentow_zad_1_2);
                PrintStudent(studenci, iloscStudentow_zad_1_2);
                clearMemory(&studenci);
                if (studenci == NULL)
                {
                    puts("Gratulacje ! Wlasnie dokonales prawidlowego zwolnienia pamieci.");
                }
                break;
           
            default:
                printf ("Podales bledna liczbe\n");
                printf ("Nic sie nie stalo. Przejdziesz do kolejnego pola wyboru :)\n");
                break;
                // teraz przechodze do mozliwosci wyboru czy chce ponownie uruchomic ktoras czesc programu (podprogramy)
                // czy zakonczyc calkiem dzialanie programu
        }
        printf ("\nGratulacje !!! Wlasnie zakonczyles dzialanie wybranego przez siebie programu nr 1.%i\n", wybor);
        while(1)
        {
            printf("\nCzy chcesz ponownie uruchomic program\n");
            printf("ktory poprzez odwolanie sie funkcji wlasnej poprzez STOS wykona opreacje ??\n");
            printf("Dla tak wpisz ''t'', dla nie wpisz ''n'': \n");
            getchar();
            scanf("%c", &kont);
            if(kont == 't')
            {
                break;
            }
            else if(kont == 'n')
            {
                wyjscie = 1;
                break;
            }
            else
            {
                printf("Podales bledna litere!\n");
            }
        }
        printf ("\nSzkoda ze nie chcesz sprawdzic jak dzialaja pozostale podprogramy programu nr 1 (zadania styczniowe)\n");
        printf ("\nMoze nastepnym razem. Powodzenia !!!\n");
    }
}

