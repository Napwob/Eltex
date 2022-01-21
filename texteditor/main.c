#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fixnum(int *x, int *y)
{
  if (*x < 0)
    *x = 0;
  if (*y < 0)
    *y = 0;
}

int findpos(int x, int y, char *str)
{
  if (x == 0)
    return y;
  int newpos = 0;
  int newx = 0;
  while (newpos < strlen(str))
  {
    newpos++;
    if (str[newpos] == '\n')
      newx++;
    if (newx == x)
      break;
  }
  return newpos + y;
}

void insertletter(int newpos, char *str, char symb)
{
  for (int i = strlen(str); i >= newpos; i--)
  {
    str[i + 1] = str[i];
  }
  str[newpos] = symb;
}

void deleteletter(int newpos, char *str)
{
    for(int i=newpos;i<=strlen(str);i++)
    {
        str[i]=str[i+1];
    }
}

int main(int argc, char* argv[])
{
  if(argc==1) return 1;
  if(strcmp(argv[1],"--help")==0 || strcmp(argv[1],"-h")==0)
  {
    printf("  Press F1 to save changes in file\n");
    printf("  Press F2 to exit without save\n");
    return 0;
  }
  initscr();
  noecho();
  keypad(stdscr, true);
  FILE *fp;
  char *name = argv[1];
  if ((fp = fopen(name, "r+")) == NULL)
    printf("Не удалось открыть файл");

  char str[500];
  int strnum = 0;
  while (true)
  {
    char s = fgetc(fp);
    if (s != EOF)
    {
      str[strnum] = s;
      strnum++;
    }
    else
      break;
  }
  fclose(fp);
  refresh();
  printw("%s", str);
  int x = 0, y = 0;
  move(x, y);
  bool editbool = true;
  FILE *fps;
  while (editbool)
  {
    int ch = getch();
    switch (ch)
    {
    case KEY_F(2):
      editbool = false;
      break;

    case KEY_F(1):
      if ((fps = fopen(name, "w+")) == NULL)
        printf("Не удалось открыть файл");
      fprintf(fps, "%s", str);
      fclose(fps);
      editbool = false;
      break;

    case KEY_UP:
      x--;
      break;

    case KEY_DOWN:
      x++;
      break;

    case KEY_LEFT:
      y--;
      break;

    case KEY_RIGHT:
      y++;
      break;

    case KEY_ENTER:
      insertletter(findpos(x, y, str), str, '\n');
      break;

    case KEY_BACKSPACE:
      deleteletter(findpos(x, y, str)-1, str);
      y--;
      break;

    case ' ':
      insertletter(findpos(x, y, str), str, ' ');
      // void insertletter(int newpos, char *str, char symb)
      break;

    default:
      insertletter(findpos(x, y, str)+1 , str, ch);
      y++;
    }
    fixnum(&x, &y);
    clear();
    printw("%s", str);
    move(x, y);
    refresh();
  }
  endwin();
  return 0;
}
