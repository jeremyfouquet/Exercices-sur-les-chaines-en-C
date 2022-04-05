//
//  main.c
//  ExoREV4Chaines
//
//  Created by jeremy fouquet on 02/04/2022.
//

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define string char *
#define formatBool(b) ((b) ? "true" : "false")

void exercice_D_1(const string) ; // prototype
int my_strcmp(const string S1, const string S2) ;
void exercice_D_2(const string) ; // prototype
string strstr(const string Source, const string SousChaine) ;
void exercice_D_3(const string) ; // prototype
int my_strstrs(const string S1, const string S2) ;
void exercice_D_4(const string) ; // prototype
string my_strchr(char C, string S) ;
void usage(const string); // prototype

int main(int argc, const char * argv[]) {
    printf("%s\n", "D. Exercices sur les chaînes");
    puts("");
    exercice_D_1("D.1 Comparaison de chaînes");
    exercice_D_2("D.2 Détecter une chaîne dans une autre");
    exercice_D_3("D.3 Compter le nombre d’occurrences d’une chaîne");
    exercice_D_4("D.4 Position d’un caractère dans une chaîne");
    puts("");
    return 0;
}

void exercice_D_1(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Cette fonction renvoie un nombre qui est négatif si la première chaîne est inférieure à la deuxième, zéro si elles sont égales, positif si la première chaîne est plus grande que la deuxième ; une chaîne est plus grande qu’une autre si soit le premier caractère différent est plus grand (en code ascii) ou si elle est plus longue : abc est plus grand que abbbe, et abcd est plus grand que ab.");
    puts("");
    string S1;
    string S2;
    printf("resultat retourné : %d\n", my_strcmp(S1 = "abc", S2 = "abc"));
    printf("resultat retourné : %d\n", my_strcmp(S1 = "abc", S2 = "abbbe"));
    printf("resultat retourné : %d\n", my_strcmp(S1 = "abc", S2 = "abcd"));
}
int my_strcmp(const string S1, const string S2){
    // https://waytolearnx.com/2019/08/comparer-deux-chaines-de-caracteres-en-c.html
    //    Spécification en Lisp :
    //    (string-compare 'abc 'abbbe) => 1
    //    (string-compare 'abc 'abcd) => -1
    //    (string-compare 'abc 'abc) => 0
    int compare = 0;
    int i;
    for(i = 0; S1[i] == S2[i] && S1[i] != '\0'; i++);
    if(S1[i] > S2[i]){
        compare = 1;
        printf("\n%s est superieur à %s\n", S1, S2);
    }
    else if(S1[i] < S2[i]) {
        compare = -1;
        printf("\n%s est inferieur à %s\n", S1, S2);
    }
    else {
        compare = 0;
        printf("\n%s est égale à %s\n", S1, S2);
    }
    return compare;
}
void exercice_D_2(const string titre) {
    //https://koor.fr/C/cstring/strstr.wp
    printf("\n%s\n", titre);
    printf("\n%s\n", "Si la sous-chaîne est trouvée dans la chaîne principale, la fonction renvoi un pointeur visant sa première occurrence. Dans le cas contraire, un pointeur nul (NULL) vous sera renvoyé.");
    string Source = "abbbe";
    string SousChaine = "abc";
    printf("\nRecherche %s dans %s\n", SousChaine, Source);
    printf("\nRetoure de la fonction : %s\n", strstr(Source, SousChaine));
    Source = "ddabcd";
    printf("\nRecherche %s dans %s\n", SousChaine, Source);
    printf("\nRetoure de la fonction : %s\n", strstr(Source, SousChaine));
    puts("");
}
void exercice_D_3(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Cette fonction renvoie le nombre de fois où la sous chaine à été trouvé dans la chaine source");
    string Source = "abbbe";
    string SousChaine = "abc";
    printf("\nIl y a %d occurence(s) de %s dans %s\n", my_strstrs(Source, SousChaine), SousChaine, Source);
    Source = "ddabcdabc";
    printf("\nIl y a %d occurence(s) de %s dans %s\n", my_strstrs(Source, SousChaine), SousChaine, Source);
    puts("");
}

int my_strstrs(const string Source, const string SousChaine) {
    // https://www.developpez.net/forums/d1323227/c-cpp/c/compter-occurrences-d-chaine/
    int i, j, k, compteur = 0;
    for (i=0; Source[i]; i++)
        for (j = i, k =0; Source[j] == SousChaine[k]; j++, k++)
            if (! SousChaine[k + 1])
                compteur++;
    return(compteur);
}
void exercice_D_4(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "Cette fonction renvoie le pointeur sur le caractère dans la chaîne, ou NULL si celui ci n'existe pas dans la chaine.");
    char C = 'a';
    string S = "bads";
    printf("\nLa position de %c dans %s est %s\n", C, S, my_strchr(C, S));
    C = 'x';
    S = "bads";
    printf("\nLa position de %c dans %s est %s\n", C, S, my_strchr(C, S));
    puts("");
}


string my_strchr(char C, string S) {
    if (C != * S && * S) return my_strchr(C, S+1) ;
    if (* S == '\0') return NULL;
    else return S;
};

void usage(const string D) {
    printf("Erreur en provenance de : %s\n", D);
    exit(1) ;
}
