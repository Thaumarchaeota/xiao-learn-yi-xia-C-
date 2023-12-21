getwd()#获取工作目录
wdset(dir = "")#改变工作目录 工作目录为正斜线
list.files()#查看工作目录下的所有文件
dir()#查看工作目录下的所有文件

#R语言中无需声明变量与定义变量类型，可直接定义与赋值变量
x <- 3 #直接对x向左赋值，连字符快捷键为 "alt" + "-"
x <<- 3 #强制对一个全局变量赋值
x #x后回车即可输出x的量

sum(1,2,3,4,5)
x <- sum(1,2,3,4,5)
mean(1,2,3,4,5)

ls()#已经赋值的变量
str(x)#某个变量的详细信息
ls.str()#已经赋值的变量详细信息
ls(all.names = TRUE)#隐藏文件
rm(x)#删除变量
history()#历史n条
save.image()#保存工作空间镜像
q()#退出

library(ggplot2)#加载R包
detach("package:ggplot2")#移除R包的加载
remove.packages("ggplot2")#卸载R包
.libPaths()#R包存储路径
library()#R包目录
#包的基础信息

library(help="ggplot2")
#列出包中包含的函数(需要先载入)
ls("package:ggplot2")

#移植已下载的R包
installed.packages()
installed.packages()[,1]#载入已下载的R包并获取第一列
Rpack <- installed.packages()[,1]
save(Rpack, file="Rpack.Rdata")
for (i in Rpack) install.package(i)

#帮助文档
help.start()#全局帮助文档
?plot#查询函数(plot)的帮助文档
args(plot)#直接列出函数功能
example(plot)#给出函数的使用示例
demo(graphics)#图例演示
help(package="ggplot2")#包的帮助文档
vignette(ggplot)#一种详细的帮助文档
??ggplot2#不加载包下可使用??搜索帮助文档
help.search("heatmap")#模糊搜索
apropos("heatmap")#列出所有包含关键字的内容
apropos("heatmap", mod="function")#利用mod限制搜索
Rsitesearch("heatmap")#利用R官网联网搜索

#R内置数据集
rivers#直接打出数据集名即可使用
data("rivers")#数据集被重定义后可加载还原
help("mtcars")#数据集详细内容

#R的数据类型
#数值型
#字符串型
#逻辑型
#日期型