# robomaster_2021
## 项目描述：
参加RoboMaster比赛，为步兵机器人编写自瞄算法，使步兵机器人能在比赛中能够自动瞄准对手的机器人，实现在比赛过程中对运动目标的追踪并提高机器人的命中率。  
## 技术栈：
算法使用C++语言与OpenCV库进行搭建，算法中使用多线程加快运行速度，使用NUC核心板作为算法搭载的运算模块，使用大恒与华腾工业相机作为视觉传感器并且编写相对应的SDK进行二次开发与相机参数调整，使用串口通信和双工通信与下位机进行数据传输。
## 工作内容1：
与团队成员进行高效沟通，确定自瞄算法功能和预期效果。
## 工作内容2：
负责算法的开发设计和维护，完成最终算法的部署。
## 工作内容3：
协助团队其它组别的开发测试与联调，完成测试阶段bug的修改和代码优化。
## 详情：
### 注释：
源码存放在master分支下。
本源码是由作者和他人共同完成，其中buff文件中的代码由他人完成，其余由作者完成并整合代码。
### 代码解释：
#### main.cpp
程序入口
#### armor
##### include
存放装甲板识别的头文件  
##### src
存放装甲板识别的cpp文件  
#### buff
##### include
存放能量机关识别的头文件  
##### src
存放能量机关识别的cpp文件  
#### cmake-build-debug
存放多个工业相机标定的参数xml文件
#### others
存放工业相机API开发、多线程、双工通信等功能的代码
##### additions.cpp、save_video.cpp与additions.h、save_video.h
录制视频的代码
##### camera_device.cpp、camera_wrapper.cpp与camera_device.h、camera_wrapper.h
大恒工业相机和华腾工业相机的API开发代码
##### serialport.cpp与serialport.h
双工通信代码
##### thread_control.cpp与thread_control.h
多线程代码

