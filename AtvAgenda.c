#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Pessoa{
    int uuid;
    char nome[50];
    char telefone[25];
    char email[50];
    char dataDeNascimento[25];
    char observ[200];
}Pessoa;

//declaração de constantes e funcoes
const int maximoDePessoas = 10;
const int maximoDeUUID = 500;

void mostra(Pessoa _pessoa);
Pessoa leia(int _uuid);
void listar(Pessoa _pessoa[], int pessoasNaAgenda);
void busca(Pessoa _pessoa[]);
void alterar(Pessoa _pessoa[]);
void excluir(Pessoa _pessoa[]);


main(){
    //agenda / espaços para pessoas
    Pessoa pessoa[maximoDePessoas];

    //variaves uteis
    int pessoasNaAgenda = 0;
    char op;
    int idGerados[maximoDeUUID]; //registro de ids, para que os ids nunca se repitam

    //percorre a agenda, limpa todo o lixo das variáveis e zera todos os códigos (UUDIs) dentro do struct
    for(int i=0; i<maximoDePessoas; i++){
        //memset define um valor para uma variavel para os primeiros caracteres definidos
        memset(&pessoa[i], NULL, sizeof(Pessoa));  
    }
    
    //zera o array que registra os ids gerados
    for(int i=0; i<maximoDeUUID; i++){
        idGerados[i] = 0;
    }

    //MENU
    while(op != '0'){
        //Menu
        system("cls");
        printf(" ______________________________________________________________\n");
        printf("|___________________________ AGENDA ___________________________|\n");
        printf("|                                                              |\n");
        printf("|       1- Cadastrar                                           |\n");
        printf("|       2- Listar                                              |\n");
        printf("|       3- Buscar                                              |\n");
        printf("|       4- Alterar                                             |\n");
        printf("|       5- Excluir                                             |\n");
        printf("|                                                              |\n");
        printf("|       0- SAIR                                                |\n");
        printf("|______________________________________________________________|\n");
        printf(" Opcao: ");    
        fflush(stdin);
        scanf(" %c",&op);

        switch(op){   
            case '0':
                system("cls");
            break;

            //CADASTRAR
            case '1':

                //Se a agenda estiver lotada
                if(pessoasNaAgenda >= maximoDePessoas){
                    system("cls");
                    printf(" ______________________________________________________________\n");
                    printf("|___________________________ AGENDA ___________________________|\n");
                    printf("|                                                              |\n");
                    printf("|                         Agenda cheia!                        |\n");
                    printf("|______________________________________________________________|\n");  
                    system("pause");
                }

                //percorre espaços da agenda
                for(int i=0; i<maximoDePessoas; i++){
                                
                    //se tem espaço na agenda
                    if(pessoa[i].uuid == 0){

                        //gera o código unico (UUID) comparando o novo código com os já usados antes  
                        pessoa[i].uuid = 1;

                        for(int j=0; j<maximoDeUUID; j++){

                            while(pessoa[i].uuid == idGerados[j]){            
                                pessoa[i].uuid++;
                            }
                        }
                        
                        //salva o uuid na lista de uuid ja usados
                        for(int j=0; j<maximoDeUUID; j++){
                            if(idGerados[j] == 0){
                                idGerados[j] = pessoa[i].uuid;
                                break;
                            }
                        }

                        pessoa[i] = leia(pessoa[i].uuid);
                        
                        pessoasNaAgenda++;

                        break;
                    }
                }
            break;
            
            //LISTAR
            case '2':
                listar(pessoa,pessoasNaAgenda);
            break;
            
            //BUSCAR
            case '3':
                busca(pessoa);
            break;
            
            //ALTERAR
            case '4':
                alterar(pessoa);
            break;
            
            //EXCLUIR
            case '5':
                excluir(pessoa);
            break;
            
            default:
                system("cls");

                printf(" ______________________________________________________________\n");
                printf("|___________________________ AGENDA ___________________________|\n");
                printf("|                                                              |\n");
                printf("|                  Selecione uma Opcao valida                  |\n");
                printf("|______________________________________________________________|\n"); 
                system("pause");
            break;
        }
    }

}
//--------------------------------------------- FUNÇÕES ----------------------------------------------

//UTIL

