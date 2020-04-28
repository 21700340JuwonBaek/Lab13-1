#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"miniproject.h"



void readMenu(){
    printf("1.������ �߰�\
    \n2.������ ��ȸ\
    \n3.������ ������Ʈ\
    \n4.������ ����\
    \n5.Save!\
    \n6.Load!\
    \n7.�˻�\
    \n8.������ ��õ�޴�\
    \n9.�̸������� �Ĵ� ����\
    \n0.����\n");

}


void listRes(Restaurant  s[], int count){
    if(count == 0) {printf("�����Ͱ� �����ϴ�!\n\n");return;}
    printf("No.      �̸�       ����        ����\n");
    for(int i=0; i<count;i++){
        printf("%d %15s   %5d��     %5.1f��\n",i+1,s[i].name,s[i].price ,s[i].reputation);
    }
printf("\n");
    }


    int addData(Restaurant  *s){
    printf("�������� �̸��� �Է����ּ���\n");
    char enter;
    enter = getchar();

    fgets(s->name,30,stdin);
    s->name[strlen(s->name)-1] = '\0';

   do{
    printf("�Ĵ� ������ ��� ������ �Է����ּ���\n");
    scanf("%d",&s->price);
    if(s->price<=0)printf("�ٽ��Է����ּ���!\n");
    }while(s->price<=0);

    do{
    printf("�Ĵ��� ������ �Է����ּ���(0~5���� �Ҽ��� �Է� ����!)\n");
    scanf("%f",&s->reputation);
    if(s->reputation>5||s->reputation<0)printf("�ٽ��Է����ּ���!\n");
    }while(s->reputation>5||s->reputation<0);

    printf("�Ĵ��� ��Ͽ� �߰��Ǿ����ϴ�!\n\n");
    return 0;

}


int updateData(Restaurant s[], int count){
    if(count == 0) {printf("�����Ͱ� �����ϴ�!\n\n");return -1;}
    listRes(s,count);
    int select;
    printf("������ �Ĵ��� ��ȣ�� �Է����ּ���");
    scanf("%d",&select);
    if(select< 1 || select > count) {
    printf("�߸��� �Է��Դϴ�!\n");
    return -1;

}
   printf("�� �Ĵ� �̸���?\n");
      char enter;
    enter = getchar();
   fgets(s[select-1].name,30,stdin);
    s[select-1].name[strlen(s[select-1].name)-1] = '\0';

    
   do{
    printf("�Ĵ� ������ ��� ������ �Է����ּ���\n");
    scanf("%d",&s[select-1  ].price);
    if(s[select-1  ].price<=0)printf("�ٽ��Է����ּ���!\n");
    }while(s[select-1  ].price<=0);

    do{
    printf("�Ĵ��� ������ �Է����ּ���(0~5���� �Ҽ��� �Է� ����!)\n");
    scanf("%f",&s[select-1  ].reputation);
    if(s[select-1  ].reputation>5||s[select-1  ].reputation<0)printf("�ٽ��Է����ּ���!\n");
    }while(s[select-1  ].reputation>5||s[select-1  ].reputation<0);


    printf("��������!\n\n");

return 0;
}


int deleteData(Restaurant s[], int count){
    if(count == 0){printf("�����;���!\n\n");return count;}
    listRes(s,count);
    int select;
    printf("������ �Ĵ��� ��ȣ�� �Է����ּ���");
    scanf("%d",&select);
    if(select< 1 || select > count) {
    printf("�߸��� �Է��Դϴ�!\n\n");
    return -1;
}

    for(int i  = select-1; i<count; i++){
        s[i]=s[i+1];
}
    printf("�����Ϸ�!\n\n");
    return --count;
}


