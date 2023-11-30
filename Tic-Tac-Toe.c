#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
struct player
{
	char name[15];
	char symbol;
}p1, p2, computer;

int mod, cpos;
int Drow=1;
char xo[][3]={'1','2','3','4','5','6','7','8','9'};
int i, j, chance, flag, Win=0;
char pos;

int dai1 = 1, dai2 = 1, ver1 = 1, ver2 = 1, ver3 = 1, hor1 = 1, hor2 = 1, hor3 = 1;


void display(char (*p)[3])
{
	int i,j;
	for(i=0;i<3;i++)
	{
		printf("___________________ \n| ");
		for(j=0;j<3;j++)
		{
			printf("%3c",*(*(p+i)+j));
			printf(" | ");
		}
		printf("\n");
	}
		printf("___________________");
}

char vertical(char (*p)[3])
{
	int i,j,count;
	for(i=0;i<3;i++)
	{
		count=1;
		for(j=0;j<2;j++)
			if( *(*(p+j)+i) == *(*(p+j+1)+i) )
				count++;
		if(count==3)
			return(*(*(p+i)+i));
	}
	return 0;
}

char horizontal(char (*p)[3])
{
	int i,j,count;
	for(i=0;i<3;i++)
	{
		count=1;
		for(j=0;j<2;j++)
			if( *(*(p+i)+j) == *(*(p+i)+j+1) )
				count++;
		if(count==3)
			return *(*(p+i)+i);

	}
	return 0;
}

char cross(char (*p)[3])
{
	int i,j,count=1;

	for(i=0;i<2;i++)
		if( *(*(p+i)+i) == *(*(p+i+1)+i+1) )
			count++;
	if(count==3)
		return *(*(p+i)+i);

	count=1;
	for(i=0,j=2;i<2;i++,j--)
		if( *(*(p+i)+j) == *(*(p+i+1)+j-1) )
			count++;
	if(count==3)
		return *(*(p+i)+j);

	return 0;
}

char checkwin(char (*p)[3])
{
	char s;
	s=vertical(p);
	if(s!=0)
		return s;

	s=horizontal(p);
	if(s!=0)
		return s;

	s=cross(p);
	if(s!=0)
		return s;

	return 0;
}

int Won(char win)
{
	if(win!=0)
	{
		Drow=0;

		(mod == 1 && win == computer.symbol)?
		printf("\n Computer won the match (O) : \n"):
		(win==p1.symbol)?
		printf("\n %s Won the match (%c) : \n",p1.name,p1.symbol):
		printf("\n %s Won the match (%c) : \n",p2.name,p2.symbol);
		return 1;
	}
	return 0;
}
void manualPlay()
{
	if(chance%2==0)
			printf("\n %s choose Position for (%c) : ",p2.name,p2.symbol);
		else
			printf("\n %s choose Position for (%c) : ",p1.name,p1.symbol);
		pos=getch();
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(pos==xo[i][j])
				{
					flag=1;
					if(chance%2==0)
						xo[i][j]=p2.symbol;
					else
						xo[i][j]=p1.symbol;
					break;
				}
			}
		}
}

int counterAlgo()
{
	if(dai1)
	{
		if(xo[0][0] == xo[1][1])
		{
			xo[2][2] = 'O';
			dai1 = 0;
			return 1;
		}
		else if(xo[1][1] == xo[2][2])
		{
			xo[0][0] = 'O';
			dai1 = 0;
			return 1;
		}
		else if(xo[0][0] == xo[2][2])
		{
			xo[1][1] = 'O';
			dai1 = 0;
			return 1;
		}
	}
	if(dai2)
	{
		if(xo[0][2] == xo[2][0])
		{
			xo[1][1] = 'O';
			dai2 = 0;
			return 1;
		}
		else if(xo[1][1] == xo[2][0])
		{
			xo[0][2] = 'O';
			dai2 = 0;
			return 1;
		}
		else if(xo[1][1] == xo[0][2])
		{
			xo[2][0] = 'O';
			dai2 = 0;
			return 1;
		}
	}
	if(ver1)
	{
		if(xo[0][0] == xo[1][0])
		{
			xo[2][0] = 'O';
			ver1 = 0;
			return 1;
		}
		else if(xo[1][0] == xo[2][0])
		{
			xo[0][0] = 'O';
			ver1 = 0;
			return 1;
		}
		else if(xo[0][0] == xo[2][0])
		{
			xo[1][0] = 'O';
			ver1 = 0;
			return 1;
		}
	}
	if(ver2)
	{
		if(xo[0][1] == xo[1][1])
		{
			xo[2][1] = 'O';
			ver2 = 0;
			return 1;
		}
		else if(xo[1][1] == xo[2][1])
		{
			xo[0][1] = 'O';
			ver2 = 0;
			return 1;
		}
		else if(xo[0][1] == xo[2][1])
		{
			xo[1][1] = 'O';
			ver2 = 0;
			return 1;
		}
	}
	if(ver3)
	{
		if(xo[0][2] == xo[1][2])
		{
			xo[2][2] = 'O';
			ver3 = 0;
			return 1;
		}
		else if(xo[1][2] == xo[2][2])
		{
			xo[0][2] = 'O';
			ver3 = 0;
			return 1;
		}
		else if(xo[0][2] == xo[2][2])
		{
			xo[1][2] = 'O';
			ver3 = 0;
			return 1;
		}
	}
	if(hor1)
	{
		if(xo[0][0] == xo[0][1])
		{
			xo[0][2] = 'O';
			hor1 = 0;
			return 1;
		}
		else if(xo[0][1] == xo[0][2])
		{
			xo[0][0] = 'O';
			hor1 = 0;
			return 1;
		}
		else if(xo[0][0] == xo[0][2])
		{
			xo[0][1] = 'O';
			hor1 = 0;
			return 1;
		}
	}
	if(hor2)
	{
		if(xo[1][0] == xo[1][1])
		{
			xo[1][2] = 'O';
			hor2 = 0;
			return 1;
		}
		else if(xo[1][1] == xo[1][2])
		{
			xo[1][0] = 'O';
			hor2 = 0;
			return 1;
		}
		else if(xo[1][0] == xo[1][2])
		{
			xo[1][1] = 'O';
			hor2 = 0;
			return 1;
		}
	}
	if(hor3)
	{
		if(xo[2][0] == xo[2][1])
		{
			xo[2][2] = 'O';
			hor3 = 0;
			return 1;
		}
		else if(xo[2][1] == xo[2][2])
		{
			xo[2][0] = 'O';
			hor3 = 0;
			return 1;
		}
		else if(xo[2][0] == xo[2][2])
		{
			xo[2][1] = 'O';
			hor3 = 0;
			return 1;
		}
	}

	return 0;

}

