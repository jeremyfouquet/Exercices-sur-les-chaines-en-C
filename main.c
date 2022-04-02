//
//  main.c
//  ExoREV4Chaines
//
//  Created by web development on 02/04/2022.
//

#include <stdio.h> // puts(), printf()
#include <stdlib.h> // exit()
#include <string.h> // strlen()

#define string char *

void exercice_D_1(const string) ; // prototype
int my_strcmp(const string S1, const string S2) ;
void exercice_D_2(const string) ; // prototype
void exercice_D_3(const string) ; // prototype
void exercice_D_4(const string) ; // prototype
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
    int idem = my_strcmp("abc", "abc") ;
    int plusGrand = my_strcmp("abc", "abbbe") ;
    int plusPetit = my_strcmp("abc", "abcd") ;
}
int my_strcmp(const string S1, const string S2){
    // https://waytolearnx.com/2019/08/comparer-deux-chaines-de-caracteres-en-c.html
    int compare = 0;
    int i;
    for(i = 0; S1[i] == S2[i] && S1[i] != '\0'; i++);
    if(S1[i] > S2[i]){
        compare = 1;
        printf("%s est superieur à %s = %d\n", S1, S2, compare);
    }
    else if(S1[i] < S2[i]) {
        compare = -1;
        printf("%s est inferieur à %s = %d\n", S1, S2, compare);
    }
    else {
        compare = 0;
        printf("%s est égale à %s = %d\n", S1, S2, compare);
    }
    puts("");
    return compare;
}
void exercice_D_2(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "");
    puts("");
}
void exercice_D_3(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "");
    puts("");
}
void exercice_D_4(const string titre) {
    printf("\n%s\n", titre);
    printf("\n%s\n", "");
    puts("");
}

void usage(const string D) {
    printf("Erreur en provenance de : %s\n", D);
    exit(1) ;
}
