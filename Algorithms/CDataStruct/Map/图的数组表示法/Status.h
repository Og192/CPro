// c1.h (������)
 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()��
 #include<limits.h> // INT_MAX��
 #include<stdio.h> // EOF(=^Z��F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream> // cout,cin
 #include<conio.h>
 #include<Windows.h>
 // �������״̬����
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
 typedef int Status; // Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK��
 typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE

 /*				while((ch=getchar()) != '\n');
				printf("\n���Զ������Թ��Ƿ����⣿(Y/N) �粻����������N������������:");			
				scanf(" %c",&ch);
				i++;
			}while(('N' == ch || 'n' == ch )&&(i < 3));
			if (3 == i)
			{
				system("cls");
				printf("��Ǹ���������õ��Թ�ͼֻ��%d�֣����ɳ���ѡ���ֶ���ʽ����\n\n",i);
				printf("������кܺõĹ�˼���ɽ��Թ�ͼ�����ҵ������������:991025437@qq.com");
				printf("\n\n9����Զ���ת���Թ����ɷ�ʽѡ�����........");
				for (i = 9; i >= 0;i--)
				{	
					printf("\b\b\b\b\b(%d��)",i);
					Sleep(1000);
				};
				ch = 'N';
			}
			else
			{
*/	//			ch = 'Y';
//			}
//			printf("\n");
	