int winAlgo()
{
	if (dai1)
	{
			if (xo[0][0] == 'O' && xo[1][1] == 'O')
			{
				xo[2][2] = 'O';
				dai1 = 0;
				return 1;
			}

			else if (xo[1][1] == 'O' && xo[2][2] == 'O')
			{

					xo[0][0] = 'O';
					dai1 = 0;
					return 1;
			}

			else if(xo[0][0] == 'O' && xo[2][2] == 'O')
			{

					xo[1][1] = 'O';
					dai1 = 0;
					return 1;
			}
	}

	if (dai2)
	{
			if (xo[0][2] == 'O' && xo[1][1] == 'O')
			{

					xo[2][0] = 'O';
					dai2 = 0;
					return 1;
			}

			else if (xo[1][1] == 'O' && xo[2][0] == 'O')
			{

					xo[0][2] = 'O';
					dai2 = 0;
					return 1;
			}

			else if(xo[0][2] == 'O' && xo[2][0] == 'O')
			{

					xo[1][1] = 'O';
					dai2 = 0;
					return 1;
			}

	}

	if (ver1)
	{
			if (xo[0][0] == 'O' && xo[1][0] == 'O')
			{
				xo[2][0] = 'O';
				ver1 = 0;
				return 1;
			}

			else if (xo[1][0] == 'O' && xo[2][0] == 'O')
			{
				xo[0][0] = 'O';
				ver1 = 0;
				return 1;

			}

			else if(xo[0][0] == 'O' && xo[2][0] == 'O')
			{
				xo[1][0] = 'O';
				ver1 = 0;
				return 1;

			}


	}
	if (ver2)
	{
			if (xo[0][1] == 'O' && xo[1][1] == 'O')
			{
				xo[2][1] = 'O';
				ver2 = 0;
				return 1;
			}
			else if (xo[1][1] == 'O' && xo[2][1] == 'O')
			{
				xo[0][1] = 'O';
				ver2 = 0;
				return 1;
			}
			else if(xo[0][1] == 'O' && xo[2][1] == 'O')
			{
				xo[1][1] = 'O';
				ver2 = 0;
				return 1;
			}

	}
	if (ver3)
	{
			if (xo[0][2] == 'O' && xo[1][2] == 'O')
			{
				xo[2][2] = 'O';
				ver3 = 0;
				return 1;
			}
			else if (xo[1][2] == 'O' && xo[2][2] == 'O')
			{
				xo[0][2] = 'O';
				ver3 = 0;
				return 1;
			}
			else if(xo[0][2] == 'O' && xo[2][2] == 'O')
			{
				xo[1][2] = 'O';
				ver3 = 0;
				return 1;
			}

	}

	if (hor1)
	{
			if (xo[0][0] == 'O' && xo[0][1] == 'O')
			{
				xo[0][2] = 'O';
				hor1 = 0;
				return 1;
			}
			else if (xo[0][1] == 'O' && xo[0][2] == 'O')
			{
				xo[0][0] = 'O';
				hor1 = 0;
				return 1;
			}
			else if(xo[0][0] == 'O' && xo[0][2] == 'O')
			{
				xo[0][1] = 'O';
				hor1 = 0;
				return 1;
			}

	}
	if (hor2)
	{
			if (xo[1][0] == 'O' && xo[1][1] == 'O')
			{
				xo[1][2] = 'O';
				hor2 = 0;
				return 1;
			}
			else if (xo[1][1] == 'O' && xo[1][2] == 'O')
			{
				xo[1][0] = 'O';
				hor2 = 0;
				return 1;
			}
			else if(xo[1][0] == 'O' && xo[1][2] == 'O')
			{
				xo[1][1] = 'O';
				hor2 = 0;
				return 1;
			}

	}
	if (hor3)
	{
			if (xo[2][0] == 'O' && xo[2][1] == 'O')
			{
				xo[2][2] = 'O';
				hor3 = 0;
				return 1;
			}
			else if (xo[2][1] == 'O' && xo[2][2] == 'O')
			{
				xo[2][0] = 'O';
				hor3 = 0;
				return 1;
			}
			else if(xo[2][0] == 'O' && xo[2][2] == 'O')
			{
				xo[2][1] = 'O';
				hor3 = 0;
				return 1;
			}
	}
	return 0;
}

