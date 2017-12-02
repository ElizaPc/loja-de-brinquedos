#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>


struct data{
	
	int dia,mes,ano;
	
}D;

struct endereco{
	
	char rua[30];
	char numero[30];
	char bairro[30];
	char cidade[30];
	char uf[2];
	
}E;

struct cliente{
	
	char nome[30];
	char cpf[30];
	struct endereco ender;
	struct data dt;
	int on;
	 
}Cliente,*p;

void CadastroCliente(FILE *file,struct cliente *cli,int a){
	
	system("cls");
	file = fopen("trab_eda.txt","a");
	
	printf("\t\t\t\t\t---Cadastro Cliente----\n");
	
	printf("Nome: ");
	fflush(stdin);
	gets(cli->nome);
	
	printf("\nCPF: ");
	fflush(stdin);
	gets(cli->cpf);
	
	printf("\n---Data de Nascimento---\n");
	printf("Dia: ");
	scanf("%d",&cli->dt.dia);
	printf("\nMes: ");
	scanf("%d",&cli->dt.mes);
	printf("\nAno: ");
	scanf("%d",&cli->dt.ano);
	
	
	printf("\n---Endereco---\n");
	printf("Rua: ");
	fflush(stdin);
	gets(cli->ender.rua);
	printf("\nNumero: ");
	fflush(stdin);
	gets(cli->ender.numero);
	printf("\nBairro: ");
	fflush(stdin);
	gets(cli->ender.bairro);
	printf("\nCidade: ");
	fflush(stdin);
	gets(cli->ender.cidade);
	printf("\nUF: ");
	fflush(stdin);
	gets(cli->ender.uf);
		
	cli->on = 1;
	
	fwrite(&Cliente, sizeof(struct cliente),1, file);
	
	fclose(file);	
}

void consultar(){
		
		system("cls");
		char nome[60],*result,aux[5] = "fim\n";
		int r;
	
		struct cliente *cc,clt;
		cc = &clt;
		
		FILE *file;
 	
 		file = fopen("trab_eda.txt", "r");
 		
        printf ("\n\n***MENU CONSULTAR***\n\n");
        
        do{
        	result = fgets(nome,60,file);
        	
        	r = strcmp(nome,aux);;
        	if(r != 0 && result != NULL){
        		printf("%s",result);
        		
			}else{
				printf("\n");
			}
			
		}while(result != NULL);
	
		fclose(file);
		
		getchar();
		
}

void excluir(){
    system("cls");
    char cpf[20], opcao;
    int pos = 0, aux = 0;

    p = &Cliente;
    
    FILE *file;
    file = fopen("trab_eda.txt","r+");

    if(file == NULL){
        printf("Não entrou no arquivo\n");
        getchar();
    }else{

        fflush(stdin);
        printf("Informe o CPF para excluir o cadastro: ");
        gets(cpf);

        while(!feof(file)){
            if(fread(&Cliente, sizeof(struct cliente),1, file) == 1){
                if(strcmp(cpf, p->cpf) == 0){
                    if(p->on == 1){
                        printf("\n\tINFORMAÇOES DO CLIENTE\n");
                        printf("\nNome: %s ", p->nome);
                        printf("\nCPF: %s", p->cpf);
                        printf("\nData de nasimento: %d/%d/%d", p->dt.dia, p->dt.mes, p->dt.ano);
                        printf("\n\n\tENDEREÇO\n");
                        printf("\nRua: %s", p->ender.rua);
                        printf("\nNumero: %d", p->ender.numero);
                        printf("\nBairro: %s", p->ender.bairro);
                        printf("\nCidade: %s", p->ender.cidade);
                        printf("\nUF: %s\n", p->ender.uf);
                        aux = pos + 1;
                        getchar();
                        break;
                    }
                }
            }
    pos++;
    }
    if(aux == 0){
        printf("\nCliente não encontrado\n");
        getchar();
    }else{
        do{
            system("cls");
            fflush(stdin);
            printf("\n\nDeseja mesmo exluir esse cliente (s\\n)?\n");
            scanf("%c", &opcao);
            opcao = tolower(opcao);
            if(opcao == 's'){
                p->on = 0;
                fseek(file, sizeof(struct cliente)*(aux-1), SEEK_SET);
                fwrite(&Cliente, sizeof(struct cliente), 1, file);
                printf("Cliente excluido com sucesso:");
            }else if(opcao == 'n'){
                printf("\nOkay, aperte qualquer tecla para voltar ao menu\n");
            }else if(opcao != 'n' && opcao != 's'){
                printf("\nOpcão Invalida\n");
                getchar();
            }
        }while(opcao != 'n' && opcao != 's');
    fclose(file);
    getchar();
    }
    }
}

struct validade{
    int dia,mes,ano;
}V;

