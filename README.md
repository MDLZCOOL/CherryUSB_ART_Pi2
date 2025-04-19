# ART-Pi 2 CherryUSB usb_device例程

## 简介

本例程主要功能是在 RT-Thread Studio 环境下移植和配置 CherryUSB usb_device，并使用 hid_mouse 作为测试。

## 软件说明

更多详细说明请参考：

1. 我的博客：https://mdlzcool.github.io/post/12a4c8db.html

2. RT-Thread 官方论坛帖子：https://club.rt-thread.org/ask/article/459a43fc89e76f8a.html

## 运行
### 编译&下载

编译完成后，将开发板的 ST-Link USB 口与 PC 机连接，然后将固件下载至开发板。

### 运行效果

正常运行后，在 USB-HS 口插上 USB，鼠标会不断转圈。

## 致谢

[CherryUSB](https://github.com/cherry-embedded/CherryUSB)
