//
//  GABOREK_STYCZEN_NR-3.c
//  Gaborek_styczen_-_zadanie_nr_3
//
//  Created by Paweł Gaborek on 10/01/2019.
//  Copyright © 2019 Paweł Gaborek. All rights reserved.
//

//Zad. 3.1
//Wczytywać od użytkownika liczby, aż nie poda on 0. Wszystkie wczytane liczby zapisać do pliku numbers.txt
//Zad. 3.2
//Wczytać z numbers.txt liczby. Utworzyć listę jednokierunkową (z zadania 2) zawierającą te liczby. Wypisać je
//na ekran.
//Zad. 3.3
//Posortować (w dowolny sposób) listę z zadania 2.3 (już po wczytaniu z pliku). Zapisać posortowaną liczbę do
//pliku sorted.txt . Algorytm sortowania proszę zaimplementować samodzielnie.






int main(void)
{
    
    // ponizej ogreslilem wszystkie zmienne globalne a takze na dalem im typ zmiennej
    int wybor;                      // zmienna dla switch, wybor podprogramu
    int wyjscie=0;                  // zmienna dla wyjscia z programu
    char kont;                      // zmienna dla wyjscia z programu
    
    puts ("\nWlasnie uruchomiles program nr 3 (zadania styczniowe)");
    puts ("Glowna funkcje main\n");
    
    while(wyjscie == 0) {
        printf ("\nMasz teraz mozliwosc wyboru ktora czesc programu chcesz uruchomic\n");
        printf ("Mozesz wybrac podprogram nr 3.1, 3.2, 3.3\n");
        printf ("Aby uruchomic program nr: \n");
        printf ("\n3.1 wybierz ''1'' \n");
        printf ("\n3.2 wybierz ''2'' \n");
        printf ("\n3.3 wybierz ''2'' \n");
        printf ("Po wprowadzeniu odpowiedniej liczby potwierdz klawiszem ''ENTER''\n");
        scanf ("%i", &wybor);
        switch (wybor)
        {
            case 1:
                // rozpoczynam program nr 3.1 (styczen)
                printf ("Uruchomiles wlasnie kolejny program, zadanie nr 3.%i\n", wybor);
                break;
            case 2:
                // rozpoczynam program nr 3.2 (styczen)
                printf ("Uruchomiles wlasnie kolejny program, zadanie nr 3.%i\n", wybor);
                break;
            case 3:
                // rozpoczynam program nr 3.2 (styczen)
                printf ("Uruchomiles wlasnie kolejny program, zadanie nr 3.%i\n", wybor);
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
        printf ("\nSzkoda ze nie chcesz sprawdzic jak dzialaja pozostale podprogramy programu nr 3 (zadania styczniowe)\n");
        printf ("\nMoze nastepnym razem. Powodzenia !!!\n");
    }
}
