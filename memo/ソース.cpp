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

	printf("《下矢印キー（↓）新規ファイル作成》\n");
	printf("《上矢印キー（↑）書き込みモード》\n");
	printf("《右矢印キー（→）名前変更》\n");
	printf("《左矢印キー（←）削除モード》\n");

	switch (getch())
	{
	case 0xe0:
		switch (getch())
		{

		case 0x50: //↓新規ファイル作成
		{
			system("cls");
			printf("新規ファイル作成\n");
			printf("新規ファイル名を入力\n");
			scanf("%s", filename);
			printf("↑ユーザーの入力した名前\n");
			printf("ファイルの名前:");
			printf("%s", filename);
			printf(".txt");
			strcat(filename, txt);

			fp = fopen(filename, "w");

			fclose(fp); //ファイルを閉じる
		}
		break;

		case 0x48:
		{
			system("cls");
			printf("書き込みモード\n"); 	//↑キー　書き込みモード
			printf("esc 書き込み\n");
			printf("tab ファイル追記");
			printf("esc→上矢印キー（↑）：終了\n");
			printf(" \n");
			for (;;)
			{
				switch (getch())
				{


				case 0x1B:	//esc
				{
					system("cls");
					printf("書き込みファイル名入力");
					scanf("%s", filenamewrite);
					fp = fopen(filenamewrite, "w");
					printf("書き込み内容入力");
					scanf("%s", len);
					fprintf(fp, "%s ", len);
					fclose(fp);
				}
				break;

				case 0x09:	//tab
				{
					system("cls");
					printf("ファイル追記\n");
					printf("追記したいファイル名を入力\n");

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
				//	printf("読み込み");
				//}
				//break;

				case 0xe0:
					switch (getch())
					{
					case 0x48: printf("↑"); //↑キー 終了
						return 0;
					}
					break;
				}
			}
		}
		break;
		case 0x4b:	//←
		{
			system("cls");
			printf("削除モード\n");
			printf("削除ファイル名入力\n");
			scanf("%s", filenamedel);
			printf("↓ユーザーの入力した名前\n");
			printf("%s", filenamedel);
			printf("\n");
			const char* file = filenamedel;

			if (remove(file) == 0)
				printf("%sを削除しました。\n", file);
			else
				printf("%sを削除できませんでした。\n", file);

			getchar();
		}
		break;

		case  0x4d:		//→
		{
			system("cls");
			printf("名前変更\n");
			printf("↓変更したいファイルの名前\n");
			scanf("%s", filenamechange);
			printf("%s", filenamechange);
			printf("\n");
			printf("↓変更後のファイルの名前\n");
			scanf("%s", filenamenew);
			strcat(filenamenew, txt);
			printf("%s", filenamenew);
			printf("\n");
			const char* file = filenamechange;
			const char* fileNew = filenamenew;

			if (rename(file, fileNew) == 0)
				printf("%sを%sにリネームしました。\n", file, fileNew);
			else
				printf("%sを%sにリネームできませんでした。\n", file, fileNew);

			getchar();
		}
		break;

		}



		///*switch (getch())
		//{
		//case 0xe0:
		//	switch (getch())
		//	{
		//	case 0x48: printf("↑"); break;
		//	case 0x50: printf("↓"); break;
		//	case 0x4b: printf("←"); break;
		//	case 0x4d: printf("→"); break;
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


