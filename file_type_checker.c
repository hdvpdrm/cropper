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
