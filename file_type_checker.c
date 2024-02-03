#include"file_type_checker.h"


int is_file_png(const char* path)
{
  FILE* image = fopen(path,"rb");
  if(image == NULL) return 0;

  unsigned char magic_bytes[8];
  fread(magic_bytes,8,1,image);

  int sum = 0;
  for(int i = 0;i<8;++i)
    sum += (int)magic_bytes[i];

  if(sum == 425) return 1;

  return 0;
}
int is_file_jpg(const char* path)
{
  FILE* image = fopen(path,"rb");
  if(image == NULL) return 0;

  unsigned char magic_bytes[4];
  fread(magic_bytes,4,1,image);

  int sum = 0;
  for(int i = 0;i<4;++i)
    sum += (int)magic_bytes[i];

  if(sum == 950) return 1;

  return 0;
}
int get_output_file_type(const char* path)
{
  char buf[3];
  int pos = 2;
  for(int i = strlen(path)-1;i > 0;--i)
    {
      if(path[i] == '.') break;
      buf[pos] = path[i];
      pos--;
      if(pos <= 0)
	break;
    }

  if(strcmp(buf,"png") == 0) return 1;
  else if(strcmp(buf,"jpg") == 0) return 0;

  return -1;
}
