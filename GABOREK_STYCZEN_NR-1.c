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

typedef struct Student Student;


typedef enum {TRUE = 1, FALSE = 0} bool;

bool AreEqueal(Student* s1, Student* s2);
{
bool containsDigits(char *str)
{
    
    int j=0;
    int w4=0;
    int w5=0;
    bool w6;
    bool dig;
    while (str[j] != '\0')
    {
        if (isdigit(str[j]))
            w4=w4+1;
        else
            w5=w5+1;
        j++;
    }
    if (w4==0)
        w6=1;
    else
        w6=0;
    return w6;
}

Student* Create(int age, int height, int semester)


void PrintStudent(Student *s)





int main(void)
{
    
    // ponizej ogreslilem wszystkie zmienne globalne a takze na dalem im typ zmiennej
    int wybor;                      // zmienna dla switch, wybor podprogramu
    int wyjscie=0;                  // zmienna dla wyjscia z programu
    char kont;                      // zmienna dla wyjscia z programu
    
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
                
                Student * student = (Student*) malloc (sizeof(Student)); // zaalokuj pamięć na X bajtów, gdzie X to wyliczony przez kompilator rozmiar struktury Student
                student->Age = 25;
                student->Semester = 6;
                free(student); // zwolnij pamięć
                
                break;
            case 2:
                // rozpoczynam program nr 1.2 (styczen)
                printf ("Uruchomiles wlasnie kolejny program, zadanie nr 1.%i\n", wybor);
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
