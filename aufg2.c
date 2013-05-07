/**
 * @file   aufgabe2-pointer.c
 * @brief  Aufgabe2 - Pointermanipulationen
 */

#include <stdio.h>


// Falls notwendig erweitern Sie die Liste der includes

/**
 @brief Aufgabe2a: Scannen durch einen String
 @param [in] char* input
 @return char*
 
 Input ist ein String der aus alphanumerischen Zeichen besteht die
 durch :: getrennt sein koennen. Als Beispiele betrachte man
 
 <p>
 
 <ul>
 <li> "Ha::ll::o"
 <li> "47::11"
 </ul>
 
 Ihre Aufgabe ist es eine Funktion zu schreiben die den
 laengsten suffix (Endung) liefert der kein :: enthaelt.
 Laengste Endungen fuer unsere Beispiele:
 <ul>
 <li> "o"
 <li> "11"
 </ul>
 
 <p>
 
 Input ist der String (char pointer), das Ergebnis soll als
 return Wert geliefert werden, welcher ein Zeiger auf den
 Anfang der laengsten Endung ohne :: ist.
 
 */

char* extract(char* input) {
    
    /*
     die methode geht von anfang duch input solange bis es zwei aufeinanderfolgende Doppeltpunkte findet
     und zwar solange bis zum '\0'
     returned wird dann ein pointer dass auf input + wortAnfang zeigt
     also auf das letzte wort nach dem letzten ::
     */
    
    int index = 0;
    int wortAnfang = 0;
    
    while(input[index] != '\0'){
        
        if((input[index]==':') && (input[index+1]==':')){
            wortAnfang=index+2;
        }
        index++;
    }
    return (char*)input+wortAnfang;
    
}

/**
 @brief Aufgabe2b: Variation von 2a
 @param [in] char* input
 @param [out] char** output
 
 Das Ergebnis soll hier nicht als return Wert geliefert werden.
 Anstatt wird ein pointer auf einen pointer verwendet.
 Wieso reicht ein pointer nicht aus?
 */

void extract2(char* input, char** output) {
    
    *output = extract(input);
    
}

/**
 @brief Aufgabe2c: Weitere Variation von Scannen
 @param [in] char* input
 @return int
 
 Input ist ein String der aus einer Liste von alphanumerischen Woertern
 die durch Leerzeichen (white-space) getrennt sind.
 Ihre Aufgabe ist es eine Funktion zu schreiben, die die Anzahl der
 Woerter zaehlt.
 <p>
 Beispiel:  "Ha ll o 5"
 <p>
 Soll liefern 4
 */

int count(char* input) {
    
    /*
     die erste while schleife prüft ob wort noch nicht zuende ist, die zweite while schleife
     prüft ob es buchstaben gibt wenn ja läuft es bis ans ende des wortes und zählt dann count
     eins hoch für die einzelnen wörter
     Die Methode gibt die Anzahl der Wörter zurück
     
     */
    
    int count = 0;
    int i=0;
    while(input[i] != '\0'){
        while(input[i] != ' '){
            while(input[i] != ' ' && input[i] != '\0'){
                i++;
            }
            count++;
        }
        i++;
    }
    return count;
    
}


/**
 @brief Aufgabe2d: Aufsammeln von Woertern. Erweiterung von Aufgabe2c.
 @param [in] char* line
 @param [in] int maxwords
 @param [out] char* words[]
 @return int Anzahl aufgesammelter Woerter
 
 Gegeben (als Input) ist ein String der aus einer Liste von alphanumerischen
 Woertern die durch Leerzeichen (white-space) getrennt sind.
 Ihre Aufgabe ist es die Woerter in einem Array von Strings aufzusammeln.
 Das Array von Strings words wird pre-allokiert mit fester Groesse (maxwords).
 Die Anzahl der aufgesammelten Woerter wird als return Wert zurueck
 geliefert.
 
 */

int breakIntoWords(char *line, int maxwords, char *words[]) {
    
    /*
     in die erste while gehts rein solange das wort noch nicht zu ende ist und auch nur so oft wie maxwords
     die nächste while sucht den wortanfang und anschließend wird wortEnde dem wortAnfang gleichgesetzt
     falls vorher noch leerzeichen sind.
     danach wird das wortende gesucht und bleibt nach dem wort stehen
     falls da nur ein leerzeichen ist wird dort ein '\0' hingesetzt ('künstliches' wortende)
     anschließend wirt das wort in worts[] aus line[] überschrieben
     und die wörter dabei in countWoerter gezählt
     und wortanfang und wortende werden dann auf den ersten buchstaben des nächsten wortes gesetzt
     
     Die Methode returned die anzahl der überschriebenen wörter in words[]
     */
    
    
    int countWoerter = 0;
    int wortAnfang = 0;
    int wortEnde = 0;
    int j = 0;
    int i = 0;
    
    while(line[wortEnde] != '\0' && i < maxwords){
        
        while(line[wortAnfang] == ' '){
            wortAnfang++;
        }
        wortEnde = wortAnfang;
        
        while(line[wortEnde] != ' ' && line[wortEnde] != '\0'){
            wortEnde++;
        }
        
        if(line[wortEnde] == ' '){
            *(line + wortEnde) = '\0';
            words[j] = line + wortAnfang;   //line + wortAnfang pointet auf den ersten Buchstaben
            i++;
            countWoerter++;
            j++;
            
            wortAnfang = wortEnde + 1;
            wortEnde = wortAnfang;
            
        }else{
            words[j] = line + wortAnfang;
            i++;
            countWoerter++;
        }
    }
    
    
    return countWoerter;
    
}


int main(){
    
    char *test = "Hal::l::ooo";
    char *test1 = "Hallo guten tag";
    char *output;
    char line[] = "hallo guten   tag ";
    int countFor = 0;
    int nwords = 10;
    char *words[10];
    
    // Aufgabe 2a)
    
    printf("Aufgabe 2a : \n");
    printf("extract: %s \n\n", extract(test) );
    
    // Aufgabe 2b)
    
    printf("Aufgabe 2b : \n");
    extract2(test, &output);
    printf("extract2: %s\n\n", output);
    
    // Aufgabe 2c)
    
    printf("Aufgabe 2c : \n");
    printf("Anzahl gezaehlter Woerter: %d \n \n", count(test1));
    
    // Aufgabe 2d)
    
    printf("Aufgabe 2d :\n");
    nwords = breakIntoWords(line, 2, words);
    printf("Aufgabe 2d) \n Speicher: %d\n",nwords);
    
    for(countFor = 0; countFor < nwords; countFor++){
        printf(" %d: %s\n", countFor,words[countFor] );
    }
    getchar();
}


// Ihre Testroutinena

/* Beispieltest fuer Aufgabe2d
 char line[] = "this is a test";
 int i;
 int nwords;
 char* words[10];
 
 nwords = breakIntoWords(line, words, 10);
 for(i = 0; i < nwords; i++)
 printf("%s\n", words[i]);
 
 soll liefern
 
 this
 is
 a
 test
 
 */