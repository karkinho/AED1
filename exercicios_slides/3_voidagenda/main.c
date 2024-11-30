#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Adicionar();
void Remover();
void Listar();
void Buscar();
void Menu();

const int sizePessoa = 10 + sizeof( int ) * 2;
void *pBuffer;

int main( int argc , char const *argv[] ){
    pBuffer = malloc( sizeof( int ) );
    *( int* )pBuffer = 0;
    Menu();
    free( pBuffer );
    return 0;
}

void Menu(){
    /*
    ======================  
    Menu
    Menu entre as funções da agenda
    ======================
    */
    int escolha;
    char buff[5];
    while ( escolha != 5 ){
        printf( "Digite 1 Para Adicionar:\n" );
        printf( "Digite 2 Para Remover:\n" );
        printf( "Digite 3 Para Buscar:\n" );
        printf( "Digite 4 Para Listar:\n" );
        printf( "Digite 5 Para Sair:\n" );
        fgets( buff , 5 , stdin );
        sscanf( buff , "%d" , &escolha );
        switch ( escolha )
        {
        case 1:
            Adicionar();
            break;
        case 2:
            Remover();
            break;
        case 3:
            Buscar();
            break;
        case 4:
            Listar();
            break;
        }
    }
    return;
}

void Adicionar(){
    /*
    ======================  
    Adicionar

    Adiciona pessoas na agenda
    ======================
    */
    char buff[11];
    void *auxpointer;
    pBuffer = realloc( pBuffer , sizePessoa * ( *( int* )pBuffer + 1 ) + sizeof( int ) );
    auxpointer = pBuffer + sizeof( int ) + ( *( int* )pBuffer * sizePessoa );
    printf("Digite o nome da pessoa:\n");
    fgets( buff , 11 , stdin );
    buff[strcspn( buff, "\n" )] = '\0';
    strcpy( ( char* )auxpointer , buff );
    auxpointer += 10;
    printf("Digite o idade da pessoa:\n");
    fgets( buff , 11 , stdin );
    sscanf( buff , "%d" , ( int* )auxpointer );
    auxpointer += sizeof( int );
    printf("Digite o telefone da pessoa:\n");
    fgets( buff , 11 , stdin );
    sscanf( buff , "%d" , ( int* )auxpointer );
    *( int* )pBuffer += 1;
    return;
}

void Listar(){
    /*
    ======================  
    Listar

    Lista todos os individuos na agenda
    ======================
    */
    void *auxpointer = pBuffer;
    auxpointer += sizeof( int );
    for ( int index = 1 ; index <= *( int* )pBuffer ; index++ ){
        printf( "%d:Nome: %s\n" , index , ( char* )auxpointer );
        auxpointer += 10;
        printf( "%d:Idade: %d\n" , index , *( int* )auxpointer );
        auxpointer += sizeof( int );
        printf( "%d:Telefone: %d\n" , index , *( int* )auxpointer );
        auxpointer += sizeof( int );
    }   
    return;
}

void Buscar(){
    /*
    ======================  
    Buscar

    Bucar um individuo na agenda e mostra seus dados
    ======================
    */
    char buff[11];
    void *auxpointer = pBuffer + sizeof( int );
    printf( "Digite o Nome da Pessoa Que Deseja Encontrar:\n" );
    fgets( buff , 11 , stdin );
    buff[strcspn( buff, "\n" )] = '\0';
    for ( int index = 0 ; index < *( int* )pBuffer ; index++ )
    {
        if ( strcmp( buff , ( char* )auxpointer ) == 0 ){
            printf( "Pessoa Encontrada!!!\n" );
            printf( "Nome: %s\n" , ( char* )auxpointer );
            auxpointer += 10;
            printf( "Idade: %d\n" , *( int* )auxpointer );
            auxpointer += sizeof( int );
            printf( "Telefone: %d\n" , *( int* )auxpointer );
            return;
        }
        auxpointer += sizePessoa;
    }
    printf( "Pessoa Não Encontrada :(\n" );
    return;
}

void Remover(){
    /*
    ======================  
    remove

    Remove um individuo da agenda
    ======================
    */
    char buff[11];
    void *auxpointer = pBuffer + sizeof( int ) , *movePoint;
    int sizeMove;
    printf( "Digite o Nome da Pessoa Que Deseja Remover:\n" );
    fgets( buff , 11 , stdin );
    buff[strcspn( buff, "\n" )] = '\0';
    for ( int index = 1 ; index <= *( int* )pBuffer ; index++ )
    {
        if ( strcmp( buff , ( char* )auxpointer ) == 0 ){
            movePoint = auxpointer + sizePessoa;
            sizeMove = ( *( int* )pBuffer - index ) * sizePessoa;
            break;
        }
        auxpointer += sizePessoa;
    }
    memmove( auxpointer , movePoint , sizeMove );
    *( int* )pBuffer -= 1;
    pBuffer = realloc( pBuffer , sizePessoa * ( *( int* )pBuffer ) + sizeof( int ) );
    return;
}