//mostra um contato especifico  
void mostra(Pessoa _pessoa){
    
    printf(" ______________________________________________________________\n");
    printf("\n");
    printf("         Codigo Unico: %i\n",_pessoa.uuid);            
    printf("\n");
    printf("         Nome: %s\n", _pessoa.nome);            
    printf("         Telefone: %s\n", _pessoa.telefone);            
    printf("         Email: %s\n", _pessoa.email);            
    printf("         Data de Nascimento: %s\n", _pessoa.dataDeNascimento);            
    printf("         Observacoes: %s\n", _pessoa.observ);            
    printf(" ______________________________________________________________\n");
}

//abre a tela de leitura das informacoes e retorna uma Struct Pessoa para o Array de pessoas  
Pessoa leia(int _uuid){
    Pessoa temp;

    temp.uuid = _uuid;

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|                Digite o nome no campo abaixo                 |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Nome: ");    
    fflush(stdin);
    fgets(temp.nome, sizeof temp.nome, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|              Digite o telefone no campo abaixo               |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Telefone: ");    
    fflush(stdin);
    fgets(temp.telefone, sizeof temp.telefone, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|                Digite a email no campo abaixo                |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Email: ");    
    fflush(stdin);
    fgets(temp.email, sizeof temp.email, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|          Digite a data de nascimento no campo abaixo         |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Data: ");    
    fflush(stdin);
    fgets(temp.dataDeNascimento, sizeof temp.dataDeNascimento, stdin);

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ADICIONAR __________________________|\n");
    printf("|                                                              |\n");
    printf("|           Digite alguma observacao no campo abaixo           |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Observacao: ");    
    fflush(stdin);
    fgets(temp.observ, sizeof temp.observ, stdin);
     
    return temp;
}


//FUNÇÕES DA AGENDA

//lista contatos
void listar(Pessoa _pessoa[], int pessoasNaAgenda){
    
    system("cls");
    //se não existe pessoas na agenda
    if(pessoasNaAgenda == 0){
        system("cls");
        printf(" ______________________________________________________________\n");
        printf("|___________________________ AGENDA ___________________________|\n");
        printf("|                                                              |\n");
        printf("|                         Agenda Vazia                         |\n");
        printf("|______________________________________________________________|\n"); 
        system("pause");        
    }else{

        //exibe a lista
        printf(" ______________________________________________________________\n");
        printf("|_____________________ TODOS OS CONTATOS ______________________|\n");
        for(int i=0; i<maximoDePessoas; i++){
            
            //exibe apenas os contatos não nulos
            if(_pessoa[i].uuid != 0){    
                mostra(_pessoa[i]);
            }
        }
        system("pause");
    }
}

//busca contatos
void busca(Pessoa _pessoa[]){
    int uuid;
    char nome[50];
    char op;
    bool pessoaEncontrada = false;

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|___________________________ BUSCAR ___________________________|\n");
    printf("|                                                              |\n");
    printf("|       1- Pesquisar por codigo unico                          |\n");
    printf("|                                                              |\n");
    printf("|       2- Pesquisar por nome                                  |\n");
    printf("|                                                              |\n");
    printf("|       0- VOLTAR                                              |\n");
    printf("|______________________________________________________________|\n");
    printf(" Opcao: ");   
    fflush(stdin);
    scanf(" %c",&op);
    
    switch(op){
        case '0':
            return 0;
        break;

        //pesquisa por UUID
        case '1':
            system("cls");
            printf(" ______________________________________________________________\n");
            printf("|__________________________ BUSCAR ____________________________|\n");
            printf("|                                                              |\n");
            printf("|            Digite o codigo unico no campo abaixo             |\n");
            printf("|______________________________________________________________|\n");   
            printf(" Codigo unico: ");
            fflush(stdin);   
            scanf(" %i",&uuid);

            //procura os contatos que combine com a busca e indica se um ou mais contatos foram encontrados
            system("cls");
            for(int i=0; i<maximoDePessoas; i++){
 
                if(uuid == _pessoa[i].uuid){
                    
                    mostra(_pessoa[i]);
                    pessoaEncontrada = true;
                }
            }                    
        break;

        //pesquisa por nome
        case '2':
            system("cls");
            printf(" ______________________________________________________________\n");
            printf("|__________________________ BUSCAR ____________________________|\n");
            printf("|                                                              |\n");
            printf("|                Digite o nome no campo abaixo                 |\n");
            printf("|______________________________________________________________|\n");   
            printf(" Nome: ");
            fflush(stdin);   
            scanf("%s",nome);
            
            //procura os contatos que combine com a busca e indica se um ou mais contatos foram encontrados
            system("cls");
            for(int i=0; i<maximoDePessoas; i++){
                
                if(strcmp(nome, _pessoa[i].nome) == 0){

                    mostra(_pessoa[i]);
                    pessoaEncontrada = true;
                }
            }      

        break;

        //opcao invalida
        default:
                system("cls");
                printf(" ______________________________________________________________\n");
                printf("|___________________________ BUSCAR ___________________________|\n");
                printf("|                                                              |\n");
                printf("|                  Selecione uma Opcao valida                  |\n");
                printf("|______________________________________________________________|\n"); 
                system("pause");        
        break;

    }

    //Se não encontrar ninguem na agenda
    if(pessoaEncontrada == false){
        system("cls");
        printf(" ______________________________________________________________\n");
        printf("|__________________________ BUSCAR ____________________________|\n");
        printf("|                                                              |\n");
        printf("|                    Contato nao encontrado                    |\n");
        printf("|______________________________________________________________|\n");   
        system("pause");
    }else{
        //pause pra leitura dos dados encontrados
        system("pause");
    }

}

//altera contatos
void alterar(Pessoa _pessoa[]){
    int uuid;
    bool pessoaEncontrada = false;

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ ALTERAR ____________________________|\n");
    printf("|                                                              |\n");
    printf("|            Digite o codigo unico no campo abaixo             |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Codigo unico: ");   
    fflush(stdin);
    scanf("%i",&uuid);

    //procura os contatos que combine com a busca e indica se um ou mais contatos foram encontrados
    system("cls");
    for(int i=0; i<maximoDePessoas; i++){
        
        if(uuid == _pessoa[i].uuid){
          
            //readiciona o contato (reescrevendo o conteudo)
            _pessoa[i] = leia(_pessoa[i].uuid);
        
            pessoaEncontrada = true;
        }
    }
    
    //Se não encontrar ninguem na agenda
    if(pessoaEncontrada == false){
        system("cls");
        printf(" ______________________________________________________________\n");
        printf("|_________________________ ALTERAR ____________________________|\n");
        printf("|                                                              |\n");
        printf("|                    Contato nao encontrado                    |\n");
        printf("|______________________________________________________________|\n");   
        system("pause");
    }
}

//exclui contatos
void excluir(Pessoa _pessoa[]){
    int uuid;
    char op;
    bool pessoaEncontrada = false;

    system("cls");
    printf(" ______________________________________________________________\n");
    printf("|_________________________ EXCLUIR ____________________________|\n");
    printf("|                                                              |\n");
    printf("|            Digite o codigo unico no campo abaixo             |\n");
    printf("|______________________________________________________________|\n");   
    printf(" Codigo unico: ");   
    fflush(stdin);
    scanf("%i",&uuid);

    //procura os contatos que combine com a busca e indica se um ou mais contatos foram encontrados
    system("cls");
    for(int i=0; i<maximoDePessoas; i++){
        
        if(uuid == _pessoa[i].uuid){
            
            system("cls");
            printf(" ______________________________________________________________\n");
            printf("|_________________________ EXCLUIR ____________________________|\n");
            printf("|                                                              |\n");
            printf("|  Voce esta prestes a exluir este contato, tem certeza disso? |\n");
            printf("|                                                              |\n");   
            
            mostra(_pessoa[i]);
            
            //confirmação de escolha
            printf("Confirme sua escolha (S/N): ");   
            fflush(stdin);
            scanf("%c", &op);
                
            if(op=='s' || op=='S'){
                //exclui o contato (reescrevendo TODO o conteudo pra NULL/0)
                memset(&_pessoa[i], NULL, sizeof(Pessoa));
                
                pessoaEncontrada = true;

                system("cls");
                printf(" ______________________________________________________________\n");
                printf("|_________________________ EXCLUIR ____________________________|\n");
                printf("|                                                              |\n");
                printf("|                      Usuario excluido                        |\n");
                printf("|______________________________________________________________|\n");   
                system("pause");
            
            }else{
                pessoaEncontrada = true;
                break;
            }
        }
    }
    
    //Se não encontrar ninguem na agenda
    if(pessoaEncontrada == false){
        system("cls");
        printf(" ______________________________________________________________\n");
        printf("|_________________________ EXCLUIR ____________________________|\n");
        printf("|                                                              |\n");
        printf("|                    Contato nao encontrado                    |\n");
        printf("|______________________________________________________________|\n");   
        system("pause");
    }
}