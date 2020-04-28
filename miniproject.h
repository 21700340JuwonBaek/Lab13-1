

typedef struct {
    char name[30]; //식당명
    float reputation;//평점
    int price; //가격
} Restaurant;

void readMenu(); //전체 메뉴(선택지)를 보여주는 함수

void listRes(Restaurant  s[], int count); //전체 리스트를 보여주는 함수

int addData(Restaurant  *s); //새로운 식당을 추가하는 함수

int updateData(Restaurant  *s, int count); //기존 등록된 식당을 수정하는 함수

int deleteData(Restaurant  *s, int count); //등록된 식당을 제거하는 함수

void SaveData(Restaurant  *s, int count); //File에 저장하는 함수

int loadData(Restaurant  *s); //저장된 파일을 불러오는 함수

void SearchData(Restaurant  *s, int count); //검색하는 함수

void SearchPrice(Restaurant s[],int count);//가격으로 검색하기

void SearchReputaion(Restaurant s[],int count);//평점으로 검색하기

void SearchName(Restaurant s[],int count);//이름으로 검색하기

void sortName(Restaurant  *s, int count); //식당 이름을 정렬하는 함수

void recommand(Restaurant *s, int count);