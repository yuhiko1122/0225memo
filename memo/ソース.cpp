#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6064)

#define _CRT_SECURE_NO_WARNINGS
#define MAXNAME 20

int main() {
	char com[10];
	char len[1000];
	char pluslen[1000];
	int i, num;
	char filename[MAXNAME];
	char filenamedel[MAXNAME];
	char filenamewrite[MAXNAME];
	char filenamechange[MAXNAME];
	char filenamenew[MAXNAME];
	char filenameplus[MAXNAME];
	FILE* fp;
	char txt[5] = { ".txt" };

	printf("�s�����L�[�i���j�V�K�t�@�C���쐬�t\n");
	printf("�s����L�[�i���j�������݃��[�h�t\n");
	printf("�s�E���L�[�i���j���O�ύX�t\n");
	printf("�s�����L�[�i���j�폜���[�h�t\n");

	switch (getch())
	{
	case 0xe0:
		switch (getch())
		{

		case 0x50: //���V�K�t�@�C���쐬
		{
			system("cls");
			printf("�V�K�t�@�C���쐬\n");
			printf("�V�K�t�@�C���������\n");
			scanf("%s", filename);
			printf("�����[�U�[�̓��͂������O\n");
			printf("�t�@�C���̖��O:");
			printf("%s", filename);
			printf(".txt");
			strcat(filename, txt);

			fp = fopen(filename, "w");

			fclose(fp); //�t�@�C�������
		}
		break;

		case 0x48:
		{
			system("cls");
			printf("�������݃��[�h\n"); 	//���L�[�@�������݃��[�h
			printf("esc ��������\n");
			printf("tab �t�@�C���ǋL");
			printf("esc������L�[�i���j�F�I��\n");
			printf(" \n");
			for (;;)
			{
				switch (getch())
				{


				case 0x1B:	//esc
				{
					system("cls");
					printf("�������݃t�@�C��������");
					scanf("%s", filenamewrite);
					fp = fopen(filenamewrite, "w");
					printf("�������ݓ��e����");
					scanf("%s", len);
					fprintf(fp, "%s ", len);
					fclose(fp);
				}
				break;

				case 0x09:	//tab
				{
					system("cls");
					printf("�t�@�C���ǋL\n");
					printf("�ǋL�������t�@�C���������\n");

					FILE* fp = NULL;
					scanf("%s", filenameplus);

					fopen_s(&fp, filenameplus, "a");


					scanf("%s", pluslen);
					fputs("\n", fp);
					fputs(pluslen, fp);

					fclose(fp);

					return 0;


				}
				break;

				//case 0x0d:	//enter
				//{
				//	system("cls");
				//	printf("�ǂݍ���");
				//}
				//break;

				case 0xe0:
					switch (getch())
					{
					case 0x48: printf("��"); //���L�[ �I��
						return 0;
					}
					break;
				}
			}
		}
		break;
		case 0x4b:	//��
		{
			system("cls");
			printf("�폜���[�h\n");
			printf("�폜�t�@�C��������\n");
			scanf("%s", filenamedel);
			printf("�����[�U�[�̓��͂������O\n");
			printf("%s", filenamedel);
			printf("\n");
			const char* file = filenamedel;

			if (remove(file) == 0)
				printf("%s���폜���܂����B\n", file);
			else
				printf("%s���폜�ł��܂���ł����B\n", file);

			getchar();
		}
		break;

		case  0x4d:		//��
		{
			system("cls");
			printf("���O�ύX\n");
			printf("���ύX�������t�@�C���̖��O\n");
			scanf("%s", filenamechange);
			printf("%s", filenamechange);
			printf("\n");
			printf("���ύX��̃t�@�C���̖��O\n");
			scanf("%s", filenamenew);
			strcat(filenamenew, txt);
			printf("%s", filenamenew);
			printf("\n");
			const char* file = filenamechange;
			const char* fileNew = filenamenew;

			if (rename(file, fileNew) == 0)
				printf("%s��%s�Ƀ��l�[�����܂����B\n", file, fileNew);
			else
				printf("%s��%s�Ƀ��l�[���ł��܂���ł����B\n", file, fileNew);

			getchar();
		}
		break;

		}



		///*switch (getch())
		//{
		//case 0xe0:
		//	switch (getch())
		//	{
		//	case 0x48: printf("��"); break;
		//	case 0x50: printf("��"); break;
		//	case 0x4b: printf("��"); break;
		//	case 0x4d: printf("��"); break;
		//	}
		//	break;*/
		//}

		//case 0x20:
				//	printf("space");	//space
				//	break;
	//case 0x09:
	//	printf("tab\n");	//tab
	//	break;
		//case 0x08:
		//	printf("backspace");	//backspace
		//	break;

		//case 0x0d:printf("\n");	//enter
					//break;
	}
}


