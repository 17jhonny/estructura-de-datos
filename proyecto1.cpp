#include<bits/stdc++.h>
	#define max 50
	using namespace std;
	struct nodo
	{     //ESTRUCTURA DE LA PILA
	       char palabra;
	       struct nodo *sgte;
    };
	typedef struct nodo *Ptrpila; //definimos estructura tipo pila
    typedef struct nodo *Tlista; //definimos estructura tipo lista
	void push(Ptrpila &,char);
	char pop(Ptrpila &);
	void agregar_atras(Tlista &,char);
	void destruir(Ptrpila &);
	int  prioridad_infija(char );
	int  prioridad_pila(char );
	void imprimir( Tlista &);
	void balanceoSimbolos( Ptrpila &, char []);


	/*                 Funcion Principal
	-----------------------------------------------------*/
	  int main(void)
	    {   Ptrpila p=NULL;
	        Ptrpila M=NULL;
	        Tlista lista=NULL;
	        char cad[max], c,x;
	        int tam;
	        system("color 0f");
    cout<<"    같같같같같같같같같같같같같같같같같같같같같같같같같같같�"<<endl;
    cout<<"    같                                                   같"<<endl;
    cout<<"    같    CONVIRTIENDO LA ECUACION MATEMATICA            같"<<endl;
    cout<<"    같             INFIJA A POSTFIJA                     같"<<endl;
    cout<<"    같                                                   같"<<endl;
    cout<<"    같같같같같같같같같같같같같같같같같같같같같같같같같같같�"<<endl<<endl;

	        do{
	           cout<<"INGRESE LA ECUACION MATEMATICA"<<endl<<endl;
	           gets(cad);
	              if(M!=NULL)
	                 destruir(M);
	           balanceoSimbolos(M,cad); //verificamos si los simbolos de agrupacion estan
	           }while(M!=NULL);         //correctamente valanceados

	        tam=strlen(cad);
	        for(int i=0;i<tam;i++)
	        {
	            if((cad[i]>=49&&cad[i]<=57)||(cad[i]>=97&&cad[i]<=122))//validado para numeros de 1-9 y letras
	                agregar_atras(lista,cad[i]);
	            if(cad[i]=='+'||cad[i]=='-'||cad[i]=='*'||cad[i]=='/'||cad[i]=='('||cad[i]=='^')
	            {   if(p==NULL)
                    push(p,cad[i]);
	                else
	                {
	                    if(prioridad_infija(cad[i])>prioridad_pila(p->palabra))//compara prioridad de operadores
	                        push(p,cad[i]);
	                    else
	                    {   if(prioridad_infija(cad[i])==prioridad_pila(p->palabra))
	                          {
	                            c=pop(p);
	                            agregar_atras(lista,c);
	                            push(p,cad[i]);
	                          }
	                        else
	                          {
	                            c=pop(p);
	                            agregar_atras(lista,c);
	                          }
	                    }
	                }
	            }
	            if(cad[i]==')')
        {
	                while(p->palabra!='('&&p!=NULL)//desempilamos y agregamos a lista
	                   {
	                       c=pop(p);
	                       agregar_atras(lista,c);
	                    }
	                if(p->palabra=='(')
	                        c=pop(p);
	                }
	        }
	        while(p!=NULL)//si es que la pila aun no esta nula pasamos los operadores a lista
	            {
	                c=pop(p);
	                agregar_atras(lista,c);
	            }
	        imprimir(lista);
        system("pause");
	        return 0;
	    }
	/*                 Apilar
	-------------------------------------------------*/
	void push(Ptrpila &p,char a)
	{
	    Ptrpila q=new struct nodo;
	    q->palabra=a;
	    q->sgte=p;
	    p=q;
	 }
	/*                 Desempilar
	-------------------------------------------------*/
	char pop(Ptrpila &p)
	{
    int n;
	    Ptrpila aux;
	    n=p->palabra;
	    aux=p;
	    p=p->sgte;
    delete(aux);
	    return n;
	}
/*                 Agregar a la Lista
	--------------------------------------------------
	funcion para agregar caracter a la lista de salida*/
	void agregar_atras(Tlista &lista,char a)
	{
	    Tlista t, q = new(struct nodo);
	    q->palabra  = a;
	    q->sgte = NULL;
	    if(lista==NULL)
      {
	        lista = q;
	      }
	    else
	      {
	        t = lista;
	        while(t->sgte!=NULL)
	        {
	            t = t->sgte;
        }
	        t->sgte = q;
	      }
	}
	/*                 Destruir Pila
	--------------------------------------------------*/
	void destruir(Ptrpila &M)
	{    Ptrpila aux;
	     if(M !=NULL)
	     {
	         while(M!=NULL)
	         {
	             aux=M;
             M=M->sgte;
	             delete(aux);
	         }
	      }
	}
/*          Prioridad en Notacion Infija
	----------------------------------------------------
	esta prioridad se usa al momento de leer el caracter
	de la cadena*/
	int prioridad_infija(char a)
	{
    if(a=='^')
	        return 4;
	    if( a=='*')
	        return 2;
	    if( a=='/')
	        return 2;
	    if( a=='+')
	        return 1;
    if( a=='-')
	        return 1;
	    if(a=='(')
	        return 5;
	}
	/*                 Prioridad en Pila
	---------------------------------------------------
	esta prioridad es usada para los elementos que se
	encuentran en la pila */
int prioridad_pila(char a)
	{
	    if(a=='^')
	        return 3;
	    if( a=='*')
	        return 2;
	    if( a=='/')
	        return 2;
    if( a=='+')
	        return 1;
	    if( a=='-')
	        return 1;
	    if(a=='(')
        return 0;
	}
	/*               Imprimir Lista
	----------------------------------------------------*/
	void imprimir( Tlista &lista)
	{
	    Ptrpila aux;
	    aux=lista;
    if(lista!=NULL)
	     {    cout<<"\t\nNOTACION POSTFIJA\n\n";
	          while(aux!=NULL)
	          {    cout<<aux->palabra;
	               aux = aux->sgte;
	          }
      }
      cout<<endl<<endl;
}
	/*                Balanceo de simbolos de agrupacion
	---------------------------------------------------------------------*/
	void balanceoSimbolos( Ptrpila &p, char cad[])
	{
	     Ptrpila aux;
	     int i = 0;

     while( cad[i] != '\0')
	     {
	            if( cad[i]=='(' || cad[i]=='[' || cad[i]=='{' )
	            {
	                 push( p, cad[i] );
	            }
	            else if( cad[i]==')' || cad[i]==']' || cad[i]=='}' )
	            {
	                 aux = p;

	                 if(aux!=NULL)
	                 {
	                      if( cad[i]==')' )
	                      {
	                           if( aux->palabra == '(')
	                              pop( p );
                      }
	                      else if( cad[i]==']' )
	                      {
	                           if( aux->palabra == '[')
	                              pop( p );
	                      }
	                      else if( cad[i]=='}' )
	                      {
                           if( aux->palabra == '{')
	                              pop( p );
	                      }
                 }
	                 else
                     push( p, cad[i] );
	            }
            i++;
	     }
	     if(p==NULL)
	         cout<<"\n\tBalanceo CORRECTO..."<<endl<<endl;
	     else
	         cout<<"\n\t Balanceo INCORRECTO, faltan simbolos de agrupacion..."<<endl;
	}

