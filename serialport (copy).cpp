#include "serialport.h"

bool SerialPort::open_com() {
    fd = open("/dev/485_USB", O_RDWR | O_NOCTTY | O_NDELAY);
    if(-1 == fd)
    {
        cout << "serialport open failed..." << endl;
        return false;
    }
    else
    {
        cout << "serialport is open ..." << endl;
        return true;
    }
}

bool SerialPort::init_com() {
    struct termios options;
    tcgetattr(fd,&options);
    bzero(&options,sizeof(options));

    options.c_cflag  |= B115200 | CLOCAL | CREAD; // 设置波特率，本地连接，接收使能
    options.c_cflag &= ~CSIZE;                     // 屏蔽数据位
    options.c_cflag  |= CS8;                    // 数据位为 8 ，CS7 for 7
    options.c_cflag &= ~CSTOPB;                // 一位停止位， 两位停止为 |= CSTOPB
    //options.c_cflag |= PARENB;                  // 有校验
    //options.c_cflag &= ~PARODD;                // 偶校验

    tcflush(fd, TCIOFLUSH);                     // 清除所有正在发生的I/O数据。
    if(tcsetattr(fd, TCSANOW, &options)!=0)     // TCSANOW立刻对值进行修改
        return  false;

    return true;

}

//int SerialPort::write_com(char buffer) {
//    char pDate[]={};
//    int WriteNum = write(fd, pDate, sizeof(pDate));
//    //uint8_t n= write(fd,buffer,size);
//
//}

int SerialPort::write_com(char buffer, int size) {
    char input[1024];
    input[0]=buffer;
    return write(fd,input,size);
}


void SerialPort::close_com() {
    int flag=close(fd);
}