void SaveData(Restaurant s[],int count){
    if(count==0){printf("������ ����!\n\n");return;}
    FILE *fp;

    fp = fopen("Restaurant_Data.txt","wt");

    for(int i = 0; i<count;i++){
        fprintf(fp,"%d %f %s\n",s[i].price,s[i].reputation,s[i].name);
    }
    printf("����Ϸ�!\n");
    fclose(fp);

printf("\n");

}

int loadData(Restaurant s[]){
       FILE *fp;

    fp = fopen("Restaurant_Data.txt","rt");
    if(fp==NULL) {
        printf("������ �����ϴ�!\n\n");return 0;
    }
    int i = 0;
    while(1){
        fscanf(fp,"%d %f %[^\n]s",&s[i].price,&s[i].reputation,s[i].name);
        if(feof(fp)!=0) break;

    i++;
    }
        printf("Load ����!\n\n");
    return i;
}


void SearchName(Restaurant s[],int count){
 printf("ã���� �ϴ� �������� �̸��� �����ּ���!\n");
        int y_n = 0;
        char name[30];
        int enter;
        enter = getchar();
        fgets(name,30,stdin);
    printf("No.      �̸�       ����        ����\n");
        name[strlen(name)-1] = '\0';
        for(int i = 0; i<count;i++){
            if(strstr(s[i].name,name)){
        printf("%d %15s   %5d��     %5.1f��\n",i+1,s[i].name,s[i].price ,s[i].reputation);
            y_n++;
            }
        }
        if(y_n == 0)printf("%s�� �˻������ �����ϴ�!\n",name);
        printf("\n");
}


void SearchReputaion(Restaurant s[],int count){

        printf("������ �Է����ּ���!\n");
        float reputation;
       int y_n = 0;
        scanf("%f",&reputation);
    printf("No.      �̸�       ����        ����\n");
        for(int i = 0; i<count; i++){
            if(reputation <= s[i].reputation){
        printf("%d %15s   %5d��     %5.1f��\n",i+1,s[i].name,s[i].price ,s[i].reputation);
            y_n++;
        }
        }

        if(y_n == 0)printf("%.1f���� ������ ���� �Ĵ��� �˻������ �����ϴ�!\n",reputation);
        printf("\n");
}

void SearchPrice(Restaurant s[],int count){
  printf("���� �Է����ּ���!\n");
        int price;
       int y_n = 0;
        scanf("%d",&price);
    printf("No.      �̸�       ����        ����\n");
        for(int i = 0; i<count; i++){
            if(price >= s[i].price){
        printf("%d %15s   %5d��     %5.1f��\n",i+1,s[i].name,s[i].price ,s[i].reputation);
            y_n++;
        }

}

        if(y_n == 0)printf("%d���� ��հ����� ���� �Ĵ��� �˻������ �����ϴ�!\n",price);
        printf("\n");
}

void SearchData(Restaurant s[],int count){
    if(count == 0) {printf("�����Ͱ� �����ϴ�!\n\n");return;}

while(1){

   printf("�˻���带 �������ּ���!\
    \n\n1.�̸����� ã��\
    \n2.�������� ã��\
    \n3.�������� ã��\
    \n4.���θ޴��� ����\n");

    int select;
    scanf("%d",&select);
    if(select == 1){
      SearchName(s,count);
    }


   else if(select == 2) {
             SearchReputaion(s,count);
}

 else if(select == 3) {
    SearchPrice(s,count);
}

else if(select == 4){
    printf("�˻��� �����մϴ�\n\n");
    break;
}

}

}


void sortName(Restaurant  *s, int count){
    if(count<2){return;}
    for(int i = 0 ; i < count ; i ++){
        for(int j = 1 ; j < count; j ++){
            int result = strcmp(s[i].name,s[j].name);
            if(result == 1) {
                Restaurant tmp;
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
            }
        }
    }
}


void recommand(Restaurant *s, int count){
    srand(time(NULL));
    int i = rand()%count;
    printf("������ %s ���??\n%s %d %f\n",s[i].name, s[i].name, s[i].price, s[i].reputation);
}

