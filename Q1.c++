#include <stdio.h>
#include <iostream>
#include <cstdlib>

int f1(int n) {
if (n == 0)
 return (1);
else
return(n * f1(n-1));
}

int f2(int n) {
if (n == 0)
 return (1);
if (n == 1)
 return (1);
else
 return(f2(n-1)+ 2 * f2(n-2));
}

int f3(int n) {
if (n == 0)
 printf("Zero ");
else
{
 printf("%d ",n);
 printf("%d ",n);
 f3(n-1);
}
}


main(){
int n[3] = {0,1,5}; 
int op;
while(op != 4){
std::cout<<"=================" <<std::endl;
std::cout<<"1 - Funcao 1" <<std::endl;
std::cout<<"2 - Funcao 2" <<std::endl;
std::cout<<"3 - Funcao 3" <<std::endl;
std::cout<<"4 - Sair" <<std::endl;
std::cout<<"=================" <<std::endl;

scanf("%d", &op);

switch (op)
{
case 1:
   
   for(int i = 0;i<3;i++)
    {
        int resultado = f1(n[i]);
        printf("%d\n", resultado);
   };
        system("pause");
    break;

case 2:
    
    for(int i = 0;i<3;i++)
    {
        int resultado = f2(n[i]);
        printf("%d\n", resultado);
    };
        system("pause");
break;

case 3:

    for(int i = 0;i<3;i++)
    {
        int resultado = f3(n[i]);
        printf("%d\n", resultado);
    };
        system("pause");
break;

default:
    break;
}
}
}