# smarthome_ui
A gui sample which set up with Flythings IDE.

# flythings的使用参考：

1、目录说明

	app：编译生成zkgui，用于加载flythings的UI生成的so
	RunEnv：目前我们已经测试过的打包镜像需要的内容，如果拷贝此目录参考：
	/project/image/configs/i2m/rootfs_fastboot.mk
	SSD_sample：Flythings IDE编译的工程，生成libzkgui.so
	tool：修改我们在用的触摸屏的方法

2、编译app：

	进入app，修改makefile，仅仅需要修改：
	PROJECT_PATH赋值对应的路径,此路径需要和SDK的project路径一致。
	PROJECT_PATH=/home/beal.wu/i2m_i6_master/project
	修改完成后，make即可，在bin中生成zkgui，可以替换/RunEnv/bin下面的zkgui
	
3、编译SSD_sample：

	打开Flythings的IDE，然后导入工程，编译参考”IDE使用参考.pdf“、”Flythings工具使用指南.pdf“
	编译生成的libzkgui.so可以替换RunEnv/lib下面的内容
	
4、编译烧录镜像

	cd /project
	./setup_config.sh configs/nvr/i2m/8.2.1/spinand.glibc.011a.64
	make clean;make image
	
	将RunEnv里面的内容放置对应的目录即可。

注：1024*600，跑800*480的程序

	1、需要将TP改成480*480
	2、fbdev.ini中配置为480*480
	3、zkgui引用头文件为480*480
