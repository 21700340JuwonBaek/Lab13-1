#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"miniproject.h"



void readMenu(){
    printf("1.아이템 추가\
    \n2.아이템 조회\
    \n3.아이템 업데이트\
    \n4.아이템 삭제\
    \n5.Save!\
    \n6.Load!\
    \n7.검색\
    \n8.오늘의 추천메뉴\
    \n9.이름순으로 식당 정렬\
    \n0.종료\n");

}


void listRes(Restaurant  s[], int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return;}
    printf("No.      이름       가격        평점\n");
    for(int i=0; i<count;i++){
        printf("%d %15s   %5d원     %5.1f점\n",i+1,s[i].name,s[i].price ,s[i].reputation);
    }
printf("\n");
    }


    int addData(Restaurant  *s){
    printf("아이템의 이름을 입력해주세요\n");
    char enter;
    enter = getchar();

    fgets(s->name,30,stdin);
    s->name[strlen(s->name)-1] = '\0';

   do{
    printf("식당 음식의 평균 가격을 입력해주세요\n");
    scanf("%d",&s->price);
    if(s->price<=0)printf("다시입력해주세요!\n");
    }while(s->price<=0);

    do{
    printf("식당의 평점을 입력해주세요(0~5까지 소수점 입력 가능!)\n");
    scanf("%f",&s->reputation);
    if(s->reputation>5||s->reputation<0)printf("다시입력해주세요!\n");
    }while(s->reputation>5||s->reputation<0);

    printf("식당이 목록에 추가되었습니다!\n\n");
    return 0;

}


int updateData(Restaurant s[], int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return -1;}
    listRes(s,count);
    int select;
    printf("수정할 식당의 번호를 입력해주세요");
    scanf("%d",&select);
    if(select< 1 || select > count) {
    printf("잘못된 입력입니다!\n");
    return -1;

}
   printf("새 식당 이름은?\n");
      char enter;
    enter = getchar();
   fgets(s[select-1].name,30,stdin);
    s[select-1].name[strlen(s[select-1].name)-1] = '\0';

    
   do{
    printf("식당 음식의 평균 가격을 입력해주세요\n");
    scanf("%d",&s[select-1  ].price);
    if(s[select-1  ].price<=0)printf("다시입력해주세요!\n");
    }while(s[select-1  ].price<=0);

    do{
    printf("식당의 평점을 입력해주세요(0~5까지 소수점 입력 가능!)\n");
    scanf("%f",&s[select-1  ].reputation);
    if(s[select-1  ].reputation>5||s[select-1  ].reputation<0)printf("다시입력해주세요!\n");
    }while(s[select-1  ].reputation>5||s[select-1  ].reputation<0);


    printf("수정성공!\n\n");

return 0;
}


int deleteData(Restaurant s[], int count){
    if(count == 0){printf("데이터없음!\n\n");return count;}
    listRes(s,count);
    int select;
    printf("삭제할 식당의 번호를 입력해주세요");
    scanf("%d",&select);
    if(select< 1 || select > count) {
    printf("잘못된 입력입니다!\n\n");
    return -1;
}

    for(int i  = select-1; i<count; i++){
        s[i]=s[i+1];
}
    printf("삭제완료!\n\n");
    return --count;
}


void SaveData(Restaurant s[],int count){
    if(count==0){printf("데이터 없음!\n\n");return;}
    FILE *fp;

    fp = fopen("Restaurant_Data.txt","wt");

    for(int i = 0; i<count;i++){
        fprintf(fp,"%d %f %s\n",s[i].price,s[i].reputation,s[i].name);
    }
    printf("저장완료!\n");
    fclose(fp);

printf("\n");

}

int loadData(Restaurant s[]){
       FILE *fp;

    fp = fopen("Restaurant_Data.txt","rt");
    if(fp==NULL) {
        printf("파일이 없습니다!\n\n");return 0;
    }
    int i = 0;
    while(1){
        fscanf(fp,"%d %f %[^\n]s",&s[i].price,&s[i].reputation,s[i].name);
        if(feof(fp)!=0) break;

    i++;
    }
        printf("Load 성공!\n\n");
    return i;
}


void SearchName(Restaurant s[],int count){
 printf("찾고자 하는 아이템의 이름을 적어주세요!\n");
        int y_n = 0;
        char name[30];
        int enter;
        enter = getchar();
        fgets(name,30,stdin);
    printf("No.      이름       가격        평점\n");
        name[strlen(name)-1] = '\0';
        for(int i = 0; i<count;i++){
            if(strstr(s[i].name,name)){
        printf("%d %15s   %5d원     %5.1f점\n",i+1,s[i].name,s[i].price ,s[i].reputation);
            y_n++;
            }
        }
        if(y_n == 0)printf("%s의 검색결과가 없습니다!\n",name);
        printf("\n");
}


void SearchReputaion(Restaurant s[],int count){

        printf("평점을 입력해주세요!\n");
        float reputation;
       int y_n = 0;
        scanf("%f",&reputation);
    printf("No.      이름       가격        평점\n");
        for(int i = 0; i<count; i++){
            if(reputation <= s[i].reputation){
        printf("%d %15s   %5d원     %5.1f점\n",i+1,s[i].name,s[i].price ,s[i].reputation);
            y_n++;
        }
        }

        if(y_n == 0)printf("%.1f보다 평점이 높은 식당의 검색결과가 없습니다!\n",reputation);
        printf("\n");
}

void SearchPrice(Restaurant s[],int count){
  printf("가격 입력해주세요!\n");
        int price;
       int y_n = 0;
        scanf("%d",&price);
    printf("No.      이름       가격        평점\n");
        for(int i = 0; i<count; i++){
            if(price >= s[i].price){
        printf("%d %15s   %5d원     %5.1f점\n",i+1,s[i].name,s[i].price ,s[i].reputation);
            y_n++;
        }

}

        if(y_n == 0)printf("%d보다 평균가격이 낮은 식당의 검색결과가 없습니다!\n",price);
        printf("\n");
}

void SearchData(Restaurant s[],int count){
    if(count == 0) {printf("데이터가 없습니다!\n\n");return;}

while(1){

   printf("검색모드를 선택해주세요!\
    \n\n1.이름으로 찾기\
    \n2.평점으로 찾기\
    \n3.가격으로 찾기\
    \n4.메인메뉴로 가기\n");

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
    printf("검색을 종료합니다\n\n");
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
    printf("오늘은 %s 어때요??\n%s %d %f\n",s[i].name, s[i].name, s[i].price, s[i].reputation);
}