void tictackalgo()
{
	
	// Decision for winning
	if(winAlgo() == 1)
	return;

	// Decision for Countering
	if(counterAlgo() == 1)
		return;



	srand(time(0));
	do
	{
		cpos = rand()%9;
	}
	while(xo[0][cpos] == 'X' || xo[0][cpos] == 'O');
	xo[0][cpos] = 'O';

}



void checkfull()
{
	int i, j;
	int count;

	//check horizontal
	for(i=0;i<3;i++)
	{
		count = 0;
		for(j=0; j<3; j++)
		{
			if(xo[i][j] == 'X' || xo[i][j] == 'O')
				count++;
		}
		if(count == 3)
		{
			switch(i)
			{
				case 0:
					hor1 = 0;
					break;
				case 1:
					hor2 = 0;
					break;
				case 2:
					hor3 = 0;
					break;
			}
		}
	}

	// check vertical
	for(i=0;i<3;i++)
	{
		count = 0;
		for(j=0; j<3; j++)
		{
			if(xo[j][i] == 'X' || xo[j][i] == 'O')
				count++;
		}
		if(count == 3)
		{
			switch(i)
			{
				case 0:
					ver1 = 0;
					break;
				case 1:
					ver2 = 0;
					break;
				case 2:
					ver3 = 0;
					break;
			}
		}
	}

	//check rightdiagonal
	count = 0;
	for(i=0,j=2; i<3; i++,j--)
		if(xo[i][j] == 'X' || xo[i][j] == 'O')
			count++;
	if(count == 3)
	{
		dai2 = 0;
		
	}

	//check leftdaigonal
	count = 0;
	for(i=0; i<3; i++)
		if(xo[i][i] == 'X' || xo[i][i] == 'O')
			count++;
	if(count == 3)
	{
		dai1 = 0;
		
	}

}
void computerplay()
{
	int cflag=0;
	if(chance%2==0)
	{

		printf("\n Computer has chosen O on position : ");
		if(chance == 2 && xo[1][1] != 'X')
		{	
			xo[1][1] = 'O';
			flag = 1;
			return;
		}
		if(chance == 2)
		{
			srand(time(0));
			do
			{
				cpos = rand()%9;
			}
			while(xo[0][cpos] == 'X' || xo[0][cpos] == 'O');
			xo[0][cpos] = 'O';
			flag = 1;
			printf("%d\n",cpos+1);
			return;
		}

		tictackalgo();
		flag = 1;


	}
	else
	{
		printf("\n %s choose Position for (%c) : ",p1.name,p1.symbol);
		pos=getch();
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(pos==xo[i][j])
				{
					flag=1;
					xo[i][j]=p1.symbol;
					checkfull();
					break;
				}
			}
		}
	}
}
int main()
{
	p1.symbol = 'X';
	p2.symbol = 'O';
	char play;
	do
	{
		printf("To play with computer press 1 \nTo play with human press 2 : ");
		scanf("%d",&mod);
		if(mod == 1)
		{
			fflush(stdin);
			printf("Enter you name : ");
			gets(p1.name);
			strcpy(computer.name,"Computer");
			computer.symbol = 'O';
		}
		else if(mod == 2)
		{
			printf("\n Symbol for player 1 : %c",p1.symbol);
			printf("\n Symbol for player 2 : %c",p2.symbol);
			printf("\n Player 1 Enter Your Name : ");
			gets(p1.name);
			printf("\n Player 2 Enter your Name : ");
			gets(p2.name);
		}
		else
		{
			printf("\n\n Wrong input \n\n");
			main();
			return;
		}
		for(chance=1;chance<10;chance++)
		{
			again:
			flag=0;
			printf("\n XO Table : \n\n");
			display(xo);
			fflush(stdin);
			if(mod == 1)
				computerplay();
			else
				manualPlay();
	
			if(flag == 0)
			{
				printf("\n Wrong Position try again \n");
				goto again;
			}
			Win=checkwin(xo);
			if(Won(Win))break;
		}
		if(Drow)
			printf("\n Match Drow : \n");
		display(xo);
		getch();
		printf("\nTo play again press y else n : ");
		scanf("%c",&play);
		system("cls");
	}while(play=='y');
	return 0;
}
