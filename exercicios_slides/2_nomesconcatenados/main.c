#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu();
void AdicionarNome( char *entrada );
void RemoverNome( char *entrada );

char *string;

int main( int argc , char const *argv[] )
{
    /*
    ====================
    main
    Chama as funções para começar o programa e inicializa o ponteiro pra a string
    ====================
    */
    string = ( char* )malloc( 2 );
    string[0] = '\0';
    Menu();
    free( string );
    return 0;
}

void Menu ()
{
    /*
    ====================
    Menu
    Printa o menu e recolhe a escolha do usuário
    ====================
    */

    int entrada;
    char buff[255];

    while ( entrada != 4 )
    {
        printf( "Digite 1 Para Adicionar Um Nome: \nDigite 2 Para Remover Um Nome: \nDigite 3 Para Listar: \nDigite 4 Para Sair:\n" );
        fgets( buff, 255 , stdin );
        sscanf( buff, "%d" , &entrada );
        switch ( entrada )
        {
        case 1: 
            printf( "Digite O Nome: ");
            fgets( buff, 255 , stdin );
            buff[strcspn( buff, "\n" )] = '\0';
            AdicionarNome( buff );
            break;
        
        case 2:
            printf( "Digite O Nome: ");
            fgets( buff, 255 , stdin );
            buff[strcspn( buff, "\n" )] = '\0';
            RemoverNome( buff );
            break;

        case 3:
            printf( "%s\n" , string);
            break;
        }
    }
}

void AdicionarNome( char *entrada )
{
    /*
    ====================
    AdicionarNome
    Adiciona o nome na string
    ====================
    */
    string = ( char* )realloc( string , strlen( string ) + strlen( entrada ) + 1 );
    strcat( string , entrada);
}

void RemoverNome( char *entrada )
{
    /*
    ====================
    RemoverNome
    Remove o nome da string
    ====================
    */ 
    char *temp;
    temp = strstr( string , entrada );
    temp[0] = '\0';
    for ( int index = 0 ; index < strlen(entrada) ; index++ ){
        temp++;
    }
    strcat( string , temp);
    string = ( char* )realloc( string , strlen( string ) + 1 );
}