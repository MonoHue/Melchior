---
title: 如何在国内使用Apple News+
author: monohue
layout: post
excerpt: 是目前最好的方法吗？
---

# 如何在国内使用Apple News+

[Apple News+](https://www.apple.com/apple-news/)是苹果推出的付费新闻订阅服务。Apple News关联的媒体所写的文章，经常出现在中高考的考卷上，也是英语学习者锻炼英语能力的优秀材料。

然而，因为国内的网络环境因素，无法连接到Apple News的服务器。大多英语学习者打开的时候都会遇见"这个服务不在你的国家开放"的提示。真是急坏了迫切希望通过学习英语、建设祖国的人们啊！

> **注意**：如果你不是以***学习英语***为目的，请***立刻退出此页面***。

## 现有的轻松可行方法

目前，网上大部分的方法可以归纳为以下三步：

0. 如果有手机卡，开启飞行模式（*防止GPS定位？*）。
1. 打开**全局模式**的科学上网软件。
2. 清除后台，等待半分钟打开Apple News。

这个方法被证明是及其有效的。事实上解决了不能通过Apple News学习英语的问题。同时，它也存在一些弊端，比如：

- 飞行模式导致接听不了电话、短信和移动流量；
- 访问国内网站时使用的是科学上网流量，又慢又烧钱；

## 改进的方法

我改进了"需要开全局"的限制。现在，不需要进入全局模式也可以学习英语。如果你的设备有电话卡，仍然需要打开飞行模式。

> ### 直接告诉我怎么做吧
> 
> 在规则（对于小火箭而言是``config`` -> ``remote files`` -> ``add file``）中加入[这个连接](https://blog.magi.red/mona.conf)。
> 
> *长按可以复制链接，对于不同的软件，可能需要修改文件内容。*
>
> > **注意**：如果你切换回中国Apple id，这会导致你的iCloud和App Store等由Apple提供的服务同时进入科学上网，这意味着下载软件、同步照片都会计入科学上网流量（还会慢），可以考虑切换回本来的规则（你应该能看到两个规则）。对其他地区用户基本不影响。

在不增加设备的情况下，我捕获到Apple News所依赖的服务器，他们来自以下几个网址：

- gateway.icloud.com:443
- gateway.icloud.com.cn:443
- gsa.apple.com:443
- gsas.apple.com:443
- play.itunes.apple.com:443
- configuration.ls.apple.com:443
- weather-data.apple.com:443
- gsp-ssl.ls.apple.com:443
- news-events.apple.com:443
- news-edge.apple.com:443
- news.iadsdk.apple.com:443
- newsletter-edge.apple.com:443
- c.apple.news:443
- metrics.icloud.com:443

总的来讲，他们来自以下四个网址：

- apple.news
- apple.com
- icloud.com
- icloud.com.cn

在上网规则内加入这四个网站后缀，就可以在非全局下访问Apple News。

如果只加入``apple.com``和``apple.news``后缀，可能会导致虽然能够打开Apple News，但并不能加载内容。

注意``.cn``顶级域名的处理。在有些默认规则中，``.cn``在相当靠前的位置，可能会覆盖``icloud.com.cn``的规则。

## 改进方法的限制与对策

这个方法解决了需要开全局模式的问题，同时产生了新的问题：

- 使用App Store等Apple提供的服务时，流量会经过科学上网服务器。这可能会导致Apple服务的速度降低和额外的科学上网流量；
- 地图会丧失高德地图的数据，即本来地图数据来源是高德和TOMTOM，现在只有TOMTOM数据。这可能会在出行时产生不便。

对于上面的问题，有一些解决方法和缓解措施：

- 细化域名规则；
- 写两个规则文件，在需要使用Apple News的时候用一个，其他时候用另一个；
- 勤开关科学上网软件。

最后，谢谢你花时间阅读这篇文章，希望能对你有所帮助。

***此致***