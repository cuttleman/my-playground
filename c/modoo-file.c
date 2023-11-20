#include <stdio.h>

void read(FILE *fp);
void write(FILE *fp);
void seek(FILE *fp);

int main(int argc, char *argv[]) {
  FILE *fp = fopen("a.txt", "w+");  // 스트림 열어서 fp에 연결시켜줌

  if (fp == NULL) {
    printf("Write Error!! \n");
    return 1;
  }

  write(fp);  // 다 쓰고나면 position indicator는 맨뒤로 이동
  seek(fp);   // position indicator(파일 위치 지정자)를 SEEK_SET(0) 부터 N 바이트 떨어진 곳으로 위치시킴
  read(fp);   // position indicator 위치부터 EOF까지 읽는 동작 수행

  fclose(fp);  // fp에 연결되어있던 스트림을 닫아줌

  return 0;
}

void write(FILE *fp) {
  fputs("안녕하세요우", fp);
}

void read(FILE *fp) {
  char c;
  int size = 0;

  while ((c = fgetc(fp)) != EOF) {
    printf("%c", c);
    size++;
  }
  printf("\n");
  printf("size : %dbytes \n", size);
}

void seek(FILE *fp) {
  fseek(fp, 0, SEEK_SET);
}

// TODO
// 문제 1. 사용자로 부터 경로를 입력 받아서 그 곳에 파일을 생성하고 a 를 입력해놓는 프로그램을 만들어보세요 (난이도 : 下)
// 문제 2. a.txt 에 어떠한 긴 글이 들어 있는데, 이 글을 입력 받아서 특정한 문자열을 검색하는 프로그램을 만들어보세요 (난이도 : 中)
// 문제 3. a.txt 에 문자열을 입력 받아서 b.txt 에 그 문자열을 역으로 출력하는 프로그램을 만들어보세요 (난이도 : 中下)
