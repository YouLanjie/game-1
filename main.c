#include "src/head.h"                                     //引入头文件

void welcome() {                                          //打印开始界面
	Clear
	printf("\t\t\t\t    welcome\n\n");
	printf("\t\t\t    1、开始游戏——————————1\n");
	printf("\t\t\t    2、游戏记录——————————2\n");
	printf("\t\t\t    3、游戏帮助——————————3\n");
	printf("\t\t\t    4、退出游戏——————————0\n");
	printf("\t\t\t           请选择( )\b\b");
}

void game() {                                             //游戏函数
	int m,a,aa,ab,c,d=0,e=0,f;                        //定义一大堆变量
	char ma='n';

	printf("\t\t      你想玩几局？");
	scanf("%d",&m);
	getchar();

	if(m == 0) return;
	else if(m < 0) return;
	else if(m > 1000) return;                         //谁会这么闲玩这么多局
	else if(m >= 100) {                               //勉强还能忍
		Clear
		printf("\t\t 这么多局，您确定吗？Y/n\n\t\t\t  ");
		scanf("%c",&ma);
		getchar();
		if(ma=='y' || ma=='Y') Clear
		else return;
	}

	Clear
	printf("\t\t     本次局数：%d局\n\t\t      按Enter继续\n\t\t\t  ",m);
	getchar();
	Clear

	for(a=1;a<=m;a++) {
		while(1) {
			srand(time(NULL));
			Print
			printf("\t\t\t请选择：\n\t\t\t攻击——1\n\t\t\t防御——2\n\t\t\t   ");
			scanf("%d",&c);
			getchar();
			printf("\n\n");

			if(c==0) {
				Clear
				printf("\t  您确定要退出吗？您的记录将不会保存！\n\t\t\t ");
				scanf("%c",&ma);
				getchar();

				if(ma=='y' || ma=='Y') {
					my.x=my.x2;
					npc.x=npc.x;
					return;
				}
				Clear
			}

			else if(c==1) {
				Clear
				Print
				printf("\t\t     你率先发动攻击，\n");
				d=rand()%(10-0);

				if(d==0 || d==4 || d==5 || d==6) {
					Clear
					npc.x=npc.x-my.g;
					if(npc.x<0) npc.x=0;
					Print
					printf("\t\t     你率先发动攻击，\n");
					printf("\t    你精准的刺中了NPC,NPC血量减少%d\n",my.g);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();

					if(npc.x<=0) {
						npc.x=0;
						e=1;
						break;
					}
				}
				
				else if(d==1) {
					Clear
					Print
					printf("\t\t     你率先发动攻击，\n");
					printf("\t    但是，你扑了个空，未能伤害到NPC。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
				}

				else if(d==2 || d==3) {
					Clear
					my.x=my.x-npc.g;
					if(my.x<0) my.x=0;
					Print
					printf("\t\t     你率先发动攻击，\n");
					printf("\t    你因为太过于紧张，反而被NPC击中。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
					if(my.x<=0){
						my.x=0;
						e=2;
						break;
					}
				}

				else if(d==7 || d==8 || d==9 || d==10){
					Clear
					aa=rand()%(5-0)+1;
					ab=npc.g-aa;
					my.x=my.x-ab;

					if(my.x<0) my.x=0;
					Print
					printf("\t\t     你率先发动攻击，\n");
					printf("    你手慢了一点，被NPC击中，因为你防御着，你的血量减少%d。\n",ab);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();

					if(my.x<=0){
						my.x=0;
						e=2;
						break;
					}
				}
			}

			else {
				Clear
				Print
				printf("\t\t     你选择了防御。\n");
				d=rand()%(20-0);
				if(d==0){
					Clear
					npc.x=npc.x-15;

					if(npc.x<0) npc.x=0;

					Print
					printf("\t\t     你选择了防御。\n");
					printf("      在你防御的时候顺便击中了NPC，使NPC的血量减少15。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();

					if(npc.x<=0){
						npc.x=0;
						e=1;
						break;
					}
				}
				else if(d==20){
					Clear
					my.x=my.x-npc.g;
					if(my.x<0) my.x=0;
					Print
					printf("\t\t     你选择了防御。\n");
					printf("     你没有防御好，导致敌人打中了你，你的血量减少%d。\n",npc.g);
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
					if(my.x<=0){
						my.x=0;
						e=2;
						break;
					}
				}
				else{
					Clear
					Print
					printf("\t\t     你选择了防御。\n");
					printf("\t  你防住了敌人的攻击，但是这已经很勉强了。\n");
					printf("\t\t      按Enter继续\n\t\t\t  ");
					getchar();
				}
			}
			Clear
		}
		Clear
		if(e==1){
			printf("\t\t此回合玩家胜利\n");
			printf("\t\t      按Enter继续\n\t\t\t  ");
			getchar();
			my.v++;
			my.x=my.x2;
			npc.x=npc.x;
			if(a==m) break;
			Clear
			printf("\t      请选择要提升的属性\n\t\t  血量————1\n\t\t 攻击力————2\n\t\t      ");
			scanf("%d",&f);
			srand(time(NULL));
			if(f==1){
				my.x=my.x+rand()%(100-30)+30;
				my.x2=my.x;
				npc.x=npc.x+rand()%(40-30)+30;
				npc.x2=npc.x;
			}
			else{
				my.g=my.g+rand()%(20-10)+10;
				npc.g=npc.g+rand()%(9-1)+1;
			}
		}
		else if(e==2){
			printf("\t\t此回合NPC胜利\n");
			printf("\t\t      按Enter继续\n\t\t\t  ");
			getchar();
			npc.v++;
			my.x=my.x2;
			npc.x=npc.x;
			if(a==m) break;
			my.x=my.x+rand()%(40-10)+10;
			my.x2=my.x;
			npc.x=npc.x+rand()%(60-40)+40;
			npc.x2=npc.x;
			printf("\t\t      按Enter继续\n\t\t\t  ");
			getchar();
		}
		Clear
	}
	FILE *fp=fopen("~/.save.txt","a");
	if(!fp) return;
	Clear
	if(my.v==npc.v){
		printf("\t\t\t平局\n");
		fprintf(fp,"\t 局数：%d  玩家赢：%d  NPC赢：%d  平局\n",m,my.v,npc.v);
		printf("\t\t      按Enter继续\n\t\t\t  ");
		getchar();
	}
	else if(my.v<npc.v){
		printf("\t\t      NPC胜利\n");
		fprintf(fp,"\t 局数：%d  玩家赢：%d  NPC赢：%d  NPC赢\n",m,my.v,npc.v);
		printf("\t\t      按Enter继续\n\t\t\t  ");
		getchar();
	}
	else if(my.v>npc.v){
		printf("\t\t      玩家胜利\n");
		fprintf(fp,"\t 局数：%d  玩家赢：%d  NPC赢：%d  玩家赢\n",m,my.v,npc.v);
		printf("\t\t      按Enter继续\n\t\t\t  ");
		getchar();
	}
	fclose(fp);
	Clear
	return;
}

void data(){
	int a,b;
	a = size();

	if (a != 0) {
		printf("\t\t\t\t游戏记录\n");
		system("cat ~/.save.txt");
		puts("\t\t\t\t 按Enter退出：");
		while (b != 0) if (kbhit()) b = 0;
	}
	else if(a == 0) {
		printf("\t\t\t\t什么都没有呢！\n");
		puts("\t\t\t\t 按Enter返回：");
		while (b != 0) if (kbhit()) b = 0;
		return;
	}
	Clear
	return;
}

void help(){
	Clear
	printf("\t\t\t 帮助\n");
	printf("\t1、在主界面时选择项目对应的数字即可。\n");
	printf("\t2、注意，游戏进行的全程只能输入整数，不可输入小数、字符串。\n");
	printf("\t3、如果有bug，请上报，我知道了会改的。\n");
	printf("\t4、不要在Windows下运行此程序。\n\n\n");
	printf("\t\t     按Enter退出\n\t\t\t  ");
	getchar();
	Clear
	return;
}

float size(){
	float fsize;	
	struct stat statbuf;
	stat("~/.save.txt",&statbuf);
	fsize=statbuf.st_size;	
	return fsize;
}

int main() {
	char a;                                           //用于判断选择的字符变量
	int b = 1;
	system("touch ~/.save.txt");                      //创建save.txt文件，存储游戏数据。如果有需要可以自行修改
	srand(time(NULL));                                //随机数
	my.g=npc.g=rand()%(60-30)+30;                     //随机初始攻击力

	init_keyboard();
	while(a != '0') {                                 //主菜单
		a = '1';
		welcome();                                //打印主菜单
		scanf("%c",&a);                           //将输入的字符串赋予变量a
		getchar();
		Clear

		if(a == '0') return 0;                    //判断是否等于“0”，如果是，就退出程序
		else if(a == '1') game();                 //如果是“1”，就开始游戏
		else if(a == '2') data();                 //如果是“2”，就打开游戏记录
		else if(a == '3') help();                 //如果是“3”，就打开帮助
	}                                                 //如果都不正确，重新开始

	close_keyboard();
	return 0;                                         //结束main函数，退出程序
}
