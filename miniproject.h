#include <stdio.h>

typedef struct {
    char name[30]; //식당명
    int menu; //식당의 메인메뉴
    int price; //가격
} Restaurant;

void readMenu(Restaurant p); //전체 메뉴(선택지)를 보여주는 함수

void listMenu(Restaurant *p, int count); //전체 리스트를 보여주는 함수
int addData(Restaurant *p); //새로운 식당을 추가하는 함수
int updateData(Restaurant *p); //기존 등록된 식당을 수정하는 함수
int deleteData(Restaurant *p); //등록된 식당을 제거하는 함수

void saveData(Restaurant *p, int count); //File에 저장하는 함수
int loadData(Restaurant *p, int count); //저장된 파일을 불러오는 함수

void searchData(Restaurant *p, int count); //검색하는 함수

void sortName(Restaurant *p, int count); //식당 이름을 정렬하는 함수

void sortPrice(Restaurant *p, int count); //메뉴 가격순으로 정렬하는 
