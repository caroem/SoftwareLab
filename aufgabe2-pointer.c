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
    
    int index = 0;
    int start = 0;
    
    // Suche "::" bis zum Nullterminator Zeichen.
    while(input[index] != '\0'){
        
        if((input[index]==':') && (input[index+1]==':')){
            start = index+2;
        }
        index++;
    }
    return (char*)input + start;
}


char* extract3(char* input){
    int index = 0;
    
    while(input[index] != '\0'){ 
        index++;
    }
    
    while((input[index] != ':' ) && (input[index-1] != ':')){               index--;
    }
    
    return (char*)input+index;
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
    *output = extract3(input); //Ergebnis wird in Main deklarierter variable über Pointer zugewiesen
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
    int index = 0;
    int countWords = 0;
    
    //Wort zuende?
    while(input[index] != '\0'){
        
        //Kein Leerzeichen?
        if(input[index]!= ' '){
            
            //Gehe bis zum Ende des Wortes
            while(input[index] != ' '){
                index++;
            }
            countWords++;
        }
        index++;
    }
    return countWords ;
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
    
    int j = 0;
    int k = 0;
    int i = 0;
    int speicher = 0;
    
    //Wort < maxwords und noch nicht zu Ende
    for(i = 0; i< maxwords; i++){
        //Wortanfang des nächstesn W
        while(  (line[j] == ' ') & (line[j] !='\0' )){
            j++;
        }
        k = j;
        //Ende des nächsten Wortes
        while(  (line[k] != ' ') & (line[k] !='\0') ){
            k++;
        }
      
        if(line[k] !='\0') {        // Suche Wortende
            *(line + k ) ='\0';
            words[i] = line+j;      //Wort in words an stelle i aufnehmen
            j = k + 1;              //Wortende+1 = wortanfang des n. Wortes
        }else {
            speicher = i;
            if(line[j]!='\0'){
                *(line + k ) ='\0';
                words[i] = line+j;
                speicher += 1;
            }
            
            
            i = maxwords;
        }
        
    }
    return speicher; }


int main() {
    
    char* test = "ha::ll::ooo ";
    char* test1 = "das   funktioniert   doch super 5 ";
    char* output;
    
    char line[] = "   this is a   test";
    int countFor;
    int nwords = 10;
    char* words[10];
    
    
    printf("extract1:\n testwort : %s \n", test);
    // printf("Suffix code2 : %s\n\n ", extract3(test));
    printf("Suffix code1 : %s\n\n ", extract(test));
    
    
    extract2(test, &output);
    printf("extract2: %s\n\n", output);
    
    
    printf("Zeichenkette: %s \n", test1);
    printf("Anzahl gezaehlter Woerter: %d \n \n", count(test1));
    
    //Beispieltest fuer Aufgabe2d
    
    
    
    nwords = breakIntoWords(line, 10, words);
    printf("Aufgabe 2d) \n");
    for(countFor = 0; countFor < nwords; countFor++){
        printf(" %d: %s\n", countFor,words[countFor] );
    }
    getchar();
    /*
     
     this
     is
     a
     test
     
     */
}