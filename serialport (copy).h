#pragma once
#include <iostream>
#include "base.h"
#include<cstdio>      /*标准输入输出定义*/
#include<cstdlib>     /*标准函数库定义*/
#include<unistd.h>     /*Unix 标准函数定义*/
#include<sys/types.h>  /*数据类型，比如一些XXX_t的那种*/
#include<sys/stat.h>   /*定义了一些返回值的结构，没看明白*/
#include<fcntl.h>      /*文件控制定义*/
#include<termios.h>    /*PPSIX 终端控制定义*/
#include<cerrno>      /*错误号定义*/

#define serialport_xy
//#define serialport_py


using namespace std;

class SerialPort{
public:
    int fd;

    bool open_com();
    void close_com();
    bool init_com();
    //int write_com(char buffer);
    int write_com(char buffer,int size);
#ifdef serialport_xy
    //unsigned char xy[6] = {0x7f,0,0,0,0,0x7e};
    unsigned char xy[6] = { 0x80,0,0 ,0,0, 0x7f };
#endif // serialport_xy

#ifdef serialport_py

    unsigned char xy[8] = { 0x80,0,0, 0,0 ,0,0, 0x7f };
    unsigned char rd[2] = { 0,0 };

#endif // serialport_xy
    //int write(int i, unsigned char string, size_t i1);
};

