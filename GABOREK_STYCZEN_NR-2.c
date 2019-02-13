//
//  GABOREK_STYCZEN_NR-2.c
//  Gaborek_styczen_-_zadanie_nr_2
//
//  Created by Paweł Gaborek on 10/01/2019.
//  Copyright © 2019 Paweł Gaborek. All rights reserved.
//

//Zad 2 (w zadaniu jest chyba blednie oznaczone jako 1. a pozniej jest odrazu nr 3).
//Zaimplementować cykliczną listę jednokierunkową. Powinna ona zawierać struktury węzła:
//struct Node
//int Value;
//Node * Next;
//Należy zaimplementować metody do operacji na liście. Poniżej znajduje się kod funkcji main oraz wszystkie
//sygnatury. Zadanie polega na dopisaniu CIAŁA poszczególnych funkcji, aby kod się skompilował izachował się
//zgodnie z tym, co napisano w komentarzach. UWAGA - proszę nie modyfikować funkcji main i NIE STOSOWAĆ
//zmiennej statycznej, zadeklarowanej poza funkcją main.

//include <stdio.h>
//include <stdlib.h>

//typedef struct Node Node;
//struct Node
//int Value;
//Node * Next;

//Node * Create (int value); // tworzy listę jednoelementową (alokuje węzeł), która ma węzeł wskazujący na
//samego siebie jako następnik
//Node* GetTail(Node* root); // metoda musi ustalić pozycję ostatniego elementu mając dostęp do korzenia
//izwrócić jego adres (uwaga - nie jest tu wymagany malloc!)
//void Add(Node* root, int value); //dodaje węzeł dolisty, której KORZEŃ jest przekazany jako parametr, do
//znalezienia końca listy należy użyć metody GetTail() z powyżej
//void PrintList(Node* root); // metoda powinna wypisać listę, mając tylko jej korzeń. Należy użyć GetTail()
//do
//określenia, kiedy zakończyć wypisywanie
//void RemoveNode(Node * root, int value); // metoda powinna usunąć węzeł o WARTOŚCI podanej jako parametr,
//mając tylko korzeń listy. UWAGA - należy usunąć węzeł, zwolnić pamięć po nim inie naruszyć integralności
//listy (powinna nastąpić zmiana następnika węzła PRZED usuwanym węzłem, na zasadzie: 2->4->8->16->2->(...),
//usuwamy węzeł 4, nowa lista: 2->8->16->2->(...)
//void FreeList(Node * root); // metoda czyści pamięć po liście, usuwając wszystkie węzły metodą free() int
//Count(Node *root); // metoda zwraca rozmiar listy

//int main(int argc, const char * argyvl]) £
//Node * root = Create(2);
//PrintList(root); // 2

//Add(root, 4);
//Add(root, 8);
//Add(root, 16);
//PrintList(root); // 2 -> 4 -> 8 -> 16
//Add(root, 20);
//PrintList(root); // 2 -> 4 -> 8 -> 16 -> 20
//printf("Ostatni wezel ma wartosc %d", GetTail(root)->Value); // 20 Add(root, 16);
//PrintList(root); // 2 -> 4 -> 8 -> 16 -> 20 -> 16 printf("%d", Count(root)); // 6

//RemoveNode(root, 8);
//PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16 RemoveNodef(root, 10); // element nieistniejący
//PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16
//RemoveNodefroot, 16); // usuń wszystkie węzły o wartości 16 PrintList(root); // 2 -> 4 -> 20
//printf("%d", Count(root)); // 3

//FreeList(root); // zwolnienie pamięci na wszystkie węzły. PrintList(root); // (nic, lista niezaalokowana)
//return 0;

//Il TODO- implementacja funkcji z sygnatur

//Uwaga - w Internecie znajduje się dużo „gotowców” listy jednokierunkowej. Proszę mi wierzyć, że przez parę
//lat pracy na uczelni już większość z nich widziałem i wielokrotnie studenci próbowali oddawać nie swój kod -
//proszę o napisanie własnej implementacji samodzielnie, a sugerowanie się gotowym rozwiązaniem TYLKO w
//zupełnej ostateczności. Często gotowce są bardziej „wizją” autora, która nijak ma się do sedna problemu.
//Oddanie gotowca będzie się równało z oceną niedostateczną na koniec semestru.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//************************************************************************************************************
//
//========================================   WAŻNE   !!!!!!!!    =============================================
//
//   w poniższym zadniu opierałem się na podstawie wykładów Pana dr hab. Wojciech Bożejko z Politechniki
//   Wrocławskiej (Pan dr Fedorow nie umieścił materiałów na e-dziekanacie a z książki "Programowanie w C",
//   autor Ritchie Kernighan, jeszcze nie przerobiłem do końca)
//
//
//************************************************************************************************************



typedef struct Node Node;

struct Node
{
    int Value;
    Node * Next;
};


/*************************************************************************************************
 Ponizej tworze pierwszy element listy a adresem
 *************************************************************************************************/

