---
title: 我的电脑在开机的时候总是想要安装4个包
author: monohue
layout: post
---

前段时间，身边很多朋友的电脑一开机，微软商店就安装四个包。因为某些原因，这几个包永远没法安装成功。中文区没有太多关于这个问题的资料，于是记录了如何修复的过程。

<!-- more -->

这四个包分别是：

- Microsoft visual C++ 2012 UWP desktop runtime package
- Microsoft visual C++ 2013 UWP desktop runtime package
- Microsoft visual C++ 2015 UWP desktop runtime package
- DirectX Runtime

## 解决方法

> 方法基于[这篇帖子](https://www.reddit.com/r/WindowsHelp/comments/q7xggo/comment/hing7nb/?utm_source=share&utm_medium=web2x&context=3)整理翻译出来，感谢作者的研究。

首先，下载这四个文件：

- https://aka.ms/directx_x64_appx
- https://aka.ms/Microsoft.VCLibs.x64.14.00.Desktop.appx
- https://www.microsoft.com/download/details.aspx?id=53176
- https://www.microsoft.com/download/details.aspx?id=53340

这四个文件下载都是微软官网的链接。
前两个（DirectX和2015）是因为图形化安装程序有问题，安装必定失败。需要通过命令行安装。
后两个（2012和2013）需要提取出文件，再通过命令行安装。

他们都需要你使用PowerShell安装，Powershell可以理解为Windows的高级命令行。这并不可怕，解决的方法也很简单：

1. 打开下载到的文件夹，在空白处右键看看是否有``打开Powershell``的选项：
   1. 如果有，直接打开。
   2. 如果没有，完成以下步骤：
      1. 复制文件夹的路径。可以通过复制文件浏览器的"地址栏"，也可以通过右键文件-属性找到路径（一般是``C:\xxxx\xxxxx\xxx``的形式）。
      2. 按``windows + X``，选择``Powershell``。
      3. 在Powershell内输入``cd ``，**注意是cd和一个空格**，黏贴路径，然后回车。
2. 安装前两个软件，下面两个命令行的作用是安装这个"包"，复制、黏贴、回车就行了：
   1. ``Add-AppxPackage -Path .\UAPSignedBinary_Microsoft.DirectX.x64.appx``
   2. ``Add-AppxPackage -Path .\Microsoft.VCLibs.x64.14.00.Desktop.appx``
3. 提取后两个软件的"包"，双击打开，同意然后安装就可以了。两个软件都要各自安装一次。
4. 安装提取出来的包，同样在命令行运行下面两个代码：
   1. ``Add-AppxPackage -Path "C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.VCLibs.Desktop.110\14.0\Appx\Retail\x64\Microsoft.VCLibs.x64.11.00.Desktop.appx"``
   2. ``Add-AppxPackage -Path "C:\Program Files (x86)\Microsoft SDKs\Windows Kits\10\ExtensionSDKs\Microsoft.VCLibs.Desktop.120\14.0\Appx\Retail\x64\Microsoft.VCLibs.x64.12.00.Desktop.appx"``
5. 大功告成！

这样以后开机就不会出现微软商店在安装什么什么的提示了，希望能帮到大家！

## UPD Oct.7, 2022

好像现在的Windows Update修复了这个问题。