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

//创建学生信息的结构体
STUSCORE createStuScore()
{
	STUSCORE stu;
	printf("请输入学生的学号:\n");
	scanf("%d",&stu.stuID);
	if(stu.stuID==-1)
		return stu;
	printf("请输入学生的姓名:\n");
	scanf("%9s",stu.stuName);
	printf("请输入学生的语文成绩:\n");
	scanf("%d",&stu.yuwen);
	printf("请输入学生的数学成绩:\n");
	scanf("%d",&stu.shuxue);
	printf("请输入学生的英语成绩:\n");
	scanf("%d",&stu.yingyu);

	return stu;

}

//创建一个学生信息节点
SSNLINK addStuScoreNode()
{
	SSNLINK assn;
	assn=(SSNLINK)malloc(sizeof(SSN));
	assn->stu=createStuScore();
	assn->NEXT=NULL;
	return assn;
}

//将一个节点添加到列表中去，返回列表的头指针
SSNLINK addToList(SSNLINK list,SSNLINK stunode)
{
	stunode->NEXT=list;
	list=stunode;
	return list;
}

//显示信息
void showOneInfo2(STUSCORE ss)
{
		printf("%8d%8s%8d%8d%8d\n",ss.stuID,ss.stuName,ss.yuwen,ss.shuxue,ss.yingyu);
}

//显示所有学生信息
void showAllInfo(SSNLINK list)
{
	SSNLINK  p;
	p=list;
	printf("%8s%8s%8s%8s%8s\n","学号","姓名","语文","数学","英语");

	while(p!=NULL)
	{
		showOneInfo2((*p).stu);
		p=p->NEXT;
	}
	
}

//查询成绩函数
void chaxuncheng(SSNLINK head)
{
	int i;
	SSNLINK cha;
	cha=head;
	printf("请输入要查询成绩学生的学号\n");
	scanf("%d",&i);getchar();
	while(cha!=NULL)
	{
		if(i==cha->stu.stuID)
		{
			printf("%8s%8s%8s%8s%8s\n","学号","姓名","语文","数学","英语");
			showOneInfo2(cha->stu);
		}
		cha=cha->NEXT;
	}
}

//修改程序函数
void xiugai(SSNLINK head)
{
	int i;
	SSNLINK gai=head;
	printf("请输入要修改成绩学生的学号\n");
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
	printf("修改成功");getchar();getchar();
}

//删除成绩函数
SSNLINK shanchu(SSNLINK head)
{
	int i;
	SSNLINK gai=head->NEXT,man=head;
	printf("请输入要删除成绩学生的学号\n");
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
	printf("删除成功");getchar();getchar();
}

//排序
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
	printf("成功排序");getchar();getchar();
}

int main()
{
	SSNLINK list=NULL,node;//list是列表的头指针，node为单节点的指针
	int choice;//choice是要选择的服务数字
	while(1)//让程序一直循环
	{
		printf("*********学生成绩管理系统********\n");
		printf("1.输入学生成绩信息\n");
		printf("2.显示所有学生的成绩信息\n");
		printf("3.查询成绩\n");
		printf("4.修改程序\n");
		printf("5.删除程序\n");
		printf("6.成绩排序\n");
		printf("*********************************\n");
		printf("请输入您的选择:\n");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1://添加学生信息
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

