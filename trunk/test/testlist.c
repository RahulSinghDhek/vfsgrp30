#include"list.h"
#include<stdio.h>

void main()
{
NODE *newnode,*head,*second,*third,*fourth;
void *p,*q,*r,*s,*t,*u;
char a[]="first",b[]="second",c[]="third",d[]="fourth",e[]="fifth";
p=a;
q=b;
r=c;s=d;t=e;

printf("\ncreating first node");
newnode=create(p);
head=newnode;
printnode(head,printstr);
printf("\ninserting after first node");
second=insert_after(head,q);
printf("\n");
printnode(head,printstr);

third=insert_after(second,r);
printf("\n");
printnode(head,printstr);
printf("\n");
fourth=insert_after(third,s);
printnode(head,printstr);
printf("\ninserting after second node");
second=insert_after(second,t);
printf("\n");
printnode(head,printstr);
printf("\ndeletng third node");
delete(head,third);
printf("\n");
printnode(head,printstr);

printf("\n");


}