typedef struct brinquedo{
    int cod,qt_est;
    char descricao[100],modelo[100],fabricante[100];
    float valor_compra,valor_venda;
    struct validade *valid = &V;
}BRINQUEDO;

//void cadastra(FILE *file,BRINQUEDO *p1,int c){
//    file = fopen("trab_eda.txt","a");
//    fflush(stdin);
//    
//    printf("\n");
//    printf("\t\t\t\t\t---Cadastro Brinquedo---\n\n");
//    
//    printf("Digite o Código do Brinquedo: "); 
//	scanf("%d",&p1->cod); 
//	fprintf(file,"%d\n",p1->cod);
//	
//    printf("Digite a Quantidade no Estoque: "); 
//	scanf("%d",&p1->qt_est); 
//	fprintf(file,"%d\n",p1->qt_est);
//    fflush(stdin);
//    
//    printf("Descrição do Brinquedo: "); gets(p1->descricao); fprintf(file,"%s\n",p1->descricao);
//    fflush(stdin);
//    
//    printf("Modelo do Brinquedo: "); gets(p1->modelo); fprintf(file,"%s\n",p1->modelo);
//    fflush(stdin);
//    
//    printf("Fabricante do Brinquedo: "); gets(p1->fabricante); fprintf(file,"%s\n",p1->fabricante);
//    fflush(stdin);
//    
//    printf("Digite o Valor de Venda do Brinquedo: "); scanf("%f",&p1->valor_venda); fprintf(file,"%.2f\n",p1->valor_venda);
//    fflush(stdin);
//    
//    printf("Digite o Valor de Compra do Brinquedo: "); scanf("%f",&p1->valor_compra); fprintf(file,"%.2f\n",p1->valor_compra);
//    fflush(stdin);
//    printf("Digite a Validade do Brinquedo: ");
//    printf("Dia: "); scanf("%d",&p1->valid.dia);
//    printf("Mes: "); scanf("%d",&p1->valid.mes);
//    printf("Ano: "); scanf("%d",&p1->valid.ano); fprintf(file,"%d / %d / %d\n\n",p1->valid.dia,p1->valid.mes,p1->valid.ano);
//    
//    fwrite(&p1, sizeof(struct Cliente),1, file);
//	
//	fclose(file);
//    
//}

int main(){
	setlocale(LC_ALL,"ptb");
	
	struct cliente *c,x[5];
	c = x;
	
	BRINQUEDO *p,B[5];
    p=B;
    
	int op;
	int cont = 0,cont1 = 0;
	char resp;
	char desc[100];
	 
	FILE *file;
	file = fopen("cad_Cliente.txt","a");
	fclose(file);
	
	if(file == NULL){
		
		printf("O arquivo nao foi criado!");
		
	}
	
		printf("\t\t\t\t\t----Loja de Brinquedos----\n\n");
		
		printf("[1]-Cadastrar Clientes\t\t\t[5]-Cadastrar Produto/Material\n");
		printf("[2]-Consultar Clientes Cadastrados\t[6]-Consultar Produto/Material por Descricao\n");
		printf("[3]-Excluir Clientes po CPF\t\t[7]-Excluir Produto/Material por Codigo\n");
		printf("[4]-Cadastrar Clientes\t\t\t[8]-Alterar dados do Produto/Material\n");
		printf("\n");
		printf("[9]-Realizar Vendas\n");
		printf("[10]-Consultar Estoque\n");
		printf("[11]-Listar Produtos Vendidos com Lucro\n");
		
		
		do{
		op = 66;
		printf("\nOPCAO...: ");
		scanf("%d",&op);
		
		switch(op){
			case 1:
				
				do{
					
					if(cont>5){
						printf("\nNão é Possível Cadastrar Mais Produtos\n");
					}else{
						CadastroCliente(file,c,cont);
						cont++;
						c++;				
					}
				
					printf("Voce deseja fazer outro cadastro? [S/N]");
					fflush(stdin);
					scanf("%s",&resp);
					resp = toupper(resp);
				
				}while(resp != 'N');
				
				printf("\n");
				
				break;
				
				
			case 2:
				consultar(); break;
			
			case 3:
				excluir(); break;
				
//			case 5:
//				do{
//					
//					if(cont>5){
//						printf("\nNão é Possível Cadastrar Mais Produtos\n");
//					}else{
//						cadastra(file,p,cont);
//						cont1++;
//						p++;				
//					}
//				
//					printf("Voce deseja fazer outro cadastro? [S/N]: ");
//					fflush(stdin);
//					scanf("%s",&resp);
//					resp = toupper(resp);
//				
//				}while(resp != 'N');
//				
//				printf("\n");
//			break;
//		}
		
		scanf("%s",&op);
		
		}while(op != 0);
	
	
	}
}
