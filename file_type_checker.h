#ifndef FILE_TYPE_CHECKER_H
#define FILE_TYPE_CHECKER_H
#include<stdio.h>
#include<string.h>
//this headers contains function to check if provided files are png or jpg

extern int is_file_png(const char* path);
extern int is_file_jpg(const char* path);
extern int get_output_file_type(const char* path);

#endif