Node * Create (int value)
{
    
    Node * zmiennaPoczatkowa=NULL;
    
    Node * zmiennaTymczasowa;
    zmiennaTymczasowa = (Node*)malloc(sizeof(Node));
    
    zmiennaTymczasowa->Value = value;
    zmiennaTymczasowa->Next = zmiennaPoczatkowa;
    zmiennaPoczatkowa = zmiennaTymczasowa;
    
    return 0;
}

/*************************************************************************************************
 Ponizej znajduje adres ostatniego elementu listy
 *************************************************************************************************/

Node * GetTail(Node * root)

{
    Node * zmiennaTymczasowa;
    while (root != NULL)
    {
        zmiennaTymczasowa = root;
        zmiennaTymczasowa = zmiennaTymczasowa->Next;
    }
    return zmiennaTymczasowa;
}
    
/*************************************************************************************************
 ponizej wstawiam element za ostatni element listy. Najpierw znajduje adres ostatniego elementu.
 *************************************************************************************************/

void Add(Node* root, int value)

{
    Node *elementKoncowy = GetTail(root);
    
    Node *zmiennaPomocnicza;
    zmiennaPomocnicza = (Node*)malloc(sizeof(Node));
      
    zmiennaPomocnicza->Value = value;
    zmiennaPomocnicza->Next = elementKoncowy->Next;
    elementKoncowy->Next = zmiennaPomocnicza;
}

/*************************************************************************************************
 Ponizej wypisuje liste i wartosi poszczegolnych wezlow "NODE"
 *************************************************************************************************/

void PrintList(Node * root)
{
    Node *adresOstatniegoElementu = GetTail(root);
    Node *zmiennaTymczasowa;
    for(zmiennaTymczasowa = root ; zmiennaTymczasowa == adresOstatniegoElementu ; zmiennaTymczasowa = zmiennaTymczasowa->Next)
    {
        printf ("Twoim elementem listy o adresie:", zmiennaTymczasowa);
        printf ("Jest element o wartosci: %i",
                zmiennaTymczasowa->Value);
    }
}

/*************************************************************************************************
 Usuwam wezly ktore maja okreslona wartosc "Value"
 *************************************************************************************************/

void RemoveNode(Node * root, int value)

{
    Node * zmiennaPomocnicza;
    Node * zmiennaTymczasowa = root;
    while (zmiennaTymczasowa != NULL)
        
        zmiennaTymczasowa = zmiennaTymczasowa->Next;
        
        if (zmiennaPomocnicza->Value = value)
        {
            zmiennaPomocnicza = root;
            root = zmiennaPomocnicza->Next;
            free (zmiennaPomocnicza);
        }
        else
            zmiennaTymczasowa = zmiennaTymczasowa->Next;
}

/*************************************************************************************************
 Ponizej czyszcze liste
 *************************************************************************************************/

void FreeList(Node * root)
{
    Node *zmiennaPomocnicza;
    while (root != NULL)
        {
            zmiennaPomocnicza = root;
            root = zmiennaPomocnicza->Next;
            free (zmiennaPomocnicza);
        }
}
    
    

int main(void)
{
    
    // ponizej ogreslilem wszystkie zmienne globalne a takze na dalem im typ zmiennej
    int wybor;                      // zmienna dla switch, wybor podprogramu
    int wyjscie=0;                  // zmienna dla wyjscia z programu
    char kont;                      // zmienna dla wyjscia z programu
    
    puts ("\nWlasnie uruchomiles program nr 2 (zadania styczniowe)");
    puts ("Glowna funkcje main\n");
    
    while(wyjscie == 0) {
        puts ("\nTeraz przystapisz do pracy z programem z zadania nr 2");
    
        
        Node * root = Create(2);
        PrintList(root); // 2
        
        Add (root, 4);
        Add (root, 8);
        Add (root, 16);
        
        PrintList (root); // 2 -> 4 -> 8 -> 16
        
        Add (root, 20);
        
        PrintList (root); // 2 -> 4 -> 8 -> 16 -> 20
        
        printf ("Ostatni wezel ma wartosc %d", GetTail(root)->Value); // 20
        
        Add(root, 16);
       
        PrintList(root); // 2 -> 4 -> 8 -> 16 -> 20 -> 16
        
        printf("%d", Count(root)); // 6
        
        RemoveNode(root, 8);
        
        PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16
        
        RemoveNodef(root, 10); // element nieistniejący
        
        PrintList(root); // 2 -> 4 -> 16 -> 20 -> 16
        
        RemoveNode (root, 16); // usuń wszystkie węzły o wartości 16 PrintList(root); // 2 -> 4 -> 20
        
        printf("%d", Count(root)); // 3
        
        FreeList(root); // zwolnienie pamięci na wszystkie węzły. PrintList(root); // (nic, lista niezaalokowana)
        return 0;
    
        
        puts ("\nSuper ! Wlasnie program nr 2 zakonczyl dzialanie");
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
        printf ("\nSzkoda ze nie chcesz sprawdzic jak dzialaja pozostale podprogramy programu nr 2 (zadania styczniowe)\n");
        printf ("\nMoze nastepnym razem. Powodzenia !!!\n");
    }
}
