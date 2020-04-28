

typedef struct {
    char name[30]; //�Ĵ��
    float reputation;//����
    int price; //����
} Restaurant;

void readMenu(); //��ü �޴�(������)�� �����ִ� �Լ�

void listRes(Restaurant  s[], int count); //��ü ����Ʈ�� �����ִ� �Լ�

int addData(Restaurant  *s); //���ο� �Ĵ��� �߰��ϴ� �Լ�

int updateData(Restaurant  *s, int count); //���� ��ϵ� �Ĵ��� �����ϴ� �Լ�

int deleteData(Restaurant  *s, int count); //��ϵ� �Ĵ��� �����ϴ� �Լ�

void SaveData(Restaurant  *s, int count); //File�� �����ϴ� �Լ�

int loadData(Restaurant  *s); //����� ������ �ҷ����� �Լ�

void SearchData(Restaurant  *s, int count); //�˻��ϴ� �Լ�

void SearchPrice(Restaurant s[],int count);//�������� �˻��ϱ�

void SearchReputaion(Restaurant s[],int count);//�������� �˻��ϱ�

void SearchName(Restaurant s[],int count);//�̸����� �˻��ϱ�

void sortName(Restaurant  *s, int count); //�Ĵ� �̸��� �����ϴ� �Լ�

void recommand(Restaurant *s, int count);