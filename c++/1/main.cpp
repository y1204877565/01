#include <stdio.h>
#include <string.h>
#include "malloc.h"
typedef struct StuScore{
	int stuID;
	char stuName[10];
	int yuwen;
	int shuxue;
	int yingyu;
} STUSCORE;

typedef struct StuScoreNode{
	STUSCORE stu;
	struct StuScoreNode *NEXT;
	
}  SSN,*SSNLINK;

//����ѧ����Ϣ�Ľṹ��
STUSCORE createStuScore()
{
	STUSCORE stu;
	printf("������ѧ����ѧ��:\n");
	scanf("%d",&stu.stuID);
	if(stu.stuID==-1)
		return stu;
	printf("������ѧ��������:\n");
	scanf("%9s",stu.stuName);
	printf("������ѧ�������ĳɼ�:\n");
	scanf("%d",&stu.yuwen);
	printf("������ѧ������ѧ�ɼ�:\n");
	scanf("%d",&stu.shuxue);
	printf("������ѧ����Ӣ��ɼ�:\n");
	scanf("%d",&stu.yingyu);

	return stu;

}

//����һ��ѧ����Ϣ�ڵ�
SSNLINK addStuScoreNode()
{
	SSNLINK assn;
	assn=(SSNLINK)malloc(sizeof(SSN));
	assn->stu=createStuScore();
	assn->NEXT=NULL;
	return assn;
}

//��һ���ڵ���ӵ��б���ȥ�������б��ͷָ��
SSNLINK addToList(SSNLINK list,SSNLINK stunode)
{
	stunode->NEXT=list;
	list=stunode;
	return list;
}

//��ʾ��Ϣ
void showOneInfo2(STUSCORE ss)
{
		printf("%8d%8s%8d%8d%8d\n",ss.stuID,ss.stuName,ss.yuwen,ss.shuxue,ss.yingyu);
}

//��ʾ����ѧ����Ϣ
void showAllInfo(SSNLINK list)
{
	SSNLINK  p;
	p=list;
	printf("%8s%8s%8s%8s%8s\n","ѧ��","����","����","��ѧ","Ӣ��");

	while(p!=NULL)
	{
		showOneInfo2((*p).stu);
		p=p->NEXT;
	}
	
}

//��ѯ�ɼ�����
void chaxuncheng(SSNLINK head)
{
	int i;
	SSNLINK cha;
	cha=head;
	printf("������Ҫ��ѯ�ɼ�ѧ����ѧ��\n");
	scanf("%d",&i);getchar();
	while(cha!=NULL)
	{
		if(i==cha->stu.stuID)
		{
			printf("%8s%8s%8s%8s%8s\n","ѧ��","����","����","��ѧ","Ӣ��");
			showOneInfo2(cha->stu);
		}
		cha=cha->NEXT;
	}
}

//�޸ĳ�����
void xiugai(SSNLINK head)
{
	int i;
	SSNLINK gai=head;
	printf("������Ҫ�޸ĳɼ�ѧ����ѧ��\n");
	scanf("%d",&i);
	while(gai!=NULL)
	{
		if(i==gai->stu.stuID)
		{
			gai->stu=createStuScore();
			break;
		}
		gai=gai->NEXT;
	}
	printf("�޸ĳɹ�");getchar();getchar();
}

//ɾ���ɼ�����
SSNLINK shanchu(SSNLINK head)
{
	int i;
	SSNLINK gai=head->NEXT,man=head;
	printf("������Ҫɾ���ɼ�ѧ����ѧ��\n");
	scanf("%d",&i);
	if(i==man->stu.stuID)
	{
		head=head->NEXT;
		return head;
	}
	else{
		while(gai!=NULL)
		{
			if(i==gai->stu.stuID)
			{
				man->NEXT=gai->NEXT;
				break;
			}
			else
				gai=gai->NEXT;
		}
	}
	printf("ɾ���ɹ�");getchar();getchar();
}

//����
void paixiu(SSNLINK head)
{
	SSNLINK da,xiao;
	STUSCORE zanshi;
	int a,b;
	da=head;
	while(da!=NULL)
	{
		xiao=da;
		a=xiao->stu.shuxue+xiao->stu.yingyu+xiao->stu.yuwen;		
		while(xiao!=NULL)
		{
			b=xiao->stu.shuxue+xiao->stu.yingyu+xiao->stu.yuwen;
			if(b>a)
			{
				zanshi=xiao->stu;
				xiao->stu=da->stu;
				da->stu=zanshi;
				a=b;
			}
			xiao=xiao->NEXT;
		}
		da=da->NEXT;
	}
	printf("�ɹ�����");getchar();getchar();
}

int main()
{
	SSNLINK list=NULL,node;//list���б��ͷָ�룬nodeΪ���ڵ��ָ��
	int choice;//choice��Ҫѡ��ķ�������
	while(1)//�ó���һֱѭ��
	{
		printf("*********ѧ���ɼ�����ϵͳ********\n");
		printf("1.����ѧ���ɼ���Ϣ\n");
		printf("2.��ʾ����ѧ���ĳɼ���Ϣ\n");
		printf("3.��ѯ�ɼ�\n");
		printf("4.�޸ĳ���\n");
		printf("5.ɾ������\n");
		printf("6.�ɼ�����\n");
		printf("*********************************\n");
		printf("����������ѡ��:\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1://���ѧ����Ϣ
			while(1)
			{
				node=addStuScoreNode();
				if(node->stu.stuID==-1)
					break;
				list=addToList(list,node);
			}

			break;
		
		case 2:showAllInfo(list);getchar();getchar();break;

		case 3:chaxuncheng(list);getchar();break;

		case 4:xiugai(list);break;

		case 5:list=shanchu(list);break;

		case 6:paixiu(list);break;

		case -1:break;

		}
	}
}

